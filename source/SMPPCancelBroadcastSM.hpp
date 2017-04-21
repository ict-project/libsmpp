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

#ifndef SMPPCANCELBROADCASTSM_HPP
#define SMPPCANCELBROADCASTSM_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPCancelBroadcastSM  : public SMPPPDU, 
			public boost::enable_shared_from_this < SMPPCancelBroadcastSM >{
		public:
			typedef boost::shared_ptr<SMPPCancelBroadcastSM> SharedPtr;
		public:
			SMPPCancelBroadcastSM(void);
			SMPPCancelBroadcastSM(const unsigned nSequenceNumber);
			virtual ~SMPPCancelBroadcastSM();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentBroadcastContentType(void) const;
			inline void omitPresentBroadcastContentType(void);
			inline void setPresentBroadcastContentType(const bool);

			inline const bool isPresentUserMessageReference(void) const;
			inline void omitPresentUserMessageReference(void);
			inline void setPresentUserMessageReference(const bool);



			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setServiceType(const std::string&);
			inline std::string& refServiceType(void);
			inline const std::string& getServiceType(void) const;

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

			inline void setBroadcastContentType(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refBroadcastContentType(void);
			inline const std::vector<unsigned char>& getBroadcastContentType(void) const;

			inline void setUserMessageReference(const unsigned short);
			inline unsigned short& refUserMessageReference(void);
			inline const unsigned short getUserMessageReference(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setBroadcastContentTypeLen(const unsigned short);
			inline unsigned short& refBroadcastContentTypeLen(void);
			inline const unsigned short getBroadcastContentTypeLen(void) const;

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
			 * A specific AVP for request
			 */
			std::string m_sServiceType;
			std::string m_sMessageId;
			unsigned char m_nSourceAddrTON;
			unsigned char m_nSourceAddrNPI;
			std::string m_sSourceAddr;
			/**
			 * A optional fields
			 */
			std::vector<unsigned char> m_aBroadcastContentType;
			unsigned short m_nUserMessageReference;

			/**
			 * A present fields for optional AVP
			 *
			 */
			bool m_bPresentBroadcastContentType;
			bool m_bPresentUserMessageReference;

			/**
			 * A 
			 */
			unsigned short m_nBroadcastContentTypeLen;
			unsigned short m_nUserMessageReferenceLen;

		};
	}
}

// Include inline files
#include "SMPPCancelBroadcastSM.inl"

#endif // SMPPCANCELBROADCASTSM_HPP
