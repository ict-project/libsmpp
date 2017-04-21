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

#ifndef SMPPUNBIND_HPP
#define SMPPUNBIND_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPUnbind  : public SMPPPDU, 
			public boost::enable_shared_from_this < SMPPUnbind >{
		public:
			typedef boost::shared_ptr<SMPPUnbind> SharedPtr;
		public:
			SMPPUnbind(void);
			SMPPUnbind(const unsigned nSequenceNumber);
			virtual ~SMPPUnbind();

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

			/**
			 * A present fields for optional AVP
			 *
			 */
		};
	}
}

// Include inline files
#include "SMPPUnbind.inl"

#endif // SMPPUNBIND_HPP
