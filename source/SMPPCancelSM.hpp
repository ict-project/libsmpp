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

#ifndef SMPPCANCELSM_HPP
#define SMPPCANCELSM_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPCancelSM  : public SMPPPDU, 
			public boost::enable_shared_from_this < SMPPCancelSM >{
		public:
			typedef boost::shared_ptr<SMPPCancelSM> SharedPtr;
		public:
			SMPPCancelSM(void);
			SMPPCancelSM(const unsigned nSequenceNumber);
			virtual ~SMPPCancelSM();
		public:
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

			inline void setDestAddrTON(const unsigned char);
			inline unsigned char& refDestAddrTON(void);
			inline const unsigned char getDestAddrTON(void) const;

			inline void setDestAddrNPI(const unsigned char);
			inline unsigned char& refDestAddrNPI(void);
			inline const unsigned char getDestAddrNPI(void) const;

			inline void setDestAddr(const std::string&);
			inline std::string& refDestAddr(void);
			inline const std::string& getDestAddr(void) const;

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
			unsigned char m_nDestAddrTON;
			unsigned char m_nDestAddrNPI;
			std::string m_sDestAddr;

			/**
			 * A present fields for optional AVP
			 *
			 */
		};
	}
}

// Include inline files
#include "SMPPCancelSM.inl"

#endif // SMPPCANCELSM_HPP
