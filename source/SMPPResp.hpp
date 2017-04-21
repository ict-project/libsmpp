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

#ifndef SMPPRESP_HPP
#define SMPPRESP_HPP

#include "SMPPPDU.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPResp  : public SMPPPDU{
		public:
			typedef boost::shared_ptr<SMPPResp> SharedPtr;
		public:
			SMPPResp(const unsigned nCommandId);
			SMPPResp(const unsigned nCommandId, const unsigned nSequenceNumber);
			SMPPResp(const unsigned nCommandId, const unsigned nSequenceNumber, const unsigned nCommandStatus);
			SMPPResp(const SMPPResp&);
			virtual ~SMPPResp();

		public:
			virtual void encodePacket(SMPPEncoder* poEncoder) = 0;
			virtual void decodePacket(SMPPDecoder* poDecoder) = 0;
			virtual void outputPacket(ISMPPOutputter* poOutputter) = 0;
			virtual void validatePacket(SMPPValidator* poValidator) = 0;


		protected:
			/**
			 * Coding and encoding interfaceN
			 */
			virtual SMPPPDU* cloneSMPPPDU(void)=0;
		protected:
		};
	}
}

// Include inline files
#include "SMPPResp.inl"

#endif // SMPPRESP_HPP
