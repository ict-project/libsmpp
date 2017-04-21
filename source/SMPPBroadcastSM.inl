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

		inline const bool SMPPBroadcastSM::isPresentBroadcastAreaIdentifier(void) const{
			return this->m_bPresentBroadcastAreaIdentifier;
		}

		inline void SMPPBroadcastSM::omitPresentBroadcastAreaIdentifier(void){
			this->m_bPresentBroadcastAreaIdentifier = false;
		}

		inline void SMPPBroadcastSM::setPresentBroadcastAreaIdentifier(const bool bPresentBroadcastAreaIdentifier){
			this->m_bPresentBroadcastAreaIdentifier = bPresentBroadcastAreaIdentifier;
		}

		inline const bool SMPPBroadcastSM::isPresentBroadcastContentType(void) const{
			return this->m_bPresentBroadcastContentType;
		}

		inline void SMPPBroadcastSM::omitPresentBroadcastContentType(void){
			this->m_bPresentBroadcastContentType = false;
		}

		inline void SMPPBroadcastSM::setPresentBroadcastContentType(const bool bPresentBroadcastContentType){
			this->m_bPresentBroadcastContentType = bPresentBroadcastContentType;
		}

		inline const bool SMPPBroadcastSM::isPresentBroadcastRepNum(void) const{
			return this->m_bPresentBroadcastRepNum;
		}

		inline void SMPPBroadcastSM::omitPresentBroadcastRepNum(void){
			this->m_bPresentBroadcastRepNum = false;
		}

		inline void SMPPBroadcastSM::setPresentBroadcastRepNum(const bool bPresentBroadcastRepNum){
			this->m_bPresentBroadcastRepNum = bPresentBroadcastRepNum;
		}

		inline const bool SMPPBroadcastSM::isPresentBroadcastFrequencyInterval(void) const{
			return this->m_bPresentBroadcastFrequencyInterval;
		}

		inline void SMPPBroadcastSM::omitPresentBroadcastFrequencyInterval(void){
			this->m_bPresentBroadcastFrequencyInterval = false;
		}

		inline void SMPPBroadcastSM::setPresentBroadcastFrequencyInterval(const bool bPresentBroadcastFrequencyInterval){
			this->m_bPresentBroadcastFrequencyInterval = bPresentBroadcastFrequencyInterval;
		}

		inline const bool SMPPBroadcastSM::isPresentAlertOnMsgDelivery(void) const{
			return this->m_bPresentAlertOnMsgDelivery;
		}

		inline void SMPPBroadcastSM::omitPresentAlertOnMsgDelivery(void){
			this->m_bPresentAlertOnMsgDelivery = false;
		}

		inline void SMPPBroadcastSM::setPresentAlertOnMsgDelivery(const bool bPresentAlertOnMsgDelivery){
			this->m_bPresentAlertOnMsgDelivery = bPresentAlertOnMsgDelivery;
		}

		inline const bool SMPPBroadcastSM::isPresentBroadcastChannelIndicator(void) const{
			return this->m_bPresentBroadcastChannelIndicator;
		}

		inline void SMPPBroadcastSM::omitPresentBroadcastChannelIndicator(void){
			this->m_bPresentBroadcastChannelIndicator = false;
		}

		inline void SMPPBroadcastSM::setPresentBroadcastChannelIndicator(const bool bPresentBroadcastChannelIndicator){
			this->m_bPresentBroadcastChannelIndicator = bPresentBroadcastChannelIndicator;
		}

		inline const bool SMPPBroadcastSM::isPresentBroadcastContentTypeInfo(void) const{
			return this->m_bPresentBroadcastContentTypeInfo;
		}

		inline void SMPPBroadcastSM::omitPresentBroadcastContentTypeInfo(void){
			this->m_bPresentBroadcastContentTypeInfo= false;
		}

		inline void SMPPBroadcastSM::setPresentBroadcastContentTypeInfo(const bool bPresentBroadcastContentTypeInfo){
			this->m_bPresentBroadcastContentTypeInfo = bPresentBroadcastContentTypeInfo;
		}

		inline const bool SMPPBroadcastSM::isPresentBroadcastMessageClass(void) const{
			return this->m_bPresentBroadcastMessageClass;
		}

		inline void SMPPBroadcastSM::omitPresentBroadcastMessageClass(void){
			this->m_bPresentBroadcastMessageClass = false;
		}

		inline void SMPPBroadcastSM::setPresentBroadcastMessageClass(const bool bPresentBroadcastMessageClass){
			this->m_bPresentBroadcastMessageClass = bPresentBroadcastMessageClass;
		}

		inline const bool SMPPBroadcastSM::isPresentBroadcastServiceGroup(void) const{
			return this->m_bPresentBroadcastServiceGroup;
		}

		inline void SMPPBroadcastSM::omitPresentBroadcastServiceGroup(void){
			this->m_bPresentBroadcastServiceGroup = false;
		}

		inline void SMPPBroadcastSM::setPresentBroadcastServiceGroup(const bool bPresentBroadcastServiceGroup){
			this->m_bPresentBroadcastServiceGroup = bPresentBroadcastServiceGroup;
		}

		inline const bool SMPPBroadcastSM::isPresentCallbackNum(void) const{
			return this->m_bPresentCallbackNum;
		}

		inline void SMPPBroadcastSM::omitPresentCallbackNum(void){
			this->m_bPresentCallbackNum = false;
		}

		inline void SMPPBroadcastSM::setPresentCallbackNum(const bool bPresentCallbackNum){
			this->m_bPresentCallbackNum = bPresentCallbackNum;
		}

		inline const bool SMPPBroadcastSM::isPresentCallbackNumPresInd(void) const{
			return this->m_bPresentCallbackNumPresInd;
		}

		inline void SMPPBroadcastSM::omitPresentCallbackNumPresInd(void){
			this->m_bPresentCallbackNumPresInd = false;
		}

		inline void SMPPBroadcastSM::setPresentCallbackNumPresInd(const bool bPresentCallbackNumPresInd){
			this->m_bPresentCallbackNumPresInd = bPresentCallbackNumPresInd;
		}

		inline const bool SMPPBroadcastSM::isPresentCallbackNumAtag(void) const{
			return this->m_bPresentCallbackNumAtag;
		}

		inline void SMPPBroadcastSM::omitPresentCallbackNumAtag(void){
			this->m_bPresentCallbackNumAtag = false;
		}

		inline void SMPPBroadcastSM::setPresentCallbackNumAtag(const bool bPresentCallbackNumAtag){
			this->m_bPresentCallbackNumAtag = bPresentCallbackNumAtag;
		}

		inline const bool SMPPBroadcastSM::isPresentDestAddrSubunit(void) const{
			return this->m_bPresentDestAddrSubunit;
		}

		inline void SMPPBroadcastSM::omitPresentDestAddrSubunit(void){
			this->m_bPresentDestAddrSubunit= false;
		}

		inline void SMPPBroadcastSM::setPresentDestAddrSubunit(const bool bPresentDestAddrSubunit){
			this->m_bPresentDestAddrSubunit = bPresentDestAddrSubunit;
		}

		inline const bool SMPPBroadcastSM::isPresentDestSubaddress(void) const{
			return this->m_bPresentDestSubaddress;
		}

		inline void SMPPBroadcastSM::omitPresentDestSubaddress(void){
			this->m_bPresentDestSubaddress = false;
		}

		inline void SMPPBroadcastSM::setPresentDestSubaddress(const bool bPresentDestSubaddress){
			this->m_bPresentDestSubaddress = bPresentDestSubaddress;
		}

		inline const bool SMPPBroadcastSM::isPresentDestPort(void) const{
			return this->m_bPresentDestPort;
		}

		inline void SMPPBroadcastSM::omitPresentDestPort(void){
			this->m_bPresentDestPort = false;
		}

		inline void SMPPBroadcastSM::setPresentDestPort(const bool bPresentDestPort){
			this->m_bPresentDestPort = bPresentDestPort;
		}

		inline const bool SMPPBroadcastSM::isPresentDisplayTime(void) const{
			return this->m_bPresentDisplayTime;
		}

		inline void SMPPBroadcastSM::omitPresentDisplayTime(void){
			this->m_bPresentDisplayTime = false;
		}

		inline void SMPPBroadcastSM::setPresentDisplayTime(const bool bPresentDisplayTime){
			this->m_bPresentDisplayTime = bPresentDisplayTime;
		}

		inline const bool SMPPBroadcastSM::isPresentLanguageIndicator(void) const{
			return this->m_bPresentLanguageIndicator;
		}

		inline void SMPPBroadcastSM::omitPresentLanguageIndicator(void){
			this->m_bPresentLanguageIndicator = false;
		}

		inline void SMPPBroadcastSM::setPresentLanguageIndicator(const bool bPresentLanguageIndicator){
			this->m_bPresentLanguageIndicator = bPresentLanguageIndicator;
		}

		inline const bool SMPPBroadcastSM::isPresentMessagePayload(void) const{
			return this->m_bPresentMessagePayload;
		}

		inline void SMPPBroadcastSM::omitPresentMessagePayload(void){
			this->m_bPresentMessagePayload = false;
		}

		inline void SMPPBroadcastSM::setPresentMessagePayload(const bool bPresentMessagePayload){
			this->m_bPresentMessagePayload = bPresentMessagePayload;
		}

		inline const bool SMPPBroadcastSM::isPresentMsValidity(void) const{
			return this->m_bPresentMsValidity;
		}

		inline void SMPPBroadcastSM::omitPresentMsValidity(void){
			this->m_bPresentMsValidity = false;
		}

		inline void SMPPBroadcastSM::setPresentMsValidity(const bool bPresentMsValidity){
			this->m_bPresentMsValidity = bPresentMsValidity;
		}

		inline const bool SMPPBroadcastSM::isPresentPayloadType(void) const{
			return this->m_bPresentPayloadType;
		}

		inline void SMPPBroadcastSM::omitPresentPayloadType(void){
			this->m_bPresentPayloadType = false;
		}

		inline void SMPPBroadcastSM::setPresentPayloadType(const bool bPresentPayloadType){
			this->m_bPresentPayloadType = bPresentPayloadType;
		}

		inline const bool SMPPBroadcastSM::isPresentPrivacyIndicator(void) const{
			return this->m_bPresentPrivacyIndicator;
		}

		inline void SMPPBroadcastSM::omitPresentPrivacyIndicator(void){
			this->m_bPresentPrivacyIndicator = false;
		}

		inline void SMPPBroadcastSM::setPresentPrivacyIndicator(const bool bPresentPrivacyIndicator){
			this->m_bPresentPrivacyIndicator = bPresentPrivacyIndicator;
		}

		inline const bool SMPPBroadcastSM::isPresentSmsSignal(void) const{
			return this->m_bPresentSmsSignal;
		}

		inline void SMPPBroadcastSM::omitPresentSmsSignal(void){
			this->m_bPresentSmsSignal = false;
		}

		inline void SMPPBroadcastSM::setPresentSmsSignal(const bool bPresentSmsSignal){
			this->m_bPresentSmsSignal = bPresentSmsSignal;
		}

		inline const bool SMPPBroadcastSM::isPresentSourceAddrSubunit(void) const{
			return this->m_bPresentSourceAddrSubunit;
		}

		inline void SMPPBroadcastSM::omitPresentSourceAddrSubunit(void){
			this->m_bPresentSourceAddrSubunit = false;
		}

		inline void SMPPBroadcastSM::setPresentSourceAddrSubunit(const bool bPresentSourceAddrSubunit){
			this->m_bPresentSourceAddrSubunit = bPresentSourceAddrSubunit;
		}

		inline const bool SMPPBroadcastSM::isPresentSourcePort(void) const{
			return this->m_bPresentSourcePort;
		}

		inline void SMPPBroadcastSM::omitPresentSourcePort(void){
			this->m_bPresentSourcePort = false;
		}

		inline void SMPPBroadcastSM::setPresentSourcePort(const bool bPresentSourcePort){
			this->m_bPresentSourcePort = bPresentSourcePort;
		}

		inline const bool SMPPBroadcastSM::isPresentSourceSubaddress(void) const{
			return this->m_bPresentSourceSubaddress;
		}

		inline void SMPPBroadcastSM::omitPresentSourceSubaddress(void){
			this->m_bPresentSourceSubaddress = false;
		}

		inline void SMPPBroadcastSM::setPresentSourceSubaddress(const bool bPresentSourceSubaddress){
			this->m_bPresentSourceSubaddress = bPresentSourceSubaddress;
		}

		inline const bool SMPPBroadcastSM::isPresentUserMessageReference(void) const{
			return this->m_bPresentUserMessageReference;
		}

		inline void SMPPBroadcastSM::omitPresentUserMessageReference(void){
			this->m_bPresentUserMessageReference = false;
		}

		inline void SMPPBroadcastSM::setPresentUserMessageReference(const bool bPresentUserMessageReference){
			this->m_bPresentUserMessageReference = bPresentUserMessageReference;
		}

		inline void SMPPBroadcastSM::setServiceType(const std::string& sServiceType){
			this->m_sServiceType = sServiceType;
		}

		inline std::string& SMPPBroadcastSM::refServiceType(void){
			return this->m_sServiceType;
		}

		inline const std::string& SMPPBroadcastSM::getServiceType(void) const{
			return this->m_sServiceType;
		}


		inline void SMPPBroadcastSM::setSourceAddrTON(const unsigned char nSourceAddrTON){
			this->m_nSourceAddrTON = nSourceAddrTON;
		}

		inline unsigned char& SMPPBroadcastSM::refSourceAddrTON(void){
			return this->m_nSourceAddrTON;
		}

		inline const unsigned char SMPPBroadcastSM::getSourceAddrTON(void) const{
			return this->m_nSourceAddrTON;
		}


		inline void SMPPBroadcastSM::setSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_nSourceAddrNPI = nSourceAddrNPI;
		}

		inline unsigned char& SMPPBroadcastSM::refSourceAddrNPI(void){
			return this->m_nSourceAddrNPI;
		}

		inline const unsigned char SMPPBroadcastSM::getSourceAddrNPI(void) const{
			return this->m_nSourceAddrNPI;
		}


		inline void SMPPBroadcastSM::setSourceAddr(const std::string& sSourceAddr){
			this->m_sSourceAddr = sSourceAddr;
		}

		inline std::string& SMPPBroadcastSM::refSourceAddr(void){
			return this->m_sSourceAddr;
		}

		inline const std::string& SMPPBroadcastSM::getSourceAddr(void) const{
			return this->m_sSourceAddr;
		}

		inline void SMPPBroadcastSM::setMessageId(const std::string& sMessageId){
			this->m_sMessageId = sMessageId;
		}

		inline std::string& SMPPBroadcastSM::refMessageId(void){
			return this->m_sMessageId;
		}

		inline const std::string& SMPPBroadcastSM::getMessageId(void) const{
			return this->m_sMessageId;
		}

		inline void SMPPBroadcastSM::setPriorityFlag(const unsigned char nPriorityFlag){
			this->m_nPriorityFlag = nPriorityFlag;
		}

		inline unsigned char& SMPPBroadcastSM::refPriorityFlag(void){
			return this->m_nPriorityFlag;
		}

		inline const unsigned char SMPPBroadcastSM::getPriorityFlag(void) const{
			return this->m_nPriorityFlag;
		}


		inline void SMPPBroadcastSM::setScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			this->m_sScheduleDeliveryTime = sScheduleDeliveryTime;
		}

		inline std::string& SMPPBroadcastSM::refScheduleDeliveryTime(void){
			return this->m_sScheduleDeliveryTime;
		}

		inline const std::string& SMPPBroadcastSM::getScheduleDeliveryTime(void) const{
			return this->m_sScheduleDeliveryTime;
		}


		inline void SMPPBroadcastSM::setValidityPeriod(const std::string& sValidityPeriod){
			this->m_sValidityPeriod = sValidityPeriod;
		}

		inline std::string& SMPPBroadcastSM::refValidityPeriod(void){
			return this->m_sValidityPeriod;
		}

		inline const std::string& SMPPBroadcastSM::getValidityPeriod(void) const{
			return this->m_sValidityPeriod;
		}

		inline void SMPPBroadcastSM::setReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){
			this->m_nReplaceIfPresentFlag = nReplaceIfPresentFlag;
		}

		inline unsigned char& SMPPBroadcastSM::refReplaceIfPresentFlag(void){
			return this->m_nReplaceIfPresentFlag;
		}

		inline const unsigned char SMPPBroadcastSM::getReplaceIfPresentFlag(void) const{
			return this->m_nReplaceIfPresentFlag;
		}


		inline void SMPPBroadcastSM::setDataCoding(const unsigned char nDataCoding){
			this->m_nDataCoding = nDataCoding;
		}

		inline unsigned char& SMPPBroadcastSM::refDataCoding(void){
			return this->m_nDataCoding;
		}

		inline const unsigned char SMPPBroadcastSM::getDataCoding(void) const{
			return this->m_nDataCoding;
		}


		inline void SMPPBroadcastSM::setSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			this->m_nSMDefaultMsgId = nSMDefaultMsgId;
		}

		inline unsigned char& SMPPBroadcastSM::refSMDefaultMsgId(void){
			return this->m_nSMDefaultMsgId;
		}

		inline const unsigned char SMPPBroadcastSM::getSMDefaultMsgId(void) const{
			return this->m_nSMDefaultMsgId;
		}

		inline void SMPPBroadcastSM::addBroadcastAreaIdentifier(const std::vector<unsigned char>& aBroadcastAreaIdentifier){
			this->m_aBroadcastAreaIdentifier.push_back(BroadcastAreaIdentifier(aBroadcastAreaIdentifier));
			this->m_bPresentBroadcastAreaIdentifier = true;

			this->m_aBroadcastAreaIdentifierLen.push_back(aBroadcastAreaIdentifier.size());
		}

		inline void SMPPBroadcastSM::addBroadcastAreaIdentifier(const BroadcastAreaIdentifier& oBroadcastAreaIdentifier){
			this->m_aBroadcastAreaIdentifier.push_back(oBroadcastAreaIdentifier);
			this->m_bPresentBroadcastAreaIdentifier = true;

			this->m_aBroadcastAreaIdentifierLen.push_back(oBroadcastAreaIdentifier.getValue().size());
		}

		inline void SMPPBroadcastSM::setBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier){
			this->m_aBroadcastAreaIdentifier = aBroadcastAreaIdentifier;
			this->m_bPresentBroadcastAreaIdentifier = true;

			this->m_aBroadcastAreaIdentifierLen.clear();
			for(unsigned j = 0; j < aBroadcastAreaIdentifier.size(); ++j){
				this->m_aBroadcastAreaIdentifierLen.push_back(aBroadcastAreaIdentifier[j].getValue().size());
			}
		}

		inline std::vector<BroadcastAreaIdentifier>& SMPPBroadcastSM::refBroadcastAreaIdentifier(void){
			return this->m_aBroadcastAreaIdentifier;
		}

		inline const std::vector<BroadcastAreaIdentifier>& SMPPBroadcastSM::getBroadcastAreaIdentifier(void) const{
			return this->m_aBroadcastAreaIdentifier;
		}


		inline void SMPPBroadcastSM::setBroadcastContentType(const std::vector<unsigned char>& aBroadcastContentType){
			this->m_nBroadcastContentTypeLen = aBroadcastContentType.size();
			this->m_aBroadcastContentType = aBroadcastContentType;
			this->m_bPresentBroadcastContentType = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refBroadcastContentType(void){
			return this->m_aBroadcastContentType;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getBroadcastContentType(void) const{
			return this->m_aBroadcastContentType;
		}


		inline void SMPPBroadcastSM::setBroadcastRepNum(const unsigned short nBroadcastRepNum){
			this->m_nBroadcastRepNum = nBroadcastRepNum;
			this->m_bPresentBroadcastRepNum = true;
		}

		inline unsigned short& SMPPBroadcastSM::refBroadcastRepNum(void){
			return this->m_nBroadcastRepNum;
		}

		inline const unsigned short SMPPBroadcastSM::getBroadcastRepNum(void) const{
			return this->m_nBroadcastRepNum;
		}


		inline void SMPPBroadcastSM::setBroadcastFrequencyInterval(const std::vector<unsigned char>& aBroadcastFrequencyInterval){
			this->m_nBroadcastFrequencyIntervalLen = aBroadcastFrequencyInterval.size();
			this->m_aBroadcastFrequencyInterval = aBroadcastFrequencyInterval;
			this->m_bPresentBroadcastFrequencyInterval = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refBroadcastFrequencyInterval(void){
			return this->m_aBroadcastFrequencyInterval;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getBroadcastFrequencyInterval(void) const{
			return this->m_aBroadcastFrequencyInterval;
		}

		inline void SMPPBroadcastSM::setAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery){
			this->m_nAlertOnMsgDelivery = nAlertOnMsgDelivery;
			this->m_bPresentAlertOnMsgDelivery = true;
		}

		inline unsigned char& SMPPBroadcastSM::refAlertOnMsgDelivery(void){
			return this->m_nAlertOnMsgDelivery;
		}

		inline const unsigned char SMPPBroadcastSM::getAlertOnMsgDelivery(void) const{
			return this->m_nAlertOnMsgDelivery;
		}

		inline void SMPPBroadcastSM::setBroadcastChannelIndicator(const unsigned char nBroadcastChannelIndicator){
			this->m_nBroadcastChannelIndicator = nBroadcastChannelIndicator;
			this->m_bPresentBroadcastChannelIndicator = true;
		}

		inline unsigned char& SMPPBroadcastSM::refBroadcastChannelIndicator(void){
			return this->m_nBroadcastChannelIndicator;
		}

		inline const unsigned char SMPPBroadcastSM::getBroadcastChannelIndicator(void) const{
			return this->m_nBroadcastChannelIndicator;
		}

		inline void SMPPBroadcastSM::setBroadcastContentTypeInfo(const std::vector<unsigned char>& aBroadcastContentTypeInfo){
			this->m_nBroadcastContentTypeInfoLen = aBroadcastContentTypeInfo.size();
			this->m_aBroadcastContentTypeInfo = aBroadcastContentTypeInfo;
			this->m_bPresentBroadcastContentTypeInfo = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refBroadcastContentTypeInfo(void){
			return this->m_aBroadcastContentTypeInfo;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getBroadcastContentTypeInfo(void) const{
			return this->m_aBroadcastContentTypeInfo;
		}

		inline void SMPPBroadcastSM::setBroadcastMessageClass(const unsigned char nBroadcastMessageClass){
			this->m_nBroadcastMessageClass = nBroadcastMessageClass;
			this->m_bPresentBroadcastMessageClass = true;
		}

		inline unsigned char& SMPPBroadcastSM::refBroadcastMessageClass(void){
			return this->m_nBroadcastMessageClass;
		}

		inline const unsigned char SMPPBroadcastSM::getBroadcastMessageClass(void) const{
			return this->m_nBroadcastMessageClass;
		}

		inline void SMPPBroadcastSM::setBroadcastServiceGroup(const std::vector<unsigned char>& aBroadcastServiceGroup){
			this->m_nBroadcastServiceGroupLen = aBroadcastServiceGroup.size();
			this->m_aBroadcastServiceGroup = aBroadcastServiceGroup;
			this->m_bPresentBroadcastServiceGroup = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refBroadcastServiceGroup(void){
			return this->m_aBroadcastServiceGroup;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getBroadcastServiceGroup(void) const{
			return this->m_aBroadcastServiceGroup;
		}

		inline void SMPPBroadcastSM::setCallbackNum(const std::vector<unsigned char>& aCallbackNum){
			this->m_nCallbackNumLen = aCallbackNum.size();
			this->m_aCallbackNum = aCallbackNum;
			this->m_bPresentCallbackNum = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refCallbackNum(void){
			return this->m_aCallbackNum;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getCallbackNum(void) const{
			return this->m_aCallbackNum;
		}

		inline void SMPPBroadcastSM::setCallbackNumPresInd(const unsigned char nCallbackNumPresInd){
			this->m_nCallbackNumPresInd = nCallbackNumPresInd;
			this->m_bPresentCallbackNumPresInd = true;
		}

		inline unsigned char& SMPPBroadcastSM::refCallbackNumPresInd(void){
			return this->m_nCallbackNumPresInd;
		}

		inline const unsigned char SMPPBroadcastSM::getCallbackNumPresInd(void) const{
			return this->m_nCallbackNumPresInd;
		}

		inline void SMPPBroadcastSM::setCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag){
			this->m_nCallbackNumAtagLen = aCallbackNumAtag.size();
			this->m_aCallbackNumAtag = aCallbackNumAtag;
			this->m_bPresentCallbackNumAtag = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refCallbackNumAtag(void){
			return this->m_aCallbackNumAtag;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getCallbackNumAtag(void) const{
			return this->m_aCallbackNumAtag;
		}

		inline void SMPPBroadcastSM::setDestAddrSubunit(const unsigned char nDestAddrSubunit){
			this->m_nDestAddrSubunit = nDestAddrSubunit;
			this->m_bPresentDestAddrSubunit = true;
		}

		inline unsigned char& SMPPBroadcastSM::refDestAddrSubunit(void){
			return this->m_nDestAddrSubunit;
		}

		inline const unsigned char SMPPBroadcastSM::getDestAddrSubunit(void) const{
			return this->m_nDestAddrSubunit;
		}

		inline void SMPPBroadcastSM::setDestSubaddress(const std::vector<unsigned char>& aDestSubaddress){
			this->m_nDestSubaddressLen = aDestSubaddress.size();
			this->m_aDestSubaddress = aDestSubaddress;
			this->m_bPresentDestSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refDestSubaddress(void){
			return this->m_aDestSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getDestSubaddress(void) const{
			return this->m_aDestSubaddress;
		}

		inline void SMPPBroadcastSM::setDestPort(const unsigned short nDestPort){
			this->m_nDestPort = nDestPort;
			this->m_bPresentDestPort = true;
		}

		inline unsigned short& SMPPBroadcastSM::refDestPort(void){
			return this->m_nDestPort;
		}

		inline const unsigned short SMPPBroadcastSM::getDestPort(void) const{
			return this->m_nDestPort;
		}

		inline void SMPPBroadcastSM::setDisplayTime(const unsigned char nDisplayTime){
			this->m_nDisplayTime = nDisplayTime;
			this->m_bPresentDisplayTime = true;
		}

		inline unsigned char& SMPPBroadcastSM::refDisplayTime(void){
			return this->m_nDisplayTime;
		}

		inline const unsigned char SMPPBroadcastSM::getDisplayTime(void) const{
			return this->m_nDisplayTime;
		}

		inline void SMPPBroadcastSM::setLanguageIndicator(const unsigned char nLanguageIndicator){
			this->m_nLanguageIndicator = nLanguageIndicator;
			this->m_bPresentLanguageIndicator = true;
		}

		inline unsigned char& SMPPBroadcastSM::refLanguageIndicator(void){
			return this->m_nLanguageIndicator;
		}

		inline const unsigned char SMPPBroadcastSM::getLanguageIndicator(void) const{
			return this->m_nLanguageIndicator;
		}

		inline void SMPPBroadcastSM::setMessagePayload(const std::vector<unsigned char>& aMessagePayload){
			this->m_nMessagePayloadLen = aMessagePayload.size();
			this->m_aMessagePayload = aMessagePayload;
			this->m_bPresentMessagePayload = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refMessagePayload(void){
			return this->m_aMessagePayload;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getMessagePayload(void) const{
			return this->m_aMessagePayload;
		}

		inline void SMPPBroadcastSM::setMsValidity(const unsigned char nMsValidity){
			this->m_nMsValidity = nMsValidity;
			this->m_bPresentMsValidity = true;
		}

		inline unsigned char& SMPPBroadcastSM::refMsValidity(void){
			return this->m_nMsValidity;
		}

		inline const unsigned char SMPPBroadcastSM::getMsValidity(void) const{
			return this->m_nMsValidity;
		}

		inline void SMPPBroadcastSM::setPayloadType(const unsigned char nPayloadType){
			this->m_nPayloadType = nPayloadType;
			this->m_bPresentPayloadType = true;
		}

		inline unsigned char& SMPPBroadcastSM::refPayloadType(void){
			return this->m_nPayloadType;
		}

		inline const unsigned char SMPPBroadcastSM::getPayloadType(void) const{
			return this->m_nPayloadType;
		}

		inline void SMPPBroadcastSM::setPrivacyIndicator(const unsigned char nPrivacyIndicator){
			this->m_nPrivacyIndicator = nPrivacyIndicator;
			this->m_bPresentPrivacyIndicator = true;
		}

		inline unsigned char& SMPPBroadcastSM::refPrivacyIndicator(void){
			return this->m_nPrivacyIndicator;
		}

		inline const unsigned char SMPPBroadcastSM::getPrivacyIndicator(void) const{
			return this->m_nPrivacyIndicator;
		}

		inline void SMPPBroadcastSM::setSmsSignal(const unsigned short nSmsSignal){
			this->m_nSmsSignal = nSmsSignal;
			this->m_bPresentSmsSignal = true;
		}

		inline unsigned short& SMPPBroadcastSM::refSmsSignal(void){
			return this->m_nSmsSignal;
		}

		inline const unsigned short SMPPBroadcastSM::getSmsSignal(void) const{
			return this->m_nSmsSignal;
		}

		inline void SMPPBroadcastSM::setSourceAddrSubunit(const unsigned char nSourceAddrSubunit){
			this->m_nSourceAddrSubunit = nSourceAddrSubunit;
			this->m_bPresentSourceAddrSubunit = true;
		}

		inline unsigned char& SMPPBroadcastSM::refSourceAddrSubunit(void){
			return this->m_nSourceAddrSubunit;
		}

		inline const unsigned char SMPPBroadcastSM::getSourceAddrSubunit(void) const{
			return this->m_nSourceAddrSubunit;
		}

		inline void SMPPBroadcastSM::setSourcePort(const unsigned short nSourcePort){
			this->m_nSourcePort = nSourcePort;
			this->m_bPresentSourcePort = true;
		}

		inline unsigned short& SMPPBroadcastSM::refSourcePort(void){
			return this->m_nSourcePort;
		}

		inline const unsigned short SMPPBroadcastSM::getSourcePort(void) const{
			return this->m_nSourcePort;
		}

		inline void SMPPBroadcastSM::setSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress){
			this->m_nSourceSubaddressLen = aSourceSubaddress.size();
			this->m_aSourceSubaddress = aSourceSubaddress;
			this->m_bPresentSourceSubaddress = true;
		}

		inline std::vector<unsigned char>& SMPPBroadcastSM::refSourceSubaddress(void){
			return this->m_aSourceSubaddress;
		}

		inline const std::vector<unsigned char>& SMPPBroadcastSM::getSourceSubaddress(void) const{
			return this->m_aSourceSubaddress;
		}

		inline void SMPPBroadcastSM::setUserMessageReference(const unsigned short nUserMessageReference){
			this->m_nUserMessageReference = nUserMessageReference;
			this->m_bPresentUserMessageReference = true;
		}

		inline unsigned short& SMPPBroadcastSM::refUserMessageReference(void){
			return this->m_nUserMessageReference;
		}

		inline const unsigned short SMPPBroadcastSM::getUserMessageReference(void) const{
			return this->m_nUserMessageReference;
		}

		inline void SMPPBroadcastSM::addBroadcastAreaIdentifierLen(const unsigned short nBroadcastAreaIdentifierLen){
			this->m_aBroadcastAreaIdentifierLen.push_back(nBroadcastAreaIdentifierLen);
		}

		inline void SMPPBroadcastSM::setBroadcastAreaIdentifierLen(const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){
			this->m_aBroadcastAreaIdentifierLen = aBroadcastAreaIdentifierLen;
		}

		inline std::vector<unsigned short>& SMPPBroadcastSM::refBroadcastAreaIdentifierLen(void){
			return this->m_aBroadcastAreaIdentifierLen;
		}

		inline const std::vector<unsigned short>& SMPPBroadcastSM::getBroadcastAreaIdentifierLen(void) const{
			return this->m_aBroadcastAreaIdentifierLen;
		}

	
		inline void SMPPBroadcastSM::setBroadcastContentTypeLen(const unsigned short nBroadcastContentTypeLen){
			this->m_nBroadcastContentTypeLen = nBroadcastContentTypeLen;
		}

		inline unsigned short& SMPPBroadcastSM::refBroadcastContentTypeLen(void){
			return this->m_nBroadcastContentTypeLen;
		}

		inline const unsigned short SMPPBroadcastSM::getBroadcastContentTypeLen(void) const{
			return this->m_nBroadcastContentTypeLen;
		}


		inline void SMPPBroadcastSM::setBroadcastRepNumLen(const unsigned short nBroadcastRepNumLen){
			this->m_nBroadcastRepNumLen = nBroadcastRepNumLen;
		}

		inline unsigned short& SMPPBroadcastSM::refBroadcastRepNumLen(void){
			return this->m_nBroadcastRepNumLen;
		}

		inline const unsigned short SMPPBroadcastSM::getBroadcastRepNumLen(void) const{
			return this->m_nBroadcastRepNumLen;
		}


		inline void SMPPBroadcastSM::setBroadcastFrequencyIntervalLen(const unsigned short nBroadcastFrequencyIntervalLen){
			this->m_nBroadcastFrequencyIntervalLen = nBroadcastFrequencyIntervalLen;
		}

		inline unsigned short& SMPPBroadcastSM::refBroadcastFrequencyIntervalLen(void){
			return this->m_nBroadcastFrequencyIntervalLen;
		}

		inline const unsigned short SMPPBroadcastSM::getBroadcastFrequencyIntervalLen(void) const{
			return this->m_nBroadcastFrequencyIntervalLen;
		}


		inline void SMPPBroadcastSM::setAlertOnMsgDeliveryLen(const unsigned short nAlertOnMsgDeliveryLen){
			this->m_nAlertOnMsgDeliveryLen = nAlertOnMsgDeliveryLen;
		}

		inline unsigned short& SMPPBroadcastSM::refAlertOnMsgDeliveryLen(void){
			return this->m_nAlertOnMsgDeliveryLen;
		}

		inline const unsigned short SMPPBroadcastSM::getAlertOnMsgDeliveryLen(void) const{
			return this->m_nAlertOnMsgDeliveryLen;
		}


		inline void SMPPBroadcastSM::setBroadcastChannelIndicatorLen(const unsigned short nBroadcastChannelIndicatorLen){
			this->m_nBroadcastChannelIndicatorLen = nBroadcastChannelIndicatorLen;
		}

		inline unsigned short& SMPPBroadcastSM::refBroadcastChannelIndicatorLen(void){
			return this->m_nBroadcastChannelIndicatorLen;
		}

		inline const unsigned short SMPPBroadcastSM::getBroadcastChannelIndicatorLen(void) const{
			return this->m_nBroadcastChannelIndicatorLen;
		}


		inline void SMPPBroadcastSM::setBroadcastContentTypeInfoLen(const unsigned short nBroadcastContentTypeInfoLen){
			this->m_nBroadcastContentTypeInfoLen = nBroadcastContentTypeInfoLen;
		}

		inline unsigned short& SMPPBroadcastSM::refBroadcastContentTypeInfoLen(void){
			return this->m_nBroadcastContentTypeInfoLen;
		}

		inline const unsigned short SMPPBroadcastSM::getBroadcastContentTypeInfoLen(void) const{
			return this->m_nBroadcastContentTypeInfoLen;
		}


		inline void SMPPBroadcastSM::setBroadcastMessageClassLen(const unsigned short nBroadcastMessageClassLen){
			this->m_nBroadcastMessageClassLen = nBroadcastMessageClassLen;
		}

		inline unsigned short& SMPPBroadcastSM::refBroadcastMessageClassLen(void){
			return this->m_nBroadcastMessageClassLen;
		}

		inline const unsigned short SMPPBroadcastSM::getBroadcastMessageClassLen(void) const{
			return this->m_nBroadcastMessageClassLen;
		}


		inline void SMPPBroadcastSM::setBroadcastServiceGroupLen(const unsigned short nBroadcastServiceGroupLen){
			this->m_nBroadcastServiceGroupLen = nBroadcastServiceGroupLen;
		}

		inline unsigned short& SMPPBroadcastSM::refBroadcastServiceGroupLen(void){
			return this->m_nBroadcastServiceGroupLen;
		}

		inline const unsigned short SMPPBroadcastSM::getBroadcastServiceGroupLen(void) const{
			return this->m_nBroadcastServiceGroupLen;
		}


		inline void SMPPBroadcastSM::setCallbackNumLen(const unsigned short nCallbackNumLen){
			this->m_nCallbackNumLen = nCallbackNumLen;
		}

		inline unsigned short& SMPPBroadcastSM::refCallbackNumLen(void){
			return this->m_nCallbackNumLen;
		}

		inline const unsigned short SMPPBroadcastSM::getCallbackNumLen(void) const{
			return this->m_nCallbackNumLen;
		}


		inline void SMPPBroadcastSM::setCallbackNumAtagLen(const unsigned short nCallbackNumAtagLen){
			this->m_nCallbackNumAtagLen = nCallbackNumAtagLen;
		}

		inline unsigned short& SMPPBroadcastSM::refCallbackNumAtagLen(void){
			return this->m_nCallbackNumAtagLen;
		}

		inline const unsigned short SMPPBroadcastSM::getCallbackNumAtagLen(void) const{
			return this->m_nCallbackNumAtagLen;
		}


		inline void SMPPBroadcastSM::setCallbackNumPresIndLen(const unsigned short nCallbackNumPresIndLen){
			this->m_nCallbackNumPresIndLen = nCallbackNumPresIndLen;
		}

		inline unsigned short& SMPPBroadcastSM::refCallbackNumPresIndLen(void){
			return this->m_nCallbackNumPresIndLen;
		}

		inline const unsigned short SMPPBroadcastSM::getCallbackNumPresIndLen(void) const{
			return this->m_nCallbackNumPresIndLen;
		}


		inline void SMPPBroadcastSM::setDestAddrSubunitLen(const unsigned short nDestAddrSubunitLen){
			this->m_nDestAddrSubunitLen = nDestAddrSubunitLen;
		}

		inline unsigned short& SMPPBroadcastSM::refDestAddrSubunitLen(void){
			return this->m_nDestAddrSubunitLen;
		}

		inline const unsigned short SMPPBroadcastSM::getDestAddrSubunitLen(void) const{
			return this->m_nDestAddrSubunitLen;
		}


		inline void SMPPBroadcastSM::setDestSubaddressLen(const unsigned short nDestSubaddressLen){
			this->m_nDestSubaddressLen = nDestSubaddressLen;
		}

		inline unsigned short& SMPPBroadcastSM::refDestSubaddressLen(void){
			return this->m_nDestSubaddressLen;
		}

		inline const unsigned short SMPPBroadcastSM::getDestSubaddressLen(void) const{
			return this->m_nDestSubaddressLen;
		}


		inline void SMPPBroadcastSM::setDestPortLen(const unsigned short nDestPortLen){
			this->m_nDestPortLen = nDestPortLen;
		}

		inline unsigned short& SMPPBroadcastSM::refDestPortLen(void){
			return this->m_nDestPortLen;
		}

		inline const unsigned short SMPPBroadcastSM::getDestPortLen(void) const{
			return this->m_nDestPortLen;
		}


		inline void SMPPBroadcastSM::setDisplayTimeLen(const unsigned short nDisplayTimeLen){
			this->m_nDisplayTimeLen = nDisplayTimeLen;
		}

		inline unsigned short& SMPPBroadcastSM::refDisplayTimeLen(void){
			return this->m_nDisplayTimeLen;
		}

		inline const unsigned short SMPPBroadcastSM::getDisplayTimeLen(void) const{
			return this->m_nDisplayTimeLen;
		}


		inline void SMPPBroadcastSM::setLanguageIndicatorLen(const unsigned short nLanguageIndicatorLen){
			this->m_nLanguageIndicatorLen = nLanguageIndicatorLen;
		}

		inline unsigned short& SMPPBroadcastSM::refLanguageIndicatorLen(void){
			return this->m_nLanguageIndicatorLen;
		}

		inline const unsigned short SMPPBroadcastSM::getLanguageIndicatorLen(void) const{
			return this->m_nLanguageIndicatorLen;
		}


		inline void SMPPBroadcastSM::setMessagePayloadLen(const unsigned short nMessagePayloadLen){
			this->m_nMessagePayloadLen = nMessagePayloadLen;
		}

		inline unsigned short& SMPPBroadcastSM::refMessagePayloadLen(void){
			return this->m_nMessagePayloadLen;
		}

		inline const unsigned short SMPPBroadcastSM::getMessagePayloadLen(void) const{
			return this->m_nMessagePayloadLen;
		}


		inline void SMPPBroadcastSM::setMsValidityLen(const unsigned short nMsValidityLen){
			this->m_nMsValidityLen = nMsValidityLen;
		}

		inline unsigned short& SMPPBroadcastSM::refMsValidityLen(void){
			return this->m_nMsValidityLen;
		}

		inline const unsigned short SMPPBroadcastSM::getMsValidityLen(void) const{
			return this->m_nMsValidityLen;
		}


		inline void SMPPBroadcastSM::setPayloadTypeLen(const unsigned short nPayloadTypeLen){
			this->m_nPayloadTypeLen = nPayloadTypeLen;
		}

		inline unsigned short& SMPPBroadcastSM::refPayloadTypeLen(void){
			return this->m_nPayloadTypeLen;
		}

		inline const unsigned short SMPPBroadcastSM::getPayloadTypeLen(void) const{
			return this->m_nPayloadTypeLen;
		}


		inline void SMPPBroadcastSM::setPrivacyIndicatorLen(const unsigned short nPrivacyIndicatorLen){
			this->m_nPrivacyIndicatorLen = nPrivacyIndicatorLen;
		}

		inline unsigned short& SMPPBroadcastSM::refPrivacyIndicatorLen(void){
			return this->m_nPrivacyIndicatorLen;
		}

		inline const unsigned short SMPPBroadcastSM::getPrivacyIndicatorLen(void) const{
			return this->m_nPrivacyIndicatorLen;
		}


		inline void SMPPBroadcastSM::setSmsSignalLen(const unsigned short nSmsSignalLen){
			this->m_nSmsSignalLen = nSmsSignalLen;
		}

		inline unsigned short& SMPPBroadcastSM::refSmsSignalLen(void){
			return this->m_nSmsSignalLen;
		}

		inline const unsigned short SMPPBroadcastSM::getSmsSignalLen(void) const{
			return this->m_nSmsSignalLen;
		}


		inline void SMPPBroadcastSM::setSourceAddrSubunitLen(const unsigned short nSourceAddrSubunitLen){
			this->m_nSourceAddrSubunitLen = nSourceAddrSubunitLen;
		}

		inline unsigned short& SMPPBroadcastSM::refSourceAddrSubunitLen(void){
			return this->m_nSourceAddrSubunitLen;
		}

		inline const unsigned short SMPPBroadcastSM::getSourceAddrSubunitLen(void) const{
			return this->m_nSourceAddrSubunitLen;
		}


		inline void SMPPBroadcastSM::setSourcePortLen(const unsigned short nSourcePortLen){
			this->m_nSourcePortLen = nSourcePortLen;
		}

		inline unsigned short& SMPPBroadcastSM::refSourcePortLen(void){
			return this->m_nSourcePortLen;
		}

		inline const unsigned short SMPPBroadcastSM::getSourcePortLen(void) const{
			return this->m_nSourcePortLen;
		}


		inline void SMPPBroadcastSM::setSourceSubaddressLen(const unsigned short nSourceSubaddressLen){
			this->m_nSourceSubaddressLen = nSourceSubaddressLen;
		}

		inline unsigned short& SMPPBroadcastSM::refSourceSubaddressLen(void){
			return this->m_nSourceSubaddressLen;
		}

		inline const unsigned short SMPPBroadcastSM::getSourceSubaddressLen(void) const{
			return this->m_nSourceSubaddressLen;
		}


		inline void SMPPBroadcastSM::setUserMessageReferenceLen(const unsigned short nUserMessageReferenceLen){
			this->m_nUserMessageReferenceLen = nUserMessageReferenceLen;
		}

		inline unsigned short& SMPPBroadcastSM::refUserMessageReferenceLen(void){
			return this->m_nUserMessageReferenceLen;
		}

		inline const unsigned short SMPPBroadcastSM::getUserMessageReferenceLen(void) const{
			return this->m_nUserMessageReferenceLen;
		}



	}
}
