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
#include "SMPPEnquireLinkResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPEnquireLinkResp::SMPPEnquireLinkResp(void):
			SMPPResp(CommandId::CM_ENQUIRE_LINK_RESP){
		}

		SMPPEnquireLinkResp::SMPPEnquireLinkResp(const SMPPEnquireLinkResp&):
			SMPPResp(CommandId::CM_ENQUIRE_LINK_RESP){
		}

		SMPPEnquireLinkResp::SMPPEnquireLinkResp(const SMPPEnquireLink& oPackage):
			SMPPResp(CommandId::CM_ENQUIRE_LINK_RESP, oPackage.getSequenceNumber()){
		}

		SMPPEnquireLinkResp::SMPPEnquireLinkResp(const SMPPEnquireLink& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_ENQUIRE_LINK_RESP, oPackage.getSequenceNumber(), nCommandStatus){
		}

		SMPPEnquireLinkResp::SMPPEnquireLinkResp(const SMPPEnquireLink::SharedPtr poPackage):
			SMPPResp(CommandId::CM_ENQUIRE_LINK_RESP, poPackage->getSequenceNumber()){
		}

		SMPPEnquireLinkResp::SMPPEnquireLinkResp(const SMPPEnquireLink::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_ENQUIRE_LINK_RESP, poPackage->getSequenceNumber(), nCommandStatus){
		}

		SMPPEnquireLinkResp::~SMPPEnquireLinkResp(){
		}

		SMPPPDU* SMPPEnquireLinkResp::cloneSMPPPDU(void){
			return new SMPPEnquireLinkResp();
		}

		void SMPPEnquireLinkResp::fireOnReceived(SMPPSession* poSession){
			SMPPEnquireLinkResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPEnquireLinkResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
		}

		void SMPPEnquireLinkResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
		}

		void SMPPEnquireLinkResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
		}

		void SMPPEnquireLinkResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
		}

	}
}
