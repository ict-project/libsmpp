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

#include "SMPPBindTransmitter.hpp"
#include "SMPPBindTransmitterResp.hpp"
#include "SMPPBindReceiver.hpp"
#include "SMPPBindReceiverResp.hpp"
#include "SMPPBindTransceiver.hpp"
#include "SMPPBindTransceiverResp.hpp"
#include "SMPPOutbind.hpp"
#include "SMPPUnbind.hpp"
#include "SMPPUnbindResp.hpp"
#include "SMPPGenericNack.hpp"
#include "SMPPSubmitSM.hpp"
#include "SMPPSubmitSMResp.hpp"
#include "SMPPSubmitMulti.hpp"
#include "SMPPSubmitMultiResp.hpp"
#include "SMPPDeliverSM.hpp"
#include "SMPPDeliverSMResp.hpp"
#include "SMPPDataSM.hpp"
#include "SMPPDataSMResp.hpp"
#include "SMPPQuerySM.hpp"
#include "SMPPQuerySMResp.hpp"
#include "SMPPCancelSM.hpp"
#include "SMPPCancelSMResp.hpp"
#include "SMPPReplaceSM.hpp"
#include "SMPPReplaceSMResp.hpp"
#include "SMPPEnquireLink.hpp"
#include "SMPPEnquireLinkResp.hpp"
#include "SMPPAlertNotification.hpp"
#include "SMPPBroadcastSM.hpp"
#include "SMPPBroadcastSMResp.hpp"
#include "SMPPCancelBroadcastSM.hpp"
#include "SMPPCancelBroadcastSMResp.hpp"
#include "SMPPQueryBroadcastSM.hpp"
#include "SMPPQueryBroadcastSMResp.hpp"

namespace anthill {
	namespace smpp {

		SMPPDecoder::SMPPDecoder(void):
			BinaryDecoder(){

			this->insertCommands();

		}

		SMPPDecoder::~SMPPDecoder(){

			this->eraseCommands();

		}

		SMPPPDU* SMPPDecoder::decodePacket() {
			SMPPPDU* poPDU = this->getPacket();
			if(poPDU){
				unsigned nLen = this->decodeCommandLength();
				poPDU->decodePacket(this);
				this->validateOffset(nLen);
				this->resetBuffer();
				return poPDU;
			} else{
				// std::cout << "Error: unknown PDU" << std::endl;
				throw std::logic_error("Error: unknown command id.");
			}
		}

		const bool SMPPDecoder::hasPackets(void){
			if(this->m_aBuffer.size() < SMPPOffset::SMPP_HEADER_SIZE || 
				this->m_aBuffer.size() < this->decodeCommandLength() ){
				return false;
			}
			return true;
		}

		const bool SMPPDecoder::hasTLVs(void){
			if( (m_nOffset + 1) < decodeCommandLength()){
				return true;
			}
			return false;
		}

		const unsigned short SMPPDecoder::getTLVCode(void){
			unsigned short nValue = 0;
			const unsigned int nSizeof = 2;
			if(SMPPOffset::TLV_CODE_POS + nSizeof <= m_aBuffer.size()){
				const unsigned nShift = m_nOffset + SMPPOffset::TLV_CODE_POS;
				unsigned char* aStart = &m_aBuffer[nShift];
				memcpy(&nValue, aStart, nSizeof);
				nValue = dontohs(nValue);
			}
			return nValue;
		}

		const std::string SMPPDecoder::getTLVError(void){

			// Create a TLVCode
			std::stringstream oOutStream;
			const unsigned int nSizeof = 2;
			if(SMPPOffset::TLV_CODE_POS + nSizeof <= m_aBuffer.size()){
				const unsigned nShift = m_nOffset + SMPPOffset::TLV_CODE_POS;
				unsigned char* aStart = &m_aBuffer[nShift];
				for(unsigned int i=0; i< nSizeof; i++) {
					oOutStream << std::hex << (unsigned int)aStart[i] << " ";
				}
			}
			oOutStream << '\0' ;

			// Output stream
			std::string sTLVCode(oOutStream.str());


			char szBuffer[256];
			memset(szBuffer, 0, sizeof(szBuffer));
			const unsigned nTLVCode = getTLVCode();
			sprintf(szBuffer, "Offset: %d, TLVCode: 0x%X, TLVCode: %s",  m_nOffset, nTLVCode, sTLVCode.c_str());
			return std::string(szBuffer);
		}

		unsigned SMPPDecoder::decodeCommandLength(void){

			int nValue = 0;
			const unsigned int nSizeof = 4;
			if(SMPPOffset::COMMAND_LENGTH_POS + nSizeof <= m_aBuffer.size()){
				const unsigned nShift = SMPPOffset::COMMAND_LENGTH_POS;
				unsigned char* aStart = &m_aBuffer[nShift];
				memcpy(((char*)&nValue), aStart, nSizeof);
				nValue = dontohl(nValue);
			}
			return nValue;
		}


		unsigned SMPPDecoder::decodeCommandId(void){

			int nValue = 0;
			const unsigned int nSizeof = 4;
			if(SMPPOffset::COMMAND_ID_POS + nSizeof <= m_aBuffer.size()){
				const unsigned nShift = SMPPOffset::COMMAND_ID_POS;
				unsigned char* aStart = &m_aBuffer[nShift];
				memcpy(((char*)&nValue), aStart, nSizeof);
				nValue = dontohl(nValue);
			}
			return nValue;
		}

		SMPPPDU* SMPPDecoder::getPacket(void){

			const unsigned nCommandId = decodeCommandId();
			Commands::iterator it = this->m_mCommands.find(nCommandId);
			if(it != m_mCommands.end()){
				return it->second->cloneSMPPPDU();
			}
			return NULL;
		}

		void SMPPDecoder::insertCommands(void){
			// Insert all available command from SMPP protocol
			m_mCommands[CommandId::CM_GENERIC_NACK] = new SMPPGenericNack();
			m_mCommands[CommandId::CM_BIND_RECEIVER] = new SMPPBindReceiver();
			m_mCommands[CommandId::CM_BIND_RECEIVER_RESP] = new SMPPBindReceiverResp();
			m_mCommands[CommandId::CM_BIND_TRANSMITTER] = new SMPPBindTransmitter();
			m_mCommands[CommandId::CM_BIND_TRANSMITTER_RESP] = new SMPPBindTransmitterResp();
			m_mCommands[CommandId::CM_QUERY_SM] = new SMPPQuerySM();
			m_mCommands[CommandId::CM_QUERY_SM_RESP] = new SMPPQuerySMResp();
			m_mCommands[CommandId::CM_SUBMIT_SM] = new SMPPSubmitSM();
			m_mCommands[CommandId::CM_SUBMIT_SM_RESP] = new SMPPSubmitSMResp();
			m_mCommands[CommandId::CM_DELIVER_SM] = new SMPPDeliverSM();
			m_mCommands[CommandId::CM_DELIVER_SM_RESP] = new SMPPDeliverSMResp();
			m_mCommands[CommandId::CM_UNBIND] = new SMPPUnbind();
			m_mCommands[CommandId::CM_UNBIND_RESP] = new SMPPUnbindResp();
			m_mCommands[CommandId::CM_REPLACE_SM] = new SMPPReplaceSM();
			m_mCommands[CommandId::CM_REPLACE_SM_RESP] = new SMPPReplaceSMResp();
			m_mCommands[CommandId::CM_CANCEL_SM] = new SMPPCancelSM();
			m_mCommands[CommandId::CM_CANCEL_SM_RESP] = new SMPPCancelSMResp();
			m_mCommands[CommandId::CM_BIND_TRANSCEIVER] = new SMPPBindTransceiver();
			m_mCommands[CommandId::CM_BIND_TRANSCEIVER_RESP] = new SMPPBindTransceiverResp();
			m_mCommands[CommandId::CM_OUTBIND] = new SMPPOutbind();
			m_mCommands[CommandId::CM_ENQUIRE_LINK] = new SMPPEnquireLink();
			m_mCommands[CommandId::CM_ENQUIRE_LINK_RESP] = new SMPPEnquireLinkResp();
			m_mCommands[CommandId::CM_SUBMIT_MULTI] = new SMPPSubmitMulti();
			m_mCommands[CommandId::CM_SUBMIT_MULTI_RESP] = new SMPPSubmitMultiResp();
			m_mCommands[CommandId::CM_ALERT_NOTIFICATION] = new SMPPAlertNotification();
			m_mCommands[CommandId::CM_DATA_SM] = new SMPPDataSM();
			m_mCommands[CommandId::CM_DATA_SM_RESP] = new SMPPDataSMResp();
			m_mCommands[CommandId::CM_BROADCAST_SM] = new SMPPBroadcastSM();
			m_mCommands[CommandId::CM_BROADCAST_SM_RESP] = new SMPPBroadcastSMResp();
			m_mCommands[CommandId::CM_QUERY_BROADCAST_SM] = new SMPPQueryBroadcastSM();
			m_mCommands[CommandId::CM_QUERY_BROADCAST_SM_RESP] = new SMPPQueryBroadcastSMResp();
			m_mCommands[CommandId::CM_CANCEL_BROADCAST_SM] = new SMPPCancelBroadcastSM();
			m_mCommands[CommandId::CM_CANCEL_BROADCAST_SM_RESP] = new SMPPCancelBroadcastSMResp();
		}

		void SMPPDecoder::eraseCommands(void){
			for(Commands::iterator it = m_mCommands.begin(); it!= m_mCommands.end();) {
				delete it->second;
				this->m_mCommands.erase(it++);
			}
		}

		void SMPPDecoder::decodeTLV(unsigned char& nValue, unsigned short& nLen, const unsigned nLimit){
			this->skipNBytes(SMPPOffset::TLV_TAG_LENGHT, nLimit);
			this->decodeUnsigned16(nLen, nLimit);
			this->decodeChar(nValue, nLimit);
		}

		void SMPPDecoder::decodeTLV(unsigned short& nValue, unsigned short& nLen, const unsigned nLimit){
			this->skipNBytes(SMPPOffset::TLV_TAG_LENGHT, nLimit);
			this->decodeUnsigned16(nLen, nLimit);
			this->decodeUnsigned16(nValue, nLimit);
		}

		void SMPPDecoder::decodeTLV(unsigned& nValue, unsigned short& nLen, const unsigned nLimit){
			this->skipNBytes(SMPPOffset::TLV_TAG_LENGHT, nLimit);
			this->decodeUnsigned16(nLen, nLimit);
			this->decodeUnsigned32(nValue, nLimit);
		}

		void SMPPDecoder::decodeTLV(std::string& sValue, unsigned short& nLen, const unsigned nLimit){
			this->skipNBytes(SMPPOffset::TLV_TAG_LENGHT, nLimit);
			this->decodeUnsigned16(nLen, nLimit);
			this->decodeCStringMax(sValue, nLen, nLimit);
		}

		void SMPPDecoder::decodeTLV(std::vector<unsigned char>& aValue, unsigned short& nLen, const unsigned nLimit){
			this->skipNBytes(SMPPOffset::TLV_TAG_LENGHT, nLimit);
			this->decodeUnsigned16(nLen, nLimit);
			this->decodeBinary(aValue, nLen, nLimit);
		}

	}
}
