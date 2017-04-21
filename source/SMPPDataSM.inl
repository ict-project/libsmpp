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

		inline const bool SMPPDataSM::isPresentSourcePort(void) const{
			return this->m_bPresentSourcePort;
		}

		inline void SMPPDataSM::omitPresentSourcePort(void){
			this->m_bPresentSourcePort = false;
		}

		inline void SMPPDataSM::setPresentSourcePort(const bool bPresentSourcePort){
			this->m_bPresentSourcePort = bPresentSourcePort;
		}

		inline const bool SMPPDataSM::isPresentSourceAddrSubunit(void) const{
			return this->m_bPresentSourceAddrSubunit;
		}

		inline void SMPPDataSM::omitPresentSourceAddrSubunit(void){
			this->m_bPresentSourceAddrSubunit = false;
		}

		inline void SMPPDataSM::setPresentSourceAddrSubunit(const bool bPresentSourceAddrSubunit){
			this->m_bPresentSourceAddrSubunit = bPresentSourceAddrSubunit;
		}

		inline const bool SMPPDataSM::isPresentSourceNetworkType(void) const{
			return this->m_bPresentSourceNetworkType;
		}

		inline void SMPPDataSM::omitPresentSourceNetworkType(void){
			this->m_bPresentSourceNetworkType = false;
		}

		inline void SMPPDataSM::setPresentSourceNetworkType(const bool bPresentSourceNetworkType){
			this->m_bPresentSourceNetworkType = bPresentSourceNetworkType;
		}

		inline const bool SMPPDataSM::isPresentSourceBearerType(void) const{
			return this->m_bPresentSourceBearerType;
		}

		inline void SMPPDataSM::omitPresentSourceBearerType(void){
			this->m_bPresentSourceBearerType= false;
		}

		inline void SMPPDataSM::setPresentSourceBearerType(const bool bPresentSourceBearerType){
			this->m_bPresentSourceBearerType = bPresentSourceBearerType;
		}

		inline const bool SMPPDataSM::isPresentSourceTelematicsId(void) const{
			return this->m_bPresentSourceTelematicsId;
		}

		inline void SMPPDataSM::omitPresentSourceTelematicsId(void){
			this->m_bPresentSourceTelematicsId= false;
		}

		inline void SMPPDataSM::setPresentSourceTelematicsId(const bool bPresentSourceTelematicsId){
			this->m_bPresentSourceTelematicsId = bPresentSourceTelematicsId;
		}

		inline const bool SMPPDataSM::isPresentDestinationPort(void) const{
			return this->m_bPresentDestinationPort;
		}

		inline void SMPPDataSM::omitPresentDestinationPort(void){
			this->m_bPresentDestinationPort = false;
		}

		inline void SMPPDataSM::setPresentDestinationPort(const bool bPresentDestinationPort){
			this->m_bPresentDestinationPort = bPresentDestinationPort;
		}

		inline const bool SMPPDataSM::isPresentDestAddrSubunit(void) const{
			return this->m_bPresentDestAddrSubunit;
		}

		inline void SMPPDataSM::omitPresentDestAddrSubunit(void){
			this->m_bPresentDestAddrSubunit= false;
		}

		inline void SMPPDataSM::setPresentDestAddrSubunit(const bool bPresentDestAddrSubunit){
			this->m_bPresentDestAddrSubunit = bPresentDestAddrSubunit;
		}

		inline const bool SMPPDataSM::isPresentDestNetworkType(void) const{
			return this->m_bPresentDestNetworkType;
		}

		inline void SMPPDataSM::omitPresentDestNetworkType(void){
			this->m_bPresentDestNetworkType= false;
		}

		inline void SMPPDataSM::setPresentDestNetworkType(const bool bPresentDestNetworkType){
			this->m_bPresentDestNetworkType = bPresentDestNetworkType;
		}

		inline const bool SMPPDataSM::isPresentDestBearerType(void) const{
			return this->m_bPresentDestBearerType;
		}

		inline void SMPPDataSM::omitPresentDestBearerType(void){
			this->m_bPresentDestBearerType= false;
		}

		inline void SMPPDataSM::setPresentDestBearerType(const bool bPresentDestBearerType){
			this->m_bPresentDestBearerType = bPresentDestBearerType;
		}

		inline const bool SMPPDataSM::isPresentDestTelematicsId(void) const{
			return this->m_bPresentDestTelematicsId;
		}

		inline void SMPPDataSM::omitPresentDestTelematicsId(void){
			this->m_bPresentDestTelematicsId= false;
		}

		inline void SMPPDataSM::setPresentDestTelematicsId(const bool bPresentDestTelematicsId){
			this->m_bPresentDestTelematicsId = bPresentDestTelematicsId;
		}


		inline const bool SMPPDataSM::isPresentSarMsgRefNum(void) const{
			return this->m_bPresentSarMsgRefNum;
		}

		inline void SMPPDataSM::omitPresentSarMsgRefNum(void){
			this->m_bPresentSarMsgRefNum = false;
		}

		inline void SMPPDataSM::setPresentSarMsgRefNum(const bool bPresentSarMsgRefNum){
			this->m_bPresentSarMsgRefNum = bPresentSarMsgRefNum;
		}

		inline const bool SMPPDataSM::isPresentSarTotalSegments(void) const{
			return this->m_bPresentSarTotalSegments;
		}

		inline void SMPPDataSM::omitPresentSarTotalSegments(void){
			this->m_bPresentSarTotalSegments = false;
		}

		inline void SMPPDataSM::setPresentSarTotalSegments(const bool bPresentSarTotalSegments){
			this->m_bPresentSarTotalSegments = bPresentSarTotalSegments;
		}

		inline const bool SMPPDataSM::isPresentSarSegmentSeqnum(void) const{
			return this->m_bPresentSarSegmentSeqnum;
		}

		inline void SMPPDataSM::omitPresentSarSegmentSeqnum(void){
			this->m_bPresentSarSegmentSeqnum = false;
		}

		inline void SMPPDataSM::setPresentSarSegmentSeqnum(const bool bPresentSarSegmentSeqnum){
			this->m_bPresentSarSegmentSeqnum = bPresentSarSegmentSeqnum;
		}

		inline const bool SMPPDataSM::isPresentMoreMessagesToSend(void) const{
			return this->m_bPresentMoreMessagesToSend;
		}

		inline void SMPPDataSM::omitPresentMoreMessagesToSend(void){
			this->m_bPresentMoreMessagesToSend = false;
		}

		inline void SMPPDataSM::setPresentMoreMessagesToSend(const bool bPresentMoreMessagesToSend){
			this->m_bPresentMoreMessagesToSend = bPresentMoreMessagesToSend;
		}

		inline const bool SMPPDataSM::isPresentQosTimeToLive(void) const{
			return this->m_bPresentQosTimeToLive;
		}

		inline void SMPPDataSM::omitPresentQosTimeToLive(void){
			this->m_bPresentQosTimeToLive = false;
		}

		inline void SMPPDataSM::setPresentQosTimeToLive(const bool bPresentQosTimeToLive){
			this->m_bPresentQosTimeToLive = bPresentQosTimeToLive;
		}

		inline const bool SMPPDataSM::isPresentPayloadType(void) const{
			return this->m_bPresentPayloadType;
		}

		inline void SMPPDataSM::omitPresentPayloadType(void){
			this->m_bPresentPayloadType = false;
		}

		inline void SMPPDataSM::setPresentPayloadType(const bool bPresentPayloadType){
			this->m_bPresentPayloadType = bPresentPayloadType;
		}

		inline const bool SMPPDataSM::isPresentMessagePayload(void) const{
			return this->m_bPresentMessagePayload;
		}

		inline void SMPPDataSM::omitPresentMessagePayload(void){
			this->m_bPresentMessagePayload = false;
		}

		inline void SMPPDataSM::setPresentMessagePayload(const bool bPresentMessagePayload){
			this->m_bPresentMessagePayload = bPresentMessagePayload;
		}

		inline const bool SMPPDataSM::isPresentSetDpf(void) const{
			return this->m_bPresentSetDpf;
		}

		inline void SMPPDataSM::omitPresentSetDpf(void){
			this->m_bPresentSetDpf = false;
		}

		inline void SMPPDataSM::setPresentSetDpf(const bool bPresentSetDpf){
			this->m_bPresentSetDpf = bPresentSetDpf;
		}

		inline const bool SMPPDataSM::isPresentReceiptedMessageId(void) const{
			return this->m_bPresentReceiptedMessageId;
		}

		inline void SMPPDataSM::omitPresentReceiptedMessageId(void){
			this->m_bPresentReceiptedMessageId = false;
		}

		inline void SMPPDataSM::setPresentReceiptedMessageId(const bool bPresentReceiptedMessageId){
			this->m_bPresentReceiptedMessageId = bPresentReceiptedMessageId;
		}

		inline const bool SMPPDataSM::isPresentMessageState(void) const{
			return this->m_bPresentMessageState;
		}

		inline void SMPPDataSM::omitPresentMessageState(void){
			this->m_bPresentMessageState = false;
		}

		inline void SMPPDataSM::setPresentMessageState(const bool bPresentMessageState){
			this->m_bPresentMessageState = bPresentMessageState;
		}

		inline const bool SMPPDataSM::isPresentNetworkErrorCode(void) const{
			return this->m_bPresentNetworkErrorCode;
		}

		inline void SMPPDataSM::omitPresentNetworkErrorCode(void){
			this->m_bPresentNetworkErrorCode = false;
		}

		inline void SMPPDataSM::setPresentNetworkErrorCode(const bool bPresentNetworkErrorCode){
			this->m_bPresentNetworkErrorCode = bPresentNetworkErrorCode;
		}

		inline const bool SMPPDataSM::isPresentUserMessageReference(void) const{
			return this->m_bPresentUserMessageReference;
		}

		inline void SMPPDataSM::omitPresentUserMessageReference(void){
			this->m_bPresentUserMessageReference = false;
		}

		inline void SMPPDataSM::setPresentUserMessageReference(const bool bPresentUserMessageReference){
			this->m_bPresentUserMessageReference = bPresentUserMessageReference;
		}

		inline const bool SMPPDataSM::isPresentPrivacyIndicator(void) const{
			return this->m_bPresentPrivacyIndicator;
		}

		inline void SMPPDataSM::omitPresentPrivacyIndicator(void){
			this->m_bPresentPrivacyIndicator = false;
		}

		inline void SMPPDataSM::setPresentPrivacyIndicator(const bool bPresentPrivacyIndicator){
			this->m_bPresentPrivacyIndicator = bPresentPrivacyIndicator;
		}

		inline const bool SMPPDataSM::isPresentCallbackNum(void) const{
			return this->m_bPresentCallbackNum;
		}

		inline void SMPPDataSM::omitPresentCallbackNum(void){
			this->m_bPresentCallbackNum = false;
		}

		inline void SMPPDataSM::setPresentCallbackNum(const bool bPresentCallbackNum){
			this->m_bPresentCallbackNum = bPresentCallbackNum;
		}

		inline const bool SMPPDataSM::isPresentCallbackNumPresInd(void) const{
			return this->m_bPresentCallbackNumPresInd;
		}

		inline void SMPPDataSM::omitPresentCallbackNumPresInd(void){
			this->m_bPresentCallbackNumPresInd = false;
		}

		inline void SMPPDataSM::setPresentCallbackNumPresInd(const bool bPresentCallbackNumPresInd){
			this->m_bPresentCallbackNumPresInd = bPresentCallbackNumPresInd;
		}

		inline const bool SMPPDataSM::isPresentCallbackNumAtag(void) const{
			return this->m_bPresentCallbackNumAtag;
		}

		inline void SMPPDataSM::omitPresentCallbackNumAtag(void){
			this->m_bPresentCallbackNumAtag = false;
		}

		inline void SMPPDataSM::setPresentCallbackNumAtag(const bool bPresentCallbackNumAtag){
			this->m_bPresentCallbackNumAtag = bPresentCallbackNumAtag;
		}

		inline const bool SMPPDataSM::isPresentSourceSubaddress(void) const{
			return this->m_bPresentSourceSubaddress;
		}

		inline void SMPPDataSM::omitPresentSourceSubaddress(void){
			this->m_bPresentSourceSubaddress = false;
		}

		inline void SMPPDataSM::setPresentSourceSubaddress(const bool bPresentSourceSubaddress){
			this->m_bPresentSourceSubaddress = bPresentSourceSubaddress;
		}

		inline const bool SMPPDataSM::isPresentDestSubaddress(void) const{
			return this->m_bPresentDestSubaddress;
		}

		inline void SMPPDataSM::omitPresentDestSubaddress(void){
			this->m_bPresentDestSubaddress = false;
		}

		inline void SMPPDataSM::setPresentDestSubaddress(const bool bPresentDestSubaddress){
			this->m_bPresentDestSubaddress = bPresentDestSubaddress;
		}

		inline const bool SMPPDataSM::isPresentUserResponseCode(void) const{
			return this->m_bPresentUserResponseCode;
		}

		inline void SMPPDataSM::omitPresentUserResponseCode(void){
			this->m_bPresentUserResponseCode= false;
		}

		inline void SMPPDataSM::setPresentUserResponseCode(const bool bPresentUserResponseCode){
			this->m_bPresentUserResponseCode = bPresentUserResponseCode;
		}

		inline const bool SMPPDataSM::isPresentDisplayTime(void) const{
			return this->m_bPresentDisplayTime;
		}

		inline void SMPPDataSM::omitPresentDisplayTime(void){
			this->m_bPresentDisplayTime = false;
		}

		inline void SMPPDataSM::setPresentDisplayTime(const bool bPresentDisplayTime){
			this->m_bPresentDisplayTime = bPresentDisplayTime;
		}

		inline const bool SMPPDataSM::isPresentSmsSignal(void) const{
			return this->m_bPresentSmsSignal;
		}

		inline void SMPPDataSM::omitPresentSmsSignal(void){
			this->m_bPresentSmsSignal = false;
		}

		inline void SMPPDataSM::setPresentSmsSignal(const bool bPresentSmsSignal){
			this->m_bPresentSmsSignal = bPresentSmsSignal;
		}

		inline const bool SMPPDataSM::isPresentMsValidity(void) const{
			return this->m_bPresentMsValidity;
		}

		inline void SMPPDataSM::omitPresentMsValidity(void){
			this->m_bPresentMsValidity = false;
		}

		inline void SMPPDataSM::setPresentMsValidity(const bool bPresentMsValidity){
			this->m_bPresentMsValidity = bPresentMsValidity;
		}

		inline const bool SMPPDataSM::isPresentMsMsgWaitFacilities(void) const{
			return this->m_bPresentMsMsgWaitFacilities;
		}

		inline void SMPPDataSM::omitPresentMsMsgWaitFacilities(void){
			this->m_bPresentMsMsgWaitFacilities = false;
		}

		inline void SMPPDataSM::setPresentMsMsgWaitFacilities(const bool bPresentMsMsgWaitFacilities){
			this->m_bPresentMsMsgWaitFacilities = bPresentMsMsgWaitFacilities;
		}

		inline const bool SMPPDataSM::isPresentNumberOfMessages(void) const{
			return this->m_bPresentNumberOfMessages;
		}

		inline void SMPPDataSM::omitPresentNumberOfMessages(void){
			this->m_bPresentNumberOfMessages = false;
		}

		inline void SMPPDataSM::setPresentNumberOfMessages(const bool bPresentNumberOfMessages){
			this->m_bPresentNumberOfMessages = bPresentNumberOfMessages;
		}

		inline const bool SMPPDataSM::isPresentAlertOnMsgDelivery(void) const{
			return this->m_bPresentAlertOnMsgDelivery;
		}

		inline void SMPPDataSM::omitPresentAlertOnMsgDelivery(void){
			this->m_bPresentAlertOnMsgDelivery = false;
		}

		inline void SMPPDataSM::setPresentAlertOnMsgDelivery(const bool bPresentAlertOnMsgDelivery){
			this->m_bPresentAlertOnMsgDelivery = bPresentAlertOnMsgDelivery;
		}

		inline const bool SMPPDataSM::isPresentLanguageIndicator(void) const{
			return this->m_bPresentLanguageIndicator;
		}

		inline void SMPPDataSM::omitPresentLanguageIndicator(void){
			this->m_bPresentLanguageIndicator = false;
		}

		inline void SMPPDataSM::setPresentLanguageIndicator(const bool bPresentLanguageIndicator){
			this->m_bPresentLanguageIndicator = bPresentLanguageIndicator;
		}

		inline const bool SMPPDataSM::isPresentItsReplyType(void) const{
			return this->m_bPresentItsReplyType;
		}

		inline void SMPPDataSM::omitPresentItsReplyType(void){
			this->m_bPresentItsReplyType = false;
		}

		inline void SMPPDataSM::setPresentItsReplyType(const bool bPresentItsReplyType){
			this->m_bPresentItsReplyType = bPresentItsReplyType;
		}

		inline const bool SMPPDataSM::isPresentItsSessionInfo(void) const{
			return this->m_bPresentItsSessionInfo;
		}

		inline void SMPPDataSM::omitPresentItsSessionInfo(void){
			this->m_bPresentItsSessionInfo = false;
		}

		inline void SMPPDataSM::setPresentItsSessionInfo(const bool bPresentItsSessionInfo){
			this->m_bPresentItsSessionInfo = bPresentItsSessionInfo;
		}

		inline void SMPPDataSM::setServiceType(const std::string& sServiceType){
			this->m_sServiceType = sServiceType;
		}

		inline std::string& SMPPDataSM::refServiceType(void){
			return this->m_sServiceType;
		}

		inline const std::string& SMPPDataSM::getServiceType(void) const{
			return this->m_sServiceType;
		}


		inline void SMPPDataSM::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPDataSM::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPDataSM::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPDataSM::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPDataSM::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPDataSM::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPDataSM::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPDataSM::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPDataSM::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}


		inline void SMPPDataSM::setDestAddrTON(const unsigned char nDestAddrTON){
			this->m_nDestAddrTON = nDestAddrTON;
		}

		inline unsigned char& SMPPDataSM::refDestAddrTON(void){
			return this->m_nDestAddrTON;
		}

		inline const unsigned char SMPPDataSM::getDestAddrTON(void) const{
			return this->m_nDestAddrTON;
		}


		inline void SMPPDataSM::setDestAddrNPI(const unsigned char nDestAddrNPI){
			this->m_nDestAddrNPI = nDestAddrNPI;
		}

		inline unsigned char& SMPPDataSM::refDestAddrNPI(void){
			return this->m_nDestAddrNPI;
		}

		inline const unsigned char SMPPDataSM::getDestAddrNPI(void) const{
			return this->m_nDestAddrNPI;
		}


		inline void SMPPDataSM::setDestAddr(const std::string& sDestAddr){
			this->m_sDestAddr = sDestAddr;
		}

		inline std::string& SMPPDataSM::refDestAddr(void){
			return this->m_sDestAddr;
		}

		inline const std::string& SMPPDataSM::getDestAddr(void) const{
			return this->m_sDestAddr;
		}


		inline void SMPPDataSM::setEsmClass(const unsigned char nEsmClass){
			this->m_nEsmClass = nEsmClass;
		}

		inline unsigned char& SMPPDataSM::refEsmClass(void){
			return this->m_nEsmClass;
		}

		inline const unsigned char SMPPDataSM::getEsmClass(void) const{
			return this->m_nEsmClass;
		}


		inline void SMPPDataSM::setRegisteredDelivery(const unsigned char nRegisteredDelivery){
			this->m_nRegisteredDelivery = nRegisteredDelivery;
		}

		inline unsigned char& SMPPDataSM::refRegisteredDelivery(void){
			return this->m_nRegisteredDelivery;
		}

		inline const unsigned char SMPPDataSM::getRegisteredDelivery(void) const{
			return this->m_nRegisteredDelivery;
		}


		inline void SMPPDataSM::setDataCoding(const unsigned char nDataCoding){
			this->m_nDataCoding = nDataCoding;
		}

		inline unsigned char& SMPPDataSM::refDataCoding(void){
			return this->m_nDataCoding;
		}

		inline const unsigned char SMPPDataSM::getDataCoding(void) const{
			return this->m_nDataCoding;
		}

		inline void SMPPDataSM::setSourcePort(const unsigned short nSourcePort){
			this->m_nSourcePort = nSourcePort;
			this->m_bPresentSourcePort = true;
		}

		inline unsigned short& SMPPDataSM::refSourcePort(void){
			return this->m_nSourcePort;
		}

		inline const unsigned short SMPPDataSM::getSourcePort(void) const{
			return this->m_nSourcePort;
		}

		inline void SMPPDataSM::setSourceAddrSubunit(const unsigned char nSourceAddrSubunit){
			this->m_nSourceAddrSubunit = nSourceAddrSubunit;
			this->m_bPresentSourceAddrSubunit = true;
		}

		inline unsigned char& SMPPDataSM::refSourceAddrSubunit(void){
			return this->m_nSourceAddrSubunit;
		}

		inline const unsigned char SMPPDataSM::getSourceAddrSubunit(void) const{
			return this->m_nSourceAddrSubunit;
		}

		inline void SMPPDataSM::setSourceNetworkType(const unsigned char nSourceNetworkType){
			this->m_nSourceNetworkType = nSourceNetworkType;
			this->m_bPresentSourceNetworkType = true;
		}

		inline unsigned char& SMPPDataSM::refSourceNetworkType(void){
			return this->m_nSourceNetworkType;
		}

		inline const unsigned char SMPPDataSM::getSourceNetworkType(void) const{
			return this->m_nSourceNetworkType;
		}

		inline void SMPPDataSM::setSourceBearerType(const unsigned char nSourceBearerType){
			this->m_nSourceBearerType = nSourceBearerType;
			this->m_bPresentSourceBearerType = true;
		}

		inline unsigned char& SMPPDataSM::refSourceBearerType(void){
			return this->m_nSourceBearerType;
		}

		inline const unsigned char SMPPDataSM::getSourceBearerType(void) const{
			return this->m_nSourceBearerType;
		}

		inline void SMPPDataSM::setSourceTelematicsId(const unsigned char nSourceTelematicsId){
			this->m_nSourceTelematicsId = nSourceTelematicsId;
			this->m_bPresentSourceTelematicsId = true;
		}

		inline unsigned char& SMPPDataSM::refSourceTelematicsId(void){
			return this->m_nSourceTelematicsId;
		}

		inline const unsigned char SMPPDataSM::getSourceTelematicsId(void) const{
			return this->m_nSourceTelematicsId;
		}

		inline void SMPPDataSM::setDestinationPort(const unsigned short nDestinationPort){
			this->m_nDestinationPort = nDestinationPort;
			this->m_bPresentDestinationPort = true;
		}

		inline unsigned short& SMPPDataSM::refDestinationPort(void){
			return this->m_nDestinationPort;
		}

		inline const unsigned short SMPPDataSM::getDestinationPort(void) const{
			return this->m_nDestinationPort;
		}

		inline void SMPPDataSM::setDestAddrSubunit(const unsigned char nDestAddrSubunit){
			this->m_nDestAddrSubunit = nDestAddrSubunit;
			this->m_bPresentDestAddrSubunit = true;
		}

		inline unsigned char& SMPPDataSM::refDestAddrSubunit(void){
			return this->m_nDestAddrSubunit;
		}

		inline const unsigned char SMPPDataSM::getDestAddrSubunit(void) const{
			return this->m_nDestAddrSubunit;
		}

		inline void SMPPDataSM::setDestNetworkType(const unsigned char nDestNetworkType){
			this->m_nDestNetworkType = nDestNetworkType;
			this->m_bPresentDestNetworkType = true;
		}

		inline unsigned char& SMPPDataSM::refDestNetworkType(void){
			return this->m_nDestNetworkType;
		}

		inline const unsigned char SMPPDataSM::getDestNetworkType(void) const{
			return this->m_nDestNetworkType;
		}

		inline void SMPPDataSM::setDestBearerType(const unsigned char nDestBearerType){
			this->m_nDestBearerType = nDestBearerType;
			this->m_bPresentDestBearerType = true;
		}

		inline unsigned char& SMPPDataSM::refDestBearerType(void){
			return this->m_nDestBearerType;
		}

		inline const unsigned char SMPPDataSM::getDestBearerType(void) const{
			return this->m_nDestBearerType;
		}

		inline void SMPPDataSM::setDestTelematicsId(const unsigned char nDestTelematicsId){
			this->m_nDestTelematicsId = nDestTelematicsId;
			this->m_bPresentDestTelematicsId = true;
		}

		inline unsigned char& SMPPDataSM::refDestTelematicsId(void){
			return this->m_nDestTelematicsId;
		}

		inline const unsigned char SMPPDataSM::getDestTelematicsId(void) const{
			return this->m_nDestTelematicsId;
		}

		inline void SMPPDataSM::setSarMsgRefNum(const unsigned short nSarMsgRefNum){
			this->m_nSarMsgRefNum = nSarMsgRefNum;
			this->m_bPresentSarMsgRefNum = true;
		}

		inline unsigned short& SMPPDataSM::refSarMsgRefNum(void){
			return this->m_nSarMsgRefNum;
		}

		inline const unsigned short SMPPDataSM::getSarMsgRefNum(void) const{
			return this->m_nSarMsgRefNum;
		}

		inline void SMPPDataSM::setSarTotalSegments(const unsigned char nSarTotalSegments){
			this->m_nSarTotalSegments = nSarTotalSegments;
			this->m_bPresentSarTotalSegments = true;
		}

		inline unsigned char& SMPPDataSM::refSarTotalSegments(void){
			return this->m_nSarTotalSegments;
		}

		inline const unsigned char SMPPDataSM::getSarTotalSegments(void) const{
			return this->m_nSarTotalSegments;
		}

		inline void SMPPDataSM::setSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum){
			this->m_nSarSegmentSeqnum = nSarSegmentSeqnum;
			this->m_bPresentSarSegmentSeqnum = true;
		}

		inline unsigned char& SMPPDataSM::refSarSegmentSeqnum(void){
			return this->m_nSarSegmentSeqnum;
		}

		inline const unsigned char SMPPDataSM::getSarSegmentSeqnum(void) const{
			return this->m_nSarSegmentSeqnum;
		}

		inline void SMPPDataSM::setMoreMessagesToSend(const unsigned char nMoreMessagesToSend){
			this->m_nMoreMessagesToSend = nMoreMessagesToSend;
			this->m_bPresentMoreMessagesToSend = true;
		}

		inline unsigned char& SMPPDataSM::refMoreMessagesToSend(void){
			return this->m_nMoreMessagesToSend;
		}

		inline const unsigned char SMPPDataSM::getMoreMessagesToSend(void) const{
			return this->m_nMoreMessagesToSend;
		}

		inline void SMPPDataSM::setQosTimeToLive(const unsigned nQosTimeToLive){
			this->m_nQosTimeToLive = nQosTimeToLive;
			this->m_bPresentQosTimeToLive = true;
		}

		inline unsigned& SMPPDataSM::refQosTimeToLive(void){
			return this->m_nQosTimeToLive;
		}

		inline const unsigned SMPPDataSM::getQosTimeToLive(void) const{
			return this->m_nQosTimeToLive;
		}

		inline void SMPPDataSM::setPayloadType(const unsigned char nPayloadType){
			this->m_nPayloadType = nPayloadType;
			this->m_bPresentPayloadType = true;
		}

		inline unsigned char& SMPPDataSM::refPayloadType(void){
			return this->m_nPayloadType;
		}

		inline const unsigned char SMPPDataSM::getPayloadType(void) const{
			return this->m_nPayloadType;
		}

		inline void SMPPDataSM::setMessagePayload(const std::vector<unsigned char>& aMessagePayload){
			this->m_nMessagePayloadLen = aMessagePayload.size();
			this->m_aMessagePayload = aMessagePayload;
			this->m_bPresentMessagePayload = true;
		}

		inline std::vector<unsigned char>& SMPPDataSM::refMessagePayload(void){
			return this->m_aMessagePayload;
		}

		inline const std::vector<unsigned char>& SMPPDataSM::getMessagePayload(void) const{
			return this->m_aMessagePayload;
		}

		inline void SMPPDataSM::setSetDpf(const unsigned char nSetDpf){
			this->m_nSetDpf = nSetDpf;
			this->m_bPresentSetDpf = true;
		}

		inline unsigned char& SMPPDataSM::refSetDpf(void){
			return this->m_nSetDpf;
		}

		inline const unsigned char SMPPDataSM::getSetDpf(void) const{
			return this->m_nSetDpf;
		}

		inline void SMPPDataSM::setReceiptedMessageId(const std::string& sReceiptedMessageId){
			this->m_nReceiptedMessageIdLen = sReceiptedMessageId.size() + 1;
			this->m_sReceiptedMessageId = sReceiptedMessageId;
			this->m_bPresentReceiptedMessageId = true;
		}

		inline void SMPPDataSM::setReceiptedMessageId(const unsigned nReceiptedMessageId){
			char szBuffer[128];
			memset(szBuffer,0,sizeof(szBuffer));
			sprintf(szBuffer, "%d", nReceiptedMessageId);

			this->m_nReceiptedMessageIdLen = strlen(szBuffer) + 1;
			this->m_sReceiptedMessageId = std::string(szBuffer);
			this->m_bPresentReceiptedMessageId = true;
		}

		inline std::string& SMPPDataSM::refReceiptedMessageId(void){
			return this->m_sReceiptedMessageId;
		}

		inline const std::string& SMPPDataSM::getReceiptedMessageId(void) const{
			return this->m_sReceiptedMessageId;
		}

		inline void SMPPDataSM::setMessageState(const unsigned char nMessageState){
			this->m_nMessageState = nMessageState;
			this->m_bPresentMessageState = true;
		}

		inline unsigned char& SMPPDataSM::refMessageState(void){
			return this->m_nMessageState;
		}

		inline const unsigned char SMPPDataSM::getMessageState(void) const{
			return this->m_nMessageState;
		}

		inline void SMPPDataSM::setNetworkErrorCode(const unsigned char nNetworkCode, const unsigned short nErrorCode){
			this->m_oNetworkErrorCode.setNetworkCode(nNetworkCode);
			this->m_oNetworkErrorCode.setErrorCode(nErrorCode);
			this->m_bPresentNetworkErrorCode = true;
		}

		inline void SMPPDataSM::setNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode){
			this->m_oNetworkErrorCode = oNetworkErrorCode;
			this->m_bPresentNetworkErrorCode = true;
		}

		inline NetworkErrorCode& SMPPDataSM::refNetworkErrorCode(void){
			return this->m_oNetworkErrorCode;
		}

		inline const NetworkErrorCode& SMPPDataSM::getNetworkErrorCode(void) const{
			return this->m_oNetworkErrorCode;
		}


		inline void SMPPDataSM::setUserMessageReference(const unsigned short nUserMessageReference){
			this->m_nUserMessageReference = nUserMessageReference;
			this->m_bPresentUserMessageReference = true;
		}

		inline unsigned short& SMPPDataSM::refUserMessageReference(void){
			return this->m_nUserMessageReference;
		}

		inline const unsigned short SMPPDataSM::getUserMessageReference(void) const{
			return this->m_nUserMessageReference;
		}

		inline void SMPPDataSM::setPrivacyIndicator(const unsigned char nPrivacyIndicator){
			this->m_nPrivacyIndicator = nPrivacyIndicator;
			this->m_bPresentPrivacyIndicator = true;
		}

		inline unsigned char& SMPPDataSM::refPrivacyIndicator(void){
			return this->m_nPrivacyIndicator;
		}

		inline const unsigned char SMPPDataSM::getPrivacyIndicator(void) const{
			return this->m_nPrivacyIndicator;
		}

		inline void SMPPDataSM::setCallbackNum(const std::vector<unsigned char>& aCallbackNum){
			this->m_nCallbackNumLen = aCallbackNum.size();
			this->m_aCallbackNum = aCallbackNum;
			this->m_bPresentCallbackNum = true;
		}

		inline std::vector<unsigned char>& SMPPDataSM::refCallbackNum(void){
			return this->m_aCallbackNum;
		}

		inline const std::vector<unsigned char>& SMPPDataSM::getCallbackNum(void) const{
			return this->m_aCallbackNum;
		}

		inline void SMPPDataSM::setCallbackNumPresInd(const unsigned char nCallbackNumPresInd){
			this->m_nCallbackNumPresInd = nCallbackNumPresInd;
			this->m_bPresentCallbackNumPresInd = true;
		}

		inline unsigned char& SMPPDataSM::refCallbackNumPresInd(void){
			return this->m_nCallbackNumPresInd;
		}

		inline const unsigned char SMPPDataSM::getCallbackNumPresInd(void) const{
			return this->m_nCallbackNumPresInd;
		}

		inline void SMPPDataSM::setCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag){
			this->m_nCallbackNumAtagLen = aCallbackNumAtag.size();
			this->m_aCallbackNumAtag = aCallbackNumAtag;
			this->m_bPresentCallbackNumAtag = true;
		}

		inline std::vector<unsigned char>& SMPPDataSM::refCallbackNumAtag(void){
			return this->m_aCallbackNumAtag;
		}

		inline const std::vector<unsigned char>& SMPPDataSM::getCallbackNumAtag(void) const{
			return this->m_aCallbackNumAtag;
		}

		inline void SMPPDataSM::setSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress){
			this->m_nSourceSubaddressLen = aSourceSubaddress.size();
			this->m_aSourceSubaddress = aSourceSubaddress;
			this->m_bPresentSourceSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPDataSM::refSourceSubaddress(void){
			return this->m_aSourceSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPDataSM::getSourceSubaddress(void) const{
			return this->m_aSourceSubaddress;
		}

		inline void SMPPDataSM::setDestSubaddress(const std::vector<unsigned char>& aDestSubaddress){
			this->m_nDestSubaddressLen = aDestSubaddress.size();
			this->m_aDestSubaddress = aDestSubaddress;
			this->m_bPresentDestSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPDataSM::refDestSubaddress(void){
			return this->m_aDestSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPDataSM::getDestSubaddress(void) const{
			return this->m_aDestSubaddress;
		}

		inline void SMPPDataSM::setUserResponseCode(const unsigned char nUserResponseCode){
			this->m_nUserResponseCode = nUserResponseCode;
			this->m_bPresentUserResponseCode = true;
		}

		inline unsigned char& SMPPDataSM::refUserResponseCode(void){
			return this->m_nUserResponseCode;
		}

		inline const unsigned char SMPPDataSM::getUserResponseCode(void) const{
			return this->m_nUserResponseCode;
		}

		inline void SMPPDataSM::setDisplayTime(const unsigned char nDisplayTime){
			this->m_nDisplayTime = nDisplayTime;
			this->m_bPresentDisplayTime = true;
		}

		inline unsigned char& SMPPDataSM::refDisplayTime(void){
			return this->m_nDisplayTime;
		}

		inline const unsigned char SMPPDataSM::getDisplayTime(void) const{
			return this->m_nDisplayTime;
		}

		inline void SMPPDataSM::setSmsSignal(const unsigned short nSmsSignal){
			this->m_nSmsSignal = nSmsSignal;
			this->m_bPresentSmsSignal = true;
		}

		inline unsigned short& SMPPDataSM::refSmsSignal(void){
			return this->m_nSmsSignal;
		}

		inline const unsigned short SMPPDataSM::getSmsSignal(void) const{
			return this->m_nSmsSignal;
		}

		inline void SMPPDataSM::setMsValidity(const unsigned char nMsValidity){
			this->m_nMsValidity = nMsValidity;
			this->m_bPresentMsValidity = true;
		}

		inline unsigned char& SMPPDataSM::refMsValidity(void){
			return this->m_nMsValidity;
		}

		inline const unsigned char SMPPDataSM::getMsValidity(void) const{
			return this->m_nMsValidity;
		}

		inline void SMPPDataSM::setMsMsgWaitFacilities(const unsigned char nMsMsgWaitFacilities){
			this->m_nMsMsgWaitFacilities = nMsMsgWaitFacilities;
			this->m_bPresentMsMsgWaitFacilities = true;
		}

		inline unsigned char& SMPPDataSM::refMsMsgWaitFacilities(void){
			return this->m_nMsMsgWaitFacilities;
		}

		inline const unsigned char SMPPDataSM::getMsMsgWaitFacilities(void) const{
			return this->m_nMsMsgWaitFacilities;
		}

		inline void SMPPDataSM::setNumberOfMessages(const unsigned char nNumberOfMessages){
			this->m_nNumberOfMessages = nNumberOfMessages;
			this->m_bPresentNumberOfMessages = true;
		}

		inline unsigned char& SMPPDataSM::refNumberOfMessages(void){
			return this->m_nNumberOfMessages;
		}

		inline const unsigned char SMPPDataSM::getNumberOfMessages(void) const{
			return this->m_nNumberOfMessages;
		}

		inline void SMPPDataSM::setAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery){
			this->m_nAlertOnMsgDelivery = nAlertOnMsgDelivery;
			this->m_bPresentAlertOnMsgDelivery = true;
		}

		inline unsigned char& SMPPDataSM::refAlertOnMsgDelivery(void){
			return this->m_nAlertOnMsgDelivery;
		}

		inline const unsigned char SMPPDataSM::getAlertOnMsgDelivery(void) const{
			return this->m_nAlertOnMsgDelivery;
		}

		inline void SMPPDataSM::setLanguageIndicator(const unsigned char nLanguageIndicator){
			this->m_nLanguageIndicator = nLanguageIndicator;
			this->m_bPresentLanguageIndicator = true;
		}

		inline unsigned char& SMPPDataSM::refLanguageIndicator(void){
			return this->m_nLanguageIndicator;
		}

		inline const unsigned char SMPPDataSM::getLanguageIndicator(void) const{
			return this->m_nLanguageIndicator;
		}

		inline void SMPPDataSM::setItsReplyType(const unsigned char nItsReplyType){
			this->m_nItsReplyType = nItsReplyType;
			this->m_bPresentItsReplyType = true;
		}

		inline unsigned char& SMPPDataSM::refItsReplyType(void){
			return this->m_nItsReplyType;
		}

		inline const unsigned char SMPPDataSM::getItsReplyType(void) const{
			return this->m_nItsReplyType;
		}

		inline void SMPPDataSM::setItsSessionInfo(const unsigned short nItsSessionInfo){
			this->m_nItsSessionInfo = nItsSessionInfo;
			this->m_bPresentItsSessionInfo = true;
		}

		inline unsigned short& SMPPDataSM::refItsSessionInfo(void){
			return this->m_nItsSessionInfo;
		}

		inline const unsigned short SMPPDataSM::getItsSessionInfo(void) const{
			return this->m_nItsSessionInfo;
		}


		inline void SMPPDataSM::setSourcePortLen(const unsigned short nSourcePortLen){
			this->m_nSourcePortLen = nSourcePortLen;
		}

		inline unsigned short& SMPPDataSM::refSourcePortLen(void){
			return this->m_nSourcePortLen;
		}

		inline const unsigned short SMPPDataSM::getSourcePortLen(void) const{
			return this->m_nSourcePortLen;
		}


		inline void SMPPDataSM::setSourceAddrSubunitLen(const unsigned short nSourceAddrSubunitLen){
			this->m_nSourceAddrSubunitLen = nSourceAddrSubunitLen;
		}

		inline unsigned short& SMPPDataSM::refSourceAddrSubunitLen(void){
			return this->m_nSourceAddrSubunitLen;
		}

		inline const unsigned short SMPPDataSM::getSourceAddrSubunitLen(void) const{
			return this->m_nSourceAddrSubunitLen;
		}


		inline void SMPPDataSM::setSourceNetworkTypeLen(const unsigned short nSourceNetworkTypeLen){
			this->m_nSourceNetworkTypeLen = nSourceNetworkTypeLen;
		}

		inline unsigned short& SMPPDataSM::refSourceNetworkTypeLen(void){
			return this->m_nSourceNetworkTypeLen;
		}

		inline const unsigned short SMPPDataSM::getSourceNetworkTypeLen(void) const{
			return this->m_nSourceNetworkTypeLen;
		}


		inline void SMPPDataSM::setSourceBearerTypeLen(const unsigned short nSourceBearerTypeLen){
			this->m_nSourceBearerTypeLen = nSourceBearerTypeLen;
		}

		inline unsigned short& SMPPDataSM::refSourceBearerTypeLen(void){
			return this->m_nSourceBearerTypeLen;
		}

		inline const unsigned short SMPPDataSM::getSourceBearerTypeLen(void) const{
			return this->m_nSourceBearerTypeLen;
		}


		inline void SMPPDataSM::setSourceTelematicsIdLen(const unsigned short nSourceTelematicsIdLen){
			this->m_nSourceTelematicsIdLen = nSourceTelematicsIdLen;
		}

		inline unsigned short& SMPPDataSM::refSourceTelematicsIdLen(void){
			return this->m_nSourceTelematicsIdLen;
		}

		inline const unsigned short SMPPDataSM::getSourceTelematicsIdLen(void) const{
			return this->m_nSourceTelematicsIdLen;
		}


		inline void SMPPDataSM::setDestinationPortLen(const unsigned short nDestinationPortLen){
			this->m_nDestinationPortLen = nDestinationPortLen;
		}

		inline unsigned short& SMPPDataSM::refDestinationPortLen(void){
			return this->m_nDestinationPortLen;
		}

		inline const unsigned short SMPPDataSM::getDestinationPortLen(void) const{
			return this->m_nDestinationPortLen;
		}


		inline void SMPPDataSM::setDestAddrSubunitLen(const unsigned short nDestAddrSubunitLen){
			this->m_nDestAddrSubunitLen = nDestAddrSubunitLen;
		}

		inline unsigned short& SMPPDataSM::refDestAddrSubunitLen(void){
			return this->m_nDestAddrSubunitLen;
		}

		inline const unsigned short SMPPDataSM::getDestAddrSubunitLen(void) const{
			return this->m_nDestAddrSubunitLen;
		}


		inline void SMPPDataSM::setDestNetworkTypeLen(const unsigned short nDestNetworkTypeLen){
			this->m_nDestNetworkTypeLen = nDestNetworkTypeLen;
		}

		inline unsigned short& SMPPDataSM::refDestNetworkTypeLen(void){
			return this->m_nDestNetworkTypeLen;
		}

		inline const unsigned short SMPPDataSM::getDestNetworkTypeLen(void) const{
			return this->m_nDestNetworkTypeLen;
		}


		inline void SMPPDataSM::setDestBearerTypeLen(const unsigned short nDestBearerTypeLen){
			this->m_nDestBearerTypeLen = nDestBearerTypeLen;
		}

		inline unsigned short& SMPPDataSM::refDestBearerTypeLen(void){
			return this->m_nDestBearerTypeLen;
		}

		inline const unsigned short SMPPDataSM::getDestBearerTypeLen(void) const{
			return this->m_nDestBearerTypeLen;
		}


		inline void SMPPDataSM::setDestTelematicsIdLen(const unsigned short nDestTelematicsIdLen){
			this->m_nDestTelematicsIdLen = nDestTelematicsIdLen;
		}

		inline unsigned short& SMPPDataSM::refDestTelematicsIdLen(void){
			return this->m_nDestTelematicsIdLen;
		}

		inline const unsigned short SMPPDataSM::getDestTelematicsIdLen(void) const{
			return this->m_nDestTelematicsIdLen;
		}


		inline void SMPPDataSM::setSarMsgRefNumLen(const unsigned short nSarMsgRefNumLen){
			this->m_nSarMsgRefNumLen = nSarMsgRefNumLen;
		}

		inline unsigned short& SMPPDataSM::refSarMsgRefNumLen(void){
			return this->m_nSarMsgRefNumLen;
		}

		inline const unsigned short SMPPDataSM::getSarMsgRefNumLen(void) const{
			return this->m_nSarMsgRefNumLen;
		}


		inline void SMPPDataSM::setSarTotalSegmentsLen(const unsigned short nSarTotalSegmentsLen){
			this->m_nSarTotalSegmentsLen = nSarTotalSegmentsLen;
		}

		inline unsigned short& SMPPDataSM::refSarTotalSegmentsLen(void){
			return this->m_nSarTotalSegmentsLen;
		}

		inline const unsigned short SMPPDataSM::getSarTotalSegmentsLen(void) const{
			return this->m_nSarTotalSegmentsLen;
		}


		inline void SMPPDataSM::setSarSegmentSeqnumLen(const unsigned short nSarSegmentSeqnumLen){
			this->m_nSarSegmentSeqnumLen = nSarSegmentSeqnumLen;
		}

		inline unsigned short& SMPPDataSM::refSarSegmentSeqnumLen(void){
			return this->m_nSarSegmentSeqnumLen;
		}

		inline const unsigned short SMPPDataSM::getSarSegmentSeqnumLen(void) const{
			return this->m_nSarSegmentSeqnumLen;
		}


		inline void SMPPDataSM::setMoreMessagesToSendLen(const unsigned short nMoreMessagesToSendLen){
			this->m_nMoreMessagesToSendLen = nMoreMessagesToSendLen;
		}

		inline unsigned short& SMPPDataSM::refMoreMessagesToSendLen(void){
			return this->m_nMoreMessagesToSendLen;
		}

		inline const unsigned short SMPPDataSM::getMoreMessagesToSendLen(void) const{
			return this->m_nMoreMessagesToSendLen;
		}


		inline void SMPPDataSM::setQosTimeToLiveLen(const unsigned short nQosTimeToLiveLen){
			this->m_nQosTimeToLiveLen = nQosTimeToLiveLen;
		}

		inline unsigned short& SMPPDataSM::refQosTimeToLiveLen(void){
			return this->m_nQosTimeToLiveLen;
		}

		inline const unsigned short SMPPDataSM::getQosTimeToLiveLen(void) const{
			return this->m_nQosTimeToLiveLen;
		}


		inline void SMPPDataSM::setPayloadTypeLen(const unsigned short nPayloadTypeLen){
			this->m_nPayloadTypeLen = nPayloadTypeLen;
		}

		inline unsigned short& SMPPDataSM::refPayloadTypeLen(void){
			return this->m_nPayloadTypeLen;
		}

		inline const unsigned short SMPPDataSM::getPayloadTypeLen(void) const{
			return this->m_nPayloadTypeLen;
		}


		inline void SMPPDataSM::setMessagePayloadLen(const unsigned short nMessagePayloadLen){
			this->m_nMessagePayloadLen = nMessagePayloadLen;
		}

		inline unsigned short& SMPPDataSM::refMessagePayloadLen(void){
			return this->m_nMessagePayloadLen;
		}

		inline const unsigned short SMPPDataSM::getMessagePayloadLen(void) const{
			return this->m_nMessagePayloadLen;
		}


		inline void SMPPDataSM::setSetDpfLen(const unsigned short nSetDpfLen){
			this->m_nSetDpfLen = nSetDpfLen;
		}

		inline unsigned short& SMPPDataSM::refSetDpfLen(void){
			return this->m_nSetDpfLen;
		}

		inline const unsigned short SMPPDataSM::getSetDpfLen(void) const{
			return this->m_nSetDpfLen;
		}


		inline void SMPPDataSM::setReceiptedMessageIdLen(const unsigned short nReceiptedMessageIdLen){
			this->m_nReceiptedMessageIdLen = nReceiptedMessageIdLen;
		}

		inline unsigned short& SMPPDataSM::refReceiptedMessageIdLen(void){
			return this->m_nReceiptedMessageIdLen;
		}

		inline const unsigned short SMPPDataSM::getReceiptedMessageIdLen(void) const{
			return this->m_nReceiptedMessageIdLen;
		}


		inline void SMPPDataSM::setMessageStateLen(const unsigned short nMessageStateLen){
			this->m_nMessageStateLen = nMessageStateLen;
		}

		inline unsigned short& SMPPDataSM::refMessageStateLen(void){
			return this->m_nMessageStateLen;
		}

		inline const unsigned short SMPPDataSM::getMessageStateLen(void) const{
			return this->m_nMessageStateLen;
		}


		inline void SMPPDataSM::setNetworkErrorCodeLen(const unsigned short nNetworkErrorCodeLen){
			this->m_nNetworkErrorCodeLen = nNetworkErrorCodeLen;
		}

		inline unsigned short& SMPPDataSM::refNetworkErrorCodeLen(void){
			return this->m_nNetworkErrorCodeLen;
		}

		inline const unsigned short SMPPDataSM::getNetworkErrorCodeLen(void) const{
			return this->m_nNetworkErrorCodeLen;
		}


		inline void SMPPDataSM::setUserMessageReferenceLen(const unsigned short nUserMessageReferenceLen){
			this->m_nUserMessageReferenceLen = nUserMessageReferenceLen;
		}

		inline unsigned short& SMPPDataSM::refUserMessageReferenceLen(void){
			return this->m_nUserMessageReferenceLen;
		}

		inline const unsigned short SMPPDataSM::getUserMessageReferenceLen(void) const{
			return this->m_nUserMessageReferenceLen;
		}


		inline void SMPPDataSM::setPrivacyIndicatorLen(const unsigned short nPrivacyIndicatorLen){
			this->m_nPrivacyIndicatorLen = nPrivacyIndicatorLen;
		}

		inline unsigned short& SMPPDataSM::refPrivacyIndicatorLen(void){
			return this->m_nPrivacyIndicatorLen;
		}

		inline const unsigned short SMPPDataSM::getPrivacyIndicatorLen(void) const{
			return this->m_nPrivacyIndicatorLen;
		}


		inline void SMPPDataSM::setCallbackNumLen(const unsigned short nCallbackNumLen){
			this->m_nCallbackNumLen = nCallbackNumLen;
		}

		inline unsigned short& SMPPDataSM::refCallbackNumLen(void){
			return this->m_nCallbackNumLen;
		}

		inline const unsigned short SMPPDataSM::getCallbackNumLen(void) const{
			return this->m_nCallbackNumLen;
		}


		inline void SMPPDataSM::setCallbackNumPresIndLen(const unsigned short nCallbackNumPresIndLen){
			this->m_nCallbackNumPresIndLen = nCallbackNumPresIndLen;
		}

		inline unsigned short& SMPPDataSM::refCallbackNumPresIndLen(void){
			return this->m_nCallbackNumPresIndLen;
		}

		inline const unsigned short SMPPDataSM::getCallbackNumPresIndLen(void) const{
			return this->m_nCallbackNumPresIndLen;
		}


		inline void SMPPDataSM::setCallbackNumAtagLen(const unsigned short nCallbackNumAtagLen){
			this->m_nCallbackNumAtagLen = nCallbackNumAtagLen;
		}

		inline unsigned short& SMPPDataSM::refCallbackNumAtagLen(void){
			return this->m_nCallbackNumAtagLen;
		}

		inline const unsigned short SMPPDataSM::getCallbackNumAtagLen(void) const{
			return this->m_nCallbackNumAtagLen;
		}


		inline void SMPPDataSM::setSourceSubaddressLen(const unsigned short nSourceSubaddressLen){
			this->m_nSourceSubaddressLen = nSourceSubaddressLen;
		}

		inline unsigned short& SMPPDataSM::refSourceSubaddressLen(void){
			return this->m_nSourceSubaddressLen;
		}

		inline const unsigned short SMPPDataSM::getSourceSubaddressLen(void) const{
			return this->m_nSourceSubaddressLen;
		}


		inline void SMPPDataSM::setDestSubaddressLen(const unsigned short nDestSubaddressLen){
			this->m_nDestSubaddressLen = nDestSubaddressLen;
		}

		inline unsigned short& SMPPDataSM::refDestSubaddressLen(void){
			return this->m_nDestSubaddressLen;
		}

		inline const unsigned short SMPPDataSM::getDestSubaddressLen(void) const{
			return this->m_nDestSubaddressLen;
		}


		inline void SMPPDataSM::setUserResponseCodeLen(const unsigned short nUserResponseCodeLen){
			this->m_nUserResponseCodeLen = nUserResponseCodeLen;
		}

		inline unsigned short& SMPPDataSM::refUserResponseCodeLen(void){
			return this->m_nUserResponseCodeLen;
		}

		inline const unsigned short SMPPDataSM::getUserResponseCodeLen(void) const{
			return this->m_nUserResponseCodeLen;
		}


		inline void SMPPDataSM::setDisplayTimeLen(const unsigned short nDisplayTimeLen){
			this->m_nDisplayTimeLen = nDisplayTimeLen;
		}

		inline unsigned short& SMPPDataSM::refDisplayTimeLen(void){
			return this->m_nDisplayTimeLen;
		}

		inline const unsigned short SMPPDataSM::getDisplayTimeLen(void) const{
			return this->m_nDisplayTimeLen;
		}


		inline void SMPPDataSM::setSmsSignalLen(const unsigned short nSmsSignalLen){
			this->m_nSmsSignalLen = nSmsSignalLen;
		}

		inline unsigned short& SMPPDataSM::refSmsSignalLen(void){
			return this->m_nSmsSignalLen;
		}

		inline const unsigned short SMPPDataSM::getSmsSignalLen(void) const{
			return this->m_nSmsSignalLen;
		}


		inline void SMPPDataSM::setMsValidityLen(const unsigned short nMsValidityLen){
			this->m_nMsValidityLen = nMsValidityLen;
		}

		inline unsigned short& SMPPDataSM::refMsValidityLen(void){
			return this->m_nMsValidityLen;
		}

		inline const unsigned short SMPPDataSM::getMsValidityLen(void) const{
			return this->m_nMsValidityLen;
		}


		inline void SMPPDataSM::setMsMsgWaitFacilitiesLen(const unsigned short nMsMsgWaitFacilitiesLen){
			this->m_nMsMsgWaitFacilitiesLen = nMsMsgWaitFacilitiesLen;
		}

		inline unsigned short& SMPPDataSM::refMsMsgWaitFacilitiesLen(void){
			return this->m_nMsMsgWaitFacilitiesLen;
		}

		inline const unsigned short SMPPDataSM::getMsMsgWaitFacilitiesLen(void) const{
			return this->m_nMsMsgWaitFacilitiesLen;
		}


		inline void SMPPDataSM::setNumberOfMessagesLen(const unsigned short nNumberOfMessagesLen){
			this->m_nNumberOfMessagesLen = nNumberOfMessagesLen;
		}

		inline unsigned short& SMPPDataSM::refNumberOfMessagesLen(void){
			return this->m_nNumberOfMessagesLen;
		}

		inline const unsigned short SMPPDataSM::getNumberOfMessagesLen(void) const{
			return this->m_nNumberOfMessagesLen;
		}


		inline void SMPPDataSM::setAlertOnMsgDeliveryLen(const unsigned short nAlertOnMsgDeliveryLen){
			this->m_nAlertOnMsgDeliveryLen = nAlertOnMsgDeliveryLen;
		}

		inline unsigned short& SMPPDataSM::refAlertOnMsgDeliveryLen(void){
			return this->m_nAlertOnMsgDeliveryLen;
		}

		inline const unsigned short SMPPDataSM::getAlertOnMsgDeliveryLen(void) const{
			return this->m_nAlertOnMsgDeliveryLen;
		}


		inline void SMPPDataSM::setLanguageIndicatorLen(const unsigned short nLanguageIndicatorLen){
			this->m_nLanguageIndicatorLen = nLanguageIndicatorLen;
		}

		inline unsigned short& SMPPDataSM::refLanguageIndicatorLen(void){
			return this->m_nLanguageIndicatorLen;
		}

		inline const unsigned short SMPPDataSM::getLanguageIndicatorLen(void) const{
			return this->m_nLanguageIndicatorLen;
		}


		inline void SMPPDataSM::setItsReplyTypeLen(const unsigned short nItsReplyTypeLen){
			this->m_nItsReplyTypeLen = nItsReplyTypeLen;
		}

		inline unsigned short& SMPPDataSM::refItsReplyTypeLen(void){
			return this->m_nItsReplyTypeLen;
		}

		inline const unsigned short SMPPDataSM::getItsReplyTypeLen(void) const{
			return this->m_nItsReplyTypeLen;
		}


		inline void SMPPDataSM::setItsSessionInfoLen(const unsigned short nItsSessionInfoLen){
			this->m_nItsSessionInfoLen = nItsSessionInfoLen;
		}

		inline unsigned short& SMPPDataSM::refItsSessionInfoLen(void){
			return this->m_nItsSessionInfoLen;
		}

		inline const unsigned short SMPPDataSM::getItsSessionInfoLen(void) const{
			return this->m_nItsSessionInfoLen;
		}



	}
}
