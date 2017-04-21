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

#ifndef SMPPALERTNOTIFICATION_HPP
#define SMPPALERTNOTIFICATION_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPAlertNotification  : public SMPPPDU, 
			public boost::enable_shared_from_this < SMPPAlertNotification >{
		public:
			typedef boost::shared_ptr<SMPPAlertNotification> SharedPtr;
		public:
			SMPPAlertNotification(void);
			SMPPAlertNotification(const unsigned nSequenceNumber);
			virtual ~SMPPAlertNotification();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentMSAvailabilityStatus(void) const;
			inline void omitPresentMSAvailabilityStatus(void);
			inline void setPresentMSAvailabilityStatus(const bool);

			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setSourceAddrTON(const unsigned char);
			inline unsigned char& refSourceAddrTON(void);
			inline const unsigned char getSourceAddrTON(void) const;

			inline void setSourceAddrNPI(const unsigned char);
			inline unsigned char& refSourceAddrNPI(void);
			inline const unsigned char getSourceAddrNPI(void) const;

			inline void setSourceAddr(const std::string&);
			inline std::string& refSourceAddr(void);
			inline const std::string& getSourceAddr(void) const;

			inline void setESMEAddrTON(const unsigned char);
			inline unsigned char& refESMEAddrTON(void);
			inline const unsigned char getESMEAddrTON(void) const;

			inline void setESMEAddrNPI(const unsigned char);
			inline unsigned char& refESMEAddrNPI(void);
			inline const unsigned char getESMEAddrNPI(void) const;

			inline void setESMEAddr(const std::string&);
			inline std::string& refESMEAddr(void);
			inline const std::string& getESMEAddr(void) const;

			inline void setMSAvailabilityStatus(const unsigned char);
			inline unsigned char& refMSAvailabilityStatus(void);
			inline const unsigned char getMSAvailabilityStatus(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setMSAvailabilityStatusLen(const unsigned short);
			inline unsigned short& refMSAvailabilityStatusLen(void);
			inline const unsigned short getMSAvailabilityStatusLen(void) const;


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
			unsigned char m_nSourceAddrTON;
			unsigned char m_nSourceAddrNPI;
			std::string m_sSourceAddr;
			unsigned char m_nESMEAddrTON;
			unsigned char m_nESMEAddrNPI;
			std::string m_sESMEAddr;
			/**
			 * A optional fields
			 *
			 */
			unsigned char m_nMSAvailabilityStatus;

			/**
			 * A present fields for optional AVP
			 *
			 */
			bool m_bPresentMSAvailabilityStatus;
			/**
			 * A 
			 *
			 */
			unsigned short m_nMSAvailabilityStatusLen;
		};
	}
}

// Include inline files
#include "SMPPAlertNotification.inl"

#endif // SMPPALERTNOTIFICATION_HPP
