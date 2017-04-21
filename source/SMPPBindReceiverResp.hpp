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

#ifndef SMPPBINDRECEIVERRESP_HPP
#define SMPPBINDRECEIVERRESP_HPP

#include "SMPPBindResp.hpp"
#include "SMPPBindReceiver.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPBindReceiverResp  : public SMPPBindResp, 
			public boost::enable_shared_from_this < SMPPBindReceiverResp >{
		public:
			typedef boost::shared_ptr<SMPPBindReceiverResp> SharedPtr;
		public:
			SMPPBindReceiverResp(void);
			SMPPBindReceiverResp(const SMPPBindReceiverResp&);
			SMPPBindReceiverResp(const SMPPBindReceiver&);
			SMPPBindReceiverResp(const SMPPBindReceiver&, const unsigned nCommandStatus);
			SMPPBindReceiverResp(const SMPPBindReceiver::SharedPtr);
			SMPPBindReceiverResp(const SMPPBindReceiver::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPBindReceiverResp();

		protected:
			/**
			 * Coding and encoding interface
			 */
			virtual SMPPPDU* cloneSMPPPDU(void);
			virtual void fireOnReceived(SMPPSession*);
		};
	}
}

// Include inline files
#include "SMPPBindReceiverResp.inl"

#endif // SMPPBINDRECEIVERRESP_HPP
