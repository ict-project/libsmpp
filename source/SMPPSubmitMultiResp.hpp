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

#ifndef SMPPSUBMITMULTRESP_HPP
#define SMPPSUBMITMULTRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPSubmitMulti.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPSubmitMultiResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPSubmitMultiResp >{
		public:
			typedef boost::shared_ptr<SMPPSubmitMultiResp> SharedPtr;
		public:
			SMPPSubmitMultiResp(void);
			SMPPSubmitMultiResp(const SMPPSubmitMultiResp&);
			SMPPSubmitMultiResp(const SMPPSubmitMulti&);
			SMPPSubmitMultiResp(const SMPPSubmitMulti&, const unsigned nCommandStatus);
			SMPPSubmitMultiResp(const SMPPSubmitMulti::SharedPtr);
			SMPPSubmitMultiResp(const SMPPSubmitMulti::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPSubmitMultiResp();
		public:
			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

			inline void setNoUnsuccess(const unsigned char);
			inline unsigned char& refNoUnsuccess(void);
			inline const unsigned char getNoUnsuccess(void) const;

			inline void addUnsuccessSME(const SMEAddress&, const unsigned);
			inline void addUnsuccessSME(const unsigned char, const char, const std::string&, const unsigned);
			inline void setUnsuccessSMEs(const std::vector<UnsuccessSME>&);
			inline std::vector<UnsuccessSME>& refUnsuccessSMEs(void);
			inline const std::vector<UnsuccessSME>& getUnsuccessSMEs(void) const;

		public:
			/**
			 * Setters and getters for optional fields
			 */


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
			std::string m_sMessageId;
			unsigned char m_nNoUnsuccess;
			std::vector<UnsuccessSME>  m_aUnsuccessSMEs;
		};
	}
}

// Include inline files
#include "SMPPSubmitMultiResp.inl"

#endif // SMPPSUBMITMULTRESP_HPP
