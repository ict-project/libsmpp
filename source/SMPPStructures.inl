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
		////////////////////////////////////////////////////////////
		// Header
		////////////////////////////////////////////////////////////

		inline void Header::setCommandLength(const unsigned nCommandLength){
			this->nCommandLength = nCommandLength;
		}

		inline unsigned& Header::refCommandLength(void){
			return this->nCommandLength;
		}

		inline const unsigned Header::getCommandLength(void) const{
			return this->nCommandLength;
		}


		inline void Header::setCommandId(const unsigned nCommandId){
			this->nCommandId = nCommandId;
		}

		inline unsigned& Header::refCommandId(void){
			return this->nCommandId;
		}

		inline const unsigned Header::getCommandId(void) const{
			return this->nCommandId;
		}


		inline void Header::setCommandStatus(const unsigned nCommandStatus){
			this->nCommandStatus = nCommandStatus;
		}

		inline unsigned& Header::refCommandStatus(void){
			return this->nCommandStatus;
		}

		inline const unsigned Header::getCommandStatus(void) const{
			return this->nCommandStatus;
		}


		inline void Header::setSequenceNumber(const unsigned nSequenceNumber){
			this->nSequenceNumber = nSequenceNumber;
		}

		inline unsigned& Header::refSequenceNumber(void){
			return this->nSequenceNumber;
		}

		inline const unsigned Header::getSequenceNumber(void) const{
			return this->nSequenceNumber;
		}

		////////////////////////////////////////////////////////////
		// SMEAddress
		////////////////////////////////////////////////////////////
		inline void SMEAddress::setTON(const unsigned char nTON){
			this->nTON = nTON;
		}

		inline unsigned char& SMEAddress::refTON(void){
			return this->nTON;
		}

		inline const unsigned char SMEAddress::getTON(void) const{
			return this->nTON;
		}


		inline void SMEAddress::setNPI(const unsigned char nNPI){
			this->nNPI = nNPI;
		}

		inline unsigned char& SMEAddress::refNPI(void){
			return this->nNPI;
		}

		inline const unsigned char SMEAddress::getNPI(void) const{
			return this->nNPI;
		}


		inline void SMEAddress::setAddress(const std::string& sAddress){
			this->sAddress = sAddress;
		}

		inline std::string& SMEAddress::refAddress(void){
			return this->sAddress;
		}

		inline const std::string& SMEAddress::getAddress(void) const{
			return this->sAddress;
		}


		////////////////////////////////////////////////////////////
		// DestAddress
		////////////////////////////////////////////////////////////

		inline void DestAddress::setDestFlag(const unsigned char nDestFlag){
			this->nDestFlag = nDestFlag;
		}

		inline unsigned char& DestAddress::refDestFlag(void){
			return this->nDestFlag;
		}

		inline const unsigned char DestAddress::getDestFlag(void) const{
			return this->nDestFlag;
		}


		inline void DestAddress::setAddress(const SMEAddress& oAddress){
			this->nDestFlag = DestFlag::SME_ADDRESS;
			this->oAddress = oAddress;
		}

		inline SMEAddress& DestAddress::refAddress(void){
			return this->oAddress;
		}

		inline const SMEAddress& DestAddress::getAddress(void) const{
			return this->oAddress;
		}


		inline void DestAddress::setDistrListName(const std::string& sDistrListName){
			this->nDestFlag = DestFlag::DISTR_LIST_NAME;
			this->sDistrListName = sDistrListName;
		}

		inline std::string& DestAddress::refDistrListName(void){
			return this->sDistrListName;
		}

		inline const std::string& DestAddress::getDistrListName(void) const{
			return this->sDistrListName;
		}


		////////////////////////////////////////////////////////////
		// UnsuccessSME
		////////////////////////////////////////////////////////////

		inline void UnsuccessSME::setSMEAddress(const SMEAddress& oSMEAddress){
			this->oSMEAddress = oSMEAddress;
		}

		inline SMEAddress& UnsuccessSME::refSMEAddress(void){
			return this->oSMEAddress;
		}

		inline const SMEAddress& UnsuccessSME::getSMEAddress(void) const{
			return this->oSMEAddress;
		}


		inline void UnsuccessSME::setErrorStatusCode(const unsigned nErrorStatusCode){
			this->nErrorStatusCode = nErrorStatusCode;
		}

		inline unsigned& UnsuccessSME::refErrorStatusCode(void){
			return this->nErrorStatusCode;
		}

		inline const unsigned UnsuccessSME::getErrorStatusCode(void) const{
			return this->nErrorStatusCode;
		}


		////////////////////////////////////////////////////////////
		// NetworkErrorCode
		////////////////////////////////////////////////////////////

		inline void NetworkErrorCode::setNetworkCode(const unsigned char nNetworkCode){
			this->nNetworkCode = nNetworkCode;
		}

		inline unsigned char& NetworkErrorCode::refNetworkCode(void){
			return this->nNetworkCode;
		}

		inline const unsigned char NetworkErrorCode::getNetworkCode(void) const{
			return this->nNetworkCode;
		}

		inline void NetworkErrorCode::setErrorCode(const unsigned short nErrorCode){
			this->nErrorCode = nErrorCode;
		}

		inline unsigned short& NetworkErrorCode::refErrorCode(void){
			return this->nErrorCode;
		}

		inline const unsigned short NetworkErrorCode::getErrorCode(void) const{
			return this->nErrorCode;
		}
	}
}
