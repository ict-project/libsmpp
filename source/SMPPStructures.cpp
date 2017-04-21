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

#include "AntHillSMPP.hpp"
#include "SMPPStructures.hpp"


namespace anthill {
	namespace smpp {
		////////////////////////////////////////////////////////////
		// Header
		////////////////////////////////////////////////////////////
		Header::Header():
			nCommandLength(0),
			nCommandId(0),
			nCommandStatus(0),
			nSequenceNumber(0){
		}

		Header::Header(const unsigned nCommandId):
			nCommandLength(0),
			nCommandId(nCommandId),
			nCommandStatus(0),
			nSequenceNumber(0){
		}

		Header::Header(const unsigned nCommandId, const unsigned nSequenceNumber):
			nCommandLength(0),
			nCommandId(nCommandId),
			nCommandStatus(0),
			nSequenceNumber(nSequenceNumber){
		}

		Header::Header(const unsigned nCommandId, const unsigned nSequenceNumber, const unsigned nCommandStatus):
			nCommandLength(0),
			nCommandId(nCommandId),
			nCommandStatus(nCommandStatus),
			nSequenceNumber(nSequenceNumber){
		}

		Header::~Header(){
		}

		const bool Header::operator ==(const Header& rhs) const{
			if(this->nCommandLength != rhs.nCommandLength) return false;
			if(this->nCommandId != rhs.nCommandId) return false;
			if(this->nCommandStatus != rhs.nCommandStatus) return false;
			if(this->nSequenceNumber != rhs.nSequenceNumber) return false;
			return true;

		}


		////////////////////////////////////////////////////////////
		// SMEAddress
		////////////////////////////////////////////////////////////
		SMEAddress::SMEAddress(void):
			nTON(0),
			nNPI(0),
			sAddress(""){
		}

		SMEAddress::SMEAddress(const unsigned char nTON, const unsigned char nNPI, const std::string& sAddress):
			nTON(nTON),
			nNPI(nNPI),
			sAddress(sAddress){
		}

		SMEAddress::~SMEAddress(){
		}

		const bool SMEAddress::operator ==(const SMEAddress& rhs) const{

			// Compare mandatory fields except length
			if(this->nTON != rhs.nTON) return false;
			if(this->nNPI != rhs.nNPI) return false;
			if(this->sAddress != rhs.sAddress) return false;
			return true;
		}

		const bool SMEAddress::operator !=(const SMEAddress& rhs) const{
			return !this->operator ==(rhs);
		}

		////////////////////////////////////////////////////////////
		// DestAddress
		////////////////////////////////////////////////////////////
		DestAddress::DestAddress(void):
			nDestFlag(DestFlag::UNKNOWN),
			oAddress(),
			sDistrListName(""){

		}

		DestAddress::DestAddress(const SMEAddress& oAddress):
			nDestFlag(DestFlag::SME_ADDRESS),
			oAddress(oAddress),
			sDistrListName(""){

		}

		DestAddress::DestAddress(const unsigned char nTON, const unsigned char nNPI, const std::string& sAddress):
			nDestFlag(DestFlag::SME_ADDRESS),
			oAddress( SMEAddress(nTON, nNPI, sAddress) ),
			sDistrListName(""){
		}

		DestAddress::DestAddress(const std::string& sDistrListName):
			nDestFlag(DestFlag::DISTR_LIST_NAME),
			oAddress(),
			sDistrListName(sDistrListName){

		}

		DestAddress::DestAddress(const unsigned char nDestFlag, const SMEAddress& oAddress, const std::string& sDistrListName):
			nDestFlag(nDestFlag),
			oAddress(oAddress),
			sDistrListName(sDistrListName){
		}

		DestAddress::~DestAddress(){
		}

		const bool DestAddress::operator ==(const DestAddress& rhs) const{

			// Compare mandatory fields except length
			if(this->nDestFlag != rhs.nDestFlag) return false;
			if(this->oAddress != rhs.oAddress) return false;
			if(this->sDistrListName != rhs.sDistrListName) return false;
			return true;
		}
		////////////////////////////////////////////////////////////
		// UnsuccessSME
		////////////////////////////////////////////////////////////
		UnsuccessSME::UnsuccessSME(void):
			oSMEAddress(),
			nErrorStatusCode(0){

		}

		UnsuccessSME::UnsuccessSME(const SMEAddress& oSMEAddress, const unsigned nErrorStatusCode):
			oSMEAddress(oSMEAddress),
			nErrorStatusCode(nErrorStatusCode){
		}

		UnsuccessSME::UnsuccessSME(const unsigned char nTON, const unsigned char nNPI, const std::string& sAddress, unsigned nErrorStatusCode):
			oSMEAddress(SMEAddress(nTON, nNPI, sAddress)),
			nErrorStatusCode(nErrorStatusCode){
		}

		UnsuccessSME::~UnsuccessSME(){
		}

		const bool UnsuccessSME::operator ==(const UnsuccessSME& rhs) const{

			// Compare mandatory fields except length
			if(this->oSMEAddress != rhs.oSMEAddress) return false;
			if(this->nErrorStatusCode != rhs.nErrorStatusCode) return false;
			return true;
		}

		////////////////////////////////////////////////////////////
		// NetworkErrorCode
		////////////////////////////////////////////////////////////
		NetworkErrorCode::NetworkErrorCode(void):
			nNetworkCode(0),
			nErrorCode(0){

		}

		NetworkErrorCode::NetworkErrorCode(unsigned char nNetworkCode, int nErrorCode):
			nNetworkCode(nNetworkCode),
			nErrorCode(nErrorCode){
		}

		NetworkErrorCode::~NetworkErrorCode(){
		}

		const bool NetworkErrorCode::operator ==(const NetworkErrorCode& rhs) const{

			// Compare mandatory fields except length
			if(this->nNetworkCode != rhs.nNetworkCode) return false;
			if(this->nErrorCode != rhs.nErrorCode) return false;
			return true;
		}


	}
}
