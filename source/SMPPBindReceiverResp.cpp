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
#include "SMPPBindReceiverResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPBindReceiverResp::SMPPBindReceiverResp(void):
			SMPPBindResp(CommandId::CM_BIND_RECEIVER_RESP){
		}

		SMPPBindReceiverResp::SMPPBindReceiverResp(const SMPPBindReceiverResp&):
			SMPPBindResp(CommandId::CM_BIND_RECEIVER_RESP){
		}

		SMPPBindReceiverResp::SMPPBindReceiverResp(const SMPPBindReceiver& oPackage):
			SMPPBindResp(CommandId::CM_BIND_RECEIVER_RESP, oPackage.getSequenceNumber()){
		}

		SMPPBindReceiverResp::SMPPBindReceiverResp(const SMPPBindReceiver& oPackage, const unsigned nCommandStatus):
			SMPPBindResp(CommandId::CM_BIND_RECEIVER_RESP, oPackage.getSequenceNumber(), nCommandStatus){
		}

		SMPPBindReceiverResp::SMPPBindReceiverResp(const SMPPBindReceiver::SharedPtr poPackage):
			SMPPBindResp(CommandId::CM_BIND_RECEIVER_RESP, poPackage->getSequenceNumber()){
		}

		SMPPBindReceiverResp::SMPPBindReceiverResp(const SMPPBindReceiver::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPBindResp(CommandId::CM_BIND_RECEIVER_RESP, poPackage->getSequenceNumber(), nCommandStatus){
		}


		SMPPBindReceiverResp::~SMPPBindReceiverResp(){
		}


		SMPPPDU* SMPPBindReceiverResp::cloneSMPPPDU(void){
			return new SMPPBindReceiverResp();
		}

		void SMPPBindReceiverResp::fireOnReceived(SMPPSession* poSession){
			SMPPBindReceiverResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}
	}
}
