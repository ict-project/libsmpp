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

		inline const bool SMPPBroadcastSMResp::isPresentBroadcastErrorStatus(void) const{
			return this->m_bPresentBroadcastErrorStatus;
		}

		inline void SMPPBroadcastSMResp::omitPresentBroadcastErrorStatus(void){
			this->m_bPresentBroadcastErrorStatus= false;
		}

		inline void SMPPBroadcastSMResp::setPresentBroadcastErrorStatus(const bool bPresentBroadcastErrorStatus){
			this->m_bPresentBroadcastErrorStatus = bPresentBroadcastErrorStatus;
		}

		inline const bool SMPPBroadcastSMResp::isPresentFailedBroadcastAreaIdentifier(void) const{
			return this->m_bPresentFailedBroadcastAreaIdentifier;
		}

		inline void SMPPBroadcastSMResp::omitPresentFailedBroadcastAreaIdentifier(void){
			this->m_bPresentFailedBroadcastAreaIdentifier= false;
		}

		inline void SMPPBroadcastSMResp::setPresentFailedBroadcastAreaIdentifier(const bool bPresentFailedBroadcastAreaIdentifier){
			this->m_bPresentFailedBroadcastAreaIdentifier = bPresentFailedBroadcastAreaIdentifier;
		}

		inline void SMPPBroadcastSMResp::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPBroadcastSMResp::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPBroadcastSMResp::getMessageId(void) const{
			return this->m_sMessageId;
		}


		inline void SMPPBroadcastSMResp::setBroadcastErrorStatus(const unsigned nBroadcastErrorStatus){
			this->m_nBroadcastErrorStatus = nBroadcastErrorStatus;
			this->m_bPresentBroadcastErrorStatus = true;
		}

		inline unsigned& SMPPBroadcastSMResp::refBroadcastErrorStatus(void){
			return this->m_nBroadcastErrorStatus;
		}

		inline const unsigned SMPPBroadcastSMResp::getBroadcastErrorStatus(void) const{
			return this->m_nBroadcastErrorStatus;
		}

		inline void SMPPBroadcastSMResp::addFailedBroadcastAreaIdentifier(const std::vector<unsigned char>& aFailedBroadcastAreaIdentifier){
			this->m_aFailedBroadcastAreaIdentifier.push_back(BroadcastAreaIdentifier(aFailedBroadcastAreaIdentifier));
			this->m_aFailedBroadcastAreaIdentifierLen.push_back(aFailedBroadcastAreaIdentifier.size());
			this->m_bPresentFailedBroadcastAreaIdentifier = true;
		}

		inline void SMPPBroadcastSMResp::addFailedBroadcastAreaIdentifier(const BroadcastAreaIdentifier& oFailedBroadcastAreaIdentifier){
			this->m_aFailedBroadcastAreaIdentifier.push_back(oFailedBroadcastAreaIdentifier);
			this->m_aFailedBroadcastAreaIdentifierLen.push_back(oFailedBroadcastAreaIdentifier.getValue().size());
			this->m_bPresentFailedBroadcastAreaIdentifier = true;
		}

		inline void SMPPBroadcastSMResp::setFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aFailedBroadcastAreaIdentifier){
			this->m_aFailedBroadcastAreaIdentifier = aFailedBroadcastAreaIdentifier;
			this->m_bPresentFailedBroadcastAreaIdentifier = true;

			this->m_aFailedBroadcastAreaIdentifierLen.clear();
			for(unsigned j=0; j < aFailedBroadcastAreaIdentifier.size(); ++j){
				this->m_aFailedBroadcastAreaIdentifierLen.push_back(aFailedBroadcastAreaIdentifier[j].getValue().size());
			}
		}

		inline std::vector<BroadcastAreaIdentifier>& SMPPBroadcastSMResp::refFailedBroadcastAreaIdentifier(void){
			return this->m_aFailedBroadcastAreaIdentifier;
		}

		inline const std::vector<BroadcastAreaIdentifier>& SMPPBroadcastSMResp::getFailedBroadcastAreaIdentifier(void) const{
			return this->m_aFailedBroadcastAreaIdentifier;
		}

		inline void SMPPBroadcastSMResp::setBroadcastErrorStatusLen(const unsigned short nBroadcastErrorStatusLen){
			this->m_nBroadcastErrorStatusLen = nBroadcastErrorStatusLen;
		}

		inline unsigned short& SMPPBroadcastSMResp::refBroadcastErrorStatusLen(void){
			return this->m_nBroadcastErrorStatusLen;
		}

		inline const unsigned short SMPPBroadcastSMResp::getBroadcastErrorStatusLen(void) const{
			return this->m_nBroadcastErrorStatusLen;
		}

		inline void SMPPBroadcastSMResp::addFailedBroadcastAreaIdentifierLen(const unsigned short nFailedBroadcastAreaIdentifierLen){
			this->m_aFailedBroadcastAreaIdentifierLen.push_back(nFailedBroadcastAreaIdentifierLen);
		}

		inline void SMPPBroadcastSMResp::setFailedBroadcastAreaIdentifierLen(const std::vector<unsigned short>& aFailedBroadcastAreaIdentifierLen){
			this->m_aFailedBroadcastAreaIdentifierLen = aFailedBroadcastAreaIdentifierLen;
		}

		inline std::vector<unsigned short>& SMPPBroadcastSMResp::refFailedBroadcastAreaIdentifierLen(void){
			return this->m_aFailedBroadcastAreaIdentifierLen;
		}

		inline const std::vector<unsigned short>& SMPPBroadcastSMResp::getFailedBroadcastAreaIdentifierLen(void) const{
			return this->m_aFailedBroadcastAreaIdentifierLen;
		}
	}
}
