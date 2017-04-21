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

#ifndef SMPPCANCELSMRESPRESP_HPP
#define SMPPCANCELSMRESPRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPCancelSM.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPCancelSMResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPCancelSMResp >{
		public:
			typedef boost::shared_ptr<SMPPCancelSMResp> SharedPtr;
		public:
			SMPPCancelSMResp(void);
			SMPPCancelSMResp(const SMPPCancelSMResp&);
			SMPPCancelSMResp(const SMPPCancelSM&);
			SMPPCancelSMResp(const SMPPCancelSM&, const unsigned nCommandStatus);
			SMPPCancelSMResp(const SMPPCancelSM::SharedPtr);
			SMPPCancelSMResp(const SMPPCancelSM::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPCancelSMResp();

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
#include "SMPPCancelSMResp.inl"

#endif // SMPPCANCELSMRESPRESP_HPP
