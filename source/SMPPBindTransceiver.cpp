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
#include "SMPPBindTransceiver.hpp"


namespace anthill {
	namespace smpp {

		SMPPBindTransceiver::SMPPBindTransceiver(void):
			SMPPBind(CommandId::CM_BIND_TRANSCEIVER){
		}

		SMPPBindTransceiver::SMPPBindTransceiver(const unsigned nSequenceNumber):
			SMPPBind(CommandId::CM_BIND_TRANSCEIVER, nSequenceNumber){
		}

		SMPPBindTransceiver::~SMPPBindTransceiver(){
		}


		SMPPPDU* SMPPBindTransceiver::cloneSMPPPDU(void){
			return new SMPPBindTransceiver();
		}

		void SMPPBindTransceiver::fireOnReceived(SMPPSession* poSession){
			SMPPBindTransceiver::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}
	}
}
