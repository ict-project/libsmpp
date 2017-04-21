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

#ifndef SMPPPDU_HPP
#define SMPPPDU_HPP

#include "ISMPPOutputter.hpp"
#include "SMPPStructures.hpp"
#include "SMPPDatatypes.hpp"

namespace anthill {
	namespace smpp {

		class SMPPSession;
		class SMPPEncoder;
		class SMPPDecoder;
		class SMPPValidator;

		/**
		 * A SMPP client 
		 *
		 *
		 */
		class ANTHILLSMPP_DLLPRFX SMPPPDU {
		public:
			typedef boost::shared_ptr<SMPPPDU> SharedPtr;

			friend class SMPPEncoder;
			friend class SMPPDecoder;
			friend class SMPPSession;

		public:
			SMPPPDU(const unsigned nCommandId);
			SMPPPDU(const unsigned nCommandId, const unsigned nSequenceNumber);
			SMPPPDU(const unsigned nCommandId, const unsigned nSequenceNumber, const unsigned nCommandStatus);
			SMPPPDU(const SMPPPDU&);
			virtual ~SMPPPDU();
		public:
			inline void setHeader(const Header oHeader);
			inline Header& refHeader(void);
			inline const Header& getHeader(void) const;

			inline void setCommandLength(const unsigned nCommandLength);
			inline unsigned& refCommandLength(void);
			inline const unsigned getCommandLength(void) const;

			inline void setCommandId(const unsigned nCommandId);
			inline unsigned& refCommandId(void);
			inline const unsigned getCommandId(void) const;

			inline void setCommandStatus(const unsigned nCommandStatus);
			inline unsigned& refCommandStatus(void);
			inline const unsigned getCommandStatus(void) const;

			inline void setSequenceNumber(const unsigned nCommandStatus);
			inline unsigned& refSequenceNumber(void);
			inline const unsigned getSequenceNumber(void) const;

		public:
			/**
			 * Coding and encoding interface
			 */
			virtual void encodePacket(SMPPEncoder* poEncoder)=0;
			virtual void decodePacket(SMPPDecoder* poDecoder)=0;
			virtual void outputPacket(ISMPPOutputter* poOutputter)=0;
			virtual void validatePacket(SMPPValidator* poValidator)=0;

		protected:
			/**
			 * Validation methods
			 */
			void validateVersion(void);

		protected:
			/**
			 * Coding and encoding interface
			 */
			virtual SMPPPDU* cloneSMPPPDU(void)=0;
			virtual void fireOnReceived(SMPPSession*)=0;

		protected:
			Header m_oHeader;

		};
	}
}

// Include inline files
#include "SMPPPDU.inl"

#endif // SMPPPDU_HPP
