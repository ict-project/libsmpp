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
#include "SMPPUnbind.hpp"


namespace anthill {
	namespace smpp {

		SMPPUnbind::SMPPUnbind(void):
			SMPPPDU(CommandId::CM_UNBIND){
		}

		SMPPUnbind::SMPPUnbind(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_UNBIND, nSequenceNumber){
		}

		SMPPUnbind::~SMPPUnbind(){
		}

		SMPPPDU* SMPPUnbind::cloneSMPPPDU(void){
			return new SMPPUnbind();
		}

		void SMPPUnbind::fireOnReceived(SMPPSession* poSession){
			SMPPUnbind::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPUnbind::encodePacket(SMPPEncoder* poEncoder){
			// Decode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
		}

		void SMPPUnbind::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
		}

		void SMPPUnbind::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
		}

		void SMPPUnbind::validatePacket(SMPPValidator* poValidator){
			// Decode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
		}

	}
}
