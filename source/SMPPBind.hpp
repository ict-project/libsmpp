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

#ifndef SMPPBIND_HPP
#define SMPPBIND_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPBind  : public SMPPPDU{
		public:
			typedef boost::shared_ptr<SMPPBind> SharedPtr;
		public:
			SMPPBind(const unsigned nCommandId);
			SMPPBind(const unsigned nCommandId, const unsigned nSequenceNumber);
			virtual ~SMPPBind();
		public:

			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setSystemId(const std::string&);
			inline std::string& refSystemId(void);
			inline const std::string& getSystemId(void) const;

			inline void setPassword(const std::string&);
			inline std::string& refPassword(void);
			inline const std::string& getPassword(void) const;

			inline void setSystemType(const std::string&);
			inline std::string& refSystemType(void);
			inline const std::string& getSystemType(void) const;

			inline void setInterfaceVersion(const unsigned char);
			inline unsigned char& refInterfaceVersion(void);
			inline const unsigned char getInterfaceVersion(void) const;

			inline void setAddrTON(const unsigned char);
			inline unsigned char& refAddrTON(void);
			inline const unsigned char getAddrTON(void) const;

			inline void setAddrNPI(const unsigned char);
			inline unsigned char& refAddrNPI(void);
			inline const unsigned char getAddrNPI(void) const;

			inline void setAddressRange(const std::string&);
			inline std::string& refAddressRange(void);
			inline const std::string& getAddressRange(void) const;

		public:
			virtual void encodePacket(SMPPEncoder* poEncoder);
			virtual void decodePacket(SMPPDecoder* poDecoder);
			virtual void outputPacket(ISMPPOutputter* poOutputter);
			virtual void validatePacket(SMPPValidator* poValidator);
		protected:
			/**
			 * Coding and encoding interface
			 */
			virtual SMPPPDU* cloneSMPPPDU(void)=0;
			virtual void fireOnReceived(SMPPSession*)=0;
		protected:
			/**
			 * A specific AVP for request
			 */
			std::string m_sSystemId;
			std::string m_sPassword;
			std::string m_sSystemType;
			unsigned char m_nInterfaceVersion;
			unsigned char m_nAddrTON;
			unsigned char m_nAddrNPI;
			std::string m_sAddressRange;

			/**
			 * A present fields for optional AVP
			 *
			 */
		};
	}
}

// Include inline files
#include "SMPPBind.inl"

#endif // SMPPBIND_HPP
