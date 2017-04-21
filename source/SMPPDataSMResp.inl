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

		inline const bool SMPPDataSMResp::isPresentDeliveryFailureReason(void) const{
			return this->m_bPresentDeliveryFailureReason;
		}

		inline void SMPPDataSMResp::omitPresentDeliveryFailureReason(void){
			this->m_bPresentDeliveryFailureReason = false;
		}

		inline void SMPPDataSMResp::setPresentDeliveryFailureReason(const bool bPresentDeliveryFailureReason){
			this->m_bPresentDeliveryFailureReason = bPresentDeliveryFailureReason;
		}

		inline const bool SMPPDataSMResp::isPresentNetworkErrorCode(void) const{
			return this->m_bPresentNetworkErrorCode;
		}

		inline void SMPPDataSMResp::omitPresentNetworkErrorCode(void){
			this->m_bPresentNetworkErrorCode = false;
		}

		inline void SMPPDataSMResp::setPresentNetworkErrorCode(const bool bPresentNetworkErrorCode){
			this->m_bPresentNetworkErrorCode = bPresentNetworkErrorCode;
		}


		inline const bool SMPPDataSMResp::isPresentAdditionalStatusInfoText(void) const{
			return this->m_bPresentAdditionalStatusInfoText;
		}

		inline void SMPPDataSMResp::omitPresentAdditionalStatusInfoText(void){
			this->m_bPresentAdditionalStatusInfoText = false;
		}

		inline void SMPPDataSMResp::setPresentAdditionalStatusInfoText(const bool bPresentAdditionalStatusInfoText){
			this->m_bPresentAdditionalStatusInfoText = bPresentAdditionalStatusInfoText;
		}


		inline const bool SMPPDataSMResp::isPresentDpfResult(void) const{
			return this->m_bPresentDpfResult;
		}

		inline void SMPPDataSMResp::omitPresentDpfResult(void){
			this->m_bPresentDpfResult = false;
		}

		inline void SMPPDataSMResp::setPresentDpfResult(const bool bPresentDpfResult){
			this->m_bPresentDpfResult = bPresentDpfResult;
		}

		inline void SMPPDataSMResp::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPDataSMResp::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPDataSMResp::getMessageId(void) const{
			return this->m_sMessageId;
		}


		inline void SMPPDataSMResp::setDeliveryFailureReason(const unsigned char nDeliveryFailureReason){
			this->m_nDeliveryFailureReason = nDeliveryFailureReason;
			this->m_bPresentDeliveryFailureReason = true;
		}

		inline unsigned char& SMPPDataSMResp::refDeliveryFailureReason(void){
			return this->m_nDeliveryFailureReason;
		}

		inline const unsigned char SMPPDataSMResp::getDeliveryFailureReason(void) const{
			return this->m_nDeliveryFailureReason;
		}

		inline void SMPPDataSMResp::setNetworkErrorCode(const unsigned char nNetworkCode, const unsigned short nErrorCode){
			this->m_oNetworkErrorCode.setNetworkCode(nNetworkCode);
			this->m_oNetworkErrorCode.setErrorCode(nErrorCode);
			this->m_bPresentNetworkErrorCode = true;
		}

		inline void SMPPDataSMResp::setNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode){
			this->m_oNetworkErrorCode = oNetworkErrorCode;
			this->m_bPresentNetworkErrorCode = true;
		}

		inline NetworkErrorCode& SMPPDataSMResp::refNetworkErrorCode(void){
			return this->m_oNetworkErrorCode;
		}

		inline const NetworkErrorCode& SMPPDataSMResp::getNetworkErrorCode(void) const{
			return this->m_oNetworkErrorCode;
		}

		inline void SMPPDataSMResp::setAdditionalStatusInfoText(const std::vector<unsigned char>& aAdditionalStatusInfoText){
			this->m_nAdditionalStatusInfoTextLen = aAdditionalStatusInfoText.size();
			this->m_aAdditionalStatusInfoText = aAdditionalStatusInfoText;
			this->m_bPresentAdditionalStatusInfoText = true;
		}

		inline void SMPPDataSMResp::setAdditionalStatusInfoText(const std::string& sAdditionalStatusInfoText){
			this->m_nAdditionalStatusInfoTextLen = sAdditionalStatusInfoText.size();
			this->m_aAdditionalStatusInfoText.resize(sAdditionalStatusInfoText.size());
			this->m_aAdditionalStatusInfoText.assign(sAdditionalStatusInfoText.begin(), sAdditionalStatusInfoText.end());
			this->m_bPresentAdditionalStatusInfoText = true;
		}

		inline std::vector<unsigned char>& SMPPDataSMResp::refAdditionalStatusInfoText(void){
			return this->m_aAdditionalStatusInfoText;
		}

		inline const std::vector<unsigned char>& SMPPDataSMResp::getAdditionalStatusInfoText(void) const{
			return this->m_aAdditionalStatusInfoText;
		}


		inline void SMPPDataSMResp::setDpfResult(const unsigned char nDpfResult){
			this->m_nDpfResult = nDpfResult;
			this->m_bPresentDpfResult = true;
		}

		inline unsigned char& SMPPDataSMResp::refDpfResult(void){
			return this->m_nDpfResult;
		}

		inline const unsigned char SMPPDataSMResp::getDpfResult(void) const{
			return this->m_nDpfResult;
		}

		inline void SMPPDataSMResp::setDeliveryFailureReasonLen(const unsigned short nDeliveryFailureReasonLen){
			this->m_nDeliveryFailureReasonLen = nDeliveryFailureReasonLen;
		}

		inline unsigned short& SMPPDataSMResp::refDeliveryFailureReasonLen(void){
			return this->m_nDeliveryFailureReasonLen;
		}

		inline const unsigned short SMPPDataSMResp::getDeliveryFailureReasonLen(void) const{
			return this->m_nDeliveryFailureReasonLen;
		}


		inline void SMPPDataSMResp::setNetworkErrorCodeLen(const unsigned short nNetworkErrorCodeLen){
			this->m_nNetworkErrorCodeLen = nNetworkErrorCodeLen;
		}

		inline unsigned short& SMPPDataSMResp::refNetworkErrorCodeLen(void){
			return this->m_nNetworkErrorCodeLen;
		}

		inline const unsigned short SMPPDataSMResp::getNetworkErrorCodeLen(void) const{
			return this->m_nNetworkErrorCodeLen;
		}


		inline void SMPPDataSMResp::setAdditionalStatusInfoTextLen(const unsigned short nAdditionalStatusInfoTextLen){
			this->m_nAdditionalStatusInfoTextLen = nAdditionalStatusInfoTextLen;
		}

		inline unsigned short& SMPPDataSMResp::refAdditionalStatusInfoTextLen(void){
			return this->m_nAdditionalStatusInfoTextLen;
		}

		inline const unsigned short SMPPDataSMResp::getAdditionalStatusInfoTextLen(void) const{
			return this->m_nAdditionalStatusInfoTextLen;
		}


		inline void SMPPDataSMResp::setDpfResultLen(const unsigned short nDpfResultLen){
			this->m_nDpfResultLen = nDpfResultLen;
		}

		inline unsigned short& SMPPDataSMResp::refDpfResultLen(void){
			return this->m_nDpfResultLen;
		}

		inline const unsigned short SMPPDataSMResp::getDpfResultLen(void) const{
			return this->m_nDpfResultLen;
		}



	}
}
