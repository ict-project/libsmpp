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

		inline void SMPPQuerySMResp::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPQuerySMResp::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPQuerySMResp::getMessageId(void) const{
			return this->m_sMessageId;
		}


		inline void SMPPQuerySMResp::setFinalDate(const std::string& sFinalDate){
			this->m_sFinalDate = sFinalDate;
		}

		inline std::string& SMPPQuerySMResp::refFinalDate(void){
			return this->m_sFinalDate;
		}

		inline const std::string& SMPPQuerySMResp::getFinalDate(void) const{
			return this->m_sFinalDate;
		}

		inline void SMPPQuerySMResp::setMessageState(const unsigned char nMessageState){
			this->m_nMessageState = nMessageState;
		}

		inline unsigned char& SMPPQuerySMResp::refMessageState(void){
			return this->m_nMessageState;
		}

		inline const unsigned char SMPPQuerySMResp::getMessageState(void) const{
			return this->m_nMessageState;
		}


		inline void SMPPQuerySMResp::setErrorCode(const unsigned char nErrorCode){
			this->m_nErrorCode = nErrorCode;
		}

		inline unsigned char& SMPPQuerySMResp::refErrorCode(void){
			return this->m_nErrorCode;
		}

		inline const unsigned char SMPPQuerySMResp::getErrorCode(void) const{
			return this->m_nErrorCode;
		}

	}
}
