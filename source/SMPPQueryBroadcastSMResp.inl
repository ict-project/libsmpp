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

		inline const bool SMPPQueryBroadcastSMResp::isPresentMessageState(void) const{
			return this->m_bPresentMessageState;
		}

		inline void SMPPQueryBroadcastSMResp::omitPresentMessageState(void){
			this->m_bPresentMessageState = false;
		}

		inline void SMPPQueryBroadcastSMResp::setPresentMessageState(const bool bPresentMessageState){
			this->m_bPresentMessageState = bPresentMessageState;
		}



		inline const bool SMPPQueryBroadcastSMResp::isPresentBroadcastAreaIdentifier(void) const{
			return this->m_bPresentBroadcastAreaIdentifier;
		}

		inline void SMPPQueryBroadcastSMResp::omitPresentBroadcastAreaIdentifier(void){
			this->m_bPresentBroadcastAreaIdentifier = false;

		}

		inline void SMPPQueryBroadcastSMResp::setPresentBroadcastAreaIdentifier(const bool bPresentBroadcastAreaIdentifier){
			this->m_bPresentBroadcastAreaIdentifier = bPresentBroadcastAreaIdentifier;
		}


		inline const bool SMPPQueryBroadcastSMResp::isPresentBroadcastAreaSuccess(void) const{
			return this->m_bPresentBroadcastAreaSuccess;
		}

		inline void SMPPQueryBroadcastSMResp::omitPresentBroadcastAreaSuccess(void){
			this->m_bPresentBroadcastAreaSuccess = false;
		}

		inline void SMPPQueryBroadcastSMResp::setPresentBroadcastAreaSuccess(const bool bPresentBroadcastAreaSuccess){
			this->m_bPresentBroadcastAreaSuccess = bPresentBroadcastAreaSuccess;
		}


		inline const bool SMPPQueryBroadcastSMResp::isPresentBroadcastEndTime(void) const{
			return this->m_bPresentBroadcastEndTime;
		}

		inline void SMPPQueryBroadcastSMResp::omitPresentBroadcastEndTime(void){
			this->m_bPresentBroadcastEndTime = false;
		}

		inline void SMPPQueryBroadcastSMResp::setPresentBroadcastEndTime(const bool bPresentBroadcastEndTime){
			this->m_bPresentBroadcastEndTime = bPresentBroadcastEndTime;
		}

		inline const bool SMPPQueryBroadcastSMResp::isPresentUserMessageReference(void) const{
			return this->m_bPresentUserMessageReference;
		}

		inline void SMPPQueryBroadcastSMResp::omitPresentUserMessageReference(void){
			this->m_bPresentUserMessageReference = false;
		}

		inline void SMPPQueryBroadcastSMResp::setPresentUserMessageReference(const bool bPresentUserMessageReference){
			this->m_bPresentUserMessageReference = bPresentUserMessageReference;
		}


		inline void SMPPQueryBroadcastSMResp::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPQueryBroadcastSMResp::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPQueryBroadcastSMResp::getMessageId(void) const{
			return this->m_sMessageId;
		}

		inline void SMPPQueryBroadcastSMResp::setMessageState(const unsigned char nMessageState){
			this->m_nMessageState = nMessageState;
			this->m_bPresentMessageState = true;
		}

		inline unsigned char& SMPPQueryBroadcastSMResp::refMessageState(void){
			return this->m_nMessageState;
		}

		inline const unsigned char SMPPQueryBroadcastSMResp::getMessageState(void) const{
			return this->m_nMessageState;
		}

		inline void SMPPQueryBroadcastSMResp::addBroadcastAreaIdentifier(const std::vector<unsigned char>& aBroadcastAreaIdentifier){
			this->m_aBroadcastAreaIdentifier.push_back(BroadcastAreaIdentifier(aBroadcastAreaIdentifier));
			this->m_bPresentBroadcastAreaIdentifier = true;

			this->m_aBroadcastAreaIdentifierLen.push_back(aBroadcastAreaIdentifier.size());
		}

		inline void SMPPQueryBroadcastSMResp::addBroadcastAreaIdentifier(const BroadcastAreaIdentifier& oBroadcastAreaIdentifier){
			this->m_aBroadcastAreaIdentifier.push_back(oBroadcastAreaIdentifier);
			this->m_bPresentBroadcastAreaIdentifier = true;

			this->m_aBroadcastAreaIdentifierLen.push_back(oBroadcastAreaIdentifier.getValue().size());
		}

		inline void SMPPQueryBroadcastSMResp::setBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier){
			this->m_aBroadcastAreaIdentifier = aBroadcastAreaIdentifier;
			this->m_bPresentBroadcastAreaIdentifier = true;

			this->m_aBroadcastAreaIdentifierLen.clear();
			for(unsigned j=0; j < aBroadcastAreaIdentifier.size(); ++j){
				this->m_aBroadcastAreaIdentifierLen.push_back(aBroadcastAreaIdentifier[j].getValue().size());
			}
		}

		inline std::vector<BroadcastAreaIdentifier>& SMPPQueryBroadcastSMResp::refBroadcastAreaIdentifier(void){
			return this->m_aBroadcastAreaIdentifier;
		}

		inline const std::vector<BroadcastAreaIdentifier>& SMPPQueryBroadcastSMResp::getBroadcastAreaIdentifier(void) const{
			return this->m_aBroadcastAreaIdentifier;
		}

		inline void SMPPQueryBroadcastSMResp::setBroadcastAreaSuccess(const unsigned char nBroadcastAreaSuccess){
			this->m_nBroadcastAreaSuccess = nBroadcastAreaSuccess;
			this->m_bPresentBroadcastAreaSuccess = true;
		}

		inline unsigned char& SMPPQueryBroadcastSMResp::refBroadcastAreaSuccess(void){
			return this->m_nBroadcastAreaSuccess;
		}

		inline const unsigned char SMPPQueryBroadcastSMResp::getBroadcastAreaSuccess(void) const{
			return this->m_nBroadcastAreaSuccess;
		}

		inline void SMPPQueryBroadcastSMResp::setUserMessageReference(const unsigned short nUserMessageReference){
			this->m_nUserMessageReference = nUserMessageReference;
			this->m_bPresentUserMessageReference = true;
		}

		inline unsigned short& SMPPQueryBroadcastSMResp::refUserMessageReference(void){
			return this->m_nUserMessageReference;
		}

		inline const unsigned short SMPPQueryBroadcastSMResp::getUserMessageReference(void) const{
			return this->m_nUserMessageReference;
		}

		inline void SMPPQueryBroadcastSMResp::setBroadcastEndTime(const std::string& sBroadcastEndTime){
			this->m_nBroadcastEndTimeLen = sBroadcastEndTime.size() + 1;
			this->m_sBroadcastEndTime = sBroadcastEndTime;
			this->m_bPresentBroadcastEndTime = true;
		}

		inline std::string& SMPPQueryBroadcastSMResp::refBroadcastEndTime(void){
			return this->m_sBroadcastEndTime;
		}

		inline const std::string& SMPPQueryBroadcastSMResp::getBroadcastEndTime(void) const{
			return this->m_sBroadcastEndTime;
		}

		inline void SMPPQueryBroadcastSMResp::setMessageStateLen(const unsigned short nMessageStateLen){
			this->m_nMessageStateLen = nMessageStateLen;
		}

		inline unsigned short& SMPPQueryBroadcastSMResp::refMessageStateLen(void){
			return this->m_nMessageStateLen;
		}

		inline const unsigned short SMPPQueryBroadcastSMResp::getMessageStateLen(void) const{
			return this->m_nMessageStateLen;
		}


		inline void SMPPQueryBroadcastSMResp::addBroadcastAreaIdentifierLen(const unsigned short nBroadcastAreaIdentifierLen){
			this->m_aBroadcastAreaIdentifierLen.push_back(nBroadcastAreaIdentifierLen);
		}

		inline void SMPPQueryBroadcastSMResp::setBroadcastAreaIdentifierLen(const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){
			this->m_aBroadcastAreaIdentifierLen = aBroadcastAreaIdentifierLen;
		}

		inline std::vector<unsigned short>& SMPPQueryBroadcastSMResp::refBroadcastAreaIdentifierLen(void){
			return this->m_aBroadcastAreaIdentifierLen;
		}

		inline const std::vector<unsigned short>& SMPPQueryBroadcastSMResp::getBroadcastAreaIdentifierLen(void) const{
			return this->m_aBroadcastAreaIdentifierLen;
		}


		inline void SMPPQueryBroadcastSMResp::setBroadcastAreaSuccessLen(const unsigned short nBroadcastAreaSuccessLen){
			this->m_nBroadcastAreaSuccessLen = nBroadcastAreaSuccessLen;
		}

		inline unsigned short& SMPPQueryBroadcastSMResp::refBroadcastAreaSuccessLen(void){
			return this->m_nBroadcastAreaSuccessLen;
		}

		inline const unsigned short SMPPQueryBroadcastSMResp::getBroadcastAreaSuccessLen(void) const{
			return this->m_nBroadcastAreaSuccessLen;
		}


		inline void SMPPQueryBroadcastSMResp::setUserMessageReferenceLen(const unsigned short nUserMessageReferenceLen){
			this->m_nUserMessageReferenceLen = nUserMessageReferenceLen;
		}

		inline unsigned short& SMPPQueryBroadcastSMResp::refUserMessageReferenceLen(void){
			return this->m_nUserMessageReferenceLen;
		}

		inline const unsigned short SMPPQueryBroadcastSMResp::getUserMessageReferenceLen(void) const{
			return this->m_nUserMessageReferenceLen;
		}


		inline void SMPPQueryBroadcastSMResp::setBroadcastEndTimeLen(const unsigned short nBroadcastEndTimeLen){
			this->m_nBroadcastEndTimeLen = nBroadcastEndTimeLen;
		}

		inline unsigned short& SMPPQueryBroadcastSMResp::refBroadcastEndTimeLen(void){
			return this->m_nBroadcastEndTimeLen;
		}

		inline const unsigned short SMPPQueryBroadcastSMResp::getBroadcastEndTimeLen(void) const{
			return this->m_nBroadcastEndTimeLen;
		}



	}
}
