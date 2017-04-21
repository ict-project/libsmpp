/*
   Copyright 2007 Majoron.com (developers@majoron.com)
   Original sources are available at www.majoron.com

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "AntHillSMPP.hpp"
#include "SMPPDecoder.hpp"
#include "SMPPEncoder.hpp"
#include "SMPPValidator.hpp"
#include "SMPPCancelBroadcastSM.hpp"


namespace anthill {
	namespace smpp {

		SMPPCancelBroadcastSM::SMPPCancelBroadcastSM(void):
			SMPPPDU(CommandId::CM_CANCEL_BROADCAST_SM),
			m_sServiceType(""),
			m_sMessageId(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_bPresentBroadcastContentType(false),
			m_bPresentUserMessageReference(false),
			m_nBroadcastContentTypeLen(m_aBroadcastContentType.size()),
			m_nUserMessageReferenceLen(sizeof(unsigned short)){
		}

		SMPPCancelBroadcastSM::SMPPCancelBroadcastSM(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_CANCEL_BROADCAST_SM, nSequenceNumber),
			m_sServiceType(""),
			m_sMessageId(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_bPresentBroadcastContentType(false),
			m_bPresentUserMessageReference(false),
			m_nBroadcastContentTypeLen(m_aBroadcastContentType.size()),
			m_nUserMessageReferenceLen(sizeof(unsigned short)){
		}

		SMPPCancelBroadcastSM::~SMPPCancelBroadcastSM(){
		}

		SMPPPDU* SMPPCancelBroadcastSM::cloneSMPPPDU(void){
			return new SMPPCancelBroadcastSM();
		}

		void SMPPCancelBroadcastSM::fireOnReceived(SMPPSession* poSession){
			SMPPCancelBroadcastSM::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPCancelBroadcastSM::encodePacket(SMPPEncoder* poEncoder){

			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeServiceType(m_sServiceType);
			poEncoder->encodeMessageId(m_sMessageId);
			poEncoder->encodeSourceAddrTON(m_nSourceAddrTON);
			poEncoder->encodeSourceAddrNPI(m_nSourceAddrNPI);
			poEncoder->encodeSourceAddr21(m_sSourceAddr);

			// Encode optional fields
			if(this->m_bPresentBroadcastContentType)
				poEncoder->encodeBroadcastContentType(m_aBroadcastContentType,
					m_nBroadcastContentTypeLen);
			if(this->m_bPresentUserMessageReference)
				poEncoder->encodeUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);

		}

		void SMPPCancelBroadcastSM::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeServiceType(m_sServiceType, getCommandLength());
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());
			poDecoder->decodeSourceAddrTON(m_nSourceAddrTON, getCommandLength());
			poDecoder->decodeSourceAddrNPI(m_nSourceAddrNPI, getCommandLength());
			poDecoder->decodeSourceAddr21(m_sSourceAddr, getCommandLength());

			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_BROADCAST_CONTENT_TYPE:{
						poDecoder->decodeBroadcastContentType(m_aBroadcastContentType,
							m_nBroadcastContentTypeLen, this->getCommandLength());
						this->m_bPresentBroadcastContentType = true;
						break;
					}
					case OptTags::TAG_USER_MESSAGE_REFERENCE:{
						poDecoder->decodeUserMessageReference(m_nUserMessageReference,
							m_nUserMessageReferenceLen, this->getCommandLength());
						this->m_bPresentUserMessageReference = true;
						break;
					}
					default:{
						// Report about error
						std::string sMessage(poDecoder->getTLVError());
						throw std::logic_error(Errors::UNKNOWN_TAG_MSG + sMessage);
						break;
					}
				}
			}
		}

		void SMPPCancelBroadcastSM::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputServiceType(m_sServiceType);
			poOutputter->outputMessageId(m_sMessageId);
			poOutputter->outputSourceAddrTON(m_nSourceAddrTON);
			poOutputter->outputSourceAddrNPI(m_nSourceAddrNPI);
			poOutputter->outputSourceAddr21(m_sSourceAddr);

			// Output optional fields
			if(this->m_bPresentBroadcastContentType)
				poOutputter->outputBroadcastContentTypeOpt(m_aBroadcastContentType,
					m_nBroadcastContentTypeLen);
			if(this->m_bPresentUserMessageReference)
				poOutputter->outputUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);

		}

		void SMPPCancelBroadcastSM::validatePacket(SMPPValidator* poValidator){

			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateServiceType(m_sServiceType);
			poValidator->validateMessageId(m_sMessageId);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddrNPI(m_nSourceAddrNPI);
			poValidator->validateSourceAddr21(m_sSourceAddr);

			// Encode optional fields
			if(this->m_bPresentBroadcastContentType)
				poValidator->validateBroadcastContentType(m_aBroadcastContentType,
					m_nBroadcastContentTypeLen);
			if(this->m_bPresentUserMessageReference)
				poValidator->validateUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);

		}

	}
}
