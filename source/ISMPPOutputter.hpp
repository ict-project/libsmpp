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

#ifndef ISMPPOUTPUTTER_HPP
#define ISMPPOUTPUTTER_HPP

#include "SMPPStructures.hpp"
#include "SMPPDatatypes.hpp"

namespace anthill {
	namespace smpp {


		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX ISMPPOutputter {
		public:
			typedef boost::shared_ptr<ISMPPOutputter> SharedPtr;

		public:
			virtual ~ISMPPOutputter() {};

			/**
			 * A methods to output header
			 */
			virtual void outputHeader(const Header& oHeader) = 0;
			/**
			 * A methods to output mandatory fields
			 */
			virtual void outputSystemId(const std::string&) = 0;
			virtual void outputPassword(const std::string&) = 0;
			virtual void outputSystemType(const std::string&) = 0;
			virtual void outputInterfaceVersion(const unsigned char) = 0;
			virtual void outputAddrTON(const unsigned char) = 0;
			virtual void outputAddrNPI(const unsigned char) = 0;
			virtual void outputAddressRange(const std::string&) = 0;
			virtual void outputServiceType(const std::string&) = 0;
			virtual void outputSourceAddrTON(const unsigned char) = 0;
			virtual void outputSourceAddrNPI(const unsigned char) = 0;
			virtual void outputSourceAddr21(const std::string&) = 0;
			virtual void outputSourceAddr65(const std::string&) = 0;
			virtual void outputDestAddrTON(const unsigned char) = 0;
			virtual void outputDestAddrNPI(const unsigned char) = 0;
			virtual void outputDestAddr21(const std::string&) = 0;
			virtual void outputDestAddr65(const std::string&) = 0;
			virtual void outputEsmClass(const unsigned char) = 0;
			virtual void outputProtocolId(const unsigned char) = 0;
			virtual void outputPriorityFlag(const unsigned char) = 0;
			virtual void outputScheduleDeliveryTime(const std::string&) = 0;
			virtual void outputValidityPeriod(const std::string&) = 0;
			virtual void outputRegisteredDelivery(const unsigned char) = 0;
			virtual void outputReplaceIfPresentFlag(const unsigned char) = 0;
			virtual void outputDataCoding(const unsigned char) = 0;
			virtual void outputSMDefaultMsgId(const unsigned char) = 0;
			virtual void outputSMLength(const unsigned char) = 0;
			virtual void outputShortMessage(std::vector<unsigned char>&) = 0;
			virtual void outputMessageId(const std::string&) = 0;
			virtual void outputESMEAddrTON(const unsigned char) = 0;
			virtual void outputESMEAddrNPI(const unsigned char) = 0;
			virtual void outputESMEAddr(const std::string&) = 0;
			virtual void outputNumberOfDest(const unsigned char) = 0;
			virtual void outputDestAddresses(const std::vector<DestAddress>&) = 0;
			virtual void outputNoUnsuccess(const unsigned char) = 0;
			virtual void outputUnsuccessSMEs(const std::vector<UnsuccessSME>&) = 0;
			virtual void outputFinalDate(const std::string&) = 0;
			virtual void outputMessageState(const unsigned char) = 0;
			virtual void outputErrorCode(const unsigned char) = 0;
			virtual void outputMessageStateTLV(const unsigned char, const unsigned short) = 0;
			virtual void outputBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&) = 0;
			virtual void outputBroadcastRepNum(const unsigned short, const unsigned short) = 0;
			virtual void outputBroadcastFrequencyInterval(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputBroadcastContentType(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputBroadcastAreaSuccess(const unsigned char, const unsigned short) = 0;
			

			/**
			 * A methods to output optional fields
			 */
			virtual void outputScInterfaceVersion(const unsigned char, const unsigned short) = 0;
			virtual void outputMSAvailabilityStatus(const unsigned char, const unsigned short) = 0;
			virtual void outputAlertOnMsgDelivery(const unsigned char, const unsigned short) = 0;
			virtual void outputBroadcastChannelIndicator(const unsigned char, const unsigned short) = 0;
			virtual void outputBroadcastContentTypeInfo(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputBroadcastMessageClass(const unsigned char, const unsigned short) = 0;
			virtual void outputBroadcastServiceGroup(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputCallbackNum(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputCallbackNumAtag(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputCallbackNumPresInd(const unsigned char, const unsigned short) = 0;
			virtual void outputDestAddrSubunit(const unsigned char, const unsigned short) = 0;
			virtual void outputDestSubaddress(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputDisplayTime(const unsigned char, const unsigned short) = 0;
			virtual void outputLanguageIndicator(const unsigned char, const unsigned short) = 0;
			virtual void outputMessagePayload(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputMsValidity(const unsigned char, const unsigned short) = 0;
			virtual void outputPayloadType(const unsigned char, const unsigned short) = 0;
			virtual void outputPrivacyIndicator(const unsigned char, const unsigned short) = 0;
			virtual void outputSmsSignal(const unsigned short, const unsigned short) = 0;
			virtual void outputSourceAddrSubunit(const unsigned char, const unsigned short) = 0;
			virtual void outputSourcePort(const unsigned short, const unsigned short) = 0;
			virtual void outputSourceSubaddress(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputUserMessageReference(const unsigned short, const unsigned short) = 0;
			virtual void outputBroadcastErrorStatus(const unsigned char, const unsigned short) = 0;
			virtual void outputFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&) = 0;
			virtual void outputBroadcastContentTypeOpt(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputSourceNetworkType(const unsigned char, const unsigned short) = 0;
			virtual void outputSourceBearerType(const unsigned char, const unsigned short) = 0;
			virtual void outputSourceTelematicsId(const unsigned char, const unsigned short) = 0;
			virtual void outputDestinationPort(const unsigned short, const unsigned short) = 0;
			virtual void outputDestNetworkType(const unsigned char, const unsigned short) = 0;
			virtual void outputDestBearerType(const unsigned char, const unsigned short) = 0;
			virtual void outputDestTelematicsId(const unsigned char, const unsigned short) = 0;
			virtual void outputSarMsgRefNum(const unsigned short, const unsigned short) = 0;
			virtual void outputSarTotalSegments(const unsigned char, const unsigned short) = 0;
			virtual void outputSarSegmentSeqnum(const unsigned char, const unsigned short) = 0;
			virtual void outputMoreMessagesToSend(const unsigned char, const unsigned short) = 0;
			virtual void outputQosTimeToLive(const unsigned, const unsigned short) = 0;
			virtual void outputSetDpf(const unsigned char, const unsigned short) = 0;
			virtual void outputReceiptedMessageId(const std::string&, const unsigned short) = 0;
			virtual void outputMessageStateTLVOpt(const unsigned char, const unsigned short) = 0;
			virtual void outputNetworkErrorCode(const NetworkErrorCode&, const unsigned short) = 0;
			virtual void outputMsMsgWaitFacilities(const unsigned char, const unsigned short) = 0;
			virtual void outputNumberOfMessages(const unsigned char, const unsigned short) = 0;
			virtual void outputItsReplyType(const unsigned char, const unsigned short) = 0;
			virtual void outputItsSessionInfo(const unsigned short, const unsigned short) = 0;
			virtual void outputUserResponseCode(const unsigned char, const unsigned short) = 0;
			virtual void outputDeliveryFailureReason(const unsigned char, const unsigned short) = 0;
			virtual void outputAdditionalStatusInfoText(const std::vector<unsigned char>&, const unsigned short) = 0;
			virtual void outputDpfResult(const unsigned char, const unsigned short) = 0;
			virtual void outputBroadcastEndTime(const std::string&, const unsigned short) = 0;
			virtual void outputUssdServiceOp(const unsigned char, const unsigned short) = 0;

		};
	}
}

#endif // ISMPPOUTPUTTER_HPP
