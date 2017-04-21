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

#ifndef SMPPBINDTRANSCEIVER_HPP
#define SMPPBINDTRANSCEIVER_HPP

#include "SMPPBind.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPBindTransceiver  : public SMPPBind, 
			public boost::enable_shared_from_this < SMPPBindTransceiver >{
		public:
			typedef boost::shared_ptr<SMPPBindTransceiver> SharedPtr;
		public:
			SMPPBindTransceiver(void);
			SMPPBindTransceiver(const unsigned nSequenceNumber);
			virtual ~SMPPBindTransceiver();

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
#include "SMPPBindTransceiver.inl"

#endif // SMPPBINDTRANSCEIVER_HPP
