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

		inline void SMPPCancelSM::setServiceType(const std::string& sServiceType){
			this->m_sServiceType = sServiceType;
		}

		inline std::string& SMPPCancelSM::refServiceType(void){
			return this->m_sServiceType;
		}

		inline const std::string& SMPPCancelSM::getServiceType(void) const{
			return this->m_sServiceType;
		}


		inline void SMPPCancelSM::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPCancelSM::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPCancelSM::getMessageId(void) const{
			return this->m_sMessageId;
		}


		inline void SMPPCancelSM::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPCancelSM::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPCancelSM::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPCancelSM::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPCancelSM::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPCancelSM::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPCancelSM::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPCancelSM::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPCancelSM::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}


		inline void SMPPCancelSM::setDestAddrTON(const unsigned char nDestAddrTON){
			this->m_nDestAddrTON = nDestAddrTON;
		}

		inline unsigned char& SMPPCancelSM::refDestAddrTON(void){
			return this->m_nDestAddrTON;
		}

		inline const unsigned char SMPPCancelSM::getDestAddrTON(void) const{
			return this->m_nDestAddrTON;
		}


		inline void SMPPCancelSM::setDestAddrNPI(const unsigned char nDestAddrNPI){
			this->m_nDestAddrNPI = nDestAddrNPI;
		}

		inline unsigned char& SMPPCancelSM::refDestAddrNPI(void){
			return this->m_nDestAddrNPI;
		}

		inline const unsigned char SMPPCancelSM::getDestAddrNPI(void) const{
			return this->m_nDestAddrNPI;
		}


		inline void SMPPCancelSM::setDestAddr(const std::string& sDestAddr){
			this->m_sDestAddr = sDestAddr;
		}

		inline std::string& SMPPCancelSM::refDestAddr(void){
			return this->m_sDestAddr;
		}

		inline const std::string& SMPPCancelSM::getDestAddr(void) const{
			return this->m_sDestAddr;
		}

	}
}
