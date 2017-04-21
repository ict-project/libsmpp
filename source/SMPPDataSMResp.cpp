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
#include "SMPPDataSMResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPDataSMResp::SMPPDataSMResp(void):
			SMPPResp(CommandId::CM_DATA_SM_RESP),
			m_sMessageId(""),
			m_nDeliveryFailureReason(0),
			m_oNetworkErrorCode(),
			m_aAdditionalStatusInfoText(),
			m_nDpfResult(0),
			m_bPresentDeliveryFailureReason(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentAdditionalStatusInfoText(false),
			m_bPresentDpfResult(false),
			m_nDeliveryFailureReasonLen(sizeof(char)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nAdditionalStatusInfoTextLen(m_aAdditionalStatusInfoText.size()),
			m_nDpfResultLen(sizeof(char)){
		}

		SMPPDataSMResp::SMPPDataSMResp(const SMPPDataSMResp&):
			SMPPResp(CommandId::CM_DATA_SM_RESP),
			m_sMessageId(""),
			m_nDeliveryFailureReason(0),
			m_oNetworkErrorCode(),
			m_aAdditionalStatusInfoText(),
			m_nDpfResult(0),
			m_bPresentDeliveryFailureReason(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentAdditionalStatusInfoText(false),
			m_bPresentDpfResult(false),
			m_nDeliveryFailureReasonLen(sizeof(char)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nAdditionalStatusInfoTextLen(m_aAdditionalStatusInfoText.size()),
			m_nDpfResultLen(sizeof(char)){
		}


		SMPPDataSMResp::SMPPDataSMResp(const SMPPDataSM& oPackage):
			SMPPResp(CommandId::CM_DATA_SM_RESP, oPackage.getSequenceNumber()),
			m_sMessageId(""),
			m_nDeliveryFailureReason(0),
			m_oNetworkErrorCode(),
			m_aAdditionalStatusInfoText(),
			m_nDpfResult(0),
			m_bPresentDeliveryFailureReason(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentAdditionalStatusInfoText(false),
			m_bPresentDpfResult(false),
			m_nDeliveryFailureReasonLen(sizeof(char)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nAdditionalStatusInfoTextLen(m_aAdditionalStatusInfoText.size()),
			m_nDpfResultLen(sizeof(char)){
		}


		SMPPDataSMResp::SMPPDataSMResp(const SMPPDataSM& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_DATA_SM_RESP, oPackage.getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_nDeliveryFailureReason(0),
			m_oNetworkErrorCode(),
			m_aAdditionalStatusInfoText(),
			m_nDpfResult(0),
			m_bPresentDeliveryFailureReason(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentAdditionalStatusInfoText(false),
			m_bPresentDpfResult(false),
			m_nDeliveryFailureReasonLen(sizeof(char)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nAdditionalStatusInfoTextLen(m_aAdditionalStatusInfoText.size()),
			m_nDpfResultLen(sizeof(char)){
		}

		SMPPDataSMResp::SMPPDataSMResp(const SMPPDataSM::SharedPtr poPackage):
			SMPPResp(CommandId::CM_DATA_SM_RESP, poPackage->getSequenceNumber()),
			m_sMessageId(""),
			m_nDeliveryFailureReason(0),
			m_oNetworkErrorCode(),
			m_aAdditionalStatusInfoText(),
			m_nDpfResult(0),
			m_bPresentDeliveryFailureReason(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentAdditionalStatusInfoText(false),
			m_bPresentDpfResult(false),
			m_nDeliveryFailureReasonLen(sizeof(char)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nAdditionalStatusInfoTextLen(m_aAdditionalStatusInfoText.size()),
			m_nDpfResultLen(sizeof(char)){
		}


		SMPPDataSMResp::SMPPDataSMResp(const SMPPDataSM::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_DATA_SM_RESP, poPackage->getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_nDeliveryFailureReason(0),
			m_oNetworkErrorCode(),
			m_aAdditionalStatusInfoText(),
			m_nDpfResult(0),
			m_bPresentDeliveryFailureReason(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentAdditionalStatusInfoText(false),
			m_bPresentDpfResult(false),
			m_nDeliveryFailureReasonLen(sizeof(char)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nAdditionalStatusInfoTextLen(m_aAdditionalStatusInfoText.size()),
			m_nDpfResultLen(sizeof(char)){
		}



		SMPPDataSMResp::~SMPPDataSMResp(){
		}

		SMPPPDU* SMPPDataSMResp::cloneSMPPPDU(void){
			return new SMPPDataSMResp();
		}

		void SMPPDataSMResp::fireOnReceived(SMPPSession* poSession){
			SMPPDataSMResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPDataSMResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeMessageId(m_sMessageId);

			// Encode optional fields
			if(this->m_bPresentDeliveryFailureReason)
				poEncoder->encodeDeliveryFailureReason(m_nDeliveryFailureReason,
					m_nDeliveryFailureReasonLen);
			if(this->m_bPresentNetworkErrorCode)
				poEncoder->encodeNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentAdditionalStatusInfoText)
				poEncoder->encodeAdditionalStatusInfoText(m_aAdditionalStatusInfoText,
					m_nAdditionalStatusInfoTextLen);
			if(this->m_bPresentDpfResult)
				poEncoder->encodeDpfResult(m_nDpfResult,
					m_nDpfResultLen);

		}

		void SMPPDataSMResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());

			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_DELIVERY_FAILURE_REASON:{
						poDecoder->decodeDeliveryFailureReason(m_nDeliveryFailureReason,
							m_nDeliveryFailureReasonLen, this->getCommandLength());
						this->m_bPresentDeliveryFailureReason = true;
						break;
					}
					case OptTags::TAG_NETWORK_ERROR_CODE:{
						poDecoder->decodeNetworkErrorCode(m_oNetworkErrorCode,
							m_nNetworkErrorCodeLen, this->getCommandLength());
						this->m_bPresentNetworkErrorCode = true;
						break;
					}
					case OptTags::TAG_ADDITIONAL_STATUS_INFO_TEXT:{
						poDecoder->decodeAdditionalStatusInfoText(m_aAdditionalStatusInfoText,
							m_nAdditionalStatusInfoTextLen, this->getCommandLength());
						this->m_bPresentAdditionalStatusInfoText = true;
						break;
					}
					case OptTags::TAG_DPF_RESULT:{
						poDecoder->decodeDpfResult(m_nDpfResult,
							m_nDpfResultLen, this->getCommandLength());
						this->m_bPresentDpfResult = true;
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

		void SMPPDataSMResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputMessageId(m_sMessageId);

			// Output optional fields
			if(this->m_bPresentDeliveryFailureReason)
				poOutputter->outputDeliveryFailureReason(m_nDeliveryFailureReason,
					m_nDeliveryFailureReasonLen);
			if(this->m_bPresentNetworkErrorCode)
				poOutputter->outputNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentAdditionalStatusInfoText)
				poOutputter->outputAdditionalStatusInfoText(m_aAdditionalStatusInfoText,
					m_nAdditionalStatusInfoTextLen);
			if(this->m_bPresentDpfResult)
				poOutputter->outputDpfResult(m_nDpfResult,
					m_nDpfResultLen);

		}

		void SMPPDataSMResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateMessageId(m_sMessageId);

			// Encode optional fields
			if(this->m_bPresentDeliveryFailureReason)
				poValidator->validateDeliveryFailureReason(m_nDeliveryFailureReason,
					m_nDeliveryFailureReasonLen);
			if(this->m_bPresentNetworkErrorCode)
				poValidator->validateNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentAdditionalStatusInfoText)
				poValidator->validateAdditionalStatusInfoText(m_aAdditionalStatusInfoText,
					m_nAdditionalStatusInfoTextLen);
			if(this->m_bPresentDpfResult)
				poValidator->validateDpfResult(m_nDpfResult,
					m_nDpfResultLen);

		}

	}
}
