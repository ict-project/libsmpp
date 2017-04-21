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
#include "SMPPHexOutputter.hpp"


namespace anthill {
	namespace smpp {


		SMPPHexOutputter::SMPPHexOutputter(std::ostream& oOutStream):
			SMPPOutputterBase(),
			TextOutputter(oOutStream){
		}

		SMPPHexOutputter::~SMPPHexOutputter(){
		}

		void SMPPHexOutputter::outputHeader(const Header& oHeader){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeHeader(oHeader);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSystemId(const std::string& sSystemId){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSystemId(sSystemId);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputPassword(const std::string& sPassword){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodePassword(sPassword);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSystemType(const std::string& sSystemType){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSystemType(sSystemType);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputInterfaceVersion(const unsigned char nInterfaceVersion){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeInterfaceVersion(nInterfaceVersion);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputAddrTON(const unsigned char nAddrTON){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAddrTON(nAddrTON);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputAddrNPI(const unsigned char nAddrNPI){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAddrNPI(nAddrNPI);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputAddressRange(const std::string& sAddressRange){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAddressRange(sAddressRange);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputServiceType(const std::string& sServiceType){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeServiceType(sServiceType);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddrTON(nSourceAddrTON);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddrNPI(nSourceAddrNPI);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourceAddr21(const std::string& sSourceAddr){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddr21(sSourceAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourceAddr65(const std::string& sSourceAddr){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddr65(sSourceAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestAddrTON(const unsigned char nDestAddrTON){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddrTON(nDestAddrTON);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestAddrNPI(const unsigned char nDestAddrNPI){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddrNPI(nDestAddrNPI);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestAddr21(const std::string& sDestAddr){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddr21(sDestAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestAddr65(const std::string& sDestAddr){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddr65(sDestAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputEsmClass(const unsigned char nEsmClass){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeEsmClass(nEsmClass);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputProtocolId(const unsigned char nProtocolId){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeProtocolId(nProtocolId);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputPriorityFlag(const unsigned char nPriorityFlag){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodePriorityFlag(nPriorityFlag);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeScheduleDeliveryTime(sScheduleDeliveryTime);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputValidityPeriod(const std::string& sValidityPeriod){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeValidityPeriod(sValidityPeriod);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputRegisteredDelivery(const unsigned char nRegisteredDelivery){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeRegisteredDelivery(nRegisteredDelivery);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeReplaceIfPresentFlag(nReplaceIfPresentFlag);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDataCoding(const unsigned char nDataCoding){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDataCoding(nDataCoding);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSMDefaultMsgId(nSMDefaultMsgId);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSMLength(const unsigned char nSMLength){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSMLength(nSMLength);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputShortMessage(std::vector<unsigned char>& aShortMessage){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeShortMessage(aShortMessage);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMessageId(const std::string& sMessageId){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessageId(sMessageId);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputESMEAddrTON(const unsigned char nESMEAddrTON){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeESMEAddrTON(nESMEAddrTON);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputESMEAddrNPI(const unsigned char nESMEAddrNPI){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeESMEAddrNPI(nESMEAddrNPI);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputESMEAddr(const std::string& sESMEAddr){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeESMEAddr(sESMEAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputNumberOfDest(const unsigned char nNumberOfDest){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeNumberOfDest(nNumberOfDest);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestAddresses(const std::vector<DestAddress>& aDestAddresses){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddresses(aDestAddresses);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputNoUnsuccess(const unsigned char nNoUnsuccess){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeNoUnsuccess(nNoUnsuccess);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputUnsuccessSMEs(const std::vector<UnsuccessSME>& aUnsuccessSMEs){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUnsuccessSMEs(aUnsuccessSMEs);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputFinalDate(const std::string& sFinalDate){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeFinalDate(sFinalDate);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMessageState(const unsigned char nMessageState){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessageState(nMessageState);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMessageStateTLV(const unsigned char nMessageState, const unsigned short nMessageStateLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessageStateTLV(nMessageState, nMessageStateLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputErrorCode(const unsigned char nErrorCode){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeErrorCode(nErrorCode);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastAreaIdentifier(aBroadcastAreaIdentifier, aBroadcastAreaIdentifierLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastRepNum(const unsigned short nBroadcastRepNum, const unsigned short nBroadcastRepNumLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastRepNum(nBroadcastRepNum, nBroadcastRepNumLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastFrequencyInterval(const std::vector<unsigned char>& aBroadcastFrequencyInterval, const unsigned short nBroadcastFrequencyIntervalLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastFrequencyInterval(aBroadcastFrequencyInterval, nBroadcastFrequencyIntervalLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastContentType(const std::vector<unsigned char>& aBroadcastContentType, const unsigned short nBroadcastContentTypeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastContentType(aBroadcastContentType,nBroadcastContentTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastAreaSuccess(const unsigned char nBroadcastAreaSuccess, const unsigned short nBroadcastAreaSuccessLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastAreaSuccess(nBroadcastAreaSuccess, nBroadcastAreaSuccessLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputScInterfaceVersion(const unsigned char nScInterfaceVersion, const unsigned short nScInterfaceVersionLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeScInterfaceVersion(nScInterfaceVersion, nScInterfaceVersionLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMSAvailabilityStatus(const unsigned char nMSAvailabilityStatus, const unsigned short nMSAvailabilityStatusLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMSAvailabilityStatus(nMSAvailabilityStatus, nMSAvailabilityStatusLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery, const unsigned short nAlertOnMsgDeliveryLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAlertOnMsgDelivery(nAlertOnMsgDelivery, nAlertOnMsgDeliveryLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastChannelIndicator(const unsigned char nBroadcastChannelIndicator, const unsigned short nBroadcastChannelIndicatorLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastChannelIndicator(nBroadcastChannelIndicator, nBroadcastChannelIndicatorLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastContentTypeInfo(const std::vector<unsigned char>& aBroadcastContentTypeInfo, const unsigned short nBroadcastContentTypeInfoLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastContentTypeInfo(aBroadcastContentTypeInfo, nBroadcastContentTypeInfoLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputBroadcastMessageClass(const unsigned char nBroadcastMessageClass, const unsigned short nBroadcastMessageClassLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastMessageClass(nBroadcastMessageClass, nBroadcastMessageClassLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastServiceGroup(const std::vector<unsigned char>& aBroadcastServiceGroup, const unsigned short nBroadcastServiceGroupLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastServiceGroup(aBroadcastServiceGroup, nBroadcastServiceGroupLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputCallbackNum(const std::vector<unsigned char>& aCallbackNum, const unsigned short nCallbackNumLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeCallbackNum(aCallbackNum, nCallbackNumLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag, const unsigned short nCallbackNumAtagLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeCallbackNumAtag(aCallbackNumAtag, nCallbackNumAtagLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputCallbackNumPresInd(const unsigned char nCallbackNumPresInd, const unsigned short nCallbackNumPresIndLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeCallbackNumPresInd(nCallbackNumPresInd, nCallbackNumPresIndLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestAddrSubunit(const unsigned char nDestAddrSubunit, const unsigned short nDestAddrSubunitLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddrSubunit(nDestAddrSubunit, nDestAddrSubunitLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestSubaddress(const std::vector<unsigned char>& aDestSubaddress, const unsigned short nDestSubaddressLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestSubaddress(aDestSubaddress, nDestSubaddressLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDisplayTime(const unsigned char nDisplayTime, const unsigned short nDisplayTimeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDisplayTime(nDisplayTime, nDisplayTimeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputLanguageIndicator(const unsigned char nLanguageIndicator, const unsigned short nLanguageIndicatorLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeLanguageIndicator(nLanguageIndicator, nLanguageIndicatorLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMessagePayload(const std::vector<unsigned char>& aMessagePayload, const unsigned short nMessagePayloadLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessagePayload(aMessagePayload, nMessagePayloadLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMsValidity(const unsigned char nMsValidity, const unsigned short nMsValidityLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMsValidity(nMsValidity, nMsValidityLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputPayloadType(const unsigned char nPayloadType, const unsigned short nPayloadTypeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodePayloadType(nPayloadType, nPayloadTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputPrivacyIndicator(const unsigned char nPrivacyIndicator, const unsigned short nPrivacyIndicatorLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodePrivacyIndicator(nPrivacyIndicator, nPrivacyIndicatorLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSmsSignal(const unsigned short nSmsSignal, const unsigned short nSmsSignalLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSmsSignal(nSmsSignal, nSmsSignalLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourceAddrSubunit(const unsigned char nSourceAddrSubunit, const unsigned short nSourceAddrSubunitLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddrSubunit(nSourceAddrSubunit, nSourceAddrSubunitLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourcePort(const unsigned short nSourcePort, const unsigned short nSourcePortLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourcePort(nSourcePort, nSourcePortLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress, const unsigned short nSourceSubaddressLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceSubaddress(aSourceSubaddress, nSourceSubaddressLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputUserMessageReference(const unsigned short nUserMessageReference, const unsigned short nUserMessageReferenceLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUserMessageReference(nUserMessageReference, nUserMessageReferenceLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputBroadcastErrorStatus(const unsigned char nBroadcastErrorStatus, const unsigned short nBroadcastErrorStatusLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastErrorStatus(nBroadcastErrorStatus, nBroadcastErrorStatusLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeFailedBroadcastAreaIdentifier(aBroadcastAreaIdentifier, aBroadcastAreaIdentifierLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputBroadcastContentTypeOpt(const std::vector<unsigned char>& aBroadcastContentType, const unsigned short nBroadcastContentTypeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastContentType(aBroadcastContentType, nBroadcastContentTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputSourceNetworkType(const unsigned char nSourceNetworkType, const unsigned short nSourceNetworkTypeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceNetworkType(nSourceNetworkType, nSourceNetworkTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourceBearerType(const unsigned char nSourceBearerType, const unsigned short nSourceBearerTypeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceBearerType(nSourceBearerType, nSourceBearerTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSourceTelematicsId(const unsigned char nSourceTelematicsId, const unsigned short nSourceTelematicsIdLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceTelematicsId(nSourceTelematicsId, nSourceTelematicsIdLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputDestinationPort(const unsigned short nDestinationPort, const unsigned short nDestinationPortLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestinationPort(nDestinationPort, nDestinationPortLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestNetworkType(const unsigned char nDestNetworkType, const unsigned short nDestNetworkTypeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestNetworkType(nDestNetworkType, nDestNetworkTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestBearerType(const unsigned char nDestBearerType, const unsigned short nDestBearerTypeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestBearerType(nDestBearerType, nDestBearerTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDestTelematicsId(const unsigned char nDestTelematicsId, const unsigned short nDestTelematicsIdLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestTelematicsId(nDestTelematicsId, nDestTelematicsIdLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSarMsgRefNum(const unsigned short nSarMsgRefNum, const unsigned short nSarMsgRefNumLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSarMsgRefNum(nSarMsgRefNum, nSarMsgRefNumLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSarTotalSegments(const unsigned char nSarTotalSegments, const unsigned short nSarTotalSegmentsLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSarTotalSegments(nSarTotalSegments, nSarTotalSegmentsLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum, const unsigned short nSarSegmentSeqnumLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSarSegmentSeqnum(nSarSegmentSeqnum, nSarSegmentSeqnumLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMoreMessagesToSend(const unsigned char nMoreMessagesToSend, const unsigned short nMoreMessagesToSendLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMoreMessagesToSend(nMoreMessagesToSend, nMoreMessagesToSendLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputQosTimeToLive(const unsigned nQosTimeToLive, const unsigned short nQosTimeToLiveLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeQosTimeToLive(nQosTimeToLive, nQosTimeToLiveLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputSetDpf(const unsigned char nSetDpf, const unsigned short nSetDpfLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSetDpf(nSetDpf, nSetDpfLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputReceiptedMessageId(const std::string& sReceiptedMessageId, const unsigned short nReceiptedMessageIdLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeReceiptedMessageId(sReceiptedMessageId, nReceiptedMessageIdLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMessageStateTLVOpt(const unsigned char nMessageState, const unsigned short nMessageStateLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessageStateTLV(nMessageState, nMessageStateLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode, const unsigned short nNetworkErrorCodeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeNetworkErrorCode(oNetworkErrorCode, nNetworkErrorCodeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputMsMsgWaitFacilities(const unsigned char nMsMsgWaitFacilities, const unsigned short nMsMsgWaitFacilitiesLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMsMsgWaitFacilities(nMsMsgWaitFacilities, nMsMsgWaitFacilitiesLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputNumberOfMessages(const unsigned char nNumberOfMessages, const unsigned short nNumberOfMessagesLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeNumberOfMessages(nNumberOfMessages, nNumberOfMessagesLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputItsReplyType(const unsigned char nItsReplyType, const unsigned short nItsReplyTypeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeItsReplyType(nItsReplyType, nItsReplyTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputItsSessionInfo(const unsigned short nItsSessionInfo, const unsigned short nItsSessionInfoLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeItsSessionInfo(nItsSessionInfo, nItsSessionInfoLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputUserResponseCode(const unsigned char nUserResponseCode, const unsigned short nUserResponseCodeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUserResponseCode(nUserResponseCode, nUserResponseCodeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDeliveryFailureReason(const unsigned char nDeliveryFailureReason, const unsigned short nDeliveryFailureReasonLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDeliveryFailureReason(nDeliveryFailureReason, nDeliveryFailureReasonLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputAdditionalStatusInfoText(const std::vector<unsigned char>& aAdditionalStatusInfoText, const unsigned short nAdditionalStatusInfoTextLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAdditionalStatusInfoText(aAdditionalStatusInfoText, nAdditionalStatusInfoTextLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputDpfResult(const unsigned char nDpfResult, const unsigned short nDpfResultLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDpfResult(nDpfResult, nDpfResultLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);

		}

		void SMPPHexOutputter::outputBroadcastEndTime(const std::string& sBroadcastEndTime, const unsigned short nBroadcastEndTimeLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastEndTime(sBroadcastEndTime, nBroadcastEndTimeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}

		void SMPPHexOutputter::outputUssdServiceOp(const unsigned char nUssdServiceOp, const unsigned short nUssdServiceOpLen){
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUssdServiceOp(nUssdServiceOp, nUssdServiceOpLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
		}
	}
}

