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

		inline const bool SMPPDeliverSM::isPresentUserMessageReference(void) const{
			return this->m_bPresentUserMessageReference;
		}

		inline void SMPPDeliverSM::omitPresentUserMessageReference(void){
			this->m_bPresentUserMessageReference = false;
		}

		inline void SMPPDeliverSM::setPresentUserMessageReference(const bool bPresentUserMessageReference){
			this->m_bPresentUserMessageReference = bPresentUserMessageReference;
		}

		inline const bool SMPPDeliverSM::isPresentSourcePort(void) const{
			return this->m_bPresentSourcePort;
		}

		inline void SMPPDeliverSM::omitPresentSourcePort(void){
			this->m_bPresentSourcePort = false;
		}

		inline void SMPPDeliverSM::setPresentSourcePort(const bool bPresentSourcePort){
			this->m_bPresentSourcePort = bPresentSourcePort;
		}

		inline const bool SMPPDeliverSM::isPresentDestinationPort(void) const{
			return this->m_bPresentDestinationPort;
		}

		inline void SMPPDeliverSM::omitPresentDestinationPort(void){
			this->m_bPresentDestinationPort = false;
		}

		inline void SMPPDeliverSM::setPresentDestinationPort(const bool bPresentDestinationPort){
			this->m_bPresentDestinationPort = bPresentDestinationPort;
		}

		inline const bool SMPPDeliverSM::isPresentSarMsgRefNum(void) const{
			return this->m_bPresentSarMsgRefNum;
		}

		inline void SMPPDeliverSM::omitPresentSarMsgRefNum(void){
			this->m_bPresentSarMsgRefNum = false;
		}

		inline void SMPPDeliverSM::setPresentSarMsgRefNum(const bool bPresentSarMsgRefNum){
			this->m_bPresentSarMsgRefNum = bPresentSarMsgRefNum;
		}

		inline const bool SMPPDeliverSM::isPresentSarTotalSegments(void) const{
			return this->m_bPresentSarTotalSegments;
		}

		inline void SMPPDeliverSM::omitPresentSarTotalSegments(void){
			this->m_bPresentSarTotalSegments = false;
		}

		inline void SMPPDeliverSM::setPresentSarTotalSegments(const bool bPresentSarTotalSegments){
			this->m_bPresentSarTotalSegments = bPresentSarTotalSegments;
		}

		inline const bool SMPPDeliverSM::isPresentSarSegmentSeqnum(void) const{
			return this->m_bPresentSarSegmentSeqnum;
		}

		inline void SMPPDeliverSM::omitPresentSarSegmentSeqnum(void){
			this->m_bPresentSarSegmentSeqnum = false;
		}

		inline void SMPPDeliverSM::setPresentSarSegmentSeqnum(const bool bPresentSarSegmentSeqnum){
			this->m_bPresentSarSegmentSeqnum = bPresentSarSegmentSeqnum;
		}

		inline const bool SMPPDeliverSM::isPresentPayloadType(void) const{
			return this->m_bPresentPayloadType;
		}

		inline void SMPPDeliverSM::omitPresentPayloadType(void){
			this->m_bPresentPayloadType = false;
		}

		inline void SMPPDeliverSM::setPresentPayloadType(const bool bPresentPayloadType){
			this->m_bPresentPayloadType = bPresentPayloadType;
		}

		inline const bool SMPPDeliverSM::isPresentMessagePayload(void) const{
			return this->m_bPresentMessagePayload;
		}

		inline void SMPPDeliverSM::omitPresentMessagePayload(void){
			this->m_bPresentMessagePayload = false;
		}

		inline void SMPPDeliverSM::setPresentMessagePayload(const bool bPresentMessagePayload){
			this->m_bPresentMessagePayload = bPresentMessagePayload;
		}

		inline const bool SMPPDeliverSM::isPresentPrivacyIndicator(void) const{
			return this->m_bPresentPrivacyIndicator;
		}

		inline void SMPPDeliverSM::omitPresentPrivacyIndicator(void){
			this->m_bPresentPrivacyIndicator = false;
		}

		inline void SMPPDeliverSM::setPresentPrivacyIndicator(const bool bPresentPrivacyIndicator){
			this->m_bPresentPrivacyIndicator = bPresentPrivacyIndicator;
		}

		inline const bool SMPPDeliverSM::isPresentCallbackNum(void) const{
			return this->m_bPresentCallbackNum;
		}

		inline void SMPPDeliverSM::omitPresentCallbackNum(void){
			this->m_bPresentCallbackNum = false;
		}

		inline void SMPPDeliverSM::setPresentCallbackNum(const bool bPresentCallbackNum){
			this->m_bPresentCallbackNum = bPresentCallbackNum;
		}

		inline const bool SMPPDeliverSM::isPresentSourceSubaddress(void) const{
			return this->m_bPresentSourceSubaddress;
		}

		inline void SMPPDeliverSM::omitPresentSourceSubaddress(void){
			this->m_bPresentSourceSubaddress = false;
		}

		inline void SMPPDeliverSM::setPresentSourceSubaddress(const bool bPresentSourceSubaddress){
			this->m_bPresentSourceSubaddress = bPresentSourceSubaddress;
		}

		inline const bool SMPPDeliverSM::isPresentDestSubaddress(void) const{
			return this->m_bPresentDestSubaddress;
		}

		inline void SMPPDeliverSM::omitPresentDestSubaddress(void){
			this->m_bPresentDestSubaddress = false;
		}

		inline void SMPPDeliverSM::setPresentDestSubaddress(const bool bPresentDestSubaddress){
			this->m_bPresentDestSubaddress = bPresentDestSubaddress;
		}

		inline const bool SMPPDeliverSM::isPresentUserResponseCode(void) const{
			return this->m_bPresentUserResponseCode;
		}

		inline void SMPPDeliverSM::omitPresentUserResponseCode(void){
			this->m_bPresentUserResponseCode= false;
		}

		inline void SMPPDeliverSM::setPresentUserResponseCode(const bool bPresentUserResponseCode){
			this->m_bPresentUserResponseCode = bPresentUserResponseCode;
		}

		inline const bool SMPPDeliverSM::isPresentLanguageIndicator(void) const{
			return this->m_bPresentLanguageIndicator;
		}

		inline void SMPPDeliverSM::omitPresentLanguageIndicator(void){
			this->m_bPresentLanguageIndicator = false;
		}

		inline void SMPPDeliverSM::setPresentLanguageIndicator(const bool bPresentLanguageIndicator){
			this->m_bPresentLanguageIndicator = bPresentLanguageIndicator;
		}

		inline const bool SMPPDeliverSM::isPresentItsSessionInfo(void) const{
			return this->m_bPresentItsSessionInfo;
		}

		inline void SMPPDeliverSM::omitPresentItsSessionInfo(void){
			this->m_bPresentItsSessionInfo = false;
		}

		inline void SMPPDeliverSM::setPresentItsSessionInfo(const bool bPresentItsSessionInfo){
			this->m_bPresentItsSessionInfo = bPresentItsSessionInfo;
		}

		inline const bool SMPPDeliverSM::isPresentNetworkErrorCode(void) const{
			return this->m_bPresentNetworkErrorCode;
		}

		inline void SMPPDeliverSM::omitPresentNetworkErrorCode(void){
			this->m_bPresentNetworkErrorCode = false;
		}

		inline void SMPPDeliverSM::setPresentNetworkErrorCode(const bool bPresentNetworkErrorCode){
			this->m_bPresentNetworkErrorCode = bPresentNetworkErrorCode;
		}

		inline const bool SMPPDeliverSM::isPresentMessageState(void) const{
			return this->m_bPresentMessageState;
		}

		inline void SMPPDeliverSM::omitPresentMessageState(void){
			this->m_bPresentMessageState = false;
		}

		inline void SMPPDeliverSM::setPresentMessageState(const bool bPresentMessageState){
			this->m_bPresentMessageState = bPresentMessageState;
		}

		inline const bool SMPPDeliverSM::isPresentReceiptedMessageId(void) const{
			return this->m_bPresentReceiptedMessageId;
		}

		inline void SMPPDeliverSM::omitPresentReceiptedMessageId(void){
			this->m_bPresentReceiptedMessageId = false;
		}

		inline void SMPPDeliverSM::setPresentReceiptedMessageId(const bool bPresentReceiptedMessageId){
			this->m_bPresentReceiptedMessageId = bPresentReceiptedMessageId;
		}

		inline void SMPPDeliverSM::setServiceType(const std::string& sServiceType){
			this->m_sServiceType = sServiceType;
		}

		inline std::string& SMPPDeliverSM::refServiceType(void){
			return this->m_sServiceType;
		}

		inline const std::string& SMPPDeliverSM::getServiceType(void) const{
			return this->m_sServiceType;
		}


		inline void SMPPDeliverSM::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPDeliverSM::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPDeliverSM::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPDeliverSM::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPDeliverSM::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPDeliverSM::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPDeliverSM::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPDeliverSM::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPDeliverSM::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}


		inline void SMPPDeliverSM::setDestAddrTON(const unsigned char nDestAddrTON){
			this->m_nDestAddrTON = nDestAddrTON;
		}

		inline unsigned char& SMPPDeliverSM::refDestAddrTON(void){
			return this->m_nDestAddrTON;
		}

		inline const unsigned char SMPPDeliverSM::getDestAddrTON(void) const{
			return this->m_nDestAddrTON;
		}


		inline void SMPPDeliverSM::setDestAddrNPI(const unsigned char nDestAddrNPI){
			this->m_nDestAddrNPI = nDestAddrNPI;
		}

		inline unsigned char& SMPPDeliverSM::refDestAddrNPI(void){
			return this->m_nDestAddrNPI;
		}

		inline const unsigned char SMPPDeliverSM::getDestAddrNPI(void) const{
			return this->m_nDestAddrNPI;
		}


		inline void SMPPDeliverSM::setDestAddr(const std::string& sDestAddr){
			this->m_sDestAddr = sDestAddr;
		}

		inline std::string& SMPPDeliverSM::refDestAddr(void){
			return this->m_sDestAddr;
		}

		inline const std::string& SMPPDeliverSM::getDestAddr(void) const{
			return this->m_sDestAddr;
		}


		inline void SMPPDeliverSM::setEsmClass(const unsigned char nEsmClass){
			this->m_nEsmClass = nEsmClass;
		}

		inline unsigned char& SMPPDeliverSM::refEsmClass(void){
			return this->m_nEsmClass;
		}

		inline const unsigned char SMPPDeliverSM::getEsmClass(void) const{
			return this->m_nEsmClass;
		}


		inline void SMPPDeliverSM::setProtocolId(const unsigned char nProtocolId){
			this->m_nProtocolId = nProtocolId;
		}

		inline unsigned char& SMPPDeliverSM::refProtocolId(void){
			return this->m_nProtocolId;
		}

		inline const unsigned char SMPPDeliverSM::getProtocolId(void) const{
			return this->m_nProtocolId;
		}


		inline void SMPPDeliverSM::setPriorityFlag(const unsigned char nPriorityFlag){
			this->m_nPriorityFlag = nPriorityFlag;
		}

		inline unsigned char& SMPPDeliverSM::refPriorityFlag(void){
			return this->m_nPriorityFlag;
		}

		inline const unsigned char SMPPDeliverSM::getPriorityFlag(void) const{
			return this->m_nPriorityFlag;
		}


		inline void SMPPDeliverSM::setScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			this->m_sScheduleDeliveryTime = sScheduleDeliveryTime;
		}

		inline std::string& SMPPDeliverSM::refScheduleDeliveryTime(void){
			return this->m_sScheduleDeliveryTime;
		}

		inline const std::string& SMPPDeliverSM::getScheduleDeliveryTime(void) const{
			return this->m_sScheduleDeliveryTime;
		}


		inline void SMPPDeliverSM::setValidityPeriod(const std::string& sValidityPeriod){
			this->m_sValidityPeriod = sValidityPeriod;
		}

		inline std::string& SMPPDeliverSM::refValidityPeriod(void){
			return this->m_sValidityPeriod;
		}

		inline const std::string& SMPPDeliverSM::getValidityPeriod(void) const{
			return this->m_sValidityPeriod;
		}


		inline void SMPPDeliverSM::setRegisteredDelivery(const unsigned char nRegisteredDelivery){
			this->m_nRegisteredDelivery = nRegisteredDelivery;
		}

		inline unsigned char& SMPPDeliverSM::refRegisteredDelivery(void){
			return this->m_nRegisteredDelivery;
		}

		inline const unsigned char SMPPDeliverSM::getRegisteredDelivery(void) const{
			return this->m_nRegisteredDelivery;
		}


		inline void SMPPDeliverSM::setReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){
			this->m_nReplaceIfPresentFlag = nReplaceIfPresentFlag;
		}

		inline unsigned char& SMPPDeliverSM::refReplaceIfPresentFlag(void){
			return this->m_nReplaceIfPresentFlag;
		}

		inline const unsigned char SMPPDeliverSM::getReplaceIfPresentFlag(void) const{
			return this->m_nReplaceIfPresentFlag;
		}


		inline void SMPPDeliverSM::setDataCoding(const unsigned char nDataCoding){
			this->m_nDataCoding = nDataCoding;
		}

		inline unsigned char& SMPPDeliverSM::refDataCoding(void){
			return this->m_nDataCoding;
		}

		inline const unsigned char SMPPDeliverSM::getDataCoding(void) const{
			return this->m_nDataCoding;
		}


		inline void SMPPDeliverSM::setSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			this->m_nSMDefaultMsgId = nSMDefaultMsgId;
		}

		inline unsigned char& SMPPDeliverSM::refSMDefaultMsgId(void){
			return this->m_nSMDefaultMsgId;
		}

		inline const unsigned char SMPPDeliverSM::getSMDefaultMsgId(void) const{
			return this->m_nSMDefaultMsgId;
		}


		inline void SMPPDeliverSM::setSMLength(const unsigned char nSMLength){
			this->m_nSMLength = nSMLength;
		}

		inline unsigned char& SMPPDeliverSM::refSMLength(void){
			return this->m_nSMLength;
		}

		inline const unsigned char SMPPDeliverSM::getSMLength(void) const{
			return this->m_nSMLength;
		}


		inline void SMPPDeliverSM::setShortMessage(const std::vector<unsigned char>& aShortMessage){
			this->m_aShortMessage = aShortMessage;
			this->m_nSMLength = this->m_aShortMessage.size();
		}

		inline void SMPPDeliverSM::setShortMessage(const std::string& sShortMessage){
			this->m_aShortMessage.resize(sShortMessage.size());
			this->m_aShortMessage.assign(sShortMessage.begin(), sShortMessage.end());
			this->m_nSMLength = this->m_aShortMessage.size();
		}

		inline std::vector<unsigned char>& SMPPDeliverSM::refShortMessage(void){
			return this->m_aShortMessage;
		}

		inline const std::vector<unsigned char>& SMPPDeliverSM::getShortMessage(void) const{
			return this->m_aShortMessage;
		}


		inline void SMPPDeliverSM::setUserMessageReference(const unsigned short nUserMessageReference){
			this->m_nUserMessageReference = nUserMessageReference;
			this->m_bPresentUserMessageReference = true;
		}

		inline unsigned short& SMPPDeliverSM::refUserMessageReference(void){
			return this->m_nUserMessageReference;
		}

		inline const unsigned short SMPPDeliverSM::getUserMessageReference(void) const{
			return this->m_nUserMessageReference;
		}

		inline void SMPPDeliverSM::setSourcePort(const unsigned short nSourcePort){
			this->m_nSourcePort = nSourcePort;
			this->m_bPresentSourcePort = true;
		}

		inline unsigned short& SMPPDeliverSM::refSourcePort(void){
			return this->m_nSourcePort;
		}

		inline const unsigned short SMPPDeliverSM::getSourcePort(void) const{
			return this->m_nSourcePort;
		}

		inline void SMPPDeliverSM::setDestinationPort(const unsigned short nDestinationPort){
			this->m_nDestinationPort = nDestinationPort;
			this->m_bPresentDestinationPort = true;
		}

		inline unsigned short& SMPPDeliverSM::refDestinationPort(void){
			return this->m_nDestinationPort;
		}

		inline const unsigned short SMPPDeliverSM::getDestinationPort(void) const{
			return this->m_nDestinationPort;
		}

		inline void SMPPDeliverSM::setSarMsgRefNum(const unsigned short nSarMsgRefNum){
			this->m_nSarMsgRefNum = nSarMsgRefNum;
			this->m_bPresentSarMsgRefNum = true;
		}

		inline unsigned short& SMPPDeliverSM::refSarMsgRefNum(void){
			return this->m_nSarMsgRefNum;
		}

		inline const unsigned short SMPPDeliverSM::getSarMsgRefNum(void) const{
			return this->m_nSarMsgRefNum;
		}

		inline void SMPPDeliverSM::setSarTotalSegments(const unsigned char nSarTotalSegments){
			this->m_nSarTotalSegments = nSarTotalSegments;
			this->m_bPresentSarTotalSegments = true;
		}

		inline unsigned char& SMPPDeliverSM::refSarTotalSegments(void){
			return this->m_nSarTotalSegments;
		}

		inline const unsigned char SMPPDeliverSM::getSarTotalSegments(void) const{
			return this->m_nSarTotalSegments;
		}

		inline void SMPPDeliverSM::setSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum){
			this->m_nSarSegmentSeqnum = nSarSegmentSeqnum;
			this->m_bPresentSarSegmentSeqnum = true;
		}

		inline unsigned char& SMPPDeliverSM::refSarSegmentSeqnum(void){
			return this->m_nSarSegmentSeqnum;
		}

		inline const unsigned char SMPPDeliverSM::getSarSegmentSeqnum(void) const{
			return this->m_nSarSegmentSeqnum;
		}

		inline void SMPPDeliverSM::setPayloadType(const unsigned char nPayloadType){
			this->m_nPayloadType = nPayloadType;
			this->m_bPresentPayloadType = true;
		}

		inline unsigned char& SMPPDeliverSM::refPayloadType(void){
			return this->m_nPayloadType;
		}

		inline const unsigned char SMPPDeliverSM::getPayloadType(void) const{
			return this->m_nPayloadType;
		}

		inline void SMPPDeliverSM::setMessagePayload(const std::vector<unsigned char>& aMessagePayload){
			this->m_nMessagePayloadLen = aMessagePayload.size();
			this->m_aMessagePayload = aMessagePayload;
			this->m_bPresentMessagePayload = true;
		}

		inline std::vector<unsigned char>& SMPPDeliverSM::refMessagePayload(void){
			return this->m_aMessagePayload;
		}

		inline const std::vector<unsigned char>& SMPPDeliverSM::getMessagePayload(void) const{
			return this->m_aMessagePayload;
		}

		inline void SMPPDeliverSM::setPrivacyIndicator(const unsigned char nPrivacyIndicator){
			this->m_nPrivacyIndicator = nPrivacyIndicator;
			this->m_bPresentPrivacyIndicator = true;
		}

		inline unsigned char& SMPPDeliverSM::refPrivacyIndicator(void){
			return this->m_nPrivacyIndicator;
		}

		inline const unsigned char SMPPDeliverSM::getPrivacyIndicator(void) const{
			return this->m_nPrivacyIndicator;
		}

		inline void SMPPDeliverSM::setCallbackNum(const std::vector<unsigned char>& aCallbackNum){
			this->m_nCallbackNumLen = aCallbackNum.size();
			this->m_aCallbackNum = aCallbackNum;
			this->m_bPresentCallbackNum = true;
		}

		inline std::vector<unsigned char>& SMPPDeliverSM::refCallbackNum(void){
			return this->m_aCallbackNum;
		}

		inline const std::vector<unsigned char>& SMPPDeliverSM::getCallbackNum(void) const{
			return this->m_aCallbackNum;
		}

		inline void SMPPDeliverSM::setSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress){
			this->m_nSourceSubaddressLen = aSourceSubaddress.size();
			this->m_aSourceSubaddress = aSourceSubaddress;
			this->m_bPresentSourceSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPDeliverSM::refSourceSubaddress(void){
			return this->m_aSourceSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPDeliverSM::getSourceSubaddress(void) const{
			return this->m_aSourceSubaddress;
		}

		inline void SMPPDeliverSM::setDestSubaddress(const std::vector<unsigned char>& aDestSubaddress){
			this->m_nDestSubaddressLen = aDestSubaddress.size();
			this->m_aDestSubaddress = aDestSubaddress;
			this->m_bPresentDestSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPDeliverSM::refDestSubaddress(void){
			return this->m_aDestSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPDeliverSM::getDestSubaddress(void) const{
			return this->m_aDestSubaddress;
		}

		inline void SMPPDeliverSM::setUserResponseCode(const unsigned char nUserResponseCode){
			this->m_nUserResponseCode = nUserResponseCode;
			this->m_bPresentUserResponseCode = true;
		}

		inline unsigned char& SMPPDeliverSM::refUserResponseCode(void){
			return this->m_nUserResponseCode;
		}

		inline const unsigned char SMPPDeliverSM::getUserResponseCode(void) const{
			return this->m_nUserResponseCode;
		}

		inline void SMPPDeliverSM::setLanguageIndicator(const unsigned char nLanguageIndicator){
			this->m_nLanguageIndicator = nLanguageIndicator;
			this->m_bPresentLanguageIndicator = true;
		}

		inline unsigned char& SMPPDeliverSM::refLanguageIndicator(void){
			return this->m_nLanguageIndicator;
		}

		inline const unsigned char SMPPDeliverSM::getLanguageIndicator(void) const{
			return this->m_nLanguageIndicator;
		}

		inline void SMPPDeliverSM::setItsSessionInfo(const unsigned short nItsSessionInfo){
			this->m_nItsSessionInfo = nItsSessionInfo;
			this->m_bPresentItsSessionInfo = true;
		}

		inline unsigned short& SMPPDeliverSM::refItsSessionInfo(void){
			return this->m_nItsSessionInfo;
		}

		inline const unsigned short SMPPDeliverSM::getItsSessionInfo(void) const{
			return this->m_nItsSessionInfo;
		}


		inline void SMPPDeliverSM::setNetworkErrorCode(const unsigned char nNetworkCode, const unsigned short nErrorCode){
			this->m_oNetworkErrorCode.setNetworkCode(nNetworkCode);
			this->m_oNetworkErrorCode.setErrorCode(nErrorCode);
			this->m_bPresentNetworkErrorCode = true;
		}

		inline void SMPPDeliverSM::setNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode){
			this->m_oNetworkErrorCode = oNetworkErrorCode;
			this->m_bPresentNetworkErrorCode = true;
		}

		inline NetworkErrorCode& SMPPDeliverSM::refNetworkErrorCode(void){
			return this->m_oNetworkErrorCode;
		}

		inline const NetworkErrorCode& SMPPDeliverSM::getNetworkErrorCode(void) const{
			return this->m_oNetworkErrorCode;
		}

		inline void SMPPDeliverSM::setMessageState(const unsigned char nMessageState){
			this->m_nMessageState = nMessageState;
			this->m_bPresentMessageState = true;
		}

		inline unsigned char& SMPPDeliverSM::refMessageState(void){
			return this->m_nMessageState;
		}

		inline const unsigned char SMPPDeliverSM::getMessageState(void) const{
			return this->m_nMessageState;
		}

		inline void SMPPDeliverSM::setReceiptedMessageId(const std::string& sReceiptedMessageId){
			this->m_nReceiptedMessageIdLen = sReceiptedMessageId.size() + 1;
			this->m_sReceiptedMessageId = sReceiptedMessageId;
			this->m_bPresentReceiptedMessageId = true;
		}

		inline void SMPPDeliverSM::setReceiptedMessageId(const unsigned nReceiptedMessageId){
			char szBuffer[128];
			memset(szBuffer,0,sizeof(szBuffer));
			sprintf(szBuffer, "%d", nReceiptedMessageId);

			this->m_nReceiptedMessageIdLen = strlen(szBuffer) + 1;
			this->m_sReceiptedMessageId = std::string(szBuffer);
			this->m_bPresentReceiptedMessageId = true;
		}

		inline std::string& SMPPDeliverSM::refReceiptedMessageId(void){
			return this->m_sReceiptedMessageId;
		}

		inline const std::string& SMPPDeliverSM::getReceiptedMessageId(void) const{
			return this->m_sReceiptedMessageId;
		}

		inline void SMPPDeliverSM::setUserMessageReferenceLen(const unsigned short nUserMessageReferenceLen){
			this->m_nUserMessageReferenceLen = nUserMessageReferenceLen;
		}

		inline unsigned short& SMPPDeliverSM::refUserMessageReferenceLen(void){
			return this->m_nUserMessageReferenceLen;
		}

		inline const unsigned short SMPPDeliverSM::getUserMessageReferenceLen(void) const{
			return this->m_nUserMessageReferenceLen;
		}


		inline void SMPPDeliverSM::setSourcePortLen(const unsigned short nSourcePortLen){
			this->m_nSourcePortLen = nSourcePortLen;
		}

		inline unsigned short& SMPPDeliverSM::refSourcePortLen(void){
			return this->m_nSourcePortLen;
		}

		inline const unsigned short SMPPDeliverSM::getSourcePortLen(void) const{
			return this->m_nSourcePortLen;
		}

		inline void SMPPDeliverSM::setDestinationPortLen(const unsigned short nDestinationPortLen){
			this->m_nDestinationPortLen = nDestinationPortLen;
		}

		inline unsigned short& SMPPDeliverSM::refDestinationPortLen(void){
			return this->m_nDestinationPortLen;
		}

		inline const unsigned short SMPPDeliverSM::getDestinationPortLen(void) const{
			return this->m_nDestinationPortLen;
		}


		inline void SMPPDeliverSM::setSarMsgRefNumLen(const unsigned short nSarMsgRefNumLen){
			this->m_nSarMsgRefNumLen = nSarMsgRefNumLen;
		}

		inline unsigned short& SMPPDeliverSM::refSarMsgRefNumLen(void){
			return this->m_nSarMsgRefNumLen;
		}

		inline const unsigned short SMPPDeliverSM::getSarMsgRefNumLen(void) const{
			return this->m_nSarMsgRefNumLen;
		}


		inline void SMPPDeliverSM::setSarTotalSegmentsLen(const unsigned short nSarTotalSegmentsLen){
			this->m_nSarTotalSegmentsLen = nSarTotalSegmentsLen;
		}

		inline unsigned short& SMPPDeliverSM::refSarTotalSegmentsLen(void){
			return this->m_nSarTotalSegmentsLen;
		}

		inline const unsigned short SMPPDeliverSM::getSarTotalSegmentsLen(void) const{
			return this->m_nSarTotalSegmentsLen;
		}


		inline void SMPPDeliverSM::setSarSegmentSeqnumLen(const unsigned short nSarSegmentSeqnumLen){
			this->m_nSarSegmentSeqnumLen = nSarSegmentSeqnumLen;
		}

		inline unsigned short& SMPPDeliverSM::refSarSegmentSeqnumLen(void){
			return this->m_nSarSegmentSeqnumLen;
		}

		inline const unsigned short SMPPDeliverSM::getSarSegmentSeqnumLen(void) const{
			return this->m_nSarSegmentSeqnumLen;
		}


		inline void SMPPDeliverSM::setUserResponseCodeLen(const unsigned short nUserResponseCodeLen){
			this->m_nUserResponseCodeLen = nUserResponseCodeLen;
		}

		inline unsigned short& SMPPDeliverSM::refUserResponseCodeLen(void){
			return this->m_nUserResponseCodeLen;
		}

		inline const unsigned short SMPPDeliverSM::getUserResponseCodeLen(void) const{
			return this->m_nUserResponseCodeLen;
		}


		inline void SMPPDeliverSM::setPrivacyIndicatorLen(const unsigned short nPrivacyIndicatorLen){
			this->m_nPrivacyIndicatorLen = nPrivacyIndicatorLen;
		}

		inline unsigned short& SMPPDeliverSM::refPrivacyIndicatorLen(void){
			return this->m_nPrivacyIndicatorLen;
		}

		inline const unsigned short SMPPDeliverSM::getPrivacyIndicatorLen(void) const{
			return this->m_nPrivacyIndicatorLen;
		}


		inline void SMPPDeliverSM::setPayloadTypeLen(const unsigned short nPayloadTypeLen){
			this->m_nPayloadTypeLen = nPayloadTypeLen;
		}

		inline unsigned short& SMPPDeliverSM::refPayloadTypeLen(void){
			return this->m_nPayloadTypeLen;
		}

		inline const unsigned short SMPPDeliverSM::getPayloadTypeLen(void) const{
			return this->m_nPayloadTypeLen;
		}


		inline void SMPPDeliverSM::setMessagePayloadLen(const unsigned short nMessagePayloadLen){
			this->m_nMessagePayloadLen = nMessagePayloadLen;
		}

		inline unsigned short& SMPPDeliverSM::refMessagePayloadLen(void){
			return this->m_nMessagePayloadLen;
		}

		inline const unsigned short SMPPDeliverSM::getMessagePayloadLen(void) const{
			return this->m_nMessagePayloadLen;
		}


		inline void SMPPDeliverSM::setCallbackNumLen(const unsigned short nCallbackNumLen){
			this->m_nCallbackNumLen = nCallbackNumLen;
		}

		inline unsigned short& SMPPDeliverSM::refCallbackNumLen(void){
			return this->m_nCallbackNumLen;
		}

		inline const unsigned short SMPPDeliverSM::getCallbackNumLen(void) const{
			return this->m_nCallbackNumLen;
		}


		inline void SMPPDeliverSM::setSourceSubaddressLen(const unsigned short nSourceSubaddressLen){
			this->m_nSourceSubaddressLen = nSourceSubaddressLen;
		}

		inline unsigned short& SMPPDeliverSM::refSourceSubaddressLen(void){
			return this->m_nSourceSubaddressLen;
		}

		inline const unsigned short SMPPDeliverSM::getSourceSubaddressLen(void) const{
			return this->m_nSourceSubaddressLen;
		}


		inline void SMPPDeliverSM::setDestSubaddressLen(const unsigned short nDestSubaddressLen){
			this->m_nDestSubaddressLen = nDestSubaddressLen;
		}

		inline unsigned short& SMPPDeliverSM::refDestSubaddressLen(void){
			return this->m_nDestSubaddressLen;
		}

		inline const unsigned short SMPPDeliverSM::getDestSubaddressLen(void) const{
			return this->m_nDestSubaddressLen;
		}


		inline void SMPPDeliverSM::setLanguageIndicatorLen(const unsigned short nLanguageIndicatorLen){
			this->m_nLanguageIndicatorLen = nLanguageIndicatorLen;
		}

		inline unsigned short& SMPPDeliverSM::refLanguageIndicatorLen(void){
			return this->m_nLanguageIndicatorLen;
		}

		inline const unsigned short SMPPDeliverSM::getLanguageIndicatorLen(void) const{
			return this->m_nLanguageIndicatorLen;
		}


		inline void SMPPDeliverSM::setItsSessionInfoLen(const unsigned short nItsSessionInfoLen){
			this->m_nItsSessionInfoLen = nItsSessionInfoLen;
		}

		inline unsigned short& SMPPDeliverSM::refItsSessionInfoLen(void){
			return this->m_nItsSessionInfoLen;
		}

		inline const unsigned short SMPPDeliverSM::getItsSessionInfoLen(void) const{
			return this->m_nItsSessionInfoLen;
		}


		inline void SMPPDeliverSM::setNetworkErrorCodeLen(const unsigned short nNetworkErrorCodeLen){
			this->m_nNetworkErrorCodeLen = nNetworkErrorCodeLen;
		}

		inline unsigned short& SMPPDeliverSM::refNetworkErrorCodeLen(void){
			return this->m_nNetworkErrorCodeLen;
		}

		inline const unsigned short SMPPDeliverSM::getNetworkErrorCodeLen(void) const{
			return this->m_nNetworkErrorCodeLen;
		}


		inline void SMPPDeliverSM::setMessageStateLen(const unsigned short nMessageStateLen){
			this->m_nMessageStateLen = nMessageStateLen;
		}

		inline unsigned short& SMPPDeliverSM::refMessageStateLen(void){
			return this->m_nMessageStateLen;
		}

		inline const unsigned short SMPPDeliverSM::getMessageStateLen(void) const{
			return this->m_nMessageStateLen;
		}


		inline void SMPPDeliverSM::setReceiptedMessageIdLen(const unsigned short nReceiptedMessageIdLen){
			this->m_nReceiptedMessageIdLen = nReceiptedMessageIdLen;
		}

		inline unsigned short& SMPPDeliverSM::refReceiptedMessageIdLen(void){
			return this->m_nReceiptedMessageIdLen;
		}

		inline const unsigned short SMPPDeliverSM::getReceiptedMessageIdLen(void) const{
			return this->m_nReceiptedMessageIdLen;
		}

	}
}
