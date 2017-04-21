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

		inline const bool SMPPQueryBroadcastSM::isPresentUserMessageReference(void) const{
			return this->m_bPresentUserMessageReference;
		}

		inline void SMPPQueryBroadcastSM::omitPresentUserMessageReference(void){
			this->m_bPresentUserMessageReference = false;
		}

		inline void SMPPQueryBroadcastSM::setPresentUserMessageReference(const bool bPresentUserMessageReference){
			this->m_bPresentUserMessageReference = bPresentUserMessageReference;
		}

		inline void SMPPQueryBroadcastSM::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPQueryBroadcastSM::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPQueryBroadcastSM::getMessageId(void) const{
			return this->m_sMessageId;
		}

		inline void SMPPQueryBroadcastSM::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPQueryBroadcastSM::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPQueryBroadcastSM::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPQueryBroadcastSM::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPQueryBroadcastSM::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPQueryBroadcastSM::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPQueryBroadcastSM::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPQueryBroadcastSM::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPQueryBroadcastSM::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}

		inline void SMPPQueryBroadcastSM::setUserMessageReference(const unsigned short nUserMessageReference){
			this->m_nUserMessageReference = nUserMessageReference;
			this->m_bPresentUserMessageReference = true;
		}

		inline unsigned short& SMPPQueryBroadcastSM::refUserMessageReference(void){
			return this->m_nUserMessageReference;
		}

		inline const unsigned short SMPPQueryBroadcastSM::getUserMessageReference(void) const{
			return this->m_nUserMessageReference;
		}


		inline void SMPPQueryBroadcastSM::setUserMessageReferenceLen(const unsigned short nUserMessageReferenceLen){
			this->m_nUserMessageReferenceLen = nUserMessageReferenceLen;
		}

		inline unsigned short& SMPPQueryBroadcastSM::refUserMessageReferenceLen(void){
			return this->m_nUserMessageReferenceLen;
		}

		inline const unsigned short SMPPQueryBroadcastSM::getUserMessageReferenceLen(void) const{
			return this->m_nUserMessageReferenceLen;
		}



	}
}
