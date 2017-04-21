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
#include "SMPPSubmitMulti.hpp"


namespace anthill {
	namespace smpp {

		SMPPSubmitMulti::SMPPSubmitMulti(void):
			SMPPPDU(CommandId::CM_SUBMIT_MULTI),
			m_sServiceType(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_nNumberOfDest(0),
			m_aDestAddresses(),
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
			m_nSourceAddrSubunit(0),
			m_nDestinationPort(0),
			m_nDestAddrSubunit(0),
			m_nSarMsgRefNum(0),
			m_nSarTotalSegments(0),
			m_nSarSegmentSeqnum(0),
			m_nPayloadType(0),
			m_aMessagePayload(),
			m_nPrivacyIndicator(0),
			m_aCallbackNum(),
			m_nCallbackNumPresInd(0),
			m_aCallbackNumAtag(),
			m_aSourceSubaddress(),
			m_aDestSubaddress(),
			m_nDisplayTime(0),
			m_nSmsSignal(0),
			m_nMsValidity(0),
			m_nMsMsgWaitFacilities(0),
			m_nAlertOnMsgDelivery(0),
			m_nLanguageIndicator(0),
			m_bPresentUserMessageReference(false),
			m_bPresentSourcePort(false),
			m_bPresentSourceAddrSubunit(false),
			m_bPresentDestinationPort(false),
			m_bPresentDestAddrSubunit(false),
			m_bPresentSarMsgRefNum(false),
			m_bPresentSarTotalSegments(false),
			m_bPresentSarSegmentSeqnum(false),
			m_bPresentPayloadType(false),
			m_bPresentMessagePayload(false),
			m_bPresentPrivacyIndicator(false),
			m_bPresentCallbackNum(false),
			m_bPresentCallbackNumPresInd(false),
			m_bPresentCallbackNumAtag(false),
			m_bPresentSourceSubaddress(false),
			m_bPresentDestSubaddress(false),
			m_bPresentDisplayTime(false),
			m_bPresentSmsSignal(false),
			m_bPresentMsValidity(false),
			m_bPresentMsMsgWaitFacilities(false),
			m_bPresentAlertOnMsgDelivery(false),
			m_bPresentLanguageIndicator(false),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nSourcePortLen(sizeof(unsigned short)),
			m_nSourceAddrSubunitLen(sizeof(char)),
			m_nDestinationPortLen(sizeof(unsigned short)),
			m_nDestAddrSubunitLen(sizeof(char)),
			m_nSarMsgRefNumLen(sizeof(unsigned short)),
			m_nSarTotalSegmentsLen(sizeof(char)),
			m_nSarSegmentSeqnumLen(sizeof(char)),
			m_nPayloadTypeLen(sizeof(char)),
			m_nMessagePayloadLen(m_aMessagePayload.size()),
			m_nPrivacyIndicatorLen(sizeof(char)),
			m_nCallbackNumLen(m_aCallbackNum.size()),
			m_nCallbackNumPresIndLen(sizeof(char)),
			m_nCallbackNumAtagLen(m_aCallbackNumAtag.size()),
			m_nSourceSubaddressLen(m_aSourceSubaddress.size()),
			m_nDestSubaddressLen(m_aDestSubaddress.size()),
			m_nDisplayTimeLen(sizeof(char)),
			m_nSmsSignalLen(sizeof(unsigned short)),
			m_nMsValidityLen(sizeof(char)),
			m_nMsMsgWaitFacilitiesLen(sizeof(char)),
			m_nAlertOnMsgDeliveryLen(sizeof(char)),
			m_nLanguageIndicatorLen(sizeof(char)){
		}

		SMPPSubmitMulti::SMPPSubmitMulti(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_SUBMIT_MULTI, nSequenceNumber),
			m_sServiceType(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_nNumberOfDest(0),
			m_aDestAddresses(),
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
			m_nSourceAddrSubunit(0),
			m_nDestinationPort(0),
			m_nDestAddrSubunit(0),
			m_nSarMsgRefNum(0),
			m_nSarTotalSegments(0),
			m_nSarSegmentSeqnum(0),
			m_nPayloadType(0),
			m_aMessagePayload(),
			m_nPrivacyIndicator(0),
			m_aCallbackNum(),
			m_nCallbackNumPresInd(0),
			m_aCallbackNumAtag(),
			m_aSourceSubaddress(),
			m_aDestSubaddress(),
			m_nDisplayTime(0),
			m_nSmsSignal(0),
			m_nMsValidity(0),
			m_nMsMsgWaitFacilities(0),
			m_nAlertOnMsgDelivery(0),
			m_nLanguageIndicator(0),
			m_bPresentUserMessageReference(false),
			m_bPresentSourcePort(false),
			m_bPresentSourceAddrSubunit(false),
			m_bPresentDestinationPort(false),
			m_bPresentDestAddrSubunit(false),
			m_bPresentSarMsgRefNum(false),
			m_bPresentSarTotalSegments(false),
			m_bPresentSarSegmentSeqnum(false),
			m_bPresentPayloadType(false),
			m_bPresentMessagePayload(false),
			m_bPresentPrivacyIndicator(false),
			m_bPresentCallbackNum(false),
			m_bPresentCallbackNumPresInd(false),
			m_bPresentCallbackNumAtag(false),
			m_bPresentSourceSubaddress(false),
			m_bPresentDestSubaddress(false),
			m_bPresentDisplayTime(false),
			m_bPresentSmsSignal(false),
			m_bPresentMsValidity(false),
			m_bPresentMsMsgWaitFacilities(false),
			m_bPresentAlertOnMsgDelivery(false),
			m_bPresentLanguageIndicator(false),
			m_nUserMessageReferenceLen(sizeof(unsigned short)),
			m_nSourcePortLen(sizeof(unsigned short)),
			m_nSourceAddrSubunitLen(sizeof(char)),
			m_nDestinationPortLen(sizeof(unsigned short)),
			m_nDestAddrSubunitLen(sizeof(char)),
			m_nSarMsgRefNumLen(sizeof(unsigned short)),
			m_nSarTotalSegmentsLen(sizeof(char)),
			m_nSarSegmentSeqnumLen(sizeof(char)),
			m_nPayloadTypeLen(sizeof(char)),
			m_nMessagePayloadLen(m_aMessagePayload.size()),
			m_nPrivacyIndicatorLen(sizeof(char)),
			m_nCallbackNumLen(m_aCallbackNum.size()),
			m_nCallbackNumPresIndLen(sizeof(char)),
			m_nCallbackNumAtagLen(m_aCallbackNumAtag.size()),
			m_nSourceSubaddressLen(m_aSourceSubaddress.size()),
			m_nDestSubaddressLen(m_aDestSubaddress.size()),
			m_nDisplayTimeLen(sizeof(char)),
			m_nSmsSignalLen(sizeof(unsigned short)),
			m_nMsValidityLen(sizeof(char)),
			m_nMsMsgWaitFacilitiesLen(sizeof(char)),
			m_nAlertOnMsgDeliveryLen(sizeof(char)),
			m_nLanguageIndicatorLen(sizeof(char)){

		}

		SMPPSubmitMulti::~SMPPSubmitMulti(){
		}

		SMPPPDU* SMPPSubmitMulti::cloneSMPPPDU(void){
			return new SMPPSubmitMulti();
		}

		void SMPPSubmitMulti::fireOnReceived(SMPPSession* poSession){
			SMPPSubmitMulti::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPSubmitMulti::encodePacket(SMPPEncoder* poEncoder){
			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeServiceType(m_sServiceType);
			poEncoder->encodeSourceAddrTON(m_nSourceAddrTON);
			poEncoder->encodeSourceAddrNPI(m_nSourceAddrNPI);
			poEncoder->encodeSourceAddr21(m_sSourceAddr);
			poEncoder->encodeNumberOfDest(m_nNumberOfDest);
			poEncoder->encodeDestAddresses(m_aDestAddresses);
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
			if(this->m_bPresentSourceAddrSubunit)
				poEncoder->encodeSourceAddrSubunit(m_nSourceAddrSubunit,
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentDestinationPort)
				poEncoder->encodeDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentDestAddrSubunit)
				poEncoder->encodeDestAddrSubunit(m_nDestAddrSubunit,
					m_nDestAddrSubunitLen);
			if(this->m_bPresentSarMsgRefNum)
				poEncoder->encodeSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poEncoder->encodeSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poEncoder->encodeSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentPayloadType)
				poEncoder->encodePayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poEncoder->encodeMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
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
			if(this->m_bPresentAlertOnMsgDelivery)
				poEncoder->encodeAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
					m_nAlertOnMsgDeliveryLen);
			if(this->m_bPresentLanguageIndicator)
				poEncoder->encodeLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
		}

		void SMPPSubmitMulti::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeServiceType(m_sServiceType, getCommandLength());
			poDecoder->decodeSourceAddrTON(m_nSourceAddrTON, getCommandLength());
			poDecoder->decodeSourceAddrNPI(m_nSourceAddrNPI, getCommandLength());
			poDecoder->decodeSourceAddr21(m_sSourceAddr, getCommandLength());
			poDecoder->decodeNumberOfDest(m_nNumberOfDest, getCommandLength());
			poDecoder->decodeDestAddresses(m_aDestAddresses, m_nNumberOfDest, getCommandLength());
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
					case OptTags::TAG_SOURCE_ADDR_SUBUNIT:{
						poDecoder->decodeSourceAddrSubunit(m_nSourceAddrSubunit,
							m_nSourceAddrSubunitLen, this->getCommandLength());
						this->m_bPresentSourceAddrSubunit = true;
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
					default:{
						// Report about error
						std::string sMessage(poDecoder->getTLVError());
						throw std::logic_error(Errors::UNKNOWN_TAG_MSG + sMessage);
						break;
					}
				}
			}
		}

		void SMPPSubmitMulti::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputServiceType(m_sServiceType);
			poOutputter->outputSourceAddrTON(m_nSourceAddrTON);
			poOutputter->outputSourceAddrNPI(m_nSourceAddrNPI);
			poOutputter->outputSourceAddr21(m_sSourceAddr);
			poOutputter->outputNumberOfDest(m_nNumberOfDest);
			poOutputter->outputDestAddresses(m_aDestAddresses);
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
			if(this->m_bPresentSourceAddrSubunit)
				poOutputter->outputSourceAddrSubunit(m_nSourceAddrSubunit,
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentDestinationPort)
				poOutputter->outputDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentDestAddrSubunit)
				poOutputter->outputDestAddrSubunit(m_nDestAddrSubunit,
					m_nDestAddrSubunitLen);
			if(this->m_bPresentSarMsgRefNum)
				poOutputter->outputSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poOutputter->outputSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poOutputter->outputSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentPayloadType)
				poOutputter->outputPayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poOutputter->outputMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
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
			if(this->m_bPresentAlertOnMsgDelivery)
				poOutputter->outputAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
					m_nAlertOnMsgDeliveryLen);
			if(this->m_bPresentLanguageIndicator)
				poOutputter->outputLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
		}

		void SMPPSubmitMulti::validatePacket(SMPPValidator* poValidator){
			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateServiceType(m_sServiceType);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddrNPI(m_nSourceAddrNPI);
			poValidator->validateSourceAddr21(m_sSourceAddr);
			poValidator->validateNumberOfDest(m_nNumberOfDest);
			poValidator->validateDestAddresses(m_aDestAddresses, m_nNumberOfDest);
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
			if(this->m_bPresentSourceAddrSubunit)
				poValidator->validateSourceAddrSubunit(m_nSourceAddrSubunit,
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentDestinationPort)
				poValidator->validateDestinationPort(m_nDestinationPort,
					m_nDestinationPortLen);
			if(this->m_bPresentDestAddrSubunit)
				poValidator->validateDestAddrSubunit(m_nDestAddrSubunit,
					m_nDestAddrSubunitLen);
			if(this->m_bPresentSarMsgRefNum)
				poValidator->validateSarMsgRefNum(m_nSarMsgRefNum,
					m_nSarMsgRefNumLen);
			if(this->m_bPresentSarTotalSegments)
				poValidator->validateSarTotalSegments(m_nSarTotalSegments,
					m_nSarTotalSegmentsLen);
			if(this->m_bPresentSarSegmentSeqnum)
				poValidator->validateSarSegmentSeqnum(m_nSarSegmentSeqnum,
					m_nSarSegmentSeqnumLen);
			if(this->m_bPresentPayloadType)
				poValidator->validatePayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentMessagePayload)
				poValidator->validateMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
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
			if(this->m_bPresentAlertOnMsgDelivery)
				poValidator->validateAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
					m_nAlertOnMsgDeliveryLen);
			if(this->m_bPresentLanguageIndicator)
				poValidator->validateLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);

			// Validate complex rules
			if(this->m_bPresentMessagePayload)
				poValidator->validateShortMessagePayload(m_aShortMessage, m_aMessagePayload);

		}

	}
}
