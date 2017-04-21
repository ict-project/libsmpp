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
#include "SMPPDeliverSM.hpp"


namespace anthill {
	namespace smpp {

		SMPPDeliverSM::SMPPDeliverSM(void):
			SMPPPDU(CommandId::CM_DELIVER_SM),
			m_sServiceType(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_nDestAddrTON(0),
			m_nDestAddrNPI(0),
			m_sDestAddr(""),
			m_nEsmClass(0),
			m_nProtocolId(0),
			m_nPriorityFlag(0),
			m_sScheduleDeliveryTime(""),
			m_sValidityPeriod(""),
			m_nRegisteredDelivery(0),
			m_nReplaceIfPresentFlag(0),
			m_nDataCoding(0),
			m_nSMDefaultMsgId(0),
			m_nSMLength(0),
			m_aShortMessage(),
			m_nUserMessageReference(0),
			m_nSourcePort(0),
			m_nDestinationPort(0),
			m_nSarMsgRefNum(0),
			m_nSarTotalSegments(0),
			m_nSarSegmentSeqnum(0),
			m_nUserResponseCode(0),
			m_nPrivacyIndicator(0),
			m_nPayloadType(0),
			m_aMessagePayload(),
			m_aCallbackNum(),
			m_aSourceSubaddress(),
			m_aDestSubaddress(),
			m_nLanguageIndicator(0),
			m_nItsSessionInfo(0),
			m_oNetworkErrorCode(),
			m_nMessageState(0),
			m_sReceiptedMessageId(""),
			m_bPresentUserMessageReference(false),
			m_bPresentSourcePort(false),
			m_bPresentDestinationPort(false),
			m_bPresentSarMsgRefNum(false),
			m_bPresentSarTotalSegments(false),
			m_bPresentSarSegmentSeqnum(false),
			m_bPresentUserResponseCode(false),
			m_bPresentPrivacyIndicator(false),
			m_bPresentPayloadType(false),
			m_bPresentMessagePayload(false),
			m_bPresentCallbackNum(false),
			m_bPresentSourceSubaddress(false),
			m_bPresentDestSubaddress(false),
			m_bPresentLanguageIndicator(false),
			m_bPresentItsSessionInfo(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentMessageState(false),
			m_bPresentReceiptedMessageId(false),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nSourcePortLen(sizeof(unsigned short)),
			m_nDestinationPortLen(sizeof(unsigned short)),
			m_nSarMsgRefNumLen(sizeof(unsigned short)),
			m_nSarTotalSegmentsLen(sizeof(char)),
			m_nSarSegmentSeqnumLen(sizeof(char)),
			m_nUserResponseCodeLen(sizeof(char)),
			m_nPrivacyIndicatorLen(sizeof(char)),
			m_nPayloadTypeLen(sizeof(char)),
			m_nMessagePayloadLen(m_aMessagePayload.size()),
			m_nCallbackNumLen(m_aCallbackNum.size()),
			m_nSourceSubaddressLen(m_aSourceSubaddress.size()),
			m_nDestSubaddressLen(m_aDestSubaddress.size()),
			m_nLanguageIndicatorLen(sizeof(char)),
			m_nItsSessionInfoLen(sizeof(unsigned short)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nMessageStateLen(sizeof(char)),
			m_nReceiptedMessageIdLen(m_sReceiptedMessageId.size() + 1) {
		}

		SMPPDeliverSM::SMPPDeliverSM(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_DELIVER_SM, nSequenceNumber),
			m_sServiceType(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_nDestAddrTON(0),
			m_nDestAddrNPI(0),
			m_sDestAddr(""),
			m_nEsmClass(0),
			m_nProtocolId(0),
			m_nPriorityFlag(0),
			m_sScheduleDeliveryTime(""),
			m_sValidityPeriod(""),
			m_nRegisteredDelivery(0),
			m_nReplaceIfPresentFlag(0),
			m_nDataCoding(0),
			m_nSMDefaultMsgId(0),
			m_nSMLength(0),
			m_aShortMessage(),
			m_nUserMessageReference(0),
			m_nSourcePort(0),
			m_nDestinationPort(0),
			m_nSarMsgRefNum(0),
			m_nSarTotalSegments(0),
			m_nSarSegmentSeqnum(0),
			m_nUserResponseCode(0),
			m_nPrivacyIndicator(0),
			m_nPayloadType(0),
			m_aMessagePayload(),
			m_aCallbackNum(),
			m_aSourceSubaddress(),
			m_aDestSubaddress(),
			m_nLanguageIndicator(0),
			m_nItsSessionInfo(0),
			m_oNetworkErrorCode(),
			m_nMessageState(0),
			m_sReceiptedMessageId(""),
			m_bPresentUserMessageReference(false),
			m_bPresentSourcePort(false),
			m_bPresentDestinationPort(false),
			m_bPresentSarMsgRefNum(false),
			m_bPresentSarTotalSegments(false),
			m_bPresentSarSegmentSeqnum(false),
			m_bPresentUserResponseCode(false),
			m_bPresentPrivacyIndicator(false),
			m_bPresentPayloadType(false),
			m_bPresentMessagePayload(false),
			m_bPresentCallbackNum(false),
			m_bPresentSourceSubaddress(false),
			m_bPresentDestSubaddress(false),
			m_bPresentLanguageIndicator(false),
			m_bPresentItsSessionInfo(false),
			m_bPresentNetworkErrorCode(false),
			m_bPresentMessageState(false),
			m_bPresentReceiptedMessageId(false),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nSourcePortLen(sizeof(unsigned short)),
			m_nDestinationPortLen(sizeof(unsigned short)),
			m_nSarMsgRefNumLen(sizeof(unsigned short)),
			m_nSarTotalSegmentsLen(sizeof(char)),
			m_nSarSegmentSeqnumLen(sizeof(char)),
			m_nUserResponseCodeLen(sizeof(char)),
			m_nPrivacyIndicatorLen(sizeof(char)),
			m_nPayloadTypeLen(sizeof(char)),
			m_nMessagePayloadLen(m_aMessagePayload.size()),
			m_nCallbackNumLen(m_aCallbackNum.size()),
			m_nSourceSubaddressLen(m_aSourceSubaddress.size()),
			m_nDestSubaddressLen(m_aDestSubaddress.size()),
			m_nLanguageIndicatorLen(sizeof(char)),
			m_nItsSessionInfoLen(sizeof(unsigned short)),
			m_nNetworkErrorCodeLen(sizeof(m_oNetworkErrorCode.getNetworkCode()) + sizeof(m_oNetworkErrorCode.getErrorCode())),
			m_nMessageStateLen(sizeof(char)),
			m_nReceiptedMessageIdLen(m_sReceiptedMessageId.size() + 1){
		}
		SMPPDeliverSM::~SMPPDeliverSM(){
		}

		SMPPPDU* SMPPDeliverSM::cloneSMPPPDU(void){
			return new SMPPDeliverSM();
		}

		void SMPPDeliverSM::fireOnReceived(SMPPSession* poSession){
			SMPPDeliverSM::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPDeliverSM::encodePacket(SMPPEncoder* poEncoder){

			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeServiceType(m_sServiceType);
			poEncoder->encodeSourceAddrTON(m_nSourceAddrTON);
			poEncoder->encodeSourceAddrNPI(m_nSourceAddrTON);
			poEncoder->encodeSourceAddr21(m_sSourceAddr);
			poEncoder->encodeDestAddrTON(m_nDestAddrTON);
			poEncoder->encodeDestAddrNPI(m_nDestAddrNPI);
			poEncoder->encodeDestAddr21(m_sDestAddr);
			poEncoder->encodeEsmClass(m_nEsmClass);
			poEncoder->encodeProtocolId(m_nProtocolId);
			poEncoder->encodePriorityFlag(m_nPriorityFlag);
			poEncoder->encodeScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poEncoder->encodeValidityPeriod(m_sValidityPeriod);
			poEncoder->encodeRegisteredDelivery(m_nRegisteredDelivery);
			poEncoder->encodeReplaceIfPresentFlag(m_nReplaceIfPresentFlag);
			poEncoder->encodeDataCoding(m_nDataCoding);
			poEncoder->encodeSMDefaultMsgId(m_nSMDefaultMsgId);
			poEncoder->encodeSMLength(m_nSMLength);
			poEncoder->encodeShortMessage(m_aShortMessage);


			// Encode optional fields
			if(this->m_bPresentUserMessageReference)
				poEncoder->encodeUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentSourcePort)
				poEncoder->encodeSourcePort(m_nSourcePort,
					m_nSourcePortLen);
			if(this->m_bPresentDestinationPort)
				poEncoder->encodeDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentSarMsgRefNum)
				poEncoder->encodeSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poEncoder->encodeSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poEncoder->encodeSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentUserResponseCode)
				poEncoder->encodeUserResponseCode(m_nUserResponseCode,
					m_nUserResponseCodeLen);
			if(this->m_bPresentPrivacyIndicator)
				poEncoder->encodePrivacyIndicator(m_nPrivacyIndicator,
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentPayloadType)
				poEncoder->encodePayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poEncoder->encodeMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
			if(this->m_bPresentCallbackNum)
				poEncoder->encodeCallbackNum(m_aCallbackNum,
					m_nCallbackNumLen);
			if(this->m_bPresentSourceSubaddress)
				poEncoder->encodeSourceSubaddress(m_aSourceSubaddress,
					m_nSourceSubaddressLen);
			if(this->m_bPresentDestSubaddress)
				poEncoder->encodeDestSubaddress(m_aDestSubaddress,
					m_nDestSubaddressLen);
			if(this->m_bPresentLanguageIndicator)
				poEncoder->encodeLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
			if(this->m_bPresentItsSessionInfo)
				poEncoder->encodeItsSessionInfo(m_nItsSessionInfo,
					m_nItsSessionInfoLen);
			if(this->m_bPresentNetworkErrorCode)
				poEncoder->encodeNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentMessageState)
				poEncoder->encodeMessageStateTLV(m_nMessageState,
					m_nMessageStateLen);
			if(this->m_bPresentReceiptedMessageId)
				poEncoder->encodeReceiptedMessageId(m_sReceiptedMessageId,
					m_nReceiptedMessageIdLen);
		}

		void SMPPDeliverSM::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeServiceType(m_sServiceType, getCommandLength());
			poDecoder->decodeSourceAddrTON(m_nSourceAddrTON, getCommandLength());
			poDecoder->decodeSourceAddrNPI(m_nSourceAddrNPI, getCommandLength());
			poDecoder->decodeSourceAddr21(m_sSourceAddr, getCommandLength());
			poDecoder->decodeDestAddrTON(m_nDestAddrTON, getCommandLength());
			poDecoder->decodeDestAddrNPI(m_nDestAddrNPI, getCommandLength());
			poDecoder->decodeDestAddr21(m_sDestAddr, getCommandLength());
			poDecoder->decodeEsmClass(m_nEsmClass, getCommandLength());
			poDecoder->decodeProtocolId(m_nProtocolId, getCommandLength());
			poDecoder->decodePriorityFlag(m_nPriorityFlag, getCommandLength());
			poDecoder->decodeScheduleDeliveryTime(m_sScheduleDeliveryTime, getCommandLength());
			poDecoder->decodeValidityPeriod(m_sValidityPeriod, getCommandLength());
			poDecoder->decodeRegisteredDelivery(m_nRegisteredDelivery, getCommandLength());
			poDecoder->decodeReplaceIfPresentFlag(m_nReplaceIfPresentFlag, getCommandLength());
			poDecoder->decodeDataCoding(m_nDataCoding, getCommandLength());
			poDecoder->decodeSMDefaultMsgId(m_nSMDefaultMsgId, getCommandLength());
			poDecoder->decodeSMLength(m_nSMLength, getCommandLength());
			poDecoder->decodeShortMessage(m_aShortMessage, m_nSMLength, getCommandLength());


			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_USER_MESSAGE_REFERENCE:{
						poDecoder->decodeUserMessageReference(m_nUserMessageReference,
							m_nUserMessageReferenceLen, this->getCommandLength());
						this->m_bPresentUserMessageReference = true;
						break;
					}
					case OptTags::TAG_SOURCE_PORT:{
						poDecoder->decodeSourcePort(m_nSourcePort,
							m_nSourcePortLen, this->getCommandLength());
						this->m_bPresentSourcePort = true;
						break;
					}
					case OptTags::TAG_DESTINATION_PORT:{
						poDecoder->decodeDestinationPort(m_nDestinationPort,
							m_nDestinationPortLen, this->getCommandLength());
						this->m_bPresentDestinationPort = true;
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
					case OptTags::TAG_USER_RESPONSE_CODE:{
						poDecoder->decodeUserResponseCode(m_nUserResponseCode,
							m_nUserResponseCodeLen, this->getCommandLength());
						this->m_bPresentUserResponseCode = true;
						break;
					}
					case OptTags::TAG_PRIVACY_INDICATOR:{
						poDecoder->decodePrivacyIndicator(m_nPrivacyIndicator,
							m_nPrivacyIndicatorLen, this->getCommandLength());
						this->m_bPresentPrivacyIndicator = true;
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
					case OptTags::TAG_CALLBACK_NUM:{
						poDecoder->decodeCallbackNum(m_aCallbackNum,
							m_nCallbackNumLen, this->getCommandLength());
						this->m_bPresentCallbackNum = true;
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
					case OptTags::TAG_LANGUAGE_INDICATOR:{
						poDecoder->decodeLanguageIndicator(m_nLanguageIndicator,
							m_nLanguageIndicatorLen, this->getCommandLength());
						this->m_bPresentLanguageIndicator = true;
						break;
					}
					case OptTags::TAG_ITS_SESSION_INFO:{
						poDecoder->decodeItsSessionInfo(m_nItsSessionInfo,
							m_nItsSessionInfoLen, this->getCommandLength());
						this->m_bPresentItsSessionInfo = true;
						break;
					}
					case OptTags::TAG_NETWORK_ERROR_CODE:{
						poDecoder->decodeNetworkErrorCode(m_oNetworkErrorCode,
							m_nNetworkErrorCodeLen, this->getCommandLength());
						this->m_bPresentNetworkErrorCode = true;
						break;
					}
					case OptTags::TAG_MESSAGE_STATE:{
						poDecoder->decodeMessageStateTLV(m_nMessageState,
							m_nMessageStateLen, this->getCommandLength());
						this->m_bPresentMessageState = true;
						break;
					}
					case OptTags::TAG_RECEIPTED_MESSAGE_ID:{
						poDecoder->decodeReceiptedMessageId(m_sReceiptedMessageId,
							m_nReceiptedMessageIdLen, this->getCommandLength());
						this->m_bPresentReceiptedMessageId = true;
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

		void SMPPDeliverSM::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputServiceType(m_sServiceType);
			poOutputter->outputSourceAddrTON(m_nSourceAddrTON);
			poOutputter->outputSourceAddrNPI(m_nSourceAddrNPI);
			poOutputter->outputSourceAddr21(m_sSourceAddr);
			poOutputter->outputDestAddrTON(m_nDestAddrTON);
			poOutputter->outputDestAddrNPI(m_nDestAddrNPI);
			poOutputter->outputDestAddr21(m_sDestAddr);
			poOutputter->outputEsmClass(m_nEsmClass);
			poOutputter->outputProtocolId(m_nProtocolId);
			poOutputter->outputPriorityFlag(m_nPriorityFlag);
			poOutputter->outputScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poOutputter->outputValidityPeriod(m_sValidityPeriod);
			poOutputter->outputRegisteredDelivery(m_nRegisteredDelivery);
			poOutputter->outputReplaceIfPresentFlag(m_nReplaceIfPresentFlag);
			poOutputter->outputDataCoding(m_nDataCoding);
			poOutputter->outputSMDefaultMsgId(m_nSMDefaultMsgId);
			poOutputter->outputSMLength(m_nSMLength);
			poOutputter->outputShortMessage(m_aShortMessage);

			// Output optional fields
			if(this->m_bPresentUserMessageReference)
				poOutputter->outputUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentSourcePort)
				poOutputter->outputSourcePort(m_nSourcePort,
					m_nSourcePortLen);
			if(this->m_bPresentDestinationPort)
				poOutputter->outputDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentSarMsgRefNum)
				poOutputter->outputSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poOutputter->outputSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poOutputter->outputSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentUserResponseCode)
				poOutputter->outputUserResponseCode(m_nUserResponseCode,
					m_nUserResponseCodeLen);
			if(this->m_bPresentPrivacyIndicator)
				poOutputter->outputPrivacyIndicator(m_nPrivacyIndicator,
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentPayloadType)
				poOutputter->outputPayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poOutputter->outputMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
			if(this->m_bPresentCallbackNum)
				poOutputter->outputCallbackNum(m_aCallbackNum,
					m_nCallbackNumLen);
			if(this->m_bPresentSourceSubaddress)
				poOutputter->outputSourceSubaddress(m_aSourceSubaddress,
					m_nSourceSubaddressLen);
			if(this->m_bPresentDestSubaddress)
				poOutputter->outputDestSubaddress(m_aDestSubaddress,
					m_nDestSubaddressLen);
			if(this->m_bPresentLanguageIndicator)
				poOutputter->outputLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
			if(this->m_bPresentItsSessionInfo)
				poOutputter->outputItsSessionInfo(m_nItsSessionInfo,
					m_nItsSessionInfoLen);
			if(this->m_bPresentNetworkErrorCode)
				poOutputter->outputNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentMessageState)
				poOutputter->outputMessageStateTLVOpt(m_nMessageState,
					m_nMessageStateLen);
			if(this->m_bPresentReceiptedMessageId)
				poOutputter->outputReceiptedMessageId(m_sReceiptedMessageId,
					m_nReceiptedMessageIdLen);
		}

		void SMPPDeliverSM::validatePacket(SMPPValidator* poValidator){

			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateServiceType(m_sServiceType);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddr65(m_sSourceAddr);
			poValidator->validateDestAddrTON(m_nDestAddrTON);
			poValidator->validateDestAddrNPI(m_nDestAddrNPI);
			poValidator->validateDestAddr65(m_sDestAddr);
			poValidator->validateEsmClass(m_nEsmClass);
			poValidator->validateProtocolId(m_nProtocolId);
			poValidator->validatePriorityFlag(m_nPriorityFlag);
			poValidator->validateScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poValidator->validateValidityPeriod(m_sValidityPeriod);
			poValidator->validateRegisteredDelivery(m_nRegisteredDelivery);
			poValidator->validateReplaceIfPresentFlag(m_nReplaceIfPresentFlag);
			poValidator->validateDataCoding(m_nDataCoding);
			poValidator->validateSMDefaultMsgId(m_nSMDefaultMsgId);
			poValidator->validateSMLength(m_nSMLength);
			poValidator->validateShortMessage(m_aShortMessage, m_nSMLength);


			// Encode optional fields
			if(this->m_bPresentUserMessageReference)
				poValidator->validateUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);
			if(this->m_bPresentSourcePort)
				poValidator->validateSourcePort(m_nSourcePort,
					m_nSourcePortLen);
			if(this->m_bPresentDestinationPort)
				poValidator->validateDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentSarMsgRefNum)
				poValidator->validateSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poValidator->validateSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poValidator->validateSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentUserResponseCode)
				poValidator->validateUserResponseCode(m_nUserResponseCode,
					m_nUserResponseCodeLen);
			if(this->m_bPresentPrivacyIndicator)
				poValidator->validatePrivacyIndicator(m_nPrivacyIndicator,
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentPayloadType)
				poValidator->validatePayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poValidator->validateMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
			if(this->m_bPresentCallbackNum)
				poValidator->validateCallbackNum(m_aCallbackNum,
					m_nCallbackNumLen);
			if(this->m_bPresentSourceSubaddress)
				poValidator->validateSourceSubaddress(m_aSourceSubaddress,
					m_nSourceSubaddressLen);
			if(this->m_bPresentDestSubaddress)
				poValidator->validateDestSubaddress(m_aDestSubaddress,
					m_nDestSubaddressLen);
			if(this->m_bPresentLanguageIndicator)
				poValidator->validateLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
			if(this->m_bPresentItsSessionInfo)
				poValidator->validateItsSessionInfo(m_nItsSessionInfo,
					m_nItsSessionInfoLen);
			if(this->m_bPresentNetworkErrorCode)
				poValidator->validateNetworkErrorCode(m_oNetworkErrorCode,
					m_nNetworkErrorCodeLen);
			if(this->m_bPresentMessageState)
				poValidator->validateMessageStateTLV(m_nMessageState,
					m_nMessageStateLen);
			if(this->m_bPresentReceiptedMessageId)
				poValidator->validateReceiptedMessageId(m_sReceiptedMessageId,
					m_nReceiptedMessageIdLen);

			// Validate complex rules
			if(this->m_bPresentMessagePayload)
				poValidator->validateShortMessagePayload(m_aShortMessage, m_aMessagePayload);
		}

	}
}
