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

#ifndef SMPPBINDRESP_HPP
#define SMPPBINDRESP_HPP

#include "SMPPResp.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPBindResp  : public SMPPResp{
		public:
			typedef boost::shared_ptr<SMPPBindResp> SharedPtr;
		public:
			SMPPBindResp(const unsigned nCommandId);
			SMPPBindResp(const unsigned nCommandId, const unsigned nSequenceNumber);
			SMPPBindResp(const unsigned nCommandId, const unsigned nSequenceNumber, const unsigned nCommandStatus);
			SMPPBindResp(const SMPPBindResp&);
			virtual ~SMPPBindResp();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentScInterfaceVersion(void) const;
			inline void omitPresentScInterfaceVersion(void);
			inline void setPresentScInterfaceVersion(const bool);

			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setSystemId(const std::string&);
			inline std::string& refSystemId(void);
			inline const std::string& getSystemId(void) const;

			inline void setScInterfaceVersion(const unsigned char);
			inline unsigned char& refScInterfaceVersion(void);
			inline const unsigned char getScInterfaceVersion(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setScInterfaceVersionLen(const unsigned short);
			inline unsigned short& refScInterfaceVersionLen(void);
			inline const unsigned short getScInterfaceVersionLen(void) const;


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
			 * A specific AVP for answer
			 *
			 */
			std::string m_sSystemId;
			unsigned char m_nScInterfaceVersion;

			/**
			 * A present fields for optional AVP
			 *
			 */
			bool m_bPresentScInterfaceVersion;
			/**
			 * A present fields for optional AVP
			 *
			 */
			unsigned short m_nScInterfaceVersionLen;
		};
	}
}

// Include inline files
#include "SMPPBindResp.inl"

#endif // SMPPBINDRESP_HPP
