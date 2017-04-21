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

		inline void SMPPBind::setSystemId(const std::string& sSystemId){
			this->m_sSystemId = sSystemId;
		}

		inline std::string& SMPPBind::refSystemId(void){
			return this->m_sSystemId;
		}

		inline const std::string& SMPPBind::getSystemId(void) const{
			return this->m_sSystemId;
		}


		inline void SMPPBind::setPassword(const std::string& sPassword){
			this->m_sPassword = sPassword;
		}

		inline std::string& SMPPBind::refPassword(void){
			return this->m_sPassword;
		}

		inline const std::string& SMPPBind::getPassword(void) const{
			return this->m_sPassword;
		}


		inline void SMPPBind::setSystemType(const std::string& sSystemType){
			this->m_sSystemType = sSystemType;
		}

		inline std::string& SMPPBind::refSystemType(void){
			return this->m_sSystemType;
		}

		inline const std::string& SMPPBind::getSystemType(void) const{
			return this->m_sSystemType;
		}


		inline void SMPPBind::setInterfaceVersion(const unsigned char nInterfaceVersion){
			this->m_nInterfaceVersion = nInterfaceVersion;
		}

		inline unsigned char& SMPPBind::refInterfaceVersion(void){
			return this->m_nInterfaceVersion;
		}

		inline const unsigned char SMPPBind::getInterfaceVersion(void) const{
			return this->m_nInterfaceVersion;
		}


		inline void SMPPBind::setAddrTON(const unsigned char nAddrTON){
			this->m_nAddrTON = nAddrTON;
		}

		inline unsigned char& SMPPBind::refAddrTON(void){
			return this->m_nAddrTON;
		}

		inline const unsigned char SMPPBind::getAddrTON(void) const{
			return this->m_nAddrTON;
		}


		inline void SMPPBind::setAddrNPI(const unsigned char nAddrNPI){
			this->m_nAddrNPI = nAddrNPI;
		}

		inline unsigned char& SMPPBind::refAddrNPI(void){
			return this->m_nAddrNPI;
		}

		inline const unsigned char SMPPBind::getAddrNPI(void) const{
			return this->m_nAddrNPI;
		}


		inline void SMPPBind::setAddressRange(const std::string& sAddressRange){
			this->m_sAddressRange = sAddressRange;
		}

		inline std::string& SMPPBind::refAddressRange(void){
			return this->m_sAddressRange;
		}

		inline const std::string& SMPPBind::getAddressRange(void) const{
			return this->m_sAddressRange;
		}

	}
}
