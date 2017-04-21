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
#include "SMPPOutbind.hpp"


namespace anthill {
	namespace smpp {

		SMPPOutbind::SMPPOutbind(void):
			SMPPPDU(CommandId::CM_OUTBIND),
			m_sSystemId(""),
			m_sPassword(""){
		}

		SMPPOutbind::SMPPOutbind(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_OUTBIND, nSequenceNumber),
			m_sSystemId(""),
			m_sPassword(""){
		}

		SMPPOutbind::~SMPPOutbind(){
		}

		SMPPPDU* SMPPOutbind::cloneSMPPPDU(void){
			return new SMPPOutbind();
		}

		void SMPPOutbind::fireOnReceived(SMPPSession* poSession){
			SMPPOutbind::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPOutbind::encodePacket(SMPPEncoder* poEncoder){

			// Decode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeSystemId(m_sSystemId);
			poEncoder->encodePassword(m_sPassword);

		}

		void SMPPOutbind::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeSystemId(m_sSystemId, getCommandLength());
			poDecoder->decodePassword(m_sPassword, getCommandLength());

		}

		void SMPPOutbind::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputSystemId(m_sSystemId);
			poOutputter->outputPassword(m_sPassword);
		}

		void SMPPOutbind::validatePacket(SMPPValidator* poValidator){

			// Decode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateSystemId(m_sSystemId);
			poValidator->validatePassword(m_sPassword);

		}

	}
}
