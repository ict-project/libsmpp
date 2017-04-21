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

		inline void SMPPSubmitMultiResp::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPSubmitMultiResp::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPSubmitMultiResp::getMessageId(void) const{
			return this->m_sMessageId;
		}


		inline void SMPPSubmitMultiResp::setNoUnsuccess(const unsigned char nNoUnsuccess){
			this->m_nNoUnsuccess = nNoUnsuccess;
		}

		inline unsigned char& SMPPSubmitMultiResp::refNoUnsuccess(void){
			return this->m_nNoUnsuccess;
		}

		inline const unsigned char SMPPSubmitMultiResp::getNoUnsuccess(void) const{
			return this->m_nNoUnsuccess;
		}


		inline void SMPPSubmitMultiResp::addUnsuccessSME(const SMEAddress& oAddress, const unsigned nErrorStatusCode){
			this->m_aUnsuccessSMEs.push_back( UnsuccessSME(oAddress, nErrorStatusCode) );
			this->m_nNoUnsuccess = this->m_aUnsuccessSMEs.size();
		}

		inline void SMPPSubmitMultiResp::addUnsuccessSME(const unsigned char nTON, const char nNPI, const std::string& sAddress, const unsigned nErrorStatusCode){
			this->m_aUnsuccessSMEs.push_back( UnsuccessSME(nTON, nNPI, sAddress, nErrorStatusCode) );
			this->m_nNoUnsuccess = this->m_aUnsuccessSMEs.size();
		}

		inline void SMPPSubmitMultiResp::setUnsuccessSMEs(const std::vector<UnsuccessSME>& aUnsuccessSMEs){
			this->m_aUnsuccessSMEs = aUnsuccessSMEs;
			this->m_nNoUnsuccess = this->m_aUnsuccessSMEs.size();
		}

		inline std::vector<UnsuccessSME>& SMPPSubmitMultiResp::refUnsuccessSMEs(void){
			return this->m_aUnsuccessSMEs;
		}

		inline const std::vector<UnsuccessSME>& SMPPSubmitMultiResp::getUnsuccessSMEs(void) const{
			return this->m_aUnsuccessSMEs;
		}

	}
}
