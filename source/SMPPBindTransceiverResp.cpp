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
#include "SMPPBindTransceiverResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPBindTransceiverResp::SMPPBindTransceiverResp(void):
			SMPPBindResp(CommandId::CM_BIND_TRANSCEIVER_RESP){
		}

		SMPPBindTransceiverResp::SMPPBindTransceiverResp(const SMPPBindTransceiverResp&):
			SMPPBindResp(CommandId::CM_BIND_TRANSCEIVER_RESP){
		}

		SMPPBindTransceiverResp::SMPPBindTransceiverResp(const SMPPBindTransceiver& oPackage):
			SMPPBindResp(CommandId::CM_BIND_TRANSCEIVER_RESP, oPackage.getSequenceNumber()){
		}

		SMPPBindTransceiverResp::SMPPBindTransceiverResp(const SMPPBindTransceiver& oPackage, const unsigned nCommandStatus):
			SMPPBindResp(CommandId::CM_BIND_TRANSCEIVER_RESP, oPackage.getSequenceNumber(), nCommandStatus){
		}

		SMPPBindTransceiverResp::SMPPBindTransceiverResp(const SMPPBindTransceiver::SharedPtr poPackage):
			SMPPBindResp(CommandId::CM_BIND_TRANSCEIVER_RESP, poPackage->getSequenceNumber()){
		}

		SMPPBindTransceiverResp::SMPPBindTransceiverResp(const SMPPBindTransceiver::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPBindResp(CommandId::CM_BIND_TRANSCEIVER_RESP, poPackage->getSequenceNumber(), nCommandStatus){
		}


		SMPPBindTransceiverResp::~SMPPBindTransceiverResp(){
		}

		SMPPPDU* SMPPBindTransceiverResp::cloneSMPPPDU(void){
			return new SMPPBindTransceiverResp();
		}

		void SMPPBindTransceiverResp::fireOnReceived(SMPPSession* poSession){
			SMPPBindTransceiverResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}
	}
}
