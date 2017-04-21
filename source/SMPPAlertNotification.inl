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

namespace anthill {
	namespace smpp {

		inline const bool SMPPAlertNotification::isPresentMSAvailabilityStatus(void) const{
			return this->m_bPresentMSAvailabilityStatus;
		}

		inline void SMPPAlertNotification::omitPresentMSAvailabilityStatus(void){
			this->m_bPresentMSAvailabilityStatus = false;
		}

		inline void SMPPAlertNotification::setPresentMSAvailabilityStatus(const bool bPresentMSAvailabilityStatus){
			this->m_bPresentMSAvailabilityStatus = bPresentMSAvailabilityStatus;
		}

		inline void SMPPAlertNotification::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}
			
		inline unsigned char& SMPPAlertNotification::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPAlertNotification::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}

		inline void SMPPAlertNotification::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}
			
		inline unsigned char& SMPPAlertNotification::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPAlertNotification::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}

		inline void SMPPAlertNotification::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}
			
		inline std::string& SMPPAlertNotification::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPAlertNotification::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}

		inline void SMPPAlertNotification::setESMEAddrTON(const unsigned char nESMEAddrTON){
			this->m_nESMEAddrTON = nESMEAddrTON;
		}
			
		inline unsigned char& SMPPAlertNotification::refESMEAddrTON(void){
			return this->m_nESMEAddrTON;
		}

		inline const unsigned char SMPPAlertNotification::getESMEAddrTON(void) const{
			return this->m_nESMEAddrTON;
		}

		inline void SMPPAlertNotification::setESMEAddrNPI(const unsigned char nESMEAddrNPI){
			this->m_nESMEAddrNPI = nESMEAddrNPI;
		}
			
		inline unsigned char& SMPPAlertNotification::refESMEAddrNPI(void){
			return this->m_nESMEAddrNPI;
		}

		inline const unsigned char SMPPAlertNotification::getESMEAddrNPI(void) const{
			return this->m_nESMEAddrNPI;
		}

		inline void SMPPAlertNotification::setESMEAddr(const std::string& sESMEAddr){
			this->m_sESMEAddr = sESMEAddr;
		}
			
		inline std::string& SMPPAlertNotification::refESMEAddr(void){
			return this->m_sESMEAddr;
		}

		inline const std::string& SMPPAlertNotification::getESMEAddr(void) const{
			return this->m_sESMEAddr;
		}

		inline void SMPPAlertNotification::setMSAvailabilityStatus(const unsigned char nMSAvailabilityStatus){
			this->m_nMSAvailabilityStatus = nMSAvailabilityStatus;
			this->m_bPresentMSAvailabilityStatus = true;
		}

		inline unsigned char& SMPPAlertNotification::refMSAvailabilityStatus(void){
			return this->m_nMSAvailabilityStatus;
		}

		inline const unsigned char SMPPAlertNotification::getMSAvailabilityStatus(void) const{
			return this->m_nMSAvailabilityStatus;
		}

		inline void SMPPAlertNotification::setMSAvailabilityStatusLen(const unsigned short nMSAvailabilityStatusLen){
			this->m_nMSAvailabilityStatusLen = nMSAvailabilityStatusLen;
		}

		inline unsigned short& SMPPAlertNotification::refMSAvailabilityStatusLen(void){
			return this->m_nMSAvailabilityStatusLen;
		}

		inline const unsigned short SMPPAlertNotification::getMSAvailabilityStatusLen(void) const{
			return this->m_nMSAvailabilityStatusLen;
		}

	}
}
