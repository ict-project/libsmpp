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
#include "SMPPQueryBroadcastSMResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPQueryBroadcastSMResp::SMPPQueryBroadcastSMResp(void):
			SMPPResp(CommandId::CM_QUERY_BROADCAST_SM_RESP),
			m_sMessageId(""),
			m_nMessageState(0),
			m_aBroadcastAreaIdentifier(),
			m_nBroadcastAreaSuccess(),
			m_nUserMessageReference(0),
			m_sBroadcastEndTime(""),
			m_bPresentMessageState(false),
			m_bPresentBroadcastAreaIdentifier(false),
			m_bPresentBroadcastAreaSuccess(false),
			m_bPresentUserMessageReference(false),
			m_bPresentBroadcastEndTime(false),
			m_nMessageStateLen(sizeof(char)),
			m_aBroadcastAreaIdentifierLen(0),
			m_nBroadcastAreaSuccessLen(sizeof(char)),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nBroadcastEndTimeLen(m_sBroadcastEndTime.size() + 1){
		}

		SMPPQueryBroadcastSMResp::SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSMResp& oPackage):
			SMPPResp(CommandId::CM_QUERY_BROADCAST_SM_RESP, oPackage.getSequenceNumber()),
			m_sMessageId(""),
			m_nMessageState(0),
			m_aBroadcastAreaIdentifier(),
			m_nBroadcastAreaSuccess(),
			m_nUserMessageReference(0),
			m_sBroadcastEndTime(""),
			m_bPresentMessageState(false),
			m_bPresentBroadcastAreaIdentifier(false),
			m_bPresentBroadcastAreaSuccess(false),
			m_bPresentUserMessageReference(false),
			m_bPresentBroadcastEndTime(false),
			m_nMessageStateLen(sizeof(char)),
			m_aBroadcastAreaIdentifierLen(0),
			m_nBroadcastAreaSuccessLen(sizeof(char)),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nBroadcastEndTimeLen(m_sBroadcastEndTime.size() + 1){
		}

		SMPPQueryBroadcastSMResp::SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSM& oPackage):
			SMPPResp(CommandId::CM_QUERY_BROADCAST_SM_RESP, oPackage.getSequenceNumber()),
			m_sMessageId(""),
			m_nMessageState(0),
			m_aBroadcastAreaIdentifier(),
			m_nBroadcastAreaSuccess(),
			m_nUserMessageReference(0),
			m_sBroadcastEndTime(""),
			m_bPresentMessageState(false),
			m_bPresentBroadcastAreaIdentifier(false),
			m_bPresentBroadcastAreaSuccess(false),
			m_bPresentUserMessageReference(false),
			m_bPresentBroadcastEndTime(false),
			m_nMessageStateLen(sizeof(char)),
			m_aBroadcastAreaIdentifierLen(0),
			m_nBroadcastAreaSuccessLen(sizeof(char)),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nBroadcastEndTimeLen(m_sBroadcastEndTime.size() + 1){
		}

		SMPPQueryBroadcastSMResp::SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSM& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_QUERY_BROADCAST_SM_RESP, oPackage.getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_nMessageState(0),
			m_aBroadcastAreaIdentifier(),
			m_nBroadcastAreaSuccess(),
			m_nUserMessageReference(0),
			m_sBroadcastEndTime(""),
			m_bPresentMessageState(false),
			m_bPresentBroadcastAreaIdentifier(false),
			m_bPresentBroadcastAreaSuccess(false),
			m_bPresentUserMessageReference(false),
			m_bPresentBroadcastEndTime(false),
			m_nMessageStateLen(sizeof(char)),
			m_aBroadcastAreaIdentifierLen(0),
			m_nBroadcastAreaSuccessLen(sizeof(char)),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nBroadcastEndTimeLen(m_sBroadcastEndTime.size() + 1){
		}

		SMPPQueryBroadcastSMResp::SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSM::SharedPtr poPackage):
			SMPPResp(CommandId::CM_QUERY_BROADCAST_SM_RESP, poPackage->getSequenceNumber()),
			m_sMessageId(""),
			m_nMessageState(0),
			m_aBroadcastAreaIdentifier(),
			m_nBroadcastAreaSuccess(),
			m_nUserMessageReference(0),
			m_sBroadcastEndTime(""),
			m_bPresentMessageState(false),
			m_bPresentBroadcastAreaIdentifier(false),
			m_bPresentBroadcastAreaSuccess(false),
			m_bPresentUserMessageReference(false),
			m_bPresentBroadcastEndTime(false),
			m_nMessageStateLen(sizeof(char)),
			m_aBroadcastAreaIdentifierLen(0),
			m_nBroadcastAreaSuccessLen(sizeof(char)),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nBroadcastEndTimeLen(m_sBroadcastEndTime.size() + 1){
		}

		SMPPQueryBroadcastSMResp::SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSM::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_QUERY_BROADCAST_SM_RESP, poPackage->getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_nMessageState(0),
			m_aBroadcastAreaIdentifier(),
			m_nBroadcastAreaSuccess(),
			m_nUserMessageReference(0),
			m_sBroadcastEndTime(""),
			m_bPresentMessageState(false),
			m_bPresentBroadcastAreaIdentifier(false),
			m_bPresentBroadcastAreaSuccess(false),
			m_bPresentUserMessageReference(false),
			m_bPresentBroadcastEndTime(false),
			m_nMessageStateLen(sizeof(char)),
			m_aBroadcastAreaIdentifierLen(0),
			m_nBroadcastAreaSuccessLen(sizeof(char)),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nBroadcastEndTimeLen(m_sBroadcastEndTime.size() + 1){
		}

		SMPPQueryBroadcastSMResp::~SMPPQueryBroadcastSMResp(){
		}

		SMPPPDU* SMPPQueryBroadcastSMResp::cloneSMPPPDU(void){
			return new SMPPQueryBroadcastSMResp();
		}

		void SMPPQueryBroadcastSMResp::fireOnReceived(SMPPSession* poSession){
			SMPPQueryBroadcastSMResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPQueryBroadcastSMResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeMessageId(m_sMessageId);

			// Encode mandatory fields as TLV structures
			poEncoder->encodeMessageStateTLV(m_nMessageState,
				m_nMessageStateLen);
			poEncoder->encodeBroadcastAreaIdentifier(m_aBroadcastAreaIdentifier,
				m_aBroadcastAreaIdentifierLen);
			poEncoder->encodeBroadcastAreaSuccess(m_nBroadcastAreaSuccess,
				m_nBroadcastAreaSuccessLen);


			// Encode optional fields
			if(this->m_bPresentUserMessageReference)
				poEncoder->encodeUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentBroadcastEndTime)
				poEncoder->encodeBroadcastEndTime(m_sBroadcastEndTime,
					m_nBroadcastEndTimeLen);
		}

		void SMPPQueryBroadcastSMResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());

			// Decode mandatory fields as TLV structures
			if(poDecoder->hasTLVs() && poDecoder->getTLVCode() == OptTags::TAG_MESSAGE_STATE){
				poDecoder->decodeMessageStateTLV(m_nMessageState,
					m_nMessageStateLen, this->getCommandLength());
				this->m_bPresentMessageState = true;
			}
			while (poDecoder->hasTLVs() && poDecoder->getTLVCode() == OptTags::TAG_BROADCAST_AREA_IDENTIFIER){
				poDecoder->decodeBroadcastAreaIdentifier(m_aBroadcastAreaIdentifier,
					m_aBroadcastAreaIdentifierLen, this->getCommandLength());
				this->m_bPresentBroadcastAreaIdentifier = true;
			}
			if(poDecoder->hasTLVs() && poDecoder->getTLVCode() == OptTags::TAG_BROADCAST_AREA_SUCCESS){
				poDecoder->decodeBroadcastAreaSuccess(m_nBroadcastAreaSuccess,
					m_nBroadcastAreaSuccessLen, this->getCommandLength());
				this->m_bPresentBroadcastAreaSuccess = true;
			}

			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_USER_MESSAGE_REFERENCE:{
						poDecoder->decodeUserMessageReference(m_nUserMessageReference,
							m_nUserMessageReferenceLen, this->getCommandLength());
						this->m_bPresentUserMessageReference = true;
						break;
					}
					case OptTags::TAG_BROADCAST_END_TIME:{
						poDecoder->decodeBroadcastEndTime(m_sBroadcastEndTime,
							m_nBroadcastEndTimeLen, this->getCommandLength());
						this->m_bPresentBroadcastEndTime = true;
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

		void SMPPQueryBroadcastSMResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputMessageId(m_sMessageId);
			poOutputter->outputMessageStateTLV(m_nMessageState, 
				m_nMessageStateLen);
			poOutputter->outputBroadcastAreaIdentifier(m_aBroadcastAreaIdentifier,
				m_aBroadcastAreaIdentifierLen);
			poOutputter->outputBroadcastAreaSuccess(m_nBroadcastAreaSuccess,
				m_nBroadcastAreaSuccessLen);


			// Output optional fields
			if(this->m_bPresentUserMessageReference)
				poOutputter->outputUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentBroadcastEndTime)
				poOutputter->outputBroadcastEndTime(m_sBroadcastEndTime,
					m_nBroadcastEndTimeLen);

		}

		void SMPPQueryBroadcastSMResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateMessageId(m_sMessageId);

			// Encode mandatory fields as TLV structures
			poValidator->validateMessageStateTLV(m_nMessageState,
				m_nMessageStateLen);
			poValidator->validateBroadcastAreaIdentifier(m_aBroadcastAreaIdentifier,
				m_aBroadcastAreaIdentifierLen);
			poValidator->validateBroadcastAreaSuccess(m_nBroadcastAreaSuccess,
				m_nBroadcastAreaSuccessLen);


			// Encode optional fields
			if(this->m_bPresentUserMessageReference)
				poValidator->validateUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentBroadcastEndTime)
				poValidator->validateBroadcastEndTime(m_sBroadcastEndTime,
					m_nBroadcastEndTimeLen);
		}
	}
}
