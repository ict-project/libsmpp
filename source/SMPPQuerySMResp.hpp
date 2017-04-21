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

#ifndef SMPPQUERYSMRESP_HPP
#define SMPPQUERYSMRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPQuerySM.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPQuerySMResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPQuerySMResp >{
		public:
			typedef boost::shared_ptr<SMPPQuerySMResp> SharedPtr;
		public:
			SMPPQuerySMResp(void);
			SMPPQuerySMResp(const SMPPQuerySMResp&);
			SMPPQuerySMResp(const SMPPQuerySM&);
			SMPPQuerySMResp(const SMPPQuerySM&, const unsigned nCommandStatus);
			SMPPQuerySMResp(const SMPPQuerySM::SharedPtr);
			SMPPQuerySMResp(const SMPPQuerySM::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPQuerySMResp();
		public:
			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

			inline void setFinalDate(const std::string&);
			inline std::string& refFinalDate(void);
			inline const std::string& getFinalDate(void) const;

			inline void setMessageState(const unsigned char);
			inline unsigned char& refMessageState(void);
			inline const unsigned char getMessageState(void) const;

			inline void setErrorCode(const unsigned char);
			inline unsigned char& refErrorCode(void);
			inline const unsigned char getErrorCode(void) const;

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
			std::string m_sMessageId;
			std::string m_sFinalDate;
			unsigned char m_nMessageState;
			unsigned char m_nErrorCode;
		};
	}
}

// Include inline files
#include "SMPPQuerySMResp.inl"

#endif // SMPPQUERYSMRESP_HPP
