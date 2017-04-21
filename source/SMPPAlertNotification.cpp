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
#include "SMPPAlertNotification.hpp"


namespace anthill {
	namespace smpp {

		SMPPAlertNotification::SMPPAlertNotification(void):
			SMPPPDU(CommandId::CM_ALERT_NOTIFICATION),
			m_nMSAvailabilityStatusLen(sizeof(char)){
		}

		SMPPAlertNotification::SMPPAlertNotification(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_ALERT_NOTIFICATION, nSequenceNumber),
			m_nMSAvailabilityStatusLen(sizeof(char)){
		}

		SMPPAlertNotification::~SMPPAlertNotification(){
		}

		SMPPPDU* SMPPAlertNotification::cloneSMPPPDU(void){
			return new SMPPAlertNotification();
		}

		void SMPPAlertNotification::fireOnReceived(SMPPSession* poSession){
			SMPPAlertNotification::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPAlertNotification::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeSourceAddrTON(m_nSourceAddrTON);
			poEncoder->encodeSourceAddrNPI(m_nSourceAddrNPI);
			poEncoder->encodeSourceAddr65(m_sSourceAddr);
			poEncoder->encodeESMEAddrTON(m_nESMEAddrTON);
			poEncoder->encodeESMEAddrNPI(m_nESMEAddrNPI);
			poEncoder->encodeESMEAddr(m_sESMEAddr);

			// Encode optional fields
			if(this->m_bPresentMSAvailabilityStatus)
				poEncoder->encodeMSAvailabilityStatus(m_nMSAvailabilityStatus,
					m_nMSAvailabilityStatusLen);
		}

		void SMPPAlertNotification::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeSourceAddrTON(m_nSourceAddrTON, getCommandLength());
			poDecoder->decodeSourceAddrNPI(m_nSourceAddrNPI, getCommandLength());
			poDecoder->decodeSourceAddr65(m_sSourceAddr, getCommandLength());
			poDecoder->decodeESMEAddrTON(m_nESMEAddrTON, getCommandLength());
			poDecoder->decodeESMEAddrNPI(m_nESMEAddrNPI, getCommandLength());
			poDecoder->decodeESMEAddr(m_sESMEAddr, getCommandLength());

			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_MS_AVAILABILITY_STATUS:{
						poDecoder->decodeMSAvailabilityStatus(m_nMSAvailabilityStatus,
							m_nMSAvailabilityStatusLen, this->getCommandLength());
						this->m_bPresentMSAvailabilityStatus = true;
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

		void SMPPAlertNotification::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputSourceAddrTON(m_nSourceAddrTON);
			poOutputter->outputSourceAddrNPI(m_nSourceAddrNPI);
			poOutputter->outputSourceAddr65(m_sSourceAddr);
			poOutputter->outputESMEAddrTON(m_nESMEAddrTON);
			poOutputter->outputESMEAddrNPI(m_nESMEAddrNPI);
			poOutputter->outputESMEAddr(m_sESMEAddr);

			// Output optional fields
			if(this->m_bPresentMSAvailabilityStatus)
				poOutputter->outputMSAvailabilityStatus(m_nMSAvailabilityStatus, 
					m_nMSAvailabilityStatusLen);

		}

		void SMPPAlertNotification::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddrNPI(m_nSourceAddrNPI);
			poValidator->validateSourceAddr65(m_sSourceAddr);
			poValidator->validateESMEAddrTON(m_nESMEAddrTON);
			poValidator->validateESMEAddrNPI(m_nESMEAddrNPI);
			poValidator->validateESMEAddr(m_sESMEAddr);

			// Encode optional fields
			if(this->m_bPresentMSAvailabilityStatus)
				poValidator->validateMSAvailabilityStatus(m_nMSAvailabilityStatus,
					m_nMSAvailabilityStatusLen);
		}
	}
}
