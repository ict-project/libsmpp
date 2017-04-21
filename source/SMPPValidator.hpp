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

#ifndef SMPPVALIDATOR_HPP
#define SMPPVALIDATOR_HPP

#include "ValidatorBase.hpp"
#include "SMPPDatatypes.hpp"
#include "SMPPStructures.hpp"

namespace anthill {
	namespace smpp {


		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPValidator : public anthill::ValidatorBase{
		public:
			SMPPValidator(void);
			SMPPValidator(const SMPPValidator&);
			virtual ~SMPPValidator(void);
		public:
			/**
			 * A methods to decode header and SMPP datatypes
			 */
			inline void validateHeader(const Header& oHeader);
			/**
			 * A methods to encode data
			 */
			inline void validateSystemId(const std::string&);
			inline void validatePassword(const std::string&);
			inline void validateSystemType(const std::string&);
			inline void validateInterfaceVersion(const unsigned char);
			inline void validateAddrTON(const unsigned char);
			inline void validateAddrNPI(const unsigned char);
			inline void validateAddressRange(const std::string&);
			inline void validateServiceType(const std::string&);
			inline void validateSourceAddrTON(const unsigned char);
			inline void validateSourceAddrNPI(const unsigned char);
			inline void validateSourceAddr21(const std::string&);
			inline void validateSourceAddr65(const std::string&);
			inline void validateDestAddrTON(const unsigned char);
			inline void validateDestAddrNPI(const unsigned char);
			inline void validateDestAddr21(const std::string&);
			inline void validateDestAddr65(const std::string&);
			inline void validateEsmClass(const unsigned char);
			inline void validateProtocolId(const unsigned char);
			inline void validatePriorityFlag(const unsigned char);
			inline void validateScheduleDeliveryTime(const std::string&);
			inline void validateValidityPeriod(const std::string&);
			inline void validateRegisteredDelivery(const unsigned char);
			inline void validateReplaceIfPresentFlag(const unsigned char);
			inline void validateDataCoding(const unsigned char);
			inline void validateSMDefaultMsgId(const unsigned char);
			inline void validateSMLength(const unsigned char);
			inline void validateShortMessage(const std::vector<unsigned char>&, const char);
			inline void validateMessageId(const std::string&);
			inline void validateMessageIdNull(const std::string&);
			inline void validateESMEAddrTON(const unsigned char);
			inline void validateESMEAddrNPI(const unsigned char);
			inline void validateESMEAddr(const std::string&);
			inline void validateNumberOfDest(const unsigned char);
			inline void validateDestAddresses(const std::vector<DestAddress>&, const char);
			inline void validateNoUnsuccess(const unsigned char);
			inline void validateUnsuccessSMEs(const std::vector<UnsuccessSME>&, const char);
			inline void validateFinalDate(const std::string&);
			inline void validateMessageState(const unsigned char);
			inline void validateErrorCode(const unsigned char);
			inline void validateBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&);
			inline void validateBroadcastRepNum(const unsigned short, const unsigned short);
			inline void validateBroadcastFrequencyInterval(const std::vector<unsigned char>&, const unsigned short);
			inline void validateBroadcastAreaSuccess(const unsigned char, const unsigned short);

			/**
			 * A methods to decode TLV
			 */
			inline void validateScInterfaceVersion(const unsigned char, const unsigned short);
			inline void validateMSAvailabilityStatus(const unsigned char, const unsigned short);
			inline void validateAlertOnMsgDelivery(const unsigned char, const unsigned short);
			inline void validateBroadcastChannelIndicator(const unsigned char, const unsigned short);
			inline void validateBroadcastContentTypeInfo(const std::vector<unsigned char>&, const unsigned short);
			inline void validateBroadcastMessageClass(const unsigned char, const unsigned short);
			inline void validateBroadcastServiceGroup(const std::vector<unsigned char>&, const unsigned short);
			inline void validateCallbackNum(const std::vector<unsigned char>&, const unsigned short);
			inline void validateCallbackNumAtag(const std::vector<unsigned char>&, const unsigned short);
			inline void validateCallbackNumPresInd(const unsigned char, const unsigned short);
			inline void validateDestAddrSubunit(const unsigned char, const unsigned short);
			inline void validateDestSubaddress(const std::vector<unsigned char>&, const unsigned short);
			inline void validateDisplayTime(const unsigned char, const unsigned short);
			inline void validateLanguageIndicator(const unsigned char, const unsigned short);
			inline void validateMessagePayload(const std::vector<unsigned char>&, const unsigned short);
			inline void validateMsValidity(const unsigned char, const unsigned short);
			inline void validatePayloadType(const unsigned char, const unsigned short);
			inline void validatePrivacyIndicator(const unsigned char, const unsigned short);
			inline void validateSmsSignal(const unsigned short, const unsigned short);
			inline void validateSourceAddrSubunit(const unsigned char, const unsigned short);
			inline void validateSourcePort(const unsigned short, const unsigned short);
			inline void validateSourceSubaddress(const std::vector<unsigned char>&, const unsigned short);
			inline void validateUserMessageReference(const unsigned short, const unsigned short);
			inline void validateBroadcastErrorStatus(const unsigned, const unsigned short);
			inline void validateFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&, const std::vector<unsigned short>&);
			inline void validateBroadcastContentType(const std::vector<unsigned char>&, const unsigned short);
			inline void validateSourceNetworkType(const unsigned char, const unsigned short);
			inline void validateSourceBearerType(const unsigned char, const unsigned short);
			inline void validateSourceTelematicsId(const unsigned char, const unsigned short);
			inline void validateDestinationPort(const unsigned short, const unsigned short);
			inline void validateDestNetworkType(const unsigned char, const unsigned short);
			inline void validateDestBearerType(const unsigned char, const unsigned short);
			inline void validateDestTelematicsId(const unsigned char, const unsigned short);
			inline void validateSarMsgRefNum(const unsigned short, const unsigned short);
			inline void validateSarTotalSegments(const unsigned char, const unsigned short);
			inline void validateSarSegmentSeqnum(const unsigned char, const unsigned short);
			inline void validateMoreMessagesToSend(const unsigned char, const unsigned short);
			inline void validateQosTimeToLive(const unsigned, const unsigned short);
			inline void validateSetDpf(const unsigned char, const unsigned short);
			inline void validateReceiptedMessageId(const std::string&, const unsigned short);
			inline void validateMessageStateTLV(const unsigned char, const unsigned short);
			inline void validateNetworkErrorCode(const NetworkErrorCode&, const unsigned short);
			inline void validateMsMsgWaitFacilities(const unsigned char, const unsigned short);
			inline void validateNumberOfMessages(const unsigned char, const unsigned short);
			inline void validateItsReplyType(const unsigned char, const unsigned short);
			inline void validateItsSessionInfo(const unsigned short, const unsigned short);
			inline void validateUserResponseCode(const unsigned char, const unsigned short);
			inline void validateDeliveryFailureReason(const unsigned char, const unsigned short);
			inline void validateAdditionalStatusInfoText(const std::vector<unsigned char>&, const unsigned short);
			inline void validateDpfResult(const unsigned char, const unsigned short);
			inline void validateBroadcastEndTime(const std::string&, const unsigned short);
			inline void validateUssdServiceOp(const unsigned char, const unsigned short);

			/**
			 * A complex rules
			 */
			inline void validateShortMessagePayload(const std::vector<unsigned char>&, const std::vector<unsigned char>&);
		};
	}
}

// Include inline files
#include "SMPPValidator.inl"

#endif // SMPPVALIDATOR_HPP

