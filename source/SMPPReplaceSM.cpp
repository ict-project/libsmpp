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
#include "SMPPReplaceSM.hpp"


namespace anthill {
	namespace smpp {

		SMPPReplaceSM::SMPPReplaceSM(void):
			SMPPPDU(CommandId::CM_REPLACE_SM),
			m_sMessageId(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_sScheduleDeliveryTime(""),
			m_sValidityPeriod(""),
			m_nRegisteredDelivery(0),
			m_nSMDefaultMsgId(0),
			m_nSMLength(0),
			m_aShortMessage(),
			m_aMessagePayload(),
			m_bPresentMessagePayload(false),
			m_nMessagePayloadLen(m_aMessagePayload.size()){
		}

		SMPPReplaceSM::SMPPReplaceSM(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_REPLACE_SM, nSequenceNumber),
			m_sMessageId(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_sScheduleDeliveryTime(""),
			m_sValidityPeriod(""),
			m_nRegisteredDelivery(0),
			m_nSMDefaultMsgId(0),
			m_nSMLength(0),
			m_aShortMessage(),
			m_aMessagePayload(),
			m_bPresentMessagePayload(false),
			m_nMessagePayloadLen(m_aMessagePayload.size()){
		}

		SMPPReplaceSM::~SMPPReplaceSM(){
		}

		SMPPPDU* SMPPReplaceSM::cloneSMPPPDU(void){
			return new SMPPReplaceSM();
		}

		void SMPPReplaceSM::fireOnReceived(SMPPSession* poSession){
			SMPPReplaceSM::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPReplaceSM::encodePacket(SMPPEncoder* poEncoder){

			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeMessageId(m_sMessageId);
			poEncoder->encodeSourceAddrTON(m_nSourceAddrTON);
			poEncoder->encodeSourceAddrNPI(m_nSourceAddrNPI);
			poEncoder->encodeSourceAddr21(m_sSourceAddr);
			poEncoder->encodeScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poEncoder->encodeValidityPeriod(m_sValidityPeriod);
			poEncoder->encodeRegisteredDelivery(m_nRegisteredDelivery);
			poEncoder->encodeSMDefaultMsgId(m_nSMDefaultMsgId);
			poEncoder->encodeSMLength(m_nSMLength);
			poEncoder->encodeShortMessage(m_aShortMessage);

			// Encode optional fields
			if(this->m_bPresentMessagePayload)
				poEncoder->encodeMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);

		}

		void SMPPReplaceSM::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());
			poDecoder->decodeSourceAddrTON(m_nSourceAddrTON, getCommandLength());
			poDecoder->decodeSourceAddrNPI(m_nSourceAddrNPI, getCommandLength());
			poDecoder->decodeSourceAddr21(m_sSourceAddr, getCommandLength());
			poDecoder->decodeScheduleDeliveryTime(m_sScheduleDeliveryTime, getCommandLength());
			poDecoder->decodeValidityPeriod(m_sValidityPeriod, getCommandLength());
			poDecoder->decodeRegisteredDelivery(m_nRegisteredDelivery, getCommandLength());
			poDecoder->decodeSMDefaultMsgId(m_nSMDefaultMsgId, getCommandLength());
			poDecoder->decodeSMLength(m_nSMLength, getCommandLength());
			poDecoder->decodeShortMessage(m_aShortMessage, m_nSMLength, getCommandLength());

			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_MESSAGE_PAYLOAD:{
						poDecoder->decodeMessagePayload(m_aMessagePayload,
							m_nMessagePayloadLen, this->getCommandLength());
						this->m_bPresentMessagePayload = true;
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
		void SMPPReplaceSM::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputMessageId(m_sMessageId);
			poOutputter->outputSourceAddrTON(m_nSourceAddrTON);
			poOutputter->outputSourceAddrNPI(m_nSourceAddrNPI);
			poOutputter->outputSourceAddr21(m_sSourceAddr);
			poOutputter->outputScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poOutputter->outputValidityPeriod(m_sValidityPeriod);
			poOutputter->outputRegisteredDelivery(m_nRegisteredDelivery);
			poOutputter->outputSMDefaultMsgId(m_nSMDefaultMsgId);
			poOutputter->outputSMLength(m_nSMLength);
			poOutputter->outputShortMessage(m_aShortMessage);

			// Output optional fields
			if(this->m_bPresentMessagePayload)
				poOutputter->outputMessagePayload(m_aMessagePayload, 
					m_nMessagePayloadLen);

		}

		void SMPPReplaceSM::validatePacket(SMPPValidator* poValidator){

			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateMessageId(m_sMessageId);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddrNPI(m_nSourceAddrNPI);
			poValidator->validateSourceAddr21(m_sSourceAddr);
			poValidator->validateScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poValidator->validateValidityPeriod(m_sValidityPeriod);
			poValidator->validateRegisteredDelivery(m_nRegisteredDelivery);
			poValidator->validateSMDefaultMsgId(m_nSMDefaultMsgId);
			poValidator->validateSMLength(m_nSMLength);
			poValidator->validateShortMessage(m_aShortMessage,m_nSMLength);

			// Encode optional fields
			if(this->m_bPresentMessagePayload)
				poValidator->validateMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);

			// Validate complex rules
			if(this->m_bPresentMessagePayload)
				poValidator->validateShortMessagePayload(m_aShortMessage, m_aMessagePayload);

		}

	}
}
