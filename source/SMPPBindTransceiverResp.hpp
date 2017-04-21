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

#ifndef SMPPBINDTRANSCEIVERRESP_HPP
#define SMPPBINDTRANSCEIVERRESP_HPP

#include "SMPPBindResp.hpp"
#include "SMPPBindTransceiver.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPBindTransceiverResp  : public SMPPBindResp, 
			public boost::enable_shared_from_this < SMPPBindTransceiverResp >{
		public:
			typedef boost::shared_ptr<SMPPBindTransceiverResp> SharedPtr;
		public:
			SMPPBindTransceiverResp(void);
			SMPPBindTransceiverResp(const SMPPBindTransceiverResp&);
			SMPPBindTransceiverResp(const SMPPBindTransceiver&);
			SMPPBindTransceiverResp(const SMPPBindTransceiver&, const unsigned);
			SMPPBindTransceiverResp(const SMPPBindTransceiver::SharedPtr);
			SMPPBindTransceiverResp(const SMPPBindTransceiver::SharedPtr, const unsigned);
			virtual ~SMPPBindTransceiverResp();

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
#include "SMPPBindTransceiverResp.inl"

#endif // SMPPBINDTRANSCEIVERRESP_HPP
