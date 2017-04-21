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

		inline const bool SMPPReplaceSM::isPresentMessagePayload(void) const{
			return this->m_bPresentMessagePayload;
		}

		inline void SMPPReplaceSM::omitPresentMessagePayload(void){
			this->m_bPresentMessagePayload = false;
		}

		inline void SMPPReplaceSM::setPresentMessagePayload(const bool bPresentMessagePayload){
			this->m_bPresentMessagePayload = bPresentMessagePayload;
		}

		inline void SMPPReplaceSM::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPReplaceSM::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPReplaceSM::getMessageId(void) const{
			return this->m_sMessageId;
		}


		inline void SMPPReplaceSM::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPReplaceSM::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPReplaceSM::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPReplaceSM::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPReplaceSM::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPReplaceSM::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPReplaceSM::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPReplaceSM::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPReplaceSM::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}

		inline void SMPPReplaceSM::setScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			this->m_sScheduleDeliveryTime = sScheduleDeliveryTime;
		}

		inline std::string& SMPPReplaceSM::refScheduleDeliveryTime(void){
			return this->m_sScheduleDeliveryTime;
		}

		inline const std::string& SMPPReplaceSM::getScheduleDeliveryTime(void) const{
			return this->m_sScheduleDeliveryTime;
		}


		inline void SMPPReplaceSM::setValidityPeriod(const std::string& sValidityPeriod){
			this->m_sValidityPeriod = sValidityPeriod;
		}

		inline std::string& SMPPReplaceSM::refValidityPeriod(void){
			return this->m_sValidityPeriod;
		}

		inline const std::string& SMPPReplaceSM::getValidityPeriod(void) const{
			return this->m_sValidityPeriod;
		}


		inline void SMPPReplaceSM::setRegisteredDelivery(const unsigned char nRegisteredDelivery){
			this->m_nRegisteredDelivery = nRegisteredDelivery;
		}

		inline unsigned char& SMPPReplaceSM::refRegisteredDelivery(void){
			return this->m_nRegisteredDelivery;
		}

		inline const unsigned char SMPPReplaceSM::getRegisteredDelivery(void) const{
			return this->m_nRegisteredDelivery;
		}

		inline void SMPPReplaceSM::setSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			this->m_nSMDefaultMsgId = nSMDefaultMsgId;
		}

		inline unsigned char& SMPPReplaceSM::refSMDefaultMsgId(void){
			return this->m_nSMDefaultMsgId;
		}

		inline const unsigned char SMPPReplaceSM::getSMDefaultMsgId(void) const{
			return this->m_nSMDefaultMsgId;
		}


		inline void SMPPReplaceSM::setSMLength(const unsigned char nSMLength){
			this->m_nSMLength = nSMLength;
		}

		inline unsigned char& SMPPReplaceSM::refSMLength(void){
			return this->m_nSMLength;
		}

		inline const unsigned char SMPPReplaceSM::getSMLength(void) const{
			return this->m_nSMLength;
		}


		inline void SMPPReplaceSM::setShortMessage(const std::vector<unsigned char>& aShortMessage){
			this->m_aShortMessage = aShortMessage;
			this->m_nSMLength = this->m_aShortMessage.size();
		}

		inline void SMPPReplaceSM::setShortMessage(const std::string& sShortMessage){
			this->m_aShortMessage.resize(sShortMessage.size());
			this->m_aShortMessage.assign(sShortMessage.begin(), sShortMessage.end());
			this->m_nSMLength = this->m_aShortMessage.size();
		}

		inline std::vector<unsigned char>& SMPPReplaceSM::refShortMessage(void){
			return this->m_aShortMessage;
		}

		inline const std::vector<unsigned char>& SMPPReplaceSM::getShortMessage(void) const{
			return this->m_aShortMessage;
		}

		inline void SMPPReplaceSM::setMessagePayload(const std::vector<unsigned char>& aMessagePayload){
			this->m_nMessagePayloadLen = aMessagePayload.size();
			this->m_aMessagePayload = aMessagePayload;
			this->m_bPresentMessagePayload = true;
		}

		inline std::vector<unsigned char>& SMPPReplaceSM::refMessagePayload(void){
			return this->m_aMessagePayload;
		}

		inline const std::vector<unsigned char>& SMPPReplaceSM::getMessagePayload(void) const{
			return this->m_aMessagePayload;
		}

		inline void SMPPReplaceSM::setMessagePayloadLen(const unsigned short nMessagePayloadLen){
			this->m_nMessagePayloadLen = nMessagePayloadLen;
		}

		inline unsigned short& SMPPReplaceSM::refMessagePayloadLen(void){
			return this->m_nMessagePayloadLen;
		}

		inline const unsigned short SMPPReplaceSM::getMessagePayloadLen(void) const{
			return this->m_nMessagePayloadLen;
		}



	}
}
