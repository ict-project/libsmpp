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
#include "SMPPUnbindResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPUnbindResp::SMPPUnbindResp(void):
			SMPPResp(CommandId::CM_UNBIND_RESP){
		}

		SMPPUnbindResp::SMPPUnbindResp(const SMPPUnbindResp& oPackage):
			SMPPResp(CommandId::CM_UNBIND_RESP, oPackage.getSequenceNumber()){
		}

		SMPPUnbindResp::SMPPUnbindResp(const SMPPUnbind& oPackage):
			SMPPResp(CommandId::CM_UNBIND_RESP, oPackage.getSequenceNumber()){
		}

		SMPPUnbindResp::SMPPUnbindResp(const SMPPUnbind& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_UNBIND_RESP, oPackage.getSequenceNumber(), nCommandStatus){
		}

		SMPPUnbindResp::SMPPUnbindResp(const SMPPUnbind::SharedPtr poPackage):
			SMPPResp(CommandId::CM_UNBIND_RESP, poPackage->getSequenceNumber()){
		}

		SMPPUnbindResp::SMPPUnbindResp(const SMPPUnbind::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_UNBIND_RESP, poPackage->getSequenceNumber(), nCommandStatus){
		}


		SMPPUnbindResp::~SMPPUnbindResp(){
		}

		SMPPPDU* SMPPUnbindResp::cloneSMPPPDU(void){
			return new SMPPUnbindResp();
		}

		void SMPPUnbindResp::fireOnReceived(SMPPSession* poSession){
			SMPPUnbindResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPUnbindResp::encodePacket(SMPPEncoder* poEncoder){
			// Decode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
		}

		void SMPPUnbindResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
		}

		void SMPPUnbindResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
		}

		void SMPPUnbindResp::validatePacket(SMPPValidator* poValidator){
			// Decode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
		}


	}
}
