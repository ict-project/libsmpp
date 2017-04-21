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
#include "SMPPReplaceSMResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPReplaceSMResp::SMPPReplaceSMResp(void):
			SMPPResp(CommandId::CM_REPLACE_SM_RESP){
		}

		SMPPReplaceSMResp::SMPPReplaceSMResp(const SMPPReplaceSMResp&):
			SMPPResp(CommandId::CM_REPLACE_SM_RESP){
		}

		SMPPReplaceSMResp::SMPPReplaceSMResp(const SMPPReplaceSM& oPackage):
			SMPPResp(CommandId::CM_REPLACE_SM_RESP, oPackage.getSequenceNumber()){
		}

		SMPPReplaceSMResp::SMPPReplaceSMResp(const SMPPReplaceSM& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_REPLACE_SM_RESP, oPackage.getSequenceNumber(), nCommandStatus){
		}

		SMPPReplaceSMResp::SMPPReplaceSMResp(const SMPPReplaceSM::SharedPtr poPackage):
			SMPPResp(CommandId::CM_REPLACE_SM_RESP, poPackage->getSequenceNumber()){
		}

		SMPPReplaceSMResp::SMPPReplaceSMResp(const SMPPReplaceSM::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_REPLACE_SM_RESP, poPackage->getSequenceNumber(), nCommandStatus){
		}


		SMPPReplaceSMResp::~SMPPReplaceSMResp(){
		}

		SMPPPDU* SMPPReplaceSMResp::cloneSMPPPDU(void){
			return new SMPPReplaceSMResp();
		}

		void SMPPReplaceSMResp::fireOnReceived(SMPPSession* poSession){
			SMPPReplaceSMResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPReplaceSMResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);

		}

		void SMPPReplaceSMResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);

		}
		void SMPPReplaceSMResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
		}

		void SMPPReplaceSMResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);

		}

	}
}
