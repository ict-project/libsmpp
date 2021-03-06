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
#include "SMPPSubmitMultiResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPSubmitMultiResp::SMPPSubmitMultiResp(void):
			SMPPResp(CommandId::CM_SUBMIT_MULTI_RESP),
			m_sMessageId(""),
			m_nNoUnsuccess(0),
			m_aUnsuccessSMEs(){
		}

		SMPPSubmitMultiResp::SMPPSubmitMultiResp(const SMPPSubmitMultiResp&):
			SMPPResp(CommandId::CM_SUBMIT_MULTI_RESP),
			m_sMessageId(""),
			m_nNoUnsuccess(0),
			m_aUnsuccessSMEs(){
		}

		SMPPSubmitMultiResp::SMPPSubmitMultiResp(const SMPPSubmitMulti& oPackage):
			SMPPResp(CommandId::CM_SUBMIT_MULTI_RESP, oPackage.getSequenceNumber()),
			m_sMessageId(""),
			m_nNoUnsuccess(0),
			m_aUnsuccessSMEs(){
		}

		SMPPSubmitMultiResp::SMPPSubmitMultiResp(const SMPPSubmitMulti& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_SUBMIT_MULTI_RESP, oPackage.getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_nNoUnsuccess(0),
			m_aUnsuccessSMEs(){
		}

		SMPPSubmitMultiResp::SMPPSubmitMultiResp(const SMPPSubmitMulti::SharedPtr poPackage):
			SMPPResp(CommandId::CM_SUBMIT_MULTI_RESP, poPackage->getSequenceNumber()),
			m_sMessageId(""),
			m_nNoUnsuccess(0),
			m_aUnsuccessSMEs(){
		}

		SMPPSubmitMultiResp::SMPPSubmitMultiResp(const SMPPSubmitMulti::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_SUBMIT_MULTI_RESP, poPackage->getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_nNoUnsuccess(0),
			m_aUnsuccessSMEs(){
		}



		SMPPSubmitMultiResp::~SMPPSubmitMultiResp(){
		}

		SMPPPDU* SMPPSubmitMultiResp::cloneSMPPPDU(void){
			return new SMPPSubmitMultiResp();
		}

		void SMPPSubmitMultiResp::fireOnReceived(SMPPSession* poSession){
			SMPPSubmitMultiResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPSubmitMultiResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeMessageId(m_sMessageId);
			poEncoder->encodeNoUnsuccess(m_nNoUnsuccess);
			poEncoder->encodeUnsuccessSMEs(m_aUnsuccessSMEs);

		}

		void SMPPSubmitMultiResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());
			poDecoder->decodeNoUnsuccess(m_nNoUnsuccess, getCommandLength());
			poDecoder->decodeUnsuccessSMEs(m_aUnsuccessSMEs, m_nNoUnsuccess, getCommandLength());

		}

		void SMPPSubmitMultiResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputMessageId(m_sMessageId);
			poOutputter->outputNoUnsuccess(m_nNoUnsuccess);
			poOutputter->outputUnsuccessSMEs(m_aUnsuccessSMEs);

		}

		void SMPPSubmitMultiResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateMessageId(m_sMessageId);
			poValidator->validateNoUnsuccess(m_nNoUnsuccess);
			poValidator->validateUnsuccessSMEs(m_aUnsuccessSMEs,m_nNoUnsuccess);

		}

	}
}
