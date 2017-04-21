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
#include "SMPPDecoder.hpp"
#include "SMPPEncoder.hpp"
#include "SMPPValidator.hpp"
#include "SMPPBind.hpp"


namespace anthill {
	namespace smpp {

		SMPPBind::SMPPBind(const unsigned nCommandId):
			SMPPPDU(nCommandId),
			m_sSystemId(""),
			m_sPassword(""),
			m_sSystemType(""),
			m_nInterfaceVersion(InterfaceVersion::SMPP_VER_5_0),
			m_nAddrTON(0),
			m_nAddrNPI(0),
			m_sAddressRange(""){
		}

		SMPPBind::SMPPBind(const unsigned nCommandId, const unsigned nSequenceNumber):
			SMPPPDU(nCommandId, nSequenceNumber),
			m_sSystemId(""),
			m_sPassword(""),
			m_sSystemType(""),
			m_nInterfaceVersion(InterfaceVersion::SMPP_VER_5_0),
			m_nAddrTON(0),
			m_nAddrNPI(0),
			m_sAddressRange(""){
		}

		SMPPBind::~SMPPBind(){
		}

		void SMPPBind::encodePacket(SMPPEncoder* poEncoder){

			// Decode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeSystemId(m_sSystemId);
			poEncoder->encodePassword(m_sPassword);
			poEncoder->encodeSystemType(m_sSystemType);
			poEncoder->encodeInterfaceVersion(m_nInterfaceVersion);
			poEncoder->encodeAddrTON(m_nAddrTON);
			poEncoder->encodeAddrNPI(m_nAddrNPI);
			poEncoder->encodeAddressRange(m_sAddressRange);

		}

		void SMPPBind::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeSystemId(m_sSystemId, getCommandLength());
			poDecoder->decodePassword(m_sPassword, getCommandLength());
			poDecoder->decodeSystemType(m_sSystemType, getCommandLength());
			poDecoder->decodeInterfaceVersion(m_nInterfaceVersion, getCommandLength());
			poDecoder->decodeAddrTON(m_nAddrTON, getCommandLength());
			poDecoder->decodeAddrNPI(m_nAddrNPI, getCommandLength());
			poDecoder->decodeAddressRange(m_sAddressRange, getCommandLength());

		}

		void SMPPBind::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputSystemId(m_sSystemId);
			poOutputter->outputPassword(m_sPassword);
			poOutputter->outputSystemType(m_sSystemType);
			poOutputter->outputInterfaceVersion(m_nInterfaceVersion);
			poOutputter->outputAddrTON(m_nAddrTON);
			poOutputter->outputAddrNPI(m_nAddrNPI);
			poOutputter->outputAddressRange(m_sAddressRange);
		}

		void SMPPBind::validatePacket(SMPPValidator* poValidator){

			// Decode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateSystemId(m_sSystemId);
			poValidator->validatePassword(m_sPassword);
			poValidator->validateSystemType(m_sSystemType);
			poValidator->validateInterfaceVersion(m_nInterfaceVersion);
			poValidator->validateAddrTON(m_nAddrTON);
			poValidator->validateAddrNPI(m_nAddrNPI);
			poValidator->validateAddressRange(m_sAddressRange);

		}
	}
}
