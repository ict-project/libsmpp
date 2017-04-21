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
#include "SMPPBindResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPBindResp::SMPPBindResp(const unsigned nCommandId):
			SMPPResp(nCommandId),
			m_sSystemId(""),
			m_nScInterfaceVersion(InterfaceVersion::SMPP_VER_5_0),
			m_bPresentScInterfaceVersion(false),
			m_nScInterfaceVersionLen(sizeof(char)){
		}

		SMPPBindResp::SMPPBindResp(const unsigned nCommandId, const unsigned nSequenceNumber):
			SMPPResp(nCommandId, nSequenceNumber),
			m_sSystemId(""),
			m_nScInterfaceVersion(InterfaceVersion::SMPP_VER_5_0),
			m_bPresentScInterfaceVersion(false),
			m_nScInterfaceVersionLen(sizeof(char)){
		}

		SMPPBindResp::SMPPBindResp(const unsigned nCommandId, const unsigned nSequenceNumber, const unsigned nCommandStatus):
			SMPPResp(nCommandId, nSequenceNumber, nCommandStatus),
			m_sSystemId(""),
			m_nScInterfaceVersion(InterfaceVersion::SMPP_VER_5_0),
			m_bPresentScInterfaceVersion(false),
			m_nScInterfaceVersionLen(sizeof(char)){
		}

		SMPPBindResp::SMPPBindResp(const SMPPBindResp& oResp):
			SMPPResp(oResp.getCommandId()),
			m_sSystemId(""),
			m_nScInterfaceVersion(InterfaceVersion::SMPP_VER_5_0),
			m_bPresentScInterfaceVersion(false),
			m_nScInterfaceVersionLen(sizeof(char)){
		}

		SMPPBindResp::~SMPPBindResp(){
		}


		void SMPPBindResp::encodePacket(SMPPEncoder* poEncoder){

			// Decode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeSystemId(m_sSystemId);

			// Encode optional fields
			if(this->m_bPresentScInterfaceVersion)
				poEncoder->encodeScInterfaceVersion(m_nScInterfaceVersion,
					m_nScInterfaceVersionLen);

		}

		void SMPPBindResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeSystemId(m_sSystemId, getCommandLength());

			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_SC_INTERFACE_VERSION:{
						poDecoder->decodeScInterfaceVersion(m_nScInterfaceVersion,
							m_nScInterfaceVersionLen, this->getCommandLength());
						this->m_bPresentScInterfaceVersion = true;
						break;
					}
					default:{
						// Report about error
						std::string sMessage(poDecoder->getTLVError());
						throw std::logic_error(Errors::UNKNOWN_TAG_MSG + sMessage);
						break;
					}
				}
			}
		}

		void SMPPBindResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputSystemId(m_sSystemId);

			// Output optional fields
			if(this->m_bPresentScInterfaceVersion)
				poOutputter->outputScInterfaceVersion(m_nScInterfaceVersion, 
					m_nScInterfaceVersionLen);

		}

		void SMPPBindResp::validatePacket(SMPPValidator* poValidator){

			// Decode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateSystemId(m_sSystemId);

			// Encode optional fields
			if(this->m_bPresentScInterfaceVersion)
				poValidator->validateScInterfaceVersion(m_nScInterfaceVersion,
					m_nScInterfaceVersionLen);

		}
	}
}
