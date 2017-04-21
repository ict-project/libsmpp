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
#include "SMPPBroadcastSMResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPBroadcastSMResp::SMPPBroadcastSMResp(void):
			SMPPResp(CommandId::CM_BROADCAST_SM_RESP),
			m_sMessageId(""),
			m_nBroadcastErrorStatus(0),
			m_aFailedBroadcastAreaIdentifier(),
			m_bPresentBroadcastErrorStatus(false),
			m_bPresentFailedBroadcastAreaIdentifier(false),
			m_nBroadcastErrorStatusLen(sizeof(unsigned)),
			m_aFailedBroadcastAreaIdentifierLen(0){
		}

		SMPPBroadcastSMResp::SMPPBroadcastSMResp(const SMPPBroadcastSMResp&):
			SMPPResp(CommandId::CM_BROADCAST_SM_RESP),
			m_sMessageId(""),
			m_nBroadcastErrorStatus(0),
			m_aFailedBroadcastAreaIdentifier(),
			m_bPresentBroadcastErrorStatus(false),
			m_bPresentFailedBroadcastAreaIdentifier(false),
			m_nBroadcastErrorStatusLen(sizeof(unsigned)),
			m_aFailedBroadcastAreaIdentifierLen(0){
		}

		SMPPBroadcastSMResp::SMPPBroadcastSMResp(const SMPPBroadcastSM& oPackage):
			SMPPResp(CommandId::CM_BROADCAST_SM_RESP, oPackage.getSequenceNumber()),
			m_sMessageId(""),
			m_nBroadcastErrorStatus(0),
			m_aFailedBroadcastAreaIdentifier(),
			m_bPresentBroadcastErrorStatus(false),
			m_bPresentFailedBroadcastAreaIdentifier(false),
			m_nBroadcastErrorStatusLen(sizeof(unsigned)),
			m_aFailedBroadcastAreaIdentifierLen(0){
		}


		SMPPBroadcastSMResp::SMPPBroadcastSMResp(const SMPPBroadcastSM& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_BROADCAST_SM_RESP, oPackage.getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_nBroadcastErrorStatus(0),
			m_aFailedBroadcastAreaIdentifier(),
			m_bPresentBroadcastErrorStatus(false),
			m_bPresentFailedBroadcastAreaIdentifier(false),
			m_nBroadcastErrorStatusLen(sizeof(unsigned)),
			m_aFailedBroadcastAreaIdentifierLen(0){
		}


		SMPPBroadcastSMResp::SMPPBroadcastSMResp(const SMPPBroadcastSM::SharedPtr poPackage):
			SMPPResp(CommandId::CM_BROADCAST_SM_RESP, poPackage->getSequenceNumber()),
			m_sMessageId(""),
			m_nBroadcastErrorStatus(0),
			m_aFailedBroadcastAreaIdentifier(),
			m_bPresentBroadcastErrorStatus(false),
			m_bPresentFailedBroadcastAreaIdentifier(false),
			m_nBroadcastErrorStatusLen(sizeof(unsigned)),
			m_aFailedBroadcastAreaIdentifierLen(0){
		}


		SMPPBroadcastSMResp::SMPPBroadcastSMResp(const SMPPBroadcastSM::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_BROADCAST_SM_RESP, poPackage->getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_nBroadcastErrorStatus(0),
			m_aFailedBroadcastAreaIdentifier(),
			m_bPresentBroadcastErrorStatus(false),
			m_bPresentFailedBroadcastAreaIdentifier(false),
			m_nBroadcastErrorStatusLen(sizeof(unsigned)),
			m_aFailedBroadcastAreaIdentifierLen(0){
		}


		SMPPBroadcastSMResp::~SMPPBroadcastSMResp(){
		}

		SMPPPDU* SMPPBroadcastSMResp::cloneSMPPPDU(void){
			return new SMPPBroadcastSMResp();
		}

		void SMPPBroadcastSMResp::fireOnReceived(SMPPSession* poSession){
			SMPPBroadcastSMResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPBroadcastSMResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeMessageId(m_sMessageId);

			// Encode optional fields
			if(this->m_bPresentBroadcastErrorStatus)
				poEncoder->encodeBroadcastErrorStatus(m_nBroadcastErrorStatus,
					m_nBroadcastErrorStatusLen);
			if(this->m_bPresentFailedBroadcastAreaIdentifier)
				poEncoder->encodeFailedBroadcastAreaIdentifier(m_aFailedBroadcastAreaIdentifier,
					m_aFailedBroadcastAreaIdentifierLen);
		}

		void SMPPBroadcastSMResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());

			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_BROADCAST_ERROR_STATUS:{
						poDecoder->decodeBroadcastErrorStatus(m_nBroadcastErrorStatus,
							m_nBroadcastErrorStatusLen, this->getCommandLength());
						this->m_bPresentBroadcastErrorStatus = true;
						break;
					}
					case OptTags::TAG_BROADCAST_AREA_IDENTIFIER:{ 
						poDecoder->decodeFailedBroadcastAreaIdentifier(m_aFailedBroadcastAreaIdentifier,
							m_aFailedBroadcastAreaIdentifierLen, this->getCommandLength());
						this->m_bPresentFailedBroadcastAreaIdentifier = true;
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

		void SMPPBroadcastSMResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputMessageId(m_sMessageId);

			// Output optional fields
			if(this->m_bPresentBroadcastErrorStatus)
				poOutputter->outputBroadcastErrorStatus(m_nBroadcastErrorStatus,
					m_nBroadcastErrorStatusLen);
			if(this->m_bPresentFailedBroadcastAreaIdentifier)
				poOutputter->outputFailedBroadcastAreaIdentifier(m_aFailedBroadcastAreaIdentifier,
					m_aFailedBroadcastAreaIdentifierLen);

		}

		void SMPPBroadcastSMResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateMessageId(m_sMessageId);

			// Encode optional fields
			if(this->m_bPresentBroadcastErrorStatus)
				poValidator->validateBroadcastErrorStatus(m_nBroadcastErrorStatus,
					m_nBroadcastErrorStatusLen);
			if(this->m_bPresentFailedBroadcastAreaIdentifier)
				poValidator->validateFailedBroadcastAreaIdentifier(m_aFailedBroadcastAreaIdentifier,
					m_aFailedBroadcastAreaIdentifierLen);
		}
	}
}
