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
#include "SMPPSubmitSMResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPSubmitSMResp::SMPPSubmitSMResp(void):
			SMPPResp(CommandId::CM_SUBMIT_SM_RESP),
			m_sMessageId(""){
		}

		SMPPSubmitSMResp::SMPPSubmitSMResp(const SMPPSubmitSM& oPackage):
			SMPPResp(CommandId::CM_SUBMIT_SM_RESP, oPackage.getSequenceNumber()),
			m_sMessageId(""){
		}

		SMPPSubmitSMResp::SMPPSubmitSMResp(const SMPPSubmitSMResp& oPackage):
			SMPPResp(CommandId::CM_SUBMIT_SM_RESP, oPackage.getSequenceNumber()),
			m_sMessageId(""){
		}

		SMPPSubmitSMResp::SMPPSubmitSMResp(const SMPPSubmitSM& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_SUBMIT_SM_RESP, oPackage.getSequenceNumber(), nCommandStatus),
			m_sMessageId(""){
		}

		SMPPSubmitSMResp::SMPPSubmitSMResp(const SMPPSubmitSM::SharedPtr poPackage):
			SMPPResp(CommandId::CM_SUBMIT_SM_RESP, poPackage->getSequenceNumber()),
			m_sMessageId(""){
		}

		SMPPSubmitSMResp::SMPPSubmitSMResp(const SMPPSubmitSM::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_SUBMIT_SM_RESP, poPackage->getSequenceNumber(), nCommandStatus),
			m_sMessageId(""){
		}

		SMPPSubmitSMResp::~SMPPSubmitSMResp(){
		}

		SMPPPDU* SMPPSubmitSMResp::cloneSMPPPDU(void){
			return new SMPPSubmitSMResp();
		}

		void SMPPSubmitSMResp::fireOnReceived(SMPPSession* poSession){
			SMPPSubmitSMResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPSubmitSMResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeMessageId(m_sMessageId);


		}

		void SMPPSubmitSMResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());

		}

		void SMPPSubmitSMResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputMessageId(m_sMessageId);
		}

		void SMPPSubmitSMResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateMessageId(m_sMessageId);


		}

	}
}
