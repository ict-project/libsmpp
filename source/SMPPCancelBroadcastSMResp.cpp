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
#include "SMPPCancelBroadcastSMResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPCancelBroadcastSMResp::SMPPCancelBroadcastSMResp(void):
			SMPPResp(CommandId::CM_CANCEL_BROADCAST_SM_RESP){
		}

		SMPPCancelBroadcastSMResp::SMPPCancelBroadcastSMResp(const SMPPCancelBroadcastSMResp&):
			SMPPResp(CommandId::CM_CANCEL_BROADCAST_SM_RESP){
		}

		SMPPCancelBroadcastSMResp::SMPPCancelBroadcastSMResp(const SMPPCancelBroadcastSM& oPackage):
			SMPPResp(CommandId::CM_CANCEL_BROADCAST_SM_RESP, oPackage.getSequenceNumber()){
		}

		SMPPCancelBroadcastSMResp::SMPPCancelBroadcastSMResp(const SMPPCancelBroadcastSM& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_CANCEL_BROADCAST_SM_RESP, oPackage.getSequenceNumber(), nCommandStatus){
		}

		SMPPCancelBroadcastSMResp::SMPPCancelBroadcastSMResp(const SMPPCancelBroadcastSM::SharedPtr poPackage):
			SMPPResp(CommandId::CM_CANCEL_BROADCAST_SM_RESP, poPackage->getSequenceNumber()){
		}

		SMPPCancelBroadcastSMResp::SMPPCancelBroadcastSMResp(const SMPPCancelBroadcastSM::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_CANCEL_BROADCAST_SM_RESP, poPackage->getSequenceNumber(), nCommandStatus){
		}


		SMPPCancelBroadcastSMResp::~SMPPCancelBroadcastSMResp(){
		}

		SMPPPDU* SMPPCancelBroadcastSMResp::cloneSMPPPDU(void){
			return new SMPPCancelBroadcastSMResp();
		}

		void SMPPCancelBroadcastSMResp::fireOnReceived(SMPPSession* poSession){
			SMPPCancelBroadcastSMResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPCancelBroadcastSMResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);

		}

		void SMPPCancelBroadcastSMResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);

		}

		void SMPPCancelBroadcastSMResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
		}

		void SMPPCancelBroadcastSMResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);

		}

	}
}
