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

		inline void SMPPValidator::validateHeader(const Header& oHeader){
		}

		inline void SMPPValidator::validateSystemId(const std::string& sSystemId){
		}

		inline void SMPPValidator::validatePassword(const std::string& sPassword){
			if(sPassword.size() + 1 > SMPPMaxLen::PASSWORD_MAX_LEN) {
				throw std::logic_error(CodecErrors::VALIDATE_PASSWORD_MAX_LEN);
			}
		}

		inline void SMPPValidator::validateSystemType(const std::string& sSystemType){
			if(sSystemType.size() + 1 > SMPPMaxLen::SYSTEM_TYPE_MAX_LEN) {
				throw std::logic_error(CodecErrors::VALIDATE_SYSTEM_TYPE_MAX_LEN);
			}
		}

		inline void SMPPValidator::validateInterfaceVersion(const unsigned char nInterfaceVersion){
			// Check the range
			if((nInterfaceVersion < InterfaceVersion::SMPP_VER_0_0 ||
				nInterfaceVersion > InterfaceVersion::SMPP_VER_3_4) &&
				nInterfaceVersion != InterfaceVersion::SMPP_VER_5_0){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_INTERFACE_VERSION_VALUE) %nInterfaceVersion).str());
			}
		}

		inline void SMPPValidator::validateAddrTON(const unsigned char nAddrTON){
		}

		inline void SMPPValidator::validateAddrNPI(const unsigned char nAddrNPI){
		}

		inline void SMPPValidator::validateAddressRange(const std::string& sAddressRange){
			if(sAddressRange.size() + 1 > SMPPMaxLen::ADDRESS_RANGE_MAX_LEN) {
				throw std::logic_error(CodecErrors::VALIDATE_ADDRESS_RANGE_MAX_LEN);
			}
		}

		inline void SMPPValidator::validateServiceType(const std::string& sServiceType){
		}

		inline void SMPPValidator::validateSourceAddrTON(const unsigned char nSourceAddrTON){
		}

		inline void SMPPValidator::validateSourceAddrNPI(const unsigned char nSourceAddrNPI){
		}

		inline void SMPPValidator::validateSourceAddr21(const std::string& sSourceAddr){
		}

		inline void SMPPValidator::validateSourceAddr65(const std::string& sSourceAddr){
		}

		inline void SMPPValidator::validateDestAddrTON(const unsigned char nDestAddrTON){
		}

		inline void SMPPValidator::validateDestAddrNPI(const unsigned char nDestAddrNPI){
		}

		inline void SMPPValidator::validateDestAddr21(const std::string& sDestAddr){
		}

		inline void SMPPValidator::validateDestAddr65(const std::string& sDestAddr){
		}

		inline void SMPPValidator::validateEsmClass(const unsigned char nEsmClass){
		}

		inline void SMPPValidator::validateProtocolId(const unsigned char nProtocolId){
		}

		inline void SMPPValidator::validatePriorityFlag(const unsigned char nPriorityFlag){
		}

		inline void SMPPValidator::validateScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			// Len should be less than 17
			if(sScheduleDeliveryTime.size() + 1 > SMPPMaxLen::SCHEDULE_DELIVERY_TIME_MAX_LEN) {
				throw std::logic_error(CodecErrors::VALIDATE_SCHEDULE_DELIVERY_TIME_MAX_LEN);
			}

			// Len should be either 17 or 1
			if((sScheduleDeliveryTime.size() + 1) != SMPPMaxLen::SCHEDULE_DELIVERY_TIME_MAX_LEN &&
				(sScheduleDeliveryTime.size() + 1) != 1) {
				throw std::logic_error(CodecErrors::VALIDATE_SCHEDULE_DELIVERY_TIME_RANGE_LEN);
			}
		}

		inline void SMPPValidator::validateValidityPeriod(const std::string& sValidityPeriod){
			// Len should be less than 17
			if(sValidityPeriod.size() + 1 > SMPPMaxLen::VALIDITY_PERIOD_MAX_LEN) {
				throw std::logic_error(CodecErrors::VALIDATE_VALIDITY_PERIOD_MAX_LEN);
			}

			// Len should be either 17 or 1
			if((sValidityPeriod.size() + 1) != SMPPMaxLen::VALIDITY_PERIOD_MAX_LEN &&
				(sValidityPeriod.size() + 1) != 1) {
				throw std::logic_error(CodecErrors::VALIDATE_VALIDITY_PERIOD_RANGE_LEN);
			}
		}

		inline void SMPPValidator::validateRegisteredDelivery(const unsigned char nRegisteredDelivery){
		}

		inline void SMPPValidator::validateReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){
		}

		inline void SMPPValidator::validateDataCoding(const unsigned char nDataCoding){
		}

		inline void SMPPValidator::validateSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
		}

		inline void SMPPValidator::validateSMLength(const unsigned char nSMLength){
		}

		inline void SMPPValidator::validateShortMessage(const std::vector<unsigned char>& aShortMessage, const char nSMLength){
		}

		inline void SMPPValidator::validateMessageId(const std::string& sMessageId){
		}

		inline void SMPPValidator::validateMessageIdNull(const std::string& sMessageId){
			// Should me null
			if((sMessageId.size() + 1) != 1) {
				throw std::logic_error(CodecErrors::VALIDATE_MESSAGE_ID_NULL_LEN);
			}
		}

		inline void SMPPValidator::validateESMEAddrTON(const unsigned char nESMEAddrTON){
		}

		inline void SMPPValidator::validateESMEAddrNPI(const unsigned char nESMEAddrNPI){
		}

		inline void SMPPValidator::validateESMEAddr(const std::string& sESMEAddr){
		}

		inline void SMPPValidator::validateNumberOfDest(const unsigned char nNumberOfDest){
		}

		inline void SMPPValidator::validateDestAddresses(const std::vector<DestAddress>& aDestAddresses, const char nNumberOfDests){
			// Check the lengths
			if(aDestAddresses.size() != nNumberOfDests){
				throw std::logic_error(CodecErrors::VALIDATE_DEST_ADDRESSES_LEN);
			}
		}

		inline void SMPPValidator::validateNoUnsuccess(const unsigned char nNoUnsuccess){
		}

		inline void SMPPValidator::validateUnsuccessSMEs(const std::vector<UnsuccessSME>& aUnsuccessSMEs, const char nNoUnsuccess){
			// Check the lengths
			if(aUnsuccessSMEs.size() != nNoUnsuccess){
				throw std::logic_error(CodecErrors::VALIDATE_UNSUCCESS_SMES_LEN);
			}
		}

		inline void SMPPValidator::validateFinalDate(const std::string& sFinalDate){
		}

		inline void SMPPValidator::validateMessageState(const unsigned char nMessageState){
			// Check the value
			if(nMessageState < MessageState::ENROUTE || nMessageState > MessageState::SKIPPED){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_MESSAGE_STATE_VALUE) %nMessageState).str());
			}
		}

		inline void SMPPValidator::validateErrorCode(const unsigned char nErrorCode){
		}

		inline void SMPPValidator::validateBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){
			// Check the presents
			if(aBroadcastAreaIdentifier.size() == 0){
				throw std::logic_error(CodecErrors::VALIDATE_BROADCAST_AREA_IDENTIFIER_MIN_LEN);
			}

			// Check the lengths
			if(aBroadcastAreaIdentifier.size() != aBroadcastAreaIdentifierLen.size()){
				throw std::logic_error(CodecErrors::VALIDATE_BROADCAST_AREA_IDENTIFIER_LEN);
			}
		}

		inline void SMPPValidator::validateBroadcastRepNum(const unsigned short nBroadcastRepNum, const unsigned short nBroadcastRepNumLen){
			// Check the TLV len
			if (nBroadcastRepNumLen != SMPPTLVLen::WORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_WORD_LEN) %nBroadcastRepNumLen %OptTags::TAG_BROADCAST_REP_NUM).str());
			}
		}

		inline void SMPPValidator::validateBroadcastFrequencyInterval(const std::vector<unsigned char>& aBroadcastFrequencyInterval, const unsigned short){
		}

		inline void SMPPValidator::validateBroadcastAreaSuccess(const unsigned char nBroadcastAreaSuccess, const unsigned short nBroadcastAreaSuccessLen){
			// Check the TLV len
			if (nBroadcastAreaSuccessLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nBroadcastAreaSuccessLen %OptTags::TAG_BROADCAST_AREA_SUCCESS).str());
			}
		}

		inline void SMPPValidator::validateScInterfaceVersion(const unsigned char nScInterfaceVersion, const unsigned short nScInterfaceVersionLen){
			// Check the TLV len
			if (nScInterfaceVersionLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nScInterfaceVersionLen %OptTags::TAG_SC_INTERFACE_VERSION).str());
			}

			// Check the range
			if((nScInterfaceVersion < InterfaceVersion::SMPP_VER_0_0 ||
				nScInterfaceVersion > InterfaceVersion::SMPP_VER_3_4) &&
				nScInterfaceVersion != InterfaceVersion::SMPP_VER_5_0){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_INTERFACE_VERSION_VALUE) %nScInterfaceVersion).str());
			}
		}

		inline void SMPPValidator::validateMSAvailabilityStatus(const unsigned char nMSAvailabilityStatus, const unsigned short nMSAvailabilityStatusLen){
			// Check the TLV len
			if (nMSAvailabilityStatusLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nMSAvailabilityStatusLen %OptTags::TAG_MS_AVAILABILITY_STATUS).str());
			}
		}

		inline void SMPPValidator::validateAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery, const unsigned short nAlertOnMsgDeliveryLen){
			// Check the TLV len
			if (nAlertOnMsgDeliveryLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nAlertOnMsgDeliveryLen %OptTags::TAG_ALERT_ON_MESSAGE_DELIVERY).str());
			}
		}

		inline void SMPPValidator::validateBroadcastChannelIndicator(const unsigned char nBroadcastChannelIndicator, const unsigned short nBroadcastChannelIndicatorLen){
			// Check the TLV len
			if (nBroadcastChannelIndicatorLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nBroadcastChannelIndicatorLen %OptTags::TAG_BROADCAST_CHANNEL_INDICATOR).str());
			}
		}

		inline void SMPPValidator::validateBroadcastContentTypeInfo(const std::vector<unsigned char>& aBroadcastContentTypeInfo, const unsigned short){
		}

		inline void SMPPValidator::validateBroadcastMessageClass(const unsigned char nBroadcastMessageClass, const unsigned short nBroadcastMessageClassLen){
			// Check the TLV len
			if (nBroadcastMessageClassLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nBroadcastMessageClassLen %OptTags::TAG_BROADCAST_MESSAGE_CLASS).str());
			}
		}

		inline void SMPPValidator::validateBroadcastServiceGroup(const std::vector<unsigned char>& aBroadcastServiceGroup, const unsigned short){
		}

		inline void SMPPValidator::validateCallbackNum(const std::vector<unsigned char>& aCallbackNum, const unsigned short){
		}

		inline void SMPPValidator::validateCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag, const unsigned short){
		}

		inline void SMPPValidator::validateCallbackNumPresInd(const unsigned char nCallbackNumPresInd, const unsigned short nCallbackNumPresIndLen){
			// Check the TLV len
			if (nCallbackNumPresIndLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nCallbackNumPresIndLen %OptTags::TAG_CALLBACK_NUM_PRES_IND).str());
			}
		}

		inline void SMPPValidator::validateDestAddrSubunit(const unsigned char nDestAddrSubunit, const unsigned short nDestAddrSubunitLen){
			// Check the TLV len
			if (nDestAddrSubunitLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nDestAddrSubunitLen %OptTags::TAG_DEST_ADDR_SUBUNIT).str());
			}
		}

		inline void SMPPValidator::validateDestSubaddress(const std::vector<unsigned char>& aDestSubaddress, const unsigned short){
		}

		inline void SMPPValidator::validateDisplayTime(const unsigned char nDisplayTime, const unsigned short nDisplayTimeLen){
			// Check the TLV len
			if (nDisplayTimeLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nDisplayTimeLen %OptTags::TAG_DISPLAY_TIME).str());
			}
		}

		inline void SMPPValidator::validateLanguageIndicator(const unsigned char nLanguageIndicator, const unsigned short nLanguageIndicatorLen){
			// Check the TLV len
			if (nLanguageIndicatorLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nLanguageIndicatorLen %OptTags::TAG_LANGUAGE_INDICATOR).str());
			}
		}

		inline void SMPPValidator::validateMessagePayload(const std::vector<unsigned char>& aMessagePayload, const unsigned short){
		}

		inline void SMPPValidator::validateMsValidity(const unsigned char nMsValidity, const unsigned short nMsValidityLen){
			// Check the TLV len
			if (nMsValidityLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nMsValidityLen %OptTags::TAG_MS_VALIDITY).str());
			}
		}

		inline void SMPPValidator::validatePayloadType(const unsigned char nPayloadType, const unsigned short nPayloadTypeLen){
			// Check the TLV len
			if (nPayloadTypeLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nPayloadTypeLen %OptTags::TAG_PAYLOAD_TYPE).str());
			}
		}

		inline void SMPPValidator::validatePrivacyIndicator(const unsigned char nPrivacyIndicator, const unsigned short nPrivacyIndicatorLen){
			// Check the TLV len
			if (nPrivacyIndicatorLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nPrivacyIndicatorLen %OptTags::TAG_PRIVACY_INDICATOR).str());
			}
		}

		inline void SMPPValidator::validateSmsSignal(const unsigned short nSmsSignal, const unsigned short nSmsSignalLen){
			// Check the TLV len
			if (nSmsSignalLen != SMPPTLVLen::WORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_WORD_LEN) %nSmsSignalLen %OptTags::TAG_SMS_SIGNAL).str());
			}
		}

		inline void SMPPValidator::validateSourceAddrSubunit(const unsigned char nSourceAddrSubunit, const unsigned short nSourceAddrSubunitLen){
			// Check the TLV len
			if (nSourceAddrSubunitLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nSourceAddrSubunitLen %OptTags::TAG_SOURCE_ADDR_SUBUNIT).str());
			}
		}

		inline void SMPPValidator::validateSourcePort(const unsigned short nSourcePort, const unsigned short nSourcePortLen){
			// Check the TLV len
			if (nSourcePortLen != SMPPTLVLen::WORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_WORD_LEN) %nSourcePortLen %OptTags::TAG_SOURCE_PORT).str());
			}
		}

		inline void SMPPValidator::validateSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress, const unsigned short){
		}

		inline void SMPPValidator::validateUserMessageReference(const unsigned short nUserMessageReference, const unsigned short nUserMessageReferenceLen){
			// Check the TLV len
			if (nUserMessageReferenceLen != SMPPTLVLen::WORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_WORD_LEN) %nUserMessageReferenceLen %OptTags::TAG_USER_MESSAGE_REFERENCE).str());
			}
		}

		inline void SMPPValidator::validateBroadcastErrorStatus(const unsigned nBroadcastErrorStatus, const unsigned short nBroadcastErrorStatusLen){
			// Check the TLV len
			if (nBroadcastErrorStatusLen != SMPPTLVLen::DWORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_DWORD_LEN) %nBroadcastErrorStatusLen %OptTags::TAG_BROADCAST_ERROR_STATUS).str());
			}
		}

		inline void SMPPValidator::validateFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aFailedBroadcastAreaIdentifier, const std::vector<unsigned short>& aFailedBroadcastAreaIdentifierLen){
			// Check the lengths
			if(aFailedBroadcastAreaIdentifier.size() != aFailedBroadcastAreaIdentifierLen.size()){
				throw std::logic_error(CodecErrors::VALIDATE_FAILED_BROADCAST_AREA_IDENTIFIER_LEN);
			}
		}

		inline void SMPPValidator::validateBroadcastContentType(const std::vector<unsigned char>& aBroadcastContentType, const unsigned short){

		}

		inline void SMPPValidator::validateSourceNetworkType(const unsigned char nSourceNetworkType, const unsigned short nSourceNetworkTypeLen){
			// Check the TLV len
			if (nSourceNetworkTypeLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nSourceNetworkTypeLen %OptTags::TAG_SOURCE_NETWORK_TYPE).str());
			}
		}

		inline void SMPPValidator::validateSourceBearerType(const unsigned char nSourceBearerType, const unsigned short nSourceBearerTypeLen){
			// Check the TLV len
			if (nSourceBearerTypeLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nSourceBearerTypeLen %OptTags::TAG_SOURCE_BEARER_TYPE).str());
			}
		}

		inline void SMPPValidator::validateSourceTelematicsId(const unsigned char nSourceTelematicsId, const unsigned short nSourceTelematicsIdLen){
			// Check the TLV len
			if (nSourceTelematicsIdLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nSourceTelematicsIdLen %OptTags::TAG_SOURCE_TELEMATICS_ID).str());
			}
		}

		inline void SMPPValidator::validateDestinationPort(const unsigned short nDestinationPort, const unsigned short nDestinationPortLen){
			// Check the TLV len
			if (nDestinationPortLen != SMPPTLVLen::WORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_WORD_LEN) %nDestinationPortLen %OptTags::TAG_DESTINATION_PORT).str());
			}
		}

		inline void SMPPValidator::validateDestNetworkType(const unsigned char nDestNetworkType, const unsigned short nDestNetworkTypeLen){
			// Check the TLV len
			if (nDestNetworkTypeLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nDestNetworkTypeLen %OptTags::TAG_DEST_NETWORK_TYPE).str());
			}
		}

		inline void SMPPValidator::validateDestBearerType(const unsigned char nDestBearerType, const unsigned short nDestBearerTypeLen){
			// Check the TLV len
			if (nDestBearerTypeLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nDestBearerTypeLen %OptTags::TAG_DEST_BEARER_TYPE).str());
			}
		}

		inline void SMPPValidator::validateDestTelematicsId(const unsigned char nDestTelematicsId, const unsigned short nDestTelematicsIdLen){
			// Check the TLV len
			if (nDestTelematicsIdLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nDestTelematicsIdLen %OptTags::TAG_DEST_TELEMATICS_ID).str());
			}
		}

		inline void SMPPValidator::validateSarMsgRefNum(const unsigned short nSarMsgRefNum, const unsigned short nSarMsgRefNumLen){
			// Check the TLV len
			if (nSarMsgRefNumLen != SMPPTLVLen::WORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_WORD_LEN) %nSarMsgRefNumLen %OptTags::TAG_SAR_MSG_REF_NUM).str());
			}
		}

		inline void SMPPValidator::validateSarTotalSegments(const unsigned char nSarTotalSegments, const unsigned short nSarTotalSegmentsLen){
			// Check the TLV len
			if (nSarTotalSegmentsLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nSarTotalSegmentsLen %OptTags::TAG_SAR_TOTAL_SEGMENTS).str());
			}
		}

		inline void SMPPValidator::validateSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum, const unsigned short nSarSegmentSeqnumLen){
			// Check the TLV len
			if (nSarSegmentSeqnumLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nSarSegmentSeqnumLen %OptTags::TAG_SAR_SEGMENT_SEQNUM).str());
			}
		}

		inline void SMPPValidator::validateMoreMessagesToSend(const unsigned char nMoreMessagesToSend, const unsigned short nMoreMessagesToSendLen){
			// Check the TLV len
			if (nMoreMessagesToSendLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nMoreMessagesToSendLen %OptTags::TAG_MORE_MESSAGES_TO_SEND).str());
			}
		}

		inline void SMPPValidator::validateQosTimeToLive(const unsigned nQosTimeToLive, const unsigned short nQosTimeToLiveLen){
			// Check the TLV len
			if (nQosTimeToLiveLen != SMPPTLVLen::DWORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_DWORD_LEN) %nQosTimeToLiveLen %OptTags::TAG_QOS_TIME_TO_LIVE).str());
			}
		}

		inline void SMPPValidator::validateSetDpf(const unsigned char nSetDpf, const unsigned short nSetDpfLen){
			// Check the TLV len
			if (nSetDpfLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nSetDpfLen %OptTags::TAG_SET_DPF).str());
			}
		}

		inline void SMPPValidator::validateReceiptedMessageId(const std::string& sReceiptedMessageId, const unsigned short){
		}

		inline void SMPPValidator::validateMessageStateTLV(const unsigned char nMessageState, const unsigned short nMessageStateLen){
			// Check the TLV len
			if (nMessageStateLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nMessageStateLen%OptTags::TAG_MESSAGE_STATE).str());
			}

			// Check the value
			if(nMessageState < MessageState::ENROUTE || nMessageState > MessageState::SKIPPED){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_MESSAGE_STATE_VALUE) %nMessageState).str());
			}
		}

		inline void SMPPValidator::validateNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode, const unsigned short nNetworkErrorCodeLen){
			// Check the TLV len
			if (nNetworkErrorCodeLen != SMPPTLVLen::THREE_BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_THREE_BYTE_LEN) %nNetworkErrorCodeLen %OptTags::TAG_NETWORK_ERROR_CODE).str());
			}
		}

		inline void SMPPValidator::validateMsMsgWaitFacilities(const unsigned char nMsMsgWaitFacilities, const unsigned short nMsMsgWaitFacilitiesLen){
			// Check the TLV len
			if (nMsMsgWaitFacilitiesLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nMsMsgWaitFacilitiesLen %OptTags::TAG_MS_MSG_WAIT_FACILITIES).str());
			}
		}

		inline void SMPPValidator::validateNumberOfMessages(const unsigned char nNumberOfMessages, const unsigned short){
		}

		inline void SMPPValidator::validateItsReplyType(const unsigned char nItsReplyType, const unsigned short nItsReplyTypeLen){
			// Check the TLV len
			if (nItsReplyTypeLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nItsReplyTypeLen %OptTags::TAG_ITS_REPLY_TYPE).str());
			}
		}

		inline void SMPPValidator::validateItsSessionInfo(const unsigned short nItsSessionInfo, const unsigned short nItsSessionInfoLen){
			// Check the TLV len
			if (nItsSessionInfoLen != SMPPTLVLen::WORD_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_WORD_LEN) %nItsSessionInfoLen %OptTags::TAG_ITS_SESSION_INFO).str());
			}
		}

		inline void SMPPValidator::validateUserResponseCode(const unsigned char nUserResponseCode, const unsigned short nUserResponseCodeLen){
			// Check the TLV len
			if (nUserResponseCodeLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nUserResponseCodeLen %OptTags::TAG_USER_RESPONSE_CODE).str());
			}
		}

		inline void SMPPValidator::validateDeliveryFailureReason(const unsigned char nDeliveryFailureReason, const unsigned short nDeliveryFailureReasonLen){
			// Check the TLV len
			if (nDeliveryFailureReasonLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nDeliveryFailureReasonLen %OptTags::TAG_DELIVERY_FAILURE_REASON).str());
			}
		}

		inline void SMPPValidator::validateAdditionalStatusInfoText(const std::vector<unsigned char>& aAdditionalStatusInfoText, const unsigned short){
		}

		inline void SMPPValidator::validateDpfResult(const unsigned char nDpfResult, const unsigned short nDpfResultLen){
			// Check the TLV len
			if (nDpfResultLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nDpfResultLen %OptTags::TAG_DPF_RESULT).str());
			}
		}

		inline void SMPPValidator::validateBroadcastEndTime(const std::string& sBroadcastEndTime, const unsigned short){
			// Len should be less than 17
			if(sBroadcastEndTime.size() + 1 > SMPPMaxLen::BROADCAST_END_TIME_MAX_LEN) {
				throw std::logic_error(CodecErrors::VALIDATE_BROADCAST_END_TIME_MAX_LEN);
			}

			// Len should be either 17 or 1
			if((sBroadcastEndTime.size() + 1) != SMPPMaxLen::BROADCAST_END_TIME_MAX_LEN &&
				(sBroadcastEndTime.size() + 1) != 1) {
				throw std::logic_error(CodecErrors::VALIDATE_BROADCAST_END_TIME_RANGE_LEN);
			}
		}

		inline void SMPPValidator::validateUssdServiceOp(const unsigned char nUssdServiceOp, const unsigned short nUssdServiceOpLen){
			// Check the TLV len
			if (nUssdServiceOpLen != SMPPTLVLen::BYTE_LEN){
				throw std::logic_error((boost::format(CodecErrors::VALIDATE_TLV_BYTE_LEN) %nUssdServiceOpLen %OptTags::TAG_USSD_SERVICE_OP).str());
			}
		}

		inline void SMPPValidator::validateShortMessagePayload(const std::vector<unsigned char>& aShortMessage, const std::vector<unsigned char>& aMessagePayload){
			if(aShortMessage.empty() == false && aMessagePayload.empty() == false){
				throw std::logic_error(CodecErrors::VALIDATE_SHORT_MESSAGE_PAYLOAD_LEN);
			}
		}

	}
}
