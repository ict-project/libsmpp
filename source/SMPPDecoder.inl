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

		inline void SMPPDecoder::decodeHeader(Header& oHeader){
			this->decodeUnsigned32(oHeader.refCommandLength());
			this->decodeUnsigned32(oHeader.refCommandId(),oHeader.getCommandLength());
			this->decodeUnsigned32(oHeader.refCommandStatus(),oHeader.getCommandLength());
			this->decodeUnsigned32(oHeader.refSequenceNumber(),oHeader.getCommandLength());
		}

		inline void SMPPDecoder::decodeSystemId(std::string& sSystemId, const unsigned nLimit){
			this->decodeCStringMax(sSystemId, SMPPMaxLen::SYSTEM_ID_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodePassword(std::string& sPassword, const unsigned nLimit){
			this->decodeCStringMax(sPassword, SMPPMaxLen::PASSWORD_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeSystemType(std::string& sSystemType, const unsigned nLimit){
			this->decodeCStringMax(sSystemType, SMPPMaxLen::SYSTEM_TYPE_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeInterfaceVersion(unsigned char& nInterfaceVersion, const unsigned nLimit){
			this->decodeChar(nInterfaceVersion, nLimit);
		}

		inline void SMPPDecoder::decodeAddrTON(unsigned char& nAddrTON, const unsigned nLimit){
			this->decodeChar(nAddrTON, nLimit);
		}

		inline void SMPPDecoder::decodeAddrNPI(unsigned char& nAddrNPI, const unsigned nLimit){
			this->decodeChar(nAddrNPI, nLimit);
		}

		inline void SMPPDecoder::decodeAddressRange(std::string& sAddressRange, const unsigned nLimit){
			this->decodeCStringMax(sAddressRange, SMPPMaxLen::ADDRESS_RANGE_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeServiceType(std::string& sServiceType, const unsigned nLimit){
			this->decodeCStringMax(sServiceType, SMPPMaxLen::SERVICE_TYPE_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeSourceAddrTON(unsigned char& nSourceAddrTON, const unsigned nLimit){
			this->decodeChar(nSourceAddrTON, nLimit);
		}

		inline void SMPPDecoder::decodeSourceAddrNPI(unsigned char& nSourceAddrNPI, const unsigned nLimit){
			this->decodeChar(nSourceAddrNPI, nLimit);
		}

		inline void SMPPDecoder::decodeSourceAddr21(std::string& sSourceAddr, const unsigned nLimit){
			this->decodeCStringMax(sSourceAddr, SMPPMaxLen::SOURCE_ADDR_MAX_LEN_21, nLimit);
		}

		inline void SMPPDecoder::decodeSourceAddr65(std::string& sSourceAddr, const unsigned nLimit){
			this->decodeCStringMax(sSourceAddr, SMPPMaxLen::SOURCE_ADDR_MAX_LEN_65, nLimit);
		}

		inline void SMPPDecoder::decodeDestAddrTON(unsigned char& nDestAddrTON, const unsigned nLimit){
			this->decodeChar(nDestAddrTON, nLimit);
		}

		inline void SMPPDecoder::decodeDestAddrNPI(unsigned char& nDestAddrNPI, const unsigned nLimit){
			this->decodeChar(nDestAddrNPI, nLimit);
		}

		inline void SMPPDecoder::decodeDestAddr21(std::string& sDestAddr, const unsigned nLimit){
			this->decodeCStringMax(sDestAddr, SMPPMaxLen::DESTINATION_ADDR_MAX_LEN_21, nLimit);
		}

		inline void SMPPDecoder::decodeDestAddr65(std::string& sDestAddr, const unsigned nLimit){
			this->decodeCStringMax(sDestAddr, SMPPMaxLen::DESTINATION_ADDR_MAX_LEN_65, nLimit);
		}

		inline void SMPPDecoder::decodeEsmClass(unsigned char& nEsmClass, const unsigned nLimit){
			this->decodeChar(nEsmClass, nLimit);
		}

		inline void SMPPDecoder::decodeProtocolId(unsigned char& nProtocolId, const unsigned nLimit){
			this->decodeChar(nProtocolId, nLimit);
		}

		inline void SMPPDecoder::decodePriorityFlag(unsigned char& nPriorityFlag, const unsigned nLimit){
			this->decodeChar(nPriorityFlag, nLimit);
		}

		inline void SMPPDecoder::decodeScheduleDeliveryTime(std::string& sScheduleDeliveryTime, const unsigned nLimit){
			this->decodeCStringMax(sScheduleDeliveryTime, SMPPMaxLen::SMPP_DATETIME_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeValidityPeriod(std::string& sValidityPeriod, const unsigned nLimit){
			this->decodeCStringMax(sValidityPeriod, SMPPMaxLen::SMPP_DATETIME_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeRegisteredDelivery(unsigned char& nRegisteredDelivery, const unsigned nLimit){
			this->decodeChar(nRegisteredDelivery, nLimit);
		}

		inline void SMPPDecoder::decodeReplaceIfPresentFlag(unsigned char& nReplaceIfPresentFlag, const unsigned nLimit){
			this->decodeChar(nReplaceIfPresentFlag, nLimit);
		}

		inline void SMPPDecoder::decodeDataCoding(unsigned char& nDataCoding, const unsigned nLimit){
			this->decodeChar(nDataCoding, nLimit);
		}

		inline void SMPPDecoder::decodeSMDefaultMsgId(unsigned char& nSMDefaultMsgId, const unsigned nLimit){
			this->decodeChar(nSMDefaultMsgId, nLimit);
		}

		inline void SMPPDecoder::decodeSMLength(unsigned char& nSMLength, const unsigned nLimit){
			this->decodeChar(nSMLength, nLimit);
		}

		inline void SMPPDecoder::decodeShortMessage(std::vector<unsigned char>& aShortMessage, unsigned char& nSMLength, const unsigned nLimit){
			this->decodeBinary(aShortMessage, nSMLength, nLimit);
		}

		inline void SMPPDecoder::decodeMessageId(std::string& sMessageId, const unsigned nLimit){
			this->decodeCStringMax(sMessageId, SMPPMaxLen::MESSAGE_ID_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeESMEAddrTON(unsigned char& nESMEAddrTON, const unsigned nLimit){
			this->decodeChar(nESMEAddrTON, nLimit);
		}

		inline void SMPPDecoder::decodeESMEAddrNPI(unsigned char& nESMEAddrNPI, const unsigned nLimit){
			this->decodeChar(nESMEAddrNPI, nLimit);
		}

		inline void SMPPDecoder::decodeESMEAddr(std::string& sESMEAddr, const unsigned nLimit){
			this->decodeCStringMax(sESMEAddr, SMPPMaxLen::ESME_ADDR_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeNumberOfDest(unsigned char& nNumberOfDest, const unsigned nLimit){
			this->decodeChar(nNumberOfDest, nLimit);
		}

		inline void SMPPDecoder::decodeDestAddresses(std::vector<DestAddress>& aDestAddresses, const char nNumberOfDests, const unsigned nLimit){
			aDestAddresses.resize(nNumberOfDests);
			for(unsigned i = 0; i < aDestAddresses.size(); ++i){
				this->decodeChar(aDestAddresses[i].refDestFlag());
				if(aDestAddresses[i].getDestFlag() == DestFlag::SME_ADDRESS){
					this->decodeChar(aDestAddresses[i].refAddress().refTON(), nLimit);
					this->decodeChar(aDestAddresses[i].refAddress().refNPI(), nLimit);
					this->decodeCStringMax(aDestAddresses[i].refAddress().refAddress(), SMPPMaxLen::DESTINATION_ADDR_MAX_LEN_21, nLimit);

				} else if(aDestAddresses[i].getDestFlag() == DestFlag::DISTR_LIST_NAME){
					this->decodeCStringMax(aDestAddresses[i].refDistrListName(), SMPPMaxLen::DL_NAME_MAX_LEN, nLimit);

				} else {
					throw std::logic_error((boost::format(CodecErrors::DECODER_INV_DSTFLAG) %m_nOffset %aDestAddresses[i].getDestFlag()).str());
				}
			}
		}

		inline void SMPPDecoder::decodeNoUnsuccess(unsigned char& nNoUnsuccess, const unsigned nLimit){
			this->decodeChar(nNoUnsuccess, nLimit);
		}

		inline void SMPPDecoder::decodeUnsuccessSMEs(std::vector<UnsuccessSME>& aUnsuccessSMEs, const char nNoUnsuccess, const unsigned nLimit){
			aUnsuccessSMEs.resize(nNoUnsuccess);
			for(unsigned i = 0; i < aUnsuccessSMEs.size(); ++i){
				this->decodeChar(aUnsuccessSMEs[i].refSMEAddress().refTON(), nLimit);
				this->decodeChar(aUnsuccessSMEs[i].refSMEAddress().refNPI(), nLimit);
				this->decodeCStringMax(aUnsuccessSMEs[i].refSMEAddress().refAddress(), SMPPMaxLen::DESTINATION_ADDR_MAX_LEN_21, nLimit);
				this->decodeUnsigned32(aUnsuccessSMEs[i].refErrorStatusCode(), nLimit);
			}
		}

		inline void SMPPDecoder::decodeFinalDate(std::string& sFinalDate, const unsigned nLimit){
			this->decodeCStringMax(sFinalDate, SMPPMaxLen::SMPP_DATETIME_MAX_LEN, nLimit);
		}

		inline void SMPPDecoder::decodeMessageState(unsigned char& nMessageState, const unsigned nLimit){
			this->decodeChar(nMessageState, nLimit);
		}

		inline void SMPPDecoder::decodeErrorCode(unsigned char& nErrorCode, const unsigned nLimit){
			this->decodeChar(nErrorCode, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastAreaIdentifier(BroadcastAreaIdentifier& oBroadcastAreaIdentifier, unsigned short& nBroadcastAreaIdentifierLen, const unsigned nLimit){
			this->decodeTLV(oBroadcastAreaIdentifier.refValue(), nBroadcastAreaIdentifierLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastAreaIdentifier(std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, std::vector<unsigned short>& aBroadcastAreaIdentifierLen, const unsigned nLimit){
			unsigned short nLen = 0;
			BroadcastAreaIdentifier oBroadcastAreaIdentifier;
			this->decodeBroadcastAreaIdentifier(oBroadcastAreaIdentifier, nLen, nLimit);

			aBroadcastAreaIdentifierLen.push_back(nLen);
			aBroadcastAreaIdentifier.push_back(oBroadcastAreaIdentifier);
		}

		inline void SMPPDecoder::decodeBroadcastRepNum(unsigned short& nBroadcastRepNum, unsigned short& nBroadcastRepNumLen, const unsigned nLimit){
			this->decodeTLV(nBroadcastRepNum, nBroadcastRepNumLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastFrequencyInterval(std::vector<unsigned char>& aBroadcastFrequencyInterval, unsigned short& nBroadcastFrequencyIntervalLen, const unsigned nLimit){
			this->decodeTLV(aBroadcastFrequencyInterval, nBroadcastFrequencyIntervalLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastAreaSuccess(unsigned char& nBroadcastAreaSuccess, unsigned short& nBroadcastAreaSuccessLen, const unsigned nLimit){
			this->decodeTLV(nBroadcastAreaSuccess, nBroadcastAreaSuccessLen, nLimit);
		}

		inline void SMPPDecoder::decodeScInterfaceVersion(unsigned char& nScInterfaceVersion, unsigned short& nScInterfaceVersionLen, const unsigned nLimit){
			this->decodeTLV(nScInterfaceVersion, nScInterfaceVersionLen, nLimit);

		}

		inline void SMPPDecoder::decodeMSAvailabilityStatus(unsigned char& nMSAvailabilityStatus, unsigned short& nMSAvailabilityStatusLen, const unsigned nLimit){
			this->decodeTLV(nMSAvailabilityStatus, nMSAvailabilityStatusLen, nLimit);
		}

		inline void SMPPDecoder::decodeAlertOnMsgDelivery(unsigned char& nAlertOnMsgDelivery, unsigned short& nAlertOnMsgDeliveryLen, const unsigned nLimit){
			this->decodeTLV(nAlertOnMsgDelivery, nAlertOnMsgDeliveryLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastChannelIndicator(unsigned char& nBroadcastChannelIndicator, unsigned short& nBroadcastChannelIndicatorLen, const unsigned nLimit){
			this->decodeTLV(nBroadcastChannelIndicator, nBroadcastChannelIndicatorLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastContentTypeInfo(std::vector<unsigned char>& aBroadcastContentTypeInfo, unsigned short& nBroadcastContentTypeInfoLen, const unsigned nLimit){
			this->decodeTLV(aBroadcastContentTypeInfo, nBroadcastContentTypeInfoLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastMessageClass(unsigned char& nBroadcastMessageClass, unsigned short& nBroadcastMessageClassLen, const unsigned nLimit){
			this->decodeTLV(nBroadcastMessageClass, nBroadcastMessageClassLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastServiceGroup(std::vector<unsigned char>& aBroadcastServiceGroup, unsigned short& nBroadcastServiceGroupLen, const unsigned nLimit){
			this->decodeTLV(aBroadcastServiceGroup, nBroadcastServiceGroupLen, nLimit);
		}

		inline void SMPPDecoder::decodeCallbackNum(std::vector<unsigned char>& aCallbackNum, unsigned short& nCallbackNumLen, const unsigned nLimit){
			this->decodeTLV(aCallbackNum, nCallbackNumLen, nLimit);
		}

		inline void SMPPDecoder::decodeCallbackNumAtag(std::vector<unsigned char>& aCallbackNumAtag, unsigned short& nCallbackNumAtagLen, const unsigned nLimit){
			this->decodeTLV(aCallbackNumAtag, nCallbackNumAtagLen, nLimit);
		}

		inline void SMPPDecoder::decodeCallbackNumPresInd(unsigned char& nCallbackNumPresInd, unsigned short& nCallbackNumPresIndLen, const unsigned nLimit){
			this->decodeTLV(nCallbackNumPresInd, nCallbackNumPresIndLen, nLimit);
		}

		inline void SMPPDecoder::decodeDestAddrSubunit(unsigned char& nDestAddrSubunit, unsigned short& nDestAddrSubunitLen, const unsigned nLimit){
			this->decodeTLV(nDestAddrSubunit, nDestAddrSubunitLen, nLimit);
		}

		inline void SMPPDecoder::decodeDestSubaddress(std::vector<unsigned char>& aDestSubaddress, unsigned short& nDestSubaddressLen, const unsigned nLimit){
			this->decodeTLV(aDestSubaddress, nDestSubaddressLen, nLimit);
		}

		inline void SMPPDecoder::decodeDisplayTime(unsigned char& nDisplayTime, unsigned short& nDisplayTimeLen, const unsigned nLimit){
			this->decodeTLV(nDisplayTime, nDisplayTimeLen, nLimit);
		}

		inline void SMPPDecoder::decodeLanguageIndicator(unsigned char& nLanguageIndicator, unsigned short& nLanguageIndicatorLen, const unsigned nLimit){
			this->decodeTLV(nLanguageIndicator, nLanguageIndicatorLen, nLimit);
		}

		inline void SMPPDecoder::decodeMessagePayload(std::vector<unsigned char>& aMessagePayload, unsigned short& nMessagePayloadLen, const unsigned nLimit){
			this->decodeTLV(aMessagePayload, nMessagePayloadLen, nLimit);
		}

		inline void SMPPDecoder::decodeMsValidity(unsigned char& nMsValidity, unsigned short& nMsValidityLen, const unsigned nLimit){
			this->decodeTLV(nMsValidity, nMsValidityLen, nLimit);
		}

		inline void SMPPDecoder::decodePayloadType(unsigned char& nPayloadType, unsigned short& nPayloadTypeLen, const unsigned nLimit){
			this->decodeTLV(nPayloadType, nPayloadTypeLen, nLimit);
		}

		inline void SMPPDecoder::decodePrivacyIndicator(unsigned char& nPrivacyIndicator, unsigned short& nPrivacyIndicatorLen, const unsigned nLimit){
			this->decodeTLV(nPrivacyIndicator, nPrivacyIndicatorLen, nLimit);
		}

		inline void SMPPDecoder::decodeSmsSignal(unsigned short& nSmsSignal, unsigned short& nSmsSignalLen, const unsigned nLimit){
			this->decodeTLV(nSmsSignal, nSmsSignalLen, nLimit);
		}

		inline void SMPPDecoder::decodeSourceAddrSubunit(unsigned char& nSourceAddrSubunit, unsigned short& nSourceAddrSubunitLen, const unsigned nLimit){
			this->decodeTLV(nSourceAddrSubunit, nSourceAddrSubunitLen, nLimit);
		}

		inline void SMPPDecoder::decodeSourcePort(unsigned short& nSourcePort, unsigned short& nSourcePortLen, const unsigned nLimit){
			this->decodeTLV(nSourcePort, nSourcePortLen, nLimit);
		}

		inline void SMPPDecoder::decodeSourceSubaddress(std::vector<unsigned char>& aSourceSubaddress, unsigned short& nSourceSubaddressLen, const unsigned nLimit){
			this->decodeTLV(aSourceSubaddress, nSourceSubaddressLen, nLimit);
		}

		inline void SMPPDecoder::decodeUserMessageReference(unsigned short& nUserMessageReference, unsigned short& nUserMessageReferenceLen, const unsigned nLimit){
			this->decodeTLV(nUserMessageReference, nUserMessageReferenceLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastErrorStatus(unsigned& nBroadcastErrorStatus, unsigned short& nBroadcastErrorStatusLen, const unsigned nLimit){
			this->decodeTLV(nBroadcastErrorStatus, nBroadcastErrorStatusLen, nLimit);
		}

		inline void SMPPDecoder::decodeFailedBroadcastAreaIdentifier(std::vector<BroadcastAreaIdentifier>& aFailedBroadcastAreaIdentifier, std::vector<unsigned short>& aFailedBroadcastAreaIdentifierLen, const unsigned nLimit){
			unsigned short nLen = 0;
			BroadcastAreaIdentifier oBroadcastAreaIdentifier;
			this->decodeBroadcastAreaIdentifier(oBroadcastAreaIdentifier, nLen, nLimit);

			aFailedBroadcastAreaIdentifierLen.push_back(nLen);
			aFailedBroadcastAreaIdentifier.push_back(oBroadcastAreaIdentifier);

		}

		inline void SMPPDecoder::decodeBroadcastContentType(std::vector<unsigned char>& aBroadcastContentType, unsigned short& nBroadcastContentTypeLen, const unsigned nLimit){
			this->decodeTLV(aBroadcastContentType, nBroadcastContentTypeLen, nLimit);
		}

		inline void SMPPDecoder::decodeSourceNetworkType(unsigned char& nSourceNetworkType, unsigned short& nSourceNetworkTypeLen, const unsigned nLimit){
			this->decodeTLV(nSourceNetworkType, nSourceNetworkTypeLen, nLimit);
		}

		inline void SMPPDecoder::decodeSourceBearerType(unsigned char& nSourceBearerType, unsigned short& nSourceBearerTypeLen, const unsigned nLimit){
			this->decodeTLV(nSourceBearerType, nSourceBearerTypeLen, nLimit);
		}

		inline void SMPPDecoder::decodeSourceTelematicsId(unsigned char& nSourceTelematicsId, unsigned short& nSourceTelematicsIdLen, const unsigned nLimit){
			this->decodeTLV(nSourceTelematicsId, nSourceTelematicsIdLen, nLimit);
		}

		inline void SMPPDecoder::decodeDestinationPort(unsigned short& nDestinationPort, unsigned short& nDestinationPortLen, const unsigned nLimit){
			this->decodeTLV(nDestinationPort, nDestinationPortLen, nLimit);
		}

		inline void SMPPDecoder::decodeDestNetworkType(unsigned char& nDestNetworkType, unsigned short& nDestNetworkTypeLen, const unsigned nLimit){
			this->decodeTLV(nDestNetworkType, nDestNetworkTypeLen, nLimit);
		}

		inline void SMPPDecoder::decodeDestBearerType(unsigned char& nDestBearerType, unsigned short& nDestBearerTypeLen, const unsigned nLimit){
			this->decodeTLV(nDestBearerType, nDestBearerTypeLen, nLimit);
		}

		inline void SMPPDecoder::decodeDestTelematicsId(unsigned char& nDestTelematicsId, unsigned short& nDestTelematicsIdLen, const unsigned nLimit){
			this->decodeTLV(nDestTelematicsId, nDestTelematicsIdLen, nLimit);
		}

		inline void SMPPDecoder::decodeSarMsgRefNum(unsigned short& nSarMsgRefNum, unsigned short& nSarMsgRefNumLen, const unsigned nLimit){
			this->decodeTLV(nSarMsgRefNum, nSarMsgRefNumLen, nLimit);
		}

		inline void SMPPDecoder::decodeSarTotalSegments(unsigned char& nSarTotalSegments, unsigned short& nSarTotalSegmentsLen, const unsigned nLimit){
			this->decodeTLV(nSarTotalSegments, nSarTotalSegmentsLen, nLimit);
		}

		inline void SMPPDecoder::decodeSarSegmentSeqnum(unsigned char& nSarSegmentSeqnum, unsigned short& nSarSegmentSeqnumLen, const unsigned nLimit){
			this->decodeTLV(nSarSegmentSeqnum, nSarSegmentSeqnumLen, nLimit);
		}

		inline void SMPPDecoder::decodeMoreMessagesToSend(unsigned char& nMoreMessagesToSend, unsigned short& nMoreMessagesToSendLen, const unsigned nLimit){
			this->decodeTLV(nMoreMessagesToSend, nMoreMessagesToSendLen, nLimit);
		}

		inline void SMPPDecoder::decodeQosTimeToLive(unsigned& nQosTimeToLive, unsigned short& nQosTimeToLiveLen, const unsigned nLimit){
			this->decodeTLV(nQosTimeToLive, nQosTimeToLiveLen, nLimit);
		}

		inline void SMPPDecoder::decodeSetDpf(unsigned char& nSetDpf, unsigned short& nSetDpfLen, const unsigned nLimit){
			this->decodeTLV(nSetDpf, nSetDpfLen, nLimit);
		}

		inline void SMPPDecoder::decodeReceiptedMessageId(std::string& sReceiptedMessageId, unsigned short& nReceiptedMessageIdLen, const unsigned nLimit){
			this->decodeTLV(sReceiptedMessageId, nReceiptedMessageIdLen, nLimit);
		}

		inline void SMPPDecoder::decodeMessageStateTLV(unsigned char& nMessageState, unsigned short& nMessageStateLen, const unsigned nLimit){
			this->decodeTLV(nMessageState, nMessageStateLen, nLimit);
		}

		inline void SMPPDecoder::decodeNetworkErrorCode(NetworkErrorCode& oNetworkErrorCode, unsigned short& nNetworkErrorCodeLen, const unsigned nLimit){
			this->skipNBytes(SMPPOffset::TLV_TAG_LENGHT);
			this->decodeUnsigned16(nNetworkErrorCodeLen);
			this->decodeChar(oNetworkErrorCode.refNetworkCode());
			this->decodeUnsigned16(oNetworkErrorCode.refErrorCode());
		}

		inline void SMPPDecoder::decodeMsMsgWaitFacilities(unsigned char& nMsMsgWaitFacilities, unsigned short& nMsMsgWaitFacilitiesLen, const unsigned nLimit){
			this->decodeTLV(nMsMsgWaitFacilities, nMsMsgWaitFacilitiesLen, nLimit);
		}

		inline void SMPPDecoder::decodeNumberOfMessages(unsigned char& nNumberOfMessages, unsigned short& nNumberOfMessagesLen, const unsigned nLimit){
			this->decodeTLV(nNumberOfMessages, nNumberOfMessagesLen, nLimit);
		}

		inline void SMPPDecoder::decodeItsReplyType(unsigned char& nItsReplyType, unsigned short& nItsReplyTypeLen, const unsigned nLimit){
			this->decodeTLV(nItsReplyType, nItsReplyTypeLen, nLimit);
		}

		inline void SMPPDecoder::decodeItsSessionInfo(unsigned short& nItsSessionInfo, unsigned short& nItsSessionInfoLen, const unsigned nLimit){
			this->decodeTLV(nItsSessionInfo, nItsSessionInfoLen, nLimit);
		}

		inline void SMPPDecoder::decodeUserResponseCode(unsigned char& nUserResponseCode, unsigned short& nUserResponseCodeLen, const unsigned nLimit){
			this->decodeTLV(nUserResponseCode, nUserResponseCodeLen, nLimit);
		}

		inline void SMPPDecoder::decodeDeliveryFailureReason(unsigned char& nDeliveryFailureReason, unsigned short& nDeliveryFailureReasonLen, const unsigned nLimit){
			this->decodeTLV(nDeliveryFailureReason, nDeliveryFailureReasonLen, nLimit);
		}

		inline void SMPPDecoder::decodeAdditionalStatusInfoText(std::vector<unsigned char>& aAdditionalStatusInfoText, unsigned short& nAdditionalStatusInfoTextLen, const unsigned nLimit){
			this->decodeTLV(aAdditionalStatusInfoText, nAdditionalStatusInfoTextLen, nLimit);
		}

		inline void SMPPDecoder::decodeDpfResult(unsigned char& nDpfResult, unsigned short& nDpfResultLen, const unsigned nLimit){
			this->decodeTLV(nDpfResult, nDpfResultLen, nLimit);
		}

		inline void SMPPDecoder::decodeBroadcastEndTime(std::string& sBroadcastEndTime, unsigned short& nBroadcastEndTimeLen, const unsigned nLimit){
			this->decodeTLV(sBroadcastEndTime, nBroadcastEndTimeLen, nLimit);
		}

		inline void SMPPDecoder::decodeUssdServiceOp(unsigned char& nUssdServiceOp, unsigned short& nUssdServiceOpLen, const unsigned nLimit){
			this->decodeTLV(nUssdServiceOp, nUssdServiceOpLen, nLimit);
		}

	}
}
