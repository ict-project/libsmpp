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
#include "SMPPCancelSM.hpp"


namespace anthill {
	namespace smpp {

		SMPPCancelSM::SMPPCancelSM(void):
			SMPPPDU(CommandId::CM_CANCEL_SM),
			m_sServiceType(""),
			m_sMessageId(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_nDestAddrTON(0),
			m_nDestAddrNPI(0),
			m_sDestAddr(""){
		}

		SMPPCancelSM::SMPPCancelSM(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_CANCEL_SM, nSequenceNumber),
			m_sServiceType(""),
			m_sMessageId(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_nDestAddrTON(0),
			m_nDestAddrNPI(0),
			m_sDestAddr(""){
		}

		SMPPCancelSM::~SMPPCancelSM(){
		}

		SMPPPDU* SMPPCancelSM::cloneSMPPPDU(void){
			return new SMPPCancelSM();
		}

		void SMPPCancelSM::fireOnReceived(SMPPSession* poSession){
			SMPPCancelSM::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPCancelSM::encodePacket(SMPPEncoder* poEncoder){

			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeServiceType(m_sServiceType);
			poEncoder->encodeMessageId(m_sMessageId);
			poEncoder->encodeSourceAddrNPI(m_nSourceAddrNPI);
			poEncoder->encodeSourceAddrTON(m_nSourceAddrTON);
			poEncoder->encodeSourceAddr21(m_sSourceAddr);
			poEncoder->encodeDestAddrNPI(m_nDestAddrNPI);
			poEncoder->encodeDestAddrTON(m_nDestAddrTON);
			poEncoder->encodeDestAddr21(m_sDestAddr);


		}

		void SMPPCancelSM::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeServiceType(m_sServiceType, getCommandLength());
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());
			poDecoder->decodeSourceAddrNPI(m_nSourceAddrNPI, getCommandLength());
			poDecoder->decodeSourceAddrTON(m_nSourceAddrTON, getCommandLength());
			poDecoder->decodeSourceAddr21(m_sSourceAddr, getCommandLength());
			poDecoder->decodeDestAddrNPI(m_nDestAddrNPI, getCommandLength());
			poDecoder->decodeDestAddrTON(m_nDestAddrTON, getCommandLength());
			poDecoder->decodeDestAddr21(m_sDestAddr, getCommandLength());

		}

		void SMPPCancelSM::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputServiceType(m_sServiceType);
			poOutputter->outputMessageId(m_sMessageId);
			poOutputter->outputSourceAddrNPI(m_nSourceAddrNPI);
			poOutputter->outputSourceAddrTON(m_nSourceAddrTON);
			poOutputter->outputSourceAddr21(m_sSourceAddr);
			poOutputter->outputDestAddrNPI(m_nDestAddrNPI);
			poOutputter->outputDestAddrTON(m_nDestAddrTON);
			poOutputter->outputDestAddr21(m_sDestAddr);
		}

		void SMPPCancelSM::validatePacket(SMPPValidator* poValidator){

			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateServiceType(m_sServiceType);
			poValidator->validateMessageId(m_sMessageId);
			poValidator->validateSourceAddrNPI(m_nSourceAddrNPI);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddr21(m_sSourceAddr);
			poValidator->validateDestAddrNPI(m_nDestAddrNPI);
			poValidator->validateDestAddrTON(m_nDestAddrTON);
			poValidator->validateDestAddr21(m_sDestAddr);


		}

	}
}
