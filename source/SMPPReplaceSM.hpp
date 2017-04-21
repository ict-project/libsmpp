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

#ifndef SMPPREPLACESM_HPP
#define SMPPREPLACESM_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPReplaceSM  : public SMPPPDU, 
			public boost::enable_shared_from_this < SMPPReplaceSM >{
		public:
			typedef boost::shared_ptr<SMPPReplaceSM> SharedPtr;
		public:
			SMPPReplaceSM(void);
			SMPPReplaceSM(const unsigned nSequenceNumber);
			virtual ~SMPPReplaceSM();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentMessagePayload(void) const;
			inline void omitPresentMessagePayload(void);
			inline void setPresentMessagePayload(const bool);

			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

			inline void setSourceAddrTON(const unsigned char);
			inline unsigned char& refSourceAddrTON(void);
			inline const unsigned char getSourceAddrTON(void) const;

			inline void setSourceAddrNPI(const unsigned char);
			inline unsigned char& refSourceAddrNPI(void);
			inline const unsigned char getSourceAddrNPI(void) const;

			inline void setSourceAddr(const std::string&);
			inline std::string& refSourceAddr(void);
			inline const std::string& getSourceAddr(void) const;

			inline void setScheduleDeliveryTime(const std::string&);
			inline std::string& refScheduleDeliveryTime(void);
			inline const std::string& getScheduleDeliveryTime(void) const;

			inline void setValidityPeriod(const std::string&);
			inline std::string& refValidityPeriod(void);
			inline const std::string& getValidityPeriod(void) const;

			inline void setRegisteredDelivery(const unsigned char);
			inline unsigned char& refRegisteredDelivery(void);
			inline const unsigned char getRegisteredDelivery(void) const;

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

			inline void setMessagePayload(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refMessagePayload(void);
			inline const std::vector<unsigned char>& getMessagePayload(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setMessagePayloadLen(const unsigned short);
			inline unsigned short& refMessagePayloadLen(void);
			inline const unsigned short getMessagePayloadLen(void) const;


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
			std::string m_sMessageId;
			unsigned char m_nSourceAddrTON;
			unsigned char m_nSourceAddrNPI;
			std::string m_sSourceAddr;
			std::string m_sScheduleDeliveryTime;
			std::string m_sValidityPeriod;
			unsigned char m_nRegisteredDelivery;
			unsigned char m_nSMDefaultMsgId;
			unsigned char m_nSMLength;
			std::vector<unsigned char> m_aShortMessage;
			/**
			 * An optional fields
			 *
			 */
			std::vector<unsigned char> m_aMessagePayload;


			/**
			 * A present fields for optional fields
			 *
			 */
			bool m_bPresentMessagePayload;
			/**
			 * An optional fields
			 *
			 */
			unsigned short m_nMessagePayloadLen;

		};
	}
}

// Include inline files
#include "SMPPReplaceSM.inl"

#endif // SMPPREPLACESM_HPP
