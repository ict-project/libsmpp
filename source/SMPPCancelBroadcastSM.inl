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

		
		inline const bool SMPPCancelBroadcastSM::isPresentBroadcastContentType(void) const{
			return this->m_bPresentBroadcastContentType;
		}

		inline void SMPPCancelBroadcastSM::omitPresentBroadcastContentType(void){
			this->m_bPresentBroadcastContentType= false;
		}

		inline void SMPPCancelBroadcastSM::setPresentBroadcastContentType(const bool bPresentBroadcastContentType){
			this->m_bPresentBroadcastContentType = bPresentBroadcastContentType;
		}

		inline const bool SMPPCancelBroadcastSM::isPresentUserMessageReference(void) const{
			return this->m_bPresentUserMessageReference;
		}

		inline void SMPPCancelBroadcastSM::omitPresentUserMessageReference(void){
			this->m_bPresentUserMessageReference = false;
		}

		inline void SMPPCancelBroadcastSM::setPresentUserMessageReference(const bool bPresentUserMessageReference){
			this->m_bPresentUserMessageReference = bPresentUserMessageReference;
		}


		inline void SMPPCancelBroadcastSM::setServiceType(const std::string& sServiceType){
			this->m_sServiceType = sServiceType;
		}

		inline std::string& SMPPCancelBroadcastSM::refServiceType(void){
			return this->m_sServiceType;
		}

		inline const std::string& SMPPCancelBroadcastSM::getServiceType(void) const{
			return this->m_sServiceType;
		}


		inline void SMPPCancelBroadcastSM::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPCancelBroadcastSM::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPCancelBroadcastSM::getMessageId(void) const{
			return this->m_sMessageId;
		}


		inline void SMPPCancelBroadcastSM::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPCancelBroadcastSM::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPCancelBroadcastSM::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPCancelBroadcastSM::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPCancelBroadcastSM::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPCancelBroadcastSM::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPCancelBroadcastSM::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPCancelBroadcastSM::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPCancelBroadcastSM::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}

		
		inline void SMPPCancelBroadcastSM::setBroadcastContentType(const std::vector<unsigned char>& aBroadcastContentType){
			this->m_nBroadcastContentTypeLen = aBroadcastContentType.size();
			this->m_aBroadcastContentType = aBroadcastContentType;
			this->m_bPresentBroadcastContentType = true;
		}

		inline std::vector<unsigned char>& SMPPCancelBroadcastSM::refBroadcastContentType(void){
			return this->m_aBroadcastContentType;
		}

		inline const std::vector<unsigned char>& SMPPCancelBroadcastSM::getBroadcastContentType(void) const{
			return this->m_aBroadcastContentType;
		}

		inline void SMPPCancelBroadcastSM::setUserMessageReference(const unsigned short nUserMessageReference){
			this->m_nUserMessageReference = nUserMessageReference;
			this->m_bPresentUserMessageReference = true;
		}

		inline unsigned short& SMPPCancelBroadcastSM::refUserMessageReference(void){
			return this->m_nUserMessageReference;
		}

		inline const unsigned short SMPPCancelBroadcastSM::getUserMessageReference(void) const{
			return this->m_nUserMessageReference;
		}

		inline void SMPPCancelBroadcastSM::setBroadcastContentTypeLen(const unsigned short nBroadcastContentTypeLen){
			this->m_nBroadcastContentTypeLen = nBroadcastContentTypeLen;
		}

		inline unsigned short& SMPPCancelBroadcastSM::refBroadcastContentTypeLen(void){
			return this->m_nBroadcastContentTypeLen;
		}

		inline const unsigned short SMPPCancelBroadcastSM::getBroadcastContentTypeLen(void) const{
			return this->m_nBroadcastContentTypeLen;
		}

		inline void SMPPCancelBroadcastSM::setUserMessageReferenceLen(const unsigned short nUserMessageReferenceLen){
			this->m_nUserMessageReferenceLen = nUserMessageReferenceLen;
		}

		inline unsigned short& SMPPCancelBroadcastSM::refUserMessageReferenceLen(void){
			return this->m_nUserMessageReferenceLen;
		}

		inline const unsigned short SMPPCancelBroadcastSM::getUserMessageReferenceLen(void) const{
			return this->m_nUserMessageReferenceLen;
		}
	}
}
