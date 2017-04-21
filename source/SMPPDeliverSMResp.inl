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

		inline const bool SMPPDeliverSMResp::isPresentAdditionalStatusInfoText(void) const{
			return this->m_bPresentAdditionalStatusInfoText;
		}

		inline void SMPPDeliverSMResp::omitPresentAdditionalStatusInfoText(void){
			this->m_bPresentAdditionalStatusInfoText = false;
		}

		inline void SMPPDeliverSMResp::setPresentAdditionalStatusInfoText(const bool bPresentAdditionalStatusInfoText){
			this->m_bPresentAdditionalStatusInfoText = bPresentAdditionalStatusInfoText;
		}


		inline const bool SMPPDeliverSMResp::isPresentDeliveryFailureReason(void) const{
			return this->m_bPresentDeliveryFailureReason;
		}

		inline void SMPPDeliverSMResp::omitPresentDeliveryFailureReason(void){
			this->m_bPresentDeliveryFailureReason = false;
		}

		inline void SMPPDeliverSMResp::setPresentDeliveryFailureReason(const bool bPresentDeliveryFailureReason){
			this->m_bPresentDeliveryFailureReason = bPresentDeliveryFailureReason;
		}

		inline const bool SMPPDeliverSMResp::isPresentNetworkErrorCode(void) const{
			return this->m_bPresentNetworkErrorCode;
		}

		inline void SMPPDeliverSMResp::omitPresentNetworkErrorCode(void){
			this->m_bPresentNetworkErrorCode = false;
		}

		inline void SMPPDeliverSMResp::setPresentNetworkErrorCode(const bool bPresentNetworkErrorCode){
			this->m_bPresentNetworkErrorCode = bPresentNetworkErrorCode;
		}


		inline void SMPPDeliverSMResp::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPDeliverSMResp::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPDeliverSMResp::getMessageId(void) const{
			return this->m_sMessageId;
		}

		inline void SMPPDeliverSMResp::setAdditionalStatusInfoText(const std::vector<unsigned char>& aAdditionalStatusInfoText){
			this->m_nAdditionalStatusInfoTextLen = aAdditionalStatusInfoText.size();
			this->m_aAdditionalStatusInfoText = aAdditionalStatusInfoText;
			this->m_bPresentAdditionalStatusInfoText = true;
		}

		inline void SMPPDeliverSMResp::setAdditionalStatusInfoText(const std::string& sAdditionalStatusInfoText){
			this->m_nAdditionalStatusInfoTextLen = sAdditionalStatusInfoText.size();
			this->m_aAdditionalStatusInfoText.resize(sAdditionalStatusInfoText.size());
			this->m_aAdditionalStatusInfoText.assign(sAdditionalStatusInfoText.begin(), sAdditionalStatusInfoText.end());
			this->m_bPresentAdditionalStatusInfoText = true;
		}

		inline std::vector<unsigned char>& SMPPDeliverSMResp::refAdditionalStatusInfoText(void){
			return this->m_aAdditionalStatusInfoText;
		}

		inline const std::vector<unsigned char>& SMPPDeliverSMResp::getAdditionalStatusInfoText(void) const{
			return this->m_aAdditionalStatusInfoText;
		}

		inline void SMPPDeliverSMResp::setDeliveryFailureReason(const unsigned char nDeliveryFailureReason){
			this->m_nDeliveryFailureReason = nDeliveryFailureReason;
			this->m_bPresentDeliveryFailureReason = true;
		}

		inline unsigned char& SMPPDeliverSMResp::refDeliveryFailureReason(void){
			return this->m_nDeliveryFailureReason;
		}

		inline const unsigned char SMPPDeliverSMResp::getDeliveryFailureReason(void) const{
			return this->m_nDeliveryFailureReason;
		}

		inline void SMPPDeliverSMResp::setNetworkErrorCode(const unsigned char nNetworkCode, const unsigned short nErrorCode){
			this->m_oNetworkErrorCode.setNetworkCode(nNetworkCode);
			this->m_oNetworkErrorCode.setErrorCode(nErrorCode);
			this->m_bPresentNetworkErrorCode = true;
		}

		inline void SMPPDeliverSMResp::setNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode){
			this->m_oNetworkErrorCode = oNetworkErrorCode;
			this->m_bPresentNetworkErrorCode = true;
		}

		inline NetworkErrorCode& SMPPDeliverSMResp::refNetworkErrorCode(void){
			return this->m_oNetworkErrorCode;
		}

		inline const NetworkErrorCode& SMPPDeliverSMResp::getNetworkErrorCode(void) const{
			return this->m_oNetworkErrorCode;
		}


		inline void SMPPDeliverSMResp::setAdditionalStatusInfoTextLen(const unsigned short nAdditionalStatusInfoTextLen){
			this->m_nAdditionalStatusInfoTextLen = nAdditionalStatusInfoTextLen;
		}

		inline unsigned short& SMPPDeliverSMResp::refAdditionalStatusInfoTextLen(void){
			return this->m_nAdditionalStatusInfoTextLen;
		}

		inline const unsigned short SMPPDeliverSMResp::getAdditionalStatusInfoTextLen(void) const{
			return this->m_nAdditionalStatusInfoTextLen;
		}



		inline void SMPPDeliverSMResp::setDeliveryFailureReasonLen(const unsigned short nDeliveryFailureReasonLen){
			this->m_nDeliveryFailureReasonLen = nDeliveryFailureReasonLen;
		}

		inline unsigned short& SMPPDeliverSMResp::refDeliveryFailureReasonLen(void){
			return this->m_nDeliveryFailureReasonLen;
		}

		inline const unsigned short SMPPDeliverSMResp::getDeliveryFailureReasonLen(void) const{
			return this->m_nDeliveryFailureReasonLen;
		}


		inline void SMPPDeliverSMResp::setNetworkErrorCodeLen(const unsigned short nNetworkErrorCodeLen){
			this->m_nNetworkErrorCodeLen = nNetworkErrorCodeLen;
		}

		inline unsigned short& SMPPDeliverSMResp::refNetworkErrorCodeLen(void){
			return this->m_nNetworkErrorCodeLen;
		}

		inline const unsigned short SMPPDeliverSMResp::getNetworkErrorCodeLen(void) const{
			return this->m_nNetworkErrorCodeLen;
		}

	}
}
