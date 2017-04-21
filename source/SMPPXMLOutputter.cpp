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
#include "SMPPXMLOutputter.hpp"


namespace anthill {
	namespace smpp {

		SMPPXMLOutputter::SMPPXMLOutputter(std::ostream& oOutStream):
			SMPPOutputterBase(),
			XMLOutputter(oOutStream){
			throw std::logic_error("SMPPXMLOutputter is not implemented yet.");
		}


		SMPPXMLOutputter::~SMPPXMLOutputter(){
		}

		void SMPPXMLOutputter::outputHeader(const Header& oHeader){
			assert(false);
		}


		void SMPPXMLOutputter::outputSystemId(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputPassword(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSystemType(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputInterfaceVersion(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputAddrTON(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputAddrNPI(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputAddressRange(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputServiceType(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceAddrTON(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceAddrNPI(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceAddr21(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceAddr65(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestAddrTON(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestAddrNPI(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestAddr21(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestAddr65(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputEsmClass(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputProtocolId(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputPriorityFlag(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputScheduleDeliveryTime(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputValidityPeriod(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputRegisteredDelivery(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputReplaceIfPresentFlag(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDataCoding(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSMDefaultMsgId(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSMLength(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputShortMessage(std::vector<unsigned char>&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputMessageId(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputESMEAddrTON(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputESMEAddrNPI(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputESMEAddr(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputNumberOfDest(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestAddresses(const std::vector<DestAddress>&){
			assert(false);
		}

		void SMPPXMLOutputter::outputNoUnsuccess(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputUnsuccessSMEs(const std::vector<UnsuccessSME>&){
			assert(false);
		}

		void SMPPXMLOutputter::outputFinalDate(const std::string&){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputMessageState(const unsigned char){
			assert(false);
		}

		void SMPPXMLOutputter::outputMessageStateTLV(const unsigned char, const unsigned short){
			assert(false);
		}

		void SMPPXMLOutputter::outputErrorCode(const unsigned char){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&){
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastRepNum(const unsigned short, const unsigned short){
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastFrequencyInterval(const std::vector<unsigned char>&, const unsigned short){
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastContentType(const std::vector<unsigned char>&, const unsigned short){
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastAreaSuccess(const unsigned char, const unsigned short){
			assert(false);
		}

		void SMPPXMLOutputter::outputScInterfaceVersion(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputMSAvailabilityStatus(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputAlertOnMsgDelivery(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastChannelIndicator(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastContentTypeInfo(const std::vector<unsigned char>&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastMessageClass(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastServiceGroup(const std::vector<unsigned char>&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputCallbackNum(const std::vector<unsigned char>&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputCallbackNumAtag(const std::vector<unsigned char>&, const unsigned short ){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputCallbackNumPresInd(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestAddrSubunit(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestSubaddress(const std::vector<unsigned char>&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDisplayTime(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputLanguageIndicator(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputMessagePayload(const std::vector<unsigned char>&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputMsValidity(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputPayloadType(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputPrivacyIndicator(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSmsSignal(const unsigned short, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceAddrSubunit(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourcePort(const unsigned short, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceSubaddress(const std::vector<unsigned char>&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputUserMessageReference(const unsigned short, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastErrorStatus(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&){
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastContentTypeOpt(const std::vector<unsigned char>&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceNetworkType(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceBearerType(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSourceTelematicsId(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestinationPort(const unsigned short, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestNetworkType(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestBearerType(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDestTelematicsId(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSarMsgRefNum(const unsigned short, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSarTotalSegments(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSarSegmentSeqnum(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputMoreMessagesToSend(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputQosTimeToLive(const unsigned, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputSetDpf(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputReceiptedMessageId(const std::string&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputMessageStateTLVOpt(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputNetworkErrorCode(const NetworkErrorCode&, const unsigned short){
			assert(false);
		}

		void SMPPXMLOutputter::outputMsMsgWaitFacilities(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputNumberOfMessages(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputItsReplyType(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputItsSessionInfo(const unsigned short, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputUserResponseCode(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDeliveryFailureReason(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputAdditionalStatusInfoText(const std::vector<unsigned char>&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputDpfResult(const unsigned char, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputBroadcastEndTime(const std::string&, const unsigned short){
			
			assert(false);
		}

		void SMPPXMLOutputter::outputUssdServiceOp(const unsigned char, const unsigned short){
			
			assert(false);
		}

	}
}
