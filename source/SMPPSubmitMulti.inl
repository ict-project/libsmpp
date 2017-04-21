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
		inline const bool SMPPSubmitMulti::isPresentUserMessageReference(void) const{
			return this->m_bPresentUserMessageReference;
		}

		inline void SMPPSubmitMulti::omitPresentUserMessageReference(void){
			this->m_bPresentUserMessageReference = false;
		}

		inline void SMPPSubmitMulti::setPresentUserMessageReference(const bool bPresentUserMessageReference){
			this->m_bPresentUserMessageReference = bPresentUserMessageReference;
		}

		inline const bool SMPPSubmitMulti::isPresentSourcePort(void) const{
			return this->m_bPresentSourcePort;
		}

		inline void SMPPSubmitMulti::omitPresentSourcePort(void){
			this->m_bPresentSourcePort = false;
		}

		inline void SMPPSubmitMulti::setPresentSourcePort(const bool bPresentSourcePort){
			this->m_bPresentSourcePort = bPresentSourcePort;
		}

		inline const bool SMPPSubmitMulti::isPresentSourceAddrSubunit(void) const{
			return this->m_bPresentSourceAddrSubunit;
		}

		inline void SMPPSubmitMulti::omitPresentSourceAddrSubunit(void){
			this->m_bPresentSourceAddrSubunit = false;
		}

		inline void SMPPSubmitMulti::setPresentSourceAddrSubunit(const bool bPresentSourceAddrSubunit){
			this->m_bPresentSourceAddrSubunit = bPresentSourceAddrSubunit;
		}

		inline const bool SMPPSubmitMulti::isPresentDestinationPort(void) const{
			return this->m_bPresentDestinationPort;
		}

		inline void SMPPSubmitMulti::omitPresentDestinationPort(void){
			this->m_bPresentDestinationPort = false;
		}

		inline void SMPPSubmitMulti::setPresentDestinationPort(const bool bPresentDestinationPort){
			this->m_bPresentDestinationPort = bPresentDestinationPort;
		}

		inline const bool SMPPSubmitMulti::isPresentDestAddrSubunit(void) const{
			return this->m_bPresentDestAddrSubunit;
		}

		inline void SMPPSubmitMulti::omitPresentDestAddrSubunit(void){
			this->m_bPresentDestAddrSubunit= false;
		}

		inline void SMPPSubmitMulti::setPresentDestAddrSubunit(const bool bPresentDestAddrSubunit){
			this->m_bPresentDestAddrSubunit = bPresentDestAddrSubunit;
		}

		inline const bool SMPPSubmitMulti::isPresentSarMsgRefNum(void) const{
			return this->m_bPresentSarMsgRefNum;
		}

		inline void SMPPSubmitMulti::omitPresentSarMsgRefNum(void){
			this->m_bPresentSarMsgRefNum = false;
		}

		inline void SMPPSubmitMulti::setPresentSarMsgRefNum(const bool bPresentSarMsgRefNum){
			this->m_bPresentSarMsgRefNum = bPresentSarMsgRefNum;
		}

		inline const bool SMPPSubmitMulti::isPresentSarTotalSegments(void) const{
			return this->m_bPresentSarTotalSegments;
		}

		inline void SMPPSubmitMulti::omitPresentSarTotalSegments(void){
			this->m_bPresentSarTotalSegments = false;
		}

		inline void SMPPSubmitMulti::setPresentSarTotalSegments(const bool bPresentSarTotalSegments){
			this->m_bPresentSarTotalSegments = bPresentSarTotalSegments;
		}

		inline const bool SMPPSubmitMulti::isPresentSarSegmentSeqnum(void) const{
			return this->m_bPresentSarSegmentSeqnum;
		}

		inline void SMPPSubmitMulti::omitPresentSarSegmentSeqnum(void){
			this->m_bPresentSarSegmentSeqnum = false;
		}

		inline void SMPPSubmitMulti::setPresentSarSegmentSeqnum(const bool bPresentSarSegmentSeqnum){
			this->m_bPresentSarSegmentSeqnum = bPresentSarSegmentSeqnum;
		}

		inline const bool SMPPSubmitMulti::isPresentPayloadType(void) const{
			return this->m_bPresentPayloadType;
		}

		inline void SMPPSubmitMulti::omitPresentPayloadType(void){
			this->m_bPresentPayloadType = false;
		}

		inline void SMPPSubmitMulti::setPresentPayloadType(const bool bPresentPayloadType){
			this->m_bPresentPayloadType = bPresentPayloadType;
		}

		inline const bool SMPPSubmitMulti::isPresentMessagePayload(void) const{
			return this->m_bPresentMessagePayload;
		}

		inline void SMPPSubmitMulti::omitPresentMessagePayload(void){
			this->m_bPresentMessagePayload = false;
		}

		inline void SMPPSubmitMulti::setPresentMessagePayload(const bool bPresentMessagePayload){
			this->m_bPresentMessagePayload = bPresentMessagePayload;
		}

		inline const bool SMPPSubmitMulti::isPresentPrivacyIndicator(void) const{
			return this->m_bPresentPrivacyIndicator;
		}

		inline void SMPPSubmitMulti::omitPresentPrivacyIndicator(void){
			this->m_bPresentPrivacyIndicator = false;
		}

		inline void SMPPSubmitMulti::setPresentPrivacyIndicator(const bool bPresentPrivacyIndicator){
			this->m_bPresentPrivacyIndicator = bPresentPrivacyIndicator;
		}

		inline const bool SMPPSubmitMulti::isPresentCallbackNum(void) const{
			return this->m_bPresentCallbackNum;
		}

		inline void SMPPSubmitMulti::omitPresentCallbackNum(void){
			this->m_bPresentCallbackNum = false;
		}

		inline void SMPPSubmitMulti::setPresentCallbackNum(const bool bPresentCallbackNum){
			this->m_bPresentCallbackNum = bPresentCallbackNum;
		}

		inline const bool SMPPSubmitMulti::isPresentCallbackNumPresInd(void) const{
			return this->m_bPresentCallbackNumPresInd;
		}

		inline void SMPPSubmitMulti::omitPresentCallbackNumPresInd(void){
			this->m_bPresentCallbackNumPresInd = false;
		}

		inline void SMPPSubmitMulti::setPresentCallbackNumPresInd(const bool bPresentCallbackNumPresInd){
			this->m_bPresentCallbackNumPresInd = bPresentCallbackNumPresInd;
		}

		inline const bool SMPPSubmitMulti::isPresentCallbackNumAtag(void) const{
			return this->m_bPresentCallbackNumAtag;
		}

		inline void SMPPSubmitMulti::omitPresentCallbackNumAtag(void){
			this->m_bPresentCallbackNumAtag = false;
		}

		inline void SMPPSubmitMulti::setPresentCallbackNumAtag(const bool bPresentCallbackNumAtag){
			this->m_bPresentCallbackNumAtag = bPresentCallbackNumAtag;
		}

		inline const bool SMPPSubmitMulti::isPresentSourceSubaddress(void) const{
			return this->m_bPresentSourceSubaddress;
		}

		inline void SMPPSubmitMulti::omitPresentSourceSubaddress(void){
			this->m_bPresentSourceSubaddress = false;
		}

		inline void SMPPSubmitMulti::setPresentSourceSubaddress(const bool bPresentSourceSubaddress){
			this->m_bPresentSourceSubaddress = bPresentSourceSubaddress;
		}

		inline const bool SMPPSubmitMulti::isPresentDestSubaddress(void) const{
			return this->m_bPresentDestSubaddress;
		}

		inline void SMPPSubmitMulti::omitPresentDestSubaddress(void){
			this->m_bPresentDestSubaddress = false;
		}

		inline void SMPPSubmitMulti::setPresentDestSubaddress(const bool bPresentDestSubaddress){
			this->m_bPresentDestSubaddress = bPresentDestSubaddress;
		}

		inline const bool SMPPSubmitMulti::isPresentDisplayTime(void) const{
			return this->m_bPresentDisplayTime;
		}

		inline void SMPPSubmitMulti::omitPresentDisplayTime(void){
			this->m_bPresentDisplayTime = false;
		}

		inline void SMPPSubmitMulti::setPresentDisplayTime(const bool bPresentDisplayTime){
			this->m_bPresentDisplayTime = bPresentDisplayTime;
		}

		inline const bool SMPPSubmitMulti::isPresentSmsSignal(void) const{
			return this->m_bPresentSmsSignal;
		}

		inline void SMPPSubmitMulti::omitPresentSmsSignal(void){
			this->m_bPresentSmsSignal = false;
		}

		inline void SMPPSubmitMulti::setPresentSmsSignal(const bool bPresentSmsSignal){
			this->m_bPresentSmsSignal = bPresentSmsSignal;
		}

		inline const bool SMPPSubmitMulti::isPresentMsValidity(void) const{
			return this->m_bPresentMsValidity;
		}

		inline void SMPPSubmitMulti::omitPresentMsValidity(void){
			this->m_bPresentMsValidity = false;
		}

		inline void SMPPSubmitMulti::setPresentMsValidity(const bool bPresentMsValidity){
			this->m_bPresentMsValidity = bPresentMsValidity;
		}

		inline const bool SMPPSubmitMulti::isPresentMsMsgWaitFacilities(void) const{
			return this->m_bPresentMsMsgWaitFacilities;
		}

		inline void SMPPSubmitMulti::omitPresentMsMsgWaitFacilities(void){
			this->m_bPresentMsMsgWaitFacilities = false;
		}

		inline void SMPPSubmitMulti::setPresentMsMsgWaitFacilities(const bool bPresentMsMsgWaitFacilities){
			this->m_bPresentMsMsgWaitFacilities = bPresentMsMsgWaitFacilities;
		}

		inline const bool SMPPSubmitMulti::isPresentAlertOnMsgDelivery(void) const{
			return this->m_bPresentAlertOnMsgDelivery;
		}

		inline void SMPPSubmitMulti::omitPresentAlertOnMsgDelivery(void){
			this->m_bPresentAlertOnMsgDelivery = false;
		}

		inline void SMPPSubmitMulti::setPresentAlertOnMsgDelivery(const bool bPresentAlertOnMsgDelivery){
			this->m_bPresentAlertOnMsgDelivery = bPresentAlertOnMsgDelivery;
		}

		inline const bool SMPPSubmitMulti::isPresentLanguageIndicator(void) const{
			return this->m_bPresentLanguageIndicator;
		}

		inline void SMPPSubmitMulti::omitPresentLanguageIndicator(void){
			this->m_bPresentLanguageIndicator = false;
		}

		inline void SMPPSubmitMulti::setPresentLanguageIndicator(const bool bPresentLanguageIndicator){
			this->m_bPresentLanguageIndicator = bPresentLanguageIndicator;
		}

		inline void SMPPSubmitMulti::setServiceType(const std::string& sServiceType){
			this->m_sServiceType = sServiceType;
		}

		inline std::string& SMPPSubmitMulti::refServiceType(void){
			return this->m_sServiceType;
		}

		inline const std::string& SMPPSubmitMulti::getServiceType(void) const{
			return this->m_sServiceType;
		}


		inline void SMPPSubmitMulti::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPSubmitMulti::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPSubmitMulti::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPSubmitMulti::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPSubmitMulti::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPSubmitMulti::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPSubmitMulti::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPSubmitMulti::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPSubmitMulti::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}

		inline void SMPPSubmitMulti::setNumberOfDest(const unsigned char nNumberOfDest){
			this->m_nNumberOfDest = nNumberOfDest;
		}

		inline unsigned char& SMPPSubmitMulti::refNumberOfDest(void){
			return this->m_nNumberOfDest;
		}

		inline const unsigned char SMPPSubmitMulti::getNumberOfDest(void) const{
			return this->m_nNumberOfDest;
		}


		inline void SMPPSubmitMulti::addDestAddress(const SMEAddress& oDestAddress){
			this->m_aDestAddresses.push_back(oDestAddress);
			this->m_nNumberOfDest = this->m_aDestAddresses.size();
		}

		inline void SMPPSubmitMulti::addDestAddress(const unsigned char nTON, const char nNPI, const std::string& sAddress){
			this->m_aDestAddresses.push_back( DestAddress(nTON, nNPI, sAddress) );
			this->m_nNumberOfDest = this->m_aDestAddresses.size();
		}

		inline void SMPPSubmitMulti::addDestAddress(const std::string& sDistrListName){
			this->m_aDestAddresses.push_back( DestAddress(sDistrListName) );
			this->m_nNumberOfDest = this->m_aDestAddresses.size();
		}

		inline void SMPPSubmitMulti::setDestAddresses(const std::vector<DestAddress>& aDestAddresses){
			this->m_aDestAddresses = aDestAddresses;
			this->m_nNumberOfDest = this->m_aDestAddresses.size();
		}

		inline std::vector<DestAddress>& SMPPSubmitMulti::refDestAddresses(void){
			return this->m_aDestAddresses;
		}

		inline const std::vector<DestAddress>& SMPPSubmitMulti::getDestAddresses(void) const{
			return this->m_aDestAddresses;
		}

		inline void SMPPSubmitMulti::setEsmClass(const unsigned char nEsmClass){
			this->m_nEsmClass = nEsmClass;
		}

		inline unsigned char& SMPPSubmitMulti::refEsmClass(void){
			return this->m_nEsmClass;
		}

		inline const unsigned char SMPPSubmitMulti::getEsmClass(void) const{
			return this->m_nEsmClass;
		}


		inline void SMPPSubmitMulti::setProtocolId(const unsigned char nProtocolId){
			this->m_nProtocolId = nProtocolId;
		}

		inline unsigned char& SMPPSubmitMulti::refProtocolId(void){
			return this->m_nProtocolId;
		}

		inline const unsigned char SMPPSubmitMulti::getProtocolId(void) const{
			return this->m_nProtocolId;
		}


		inline void SMPPSubmitMulti::setPriorityFlag(const unsigned char nPriorityFlag){
			this->m_nPriorityFlag = nPriorityFlag;
		}

		inline unsigned char& SMPPSubmitMulti::refPriorityFlag(void){
			return this->m_nPriorityFlag;
		}

		inline const unsigned char SMPPSubmitMulti::getPriorityFlag(void) const{
			return this->m_nPriorityFlag;
		}


		inline void SMPPSubmitMulti::setScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			this->m_sScheduleDeliveryTime = sScheduleDeliveryTime;
		}

		inline std::string& SMPPSubmitMulti::refScheduleDeliveryTime(void){
			return this->m_sScheduleDeliveryTime;
		}

		inline const std::string& SMPPSubmitMulti::getScheduleDeliveryTime(void) const{
			return this->m_sScheduleDeliveryTime;
		}


		inline void SMPPSubmitMulti::setValidityPeriod(const std::string& sValidityPeriod){
			this->m_sValidityPeriod = sValidityPeriod;
		}

		inline std::string& SMPPSubmitMulti::refValidityPeriod(void){
			return this->m_sValidityPeriod;
		}

		inline const std::string& SMPPSubmitMulti::getValidityPeriod(void) const{
			return this->m_sValidityPeriod;
		}


		inline void SMPPSubmitMulti::setRegisteredDelivery(const unsigned char nRegisteredDelivery){
			this->m_nRegisteredDelivery = nRegisteredDelivery;
		}

		inline unsigned char& SMPPSubmitMulti::refRegisteredDelivery(void){
			return this->m_nRegisteredDelivery;
		}

		inline const unsigned char SMPPSubmitMulti::getRegisteredDelivery(void) const{
			return this->m_nRegisteredDelivery;
		}


		inline void SMPPSubmitMulti::setReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){
			this->m_nReplaceIfPresentFlag = nReplaceIfPresentFlag;
		}

		inline unsigned char& SMPPSubmitMulti::refReplaceIfPresentFlag(void){
			return this->m_nReplaceIfPresentFlag;
		}

		inline const unsigned char SMPPSubmitMulti::getReplaceIfPresentFlag(void) const{
			return this->m_nReplaceIfPresentFlag;
		}


		inline void SMPPSubmitMulti::setDataCoding(const unsigned char nDataCoding){
			this->m_nDataCoding = nDataCoding;
		}

		inline unsigned char& SMPPSubmitMulti::refDataCoding(void){
			return this->m_nDataCoding;
		}

		inline const unsigned char SMPPSubmitMulti::getDataCoding(void) const{
			return this->m_nDataCoding;
		}


		inline void SMPPSubmitMulti::setSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			this->m_nSMDefaultMsgId = nSMDefaultMsgId;
		}

		inline unsigned char& SMPPSubmitMulti::refSMDefaultMsgId(void){
			return this->m_nSMDefaultMsgId;
		}

		inline const unsigned char SMPPSubmitMulti::getSMDefaultMsgId(void) const{
			return this->m_nSMDefaultMsgId;
		}


		inline void SMPPSubmitMulti::setSMLength(const unsigned char nSMLength){
			this->m_nSMLength = nSMLength;
		}

		inline unsigned char& SMPPSubmitMulti::refSMLength(void){
			return this->m_nSMLength;
		}

		inline const unsigned char SMPPSubmitMulti::getSMLength(void) const{
			return this->m_nSMLength;
		}


		inline void SMPPSubmitMulti::setShortMessage(const std::vector<unsigned char>& aShortMessage){
			this->m_aShortMessage = aShortMessage;
			this->m_nSMLength = this->m_aShortMessage.size();
		}

		inline void SMPPSubmitMulti::setShortMessage(const std::string& sShortMessage){
			this->m_aShortMessage.resize(sShortMessage.size());
			this->m_aShortMessage.assign(sShortMessage.begin(),sShortMessage.end());
			this->m_nSMLength = this->m_aShortMessage.size();
		}

		inline std::vector<unsigned char>& SMPPSubmitMulti::refShortMessage(void){
			return this->m_aShortMessage;
		}

		inline const std::vector<unsigned char>& SMPPSubmitMulti::getShortMessage(void) const{
			return this->m_aShortMessage;
		}


		inline void SMPPSubmitMulti::setUserMessageReference(const unsigned short nUserMessageReference){
			this->m_nUserMessageReference = nUserMessageReference;
			this->m_bPresentUserMessageReference = true;
		}

		inline unsigned short& SMPPSubmitMulti::refUserMessageReference(void){
			return this->m_nUserMessageReference;
		}

		inline const unsigned short SMPPSubmitMulti::getUserMessageReference(void) const{
			return this->m_nUserMessageReference;
		}

		inline void SMPPSubmitMulti::setSourcePort(const unsigned short nSourcePort){
			this->m_nSourcePort = nSourcePort;
			this->m_bPresentSourcePort = true;
		}

		inline unsigned short& SMPPSubmitMulti::refSourcePort(void){
			return this->m_nSourcePort;
		}

		inline const unsigned short SMPPSubmitMulti::getSourcePort(void) const{
			return this->m_nSourcePort;
		}

		inline void SMPPSubmitMulti::setSourceAddrSubunit(const unsigned char nSourceAddrSubunit){
			this->m_nSourceAddrSubunit = nSourceAddrSubunit;
			this->m_bPresentSourceAddrSubunit = true;
		}

		inline unsigned char& SMPPSubmitMulti::refSourceAddrSubunit(void){
			return this->m_nSourceAddrSubunit;
		}

		inline const unsigned char SMPPSubmitMulti::getSourceAddrSubunit(void) const{
			return this->m_nSourceAddrSubunit;
		}

		inline void SMPPSubmitMulti::setDestinationPort(const unsigned short nDestinationPort){
			this->m_nDestinationPort = nDestinationPort;
			this->m_bPresentDestinationPort = true;
		}

		inline unsigned short& SMPPSubmitMulti::refDestinationPort(void){
			return this->m_nDestinationPort;
		}

		inline const unsigned short SMPPSubmitMulti::getDestinationPort(void) const{
			return this->m_nDestinationPort;
		}

		inline void SMPPSubmitMulti::setDestAddrSubunit(const unsigned char nDestAddrSubunit){
			this->m_nDestAddrSubunit = nDestAddrSubunit;
			this->m_bPresentDestAddrSubunit = true;
		}

		inline unsigned char& SMPPSubmitMulti::refDestAddrSubunit(void){
			return this->m_nDestAddrSubunit;
		}

		inline const unsigned char SMPPSubmitMulti::getDestAddrSubunit(void) const{
			return this->m_nDestAddrSubunit;
		}

		inline void SMPPSubmitMulti::setSarMsgRefNum(const unsigned short nSarMsgRefNum){
			this->m_nSarMsgRefNum = nSarMsgRefNum;
			this->m_bPresentSarMsgRefNum = true;
		}

		inline unsigned short& SMPPSubmitMulti::refSarMsgRefNum(void){
			return this->m_nSarMsgRefNum;
		}

		inline const unsigned short SMPPSubmitMulti::getSarMsgRefNum(void) const{
			return this->m_nSarMsgRefNum;
		}

		inline void SMPPSubmitMulti::setSarTotalSegments(const unsigned char nSarTotalSegments){
			this->m_nSarTotalSegments = nSarTotalSegments;
			this->m_bPresentSarTotalSegments = true;
		}

		inline unsigned char& SMPPSubmitMulti::refSarTotalSegments(void){
			return this->m_nSarTotalSegments;
		}

		inline const unsigned char SMPPSubmitMulti::getSarTotalSegments(void) const{
			return this->m_nSarTotalSegments;
		}

		inline void SMPPSubmitMulti::setSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum){
			this->m_nSarSegmentSeqnum = nSarSegmentSeqnum;
			this->m_bPresentSarSegmentSeqnum = true;
		}

		inline unsigned char& SMPPSubmitMulti::refSarSegmentSeqnum(void){
			return this->m_nSarSegmentSeqnum;
		}

		inline const unsigned char SMPPSubmitMulti::getSarSegmentSeqnum(void) const{
			return this->m_nSarSegmentSeqnum;
		}

		inline void SMPPSubmitMulti::setPayloadType(const unsigned char nPayloadType){
			this->m_nPayloadType = nPayloadType;
			this->m_bPresentPayloadType = true;
		}

		inline unsigned char& SMPPSubmitMulti::refPayloadType(void){
			return this->m_nPayloadType;
		}

		inline const unsigned char SMPPSubmitMulti::getPayloadType(void) const{
			return this->m_nPayloadType;
		}

		inline void SMPPSubmitMulti::setMessagePayload(const std::vector<unsigned char>& aMessagePayload){
			this->m_nMessagePayloadLen = aMessagePayload.size();
			this->m_aMessagePayload = aMessagePayload;
			this->m_bPresentMessagePayload = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitMulti::refMessagePayload(void){
			return this->m_aMessagePayload;
		}

		inline const std::vector<unsigned char>& SMPPSubmitMulti::getMessagePayload(void) const{
			return this->m_aMessagePayload;
		}

		inline void SMPPSubmitMulti::setPrivacyIndicator(const unsigned char nPrivacyIndicator){
			this->m_nPrivacyIndicator = nPrivacyIndicator;
			this->m_bPresentPrivacyIndicator = true;
		}

		inline unsigned char& SMPPSubmitMulti::refPrivacyIndicator(void){
			return this->m_nPrivacyIndicator;
		}

		inline const unsigned char SMPPSubmitMulti::getPrivacyIndicator(void) const{
			return this->m_nPrivacyIndicator;
		}

		inline void SMPPSubmitMulti::setCallbackNum(const std::vector<unsigned char>& aCallbackNum){
			this->m_nCallbackNumLen = aCallbackNum.size();
			this->m_aCallbackNum = aCallbackNum;
			this->m_bPresentCallbackNum = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitMulti::refCallbackNum(void){
			return this->m_aCallbackNum;
		}

		inline const std::vector<unsigned char>& SMPPSubmitMulti::getCallbackNum(void) const{
			return this->m_aCallbackNum;
		}

		inline void SMPPSubmitMulti::setCallbackNumPresInd(const unsigned char nCallbackNumPresInd){
			this->m_nCallbackNumPresInd = nCallbackNumPresInd;
			this->m_bPresentCallbackNumPresInd = true;
		}

		inline unsigned char& SMPPSubmitMulti::refCallbackNumPresInd(void){
			return this->m_nCallbackNumPresInd;
		}

		inline const unsigned char SMPPSubmitMulti::getCallbackNumPresInd(void) const{
			return this->m_nCallbackNumPresInd;
		}

		inline void SMPPSubmitMulti::setCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag){
			this->m_nCallbackNumAtagLen = aCallbackNumAtag.size();
			this->m_aCallbackNumAtag = aCallbackNumAtag;
			this->m_bPresentCallbackNumAtag = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitMulti::refCallbackNumAtag(void){
			return this->m_aCallbackNumAtag;
		}

		inline const std::vector<unsigned char>& SMPPSubmitMulti::getCallbackNumAtag(void) const{
			return this->m_aCallbackNumAtag;
		}

		inline void SMPPSubmitMulti::setSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress){
			this->m_nSourceSubaddressLen = aSourceSubaddress.size();
			this->m_aSourceSubaddress = aSourceSubaddress;
			this->m_bPresentSourceSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitMulti::refSourceSubaddress(void){
			return this->m_aSourceSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPSubmitMulti::getSourceSubaddress(void) const{
			return this->m_aSourceSubaddress;
		}

		inline void SMPPSubmitMulti::setDestSubaddress(const std::vector<unsigned char>& aDestSubaddress){
			this->m_nDestSubaddressLen = aDestSubaddress.size();
			this->m_aDestSubaddress = aDestSubaddress;
			this->m_bPresentDestSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPSubmitMulti::refDestSubaddress(void){
			return this->m_aDestSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPSubmitMulti::getDestSubaddress(void) const{
			return this->m_aDestSubaddress;
		}

		inline void SMPPSubmitMulti::setDisplayTime(const unsigned char nDisplayTime){
			this->m_nDisplayTime = nDisplayTime;
			this->m_bPresentDisplayTime = true;
		}

		inline unsigned char& SMPPSubmitMulti::refDisplayTime(void){
			return this->m_nDisplayTime;
		}

		inline const unsigned char SMPPSubmitMulti::getDisplayTime(void) const{
			return this->m_nDisplayTime;
		}

		inline void SMPPSubmitMulti::setSmsSignal(const unsigned short nSmsSignal){
			this->m_nSmsSignal = nSmsSignal;
			this->m_bPresentSmsSignal = true;
		}

		inline unsigned short& SMPPSubmitMulti::refSmsSignal(void){
			return this->m_nSmsSignal;
		}

		inline const unsigned short SMPPSubmitMulti::getSmsSignal(void) const{
			return this->m_nSmsSignal;
		}

		inline void SMPPSubmitMulti::setMsValidity(const unsigned char nMsValidity){
			this->m_nMsValidity = nMsValidity;
			this->m_bPresentMsValidity = true;
		}

		inline unsigned char& SMPPSubmitMulti::refMsValidity(void){
			return this->m_nMsValidity;
		}

		inline const unsigned char SMPPSubmitMulti::getMsValidity(void) const{
			return this->m_nMsValidity;
		}

		inline void SMPPSubmitMulti::setMsMsgWaitFacilities(const unsigned char nMsMsgWaitFacilities){
			this->m_nMsMsgWaitFacilities = nMsMsgWaitFacilities;
			this->m_bPresentMsMsgWaitFacilities = true;
		}

		inline unsigned char& SMPPSubmitMulti::refMsMsgWaitFacilities(void){
			return this->m_nMsMsgWaitFacilities;
		}

		inline const unsigned char SMPPSubmitMulti::getMsMsgWaitFacilities(void) const{
			return this->m_nMsMsgWaitFacilities;
		}

		inline void SMPPSubmitMulti::setAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery){
			this->m_nAlertOnMsgDelivery = nAlertOnMsgDelivery;
			this->m_bPresentAlertOnMsgDelivery = true;
		}

		inline unsigned char& SMPPSubmitMulti::refAlertOnMsgDelivery(void){
			return this->m_nAlertOnMsgDelivery;
		}

		inline const unsigned char SMPPSubmitMulti::getAlertOnMsgDelivery(void) const{
			return this->m_nAlertOnMsgDelivery;
		}

		inline void SMPPSubmitMulti::setLanguageIndicator(const unsigned char nLanguageIndicator){
			this->m_nLanguageIndicator = nLanguageIndicator;
			this->m_bPresentLanguageIndicator = true;
		}

		inline unsigned char& SMPPSubmitMulti::refLanguageIndicator(void){
			return this->m_nLanguageIndicator;
		}

		inline const unsigned char SMPPSubmitMulti::getLanguageIndicator(void) const{
			return this->m_nLanguageIndicator;
		}

		inline void SMPPSubmitMulti::setUserMessageReferenceLen(const unsigned short nUserMessageReferenceLen){
			this->m_nUserMessageReferenceLen = nUserMessageReferenceLen;
		}

		inline unsigned short& SMPPSubmitMulti::refUserMessageReferenceLen(void){
			return this->m_nUserMessageReferenceLen;
		}

		inline const unsigned short SMPPSubmitMulti::getUserMessageReferenceLen(void) const{
			return this->m_nUserMessageReferenceLen;
		}


		inline void SMPPSubmitMulti::setSourcePortLen(const unsigned short nSourcePortLen){
			this->m_nSourcePortLen = nSourcePortLen;
		}

		inline unsigned short& SMPPSubmitMulti::refSourcePortLen(void){
			return this->m_nSourcePortLen;
		}

		inline const unsigned short SMPPSubmitMulti::getSourcePortLen(void) const{
			return this->m_nSourcePortLen;
		}


		inline void SMPPSubmitMulti::setSourceAddrSubunitLen(const unsigned short nSourceAddrSubunitLen){
			this->m_nSourceAddrSubunitLen = nSourceAddrSubunitLen;
		}

		inline unsigned short& SMPPSubmitMulti::refSourceAddrSubunitLen(void){
			return this->m_nSourceAddrSubunitLen;
		}

		inline const unsigned short SMPPSubmitMulti::getSourceAddrSubunitLen(void) const{
			return this->m_nSourceAddrSubunitLen;
		}


		inline void SMPPSubmitMulti::setDestinationPortLen(const unsigned short nDestinationPortLen){
			this->m_nDestinationPortLen = nDestinationPortLen;
		}

		inline unsigned short& SMPPSubmitMulti::refDestinationPortLen(void){
			return this->m_nDestinationPortLen;
		}

		inline const unsigned short SMPPSubmitMulti::getDestinationPortLen(void) const{
			return this->m_nDestinationPortLen;
		}


		inline void SMPPSubmitMulti::setDestAddrSubunitLen(const unsigned short nDestAddrSubunitLen){
			this->m_nDestAddrSubunitLen = nDestAddrSubunitLen;
		}

		inline unsigned short& SMPPSubmitMulti::refDestAddrSubunitLen(void){
			return this->m_nDestAddrSubunitLen;
		}

		inline const unsigned short SMPPSubmitMulti::getDestAddrSubunitLen(void) const{
			return this->m_nDestAddrSubunitLen;
		}


		inline void SMPPSubmitMulti::setSarMsgRefNumLen(const unsigned short nSarMsgRefNumLen){
			this->m_nSarMsgRefNumLen = nSarMsgRefNumLen;
		}

		inline unsigned short& SMPPSubmitMulti::refSarMsgRefNumLen(void){
			return this->m_nSarMsgRefNumLen;
		}

		inline const unsigned short SMPPSubmitMulti::getSarMsgRefNumLen(void) const{
			return this->m_nSarMsgRefNumLen;
		}


		inline void SMPPSubmitMulti::setSarTotalSegmentsLen(const unsigned short nSarTotalSegmentsLen){
			this->m_nSarTotalSegmentsLen = nSarTotalSegmentsLen;
		}

		inline unsigned short& SMPPSubmitMulti::refSarTotalSegmentsLen(void){
			return this->m_nSarTotalSegmentsLen;
		}

		inline const unsigned short SMPPSubmitMulti::getSarTotalSegmentsLen(void) const{
			return this->m_nSarTotalSegmentsLen;
		}

		inline void SMPPSubmitMulti::setSarSegmentSeqnumLen(const unsigned short nSarSegmentSeqnumLen){
			this->m_nSarSegmentSeqnumLen = nSarSegmentSeqnumLen;
		}

		inline unsigned short& SMPPSubmitMulti::refSarSegmentSeqnumLen(void){
			return this->m_nSarSegmentSeqnumLen;
		}

		inline const unsigned short SMPPSubmitMulti::getSarSegmentSeqnumLen(void) const{
			return this->m_nSarSegmentSeqnumLen;
		}


		inline void SMPPSubmitMulti::setPayloadTypeLen(const unsigned short nPayloadTypeLen){
			this->m_nPayloadTypeLen = nPayloadTypeLen;
		}

		inline unsigned short& SMPPSubmitMulti::refPayloadTypeLen(void){
			return this->m_nPayloadTypeLen;
		}

		inline const unsigned short SMPPSubmitMulti::getPayloadTypeLen(void) const{
			return this->m_nPayloadTypeLen;
		}


		inline void SMPPSubmitMulti::setMessagePayloadLen(const unsigned short nMessagePayloadLen){
			this->m_nMessagePayloadLen = nMessagePayloadLen;
		}

		inline unsigned short& SMPPSubmitMulti::refMessagePayloadLen(void){
			return this->m_nMessagePayloadLen;
		}

		inline const unsigned short SMPPSubmitMulti::getMessagePayloadLen(void) const{
			return this->m_nMessagePayloadLen;
		}


		inline void SMPPSubmitMulti::setPrivacyIndicatorLen(const unsigned short nPrivacyIndicatorLen){
			this->m_nPrivacyIndicatorLen = nPrivacyIndicatorLen;
		}

		inline unsigned short& SMPPSubmitMulti::refPrivacyIndicatorLen(void){
			return this->m_nPrivacyIndicatorLen;
		}

		inline const unsigned short SMPPSubmitMulti::getPrivacyIndicatorLen(void) const{
			return this->m_nPrivacyIndicatorLen;
		}


		inline void SMPPSubmitMulti::setCallbackNumLen(const unsigned short nCallbackNumLen){
			this->m_nCallbackNumLen = nCallbackNumLen;
		}

		inline unsigned short& SMPPSubmitMulti::refCallbackNumLen(void){
			return this->m_nCallbackNumLen;
		}

		inline const unsigned short SMPPSubmitMulti::getCallbackNumLen(void) const{
			return this->m_nCallbackNumLen;
		}


		inline void SMPPSubmitMulti::setCallbackNumPresIndLen(const unsigned short nCallbackNumPresIndLen){
			this->m_nCallbackNumPresIndLen = nCallbackNumPresIndLen;
		}

		inline unsigned short& SMPPSubmitMulti::refCallbackNumPresIndLen(void){
			return this->m_nCallbackNumPresIndLen;
		}

		inline const unsigned short SMPPSubmitMulti::getCallbackNumPresIndLen(void) const{
			return this->m_nCallbackNumPresIndLen;
		}


		inline void SMPPSubmitMulti::setCallbackNumAtagLen(const unsigned short nCallbackNumAtagLen){
			this->m_nCallbackNumAtagLen = nCallbackNumAtagLen;
		}

		inline unsigned short& SMPPSubmitMulti::refCallbackNumAtagLen(void){
			return this->m_nCallbackNumAtagLen;
		}

		inline const unsigned short SMPPSubmitMulti::getCallbackNumAtagLen(void) const{
			return this->m_nCallbackNumAtagLen;
		}


		inline void SMPPSubmitMulti::setSourceSubaddressLen(const unsigned short nSourceSubaddressLen){
			this->m_nSourceSubaddressLen = nSourceSubaddressLen;
		}

		inline unsigned short& SMPPSubmitMulti::refSourceSubaddressLen(void){
			return this->m_nSourceSubaddressLen;
		}

		inline const unsigned short SMPPSubmitMulti::getSourceSubaddressLen(void) const{
			return this->m_nSourceSubaddressLen;
		}


		inline void SMPPSubmitMulti::setDestSubaddressLen(const unsigned short nDestSubaddressLen){
			this->m_nDestSubaddressLen = nDestSubaddressLen;
		}

		inline unsigned short& SMPPSubmitMulti::refDestSubaddressLen(void){
			return this->m_nDestSubaddressLen;
		}

		inline const unsigned short SMPPSubmitMulti::getDestSubaddressLen(void) const{
			return this->m_nDestSubaddressLen;
		}


		inline void SMPPSubmitMulti::setDisplayTimeLen(const unsigned short nDisplayTimeLen){
			this->m_nDisplayTimeLen = nDisplayTimeLen;
		}

		inline unsigned short& SMPPSubmitMulti::refDisplayTimeLen(void){
			return this->m_nDisplayTimeLen;
		}

		inline const unsigned short SMPPSubmitMulti::getDisplayTimeLen(void) const{
			return this->m_nDisplayTimeLen;
		}


		inline void SMPPSubmitMulti::setSmsSignalLen(const unsigned short nSmsSignalLen){
			this->m_nSmsSignalLen = nSmsSignalLen;
		}

		inline unsigned short& SMPPSubmitMulti::refSmsSignalLen(void){
			return this->m_nSmsSignalLen;
		}

		inline const unsigned short SMPPSubmitMulti::getSmsSignalLen(void) const{
			return this->m_nSmsSignalLen;
		}


		inline void SMPPSubmitMulti::setMsValidityLen(const unsigned short nMsValidityLen){
			this->m_nMsValidityLen = nMsValidityLen;
		}

		inline unsigned short& SMPPSubmitMulti::refMsValidityLen(void){
			return this->m_nMsValidityLen;
		}

		inline const unsigned short SMPPSubmitMulti::getMsValidityLen(void) const{
			return this->m_nMsValidityLen;
		}


		inline void SMPPSubmitMulti::setMsMsgWaitFacilitiesLen(const unsigned short nMsMsgWaitFacilitiesLen){
			this->m_nMsMsgWaitFacilitiesLen = nMsMsgWaitFacilitiesLen;
		}

		inline unsigned short& SMPPSubmitMulti::refMsMsgWaitFacilitiesLen(void){
			return this->m_nMsMsgWaitFacilitiesLen;
		}

		inline const unsigned short SMPPSubmitMulti::getMsMsgWaitFacilitiesLen(void) const{
			return this->m_nMsMsgWaitFacilitiesLen;
		}


		inline void SMPPSubmitMulti::setAlertOnMsgDeliveryLen(const unsigned short nAlertOnMsgDeliveryLen){
			this->m_nAlertOnMsgDeliveryLen = nAlertOnMsgDeliveryLen;
		}

		inline unsigned short& SMPPSubmitMulti::refAlertOnMsgDeliveryLen(void){
			return this->m_nAlertOnMsgDeliveryLen;
		}

		inline const unsigned short SMPPSubmitMulti::getAlertOnMsgDeliveryLen(void) const{
			return this->m_nAlertOnMsgDeliveryLen;
		}


		inline void SMPPSubmitMulti::setLanguageIndicatorLen(const unsigned short nLanguageIndicatorLen){
			this->m_nLanguageIndicatorLen = nLanguageIndicatorLen;
		}

		inline unsigned short& SMPPSubmitMulti::refLanguageIndicatorLen(void){
			return this->m_nLanguageIndicatorLen;
		}

		inline const unsigned short SMPPSubmitMulti::getLanguageIndicatorLen(void) const{
			return this->m_nLanguageIndicatorLen;
		}

	}
}
