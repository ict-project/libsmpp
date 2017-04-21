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

#ifndef SMPPENCODER_HPP
#define SMPPENCODER_HPP

#include "BinaryEncoder.hpp"
#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {


		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPEncoder : public anthill::BinaryEncoder{
		public:
			SMPPEncoder(void);
			virtual ~SMPPEncoder(void);
		public:
			void encodeCommandLength(void);
			std::vector<unsigned char>& encodePacket(SMPPPDU* poPDU);

		public:
			/**
			 * A methods to encode header and 
			 */
			inline void encodeHeader(const Header& oHeader);
			/**
			 * A methods to encode data
			 */
			inline void encodeSystemId(const std::string&);
			inline void encodePassword(const std::string&);
			inline void encodeSystemType(const std::string&);
			inline void encodeInterfaceVersion(const unsigned char);
			inline void encodeAddrTON(const unsigned char);
			inline void encodeAddrNPI(const unsigned char);
			inline void encodeAddressRange(const std::string&);
			inline void encodeServiceType(const std::string&);
			inline void encodeSourceAddrTON(const unsigned char);
			inline void encodeSourceAddrNPI(const unsigned char);
			inline void encodeSourceAddr21(const std::string&);
			inline void encodeSourceAddr65(const std::string&);
			inline void encodeDestAddrTON(const unsigned char);
			inline void encodeDestAddrNPI(const unsigned char);
			inline void encodeDestAddr21(const std::string&);
			inline void encodeDestAddr65(const std::string&);
			inline void encodeEsmClass(const unsigned char);
			inline void encodeProtocolId(const unsigned char);
			inline void encodePriorityFlag(const unsigned char);
			inline void encodeScheduleDeliveryTime(const std::string&);
			inline void encodeValidityPeriod(const std::string&);
			inline void encodeRegisteredDelivery(const unsigned char);
			inline void encodeReplaceIfPresentFlag(const unsigned char);
			inline void encodeDataCoding(const unsigned char);
			inline void encodeSMDefaultMsgId(const unsigned char);
			inline void encodeSMLength(const unsigned char);
			inline void encodeShortMessage(const std::vector<unsigned char>&);
			inline void encodeMessageId(const std::string&);
			inline void encodeESMEAddrTON(const unsigned char);
			inline void encodeESMEAddrNPI(const unsigned char);
			inline void encodeESMEAddr(const std::string&);
			inline void encodeNumberOfDest(const unsigned char);
			inline void encodeDestAddresses(const std::vector<DestAddress>&);
			inline void encodeNoUnsuccess(const unsigned char);
			inline void encodeUnsuccessSMEs(const std::vector<UnsuccessSME>&);
			inline void encodeFinalDate(const std::string&);
			inline void encodeErrorCode(const unsigned char);
			inline void encodeMessageState(const unsigned char);
			inline void encodeBroadcastAreaIdentifier(const BroadcastAreaIdentifier&, const unsigned short);
			inline void encodeBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&);
			inline void encodeBroadcastRepNum(unsigned short, const unsigned short);
			inline void encodeBroadcastFrequencyInterval(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeBroadcastAreaSuccess(unsigned char, const unsigned short);

			/**
			 * A methods to encode TLV
			 */
			inline void encodeScInterfaceVersion(const unsigned char, const unsigned short);
			inline void encodeMSAvailabilityStatus(const unsigned char, const unsigned short);
			inline void encodeAlertOnMsgDelivery(const unsigned char, const unsigned short);
			inline void encodeBroadcastChannelIndicator(const unsigned char, const unsigned short);
			inline void encodeBroadcastContentTypeInfo(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeBroadcastMessageClass(const unsigned char, const unsigned short);
			inline void encodeBroadcastServiceGroup(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeCallbackNum(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeCallbackNumAtag(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeCallbackNumPresInd(const unsigned char, const unsigned short);
			inline void encodeDestAddrSubunit(const unsigned char, const unsigned short);
			inline void encodeDestSubaddress(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeDisplayTime(const unsigned char, const unsigned short);
			inline void encodeLanguageIndicator(const unsigned char, const unsigned short);
			inline void encodeMessagePayload(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeMsValidity(const unsigned char, const unsigned short);
			inline void encodePayloadType(const unsigned char, const unsigned short);
			inline void encodePrivacyIndicator(const unsigned char, const unsigned short);
			inline void encodeSmsSignal(const unsigned short, const unsigned short);
			inline void encodeSourceAddrSubunit(const unsigned char, const unsigned short);
			inline void encodeSourcePort(const unsigned short, const unsigned short);
			inline void encodeSourceSubaddress(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeUserMessageReference(const unsigned short, const unsigned short);
			inline void encodeBroadcastErrorStatus(const unsigned, const unsigned short);
			inline void encodeFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&);
			inline void encodeBroadcastContentType(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeSourceNetworkType(const unsigned char, const unsigned short);
			inline void encodeSourceBearerType(const unsigned char, const unsigned short);
			inline void encodeSourceTelematicsId(const unsigned char, const unsigned short);
			inline void encodeDestinationPort(const unsigned short, const unsigned short);
			inline void encodeDestNetworkType(const unsigned char, const unsigned short);
			inline void encodeDestBearerType(const unsigned char, const unsigned short);
			inline void encodeDestTelematicsId(const unsigned char, const unsigned short);
			inline void encodeSarMsgRefNum(const unsigned short, const unsigned short);
			inline void encodeSarTotalSegments(const unsigned char, const unsigned short);
			inline void encodeSarSegmentSeqnum(const unsigned char, const unsigned short);
			inline void encodeMoreMessagesToSend(const unsigned char, const unsigned short);
			inline void encodeQosTimeToLive(const unsigned, const unsigned short);
			inline void encodeSetDpf(const unsigned char, const unsigned short);
			inline void encodeReceiptedMessageId(const std::string&, const unsigned short);
			inline void encodeMessageStateTLV(const unsigned char, const unsigned short);
			inline void encodeNetworkErrorCode(const NetworkErrorCode&, const unsigned short);
			inline void encodeMsMsgWaitFacilities(const unsigned char, const unsigned short);
			inline void encodeNumberOfMessages(const unsigned char, const unsigned short);
			inline void encodeItsReplyType(const unsigned char, const unsigned short);
			inline void encodeItsSessionInfo(const unsigned short, const unsigned short);
			inline void encodeUserResponseCode(const unsigned char, const unsigned short);
			inline void encodeDeliveryFailureReason(const unsigned char, const unsigned short);
			inline void encodeAdditionalStatusInfoText(const std::vector<unsigned char>&, const unsigned short);
			inline void encodeDpfResult(const unsigned char, const unsigned short);
			inline void encodeBroadcastEndTime(const std::string&, const unsigned short);
			inline void encodeUssdServiceOp(const unsigned char, const unsigned short);

		protected:
			void encodeTLV(const unsigned short, const unsigned char, const unsigned short);
			void encodeTLV(const unsigned short, const unsigned short, const unsigned short);
			void encodeTLV(const unsigned short, const unsigned, const unsigned short);
			void encodeTLV(const unsigned short, const std::string&, const unsigned short);
			void encodeTLV(const unsigned short, const std::vector<unsigned char>&, const unsigned short);
		};
	}
}

// Include inline files
#include "SMPPEncoder.inl"


#endif // SMPPENCODER_HPP
