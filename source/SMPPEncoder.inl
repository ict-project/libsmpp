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

namespace anthill {
	namespace smpp {

		inline void SMPPEncoder::encodeHeader(const Header& oHeader){
			this->encodeUnsigned32(oHeader.getCommandLength());
			this->encodeUnsigned32(oHeader.getCommandId());
			this->encodeUnsigned32(oHeader.getCommandStatus());
			this->encodeUnsigned32(oHeader.getSequenceNumber());

		}

		inline void SMPPEncoder::encodeSystemId(const std::string& sSystemId){
			this->encodeCString(sSystemId);
		}

		inline void SMPPEncoder::encodePassword(const std::string& sPassword){
			this->encodeCString(sPassword);
		}

		inline void SMPPEncoder::encodeSystemType(const std::string& sSystemType){
			this->encodeCString(sSystemType);
		}

		inline void SMPPEncoder::encodeInterfaceVersion(const unsigned char nInterfaceVersion){
			this->encodeChar(nInterfaceVersion);
		}

		inline void SMPPEncoder::encodeAddrTON(const unsigned char nAddrTON){
			this->encodeChar(nAddrTON);
		}

		inline void SMPPEncoder::encodeAddrNPI(const unsigned char nAddrNPI){
			this->encodeChar(nAddrNPI);
		}

		inline void SMPPEncoder::encodeAddressRange(const std::string& sAddressRange){
			this->encodeCString(sAddressRange);
		}

		inline void SMPPEncoder::encodeServiceType(const std::string& sServiceType){
			this->encodeCString(sServiceType);
		}

		inline void SMPPEncoder::encodeSourceAddrTON(const unsigned char nSourceAddrTON){
			this->encodeChar(nSourceAddrTON);
		}

		inline void SMPPEncoder::encodeSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->encodeChar(nSourceAddrNPI);
		}

		inline void SMPPEncoder::encodeSourceAddr21(const std::string& sSourceAddr){
			this->encodeCString(sSourceAddr);
		}

		inline void SMPPEncoder::encodeSourceAddr65(const std::string& sSourceAddr){
			this->encodeCString(sSourceAddr);
		}

		inline void SMPPEncoder::encodeDestAddrTON(const unsigned char nDestAddrTON){
			this->encodeChar(nDestAddrTON);
		}

		inline void SMPPEncoder::encodeDestAddrNPI(const unsigned char nDestAddrNPI){
			this->encodeChar(nDestAddrNPI);
		}

		inline void SMPPEncoder::encodeDestAddr21(const std::string& sDestAddr){
			this->encodeCString(sDestAddr);
		}

		inline void SMPPEncoder::encodeDestAddr65(const std::string& sDestAddr){
			this->encodeCString(sDestAddr);
		}

		inline void SMPPEncoder::encodeEsmClass(const unsigned char nEsmClass){
			this->encodeChar(nEsmClass);
		}

		inline void SMPPEncoder::encodeProtocolId(const unsigned char nProtocolId){
			this->encodeChar(nProtocolId);
		}

		inline void SMPPEncoder::encodePriorityFlag(const unsigned char nPriorityFlag){
			this->encodeChar(nPriorityFlag);
		}

		inline void SMPPEncoder::encodeScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			this->encodeCString(sScheduleDeliveryTime);
		}

		inline void SMPPEncoder::encodeValidityPeriod(const std::string& sValidityPeriod){
			this->encodeCString(sValidityPeriod);
		}

		inline void SMPPEncoder::encodeRegisteredDelivery(const unsigned char nRegisteredDelivery){
			this->encodeChar(nRegisteredDelivery);
		}

		inline void SMPPEncoder::encodeReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){
			this->encodeChar(nReplaceIfPresentFlag);
		}

		inline void SMPPEncoder::encodeDataCoding(const unsigned char nDataCoding){
			this->encodeChar(nDataCoding);
		}

		inline void SMPPEncoder::encodeSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			this->encodeChar(nSMDefaultMsgId);
		}

		inline void SMPPEncoder::encodeSMLength(const unsigned char nSMLength){
			this->encodeChar(nSMLength);
		}

		inline void SMPPEncoder::encodeShortMessage(const std::vector<unsigned char>& aShortMessage){
			this->encodeBinary(aShortMessage);
		}

		inline void SMPPEncoder::encodeMessageId(const std::string& sMessageId){
			this->encodeCString(sMessageId);
		}

		inline void SMPPEncoder::encodeESMEAddrTON(const unsigned char nESMEAddrTON){
			this->encodeChar(nESMEAddrTON);
		}

		inline void SMPPEncoder::encodeESMEAddrNPI(const unsigned char nESMEAddrNPI){
			this->encodeChar(nESMEAddrNPI);
		}

		inline void SMPPEncoder::encodeESMEAddr(const std::string& sESMEAddr){
			this->encodeCString(sESMEAddr);
		}

		inline void SMPPEncoder::encodeNumberOfDest(const unsigned char nNumberOfDest){
			this->encodeChar(nNumberOfDest);
		}

		inline void SMPPEncoder::encodeDestAddresses(const std::vector<DestAddress>& aDestAddresses){
			for(unsigned i = 0; i < aDestAddresses.size(); ++i){
				this->encodeChar(aDestAddresses[i].getDestFlag());
				if(aDestAddresses[i].getDestFlag() == DestFlag::SME_ADDRESS){
					this->encodeChar(aDestAddresses[i].getAddress().getTON());
					this->encodeChar(aDestAddresses[i].getAddress().getNPI());
					this->encodeCString(aDestAddresses[i].getAddress().getAddress());

				} else if(aDestAddresses[i].getDestFlag() == DestFlag::DISTR_LIST_NAME){
					this->encodeCString(aDestAddresses[i].getDistrListName());

				} else {
					throw std::logic_error((boost::format(CodecErrors::ENCODER_INV_DSTFLAG) %m_nOffset %aDestAddresses[i].getDestFlag()).str());
				}
			}
		}

		inline void SMPPEncoder::encodeNoUnsuccess(const unsigned char nNoUnsuccess){
			this->encodeChar(nNoUnsuccess);
		}

		inline void SMPPEncoder::encodeUnsuccessSMEs(const std::vector<UnsuccessSME>& aUnsuccessSMEs){
			for(unsigned i = 0; i < aUnsuccessSMEs.size(); ++i){
				this->encodeChar(aUnsuccessSMEs[i].getSMEAddress().getTON());
				this->encodeChar(aUnsuccessSMEs[i].getSMEAddress().getNPI());
				this->encodeCString(aUnsuccessSMEs[i].getSMEAddress().getAddress());
				this->encodeUnsigned32(aUnsuccessSMEs[i].getErrorStatusCode());
			}
		}

		inline void SMPPEncoder::encodeFinalDate(const std::string& sFinalDate){
			this->encodeCString(sFinalDate);
		}

		inline void SMPPEncoder::encodeMessageState(const unsigned char nMessageState){
			this->encodeChar(nMessageState);
		}

		inline void SMPPEncoder::encodeErrorCode(const unsigned char nErrorCode){
			this->encodeChar(nErrorCode);
		}

		inline void SMPPEncoder::encodeBroadcastAreaIdentifier(const BroadcastAreaIdentifier& oBroadcastAreaIdentifier, const unsigned short nBroadcastAreaIdentifierLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_AREA_IDENTIFIER, oBroadcastAreaIdentifier.getValue(), nBroadcastAreaIdentifierLen);
		}


		inline void SMPPEncoder::encodeBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){
			for(unsigned j=0; j < aBroadcastAreaIdentifier.size(); ++ j){
				this->encodeBroadcastAreaIdentifier(aBroadcastAreaIdentifier[j], aBroadcastAreaIdentifierLen[j]);
			}
		}

		inline void SMPPEncoder::encodeBroadcastRepNum(const unsigned short nBroadcastRepNum, const unsigned short nBroadcastRepNumLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_REP_NUM, nBroadcastRepNum, nBroadcastRepNumLen);
		}

		inline void SMPPEncoder::encodeBroadcastFrequencyInterval(const std::vector<unsigned char>& aBroadcastFrequencyInterval, const unsigned short nBroadcastFrequencyIntervalLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_FREQUENCY_INTERVAL, aBroadcastFrequencyInterval, nBroadcastFrequencyIntervalLen);
		}

		inline void SMPPEncoder::encodeBroadcastAreaSuccess(unsigned char nBroadcastAreaSuccess, const unsigned short nBroadcastAreaSuccessLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_AREA_SUCCESS, nBroadcastAreaSuccess, nBroadcastAreaSuccessLen);
		}

		inline void SMPPEncoder::encodeScInterfaceVersion(const unsigned char nScInterfaceVersion, const unsigned short nScInterfaceVersionLen){
			this->encodeTLV(OptTags::TAG_SC_INTERFACE_VERSION, nScInterfaceVersion, nScInterfaceVersionLen);
		}

		inline void SMPPEncoder::encodeMSAvailabilityStatus(const unsigned char nMSAvailabilityStatus, const unsigned short nMSAvailabilityStatusLen){
			this->encodeTLV(OptTags::TAG_MS_AVAILABILITY_STATUS, nMSAvailabilityStatus, nMSAvailabilityStatusLen);
		}

		inline void SMPPEncoder::encodeAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery, const unsigned short nAlertOnMsgDeliveryLen){
			this->encodeTLV(OptTags::TAG_ALERT_ON_MESSAGE_DELIVERY, nAlertOnMsgDelivery, nAlertOnMsgDeliveryLen);
		}

		inline void SMPPEncoder::encodeBroadcastChannelIndicator(const unsigned char nBroadcastChannelIndicator, const unsigned short nBroadcastChannelIndicatorLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_CHANNEL_INDICATOR, nBroadcastChannelIndicator, nBroadcastChannelIndicatorLen);
		}

		inline void SMPPEncoder::encodeBroadcastContentTypeInfo(const std::vector<unsigned char>& aBroadcastContentTypeInfo, const unsigned short nBroadcastContentTypeInfoLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_CONTENT_TYPE_INFO, aBroadcastContentTypeInfo, nBroadcastContentTypeInfoLen);
		}

		inline void SMPPEncoder::encodeBroadcastMessageClass(const unsigned char nBroadcastMessageClass, const unsigned short nBroadcastMessageClassLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_MESSAGE_CLASS, nBroadcastMessageClass, nBroadcastMessageClassLen);
		}

		inline void SMPPEncoder::encodeBroadcastServiceGroup(const std::vector<unsigned char>& aBroadcastServiceGroup, const unsigned short nBroadcastServiceGroupLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_SERVICE_GROUP, aBroadcastServiceGroup, nBroadcastServiceGroupLen);
		}

		inline void SMPPEncoder::encodeCallbackNum(const std::vector<unsigned char>& aCallbackNum, const unsigned short nCallbackNumLen){
			this->encodeTLV(OptTags::TAG_CALLBACK_NUM, aCallbackNum, nCallbackNumLen);
		}

		inline void SMPPEncoder::encodeCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag, const unsigned short nCallbackNumAtagLen){
			this->encodeTLV(OptTags::TAG_CALLBACK_NUM_ATAG, aCallbackNumAtag, nCallbackNumAtagLen);
		}

		inline void SMPPEncoder::encodeCallbackNumPresInd(const unsigned char nCallbackNumPresInd, const unsigned short nCallbackNumPresIndLen){
			this->encodeTLV(OptTags::TAG_CALLBACK_NUM_PRES_IND, nCallbackNumPresInd, nCallbackNumPresIndLen);
		}

		inline void SMPPEncoder::encodeDestAddrSubunit(const unsigned char nDestAddrSubunit, const unsigned short nDestAddrSubunitLen){
			this->encodeTLV(OptTags::TAG_DEST_ADDR_SUBUNIT, nDestAddrSubunit, nDestAddrSubunitLen);
		}

		inline void SMPPEncoder::encodeDestSubaddress(const std::vector<unsigned char>& aDestSubaddress, const unsigned short nDestSubaddressLen){
			this->encodeTLV(OptTags::TAG_DEST_SUBADDRESS, aDestSubaddress, nDestSubaddressLen);
		}

		inline void SMPPEncoder::encodeDisplayTime(const unsigned char nDisplayTime, const unsigned short nDisplayTimeLen){
			this->encodeTLV(OptTags::TAG_DISPLAY_TIME, nDisplayTime, nDisplayTimeLen);
		}

		inline void SMPPEncoder::encodeLanguageIndicator(const unsigned char nLanguageIndicator, const unsigned short nLanguageIndicatorLen){
			this->encodeTLV(OptTags::TAG_LANGUAGE_INDICATOR, nLanguageIndicator, nLanguageIndicatorLen);
		}

		inline void SMPPEncoder::encodeMessagePayload(const std::vector<unsigned char>& aMessagePayload, const unsigned short nMessagePayloadLen){
			this->encodeTLV(OptTags::TAG_MESSAGE_PAYLOAD, aMessagePayload, nMessagePayloadLen);
		}

		inline void SMPPEncoder::encodeMsValidity(const unsigned char nMsValidity, const unsigned short nMsValidityLen){
			this->encodeTLV(OptTags::TAG_MS_VALIDITY, nMsValidity, nMsValidityLen);
		}

		inline void SMPPEncoder::encodePayloadType(const unsigned char nPayloadType, const unsigned short nPayloadTypeLen){
			this->encodeTLV(OptTags::TAG_PAYLOAD_TYPE, nPayloadType, nPayloadTypeLen);
		}

		inline void SMPPEncoder::encodePrivacyIndicator(const unsigned char nPrivacyIndicator, const unsigned short nPrivacyIndicatorLen){
			this->encodeTLV(OptTags::TAG_PRIVACY_INDICATOR, nPrivacyIndicator, nPrivacyIndicatorLen);
		}

		inline void SMPPEncoder::encodeSmsSignal(const unsigned short nSmsSignal, const unsigned short nSmsSignalLen){
			this->encodeTLV(OptTags::TAG_SMS_SIGNAL, nSmsSignal, nSmsSignalLen);
		}

		inline void SMPPEncoder::encodeSourceAddrSubunit(const unsigned char nSourceAddrSubunit, const unsigned short nSourceAddrSubunitLen){
			this->encodeTLV(OptTags::TAG_SOURCE_ADDR_SUBUNIT, nSourceAddrSubunit, nSourceAddrSubunitLen);
		}

		inline void SMPPEncoder::encodeSourcePort(const unsigned short nSourcePort, const unsigned short nSourcePortLen){
			this->encodeTLV(OptTags::TAG_SOURCE_PORT, nSourcePort, nSourcePortLen);
		}

		inline void SMPPEncoder::encodeSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress, const unsigned short nSourceSubaddressLen){
			this->encodeTLV(OptTags::TAG_SOURCE_SUBADDRESS, aSourceSubaddress, nSourceSubaddressLen);
		}

		inline void SMPPEncoder::encodeUserMessageReference(const unsigned short nUserMessageReference, const unsigned short nUserMessageReferenceLen){
			this->encodeTLV(OptTags::TAG_USER_MESSAGE_REFERENCE, nUserMessageReference, nUserMessageReferenceLen);
		}

		inline void SMPPEncoder::encodeBroadcastErrorStatus(const unsigned nBroadcastErrorStatus, const unsigned short nBroadcastErrorStatusLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_ERROR_STATUS, nBroadcastErrorStatus, nBroadcastErrorStatusLen);
		}

		inline void SMPPEncoder::encodeFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aFailedBroadcastAreaIdentifier, const std::vector<unsigned short>& aFailedBroadcastAreaIdentifierLen){
			for(unsigned j=0; j < aFailedBroadcastAreaIdentifier.size(); ++ j){
				this->encodeBroadcastAreaIdentifier(aFailedBroadcastAreaIdentifier[j], aFailedBroadcastAreaIdentifierLen[j]);
			}
		}

		inline void SMPPEncoder::encodeBroadcastContentType(const std::vector<unsigned char>& aBroadcastContentType, const unsigned short nBroadcastContentTypeLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_CONTENT_TYPE, aBroadcastContentType, nBroadcastContentTypeLen);
		}

		inline void SMPPEncoder::encodeSourceNetworkType(const unsigned char nSourceNetworkType, const unsigned short nSourceNetworkTypeLen){
			this->encodeTLV(OptTags::TAG_SOURCE_NETWORK_TYPE, nSourceNetworkType, nSourceNetworkTypeLen);
		}

		inline void SMPPEncoder::encodeSourceBearerType(const unsigned char nSourceBearerType, const unsigned short nSourceBearerTypeLen){
			this->encodeTLV(OptTags::TAG_SOURCE_BEARER_TYPE, nSourceBearerType, nSourceBearerTypeLen);
		}

		inline void SMPPEncoder::encodeSourceTelematicsId(const unsigned char nSourceTelematicsId, const unsigned short nSourceTelematicsIdLen){
			this->encodeTLV(OptTags::TAG_SOURCE_TELEMATICS_ID, nSourceTelematicsId, nSourceTelematicsIdLen);
		}

		inline void SMPPEncoder::encodeDestinationPort(const unsigned short nDestinationPort, const unsigned short nDestinationPortLen){
			this->encodeTLV(OptTags::TAG_DESTINATION_PORT, nDestinationPort, nDestinationPortLen);
		}

		inline void SMPPEncoder::encodeDestNetworkType(const unsigned char nDestNetworkType, const unsigned short nDestNetworkTypeLen){
			this->encodeTLV(OptTags::TAG_DEST_NETWORK_TYPE, nDestNetworkType, nDestNetworkTypeLen);
		}

		inline void SMPPEncoder::encodeDestBearerType(const unsigned char nDestBearerType, const unsigned short nDestBearerTypeLen){
			this->encodeTLV(OptTags::TAG_DEST_BEARER_TYPE, nDestBearerType, nDestBearerTypeLen);
		}

		inline void SMPPEncoder::encodeDestTelematicsId(const unsigned char nDestTelematicsId, const unsigned short nDestTelematicsIdLen){
			this->encodeTLV(OptTags::TAG_DEST_TELEMATICS_ID, nDestTelematicsId, nDestTelematicsIdLen);
		}

		inline void SMPPEncoder::encodeSarMsgRefNum(const unsigned short nSarMsgRefNum, const unsigned short nSarMsgRefNumLen){
			this->encodeTLV(OptTags::TAG_SAR_MSG_REF_NUM, nSarMsgRefNum, nSarMsgRefNumLen);
		}

		inline void SMPPEncoder::encodeSarTotalSegments(const unsigned char nSarTotalSegments, const unsigned short nSarTotalSegmentsLen){
			this->encodeTLV(OptTags::TAG_SAR_TOTAL_SEGMENTS, nSarTotalSegments, nSarTotalSegmentsLen);
		}

		inline void SMPPEncoder::encodeSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum, const unsigned short nSarSegmentSeqnumLen){
			this->encodeTLV(OptTags::TAG_SAR_SEGMENT_SEQNUM, nSarSegmentSeqnum, nSarSegmentSeqnumLen);
		}

		inline void SMPPEncoder::encodeMoreMessagesToSend(const unsigned char nMoreMessagesToSend, const unsigned short nMoreMessagesToSendLen){
			this->encodeTLV(OptTags::TAG_MORE_MESSAGES_TO_SEND, nMoreMessagesToSend, nMoreMessagesToSendLen);
		}

		inline void SMPPEncoder::encodeQosTimeToLive(const unsigned nQosTimeToLive, const unsigned short nQosTimeToLiveLen){
			this->encodeTLV(OptTags::TAG_QOS_TIME_TO_LIVE, nQosTimeToLive, nQosTimeToLiveLen);
		}

		inline void SMPPEncoder::encodeSetDpf(const unsigned char nSetDpf, const unsigned short nSetDpfLen){
			this->encodeTLV(OptTags::TAG_SET_DPF, nSetDpf, nSetDpfLen);
		}

		inline void SMPPEncoder::encodeReceiptedMessageId(const std::string& sReceiptedMessageId, const unsigned short nReceiptedMessageIdLen){
			this->encodeTLV(OptTags::TAG_RECEIPTED_MESSAGE_ID, sReceiptedMessageId, nReceiptedMessageIdLen);
		}

		inline void SMPPEncoder::encodeMessageStateTLV(const unsigned char nMessageState, const unsigned short nMessageStateLen){
			this->encodeTLV(OptTags::TAG_MESSAGE_STATE, nMessageState, nMessageStateLen);
		}

		inline void SMPPEncoder::encodeNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode, const unsigned short nNetworkErrorCodeLen){
			this->encodeUnsigned16(OptTags::TAG_NETWORK_ERROR_CODE);
			this->encodeUnsigned16(nNetworkErrorCodeLen);
			this->encodeChar(oNetworkErrorCode.getNetworkCode());
			this->encodeUnsigned16(oNetworkErrorCode.getErrorCode());

		}

		inline void SMPPEncoder::encodeMsMsgWaitFacilities(const unsigned char nMsMsgWaitFacilities, const unsigned short nMsMsgWaitFacilitiesLen){
			this->encodeTLV(OptTags::TAG_MS_MSG_WAIT_FACILITIES, nMsMsgWaitFacilities, nMsMsgWaitFacilitiesLen);
		}

		inline void SMPPEncoder::encodeNumberOfMessages(const unsigned char nNumberOfMessages, const unsigned short nNumberOfMessagesLen){
			this->encodeTLV(OptTags::TAG_NUMBER_OF_MESSAGES, nNumberOfMessages, nNumberOfMessagesLen);
		}

		inline void SMPPEncoder::encodeItsReplyType(const unsigned char nItsReplyType, const unsigned short nItsReplyTypeLen){
			this->encodeTLV(OptTags::TAG_ITS_REPLY_TYPE, nItsReplyType, nItsReplyTypeLen);
		}

		inline void SMPPEncoder::encodeItsSessionInfo(const unsigned short nItsSessionInfo, const unsigned short nItsSessionInfoLen){
			this->encodeTLV(OptTags::TAG_ITS_SESSION_INFO, nItsSessionInfo, nItsSessionInfoLen);
		}

		inline void SMPPEncoder::encodeUserResponseCode(const unsigned char nUserResponseCode, const unsigned short nUserResponseCodeLen){
			this->encodeTLV(OptTags::TAG_USER_RESPONSE_CODE, nUserResponseCode, nUserResponseCodeLen);
		}

		inline void SMPPEncoder::encodeDeliveryFailureReason(const unsigned char nDeliveryFailureReason, const unsigned short nDeliveryFailureReasonLen){
			this->encodeTLV(OptTags::TAG_DELIVERY_FAILURE_REASON, nDeliveryFailureReason, nDeliveryFailureReasonLen);
		}

		inline void SMPPEncoder::encodeAdditionalStatusInfoText(const std::vector<unsigned char>& aAdditionalStatusInfoText, const unsigned short nAdditionalStatusInfoTextLen){
			this->encodeTLV(OptTags::TAG_ADDITIONAL_STATUS_INFO_TEXT, aAdditionalStatusInfoText, nAdditionalStatusInfoTextLen);
		}

		inline void SMPPEncoder::encodeDpfResult(const unsigned char nDpfResult, const unsigned short nDpfResultLen){
			this->encodeTLV(OptTags::TAG_DPF_RESULT, nDpfResult, nDpfResultLen);
		}

		inline void SMPPEncoder::encodeBroadcastEndTime(const std::string& sBroadcastEndTime, const unsigned short nBroadcastEndTimeLen){
			this->encodeTLV(OptTags::TAG_BROADCAST_END_TIME, sBroadcastEndTime, nBroadcastEndTimeLen);
		}

		inline void SMPPEncoder::encodeUssdServiceOp(const unsigned char nUssdServiceOp, const unsigned short nUssdServiceOpLen){
			this->encodeTLV(OptTags::TAG_USSD_SERVICE_OP, nUssdServiceOp, nUssdServiceOpLen);
		}

	}
}
