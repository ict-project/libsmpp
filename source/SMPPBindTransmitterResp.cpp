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
#include "SMPPBindTransmitterResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPBindTransmitterResp::SMPPBindTransmitterResp(void):
			SMPPBindResp(CommandId::CM_BIND_TRANSMITTER_RESP){
		}

		SMPPBindTransmitterResp::SMPPBindTransmitterResp(const SMPPBindTransmitterResp&):
			SMPPBindResp(CommandId::CM_BIND_TRANSMITTER_RESP){
		}

		SMPPBindTransmitterResp::SMPPBindTransmitterResp(const SMPPBindTransmitter& oPackage):
			SMPPBindResp(CommandId::CM_BIND_TRANSMITTER_RESP, oPackage.getSequenceNumber()){
		}

		SMPPBindTransmitterResp::SMPPBindTransmitterResp(const SMPPBindTransmitter& oPackage, const unsigned nCommandStatus):
			SMPPBindResp(CommandId::CM_BIND_TRANSMITTER_RESP, oPackage.getSequenceNumber(), nCommandStatus){
		}

		SMPPBindTransmitterResp::SMPPBindTransmitterResp(const SMPPBindTransmitter::SharedPtr poPackage):
			SMPPBindResp(CommandId::CM_BIND_TRANSMITTER_RESP, poPackage->getSequenceNumber()){
		}

		SMPPBindTransmitterResp::SMPPBindTransmitterResp(const SMPPBindTransmitter::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPBindResp(CommandId::CM_BIND_TRANSMITTER_RESP, poPackage->getSequenceNumber(), nCommandStatus){
		}

		SMPPBindTransmitterResp::~SMPPBindTransmitterResp(){
		}

		SMPPPDU* SMPPBindTransmitterResp::cloneSMPPPDU(void){
			return new SMPPBindTransmitterResp();
		}

		void SMPPBindTransmitterResp::fireOnReceived(SMPPSession* poSession){
			SMPPBindTransmitterResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}
	}
}
