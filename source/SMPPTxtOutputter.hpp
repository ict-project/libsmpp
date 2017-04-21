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

#ifndef SMPPTXTOUTPUTTER_HPP
#define SMPPTXTOUTPUTTER_HPP

#include "TextOutputter.hpp"
#include "SMPPOutputterBase.hpp"


namespace anthill {
	namespace smpp {


		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPTxtOutputter : public SMPPOutputterBase, public anthill::TextOutputter{

		public:
			SMPPTxtOutputter(std::ostream&);
			SMPPTxtOutputter(std::ostream&, const bool bShowHex);
			SMPPTxtOutputter(std::ostream&, const bool bShowHex, const bool bShowEsm);
			SMPPTxtOutputter(std::ostream&, const bool bShowHex, const bool bShowEsm, const bool bShowFmt);
			virtual ~SMPPTxtOutputter();

			/**
			 * A methods to output header
			 */
			virtual void outputHeader(const Header& oHeader);
			/**
			 * A methods to output mandatory fields
			 */
			virtual void outputSystemId(const std::string&);
			virtual void outputPassword(const std::string&);
			virtual void outputSystemType(const std::string&);
			virtual void outputInterfaceVersion(const unsigned char);
			virtual void outputAddrTON(const unsigned char);
			virtual void outputAddrNPI(const unsigned char);
			virtual void outputAddressRange(const std::string&);
			virtual void outputServiceType(const std::string&);
			virtual void outputSourceAddrTON(const unsigned char);
			virtual void outputSourceAddrNPI(const unsigned char);
			virtual void outputSourceAddr21(const std::string&);
			virtual void outputSourceAddr65(const std::string&);
			virtual void outputDestAddrTON(const unsigned char);
			virtual void outputDestAddrNPI(const unsigned char);
			virtual void outputDestAddr21(const std::string&);
			virtual void outputDestAddr65(const std::string&);
			virtual void outputEsmClass(const unsigned char);
			virtual void outputProtocolId(const unsigned char);
			virtual void outputPriorityFlag(const unsigned char);
			virtual void outputScheduleDeliveryTime(const std::string&);
			virtual void outputValidityPeriod(const std::string&);
			virtual void outputRegisteredDelivery(const unsigned char);
			virtual void outputReplaceIfPresentFlag(const unsigned char);
			virtual void outputDataCoding(const unsigned char);
			virtual void outputSMDefaultMsgId(const unsigned char);
			virtual void outputSMLength(const unsigned char);
			virtual void outputShortMessage(std::vector<unsigned char>&);
			virtual void outputMessageId(const std::string&);
			virtual void outputESMEAddrTON(const unsigned char);
			virtual void outputESMEAddrNPI(const unsigned char);
			virtual void outputESMEAddr(const std::string&);
			virtual void outputNumberOfDest(const unsigned char);
			virtual void outputDestAddresses(const std::vector<DestAddress>&);
			virtual void outputNoUnsuccess(const unsigned char);
			virtual void outputUnsuccessSMEs(const std::vector<UnsuccessSME>&);
			virtual void outputFinalDate(const std::string&);
			virtual void outputMessageState(const unsigned char);
			virtual void outputErrorCode(const unsigned char);
			virtual void outputMessageStateTLV(const unsigned char, const unsigned short);
			virtual void outputBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&);
			virtual void outputBroadcastRepNum(const unsigned short, const unsigned short);
			virtual void outputBroadcastFrequencyInterval(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputBroadcastContentType(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputBroadcastAreaSuccess(const unsigned char, const unsigned short);
			

			/**
			 * A methods to output optional fields
			 */
			virtual void outputScInterfaceVersion(const unsigned char, const unsigned short);
			virtual void outputMSAvailabilityStatus(const unsigned char, const unsigned short);
			virtual void outputAlertOnMsgDelivery(const unsigned char, const unsigned short);
			virtual void outputBroadcastChannelIndicator(const unsigned char, const unsigned short);
			virtual void outputBroadcastContentTypeInfo(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputBroadcastMessageClass(const unsigned char, const unsigned short);
			virtual void outputBroadcastServiceGroup(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputCallbackNum(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputCallbackNumAtag(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputCallbackNumPresInd(const unsigned char, const unsigned short);
			virtual void outputDestAddrSubunit(const unsigned char, const unsigned short);
			virtual void outputDestSubaddress(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputDisplayTime(const unsigned char, const unsigned short);
			virtual void outputLanguageIndicator(const unsigned char, const unsigned short);
			virtual void outputMessagePayload(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputMsValidity(const unsigned char, const unsigned short);
			virtual void outputPayloadType(const unsigned char, const unsigned short);
			virtual void outputPrivacyIndicator(const unsigned char, const unsigned short);
			virtual void outputSmsSignal(const unsigned short, const unsigned short);
			virtual void outputSourceAddrSubunit(const unsigned char, const unsigned short);
			virtual void outputSourcePort(const unsigned short, const unsigned short);
			virtual void outputSourceSubaddress(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputUserMessageReference(const unsigned short, const unsigned short);
			virtual void outputBroadcastErrorStatus(const unsigned char, const unsigned short);
			virtual void outputFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&);
			virtual void outputBroadcastContentTypeOpt(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputSourceNetworkType(const unsigned char, const unsigned short);
			virtual void outputSourceBearerType(const unsigned char, const unsigned short);
			virtual void outputSourceTelematicsId(const unsigned char, const unsigned short);
			virtual void outputDestinationPort(const unsigned short, const unsigned short);
			virtual void outputDestNetworkType(const unsigned char, const unsigned short);
			virtual void outputDestBearerType(const unsigned char, const unsigned short);
			virtual void outputDestTelematicsId(const unsigned char, const unsigned short);
			virtual void outputSarMsgRefNum(const unsigned short, const unsigned short);
			virtual void outputSarTotalSegments(const unsigned char, const unsigned short);
			virtual void outputSarSegmentSeqnum(const unsigned char, const unsigned short);
			virtual void outputMoreMessagesToSend(const unsigned char, const unsigned short);
			virtual void outputQosTimeToLive(const unsigned, const unsigned short);
			virtual void outputSetDpf(const unsigned char, const unsigned short);
			virtual void outputReceiptedMessageId(const std::string&, const unsigned short);
			virtual void outputMessageStateTLVOpt(const unsigned char, const unsigned short);
			virtual void outputNetworkErrorCode(const NetworkErrorCode&, const unsigned short);
			virtual void outputMsMsgWaitFacilities(const unsigned char, const unsigned short);
			virtual void outputNumberOfMessages(const unsigned char, const unsigned short);
			virtual void outputItsReplyType(const unsigned char, const unsigned short);
			virtual void outputItsSessionInfo(const unsigned short, const unsigned short);
			virtual void outputUserResponseCode(const unsigned char, const unsigned short);
			virtual void outputDeliveryFailureReason(const unsigned char, const unsigned short);
			virtual void outputAdditionalStatusInfoText(const std::vector<unsigned char>&, const unsigned short);
			virtual void outputDpfResult(const unsigned char, const unsigned short);
			virtual void outputBroadcastEndTime(const std::string&, const unsigned short);
			virtual void outputUssdServiceOp(const unsigned char, const unsigned short);
		protected:
			bool m_bShowHeximal;
			bool m_bShowEsminfo;
			bool m_bShowFmtinfo;
		};
	}
}

#endif // SMPPTXTOUTPUTTER_HPP
