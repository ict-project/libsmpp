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

#ifndef SMPPBROADCASTSM_HPP
#define SMPPBROADCASTSM_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPBroadcastSM  : public SMPPPDU, 
			public boost::enable_shared_from_this < SMPPBroadcastSM >{
		public:
			typedef boost::shared_ptr<SMPPBroadcastSM> SharedPtr;
		public:
			SMPPBroadcastSM(void);
			SMPPBroadcastSM(const unsigned nSequenceNumber);
			virtual ~SMPPBroadcastSM();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentBroadcastAreaIdentifier(void) const;
			inline void omitPresentBroadcastAreaIdentifier(void);
			inline void setPresentBroadcastAreaIdentifier(const bool);

			inline const bool isPresentBroadcastContentType(void) const;
			inline void omitPresentBroadcastContentType(void);
			inline void setPresentBroadcastContentType(const bool);

			inline const bool isPresentBroadcastRepNum(void) const;
			inline void omitPresentBroadcastRepNum(void);
			inline void setPresentBroadcastRepNum(const bool);

			inline const bool isPresentBroadcastFrequencyInterval(void) const;
			inline void omitPresentBroadcastFrequencyInterval(void);
			inline void setPresentBroadcastFrequencyInterval(const bool);

			inline const bool isPresentAlertOnMsgDelivery(void) const;
			inline void omitPresentAlertOnMsgDelivery(void);
			inline void setPresentAlertOnMsgDelivery(const bool);

			inline const bool isPresentBroadcastChannelIndicator(void) const;
			inline void omitPresentBroadcastChannelIndicator(void);
			inline void setPresentBroadcastChannelIndicator(const bool);

			inline const bool isPresentBroadcastContentTypeInfo(void) const;
			inline void omitPresentBroadcastContentTypeInfo(void);
			inline void setPresentBroadcastContentTypeInfo(const bool);

			inline const bool isPresentBroadcastMessageClass(void) const;
			inline void omitPresentBroadcastMessageClass(void);
			inline void setPresentBroadcastMessageClass(const bool);

			inline const bool isPresentBroadcastServiceGroup(void) const;
			inline void omitPresentBroadcastServiceGroup(void);
			inline void setPresentBroadcastServiceGroup(const bool);

			inline const bool isPresentCallbackNum(void) const;
			inline void omitPresentCallbackNum(void);
			inline void setPresentCallbackNum(const bool);

			inline const bool isPresentCallbackNumAtag(void) const;
			inline void omitPresentCallbackNumAtag(void);
			inline void setPresentCallbackNumAtag(const bool);

			inline const bool isPresentCallbackNumPresInd(void) const;
			inline void omitPresentCallbackNumPresInd(void);
			inline void setPresentCallbackNumPresInd(const bool);

			inline const bool isPresentDestAddrSubunit(void) const;
			inline void omitPresentDestAddrSubunit(void);
			inline void setPresentDestAddrSubunit(const bool);

			inline const bool isPresentDestSubaddress(void) const;
			inline void omitPresentDestSubaddress(void);
			inline void setPresentDestSubaddress(const bool);

			inline const bool isPresentDestPort(void) const;
			inline void omitPresentDestPort(void);
			inline void setPresentDestPort(const bool);

			inline const bool isPresentDisplayTime(void) const;
			inline void omitPresentDisplayTime(void);
			inline void setPresentDisplayTime(const bool);

			inline const bool isPresentLanguageIndicator(void) const;
			inline void omitPresentLanguageIndicator(void);
			inline void setPresentLanguageIndicator(const bool);

			inline const bool isPresentMessagePayload(void) const;
			inline void omitPresentMessagePayload(void);
			inline void setPresentMessagePayload(const bool);

			inline const bool isPresentMsValidity(void) const;
			inline void omitPresentMsValidity(void);
			inline void setPresentMsValidity(const bool);

			inline const bool isPresentPayloadType(void) const;
			inline void omitPresentPayloadType(void);
			inline void setPresentPayloadType(const bool);

			inline const bool isPresentPrivacyIndicator(void) const;
			inline void omitPresentPrivacyIndicator(void);
			inline void setPresentPrivacyIndicator(const bool);

			inline const bool isPresentSmsSignal(void) const;
			inline void omitPresentSmsSignal(void);
			inline void setPresentSmsSignal(const bool);

			inline const bool isPresentSourceAddrSubunit(void) const;
			inline void omitPresentSourceAddrSubunit(void);
			inline void setPresentSourceAddrSubunit(const bool);

			inline const bool isPresentSourcePort(void) const;
			inline void omitPresentSourcePort(void);
			inline void setPresentSourcePort(const bool);

			inline const bool isPresentSourceSubaddress(void) const;
			inline void omitPresentSourceSubaddress(void);
			inline void setPresentSourceSubaddress(const bool);

			inline const bool isPresentUserMessageReference(void) const;
			inline void omitPresentUserMessageReference(void);
			inline void setPresentUserMessageReference(const bool);

			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setServiceType(const std::string&);
			inline std::string& refServiceType(void);
			inline const std::string& getServiceType(void) const;

			inline void setSourceAddrTON(const unsigned char);
			inline unsigned char& refSourceAddrTON(void);
			inline const unsigned char getSourceAddrTON(void) const;

			inline void setSourceAddrNPI(const unsigned char);
			inline unsigned char& refSourceAddrNPI(void);
			inline const unsigned char getSourceAddrNPI(void) const;

			inline void setSourceAddr(const std::string&);
			inline std::string& refSourceAddr(void);
			inline const std::string& getSourceAddr(void) const;

			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

			inline void setPriorityFlag(const unsigned char);
			inline unsigned char& refPriorityFlag(void);
			inline const unsigned char getPriorityFlag(void) const;

			inline void setScheduleDeliveryTime(const std::string&);
			inline std::string& refScheduleDeliveryTime(void);
			inline const std::string& getScheduleDeliveryTime(void) const;

			inline void setValidityPeriod(const std::string&);
			inline std::string& refValidityPeriod(void);
			inline const std::string& getValidityPeriod(void) const;

			inline void setReplaceIfPresentFlag(const unsigned char);
			inline unsigned char& refReplaceIfPresentFlag(void);
			inline const unsigned char getReplaceIfPresentFlag(void) const;

			inline void setDataCoding(const unsigned char);
			inline unsigned char& refDataCoding(void);
			inline const unsigned char getDataCoding(void) const;

			inline void setSMDefaultMsgId(const unsigned char);
			inline unsigned char& refSMDefaultMsgId(void);
			inline const unsigned char getSMDefaultMsgId(void) const;

			inline void addBroadcastAreaIdentifier(const std::vector<unsigned char>&);
			inline void addBroadcastAreaIdentifier(const BroadcastAreaIdentifier&);
			inline void setBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&);
			inline std::vector<BroadcastAreaIdentifier>& refBroadcastAreaIdentifier(void);
			inline const std::vector<BroadcastAreaIdentifier>& getBroadcastAreaIdentifier(void) const;

			inline void setBroadcastContentType(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refBroadcastContentType(void);
			inline const std::vector<unsigned char>& getBroadcastContentType(void) const;

			inline void setBroadcastRepNum(const unsigned short);
			inline unsigned short& refBroadcastRepNum(void);
			inline const unsigned short getBroadcastRepNum(void) const;

			inline void setBroadcastFrequencyInterval(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refBroadcastFrequencyInterval(void);
			inline const std::vector<unsigned char>& getBroadcastFrequencyInterval(void) const;

			inline void setAlertOnMsgDelivery(const unsigned char);
			inline unsigned char& refAlertOnMsgDelivery(void);
			inline const unsigned char getAlertOnMsgDelivery(void) const;

			inline void setBroadcastChannelIndicator(const unsigned char);
			inline unsigned char& refBroadcastChannelIndicator(void);
			inline const unsigned char getBroadcastChannelIndicator(void) const;

			inline void setBroadcastContentTypeInfo(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refBroadcastContentTypeInfo(void);
			inline const std::vector<unsigned char>& getBroadcastContentTypeInfo(void) const;

			inline void setBroadcastMessageClass(const unsigned char);
			inline unsigned char& refBroadcastMessageClass(void);
			inline const unsigned char getBroadcastMessageClass(void) const;

			inline void setBroadcastServiceGroup(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refBroadcastServiceGroup(void);
			inline const std::vector<unsigned char>& getBroadcastServiceGroup(void) const;

			inline void setCallbackNum(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refCallbackNum(void);
			inline const std::vector<unsigned char>& getCallbackNum(void) const;

			inline void setCallbackNumAtag(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refCallbackNumAtag(void);
			inline const std::vector<unsigned char>& getCallbackNumAtag(void) const;

			inline void setCallbackNumPresInd(const unsigned char);
			inline unsigned char& refCallbackNumPresInd(void);
			inline const unsigned char getCallbackNumPresInd(void) const;

			inline void setDestAddrSubunit(const unsigned char);
			inline unsigned char& refDestAddrSubunit(void);
			inline const unsigned char getDestAddrSubunit(void) const;

			inline void setDestSubaddress(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refDestSubaddress(void);
			inline const std::vector<unsigned char>& getDestSubaddress(void) const;

			inline void setDestPort(const unsigned short);
			inline unsigned short& refDestPort(void);
			inline const unsigned short getDestPort(void) const;

			inline void setDisplayTime(const unsigned char);
			inline unsigned char& refDisplayTime(void);
			inline const unsigned char getDisplayTime(void) const;

			inline void setLanguageIndicator(const unsigned char);
			inline unsigned char& refLanguageIndicator(void);
			inline const unsigned char getLanguageIndicator(void) const;

			inline void setMessagePayload(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refMessagePayload(void);
			inline const std::vector<unsigned char>& getMessagePayload(void) const;

			inline void setMsValidity(const unsigned char);
			inline unsigned char& refMsValidity(void);
			inline const unsigned char getMsValidity(void) const;

			inline void setPayloadType(const unsigned char);
			inline unsigned char& refPayloadType(void);
			inline const unsigned char getPayloadType(void) const;

			inline void setPrivacyIndicator(const unsigned char);
			inline unsigned char& refPrivacyIndicator(void);
			inline const unsigned char getPrivacyIndicator(void) const;

			inline void setSmsSignal(const unsigned short);
			inline unsigned short& refSmsSignal(void);
			inline const unsigned short getSmsSignal(void) const;

			inline void setSourceAddrSubunit(const unsigned char);
			inline unsigned char& refSourceAddrSubunit(void);
			inline const unsigned char getSourceAddrSubunit(void) const;

			inline void setSourcePort(const unsigned short);
			inline unsigned short& refSourcePort(void);
			inline const unsigned short getSourcePort(void) const;

			inline void setSourceSubaddress(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refSourceSubaddress(void);
			inline const std::vector<unsigned char>& getSourceSubaddress(void) const;

			inline void setUserMessageReference(const unsigned short);
			inline unsigned short& refUserMessageReference(void);
			inline const unsigned short getUserMessageReference(void) const;


			/**
			 * Setters and getters for len fields
			 */
			inline void addBroadcastAreaIdentifierLen(const unsigned short);
			inline void setBroadcastAreaIdentifierLen(const std::vector<unsigned short>&);
			inline std::vector<unsigned short>& refBroadcastAreaIdentifierLen(void);
			inline const std::vector<unsigned short>& getBroadcastAreaIdentifierLen(void) const;
		
			inline void setBroadcastContentTypeLen(const unsigned short);
			inline unsigned short& refBroadcastContentTypeLen(void);
			inline const unsigned short getBroadcastContentTypeLen(void) const;

			inline void setBroadcastRepNumLen(const unsigned short);
			inline unsigned short& refBroadcastRepNumLen(void);
			inline const unsigned short getBroadcastRepNumLen(void) const;

			inline void setBroadcastFrequencyIntervalLen(const unsigned short);
			inline unsigned short& refBroadcastFrequencyIntervalLen(void);
			inline const unsigned short getBroadcastFrequencyIntervalLen(void) const;

			inline void setAlertOnMsgDeliveryLen(const unsigned short);
			inline unsigned short& refAlertOnMsgDeliveryLen(void);
			inline const unsigned short getAlertOnMsgDeliveryLen(void) const;

			inline void setBroadcastChannelIndicatorLen(const unsigned short);
			inline unsigned short& refBroadcastChannelIndicatorLen(void);
			inline const unsigned short getBroadcastChannelIndicatorLen(void) const;

			inline void setBroadcastContentTypeInfoLen(const unsigned short);
			inline unsigned short& refBroadcastContentTypeInfoLen(void);
			inline const unsigned short getBroadcastContentTypeInfoLen(void) const;

			inline void setBroadcastMessageClassLen(const unsigned short);
			inline unsigned short& refBroadcastMessageClassLen(void);
			inline const unsigned short getBroadcastMessageClassLen(void) const;

			inline void setBroadcastServiceGroupLen(const unsigned short);
			inline unsigned short& refBroadcastServiceGroupLen(void);
			inline const unsigned short getBroadcastServiceGroupLen(void) const;

			inline void setCallbackNumLen(const unsigned short);
			inline unsigned short& refCallbackNumLen(void);
			inline const unsigned short getCallbackNumLen(void) const;

			inline void setCallbackNumAtagLen(const unsigned short);
			inline unsigned short& refCallbackNumAtagLen(void);
			inline const unsigned short getCallbackNumAtagLen(void) const;

			inline void setCallbackNumPresIndLen(const unsigned short);
			inline unsigned short& refCallbackNumPresIndLen(void);
			inline const unsigned short getCallbackNumPresIndLen(void) const;

			inline void setDestAddrSubunitLen(const unsigned short);
			inline unsigned short& refDestAddrSubunitLen(void);
			inline const unsigned short getDestAddrSubunitLen(void) const;

			inline void setDestSubaddressLen(const unsigned short);
			inline unsigned short& refDestSubaddressLen(void);
			inline const unsigned short getDestSubaddressLen(void) const;

			inline void setDestPortLen(const unsigned short);
			inline unsigned short& refDestPortLen(void);
			inline const unsigned short getDestPortLen(void) const;

			inline void setDisplayTimeLen(const unsigned short);
			inline unsigned short& refDisplayTimeLen(void);
			inline const unsigned short getDisplayTimeLen(void) const;

			inline void setLanguageIndicatorLen(const unsigned short);
			inline unsigned short& refLanguageIndicatorLen(void);
			inline const unsigned short getLanguageIndicatorLen(void) const;

			inline void setMessagePayloadLen(const unsigned short);
			inline unsigned short& refMessagePayloadLen(void);
			inline const unsigned short getMessagePayloadLen(void) const;

			inline void setMsValidityLen(const unsigned short);
			inline unsigned short& refMsValidityLen(void);
			inline const unsigned short getMsValidityLen(void) const;

			inline void setPayloadTypeLen(const unsigned short);
			inline unsigned short& refPayloadTypeLen(void);
			inline const unsigned short getPayloadTypeLen(void) const;

			inline void setPrivacyIndicatorLen(const unsigned short);
			inline unsigned short& refPrivacyIndicatorLen(void);
			inline const unsigned short getPrivacyIndicatorLen(void) const;

			inline void setSmsSignalLen(const unsigned short);
			inline unsigned short& refSmsSignalLen(void);
			inline const unsigned short getSmsSignalLen(void) const;

			inline void setSourceAddrSubunitLen(const unsigned short);
			inline unsigned short& refSourceAddrSubunitLen(void);
			inline const unsigned short getSourceAddrSubunitLen(void) const;

			inline void setSourcePortLen(const unsigned short);
			inline unsigned short& refSourcePortLen(void);
			inline const unsigned short getSourcePortLen(void) const;

			inline void setSourceSubaddressLen(const unsigned short);
			inline unsigned short& refSourceSubaddressLen(void);
			inline const unsigned short getSourceSubaddressLen(void) const;

			inline void setUserMessageReferenceLen(const unsigned short);
			inline unsigned short& refUserMessageReferenceLen(void);
			inline const unsigned short getUserMessageReferenceLen(void) const;


		public:
			virtual void encodePacket(SMPPEncoder* poEncoder);
			virtual void decodePacket(SMPPDecoder* poDecoder);
			virtual void outputPacket(ISMPPOutputter* poOutputter);
			virtual void validatePacket(SMPPValidator* poValidator);

		protected:
			/**
			 * Coding and encoding interface
			 */
			virtual SMPPPDU* cloneSMPPPDU(void);
			virtual void fireOnReceived(SMPPSession*);
		protected:
			/**
			 * A specific AVP for answer
			 *
			 */
			std::string m_sServiceType;
			unsigned char m_nSourceAddrTON;
			unsigned char m_nSourceAddrNPI;
			std::string m_sSourceAddr;
			std::string m_sMessageId;
			unsigned char m_nPriorityFlag;
			std::string m_sScheduleDeliveryTime;
			std::string m_sValidityPeriod;
			unsigned char m_nReplaceIfPresentFlag;
			unsigned char m_nDataCoding;
			unsigned char m_nSMDefaultMsgId;
			std::vector<BroadcastAreaIdentifier> m_aBroadcastAreaIdentifier;
			std::vector<unsigned char> m_aBroadcastContentType;
			unsigned short m_nBroadcastRepNum;
			std::vector<unsigned char> m_aBroadcastFrequencyInterval;

			/**
			 * A specific AVP for answer
			 *
			 */
			unsigned char m_nAlertOnMsgDelivery;
			unsigned char m_nBroadcastChannelIndicator;
			std::vector<unsigned char>  m_aBroadcastContentTypeInfo;
			unsigned char m_nBroadcastMessageClass;
			std::vector<unsigned char> m_aBroadcastServiceGroup;
			std::vector<unsigned char> m_aCallbackNum;
			std::vector<unsigned char> m_aCallbackNumAtag;
			unsigned char m_nCallbackNumPresInd;
			unsigned char m_nDestAddrSubunit;
			std::vector<unsigned char> m_aDestSubaddress;
			unsigned short m_nDestPort;
			unsigned char m_nDisplayTime;
			unsigned char m_nLanguageIndicator;
			std::vector<unsigned char> m_aMessagePayload;
			unsigned char m_nMsValidity;
			unsigned char m_nPayloadType;
			unsigned char m_nPrivacyIndicator;
			unsigned short m_nSmsSignal;
			unsigned char m_nSourceAddrSubunit;
			unsigned short m_nSourcePort;
			std::vector<unsigned char> m_aSourceSubaddress;
			unsigned short m_nUserMessageReference;

			/**
			 * A present fields for optional AVP
			 *
			 */

			bool m_bPresentBroadcastAreaIdentifier;
			bool m_bPresentBroadcastContentType;
			bool m_bPresentBroadcastRepNum;
			bool m_bPresentBroadcastFrequencyInterval;
			bool m_bPresentAlertOnMsgDelivery;
			bool m_bPresentBroadcastChannelIndicator;
			bool m_bPresentBroadcastContentTypeInfo;
			bool m_bPresentBroadcastMessageClass;
			bool m_bPresentBroadcastServiceGroup;
			bool m_bPresentCallbackNum;
			bool m_bPresentCallbackNumAtag;
			bool m_bPresentCallbackNumPresInd;
			bool m_bPresentDestAddrSubunit;
			bool m_bPresentDestSubaddress;
			bool m_bPresentDestPort;
			bool m_bPresentDisplayTime;
			bool m_bPresentLanguageIndicator;
			bool m_bPresentMessagePayload;
			bool m_bPresentMsValidity;
			bool m_bPresentPayloadType;
			bool m_bPresentPrivacyIndicator;
			bool m_bPresentSmsSignal;
			bool m_bPresentSourceAddrSubunit;
			bool m_bPresentSourcePort;
			bool m_bPresentSourceSubaddress;
			bool m_bPresentUserMessageReference;

			/**
			 * A specific AVP for answer
			 *
			 */
			std::vector<unsigned short> m_aBroadcastAreaIdentifierLen;
			unsigned short m_nBroadcastContentTypeLen;
			unsigned short m_nBroadcastRepNumLen;
			unsigned short m_nBroadcastFrequencyIntervalLen;
			unsigned short m_nAlertOnMsgDeliveryLen;
			unsigned short m_nBroadcastChannelIndicatorLen;
			unsigned short m_nBroadcastContentTypeInfoLen;
			unsigned short m_nBroadcastMessageClassLen;
			unsigned short m_nBroadcastServiceGroupLen;
			unsigned short m_nCallbackNumLen;
			unsigned short m_nCallbackNumAtagLen;
			unsigned short m_nCallbackNumPresIndLen;
			unsigned short m_nDestAddrSubunitLen;
			unsigned short m_nDestSubaddressLen;
			unsigned short m_nDestPortLen;
			unsigned short m_nDisplayTimeLen;
			unsigned short m_nLanguageIndicatorLen;
			unsigned short m_nMessagePayloadLen;
			unsigned short m_nMsValidityLen;
			unsigned short m_nPayloadTypeLen;
			unsigned short m_nPrivacyIndicatorLen;
			unsigned short m_nSmsSignalLen;
			unsigned short m_nSourceAddrSubunitLen;
			unsigned short m_nSourcePortLen;
			unsigned short m_nSourceSubaddressLen;
			unsigned short m_nUserMessageReferenceLen;

		};
	}
}

// Include inline files
#include "SMPPBroadcastSM.inl"

#endif // SMPPBROADCASTSM_HPP
