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

#ifndef SMPPDELIVERSM_HPP
#define SMPPDELIVERSM_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPDeliverSM  : public SMPPPDU, 
			public boost::enable_shared_from_this < SMPPDeliverSM >{
		public:
			typedef boost::shared_ptr<SMPPDeliverSM> SharedPtr;
		public:
			SMPPDeliverSM(void);
			SMPPDeliverSM(const unsigned nSequenceNumber);
			virtual ~SMPPDeliverSM();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentUserMessageReference(void) const;
			inline void omitPresentUserMessageReference(void);
			inline void setPresentUserMessageReference(const bool);

			inline const bool isPresentSourcePort(void) const;
			inline void omitPresentSourcePort(void);
			inline void setPresentSourcePort(const bool);

			inline const bool isPresentDestinationPort(void) const;
			inline void omitPresentDestinationPort(void);
			inline void setPresentDestinationPort(const bool);

			inline const bool isPresentSarMsgRefNum(void) const;
			inline void omitPresentSarMsgRefNum(void);
			inline void setPresentSarMsgRefNum(const bool);

			inline const bool isPresentSarTotalSegments(void) const;
			inline void omitPresentSarTotalSegments(void);
			inline void setPresentSarTotalSegments(const bool);

			inline const bool isPresentSarSegmentSeqnum(void) const;
			inline void omitPresentSarSegmentSeqnum(void);
			inline void setPresentSarSegmentSeqnum(const bool);

			inline const bool isPresentUserResponseCode(void) const;
			inline void omitPresentUserResponseCode(void);
			inline void setPresentUserResponseCode(const bool);

			inline const bool isPresentPrivacyIndicator(void) const;
			inline void omitPresentPrivacyIndicator(void);
			inline void setPresentPrivacyIndicator(const bool);

			inline const bool isPresentPayloadType(void) const;
			inline void omitPresentPayloadType(void);
			inline void setPresentPayloadType(const bool);

			inline const bool isPresentMessagePayload(void) const;
			inline void omitPresentMessagePayload(void);
			inline void setPresentMessagePayload(const bool);

			inline const bool isPresentCallbackNum(void) const;
			inline void omitPresentCallbackNum(void);
			inline void setPresentCallbackNum(const bool);

			inline const bool isPresentSourceSubaddress(void) const;
			inline void omitPresentSourceSubaddress(void);
			inline void setPresentSourceSubaddress(const bool);

			inline const bool isPresentDestSubaddress(void) const;
			inline void omitPresentDestSubaddress(void);
			inline void setPresentDestSubaddress(const bool);

			inline const bool isPresentLanguageIndicator(void) const;
			inline void omitPresentLanguageIndicator(void);
			inline void setPresentLanguageIndicator(const bool);

			inline const bool isPresentItsSessionInfo(void) const;
			inline void omitPresentItsSessionInfo(void);
			inline void setPresentItsSessionInfo(const bool);

			inline const bool isPresentNetworkErrorCode(void) const;
			inline void omitPresentNetworkErrorCode(void);
			inline void setPresentNetworkErrorCode(const bool);

			inline const bool isPresentMessageState(void) const;
			inline void omitPresentMessageState(void);
			inline void setPresentMessageState(const bool);

			inline const bool isPresentReceiptedMessageId(void) const;
			inline void omitPresentReceiptedMessageId(void);
			inline void setPresentReceiptedMessageId(const bool);

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

			inline void setDestAddrTON(const unsigned char);
			inline unsigned char& refDestAddrTON(void);
			inline const unsigned char getDestAddrTON(void) const;

			inline void setDestAddrNPI(const unsigned char);
			inline unsigned char& refDestAddrNPI(void);
			inline const unsigned char getDestAddrNPI(void) const;

			inline void setDestAddr(const std::string&);
			inline std::string& refDestAddr(void);
			inline const std::string& getDestAddr(void) const;

			inline void setEsmClass(const unsigned char);
			inline unsigned char& refEsmClass(void);
			inline const unsigned char getEsmClass(void) const;

			inline void setProtocolId(const unsigned char);
			inline unsigned char& refProtocolId(void);
			inline const unsigned char getProtocolId(void) const;

			inline void setPriorityFlag(const unsigned char);
			inline unsigned char& refPriorityFlag(void);
			inline const unsigned char getPriorityFlag(void) const;

			inline void setScheduleDeliveryTime(const std::string&);
			inline std::string& refScheduleDeliveryTime(void);
			inline const std::string& getScheduleDeliveryTime(void) const;

			inline void setValidityPeriod(const std::string&);
			inline std::string& refValidityPeriod(void);
			inline const std::string& getValidityPeriod(void) const;

			inline void setRegisteredDelivery(const unsigned char);
			inline unsigned char& refRegisteredDelivery(void);
			inline const unsigned char getRegisteredDelivery(void) const;

			inline void setReplaceIfPresentFlag(const unsigned char);
			inline unsigned char& refReplaceIfPresentFlag(void);
			inline const unsigned char getReplaceIfPresentFlag(void) const;

			inline void setDataCoding(const unsigned char);
			inline unsigned char& refDataCoding(void);
			inline const unsigned char getDataCoding(void) const;

			inline void setSMDefaultMsgId(const unsigned char);
			inline unsigned char& refSMDefaultMsgId(void);
			inline const unsigned char getSMDefaultMsgId(void) const;

			inline void setSMLength(const unsigned char);
			inline unsigned char& refSMLength(void);
			inline const unsigned char getSMLength(void) const;

			inline void setShortMessage(const std::vector<unsigned char>&);
			inline void setShortMessage(const std::string&);
			inline std::vector<unsigned char>& refShortMessage(void);
			inline const std::vector<unsigned char>& getShortMessage(void) const;

			inline void setUserMessageReference(const unsigned short);
			inline unsigned short& refUserMessageReference(void);
			inline const unsigned short getUserMessageReference(void) const;

			inline void setSourcePort(const unsigned short);
			inline unsigned short& refSourcePort(void);
			inline const unsigned short getSourcePort(void) const;

			inline void setDestinationPort(const unsigned short);
			inline unsigned short& refDestinationPort(void);
			inline const unsigned short getDestinationPort(void) const;

			inline void setSarMsgRefNum(const unsigned short);
			inline unsigned short& refSarMsgRefNum(void);
			inline const unsigned short getSarMsgRefNum(void) const;

			inline void setSarTotalSegments(const unsigned char);
			inline unsigned char& refSarTotalSegments(void);
			inline const unsigned char getSarTotalSegments(void) const;

			inline void setSarSegmentSeqnum(const unsigned char);
			inline unsigned char& refSarSegmentSeqnum(void);
			inline const unsigned char getSarSegmentSeqnum(void) const;

			inline void setUserResponseCode(const unsigned char);
			inline unsigned char& refUserResponseCode(void);
			inline const unsigned char getUserResponseCode(void) const;

			inline void setPrivacyIndicator(const unsigned char);
			inline unsigned char& refPrivacyIndicator(void);
			inline const unsigned char getPrivacyIndicator(void) const;

			inline void setPayloadType(const unsigned char);
			inline unsigned char& refPayloadType(void);
			inline const unsigned char getPayloadType(void) const;

			inline void setMessagePayload(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refMessagePayload(void);
			inline const std::vector<unsigned char>& getMessagePayload(void) const;

			inline void setCallbackNum(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refCallbackNum(void);
			inline const std::vector<unsigned char>& getCallbackNum(void) const;

			inline void setSourceSubaddress(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refSourceSubaddress(void);
			inline const std::vector<unsigned char>& getSourceSubaddress(void) const;

			inline void setDestSubaddress(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refDestSubaddress(void);
			inline const std::vector<unsigned char>& getDestSubaddress(void) const;

			inline void setLanguageIndicator(const unsigned char);
			inline unsigned char& refLanguageIndicator(void);
			inline const unsigned char getLanguageIndicator(void) const;

			inline void setItsSessionInfo(const unsigned short);
			inline unsigned short& refItsSessionInfo(void);
			inline const unsigned short getItsSessionInfo(void) const;

			inline void setNetworkErrorCode(const unsigned char nNetworkCode, const unsigned short nErrorCode);
			inline void setNetworkErrorCode(const NetworkErrorCode&);
			inline NetworkErrorCode& refNetworkErrorCode(void);
			inline const NetworkErrorCode& getNetworkErrorCode(void) const;

			inline void setMessageState(const unsigned char);
			inline unsigned char& refMessageState(void);
			inline const unsigned char getMessageState(void) const;

			inline void setReceiptedMessageId(const std::string&);
			inline void setReceiptedMessageId(const unsigned);
			inline std::string& refReceiptedMessageId(void);
			inline const std::string& getReceiptedMessageId(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setUserMessageReferenceLen(const unsigned short);
			inline unsigned short& refUserMessageReferenceLen(void);
			inline const unsigned short getUserMessageReferenceLen(void) const;

			inline void setSourcePortLen(const unsigned short);
			inline unsigned short& refSourcePortLen(void);
			inline const unsigned short getSourcePortLen(void) const;

			inline void setDestinationPortLen(const unsigned short);
			inline unsigned short& refDestinationPortLen(void);
			inline const unsigned short getDestinationPortLen(void) const;

			inline void setSarMsgRefNumLen(const unsigned short);
			inline unsigned short& refSarMsgRefNumLen(void);
			inline const unsigned short getSarMsgRefNumLen(void) const;

			inline void setSarTotalSegmentsLen(const unsigned short);
			inline unsigned short& refSarTotalSegmentsLen(void);
			inline const unsigned short getSarTotalSegmentsLen(void) const;

			inline void setSarSegmentSeqnumLen(const unsigned short);
			inline unsigned short& refSarSegmentSeqnumLen(void);
			inline const unsigned short getSarSegmentSeqnumLen(void) const;

			inline void setUserResponseCodeLen(const unsigned short);
			inline unsigned short& refUserResponseCodeLen(void);
			inline const unsigned short getUserResponseCodeLen(void) const;

			inline void setPrivacyIndicatorLen(const unsigned short);
			inline unsigned short& refPrivacyIndicatorLen(void);
			inline const unsigned short getPrivacyIndicatorLen(void) const;

			inline void setPayloadTypeLen(const unsigned short);
			inline unsigned short& refPayloadTypeLen(void);
			inline const unsigned short getPayloadTypeLen(void) const;

			inline void setMessagePayloadLen(const unsigned short);
			inline unsigned short& refMessagePayloadLen(void);
			inline const unsigned short getMessagePayloadLen(void) const;

			inline void setCallbackNumLen(const unsigned short);
			inline unsigned short& refCallbackNumLen(void);
			inline const unsigned short getCallbackNumLen(void) const;

			inline void setSourceSubaddressLen(const unsigned short);
			inline unsigned short& refSourceSubaddressLen(void);
			inline const unsigned short getSourceSubaddressLen(void) const;

			inline void setDestSubaddressLen(const unsigned short);
			inline unsigned short& refDestSubaddressLen(void);
			inline const unsigned short getDestSubaddressLen(void) const;

			inline void setLanguageIndicatorLen(const unsigned short);
			inline unsigned short& refLanguageIndicatorLen(void);
			inline const unsigned short getLanguageIndicatorLen(void) const;

			inline void setItsSessionInfoLen(const unsigned short);
			inline unsigned short& refItsSessionInfoLen(void);
			inline const unsigned short getItsSessionInfoLen(void) const;

			inline void setNetworkErrorCodeLen(const unsigned short);
			inline unsigned short& refNetworkErrorCodeLen(void);
			inline const unsigned short getNetworkErrorCodeLen(void) const;

			inline void setMessageStateLen(const unsigned short);
			inline unsigned short& refMessageStateLen(void);
			inline const unsigned short getMessageStateLen(void) const;

			inline void setReceiptedMessageIdLen(const unsigned short);
			inline unsigned short& refReceiptedMessageIdLen(void);
			inline const unsigned short getReceiptedMessageIdLen(void) const;

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
			 * A mandatory fields
			 *
			 */
			std::string m_sServiceType;
			unsigned char m_nSourceAddrTON;
			unsigned char m_nSourceAddrNPI;
			std::string m_sSourceAddr;
			unsigned char m_nDestAddrTON;
			unsigned char m_nDestAddrNPI;
			std::string m_sDestAddr;
			unsigned char m_nEsmClass;
			unsigned char m_nProtocolId;
			unsigned char m_nPriorityFlag;
			std::string m_sScheduleDeliveryTime;
			std::string m_sValidityPeriod;
			unsigned char m_nRegisteredDelivery;
			unsigned char m_nReplaceIfPresentFlag;
			unsigned char m_nDataCoding;
			unsigned char m_nSMDefaultMsgId;
			unsigned char m_nSMLength;
			std::vector<unsigned char> m_aShortMessage;

			/**
			 * A optional fields
			 *
			 */
			unsigned short m_nUserMessageReference;
			unsigned short m_nSourcePort;
			unsigned short m_nDestinationPort;
			unsigned short m_nSarMsgRefNum;
			unsigned char m_nSarTotalSegments;
			unsigned char m_nSarSegmentSeqnum;
			unsigned char m_nUserResponseCode;
			unsigned char m_nPrivacyIndicator;
			unsigned char m_nPayloadType;
			std::vector<unsigned char> m_aMessagePayload;
			std::vector<unsigned char> m_aCallbackNum;
			std::vector<unsigned char> m_aSourceSubaddress;
			std::vector<unsigned char> m_aDestSubaddress;
			unsigned char m_nLanguageIndicator;
			unsigned short m_nItsSessionInfo;
			NetworkErrorCode m_oNetworkErrorCode;
			unsigned char m_nMessageState;
			std::string m_sReceiptedMessageId;

			/**
			 * A present fields for optional AVP
			 *
			 */
			bool m_bPresentUserMessageReference;		
			bool m_bPresentSourcePort;
			bool m_bPresentDestinationPort;
			bool m_bPresentSarMsgRefNum;
			bool m_bPresentSarTotalSegments;
			bool m_bPresentSarSegmentSeqnum;
			bool m_bPresentUserResponseCode;
			bool m_bPresentPrivacyIndicator;
			bool m_bPresentPayloadType;
			bool m_bPresentMessagePayload;
			bool m_bPresentCallbackNum;
			bool m_bPresentSourceSubaddress;
			bool m_bPresentDestSubaddress;
			bool m_bPresentLanguageIndicator;
			bool m_bPresentItsSessionInfo;
			bool m_bPresentNetworkErrorCode;
			bool m_bPresentMessageState;
			bool m_bPresentReceiptedMessageId;

			/**
			 * A 
			 *
			 */
			unsigned short m_nUserMessageReferenceLen;
			unsigned short m_nSourcePortLen;
			unsigned short m_nDestinationPortLen;
			unsigned short m_nSarMsgRefNumLen;
			unsigned short m_nSarTotalSegmentsLen;
			unsigned short m_nSarSegmentSeqnumLen;
			unsigned short m_nUserResponseCodeLen;
			unsigned short m_nPrivacyIndicatorLen;
			unsigned short m_nPayloadTypeLen;
			unsigned short m_nMessagePayloadLen;
			unsigned short m_nCallbackNumLen;
			unsigned short m_nSourceSubaddressLen;
			unsigned short m_nDestSubaddressLen;
			unsigned short m_nLanguageIndicatorLen;
			unsigned short m_nItsSessionInfoLen;
			unsigned short m_nNetworkErrorCodeLen;
			unsigned short m_nMessageStateLen;
			unsigned short m_nReceiptedMessageIdLen;

		};
	}
}

// Include inline files
#include "SMPPDeliverSM.inl"

#endif // SMPPDELIVERSM_HPP
