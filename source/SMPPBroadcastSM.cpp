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
#include "SMPPBroadcastSM.hpp"


namespace anthill {
	namespace smpp {

		SMPPBroadcastSM::SMPPBroadcastSM(void):
			SMPPPDU(CommandId::CM_BROADCAST_SM),
			m_sServiceType(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_sMessageId(""),
			m_nPriorityFlag(0),
			m_sScheduleDeliveryTime(""),
			m_sValidityPeriod(""),
			m_nReplaceIfPresentFlag(0),
			m_nDataCoding(0),
			m_nSMDefaultMsgId(0),
			m_nAlertOnMsgDelivery(0),
			m_nBroadcastChannelIndicator(0),
			m_aBroadcastContentTypeInfo(),
			m_nBroadcastMessageClass(0),
			m_aBroadcastServiceGroup(),
			m_aCallbackNum(0),
			m_aCallbackNumAtag(),
			m_nCallbackNumPresInd(0),
			m_nDestAddrSubunit(0),
			m_aDestSubaddress(),
			m_nDestPort(0),
			m_nDisplayTime(0),
			m_nLanguageIndicator(0),
			m_aMessagePayload(),
			m_nMsValidity(0),
			m_nPayloadType(0),
			m_nPrivacyIndicator(0),
			m_nSmsSignal(0),
			m_nSourceAddrSubunit(0),
			m_nSourcePort(0),
			m_aSourceSubaddress(),
			m_nUserMessageReference(0),
			m_bPresentBroadcastAreaIdentifier(false),
			m_bPresentBroadcastContentType(false),
			m_bPresentBroadcastRepNum(false),
			m_bPresentBroadcastFrequencyInterval(false),
			m_bPresentAlertOnMsgDelivery(false),
			m_bPresentBroadcastChannelIndicator(false),
			m_bPresentBroadcastContentTypeInfo(false),
			m_bPresentBroadcastMessageClass(false),
			m_bPresentBroadcastServiceGroup(false),
			m_bPresentCallbackNum(false),
			m_bPresentCallbackNumAtag(false),
			m_bPresentCallbackNumPresInd(false),
			m_bPresentDestAddrSubunit(false),
			m_bPresentDestSubaddress(false),
			m_bPresentDestPort(false),
			m_bPresentDisplayTime(false),
			m_bPresentLanguageIndicator(false),
			m_bPresentMessagePayload(false),
			m_bPresentMsValidity(false),
			m_bPresentPayloadType(false),
			m_bPresentPrivacyIndicator(false),
			m_bPresentSmsSignal(false),
			m_bPresentSourceAddrSubunit(false),
			m_bPresentSourcePort(false),
			m_bPresentSourceSubaddress(false),
			m_bPresentUserMessageReference(false),
			m_aBroadcastAreaIdentifierLen(),
			m_nBroadcastContentTypeLen(sizeof(unsigned char)),
			m_nBroadcastRepNumLen(sizeof(unsigned short)),
			m_nBroadcastFrequencyIntervalLen(0),
			m_nAlertOnMsgDeliveryLen(sizeof(char)),
			m_nBroadcastChannelIndicatorLen(sizeof(char)),
			m_nBroadcastContentTypeInfoLen(m_aBroadcastContentTypeInfo.size()),
			m_nBroadcastMessageClassLen(sizeof(char)),
			m_nBroadcastServiceGroupLen(m_aBroadcastServiceGroup.size()),
			m_nCallbackNumLen(m_aCallbackNum.size()),
			m_nCallbackNumAtagLen(m_aCallbackNumAtag.size()),
			m_nCallbackNumPresIndLen(sizeof(char)),
			m_nDestAddrSubunitLen(sizeof(char)),
			m_nDestSubaddressLen(m_aDestSubaddress.size()),
			m_nDestPortLen(sizeof(unsigned short)),
			m_nDisplayTimeLen(sizeof(char)),
			m_nLanguageIndicatorLen(sizeof(char)),
			m_nMessagePayloadLen(m_aMessagePayload.size()),
			m_nMsValidityLen(sizeof(char)),
			m_nPayloadTypeLen(sizeof(char)),
			m_nPrivacyIndicatorLen(sizeof(char)),
			m_nSmsSignalLen(sizeof(unsigned short)),
			m_nSourceAddrSubunitLen(sizeof(char)),
			m_nSourcePortLen(sizeof(unsigned short)),
			m_nSourceSubaddressLen(m_aSourceSubaddress.size()),
			m_nUserMessageReferenceLen(sizeof(unsigned short)){

		}

		SMPPBroadcastSM::SMPPBroadcastSM(const unsigned nSequenceNumber):
			SMPPPDU(CommandId::CM_BROADCAST_SM, nSequenceNumber),
			m_sServiceType(""),
			m_nSourceAddrTON(0),
			m_nSourceAddrNPI(0),
			m_sSourceAddr(""),
			m_sMessageId(""),
			m_nPriorityFlag(0),
			m_sScheduleDeliveryTime(""),
			m_sValidityPeriod(""),
			m_nReplaceIfPresentFlag(0),
			m_nDataCoding(0),
			m_nSMDefaultMsgId(0),
			m_nAlertOnMsgDelivery(0),
			m_nBroadcastChannelIndicator(0),
			m_aBroadcastContentTypeInfo(),
			m_nBroadcastMessageClass(0),
			m_aBroadcastServiceGroup(),
			m_aCallbackNum(0),
			m_aCallbackNumAtag(),
			m_nCallbackNumPresInd(0),
			m_nDestAddrSubunit(0),
			m_aDestSubaddress(),
			m_nDestPort(0),
			m_nDisplayTime(0),
			m_nLanguageIndicator(0),
			m_aMessagePayload(),
			m_nMsValidity(0),
			m_nPayloadType(0),
			m_nPrivacyIndicator(0),
			m_nSmsSignal(0),
			m_nSourceAddrSubunit(0),
			m_nSourcePort(0),
			m_aSourceSubaddress(),
			m_nUserMessageReference(0),
			m_bPresentBroadcastAreaIdentifier(false),
			m_bPresentBroadcastContentType(false),
			m_bPresentBroadcastRepNum(false),
			m_bPresentBroadcastFrequencyInterval(false),
			m_bPresentAlertOnMsgDelivery(false),
			m_bPresentBroadcastChannelIndicator(false),
			m_bPresentBroadcastContentTypeInfo(false),
			m_bPresentBroadcastMessageClass(false),
			m_bPresentBroadcastServiceGroup(false),
			m_bPresentCallbackNum(false),
			m_bPresentCallbackNumAtag(false),
			m_bPresentCallbackNumPresInd(false),
			m_bPresentDestAddrSubunit(false),
			m_bPresentDestSubaddress(false),
			m_bPresentDestPort(false),
			m_bPresentDisplayTime(false),
			m_bPresentLanguageIndicator(false),
			m_bPresentMessagePayload(false),
			m_bPresentMsValidity(false),
			m_bPresentPayloadType(false),
			m_bPresentPrivacyIndicator(false),
			m_bPresentSmsSignal(false),
			m_bPresentSourceAddrSubunit(false),
			m_bPresentSourcePort(false),
			m_bPresentSourceSubaddress(false),
			m_bPresentUserMessageReference(false),
			m_aBroadcastAreaIdentifierLen(),
			m_nBroadcastContentTypeLen(sizeof(unsigned char)),
			m_nBroadcastRepNumLen(sizeof(unsigned short)),
			m_nBroadcastFrequencyIntervalLen(0),
			m_nAlertOnMsgDeliveryLen(sizeof(char)),
			m_nBroadcastChannelIndicatorLen(sizeof(char)),
			m_nBroadcastContentTypeInfoLen(m_aBroadcastContentTypeInfo.size()),
			m_nBroadcastMessageClassLen(sizeof(char)),
			m_nBroadcastServiceGroupLen(m_aBroadcastServiceGroup.size()),
			m_nCallbackNumLen(m_aCallbackNum.size()),
			m_nCallbackNumAtagLen(m_aCallbackNumAtag.size()),
			m_nCallbackNumPresIndLen(sizeof(char)),
			m_nDestAddrSubunitLen(sizeof(char)),
			m_nDestSubaddressLen(m_aDestSubaddress.size()),
			m_nDestPortLen(sizeof(unsigned short)),
			m_nDisplayTimeLen(sizeof(char)),
			m_nLanguageIndicatorLen(sizeof(char)),
			m_nMessagePayloadLen(m_aMessagePayload.size()),
			m_nMsValidityLen(sizeof(char)),
			m_nPayloadTypeLen(sizeof(char)),
			m_nPrivacyIndicatorLen(sizeof(char)),
			m_nSmsSignalLen(sizeof(unsigned short)),
			m_nSourceAddrSubunitLen(sizeof(char)),
			m_nSourcePortLen(sizeof(unsigned short)),
			m_nSourceSubaddressLen(m_aSourceSubaddress.size()),
			m_nUserMessageReferenceLen(sizeof(unsigned short)){

		}

		SMPPBroadcastSM::~SMPPBroadcastSM(){
		}

		SMPPPDU* SMPPBroadcastSM::cloneSMPPPDU(void){
			return new SMPPBroadcastSM();
		}

		void SMPPBroadcastSM::fireOnReceived(SMPPSession* poSession){
			SMPPBroadcastSM::SharedPtr poPtr(this);
			// poSession->fireOnReceived(this->shared_from_this());
		}

		void SMPPBroadcastSM::encodePacket(SMPPEncoder* poEncoder){

			// Encode header and mandatory fields
			poEncoder->encodeHeader(m_oHeader);
			poEncoder->encodeServiceType(m_sServiceType);
			poEncoder->encodeSourceAddrTON(m_nSourceAddrTON);
			poEncoder->encodeSourceAddrNPI(m_nSourceAddrNPI);
			poEncoder->encodeSourceAddr21(m_sSourceAddr);
			poEncoder->encodeMessageId(m_sMessageId);
			poEncoder->encodePriorityFlag(m_nPriorityFlag);
			poEncoder->encodeScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poEncoder->encodeValidityPeriod(m_sValidityPeriod);
			poEncoder->encodeReplaceIfPresentFlag(m_nReplaceIfPresentFlag);
			poEncoder->encodeDataCoding(m_nDataCoding);
			poEncoder->encodeSMDefaultMsgId(m_nSMDefaultMsgId);

			// Encode mandatory fields as TLV structures
			poEncoder->encodeBroadcastAreaIdentifier(m_aBroadcastAreaIdentifier,
				m_aBroadcastAreaIdentifierLen);
			poEncoder->encodeBroadcastContentType(m_aBroadcastContentType,
				m_nBroadcastContentTypeLen);
			poEncoder->encodeBroadcastRepNum(m_nBroadcastRepNum,
				m_nBroadcastRepNumLen);
			poEncoder->encodeBroadcastFrequencyInterval(m_aBroadcastFrequencyInterval,
				m_nBroadcastFrequencyIntervalLen);

			// Encode optional fields
			if(this->m_bPresentAlertOnMsgDelivery)
				poEncoder->encodeAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
					m_nAlertOnMsgDelivery);
			if(this->m_bPresentBroadcastChannelIndicator)
				poEncoder->encodeBroadcastChannelIndicator(m_nBroadcastChannelIndicator,
					m_nBroadcastChannelIndicator);
			if(this->m_bPresentBroadcastContentTypeInfo)
				poEncoder->encodeBroadcastContentTypeInfo(m_aBroadcastContentTypeInfo,
					m_nBroadcastContentTypeInfoLen);
			if(this->m_bPresentBroadcastMessageClass)
				poEncoder->encodeBroadcastMessageClass(m_nBroadcastMessageClass,
					m_nBroadcastMessageClassLen);
			if(this->m_bPresentBroadcastServiceGroup)
				poEncoder->encodeBroadcastServiceGroup(m_aBroadcastServiceGroup,
					m_nBroadcastServiceGroupLen);
			if(this->m_bPresentCallbackNum)
				poEncoder->encodeCallbackNum(m_aCallbackNum,
					m_nCallbackNumLen);
			if(this->m_bPresentCallbackNumAtag)
				poEncoder->encodeCallbackNumAtag(m_aCallbackNumAtag,
					m_nCallbackNumAtagLen);
			if(this->m_bPresentCallbackNumPresInd)
				poEncoder->encodeCallbackNumPresInd(m_nCallbackNumPresInd,
					m_nCallbackNumPresIndLen);
			if(this->m_bPresentDestAddrSubunit)
				poEncoder->encodeDestAddrSubunit(m_nDestAddrSubunit,
					m_nDestAddrSubunitLen);
			if(this->m_bPresentDestSubaddress)
				poEncoder->encodeDestSubaddress(m_aDestSubaddress,
					m_nDestSubaddressLen);
			if(this->m_bPresentDestPort)
				poEncoder->encodeDestinationPort(m_nDestPort,
					m_nDestPortLen);
			if(this->m_bPresentDisplayTime)
				poEncoder->encodeDisplayTime(m_nDisplayTime,
					m_nDisplayTimeLen);
			if(this->m_bPresentLanguageIndicator)
				poEncoder->encodeLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
			if(this->m_bPresentMessagePayload)
				poEncoder->encodeMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
			if(this->m_bPresentMsValidity)
				poEncoder->encodeMsValidity(m_nMsValidity,
					m_nMsValidityLen);
			if(this->m_bPresentPayloadType)
				poEncoder->encodePayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentPrivacyIndicator)
				poEncoder->encodePrivacyIndicator(m_nPrivacyIndicator,
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentSmsSignal)
				poEncoder->encodeSmsSignal(m_nSmsSignal,
					m_nSmsSignalLen);
			if(this->m_bPresentSourceAddrSubunit)
				poEncoder->encodeSourceAddrSubunit(m_nSourceAddrSubunit,
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentSourcePort)
				poEncoder->encodeSourcePort(m_nSourcePort,
					m_nSourcePortLen);
			if(this->m_bPresentSourceSubaddress)
				poEncoder->encodeSourceSubaddress(m_aSourceSubaddress,
					m_nSourceSubaddressLen);
			if(this->m_bPresentUserMessageReference)
				poEncoder->encodeUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);

		}

		void SMPPBroadcastSM::decodePacket(SMPPDecoder* poDecoder){
			// Decode header and mandatory fields
			poDecoder->decodeHeader(m_oHeader);
			poDecoder->decodeServiceType(m_sServiceType, getCommandLength());
			poDecoder->decodeSourceAddrTON(m_nSourceAddrTON, getCommandLength());
			poDecoder->decodeSourceAddrNPI(m_nSourceAddrNPI, getCommandLength());
			poDecoder->decodeSourceAddr21(m_sSourceAddr, getCommandLength());
			poDecoder->decodeMessageId(m_sMessageId, getCommandLength());
			poDecoder->decodePriorityFlag(m_nPriorityFlag, getCommandLength());
			poDecoder->decodeScheduleDeliveryTime(m_sScheduleDeliveryTime, getCommandLength());
			poDecoder->decodeValidityPeriod(m_sValidityPeriod, getCommandLength());
			poDecoder->decodeReplaceIfPresentFlag(m_nReplaceIfPresentFlag, getCommandLength());
			poDecoder->decodeDataCoding(m_nDataCoding, getCommandLength());
			poDecoder->decodeSMDefaultMsgId(m_nSMDefaultMsgId, getCommandLength());

			// Decode mandatory fields as TLV structures
			while (poDecoder->hasTLVs() && poDecoder->getTLVCode() == OptTags::TAG_BROADCAST_AREA_IDENTIFIER){
				poDecoder->decodeBroadcastAreaIdentifier(m_aBroadcastAreaIdentifier, 
					m_aBroadcastAreaIdentifierLen, this->getCommandLength());
				this->m_bPresentBroadcastAreaIdentifier = true;

			}
			if(poDecoder->hasTLVs() && poDecoder->getTLVCode() == OptTags::TAG_BROADCAST_CONTENT_TYPE){
				poDecoder->decodeBroadcastContentType(m_aBroadcastContentType,
					m_nBroadcastContentTypeLen, this->getCommandLength());
				this->m_bPresentBroadcastContentType = true;
			}
			if(poDecoder->hasTLVs() && poDecoder->getTLVCode() == OptTags::TAG_BROADCAST_REP_NUM){
				poDecoder->decodeBroadcastRepNum(m_nBroadcastRepNum,
					m_nBroadcastRepNumLen, this->getCommandLength());
				this->m_bPresentBroadcastRepNum = true;
			}
			if(poDecoder->hasTLVs() && poDecoder->getTLVCode() == OptTags::TAG_BROADCAST_FREQUENCY_INTERVAL){
				poDecoder->decodeBroadcastFrequencyInterval(m_aBroadcastFrequencyInterval,
					m_nBroadcastFrequencyIntervalLen, this->getCommandLength());
				this->m_bPresentBroadcastFrequencyInterval = true;
			}

			// Decode optional fields
			while(poDecoder->hasTLVs()){
				switch(poDecoder->getTLVCode()){
					case OptTags::TAG_ALERT_ON_MESSAGE_DELIVERY:{
						poDecoder->decodeAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
							m_nAlertOnMsgDeliveryLen, this->getCommandLength());
						this->m_bPresentAlertOnMsgDelivery = true;
						break;
					}
					case OptTags::TAG_BROADCAST_CHANNEL_INDICATOR:{ 
						poDecoder->decodeBroadcastChannelIndicator(m_nBroadcastChannelIndicator,
							m_nBroadcastChannelIndicatorLen, this->getCommandLength());
						this->m_bPresentBroadcastChannelIndicator= true;
						break;
					}
					case OptTags::TAG_BROADCAST_CONTENT_TYPE_INFO:{ 
						poDecoder->decodeBroadcastContentTypeInfo(m_aBroadcastContentTypeInfo,
							m_nBroadcastContentTypeInfoLen, this->getCommandLength());
						this->m_bPresentBroadcastContentTypeInfo= true;
						break;
					}
					case OptTags::TAG_BROADCAST_MESSAGE_CLASS:{ 
						poDecoder->decodeBroadcastMessageClass(m_nBroadcastMessageClass,
							m_nBroadcastMessageClassLen, this->getCommandLength());
						this->m_bPresentBroadcastMessageClass = true;
						break;
					}
					case OptTags::TAG_BROADCAST_SERVICE_GROUP:{ 
						poDecoder->decodeBroadcastServiceGroup(m_aBroadcastServiceGroup,
							m_nBroadcastServiceGroupLen, this->getCommandLength());
						this->m_bPresentBroadcastServiceGroup= true;
						break;
					}
					case OptTags::TAG_CALLBACK_NUM:{ 
						poDecoder->decodeCallbackNum(m_aCallbackNum,
							m_nCallbackNumLen, this->getCommandLength());
						this->m_bPresentCallbackNum= true;
						break;
					}
					case OptTags::TAG_CALLBACK_NUM_ATAG:{ 
						poDecoder->decodeCallbackNumAtag(m_aCallbackNumAtag,
							m_nCallbackNumAtagLen, this->getCommandLength());
						this->m_bPresentCallbackNumAtag = true;
						break;
					}
					case OptTags::TAG_CALLBACK_NUM_PRES_IND:{ 
						poDecoder->decodeCallbackNumPresInd(m_nCallbackNumPresInd,
							m_nCallbackNumPresIndLen, this->getCommandLength());
						this->m_bPresentCallbackNumPresInd = true;
						break;
					}
					case OptTags::TAG_DEST_ADDR_SUBUNIT:{ 
						poDecoder->decodeDestAddrSubunit(m_nDestAddrSubunit,
							m_nDestAddrSubunitLen, this->getCommandLength());
						this->m_bPresentDestAddrSubunit = true;
						break;
					}
					case OptTags::TAG_DEST_SUBADDRESS:{ 
						poDecoder->decodeDestSubaddress(m_aDestSubaddress,
							m_nDestSubaddressLen, this->getCommandLength());
						this->m_bPresentDestSubaddress= true;
						break;
					}
					case OptTags::TAG_DESTINATION_PORT:{ 
						poDecoder->decodeDestinationPort(m_nDestPort,
							m_nDestPortLen, this->getCommandLength());
						this->m_bPresentDestPort= true;
						break;
					}
					case OptTags::TAG_DISPLAY_TIME:{ 
						poDecoder->decodeDisplayTime(m_nDisplayTime,
							m_nDisplayTimeLen, this->getCommandLength());
						this->m_bPresentDisplayTime = true;
						break;
					}
					case OptTags::TAG_LANGUAGE_INDICATOR:{ 
						poDecoder->decodeLanguageIndicator(m_nLanguageIndicator,
							m_nLanguageIndicatorLen, this->getCommandLength());
						this->m_bPresentLanguageIndicator = true;
						break;
					}
					case OptTags::TAG_MESSAGE_PAYLOAD:{ 
						poDecoder->decodeMessagePayload(m_aMessagePayload,
							m_nMessagePayloadLen, this->getCommandLength());
						this->m_bPresentMessagePayload = true;
						break;
					}
					case OptTags::TAG_MS_VALIDITY:{ 
						poDecoder->decodeMsValidity(m_nMsValidity,
							m_nMsValidityLen, this->getCommandLength());
						this->m_bPresentMsValidity = true;
						break;
					}
					case OptTags::TAG_PAYLOAD_TYPE:{ 
						poDecoder->decodePayloadType(m_nPayloadType,
							m_nPayloadTypeLen, this->getCommandLength());
						this->m_bPresentPayloadType = true;
						break;
					}
					case OptTags::TAG_PRIVACY_INDICATOR:{ 
						poDecoder->decodePrivacyIndicator(m_nPrivacyIndicator,
							m_nPrivacyIndicatorLen, this->getCommandLength());
						this->m_bPresentPrivacyIndicator= true;
						break;
					}
					case OptTags::TAG_SMS_SIGNAL:{ 
						poDecoder->decodeSmsSignal(m_nSmsSignal,
							m_nSmsSignalLen, this->getCommandLength());
						this->m_bPresentSmsSignal = true;
						break;
					}
					case OptTags::TAG_SOURCE_ADDR_SUBUNIT:{ 
						poDecoder->decodeSourceAddrSubunit(m_nSourceAddrSubunit,
							m_nSourceAddrSubunitLen, this->getCommandLength());
						this->m_bPresentSourceAddrSubunit = true;
						break;
					}
					case OptTags::TAG_SOURCE_PORT:{ 
						poDecoder->decodeSourcePort(m_nSourcePort,
							m_nSourcePortLen, this->getCommandLength());
						this->m_bPresentSourcePort = true;
						break;
					}
					case OptTags::TAG_SOURCE_SUBADDRESS:{ 
						poDecoder->decodeSourceSubaddress(m_aSourceSubaddress,
							m_nSourceSubaddressLen, this->getCommandLength());
						this->m_bPresentSourceSubaddress = true;
						break;
					}
					case OptTags::TAG_USER_MESSAGE_REFERENCE:{ 
						poDecoder->decodeUserMessageReference(m_nUserMessageReference,
							m_nUserMessageReferenceLen, this->getCommandLength());
						this->m_bPresentUserMessageReference = true;
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

		void SMPPBroadcastSM::outputPacket(ISMPPOutputter* poOutputter){
			// Output header and mandatory fields
			poOutputter->outputHeader(m_oHeader);
			poOutputter->outputServiceType(m_sServiceType);
			poOutputter->outputSourceAddrTON(m_nSourceAddrTON);
			poOutputter->outputSourceAddrNPI(m_nSourceAddrNPI);
			poOutputter->outputSourceAddr21(m_sSourceAddr);
			poOutputter->outputMessageId(m_sMessageId);
			poOutputter->outputPriorityFlag(m_nPriorityFlag);
			poOutputter->outputScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poOutputter->outputValidityPeriod(m_sValidityPeriod);
			poOutputter->outputReplaceIfPresentFlag(m_nReplaceIfPresentFlag);
			poOutputter->outputDataCoding(m_nDataCoding);
			poOutputter->outputSMDefaultMsgId(m_nSMDefaultMsgId);
			poOutputter->outputBroadcastAreaIdentifier(m_aBroadcastAreaIdentifier,
				m_aBroadcastAreaIdentifierLen);
			poOutputter->outputBroadcastContentType(m_aBroadcastContentType, 
				m_nBroadcastContentTypeLen);
			poOutputter->outputBroadcastRepNum(m_nBroadcastRepNum, 
				m_nBroadcastRepNumLen);
			poOutputter->outputBroadcastFrequencyInterval(m_aBroadcastFrequencyInterval, 
				m_nBroadcastFrequencyIntervalLen);


			// Output optional fields
			if(this->m_bPresentAlertOnMsgDelivery)
				poOutputter->outputAlertOnMsgDelivery(m_nAlertOnMsgDelivery, 
					m_nAlertOnMsgDeliveryLen);
			if(this->m_bPresentBroadcastChannelIndicator)
				poOutputter->outputBroadcastChannelIndicator(m_nBroadcastChannelIndicator, 
					m_nBroadcastChannelIndicatorLen);
			if(this->m_bPresentBroadcastContentTypeInfo)
				poOutputter->outputBroadcastContentTypeInfo(m_aBroadcastContentTypeInfo, 
					m_nBroadcastContentTypeInfoLen);
			if(this->m_bPresentBroadcastMessageClass)
				poOutputter->outputBroadcastMessageClass(m_nBroadcastMessageClass, 
					m_nBroadcastMessageClassLen);
			if(this->m_bPresentBroadcastServiceGroup)
				poOutputter->outputBroadcastServiceGroup(m_aBroadcastServiceGroup, 
					m_nBroadcastServiceGroupLen);
			if(this->m_bPresentCallbackNum)
				poOutputter->outputCallbackNum(m_aCallbackNum, 
					m_nCallbackNumLen);
			if(this->m_bPresentCallbackNumAtag)
				poOutputter->outputCallbackNumAtag(m_aCallbackNumAtag, 
					m_nCallbackNumAtagLen);
			if(this->m_bPresentCallbackNumPresInd)
				poOutputter->outputCallbackNumPresInd(m_nCallbackNumPresInd, 
					m_nCallbackNumPresIndLen);
			if(this->m_bPresentDestAddrSubunit)
				poOutputter->outputDestAddrSubunit(m_nDestAddrSubunit, 
					m_nDestAddrSubunitLen);
			if(this->m_bPresentDestSubaddress)
				poOutputter->outputDestSubaddress(m_aDestSubaddress, 
					m_nDestSubaddressLen);
			if(this->m_bPresentDestPort)
				poOutputter->outputDestinationPort(m_nDestPort, 
					m_nDestPortLen);
			if(this->m_bPresentDisplayTime)
				poOutputter->outputDisplayTime(m_nDisplayTime, 
					m_nDisplayTimeLen);
			if(this->m_bPresentLanguageIndicator)
				poOutputter->outputLanguageIndicator(m_nLanguageIndicator, 
					m_nLanguageIndicatorLen);
			if(this->m_bPresentMessagePayload)
				poOutputter->outputMessagePayload(m_aMessagePayload, 
					m_nMessagePayloadLen);
			if(this->m_bPresentMsValidity)
				poOutputter->outputMsValidity(m_nMsValidity, 
					m_nMsValidityLen);
			if(this->m_bPresentPayloadType)
				poOutputter->outputPayloadType(m_nPayloadType, 
					m_nPayloadTypeLen);
			if(this->m_bPresentPrivacyIndicator)
				poOutputter->outputPrivacyIndicator(m_nPrivacyIndicator, 
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentSmsSignal)
				poOutputter->outputSmsSignal(m_nSmsSignal, 
					m_nSmsSignalLen);
			if(this->m_bPresentSourceAddrSubunit)
				poOutputter->outputSourceAddrSubunit(m_nSourceAddrSubunit, 
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentSourcePort)
				poOutputter->outputSourcePort(m_nSourcePort, 
					m_nSourcePortLen);
			if(this->m_bPresentSourceSubaddress)
				poOutputter->outputSourceSubaddress(m_aSourceSubaddress, 
					m_nSourceSubaddressLen);
			if(this->m_bPresentUserMessageReference)
				poOutputter->outputUserMessageReference(m_nUserMessageReference, 
					m_nUserMessageReferenceLen);
		}

		void SMPPBroadcastSM::validatePacket(SMPPValidator* poValidator){

			// Encode header and mandatory fields
			poValidator->validateHeader(m_oHeader);
			poValidator->validateServiceType(m_sServiceType);
			poValidator->validateSourceAddrTON(m_nSourceAddrTON);
			poValidator->validateSourceAddrNPI(m_nSourceAddrNPI);
			poValidator->validateSourceAddr21(m_sSourceAddr);
			poValidator->validateMessageId(m_sMessageId);
			poValidator->validatePriorityFlag(m_nPriorityFlag);
			poValidator->validateScheduleDeliveryTime(m_sScheduleDeliveryTime);
			poValidator->validateValidityPeriod(m_sValidityPeriod);
			poValidator->validateReplaceIfPresentFlag(m_nReplaceIfPresentFlag);
			poValidator->validateDataCoding(m_nDataCoding);
			poValidator->validateSMDefaultMsgId(m_nSMDefaultMsgId);

			// Encode mandatory fields as TLV structures
			poValidator->validateBroadcastAreaIdentifier(m_aBroadcastAreaIdentifier, 
				m_aBroadcastAreaIdentifierLen);
			poValidator->validateBroadcastContentType(m_aBroadcastContentType,
				m_nBroadcastContentTypeLen);
			poValidator->validateBroadcastRepNum(m_nBroadcastRepNum,
				m_nBroadcastRepNumLen);
			poValidator->validateBroadcastFrequencyInterval(m_aBroadcastFrequencyInterval,
				m_nBroadcastFrequencyIntervalLen);

			// Encode optional fields
			if(this->m_bPresentAlertOnMsgDelivery)
				poValidator->validateAlertOnMsgDelivery(m_nAlertOnMsgDelivery,
					m_nAlertOnMsgDeliveryLen);
			if(this->m_bPresentBroadcastChannelIndicator)
				poValidator->validateBroadcastChannelIndicator(m_nBroadcastChannelIndicator,
					m_nBroadcastChannelIndicatorLen);
			if(this->m_bPresentBroadcastContentTypeInfo)
				poValidator->validateBroadcastContentTypeInfo(m_aBroadcastContentTypeInfo,
					m_nBroadcastContentTypeInfoLen);
			if(this->m_bPresentBroadcastMessageClass)
				poValidator->validateBroadcastMessageClass(m_nBroadcastMessageClass,
					m_nBroadcastMessageClassLen);
			if(this->m_bPresentBroadcastServiceGroup)
				poValidator->validateBroadcastServiceGroup(m_aBroadcastServiceGroup,
					m_nBroadcastServiceGroupLen);
			if(this->m_bPresentCallbackNum)
				poValidator->validateCallbackNum(m_aCallbackNum,
					m_nCallbackNumLen);
			if(this->m_bPresentCallbackNumAtag)
				poValidator->validateCallbackNumAtag(m_aCallbackNumAtag,
					m_nCallbackNumAtagLen);
			if(this->m_bPresentCallbackNumPresInd)
				poValidator->validateCallbackNumPresInd(m_nCallbackNumPresInd,
					m_nCallbackNumPresIndLen);
			if(this->m_bPresentDestAddrSubunit)
				poValidator->validateDestAddrSubunit(m_nDestAddrSubunit,
					m_nDestAddrSubunitLen);
			if(this->m_bPresentDestSubaddress)
				poValidator->validateDestSubaddress(m_aDestSubaddress,
					m_nDestSubaddressLen);
			if(this->m_bPresentDestPort)
				poValidator->validateDestinationPort(m_nDestPort,
					m_nDestPortLen);
			if(this->m_bPresentDisplayTime)
				poValidator->validateDisplayTime(m_nDisplayTime,
					m_nDisplayTimeLen);
			if(this->m_bPresentLanguageIndicator)
				poValidator->validateLanguageIndicator(m_nLanguageIndicator,
					m_nLanguageIndicatorLen);
			if(this->m_bPresentMessagePayload)
				poValidator->validateMessagePayload(m_aMessagePayload,
					m_nMessagePayloadLen);
			if(this->m_bPresentMsValidity)
				poValidator->validateMsValidity(m_nMsValidity,
					m_nMsValidityLen);
			if(this->m_bPresentPayloadType)
				poValidator->validatePayloadType(m_nPayloadType,
					m_nPayloadTypeLen);
			if(this->m_bPresentPrivacyIndicator)
				poValidator->validatePrivacyIndicator(m_nPrivacyIndicator,
					m_nPrivacyIndicatorLen);
			if(this->m_bPresentSmsSignal)
				poValidator->validateSmsSignal(m_nSmsSignal,
					m_nSmsSignalLen);
			if(this->m_bPresentSourceAddrSubunit)
				poValidator->validateSourceAddrSubunit(m_nSourceAddrSubunit,
					m_nSourceAddrSubunitLen);
			if(this->m_bPresentSourcePort)
				poValidator->validateSourcePort(m_nSourcePort,
					m_nSourcePortLen);
			if(this->m_bPresentSourceSubaddress)
				poValidator->validateSourceSubaddress(m_aSourceSubaddress,
					m_nSourceSubaddressLen);
			if(this->m_bPresentUserMessageReference)
				poValidator->validateUserMessageReference(m_nUserMessageReference,
					m_nUserMessageReferenceLen);

		}

	}
}
