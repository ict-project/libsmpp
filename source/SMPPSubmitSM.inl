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

		inline const bool SMPPSubmitSM::isPresentUserMessageReference(void) const{
			return this->m_bPresentUserMessageReference;
		}

		inline void SMPPSubmitSM::omitPresentUserMessageReference(void){
			this->m_bPresentUserMessageReference = false;
		}

		inline void SMPPSubmitSM::setPresentUserMessageReference(const bool bPresentUserMessageReference){
			this->m_bPresentUserMessageReference = bPresentUserMessageReference;
		}

		inline const bool SMPPSubmitSM::isPresentSourcePort(void) const{
			return this->m_bPresentSourcePort;
		}

		inline void SMPPSubmitSM::omitPresentSourcePort(void){
			this->m_bPresentSourcePort = false;
		}

		inline void SMPPSubmitSM::setPresentSourcePort(const bool bPresentSourcePort){
			this->m_bPresentSourcePort = bPresentSourcePort;
		}

		inline const bool SMPPSubmitSM::isPresentSourceAddrSubunit(void) const{
			return this->m_bPresentSourceAddrSubunit;
		}

		inline void SMPPSubmitSM::omitPresentSourceAddrSubunit(void){
			this->m_bPresentSourceAddrSubunit = false;
		}

		inline void SMPPSubmitSM::setPresentSourceAddrSubunit(const bool bPresentSourceAddrSubunit){
			this->m_bPresentSourceAddrSubunit = bPresentSourceAddrSubunit;
		}

		inline const bool SMPPSubmitSM::isPresentDestinationPort(void) const{
			return this->m_bPresentDestinationPort;
		}

		inline void SMPPSubmitSM::omitPresentDestinationPort(void){
			this->m_bPresentDestinationPort = false;
		}

		inline void SMPPSubmitSM::setPresentDestinationPort(const bool bPresentDestinationPort){
			this->m_bPresentDestinationPort = bPresentDestinationPort;
		}

		inline const bool SMPPSubmitSM::isPresentDestAddrSubunit(void) const{
			return this->m_bPresentDestAddrSubunit;
		}

		inline void SMPPSubmitSM::omitPresentDestAddrSubunit(void){
			this->m_bPresentDestAddrSubunit= false;
		}

		inline void SMPPSubmitSM::setPresentDestAddrSubunit(const bool bPresentDestAddrSubunit){
			this->m_bPresentDestAddrSubunit = bPresentDestAddrSubunit;
		}

		inline const bool SMPPSubmitSM::isPresentSarMsgRefNum(void) const{
			return this->m_bPresentSarMsgRefNum;
		}

		inline void SMPPSubmitSM::omitPresentSarMsgRefNum(void){
			this->m_bPresentSarMsgRefNum = false;
		}

		inline void SMPPSubmitSM::setPresentSarMsgRefNum(const bool bPresentSarMsgRefNum){
			this->m_bPresentSarMsgRefNum = bPresentSarMsgRefNum;
		}

		inline const bool SMPPSubmitSM::isPresentSarTotalSegments(void) const{
			return this->m_bPresentSarTotalSegments;
		}

		inline void SMPPSubmitSM::omitPresentSarTotalSegments(void){
			this->m_bPresentSarTotalSegments = false;
		}

		inline void SMPPSubmitSM::setPresentSarTotalSegments(const bool bPresentSarTotalSegments){
			this->m_bPresentSarTotalSegments = bPresentSarTotalSegments;
		}

		inline const bool SMPPSubmitSM::isPresentSarSegmentSeqnum(void) const{
			return this->m_bPresentSarSegmentSeqnum;
		}

		inline void SMPPSubmitSM::omitPresentSarSegmentSeqnum(void){
			this->m_bPresentSarSegmentSeqnum = false;
		}

		inline void SMPPSubmitSM::setPresentSarSegmentSeqnum(const bool bPresentSarSegmentSeqnum){
			this->m_bPresentSarSegmentSeqnum = bPresentSarSegmentSeqnum;
		}

		inline const bool SMPPSubmitSM::isPresentMoreMessagesToSend(void) const{
			return this->m_bPresentMoreMessagesToSend;
		}

		inline void SMPPSubmitSM::omitPresentMoreMessagesToSend(void){
			this->m_bPresentMoreMessagesToSend = false;
		}

		inline void SMPPSubmitSM::setPresentMoreMessagesToSend(const bool bPresentMoreMessagesToSend){
			this->m_bPresentMoreMessagesToSend = bPresentMoreMessagesToSend;
		}

		inline const bool SMPPSubmitSM::isPresentPayloadType(void) const{
			return this->m_bPresentPayloadType;
		}

		inline void SMPPSubmitSM::omitPresentPayloadType(void){
			this->m_bPresentPayloadType = false;
		}

		inline void SMPPSubmitSM::setPresentPayloadType(const bool bPresentPayloadType){
			this->m_bPresentPayloadType = bPresentPayloadType;
		}

		inline const bool SMPPSubmitSM::isPresentMessagePayload(void) const{
			return this->m_bPresentMessagePayload;
		}

		inline void SMPPSubmitSM::omitPresentMessagePayload(void){
			this->m_bPresentMessagePayload = false;
		}

		inline void SMPPSubmitSM::setPresentMessagePayload(const bool bPresentMessagePayload){
			this->m_bPresentMessagePayload = bPresentMessagePayload;
		}

		inline const bool SMPPSubmitSM::isPresentPrivacyIndicator(void) const{
			return this->m_bPresentPrivacyIndicator;
		}

		inline void SMPPSubmitSM::omitPresentPrivacyIndicator(void){
			this->m_bPresentPrivacyIndicator = false;
		}

		inline void SMPPSubmitSM::setPresentPrivacyIndicator(const bool bPresentPrivacyIndicator){
			this->m_bPresentPrivacyIndicator = bPresentPrivacyIndicator;
		}

		inline const bool SMPPSubmitSM::isPresentCallbackNum(void) const{
			return this->m_bPresentCallbackNum;
		}

		inline void SMPPSubmitSM::omitPresentCallbackNum(void){
			this->m_bPresentCallbackNum = false;
		}

		inline void SMPPSubmitSM::setPresentCallbackNum(const bool bPresentCallbackNum){
			this->m_bPresentCallbackNum = bPresentCallbackNum;
		}

		inline const bool SMPPSubmitSM::isPresentCallbackNumPresInd(void) const{
			return this->m_bPresentCallbackNumPresInd;
		}

		inline void SMPPSubmitSM::omitPresentCallbackNumPresInd(void){
			this->m_bPresentCallbackNumPresInd = false;
		}

		inline void SMPPSubmitSM::setPresentCallbackNumPresInd(const bool bPresentCallbackNumPresInd){
			this->m_bPresentCallbackNumPresInd = bPresentCallbackNumPresInd;
		}

		inline const bool SMPPSubmitSM::isPresentCallbackNumAtag(void) const{
			return this->m_bPresentCallbackNumAtag;
		}

		inline void SMPPSubmitSM::omitPresentCallbackNumAtag(void){
			this->m_bPresentCallbackNumAtag = false;
		}

		inline void SMPPSubmitSM::setPresentCallbackNumAtag(const bool bPresentCallbackNumAtag){
			this->m_bPresentCallbackNumAtag = bPresentCallbackNumAtag;
		}

		inline const bool SMPPSubmitSM::isPresentSourceSubaddress(void) const{
			return this->m_bPresentSourceSubaddress;
		}

		inline void SMPPSubmitSM::omitPresentSourceSubaddress(void){
			this->m_bPresentSourceSubaddress = false;
		}

		inline void SMPPSubmitSM::setPresentSourceSubaddress(const bool bPresentSourceSubaddress){
			this->m_bPresentSourceSubaddress = bPresentSourceSubaddress;
		}

		inline const bool SMPPSubmitSM::isPresentDestSubaddress(void) const{
			return this->m_bPresentDestSubaddress;
		}

		inline void SMPPSubmitSM::omitPresentDestSubaddress(void){
			this->m_bPresentDestSubaddress = false;
		}

		inline void SMPPSubmitSM::setPresentDestSubaddress(const bool bPresentDestSubaddress){
			this->m_bPresentDestSubaddress = bPresentDestSubaddress;
		}

		inline const bool SMPPSubmitSM::isPresentUserResponseCode(void) const{
			return this->m_bPresentUserResponseCode;
		}

		inline void SMPPSubmitSM::omitPresentUserResponseCode(void){
			this->m_bPresentUserResponseCode= false;
		}

		inline void SMPPSubmitSM::setPresentUserResponseCode(const bool bPresentUserResponseCode){
			this->m_bPresentUserResponseCode = bPresentUserResponseCode;
		}

		inline const bool SMPPSubmitSM::isPresentDisplayTime(void) const{
			return this->m_bPresentDisplayTime;
		}

		inline void SMPPSubmitSM::omitPresentDisplayTime(void){
			this->m_bPresentDisplayTime = false;
		}

		inline void SMPPSubmitSM::setPresentDisplayTime(const bool bPresentDisplayTime){
			this->m_bPresentDisplayTime = bPresentDisplayTime;
		}

		inline const bool SMPPSubmitSM::isPresentSmsSignal(void) const{
			return this->m_bPresentSmsSignal;
		}

		inline void SMPPSubmitSM::omitPresentSmsSignal(void){
			this->m_bPresentSmsSignal = false;
		}

		inline void SMPPSubmitSM::setPresentSmsSignal(const bool bPresentSmsSignal){
			this->m_bPresentSmsSignal = bPresentSmsSignal;
		}

		inline const bool SMPPSubmitSM::isPresentMsValidity(void) const{
			return this->m_bPresentMsValidity;
		}

		inline void SMPPSubmitSM::omitPresentMsValidity(void){
			this->m_bPresentMsValidity = false;
		}

		inline void SMPPSubmitSM::setPresentMsValidity(const bool bPresentMsValidity){
			this->m_bPresentMsValidity = bPresentMsValidity;
		}

		inline const bool SMPPSubmitSM::isPresentMsMsgWaitFacilities(void) const{
			return this->m_bPresentMsMsgWaitFacilities;
		}

		inline void SMPPSubmitSM::omitPresentMsMsgWaitFacilities(void){
			this->m_bPresentMsMsgWaitFacilities = false;
		}

		inline void SMPPSubmitSM::setPresentMsMsgWaitFacilities(const bool bPresentMsMsgWaitFacilities){
			this->m_bPresentMsMsgWaitFacilities = bPresentMsMsgWaitFacilities;
		}

		inline const bool SMPPSubmitSM::isPresentNumberOfMessages(void) const{
			return this->m_bPresentNumberOfMessages;
		}

		inline void SMPPSubmitSM::omitPresentNumberOfMessages(void){
			this->m_bPresentNumberOfMessages = false;
		}

		inline void SMPPSubmitSM::setPresentNumberOfMessages(const bool bPresentNumberOfMessages){
			this->m_bPresentNumberOfMessages = bPresentNumberOfMessages;
		}

		inline const bool SMPPSubmitSM::isPresentAlertOnMsgDelivery(void) const{
			return this->m_bPresentAlertOnMsgDelivery;
		}

		inline void SMPPSubmitSM::omitPresentAlertOnMsgDelivery(void){
			this->m_bPresentAlertOnMsgDelivery = false;
		}

		inline void SMPPSubmitSM::setPresentAlertOnMsgDelivery(const bool bPresentAlertOnMsgDelivery){
			this->m_bPresentAlertOnMsgDelivery = bPresentAlertOnMsgDelivery;
		}

		inline const bool SMPPSubmitSM::isPresentLanguageIndicator(void) const{
			return this->m_bPresentLanguageIndicator;
		}

		inline void SMPPSubmitSM::omitPresentLanguageIndicator(void){
			this->m_bPresentLanguageIndicator = false;
		}

		inline void SMPPSubmitSM::setPresentLanguageIndicator(const bool bPresentLanguageIndicator){
			this->m_bPresentLanguageIndicator = bPresentLanguageIndicator;
		}

		inline const bool SMPPSubmitSM::isPresentItsReplyType(void) const{
			return this->m_bPresentItsReplyType;
		}

		inline void SMPPSubmitSM::omitPresentItsReplyType(void){
			this->m_bPresentItsReplyType = false;
		}

		inline void SMPPSubmitSM::setPresentItsReplyType(const bool bPresentItsReplyType){
			this->m_bPresentItsReplyType = bPresentItsReplyType;
		}

		inline const bool SMPPSubmitSM::isPresentItsSessionInfo(void) const{
			return this->m_bPresentItsSessionInfo;
		}

		inline void SMPPSubmitSM::omitPresentItsSessionInfo(void){
			this->m_bPresentItsSessionInfo = false;
		}

		inline void SMPPSubmitSM::setPresentItsSessionInfo(const bool bPresentItsSessionInfo){
			this->m_bPresentItsSessionInfo = bPresentItsSessionInfo;
		}

		inline const bool SMPPSubmitSM::isPresentUssdServiceOp(void) const{
			return this->m_bPresentUssdServiceOp;
		}

		inline void SMPPSubmitSM::omitPresentUssdServiceOp(void){
			this->m_bPresentUssdServiceOp = false;
		}

		inline void SMPPSubmitSM::setPresentUssdServiceOp(const bool bPresentUssdServiceOp){
			this->m_bPresentUssdServiceOp = bPresentUssdServiceOp;
		}

		inline void SMPPSubmitSM::setServiceType(const std::string& sServiceType){
			this->m_sServiceType = sServiceType;
		}

		inline std::string& SMPPSubmitSM::refServiceType(void){
			return this->m_sServiceType;
		}

		inline const std::string& SMPPSubmitSM::getServiceType(void) const{
			return this->m_sServiceType;
		}


		inline void SMPPSubmitSM::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPSubmitSM::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPSubmitSM::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPSubmitSM::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPSubmitSM::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPSubmitSM::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPSubmitSM::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPSubmitSM::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPSubmitSM::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}


		inline void SMPPSubmitSM::setDestAddrTON(const unsigned char nDestAddrTON){
			this->m_nDestAddrTON = nDestAddrTON;
		}

		inline unsigned char& SMPPSubmitSM::refDestAddrTON(void){
			return this->m_nDestAddrTON;
		}

		inline const unsigned char SMPPSubmitSM::getDestAddrTON(void) const{
			return this->m_nDestAddrTON;
		}


		inline void SMPPSubmitSM::setDestAddrNPI(const unsigned char nDestAddrNPI){
			this->m_nDestAddrNPI = nDestAddrNPI;
		}

		inline unsigned char& SMPPSubmitSM::refDestAddrNPI(void){
			return this->m_nDestAddrNPI;
		}

		inline const unsigned char SMPPSubmitSM::getDestAddrNPI(void) const{
			return this->m_nDestAddrNPI;
		}


		inline void SMPPSubmitSM::setDestAddr(const std::string& sDestAddr){
			this->m_sDestAddr = sDestAddr;
		}

		inline std::string& SMPPSubmitSM::refDestAddr(void){
			return this->m_sDestAddr;
		}

		inline const std::string& SMPPSubmitSM::getDestAddr(void) const{
			return this->m_sDestAddr;
		}


		inline void SMPPSubmitSM::setEsmClass(const unsigned char nEsmClass){
			this->m_nEsmClass = nEsmClass;
		}

		inline unsigned char& SMPPSubmitSM::refEsmClass(void){
			return this->m_nEsmClass;
		}

		inline const unsigned char SMPPSubmitSM::getEsmClass(void) const{
			return this->m_nEsmClass;
		}


		inline void SMPPSubmitSM::setProtocolId(const unsigned char nProtocolId){
			this->m_nProtocolId = nProtocolId;
		}

		inline unsigned char& SMPPSubmitSM::refProtocolId(void){
			return this->m_nProtocolId;
		}

		inline const unsigned char SMPPSubmitSM::getProtocolId(void) const{
			return this->m_nProtocolId;
		}


		inline void SMPPSubmitSM::setPriorityFlag(const unsigned char nPriorityFlag){
			this->m_nPriorityFlag = nPriorityFlag;
		}

		inline unsigned char& SMPPSubmitSM::refPriorityFlag(void){
			return this->m_nPriorityFlag;
		}

		inline const unsigned char SMPPSubmitSM::getPriorityFlag(void) const{
			return this->m_nPriorityFlag;
		}


		inline void SMPPSubmitSM::setScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			this->m_sScheduleDeliveryTime = sScheduleDeliveryTime;
		}

		inline std::string& SMPPSubmitSM::refScheduleDeliveryTime(void){
			return this->m_sScheduleDeliveryTime;
		}

		inline const std::string& SMPPSubmitSM::getScheduleDeliveryTime(void) const{
			return this->m_sScheduleDeliveryTime;
		}


		inline void SMPPSubmitSM::setValidityPeriod(const std::string& sValidityPeriod){
			this->m_sValidityPeriod = sValidityPeriod;
		}

		inline std::string& SMPPSubmitSM::refValidityPeriod(void){
			return this->m_sValidityPeriod;
		}

		inline const std::string& SMPPSubmitSM::getValidityPeriod(void) const{
			return this->m_sValidityPeriod;
		}


		inline void SMPPSubmitSM::setRegisteredDelivery(const unsigned char nRegisteredDelivery){
			this->m_nRegisteredDelivery = nRegisteredDelivery;
		}

		inline unsigned char& SMPPSubmitSM::refRegisteredDelivery(void){
			return this->m_nRegisteredDelivery;
		}

		inline const unsigned char SMPPSubmitSM::getRegisteredDelivery(void) const{
			return this->m_nRegisteredDelivery;
		}


		inline void SMPPSubmitSM::setReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){
			this->m_nReplaceIfPresentFlag = nReplaceIfPresentFlag;
		}

		inline unsigned char& SMPPSubmitSM::refReplaceIfPresentFlag(void){
			return this->m_nReplaceIfPresentFlag;
		}

		inline const unsigned char SMPPSubmitSM::getReplaceIfPresentFlag(void) const{
			return this->m_nReplaceIfPresentFlag;
		}


		inline void SMPPSubmitSM::setDataCoding(const unsigned char nDataCoding){
			this->m_nDataCoding = nDataCoding;
		}

		inline unsigned char& SMPPSubmitSM::refDataCoding(void){
			return this->m_nDataCoding;
		}

		inline const unsigned char SMPPSubmitSM::getDataCoding(void) const{
			return this->m_nDataCoding;
		}


		inline void SMPPSubmitSM::setSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			this->m_nSMDefaultMsgId = nSMDefaultMsgId;
		}

		inline unsigned char& SMPPSubmitSM::refSMDefaultMsgId(void){
			return this->m_nSMDefaultMsgId;
		}

		inline const unsigned char SMPPSubmitSM::getSMDefaultMsgId(void) const{
			return this->m_nSMDefaultMsgId;
		}


		inline void SMPPSubmitSM::setSMLength(const unsigned char nSMLength){
			this->m_nSMLength = nSMLength;
		}

		inline unsigned char& SMPPSubmitSM::refSMLength(void){
			return this->m_nSMLength;
		}

		inline const unsigned char SMPPSubmitSM::getSMLength(void) const{
			return this->m_nSMLength;
		}


		inline void SMPPSubmitSM::setShortMessage(const std::vector<unsigned char>& aShortMessage){
			this->m_aShortMessage = aShortMessage;
			this->m_nSMLength = this->m_aShortMessage.size();
		}

		inline void SMPPSubmitSM::setShortMessage(const std::string& sShortMessage){
			this->m_aShortMessage.resize(sShortMessage.size());
			this->m_aShortMessage.assign(sShortMessage.begin(), sShortMessage.end());
			this->m_nSMLength = this->m_aShortMessage.size();
		}

		inline std::vector<unsigned char>& SMPPSubmitSM::refShortMessage(void){
			return this->m_aShortMessage;
		}

		inline const std::vector<unsigned char>& SMPPSubmitSM::getShortMessage(void) const{
			return this->m_aShortMessage;
		}


		inline void SMPPSubmitSM::setUserMessageReference(const unsigned short nUserMessageReference){
			this->m_nUserMessageReference = nUserMessageReference;
			this->m_bPresentUserMessageReference = true;
		}

		inline unsigned short& SMPPSubmitSM::refUserMessageReference(void){
			return this->m_nUserMessageReference;
		}

		inline const unsigned short SMPPSubmitSM::getUserMessageReference(void) const{
			return this->m_nUserMessageReference;
		}

		inline void SMPPSubmitSM::setSourcePort(const unsigned short nSourcePort){
			this->m_nSourcePort = nSourcePort;
			this->m_bPresentSourcePort = true;
		}

		inline unsigned short& SMPPSubmitSM::refSourcePort(void){
			return this->m_nSourcePort;
		}

		inline const unsigned short SMPPSubmitSM::getSourcePort(void) const{
			return this->m_nSourcePort;
		}

		inline void SMPPSubmitSM::setSourceAddrSubunit(const unsigned char nSourceAddrSubunit){
			this->m_nSourceAddrSubunit = nSourceAddrSubunit;
			this->m_bPresentSourceAddrSubunit = true;
		}

		inline unsigned char& SMPPSubmitSM::refSourceAddrSubunit(void){
			return this->m_nSourceAddrSubunit;
		}

		inline const unsigned char SMPPSubmitSM::getSourceAddrSubunit(void) const{
			return this->m_nSourceAddrSubunit;
		}

		inline void SMPPSubmitSM::setDestinationPort(const unsigned short nDestinationPort){
			this->m_nDestinationPort = nDestinationPort;
			this->m_bPresentDestinationPort = true;
		}

		inline unsigned short& SMPPSubmitSM::refDestinationPort(void){
			return this->m_nDestinationPort;
		}

		inline const unsigned short SMPPSubmitSM::getDestinationPort(void) const{
			return this->m_nDestinationPort;
		}

		inline void SMPPSubmitSM::setDestAddrSubunit(const unsigned char nDestAddrSubunit){
			this->m_nDestAddrSubunit = nDestAddrSubunit;
			this->m_bPresentDestAddrSubunit = true;
		}

		inline unsigned char& SMPPSubmitSM::refDestAddrSubunit(void){
			return this->m_nDestAddrSubunit;
		}

		inline const unsigned char SMPPSubmitSM::getDestAddrSubunit(void) const{
			return this->m_nDestAddrSubunit;
		}

		inline void SMPPSubmitSM::setSarMsgRefNum(const unsigned short nSarMsgRefNum){
			this->m_nSarMsgRefNum = nSarMsgRefNum;
			this->m_bPresentSarMsgRefNum = true;
		}

		inline unsigned short& SMPPSubmitSM::refSarMsgRefNum(void){
			return this->m_nSarMsgRefNum;
		}

		inline const unsigned short SMPPSubmitSM::getSarMsgRefNum(void) const{
			return this->m_nSarMsgRefNum;
		}

		inline void SMPPSubmitSM::setSarTotalSegments(const unsigned char nSarTotalSegments){
			this->m_nSarTotalSegments = nSarTotalSegments;
			this->m_bPresentSarTotalSegments = true;
		}

		inline unsigned char& SMPPSubmitSM::refSarTotalSegments(void){
			return this->m_nSarTotalSegments;
		}

		inline const unsigned char SMPPSubmitSM::getSarTotalSegments(void) const{
			return this->m_nSarTotalSegments;
		}

		inline void SMPPSubmitSM::setSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum){
			this->m_nSarSegmentSeqnum = nSarSegmentSeqnum;
			this->m_bPresentSarSegmentSeqnum = true;
		}

		inline unsigned char& SMPPSubmitSM::refSarSegmentSeqnum(void){
			return this->m_nSarSegmentSeqnum;
		}

		inline const unsigned char SMPPSubmitSM::getSarSegmentSeqnum(void) const{
			return this->m_nSarSegmentSeqnum;
		}

		inline void SMPPSubmitSM::setMoreMessagesToSend(const unsigned char nMoreMessagesToSend){
			this->m_nMoreMessagesToSend = nMoreMessagesToSend;
			this->m_bPresentMoreMessagesToSend = true;
		}

		inline unsigned char& SMPPSubmitSM::refMoreMessagesToSend(void){
			return this->m_nMoreMessagesToSend;
		}

		inline const unsigned char SMPPSubmitSM::getMoreMessagesToSend(void) const{
			return this->m_nMoreMessagesToSend;
		}

		inline void SMPPSubmitSM::setPayloadType(const unsigned char nPayloadType){
			this->m_nPayloadType = nPayloadType;
			this->m_bPresentPayloadType = true;
		}

		inline unsigned char& SMPPSubmitSM::refPayloadType(void){
			return this->m_nPayloadType;
		}

		inline const unsigned char SMPPSubmitSM::getPayloadType(void) const{
			return this->m_nPayloadType;
		}

		inline void SMPPSubmitSM::setMessagePayload(const std::vector<unsigned char>& aMessagePayload){
			this->m_nMessagePayloadLen = aMessagePayload.size();
			this->m_aMessagePayload = aMessagePayload;
			this->m_bPresentMessagePayload = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitSM::refMessagePayload(void){
			return this->m_aMessagePayload;
		}

		inline const std::vector<unsigned char>& SMPPSubmitSM::getMessagePayload(void) const{
			return this->m_aMessagePayload;
		}

		inline void SMPPSubmitSM::setPrivacyIndicator(const unsigned char nPrivacyIndicator){
			this->m_nPrivacyIndicator = nPrivacyIndicator;
			this->m_bPresentPrivacyIndicator = true;
		}

		inline unsigned char& SMPPSubmitSM::refPrivacyIndicator(void){
			return this->m_nPrivacyIndicator;
		}

		inline const unsigned char SMPPSubmitSM::getPrivacyIndicator(void) const{
			return this->m_nPrivacyIndicator;
		}

		inline void SMPPSubmitSM::setCallbackNum(const std::vector<unsigned char>& aCallbackNum){
			this->m_nCallbackNumLen = aCallbackNum.size();
			this->m_aCallbackNum = aCallbackNum;
			this->m_bPresentCallbackNum = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitSM::refCallbackNum(void){
			return this->m_aCallbackNum;
		}

		inline const std::vector<unsigned char>& SMPPSubmitSM::getCallbackNum(void) const{
			return this->m_aCallbackNum;
		}

		inline void SMPPSubmitSM::setCallbackNumPresInd(const unsigned char nCallbackNumPresInd){
			this->m_nCallbackNumPresInd = nCallbackNumPresInd;
			this->m_bPresentCallbackNumPresInd = true;
		}

		inline unsigned char& SMPPSubmitSM::refCallbackNumPresInd(void){
			return this->m_nCallbackNumPresInd;
		}

		inline const unsigned char SMPPSubmitSM::getCallbackNumPresInd(void) const{
			return this->m_nCallbackNumPresInd;
		}

		inline void SMPPSubmitSM::setCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag){
			this->m_nCallbackNumAtagLen = aCallbackNumAtag.size();
			this->m_aCallbackNumAtag = aCallbackNumAtag;
			this->m_bPresentCallbackNumAtag = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitSM::refCallbackNumAtag(void){
			return this->m_aCallbackNumAtag;
		}

		inline const std::vector<unsigned char>& SMPPSubmitSM::getCallbackNumAtag(void) const{
			return this->m_aCallbackNumAtag;
		}

		inline void SMPPSubmitSM::setSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress){
			this->m_nSourceSubaddressLen = aSourceSubaddress.size();
			this->m_aSourceSubaddress = aSourceSubaddress;
			this->m_bPresentSourceSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitSM::refSourceSubaddress(void){
			return this->m_aSourceSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPSubmitSM::getSourceSubaddress(void) const{
			return this->m_aSourceSubaddress;
		}

		inline void SMPPSubmitSM::setDestSubaddress(const std::vector<unsigned char>& aDestSubaddress){
			this->m_nDestSubaddressLen = aDestSubaddress.size();
			this->m_aDestSubaddress = aDestSubaddress;
			this->m_bPresentDestSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitSM::refDestSubaddress(void){
			return this->m_aDestSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPSubmitSM::getDestSubaddress(void) const{
			return this->m_aDestSubaddress;
		}

		inline void SMPPSubmitSM::setUserResponseCode(const unsigned char nUserResponseCode){
			this->m_nUserResponseCode = nUserResponseCode;
			this->m_bPresentUserResponseCode = true;
		}

		inline unsigned char& SMPPSubmitSM::refUserResponseCode(void){
			return this->m_nUserResponseCode;
		}

		inline const unsigned char SMPPSubmitSM::getUserResponseCode(void) const{
			return this->m_nUserResponseCode;
		}

		inline void SMPPSubmitSM::setDisplayTime(const unsigned char nDisplayTime){
			this->m_nDisplayTime = nDisplayTime;
			this->m_bPresentDisplayTime = true;
		}

		inline unsigned char& SMPPSubmitSM::refDisplayTime(void){
			return this->m_nDisplayTime;
		}

		inline const unsigned char SMPPSubmitSM::getDisplayTime(void) const{
			return this->m_nDisplayTime;
		}

		inline void SMPPSubmitSM::setSmsSignal(const unsigned short nSmsSignal){
			this->m_nSmsSignal = nSmsSignal;
			this->m_bPresentSmsSignal = true;
		}

		inline unsigned short& SMPPSubmitSM::refSmsSignal(void){
			return this->m_nSmsSignal;
		}

		inline const unsigned short SMPPSubmitSM::getSmsSignal(void) const{
			return this->m_nSmsSignal;
		}

		inline void SMPPSubmitSM::setMsValidity(const unsigned char nMsValidity){
			this->m_nMsValidity = nMsValidity;
			this->m_bPresentMsValidity = true;
		}

		inline unsigned char& SMPPSubmitSM::refMsValidity(void){
			return this->m_nMsValidity;
		}

		inline const unsigned char SMPPSubmitSM::getMsValidity(void) const{
			return this->m_nMsValidity;
		}

		inline void SMPPSubmitSM::setMsMsgWaitFacilities(const unsigned char nMsMsgWaitFacilities){
			this->m_nMsMsgWaitFacilities = nMsMsgWaitFacilities;
			this->m_bPresentMsMsgWaitFacilities = true;
		}

		inline unsigned char& SMPPSubmitSM::refMsMsgWaitFacilities(void){
			return this->m_nMsMsgWaitFacilities;
		}

		inline const unsigned char SMPPSubmitSM::getMsMsgWaitFacilities(void) const{
			return this->m_nMsMsgWaitFacilities;
		}

		inline void SMPPSubmitSM::setNumberOfMessages(const unsigned char nNumberOfMessages){
			this->m_nNumberOfMessages = nNumberOfMessages;
			this->m_bPresentNumberOfMessages = true;
		}

		inline unsigned char& SMPPSubmitSM::refNumberOfMessages(void){
			return this->m_nNumberOfMessages;
		}

		inline const unsigned char SMPPSubmitSM::getNumberOfMessages(void) const{
			return this->m_nNumberOfMessages;
		}

		inline void SMPPSubmitSM::setAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery){
			this->m_nAlertOnMsgDelivery = nAlertOnMsgDelivery;
			this->m_bPresentAlertOnMsgDelivery = true;
		}

		inline unsigned char& SMPPSubmitSM::refAlertOnMsgDelivery(void){
			return this->m_nAlertOnMsgDelivery;
		}

		inline const unsigned char SMPPSubmitSM::getAlertOnMsgDelivery(void) const{
			return this->m_nAlertOnMsgDelivery;
		}

		inline void SMPPSubmitSM::setLanguageIndicator(const unsigned char nLanguageIndicator){
			this->m_nLanguageIndicator = nLanguageIndicator;
			this->m_bPresentLanguageIndicator = true;
		}

		inline unsigned char& SMPPSubmitSM::refLanguageIndicator(void){
			return this->m_nLanguageIndicator;
		}

		inline const unsigned char SMPPSubmitSM::getLanguageIndicator(void) const{
			return this->m_nLanguageIndicator;
		}

		inline void SMPPSubmitSM::setItsReplyType(const unsigned char nItsReplyType){
			this->m_nItsReplyType = nItsReplyType;
			this->m_bPresentItsReplyType = true;
		}

		inline unsigned char& SMPPSubmitSM::refItsReplyType(void){
			return this->m_nItsReplyType;
		}

		inline const unsigned char SMPPSubmitSM::getItsReplyType(void) const{
			return this->m_nItsReplyType;
		}

		inline void SMPPSubmitSM::setItsSessionInfo(const unsigned short nItsSessionInfo){
			this->m_nItsSessionInfo = nItsSessionInfo;
			this->m_bPresentItsSessionInfo = true;
		}

		inline unsigned short& SMPPSubmitSM::refItsSessionInfo(void){
			return this->m_nItsSessionInfo;
		}

		inline const unsigned short SMPPSubmitSM::getItsSessionInfo(void) const{
			return this->m_nItsSessionInfo;
		}

		inline void SMPPSubmitSM::setUssdServiceOp(const unsigned char nUssdServiceOp){
			this->m_nUssdServiceOp = nUssdServiceOp;
			this->m_bPresentUssdServiceOp = true;
		}

		inline unsigned char& SMPPSubmitSM::refUssdServiceOp(void){
			return this->m_nUssdServiceOp;
		}

		inline const unsigned char SMPPSubmitSM::getUssdServiceOp(void) const{
			return this->m_nUssdServiceOp;
		}

		inline void SMPPSubmitSM::setUserMessageReferenceLen(const unsigned short nUserMessageReferenceLen){
			this->m_nUserMessageReferenceLen = nUserMessageReferenceLen;
		}

		inline unsigned short& SMPPSubmitSM::refUserMessageReferenceLen(void){
			return this->m_nUserMessageReferenceLen;
		}

		inline const unsigned short SMPPSubmitSM::getUserMessageReferenceLen(void) const{
			return this->m_nUserMessageReferenceLen;
		}


		inline void SMPPSubmitSM::setSourcePortLen(const unsigned short nSourcePortLen){
			this->m_nSourcePortLen = nSourcePortLen;
		}

		inline unsigned short& SMPPSubmitSM::refSourcePortLen(void){
			return this->m_nSourcePortLen;
		}

		inline const unsigned short SMPPSubmitSM::getSourcePortLen(void) const{
			return this->m_nSourcePortLen;
		}


		inline void SMPPSubmitSM::setSourceAddrSubunitLen(const unsigned short nSourceAddrSubunitLen){
			this->m_nSourceAddrSubunitLen = nSourceAddrSubunitLen;
		}

		inline unsigned short& SMPPSubmitSM::refSourceAddrSubunitLen(void){
			return this->m_nSourceAddrSubunitLen;
		}

		inline const unsigned short SMPPSubmitSM::getSourceAddrSubunitLen(void) const{
			return this->m_nSourceAddrSubunitLen;
		}


		inline void SMPPSubmitSM::setDestinationPortLen(const unsigned short nDestinationPortLen){
			this->m_nDestinationPortLen = nDestinationPortLen;
		}

		inline unsigned short& SMPPSubmitSM::refDestinationPortLen(void){
			return this->m_nDestinationPortLen;
		}

		inline const unsigned short SMPPSubmitSM::getDestinationPortLen(void) const{
			return this->m_nDestinationPortLen;
		}


		inline void SMPPSubmitSM::setDestAddrSubunitLen(const unsigned short nDestAddrSubunitLen){
			this->m_nDestAddrSubunitLen = nDestAddrSubunitLen;
		}

		inline unsigned short& SMPPSubmitSM::refDestAddrSubunitLen(void){
			return this->m_nDestAddrSubunitLen;
		}

		inline const unsigned short SMPPSubmitSM::getDestAddrSubunitLen(void) const{
			return this->m_nDestAddrSubunitLen;
		}


		inline void SMPPSubmitSM::setSarMsgRefNumLen(const unsigned short nSarMsgRefNumLen){
			this->m_nSarMsgRefNumLen = nSarMsgRefNumLen;
		}

		inline unsigned short& SMPPSubmitSM::refSarMsgRefNumLen(void){
			return this->m_nSarMsgRefNumLen;
		}

		inline const unsigned short SMPPSubmitSM::getSarMsgRefNumLen(void) const{
			return this->m_nSarMsgRefNumLen;
		}


		inline void SMPPSubmitSM::setSarTotalSegmentsLen(const unsigned short nSarTotalSegmentsLen){
			this->m_nSarTotalSegmentsLen = nSarTotalSegmentsLen;
		}

		inline unsigned short& SMPPSubmitSM::refSarTotalSegmentsLen(void){
			return this->m_nSarTotalSegmentsLen;
		}

		inline const unsigned short SMPPSubmitSM::getSarTotalSegmentsLen(void) const{
			return this->m_nSarTotalSegmentsLen;
		}


		inline void SMPPSubmitSM::setSarSegmentSeqnumLen(const unsigned short nSarSegmentSeqnumLen){
			this->m_nSarSegmentSeqnumLen = nSarSegmentSeqnumLen;
		}

		inline unsigned short& SMPPSubmitSM::refSarSegmentSeqnumLen(void){
			return this->m_nSarSegmentSeqnumLen;
		}

		inline const unsigned short SMPPSubmitSM::getSarSegmentSeqnumLen(void) const{
			return this->m_nSarSegmentSeqnumLen;
		}


		inline void SMPPSubmitSM::setMoreMessagesToSendLen(const unsigned short nMoreMessagesToSendLen){
			this->m_nMoreMessagesToSendLen = nMoreMessagesToSendLen;
		}

		inline unsigned short& SMPPSubmitSM::refMoreMessagesToSendLen(void){
			return this->m_nMoreMessagesToSendLen;
		}

		inline const unsigned short SMPPSubmitSM::getMoreMessagesToSendLen(void) const{
			return this->m_nMoreMessagesToSendLen;
		}


		inline void SMPPSubmitSM::setPayloadTypeLen(const unsigned short nPayloadTypeLen){
			this->m_nPayloadTypeLen = nPayloadTypeLen;
		}

		inline unsigned short& SMPPSubmitSM::refPayloadTypeLen(void){
			return this->m_nPayloadTypeLen;
		}

		inline const unsigned short SMPPSubmitSM::getPayloadTypeLen(void) const{
			return this->m_nPayloadTypeLen;
		}

		inline void SMPPSubmitSM::setMessagePayloadLen(const unsigned short nMessagePayloadLen){
			this->m_nMessagePayloadLen = nMessagePayloadLen;
		}

		inline unsigned short& SMPPSubmitSM::refMessagePayloadLen(void){
			return this->m_nMessagePayloadLen;
		}

		inline const unsigned short SMPPSubmitSM::getMessagePayloadLen(void) const{
			return this->m_nMessagePayloadLen;
		}


		inline void SMPPSubmitSM::setPrivacyIndicatorLen(const unsigned short nPrivacyIndicatorLen){
			this->m_nPrivacyIndicatorLen = nPrivacyIndicatorLen;
		}

		inline unsigned short& SMPPSubmitSM::refPrivacyIndicatorLen(void){
			return this->m_nPrivacyIndicatorLen;
		}

		inline const unsigned short SMPPSubmitSM::getPrivacyIndicatorLen(void) const{
			return this->m_nPrivacyIndicatorLen;
		}


		inline void SMPPSubmitSM::setCallbackNumLen(const unsigned short nCallbackNumLen){
			this->m_nCallbackNumLen = nCallbackNumLen;
		}

		inline unsigned short& SMPPSubmitSM::refCallbackNumLen(void){
			return this->m_nCallbackNumLen;
		}

		inline const unsigned short SMPPSubmitSM::getCallbackNumLen(void) const{
			return this->m_nCallbackNumLen;
		}


		inline void SMPPSubmitSM::setCallbackNumPresIndLen(const unsigned short nCallbackNumPresIndLen){
			this->m_nCallbackNumPresIndLen = nCallbackNumPresIndLen;
		}

		inline unsigned short& SMPPSubmitSM::refCallbackNumPresIndLen(void){
			return this->m_nCallbackNumPresIndLen;
		}

		inline const unsigned short SMPPSubmitSM::getCallbackNumPresIndLen(void) const{
			return this->m_nCallbackNumPresIndLen;
		}


		inline void SMPPSubmitSM::setCallbackNumAtagLen(const unsigned short nCallbackNumAtagLen){
			this->m_nCallbackNumAtagLen = nCallbackNumAtagLen;
		}

		inline unsigned short& SMPPSubmitSM::refCallbackNumAtagLen(void){
			return this->m_nCallbackNumAtagLen;
		}

		inline const unsigned short SMPPSubmitSM::getCallbackNumAtagLen(void) const{
			return this->m_nCallbackNumAtagLen;
		}


		inline void SMPPSubmitSM::setSourceSubaddressLen(const unsigned short nSourceSubaddressLen){
			this->m_nSourceSubaddressLen = nSourceSubaddressLen;
		}

		inline unsigned short& SMPPSubmitSM::refSourceSubaddressLen(void){
			return this->m_nSourceSubaddressLen;
		}

		inline const unsigned short SMPPSubmitSM::getSourceSubaddressLen(void) const{
			return this->m_nSourceSubaddressLen;
		}


		inline void SMPPSubmitSM::setDestSubaddressLen(const unsigned short nDestSubaddressLen){
			this->m_nDestSubaddressLen = nDestSubaddressLen;
		}

		inline unsigned short& SMPPSubmitSM::refDestSubaddressLen(void){
			return this->m_nDestSubaddressLen;
		}

		inline const unsigned short SMPPSubmitSM::getDestSubaddressLen(void) const{
			return this->m_nDestSubaddressLen;
		}


		inline void SMPPSubmitSM::setUserResponseCodeLen(const unsigned short nUserResponseCodeLen){
			this->m_nUserResponseCodeLen = nUserResponseCodeLen;
		}

		inline unsigned short& SMPPSubmitSM::refUserResponseCodeLen(void){
			return this->m_nUserResponseCodeLen;
		}

		inline const unsigned short SMPPSubmitSM::getUserResponseCodeLen(void) const{
			return this->m_nUserResponseCodeLen;
		}


		inline void SMPPSubmitSM::setDisplayTimeLen(const unsigned short nDisplayTimeLen){
			this->m_nDisplayTimeLen = nDisplayTimeLen;
		}

		inline unsigned short& SMPPSubmitSM::refDisplayTimeLen(void){
			return this->m_nDisplayTimeLen;
		}

		inline const unsigned short SMPPSubmitSM::getDisplayTimeLen(void) const{
			return this->m_nDisplayTimeLen;
		}


		inline void SMPPSubmitSM::setSmsSignalLen(const unsigned short nSmsSignalLen){
			this->m_nSmsSignalLen = nSmsSignalLen;
		}

		inline unsigned short& SMPPSubmitSM::refSmsSignalLen(void){
			return this->m_nSmsSignalLen;
		}

		inline const unsigned short SMPPSubmitSM::getSmsSignalLen(void) const{
			return this->m_nSmsSignalLen;
		}


		inline void SMPPSubmitSM::setMsValidityLen(const unsigned short nMsValidityLen){
			this->m_nMsValidityLen = nMsValidityLen;
		}

		inline unsigned short& SMPPSubmitSM::refMsValidityLen(void){
			return this->m_nMsValidityLen;
		}

		inline const unsigned short SMPPSubmitSM::getMsValidityLen(void) const{
			return this->m_nMsValidityLen;
		}


		inline void SMPPSubmitSM::setMsMsgWaitFacilitiesLen(const unsigned short nMsMsgWaitFacilitiesLen){
			this->m_nMsMsgWaitFacilitiesLen = nMsMsgWaitFacilitiesLen;
		}

		inline unsigned short& SMPPSubmitSM::refMsMsgWaitFacilitiesLen(void){
			return this->m_nMsMsgWaitFacilitiesLen;
		}

		inline const unsigned short SMPPSubmitSM::getMsMsgWaitFacilitiesLen(void) const{
			return this->m_nMsMsgWaitFacilitiesLen;
		}


		inline void SMPPSubmitSM::setNumberOfMessagesLen(const unsigned short nNumberOfMessagesLen){
			this->m_nNumberOfMessagesLen = nNumberOfMessagesLen;
		}

		inline unsigned short& SMPPSubmitSM::refNumberOfMessagesLen(void){
			return this->m_nNumberOfMessagesLen;
		}

		inline const unsigned short SMPPSubmitSM::getNumberOfMessagesLen(void) const{
			return this->m_nNumberOfMessagesLen;
		}


		inline void SMPPSubmitSM::setAlertOnMsgDeliveryLen(const unsigned short nAlertOnMsgDeliveryLen){
			this->m_nAlertOnMsgDeliveryLen = nAlertOnMsgDeliveryLen;
		}

		inline unsigned short& SMPPSubmitSM::refAlertOnMsgDeliveryLen(void){
			return this->m_nAlertOnMsgDeliveryLen;
		}

		inline const unsigned short SMPPSubmitSM::getAlertOnMsgDeliveryLen(void) const{
			return this->m_nAlertOnMsgDeliveryLen;
		}


		inline void SMPPSubmitSM::setLanguageIndicatorLen(const unsigned short nLanguageIndicatorLen){
			this->m_nLanguageIndicatorLen = nLanguageIndicatorLen;
		}

		inline unsigned short& SMPPSubmitSM::refLanguageIndicatorLen(void){
			return this->m_nLanguageIndicatorLen;
		}

		inline const unsigned short SMPPSubmitSM::getLanguageIndicatorLen(void) const{
			return this->m_nLanguageIndicatorLen;
		}


		inline void SMPPSubmitSM::setItsReplyTypeLen(const unsigned short nItsReplyTypeLen){
			this->m_nItsReplyTypeLen = nItsReplyTypeLen;
		}

		inline unsigned short& SMPPSubmitSM::refItsReplyTypeLen(void){
			return this->m_nItsReplyTypeLen;
		}

		inline const unsigned short SMPPSubmitSM::getItsReplyTypeLen(void) const{
			return this->m_nItsReplyTypeLen;
		}


		inline void SMPPSubmitSM::setItsSessionInfoLen(const unsigned short nItsSessionInfoLen){
			this->m_nItsSessionInfoLen = nItsSessionInfoLen;
		}

		inline unsigned short& SMPPSubmitSM::refItsSessionInfoLen(void){
			return this->m_nItsSessionInfoLen;
		}

		inline const unsigned short SMPPSubmitSM::getItsSessionInfoLen(void) const{
			return this->m_nItsSessionInfoLen;
		}


		inline void SMPPSubmitSM::setUssdServiceOpLen(const unsigned short nUssdServiceOpLen){
			this->m_nUssdServiceOpLen = nUssdServiceOpLen;
		}

		inline unsigned short& SMPPSubmitSM::refUssdServiceOpLen(void){
			return this->m_nUssdServiceOpLen;
		}

		inline const unsigned short SMPPSubmitSM::getUssdServiceOpLen(void) const{
			return this->m_nUssdServiceOpLen;
		}

	}
}
