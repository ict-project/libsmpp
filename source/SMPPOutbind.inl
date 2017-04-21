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

		inline void SMPPOutbind::setSystemId(const std::string& sSystemId){
			this->m_sSystemId = sSystemId;
		}

		inline std::string& SMPPOutbind::refSystemId(void){
			return this->m_sSystemId;
		}

		inline const std::string& SMPPOutbind::getSystemId(void) const{
			return this->m_sSystemId;
		}


		inline void SMPPOutbind::setPassword(const std::string& sPassword){
			this->m_sPassword = sPassword;
		}

		inline std::string& SMPPOutbind::refPassword(void){
			return this->m_sPassword;
		}

		inline const std::string& SMPPOutbind::getPassword(void) const{
			return this->m_sPassword;
		}


	}
}
