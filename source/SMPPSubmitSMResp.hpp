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

#ifndef SMPPSUBMITSMRESP_HPP
#define SMPPSUBMITSMRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPSubmitSM.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPSubmitSMResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPSubmitSMResp >{
		public:
			typedef boost::shared_ptr<SMPPSubmitSMResp> SharedPtr;
		public:
			SMPPSubmitSMResp(void);
			SMPPSubmitSMResp(const SMPPSubmitSMResp&);
			SMPPSubmitSMResp(const SMPPSubmitSM&);
			SMPPSubmitSMResp(const SMPPSubmitSM&, const unsigned nCommandStatus);
			SMPPSubmitSMResp(const SMPPSubmitSM::SharedPtr);
			SMPPSubmitSMResp(const SMPPSubmitSM::SharedPtr, const unsigned nCommandStatus);

			virtual ~SMPPSubmitSMResp();

		public:
			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

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

		};
	}
}

// Include inline files
#include "SMPPSubmitSMResp.inl"

#endif // SMPPSUBMITSMRESP_HPP
