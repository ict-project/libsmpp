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

		inline const bool SMPPBindResp::isPresentScInterfaceVersion(void) const{
			return this->m_bPresentScInterfaceVersion;
		}

		inline void SMPPBindResp::omitPresentScInterfaceVersion(void){
			this->m_bPresentScInterfaceVersion = false;
		}

		inline void SMPPBindResp::setPresentScInterfaceVersion(const bool bPresentScInterfaceVersion){
			this->m_bPresentScInterfaceVersion = bPresentScInterfaceVersion;
		}

		inline void SMPPBindResp::setSystemId(const std::string& sSystemId){
			this->m_sSystemId = sSystemId;
		}
			
		inline std::string& SMPPBindResp::refSystemId(void){
			return this->m_sSystemId;
		}

		inline const std::string& SMPPBindResp::getSystemId(void) const{
			return this->m_sSystemId;
		}

		inline void SMPPBindResp::setScInterfaceVersion(const unsigned char nScInterfaceVersion){
			this->m_nScInterfaceVersion = nScInterfaceVersion;
			this->m_bPresentScInterfaceVersion = true;
		}

		inline unsigned char& SMPPBindResp::refScInterfaceVersion(void){
			return this->m_nScInterfaceVersion;
		}

		inline const unsigned char SMPPBindResp::getScInterfaceVersion(void) const{
			return this->m_nScInterfaceVersion;
		}

		inline void SMPPBindResp::setScInterfaceVersionLen(const unsigned short nScInterfaceVersionLen){
			this->m_nScInterfaceVersionLen = nScInterfaceVersionLen;
		}

		inline unsigned short& SMPPBindResp::refScInterfaceVersionLen(void){
			return this->m_nScInterfaceVersionLen;
		}

		inline const unsigned short SMPPBindResp::getScInterfaceVersionLen(void) const{
			return this->m_nScInterfaceVersionLen;
		}
	}
}
