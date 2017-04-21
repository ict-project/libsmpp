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

#ifndef SMPPDECODER_HPP
#define SMPPDECODER_HPP

#include "BinaryDecoder.hpp"
#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {


		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPDecoder : public anthill::BinaryDecoder{
		public:
			SMPPDecoder(void);
			virtual ~SMPPDecoder(void);
		public:
			const bool hasTLVs(void);
			const bool hasPackets(void);
			const unsigned short getTLVCode(void);
			const std::string getTLVError(void);
			SMPPPDU* getPacket(void);
			SMPPPDU* decodePacket(void);

		public:
			/**
			 * A methods to decode header and SMPP datatypes
			 */
			inline void decodeHeader(Header& oHeader);
			/**
			 * A methods to encode data
			 */
			inline void decodeSystemId(std::string&, const unsigned);
			inline void decodePassword(std::string&, const unsigned);
			inline void decodeSystemType(std::string&, const unsigned);
			inline void decodeInterfaceVersion(unsigned char&, const unsigned);
			inline void decodeAddrTON(unsigned char&, const unsigned);
			inline void decodeAddrNPI(unsigned char&, const unsigned);
			inline void decodeAddressRange(std::string&, const unsigned);
			inline void decodeServiceType(std::string&, const unsigned);
			inline void decodeSourceAddrTON(unsigned char&, const unsigned);
			inline void decodeSourceAddrNPI(unsigned char&, const unsigned);
			inline void decodeSourceAddr21(std::string&, const unsigned);
			inline void decodeSourceAddr65(std::string&, const unsigned);
			inline void decodeDestAddrTON(unsigned char&, const unsigned);
			inline void decodeDestAddrNPI(unsigned char&, const unsigned);
			inline void decodeDestAddr21(std::string&, const unsigned);
			inline void decodeDestAddr65(std::string&, const unsigned);
			inline void decodeEsmClass(unsigned char&, const unsigned);
			inline void decodeProtocolId(unsigned char&, const unsigned);
			inline void decodePriorityFlag(unsigned char&, const unsigned);
			inline void decodeScheduleDeliveryTime(std::string&, const unsigned);
			inline void decodeValidityPeriod(std::string&, const unsigned);
			inline void decodeRegisteredDelivery(unsigned char&, const unsigned);
			inline void decodeReplaceIfPresentFlag(unsigned char&, const unsigned);
			inline void decodeDataCoding(unsigned char&, const unsigned);
			inline void decodeSMDefaultMsgId(unsigned char&, const unsigned);
			inline void decodeSMLength(unsigned char&, const unsigned);
			inline void decodeShortMessage(std::vector<unsigned char>&, unsigned char&, const unsigned);
			inline void decodeMessageId(std::string&, const unsigned);
			inline void decodeESMEAddrTON(unsigned char&, const unsigned);
			inline void decodeESMEAddrNPI(unsigned char&, const unsigned);
			inline void decodeESMEAddr(std::string&, const unsigned);
			inline void decodeNumberOfDest(unsigned char&, const unsigned);
			inline void decodeDestAddresses(std::vector<DestAddress>&, const char, const unsigned);
			inline void decodeNoUnsuccess(unsigned char&, const unsigned);
			inline void decodeUnsuccessSMEs(std::vector<UnsuccessSME>&, const char, const unsigned);
			inline void decodeFinalDate(std::string&, const unsigned);
			inline void decodeErrorCode(unsigned char&, const unsigned);
			inline void decodeMessageState(unsigned char&, const unsigned);
			inline void decodeBroadcastAreaIdentifier(BroadcastAreaIdentifier&, unsigned short&, const unsigned);
			inline void decodeBroadcastAreaIdentifier(std::vector<BroadcastAreaIdentifier>&, std::vector<unsigned short>&, const unsigned);
			inline void decodeBroadcastRepNum(unsigned short&, unsigned short&, const unsigned);
			inline void decodeBroadcastFrequencyInterval(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeBroadcastAreaSuccess(unsigned char&, unsigned short&, const unsigned);

			/**
			 * A methods to decode TLV
			 */
			inline void decodeScInterfaceVersion(unsigned char&, unsigned short&, const unsigned);
			inline void decodeMSAvailabilityStatus(unsigned char&, unsigned short&, const unsigned);
			inline void decodeAlertOnMsgDelivery(unsigned char&, unsigned short&, const unsigned);
			inline void decodeBroadcastChannelIndicator(unsigned char&, unsigned short&, const unsigned);
			inline void decodeBroadcastContentTypeInfo(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeBroadcastMessageClass(unsigned char&, unsigned short&, const unsigned);
			inline void decodeBroadcastServiceGroup(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeCallbackNum(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeCallbackNumAtag(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeCallbackNumPresInd(unsigned char&, unsigned short&, const unsigned);
			inline void decodeDestAddrSubunit(unsigned char&, unsigned short&, const unsigned);
			inline void decodeDestSubaddress(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeDisplayTime(unsigned char&, unsigned short&, const unsigned);
			inline void decodeLanguageIndicator(unsigned char&, unsigned short&, const unsigned);
			inline void decodeMessagePayload(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeMsValidity(unsigned char&, unsigned short&, const unsigned);
			inline void decodePayloadType(unsigned char&, unsigned short&, const unsigned);
			inline void decodePrivacyIndicator(unsigned char&, unsigned short&, const unsigned);
			inline void decodeSmsSignal(unsigned short&, unsigned short&, const unsigned);
			inline void decodeSourceAddrSubunit(unsigned char&, unsigned short&, const unsigned);
			inline void decodeSourcePort(unsigned short&, unsigned short&, const unsigned);
			inline void decodeSourceSubaddress(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeUserMessageReference(unsigned short&, unsigned short&, const unsigned);
			inline void decodeBroadcastErrorStatus(unsigned&, unsigned short&, const unsigned);
			inline void decodeFailedBroadcastAreaIdentifier(std::vector<BroadcastAreaIdentifier>&, std::vector<unsigned short>&, const unsigned);
			inline void decodeBroadcastContentType(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeSourceNetworkType(unsigned char&, unsigned short&, const unsigned);
			inline void decodeSourceBearerType(unsigned char&, unsigned short&, const unsigned);
			inline void decodeSourceTelematicsId(unsigned char&, unsigned short&, const unsigned);
			inline void decodeDestinationPort(unsigned short&, unsigned short&, const unsigned);
			inline void decodeDestNetworkType(unsigned char&, unsigned short&, const unsigned);
			inline void decodeDestBearerType(unsigned char&, unsigned short&, const unsigned);
			inline void decodeDestTelematicsId(unsigned char&, unsigned short&, const unsigned);
			inline void decodeSarMsgRefNum(unsigned short&, unsigned short&, const unsigned);
			inline void decodeSarTotalSegments(unsigned char&, unsigned short&, const unsigned);
			inline void decodeSarSegmentSeqnum(unsigned char&, unsigned short&, const unsigned);
			inline void decodeMoreMessagesToSend(unsigned char&, unsigned short&, const unsigned);
			inline void decodeQosTimeToLive(unsigned&, unsigned short&, const unsigned);
			inline void decodeSetDpf(unsigned char&, unsigned short&, const unsigned);
			inline void decodeReceiptedMessageId(std::string&, unsigned short&, const unsigned);
			inline void decodeMessageStateTLV(unsigned char&, unsigned short&, const unsigned);
			inline void decodeNetworkErrorCode(NetworkErrorCode&, unsigned short&, const unsigned);
			inline void decodeMsMsgWaitFacilities(unsigned char&, unsigned short&, const unsigned);
			inline void decodeNumberOfMessages(unsigned char&, unsigned short&, const unsigned);
			inline void decodeItsReplyType(unsigned char&, unsigned short&, const unsigned);
			inline void decodeItsSessionInfo(unsigned short&, unsigned short&, const unsigned);
			inline void decodeUserResponseCode(unsigned char&, unsigned short&, const unsigned);
			inline void decodeDeliveryFailureReason(unsigned char&, unsigned short&, const unsigned);
			inline void decodeAdditionalStatusInfoText(std::vector<unsigned char>&, unsigned short&, const unsigned);
			inline void decodeDpfResult(unsigned char&, unsigned short&, const unsigned);
			inline void decodeBroadcastEndTime(std::string&, unsigned short&, const unsigned);
			inline void decodeUssdServiceOp(unsigned char&, unsigned short&, const unsigned);


		protected:
			unsigned decodeCommandLength(void);
			unsigned decodeCommandId(void);
			void insertCommands(void);
			void eraseCommands(void);

			void decodeTLV(unsigned char&, unsigned short&, const unsigned);
			void decodeTLV(unsigned short&, unsigned short&, const unsigned);
			void decodeTLV(unsigned&, unsigned short&, const unsigned);
			void decodeTLV(std::string&, unsigned short&, const unsigned);
			void decodeTLV(std::vector<unsigned char>&, unsigned short&, const unsigned);


		protected:
			typedef std::map < int , SMPPPDU*> Commands;
			Commands m_mCommands;

		};
	}
}

// Include inline files
#include "SMPPDecoder.inl"


#endif // SMPPDECODER_HPP
