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
#include "SMPPDataSM.hpp"


namespace anthill {
	namespace smpp {

		SMPPDataSM::SMPPDataSM(void):
			SMPPPDU(CommandId::CM_DATA_SM),
			m_sServiceType(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_nDestAddrTON(0),
			m_nDestAddrNPI(0),
			m_sDestAddr(""),
			m_nEsmClass(0),
			m_nRegisteredDelivery(0),
			m_nDataCoding(0),
			m_nSourcePort(0),
			m_nSourceAddrSubunit(0),
			m_nSourceNetworkType(0),
			m_nSourceBearerType(0),
			m_nSourceTelematicsId(0),
			m_nDestinationPort(0),
			m_nDestAddrSubunit(0),
			m_nDestNetworkType(0),
			m_nDestBearerType(0),
			m_nDestTelematicsId(0),
			m_nSarMsgRefNum(0),
			m_nSarTotalSegments(0),
			m_nSarSegmentSeqnum(0),
			m_nMoreMessagesToSend(0),
			m_nQosTimeToLive(0),
			m_nPayloadType(0),
			m_aMessagePayload(),
			m_nSetDpf(0),
			m_sReceiptedMessageId(""),
			m_nMessageState(0),
			m_oNetworkErrorCode(),
			m_nUserMessageReference(0),
			m_nPrivacyIndicator(0),
			m_aCallbackNum(),
			m_nCallbackNumPresInd(0),
			m_aCallbackNumAtag(),
			m_aSourceSubaddress(),
			m_aDestSubaddress(),
			m_nUserResponseCode(0),
			m_nDisplayTime(0),
			m_nSmsSignal(0),
			m_nMsValidity(0),
			m_nMsMsgWaitFacilities(0),
			m_nNumberOfMessages(0),
			m_nAlertOnMsgDelivery(0),
			m_nLanguageIndicator(0),
			m_nItsReplyType(0),
			m_nItsSessionInfo(0),
			m_bPresentSourcePort(false),
			m_bPresentSourceAddrSubunit(false),
			m_bPresentSourceNetworkType(false),
			m_bPresentSourceBearerType(false),
			m_bPresentSourceTelematicsId(false),
			m_bPresentDestinationPort(false),
			m_bPresentDestAddrSubunit(false),
			m_bPresentDestNetworkType(false),
			m_bPresentDestBearerType(false),
			m_bPresentDestTelematicsId(false),
			m_bPresentSarMsgRefNum(false),
			m_bPresentSarTotalSegments(false),
			m_bPresentSarSegmentSeqnum(false),
			m_bPresentMoreMessagesToSend(false),
			m_bPresentQosTimeToLive(false),
			m_bPresentPayloadType(false),
			m_bPresentMessagePayload(false),
			m_bPresentSetDpf(false),
			m_bPresentReceiptedMessageId(false),
			m_bPresentMessageState(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentUserMessageReference(false),
			m_bPresentPrivacyIndicator(false),
			m_bPresentCallbackNum(false),
			m_bPresentCallbackNumPresInd(false),
			m_bPresentCallbackNumAtag(false),
			m_bPresentSourceSubaddress(false),
			m_bPresentDestSubaddress(false),
			m_bPresentUserResponseCode(false),
			m_bPresentDisplayTime(false),
			m_bPresentSmsSignal(false),
			m_bPresentMsValidity(false),
			m_bPresentMsMsgWaitFacilities(false),
			m_bPresentNumberOfMessages(false),
			m_bPresentAlertOnMsgDelivery(false),
			m_bPresentLanguageIndicator(false),
			m_bPresentItsReplyType(false),
			m_bPresentItsSessionInfo(false),
			m_nSourcePortLen(sizeof(unsigned short)),
			m_nSourceAddrSubunitLen(sizeof(char)),
			m_nSourceNetworkTypeLen(sizeof(char)),
			m_nSourceBearerTypeLen(sizeof(char)),
			m_nSourceTelematicsIdLen(sizeof(char)),
			m_nDestinationPortLen(sizeof(unsigned short)),
			m_nDestAddrSubunitLen(sizeof(char)),
			m_nDestNetworkTypeLen(sizeof(char)),
			m_nDestBearerTypeLen(sizeof(char)),
			m_nDestTelematicsIdLen(sizeof(char)),
			m_nSarMsgRefNumLen(sizeof(unsigned short)),
			m_nSarTotalSegmentsLen(sizeof(char)),
			m_nSarSegmentSeqnumLen(sizeof(char)),
			m_nMoreMessagesToSendLen(sizeof(char)),
			m_nQosTimeToLiveLen(sizeof(unsigned)),
			m_nPayloadTypeLen(sizeof(char)),
			m_nMessagePayloadLen(m_aMessagePayload.size()),
			m_nSetDpfLen(sizeof(char)),
			m_nReceiptedMessageIdLen(m_sReceiptedMessageId.size()+1),
			m_nMessageStateLen(sizeof(char)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nPrivacyIndicatorLen(sizeof(char)),
			m_nCallbackNumLen(m_aCallbackNum.size()),
			m_nCallbackNumPresIndLen(sizeof(char)),
			m_nCallbackNumAtagLen(m_aCallbackNumAtag.size()),
			m_nSourceSubaddressLen(m_aSourceSubaddress.size()),
			m_nDestSubaddressLen(m_aDestSubaddress.size()),
			m_nUserResponseCodeLen(sizeof(char)),
			m_nDisplayTimeLen(sizeof(char)),
			m_nSmsSignalLen(sizeof(unsigned short)),
			m_nMsValidityLen(sizeof(char)),
			m_nMsMsgWaitFacilitiesLen(sizeof(char)),
			m_nNumberOfMessagesLen(sizeof(char)),
			m_nAlertOnMsgDeliveryLen(sizeof(char)),
			m_nLanguageIndicatorLen(sizeof(char)),
			m_nItsReplyTypeLen(sizeof(char)),
			m_nItsSessionInfoLen(sizeof(unsigned short)){
		}

		SMPPDataSM::SMPPDataSM(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_DATA_SM, nSequenceNumber),
			m_sServiceType(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_nDestAddrTON(0),
			m_nDestAddrNPI(0),
			m_sDestAddr(""),
			m_nEsmClass(0),
			m_nRegisteredDelivery(0),
			m_nDataCoding(0),
			m_nSourcePort(0),
			m_nSourceAddrSubunit(0),
			m_nSourceNetworkType(0),
			m_nSourceBearerType(0),
			m_nSourceTelematicsId(0),
			m_nDestinationPort(0),
			m_nDestAddrSubunit(0),
			m_nDestNetworkType(0),
			m_nDestBearerType(0),
			m_nDestTelematicsId(0),
			m_nSarMsgRefNum(0),
			m_nSarTotalSegments(0),
			m_nSarSegmentSeqnum(0),
			m_nMoreMessagesToSend(0),
			m_nQosTimeToLive(0),
			m_nPayloadType(0),
			m_aMessagePayload(),
			m_nSetDpf(0),
			m_sReceiptedMessageId(""),
			m_nMessageState(0),
			m_oNetworkErrorCode(),
			m_nUserMessageReference(0),
			m_nPrivacyIndicator(0),
			m_aCallbackNum(),
			m_nCallbackNumPresInd(0),
			m_aCallbackNumAtag(),
			m_aSourceSubaddress(),
			m_aDestSubaddress(),
			m_nUserResponseCode(0),
			m_nDisplayTime(0),
			m_nSmsSignal(0),
			m_nMsValidity(0),
			m_nMsMsgWaitFacilities(0),
			m_nNumberOfMessages(0),
			m_nAlertOnMsgDelivery(0),
			m_nLanguageIndicator(0),
			m_nItsReplyType(0),
			m_nItsSessionInfo(0),
			m_bPresentSourcePort(false),
			m_bPresentSourceAddrSubunit(false),
			m_bPresentSourceNetworkType(false),
			m_bPresentSourceBearerType(false),
			m_bPresentSourceTelematicsId(false),
			m_bPresentDestinationPort(false),
			m_bPresentDestAddrSubunit(false),
			m_bPresentDestNetworkType(false),
			m_bPresentDestBearerType(false),
			m_bPresentDestTelematicsId(false),
			m_bPresentSarMsgRefNum(false),
			m_bPresentSarTotalSegments(false),
			m_bPresentSarSegmentSeqnum(false),
			m_bPresentMoreMessagesToSend(false),
			m_bPresentQosTimeToLive(false),
			m_bPresentPayloadType(false),
			m_bPresentMessagePayload(false),
			m_bPresentSetDpf(false),
			m_bPresentReceiptedMessageId(false),
			m_bPresentMessageState(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentUserMessageReference(false),
			m_bPresentPrivacyIndicator(false),
			m_bPresentCallbackNum(false),
			m_bPresentCallbackNumPresInd(false),
			m_bPresentCallbackNumAtag(false),
			m_bPresentSourceSubaddress(false),
			m_bPresentDestSubaddress(false),
			m_bPresentUserResponseCode(false),
			m_bPresentDisplayTime(false),
			m_bPresentSmsSignal(false),
			m_bPresentMsValidity(false),
			m_bPresentMsMsgWaitFacilities(false),
			m_bPresentNumberOfMessages(false),
			m_bPresentAlertOnMsgDelivery(false),
			m_bPresentLanguageIndicator(false),
			m_bPresentItsReplyType(false),
			m_bPresentItsSessionInfo(false),
			m_nSourcePortLen(sizeof(unsigned short)),
			m_nSourceAddrSubunitLen(sizeof(char)),
			m_nSourceNetworkTypeLen(sizeof(char)),
			m_nSourceBearerTypeLen(sizeof(char)),
			m_nSourceTelematicsIdLen(sizeof(char)),
			m_nDestinationPortLen(sizeof(unsigned short)),
			m_nDestAddrSubunitLen(sizeof(char)),
			m_nDestNetworkTypeLen(sizeof(char)),
			m_nDestBearerTypeLen(sizeof(char)),
			m_nDestTelematicsIdLen(sizeof(char)),
			m_nSarMsgRefNumLen(sizeof(unsigned short)),
			m_nSarTotalSegmentsLen(sizeof(char)),
			m_nSarSegmentSeqnumLen(sizeof(char)),
			m_nMoreMessagesToSendLen(sizeof(char)),
			m_nQosTimeToLiveLen(sizeof(unsigned)),
			m_nPayloadTypeLen(sizeof(char)),
			m_nMessagePayloadLen(m_aMessagePayload.size()),
			m_nSetDpfLen(sizeof(char)),
			m_nReceiptedMessageIdLen(m_sReceiptedMessageId.size()+1),
			m_nMessageStateLen(sizeof(char)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nPrivacyIndicatorLen(sizeof(char)),
			m_nCallbackNumLen(m_aCallbackNum.size()),
			m_nCallbackNumPresIndLen(sizeof(char)),
			m_nCallbackNumAtagLen(m_aCallbackNumAtag.size()),
			m_nSourceSubaddressLen(m_aSourceSubaddress.size()),
			m_nDestSubaddressLen(m_aDestSubaddress.size()),
			m_nUserResponseCodeLen(sizeof(char)),
			m_nDisplayTimeLen(sizeof(char)),
			m_nSmsSignalLen(sizeof(unsigned short)),
			m_nMsValidityLen(sizeof(char)),
			m_nMsMsgWaitFacilitiesLen(sizeof(char)),
			m_nNumberOfMessagesLen(sizeof(char)),
			m_nAlertOnMsgDeliveryLen(sizeof(char)),
			m_nLanguageIndicatorLen(sizeof(char)),
			m_nItsReplyTypeLen(sizeof(char)),
			m_nItsSessionInfoLen(sizeof(unsigned short)){
		}

		SMPPDataSM::~SMPPDataSM(){
		}

		SMPPPDU* SMPPDataSM::cloneSMPPPDU(void){
			return new SMPPDataSM();
		}

		void SMPPDataSM::fireOnReceived(SMPPSession* poSession){
			SMPPDataSM::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPDataSM::encodePacket(SMPPEncoder* poEncoder){

			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeServiceType(m_sServiceType);
			poEncoder->encodeSourceAddrTON(m_nSourceAddrTON);
			poEncoder->encodeSourceAddrNPI(m_nSourceAddrNPI);
			poEncoder->encodeSourceAddr65(m_sSourceAddr);
			poEncoder->encodeDestAddrTON(m_nDestAddrTON);
			poEncoder->encodeDestAddrNPI(m_nDestAddrNPI);
			poEncoder->encodeDestAddr65(m_sDestAddr);
			poEncoder->encodeEsmClass(m_nEsmClass);
			poEncoder->encodeRegisteredDelivery(m_nRegisteredDelivery);
			poEncoder->encodeDataCoding(m_nDataCoding);


			// Encode optional fields
			if(this->m_bPresentSourcePort)
				poEncoder->encodeSourcePort(m_nSourcePort,
					m_nSourcePortLen);
			if(this->m_bPresentSourceAddrSubunit)
				poEncoder->encodeSourceAddrSubunit(m_nSourceAddrSubunit,
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentSourceNetworkType)
				poEncoder->encodeSourceNetworkType(m_nSourceNetworkType,
					m_nSourceNetworkTypeLen);
			if(this->m_bPresentSourceBearerType)
				poEncoder->encodeSourceBearerType(m_nSourceBearerType,
					m_nSourceBearerTypeLen);
			if(this->m_bPresentSourceTelematicsId)
				poEncoder->encodeSourceTelematicsId(m_nSourceTelematicsId,
					m_nSourceTelematicsIdLen);
			if(this->m_bPresentDestinationPort)
				poEncoder->encodeDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentDestAddrSubunit)
				poEncoder->encodeDestAddrSubunit(m_nDestAddrSubunit,
					m_nDestAddrSubunitLen);
			if(this->m_bPresentDestNetworkType)
				poEncoder->encodeDestNetworkType(m_nDestNetworkType,
					m_nDestNetworkTypeLen);
			if(this->m_bPresentDestBearerType)
				poEncoder->encodeDestBearerType(m_nDestBearerType,
					m_nDestBearerTypeLen);
			if(this->m_bPresentDestTelematicsId)
				poEncoder->encodeDestTelematicsId(m_nDestTelematicsId,
					m_nDestTelematicsIdLen);
			if(this->m_bPresentSarMsgRefNum)
				poEncoder->encodeSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poEncoder->encodeSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poEncoder->encodeSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentMoreMessagesToSend)
				poEncoder->encodeMoreMessagesToSend(m_nMoreMessagesToSend,
					m_nMoreMessagesToSendLen);
			if(this->m_bPresentQosTimeToLive)
				poEncoder->encodeQosTimeToLive(m_nQosTimeToLive,
					m_nQosTimeToLiveLen);
			if(this->m_bPresentPayloadType)
				poEncoder->encodePayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poEncoder->encodeMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
			if(this->m_bPresentSetDpf)
				poEncoder->encodeSetDpf(m_nSetDpf,
					m_nSetDpfLen);
			if(this->m_bPresentReceiptedMessageId)
				poEncoder->encodeReceiptedMessageId(m_sReceiptedMessageId,
					m_nReceiptedMessageIdLen);
			if(this->m_bPresentMessageState)
				poEncoder->encodeMessageStateTLV(m_nMessageState,
					m_nMessageStateLen);
			if(this->m_bPresentNetworkErrorCode)
				poEncoder->encodeNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentUserMessageReference)
				poEncoder->encodeUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentPrivacyIndicator)
				poEncoder->encodePrivacyIndicator(m_nPrivacyIndicator,
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentCallbackNum)
				poEncoder->encodeCallbackNum(m_aCallbackNum,
					m_nCallbackNumLen);
			if(this->m_bPresentCallbackNumPresInd)
				poEncoder->encodeCallbackNumPresInd(m_nCallbackNumPresInd,
					m_nCallbackNumPresIndLen);
			if(this->m_bPresentCallbackNumAtag)
				poEncoder->encodeCallbackNumAtag(m_aCallbackNumAtag,
					m_nCallbackNumAtagLen);
			if(this->m_bPresentSourceSubaddress)
				poEncoder->encodeSourceSubaddress(m_aSourceSubaddress,
					m_nSourceSubaddressLen);
			if(this->m_bPresentDestSubaddress)
				poEncoder->encodeDestSubaddress(m_aDestSubaddress,
					m_nDestSubaddressLen);
			if(this->m_bPresentUserResponseCode)
				poEncoder->encodeUserResponseCode(m_nUserResponseCode,
					m_nUserResponseCodeLen);
			if(this->m_bPresentDisplayTime)
				poEncoder->encodeDisplayTime(m_nDisplayTime,
					m_nDisplayTimeLen);
			if(this->m_bPresentSmsSignal)
				poEncoder->encodeSmsSignal(m_nSmsSignal,
					m_nSmsSignalLen);
			if(this->m_bPresentMsValidity)
				poEncoder->encodeMsValidity(m_nMsValidity,
					m_nMsValidityLen);
			if(this->m_bPresentMsMsgWaitFacilities)
				poEncoder->encodeMsMsgWaitFacilities(m_nMsMsgWaitFacilities,
					m_nMsMsgWaitFacilitiesLen);
			if(this->m_bPresentNumberOfMessages)
				poEncoder->encodeNumberOfMessages(m_nNumberOfMessages,
					m_nNumberOfMessagesLen);
			if(this->m_bPresentAlertOnMsgDelivery)
				poEncoder->encodeAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
					m_nAlertOnMsgDeliveryLen);
			if(this->m_bPresentLanguageIndicator)
				poEncoder->encodeLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
			if(this->m_bPresentItsReplyType)
				poEncoder->encodeItsReplyType(m_nItsReplyType,
					m_nItsReplyTypeLen);
			if(this->m_bPresentItsSessionInfo)
				poEncoder->encodeItsSessionInfo(m_nItsSessionInfo,
					m_nItsSessionInfoLen);

		}

		void SMPPDataSM::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeServiceType(m_sServiceType, getCommandLength());
			poDecoder->decodeSourceAddrTON(m_nSourceAddrTON, getCommandLength());
			poDecoder->decodeSourceAddrNPI(m_nSourceAddrNPI, getCommandLength());
			poDecoder->decodeSourceAddr65(m_sSourceAddr, getCommandLength());
			poDecoder->decodeDestAddrTON(m_nDestAddrTON, getCommandLength());
			poDecoder->decodeDestAddrNPI(m_nDestAddrNPI, getCommandLength());
			poDecoder->decodeDestAddr65(m_sDestAddr, getCommandLength());
			poDecoder->decodeEsmClass(m_nEsmClass, getCommandLength());
			poDecoder->decodeRegisteredDelivery(m_nRegisteredDelivery, getCommandLength());
			poDecoder->decodeDataCoding(m_nDataCoding, getCommandLength());


			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_SOURCE_PORT:{
						poDecoder->decodeSourcePort(m_nSourcePort,
							m_nSourcePortLen, this->getCommandLength());
						this->m_bPresentSourcePort = true;
						break;
					}
					case OptTags::TAG_SOURCE_ADDR_SUBUNIT:{
						poDecoder->decodeSourceAddrSubunit(m_nSourceAddrSubunit,
							m_nSourceAddrSubunitLen, this->getCommandLength());
						this->m_bPresentSourceAddrSubunit = true;
						break;
					}
					case OptTags::TAG_SOURCE_NETWORK_TYPE:{
						poDecoder->decodeSourceNetworkType(m_nSourceNetworkType,
							m_nSourceNetworkTypeLen, this->getCommandLength());
						this->m_bPresentSourceNetworkType = true;
						break;
					}
					case OptTags::TAG_SOURCE_BEARER_TYPE:{
						poDecoder->decodeSourceBearerType(m_nSourceBearerType,
							m_nSourceBearerTypeLen, this->getCommandLength());
						this->m_bPresentSourceBearerType = true;
						break;
					}
					case OptTags::TAG_SOURCE_TELEMATICS_ID:{
						poDecoder->decodeSourceTelematicsId(m_nSourceTelematicsId,
							m_nSourceTelematicsIdLen, this->getCommandLength());
						this->m_bPresentSourceTelematicsId = true;
						break;
					}
					case OptTags::TAG_DESTINATION_PORT:{
						poDecoder->decodeDestinationPort(m_nDestinationPort,
							m_nDestinationPortLen, this->getCommandLength());
						this->m_bPresentDestinationPort = true;
						break;
					}
					case OptTags::TAG_DEST_ADDR_SUBUNIT:{
						poDecoder->decodeDestAddrSubunit(m_nDestAddrSubunit,
							m_nDestAddrSubunitLen, this->getCommandLength());
						this->m_bPresentDestAddrSubunit = true;
						break;
					}
					case OptTags::TAG_DEST_NETWORK_TYPE:{
						poDecoder->decodeDestNetworkType(m_nDestNetworkType,
							m_nDestNetworkTypeLen, this->getCommandLength());
						this->m_bPresentDestNetworkType = true;
						break;
					}
					case OptTags::TAG_DEST_BEARER_TYPE:{
						poDecoder->decodeDestBearerType(m_nDestBearerType,
							m_nDestBearerTypeLen, this->getCommandLength());
						this->m_bPresentDestBearerType = true;
						break;
					}
					case OptTags::TAG_DEST_TELEMATICS_ID:{
						poDecoder->decodeDestTelematicsId(m_nDestTelematicsId,
							m_nDestTelematicsIdLen, this->getCommandLength());
						this->m_bPresentDestTelematicsId = true;
						break;
					}
					case OptTags::TAG_SAR_MSG_REF_NUM:{
						poDecoder->decodeSarMsgRefNum(m_nSarMsgRefNum,
							m_nSarMsgRefNumLen, this->getCommandLength());
						this->m_bPresentSarMsgRefNum = true;
						break;
					}
					case OptTags::TAG_SAR_TOTAL_SEGMENTS:{
						poDecoder->decodeSarTotalSegments(m_nSarTotalSegments,
							m_nSarTotalSegmentsLen, this->getCommandLength());
						this->m_bPresentSarTotalSegments = true;
						break;
					}
					case OptTags::TAG_SAR_SEGMENT_SEQNUM:{
						poDecoder->decodeSarSegmentSeqnum(m_nSarSegmentSeqnum,
							m_nSarSegmentSeqnumLen, this->getCommandLength());
						this->m_bPresentSarSegmentSeqnum = true;
						break;
					}
					case OptTags::TAG_MORE_MESSAGES_TO_SEND:{
						poDecoder->decodeMoreMessagesToSend(m_nMoreMessagesToSend,
							m_nMoreMessagesToSendLen, this->getCommandLength());
						this->m_bPresentMoreMessagesToSend = true;
						break;
					}
					case OptTags::TAG_QOS_TIME_TO_LIVE:{
						poDecoder->decodeQosTimeToLive(m_nQosTimeToLive,
							m_nQosTimeToLiveLen, this->getCommandLength());
						this->m_bPresentQosTimeToLive = true;
						break;
					}
					case OptTags::TAG_PAYLOAD_TYPE:{
						poDecoder->decodePayloadType(m_nPayloadType,
							m_nPayloadTypeLen, this->getCommandLength());
						this->m_bPresentPayloadType = true;
						break;
					}
					case OptTags::TAG_MESSAGE_PAYLOAD:{
						poDecoder->decodeMessagePayload(m_aMessagePayload,
							m_nMessagePayloadLen, this->getCommandLength());
						this->m_bPresentMessagePayload = true;
						break;
					}
					case OptTags::TAG_SET_DPF:{
						poDecoder->decodeSetDpf(m_nSetDpf,
							m_nSetDpfLen, this->getCommandLength());
						this->m_bPresentSetDpf = true;
						break;
					}
					case OptTags::TAG_RECEIPTED_MESSAGE_ID:{
						poDecoder->decodeReceiptedMessageId(m_sReceiptedMessageId,
							m_nReceiptedMessageIdLen, this->getCommandLength());
						this->m_bPresentReceiptedMessageId = true;
						break;
					}
					case OptTags::TAG_MESSAGE_STATE:{
						poDecoder->decodeMessageStateTLV(m_nMessageState,
							m_nMessageStateLen, this->getCommandLength());
						this->m_bPresentMessageState = true;
						break;
					}
					case OptTags::TAG_NETWORK_ERROR_CODE:{
						poDecoder->decodeNetworkErrorCode(m_oNetworkErrorCode,
							m_nNetworkErrorCodeLen, this->getCommandLength());
						this->m_bPresentNetworkErrorCode = true;
						break;
					}
					case OptTags::TAG_USER_MESSAGE_REFERENCE:{
						poDecoder->decodeUserMessageReference(m_nUserMessageReference,
							m_nUserMessageReferenceLen, this->getCommandLength());
						this->m_bPresentUserMessageReference = true;
						break;
					}
					case OptTags::TAG_PRIVACY_INDICATOR:{
						poDecoder->decodePrivacyIndicator(m_nPrivacyIndicator,
							m_nPrivacyIndicatorLen, this->getCommandLength());
						this->m_bPresentPrivacyIndicator = true;
						break;
					}
					case OptTags::TAG_CALLBACK_NUM:{
						poDecoder->decodeCallbackNum(m_aCallbackNum,
							m_nCallbackNumLen, this->getCommandLength());
						this->m_bPresentCallbackNum = true;
						break;
					}
					case OptTags::TAG_CALLBACK_NUM_PRES_IND:{
						poDecoder->decodeCallbackNumPresInd(m_nCallbackNumPresInd,
							m_nCallbackNumPresIndLen, this->getCommandLength());
						this->m_bPresentCallbackNumPresInd = true;
						break;
					}
					case OptTags::TAG_CALLBACK_NUM_ATAG:{
						poDecoder->decodeCallbackNumAtag(m_aCallbackNumAtag,
							m_nCallbackNumAtagLen, this->getCommandLength());
						this->m_bPresentCallbackNumAtag = true;
						break;
					}
					case OptTags::TAG_SOURCE_SUBADDRESS:{
						poDecoder->decodeSourceSubaddress(m_aSourceSubaddress,
							m_nSourceSubaddressLen, this->getCommandLength());
						this->m_bPresentSourceSubaddress = true;
						break;
					}
					case OptTags::TAG_DEST_SUBADDRESS:{
						poDecoder->decodeDestSubaddress(m_aDestSubaddress,
							m_nDestSubaddressLen, this->getCommandLength());
						this->m_bPresentDestSubaddress = true;
						break;
					}
					case OptTags::TAG_USER_RESPONSE_CODE:{
						poDecoder->decodeUserResponseCode(m_nUserResponseCode,
							m_nUserResponseCodeLen, this->getCommandLength());
						this->m_bPresentUserResponseCode = true;
						break;
					}
					case OptTags::TAG_DISPLAY_TIME:{
						poDecoder->decodeDisplayTime(m_nDisplayTime,
							m_nDisplayTimeLen, this->getCommandLength());
						this->m_bPresentDisplayTime = true;
						break;
					}
					case OptTags::TAG_SMS_SIGNAL:{
						poDecoder->decodeSmsSignal(m_nSmsSignal,
							m_nSmsSignalLen, this->getCommandLength());
						this->m_bPresentSmsSignal = true;
						break;
					}
					case OptTags::TAG_MS_VALIDITY:{
						poDecoder->decodeMsValidity(m_nMsValidity,
							m_nMsValidityLen, this->getCommandLength());
						this->m_bPresentMsValidity = true;
						break;
					}
					case OptTags::TAG_MS_MSG_WAIT_FACILITIES:{
						poDecoder->decodeMsMsgWaitFacilities(m_nMsMsgWaitFacilities,
							m_nMsMsgWaitFacilitiesLen, this->getCommandLength());
						this->m_bPresentMsMsgWaitFacilities = true;
						break;
					}
					case OptTags::TAG_NUMBER_OF_MESSAGES:{
						poDecoder->decodeNumberOfMessages(m_nNumberOfMessages,
							m_nNumberOfMessagesLen, this->getCommandLength());
						this->m_bPresentNumberOfMessages = true;
						break;
					}
					case OptTags::TAG_ALERT_ON_MESSAGE_DELIVERY:{
						poDecoder->decodeAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
							m_nAlertOnMsgDeliveryLen, this->getCommandLength());
						this->m_bPresentAlertOnMsgDelivery = true;
						break;
					}
					case OptTags::TAG_LANGUAGE_INDICATOR:{
						poDecoder->decodeLanguageIndicator(m_nLanguageIndicator,
							m_nLanguageIndicatorLen, this->getCommandLength());
						this->m_bPresentLanguageIndicator = true;
						break;
					}
					case OptTags::TAG_ITS_REPLY_TYPE:{
						poDecoder->decodeItsReplyType(m_nItsReplyType,
							m_nItsReplyTypeLen, this->getCommandLength());
						this->m_bPresentItsReplyType = true;
						break;
					}
					case OptTags::TAG_ITS_SESSION_INFO:{
						poDecoder->decodeItsSessionInfo(m_nItsSessionInfo,
							m_nItsSessionInfoLen, this->getCommandLength());
						this->m_bPresentItsSessionInfo = true;
						break;
					}
					default:{
						// Report about error
						std::string sMessage(poDecoder->getTLVError());
						throw std::logic_error(Errors::UNKNOWN_TAG_MSG + sMessage);
						break;
					}
				}
			}
		}

		void SMPPDataSM::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputServiceType(m_sServiceType);
			poOutputter->outputSourceAddrTON(m_nSourceAddrTON);
			poOutputter->outputSourceAddrNPI(m_nSourceAddrNPI);
			poOutputter->outputSourceAddr65(m_sSourceAddr);
			poOutputter->outputDestAddrTON(m_nDestAddrTON);
			poOutputter->outputDestAddrNPI(m_nDestAddrNPI);
			poOutputter->outputDestAddr65(m_sDestAddr);
			poOutputter->outputEsmClass(m_nEsmClass);
			poOutputter->outputRegisteredDelivery(m_nRegisteredDelivery);
			poOutputter->outputDataCoding(m_nDataCoding);

			// Output optional fields
			if(this->m_bPresentSourcePort)
				poOutputter->outputSourcePort(m_nSourcePort,
					m_nSourcePortLen);
			if(this->m_bPresentSourceAddrSubunit)
				poOutputter->outputSourceAddrSubunit(m_nSourceAddrSubunit,
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentSourceNetworkType)
				poOutputter->outputSourceNetworkType(m_nSourceNetworkType,
					m_nSourceNetworkTypeLen);
			if(this->m_bPresentSourceBearerType)
				poOutputter->outputSourceBearerType(m_nSourceBearerType,
					m_nSourceBearerTypeLen);
			if(this->m_bPresentSourceTelematicsId)
				poOutputter->outputSourceTelematicsId(m_nSourceTelematicsId,
					m_nSourceTelematicsIdLen);
			if(this->m_bPresentDestinationPort)
				poOutputter->outputDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentDestAddrSubunit)
				poOutputter->outputDestAddrSubunit(m_nDestAddrSubunit,
					m_nDestAddrSubunitLen);
			if(this->m_bPresentDestNetworkType)
				poOutputter->outputDestNetworkType(m_nDestNetworkType,
					m_nDestNetworkTypeLen);
			if(this->m_bPresentDestBearerType)
				poOutputter->outputDestBearerType(m_nDestBearerType,
					m_nDestBearerTypeLen);
			if(this->m_bPresentDestTelematicsId)
				poOutputter->outputDestTelematicsId(m_nDestTelematicsId,
					m_nDestTelematicsIdLen);
			if(this->m_bPresentSarMsgRefNum)
				poOutputter->outputSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poOutputter->outputSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poOutputter->outputSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentMoreMessagesToSend)
				poOutputter->outputMoreMessagesToSend(m_nMoreMessagesToSend,
					m_nMoreMessagesToSendLen);
			if(this->m_bPresentQosTimeToLive)
				poOutputter->outputQosTimeToLive(m_nQosTimeToLive,
					m_nQosTimeToLiveLen);
			if(this->m_bPresentPayloadType)
				poOutputter->outputPayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poOutputter->outputMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
			if(this->m_bPresentSetDpf)
				poOutputter->outputSetDpf(m_nSetDpf,
					m_nSetDpfLen);
			if(this->m_bPresentReceiptedMessageId)
				poOutputter->outputReceiptedMessageId(m_sReceiptedMessageId,
					m_nReceiptedMessageIdLen);
			if(this->m_bPresentMessageState)
				poOutputter->outputMessageStateTLVOpt(m_nMessageState,
					m_nMessageStateLen);
			if(this->m_bPresentNetworkErrorCode)
				poOutputter->outputNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentUserMessageReference)
				poOutputter->outputUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentPrivacyIndicator)
				poOutputter->outputPrivacyIndicator(m_nPrivacyIndicator,
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentCallbackNum)
				poOutputter->outputCallbackNum(m_aCallbackNum,
					m_nCallbackNumLen);
			if(this->m_bPresentCallbackNumPresInd)
				poOutputter->outputCallbackNumPresInd(m_nCallbackNumPresInd,
					m_nCallbackNumPresIndLen);
			if(this->m_bPresentCallbackNumAtag)
				poOutputter->outputCallbackNumAtag(m_aCallbackNumAtag,
					m_nCallbackNumAtagLen);
			if(this->m_bPresentSourceSubaddress)
				poOutputter->outputSourceSubaddress(m_aSourceSubaddress,
					m_nSourceSubaddressLen);
			if(this->m_bPresentDestSubaddress)
				poOutputter->outputDestSubaddress(m_aDestSubaddress,
					m_nDestSubaddressLen);
			if(this->m_bPresentUserResponseCode)
				poOutputter->outputUserResponseCode(m_nUserResponseCode,
					m_nUserResponseCodeLen);
			if(this->m_bPresentDisplayTime)
				poOutputter->outputDisplayTime(m_nDisplayTime,
					m_nDisplayTimeLen);
			if(this->m_bPresentSmsSignal)
				poOutputter->outputSmsSignal(m_nSmsSignal,
					m_nSmsSignalLen);
			if(this->m_bPresentMsValidity)
				poOutputter->outputMsValidity(m_nMsValidity,
					m_nMsValidityLen);
			if(this->m_bPresentMsMsgWaitFacilities)
				poOutputter->outputMsMsgWaitFacilities(m_nMsMsgWaitFacilities,
					m_nMsMsgWaitFacilitiesLen);
			if(this->m_bPresentNumberOfMessages)
				poOutputter->outputNumberOfMessages(m_nNumberOfMessages,
					m_nNumberOfMessagesLen);
			if(this->m_bPresentAlertOnMsgDelivery)
				poOutputter->outputAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
					m_nAlertOnMsgDeliveryLen);
			if(this->m_bPresentLanguageIndicator)
				poOutputter->outputLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
			if(this->m_bPresentItsReplyType)
				poOutputter->outputItsReplyType(m_nItsReplyType,
					m_nItsReplyTypeLen);
			if(this->m_bPresentItsSessionInfo)
				poOutputter->outputItsSessionInfo(m_nItsSessionInfo,
					m_nItsSessionInfoLen);
		}

		void SMPPDataSM::validatePacket(SMPPValidator* poValidator){

			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateServiceType(m_sServiceType);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddrNPI(m_nSourceAddrNPI);
			poValidator->validateSourceAddr65(m_sSourceAddr);
			poValidator->validateDestAddrTON(m_nDestAddrTON);
			poValidator->validateDestAddrNPI(m_nDestAddrNPI);
			poValidator->validateDestAddr65(m_sDestAddr);
			poValidator->validateEsmClass(m_nEsmClass);
			poValidator->validateRegisteredDelivery(m_nRegisteredDelivery);
			poValidator->validateDataCoding(m_nDataCoding);


			// Encode optional fields
			if(this->m_bPresentSourcePort)
				poValidator->validateSourcePort(m_nSourcePort,
					m_nSourcePortLen);
			if(this->m_bPresentSourceAddrSubunit)
				poValidator->validateSourceAddrSubunit(m_nSourceAddrSubunit,
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentSourceNetworkType)
				poValidator->validateSourceNetworkType(m_nSourceNetworkType,
					m_nSourceNetworkTypeLen);
			if(this->m_bPresentSourceBearerType)
				poValidator->validateSourceBearerType(m_nSourceBearerType,
					m_nSourceBearerTypeLen);
			if(this->m_bPresentSourceTelematicsId)
				poValidator->validateSourceTelematicsId(m_nSourceTelematicsId,
					m_nSourceTelematicsIdLen);
			if(this->m_bPresentDestinationPort)
				poValidator->validateDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentDestAddrSubunit)
				poValidator->validateDestAddrSubunit(m_nDestAddrSubunit,
					m_nDestAddrSubunitLen);
			if(this->m_bPresentDestNetworkType)
				poValidator->validateDestNetworkType(m_nDestNetworkType,
					m_nDestNetworkTypeLen);
			if(this->m_bPresentDestBearerType)
				poValidator->validateDestBearerType(m_nDestBearerType,
					m_nDestBearerTypeLen);
			if(this->m_bPresentDestTelematicsId)
				poValidator->validateDestTelematicsId(m_nDestTelematicsId,
					m_nDestTelematicsIdLen);
			if(this->m_bPresentSarMsgRefNum)
				poValidator->validateSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poValidator->validateSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poValidator->validateSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentMoreMessagesToSend)
				poValidator->validateMoreMessagesToSend(m_nMoreMessagesToSend,
					m_nMoreMessagesToSendLen);
			if(this->m_bPresentQosTimeToLive)
				poValidator->validateQosTimeToLive(m_nQosTimeToLive,
					m_nQosTimeToLiveLen);
			if(this->m_bPresentPayloadType)
				poValidator->validatePayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poValidator->validateMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
			if(this->m_bPresentSetDpf)
				poValidator->validateSetDpf(m_nSetDpf,
					m_nSetDpfLen);
			if(this->m_bPresentReceiptedMessageId)
				poValidator->validateReceiptedMessageId(m_sReceiptedMessageId,
					m_nReceiptedMessageIdLen);
			if(this->m_bPresentMessageState)
				poValidator->validateMessageStateTLV(m_nMessageState,
					m_nMessageStateLen);
			if(this->m_bPresentNetworkErrorCode)
				poValidator->validateNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentUserMessageReference)
				poValidator->validateUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentPrivacyIndicator)
				poValidator->validatePrivacyIndicator(m_nPrivacyIndicator,
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentCallbackNum)
				poValidator->validateCallbackNum(m_aCallbackNum,
					m_nCallbackNumLen);
			if(this->m_bPresentCallbackNumPresInd)
				poValidator->validateCallbackNumPresInd(m_nCallbackNumPresInd,
					m_nCallbackNumPresIndLen);
			if(this->m_bPresentCallbackNumAtag)
				poValidator->validateCallbackNumAtag(m_aCallbackNumAtag,
					m_nCallbackNumAtagLen);
			if(this->m_bPresentSourceSubaddress)
				poValidator->validateSourceSubaddress(m_aSourceSubaddress,
					m_nSourceSubaddressLen);
			if(this->m_bPresentDestSubaddress)
				poValidator->validateDestSubaddress(m_aDestSubaddress,
					m_nDestSubaddressLen);
			if(this->m_bPresentUserResponseCode)
				poValidator->validateUserResponseCode(m_nUserResponseCode,
					m_nUserResponseCodeLen);
			if(this->m_bPresentDisplayTime)
				poValidator->validateDisplayTime(m_nDisplayTime,
					m_nDisplayTimeLen);
			if(this->m_bPresentSmsSignal)
				poValidator->validateSmsSignal(m_nSmsSignal,
					m_nSmsSignalLen);
			if(this->m_bPresentMsValidity)
				poValidator->validateMsValidity(m_nMsValidity,
					m_nMsValidityLen);
			if(this->m_bPresentMsMsgWaitFacilities)
				poValidator->validateMsMsgWaitFacilities(m_nMsMsgWaitFacilities,
					m_nMsMsgWaitFacilitiesLen);
			if(this->m_bPresentNumberOfMessages)
				poValidator->validateNumberOfMessages(m_nNumberOfMessages,
					m_nNumberOfMessagesLen);
			if(this->m_bPresentAlertOnMsgDelivery)
				poValidator->validateAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
					m_nAlertOnMsgDeliveryLen);
			if(this->m_bPresentLanguageIndicator)
				poValidator->validateLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
			if(this->m_bPresentItsReplyType)
				poValidator->validateItsReplyType(m_nItsReplyType,
					m_nItsReplyTypeLen);
			if(this->m_bPresentItsSessionInfo)
				poValidator->validateItsSessionInfo(m_nItsSessionInfo,
					m_nItsSessionInfoLen);

		}
	}
}
