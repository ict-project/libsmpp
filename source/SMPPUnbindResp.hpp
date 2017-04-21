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

#ifndef SMPPUNBINDRESP_HPP
#define SMPPUNBINDRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPUnbind.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPUnbindResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPUnbindResp >{
		public:
			typedef boost::shared_ptr<SMPPUnbindResp> SharedPtr;
		public:
			SMPPUnbindResp(void);
			SMPPUnbindResp(const SMPPUnbindResp&);
			SMPPUnbindResp(const SMPPUnbind&);
			SMPPUnbindResp(const SMPPUnbind&, const unsigned nCommandStatus);
			SMPPUnbindResp(const SMPPUnbind::SharedPtr);
			SMPPUnbindResp(const SMPPUnbind::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPUnbindResp();
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
		};
	}
}

// Include inline files
#include "SMPPUnbindResp.inl"

#endif // SMPPUNBINDRESP_HPP
