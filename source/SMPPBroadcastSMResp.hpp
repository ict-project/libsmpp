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

#ifndef SMPPBROADCASTSMRESP_HPP
#define SMPPBROADCASTSMRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPBroadcastSM.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPBroadcastSMResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPBroadcastSMResp >{
		public:
			typedef boost::shared_ptr<SMPPBroadcastSMResp> SharedPtr;
		public:
			SMPPBroadcastSMResp(void);
			SMPPBroadcastSMResp(const SMPPBroadcastSMResp&);
			SMPPBroadcastSMResp(const SMPPBroadcastSM&);
			SMPPBroadcastSMResp(const SMPPBroadcastSM&, const unsigned nCommandStatus);
			SMPPBroadcastSMResp(const SMPPBroadcastSM::SharedPtr);
			SMPPBroadcastSMResp(const SMPPBroadcastSM::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPBroadcastSMResp();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentBroadcastErrorStatus(void) const;
			inline void omitPresentBroadcastErrorStatus(void);
			inline void setPresentBroadcastErrorStatus(const bool);

			inline const bool isPresentFailedBroadcastAreaIdentifier(void) const;
			inline void omitPresentFailedBroadcastAreaIdentifier(void);
			inline void setPresentFailedBroadcastAreaIdentifier(const bool);

			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

			inline void setBroadcastErrorStatus(const unsigned);
			inline unsigned& refBroadcastErrorStatus(void);
			inline const unsigned getBroadcastErrorStatus(void) const;

			inline void addFailedBroadcastAreaIdentifier(const std::vector<unsigned char>&);
			inline void addFailedBroadcastAreaIdentifier(const BroadcastAreaIdentifier&);
			inline void setFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&);
			inline std::vector<BroadcastAreaIdentifier>& refFailedBroadcastAreaIdentifier(void);
			inline const std::vector<BroadcastAreaIdentifier>& getFailedBroadcastAreaIdentifier(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setBroadcastErrorStatusLen(const unsigned short);
			inline unsigned short& refBroadcastErrorStatusLen(void);
			inline const unsigned short getBroadcastErrorStatusLen(void) const;

			inline void addFailedBroadcastAreaIdentifierLen(const unsigned short);
			inline void setFailedBroadcastAreaIdentifierLen(const std::vector<unsigned short>&);
			inline std::vector<unsigned short>& refFailedBroadcastAreaIdentifierLen(void);
			inline const std::vector<unsigned short>& getFailedBroadcastAreaIdentifierLen(void) const;


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
			 * A mandatory fields
			 *
			 */
			std::string m_sMessageId;
			/**
			 * A optional fields
			 *
			 */
			unsigned m_nBroadcastErrorStatus;
			std::vector<BroadcastAreaIdentifier> m_aFailedBroadcastAreaIdentifier;

			/**
			 * A present fields
			 *
			 */
			bool m_bPresentBroadcastErrorStatus;
			bool m_bPresentFailedBroadcastAreaIdentifier;
			/**
			 * A optional fields
			 *
			 */
			unsigned short m_nBroadcastErrorStatusLen;
			std::vector<unsigned short> m_aFailedBroadcastAreaIdentifierLen;


		};
	}
}

// Include inline files
#include "SMPPBroadcastSMResp.inl"

#endif // SMPPBROADCASTSMRESP_HPP
