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
#include "SMPPQuerySMResp.hpp"


namespace anthill {
	namespace smpp {

		SMPPQuerySMResp::SMPPQuerySMResp(void):
			SMPPResp(CommandId::CM_QUERY_SM_RESP),
			m_sMessageId(""),
			m_sFinalDate(""),
			m_nMessageState(0),
			m_nErrorCode(0){
		}

		SMPPQuerySMResp::SMPPQuerySMResp(const SMPPQuerySMResp&):
			SMPPResp(CommandId::CM_QUERY_SM_RESP),
			m_sMessageId(""),
			m_sFinalDate(""),
			m_nMessageState(0),
			m_nErrorCode(0){
		}


		SMPPQuerySMResp::SMPPQuerySMResp(const SMPPQuerySM& oPackage):
			SMPPResp(CommandId::CM_QUERY_SM_RESP, oPackage.getSequenceNumber()),
			m_sMessageId(""),
			m_sFinalDate(""),
			m_nMessageState(0),
			m_nErrorCode(0){
		}

		SMPPQuerySMResp::SMPPQuerySMResp(const SMPPQuerySM& oPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_QUERY_SM_RESP, oPackage.getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_sFinalDate(""),
			m_nMessageState(0),
			m_nErrorCode(0){
		}

		SMPPQuerySMResp::SMPPQuerySMResp(const SMPPQuerySM::SharedPtr poPackage):
			SMPPResp(CommandId::CM_QUERY_SM_RESP, poPackage->getSequenceNumber()),
			m_sMessageId(""),
			m_sFinalDate(""),
			m_nMessageState(0),
			m_nErrorCode(0){
		}

		SMPPQuerySMResp::SMPPQuerySMResp(const SMPPQuerySM::SharedPtr poPackage, const unsigned nCommandStatus):
			SMPPResp(CommandId::CM_QUERY_SM_RESP, poPackage->getSequenceNumber(), nCommandStatus),
			m_sMessageId(""),
			m_sFinalDate(""),
			m_nMessageState(0),
			m_nErrorCode(0){
		}

		SMPPQuerySMResp::~SMPPQuerySMResp(){
		}

		SMPPPDU* SMPPQuerySMResp::cloneSMPPPDU(void){
			return new SMPPQuerySMResp();
		}

		void SMPPQuerySMResp::fireOnReceived(SMPPSession* poSession){
			SMPPQuerySMResp::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPQuerySMResp::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeMessageId(m_sMessageId);
			poEncoder->encodeFinalDate(m_sFinalDate);
			poEncoder->encodeMessageState(m_nMessageState);
			poEncoder->encodeErrorCode(m_nErrorCode);

		}

		void SMPPQuerySMResp::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());
			poDecoder->decodeFinalDate(m_sFinalDate, getCommandLength());
			poDecoder->decodeMessageState(m_nMessageState, getCommandLength());
			poDecoder->decodeErrorCode(m_nErrorCode, getCommandLength());
		}

		void SMPPQuerySMResp::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputMessageId(m_sMessageId);
			poOutputter->outputFinalDate(m_sFinalDate);
			poOutputter->outputMessageState(m_nMessageState);
			poOutputter->outputErrorCode(m_nErrorCode);

		}

		void SMPPQuerySMResp::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateMessageId(m_sMessageId);
			poValidator->validateFinalDate(m_sFinalDate);
			poValidator->validateMessageState(m_nMessageState);
			poValidator->validateErrorCode(m_nErrorCode);

		}

	}
}
