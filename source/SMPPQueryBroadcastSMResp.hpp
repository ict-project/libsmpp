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

#ifndef SMPPQUERYBROADCASTSMRESP_HPP
#define SMPPQUERYBROADCASTSMRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPQueryBroadcastSM.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPQueryBroadcastSMResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPQueryBroadcastSMResp >{
		public:
			typedef boost::shared_ptr<SMPPQueryBroadcastSMResp> SharedPtr;
		public:
			SMPPQueryBroadcastSMResp(void);
			SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSMResp&);
			SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSM&);
			SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSM&, const unsigned nCommandStatus);
			SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSM::SharedPtr);
			SMPPQueryBroadcastSMResp(const SMPPQueryBroadcastSM::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPQueryBroadcastSMResp();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentMessageState(void) const;
			inline void omitPresentMessageState(void);
			inline void setPresentMessageState(const bool);

			inline const bool isPresentBroadcastAreaIdentifier(void) const;
			inline void omitPresentBroadcastAreaIdentifier(void);
			inline void setPresentBroadcastAreaIdentifier(const bool);

			inline const bool isPresentBroadcastAreaSuccess(void) const;
			inline void omitPresentBroadcastAreaSuccess(void);
			inline void setPresentBroadcastAreaSuccess(const bool);

			inline const bool isPresentBroadcastEndTime(void) const;
			inline void omitPresentBroadcastEndTime(void);
			inline void setPresentBroadcastEndTime(const bool);

			inline const bool isPresentUserMessageReference(void) const;
			inline void omitPresentUserMessageReference(void);
			inline void setPresentUserMessageReference(const bool);

			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

			inline void setMessageState(const unsigned char);
			inline unsigned char& refMessageState(void);
			inline const unsigned char getMessageState(void) const;

			inline void addBroadcastAreaIdentifier(const std::vector<unsigned char>&);
			inline void addBroadcastAreaIdentifier(const BroadcastAreaIdentifier&);
			inline void setBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>&);
			inline std::vector<BroadcastAreaIdentifier>& refBroadcastAreaIdentifier(void);
			inline const std::vector<BroadcastAreaIdentifier>& getBroadcastAreaIdentifier(void) const;

			inline void setBroadcastAreaSuccess(const unsigned char);
			inline unsigned char& refBroadcastAreaSuccess(void);
			inline const unsigned char getBroadcastAreaSuccess(void) const;


			inline void setUserMessageReference(const unsigned short);
			inline unsigned short& refUserMessageReference(void);
			inline const unsigned short getUserMessageReference(void) const;

			inline void setBroadcastEndTime(const std::string&);
			inline std::string& refBroadcastEndTime(void);
			inline const std::string& getBroadcastEndTime(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setMessageStateLen(const unsigned short);
			inline unsigned short& refMessageStateLen(void);
			inline const unsigned short getMessageStateLen(void) const;

			inline void addBroadcastAreaIdentifierLen(const unsigned short);
			inline void setBroadcastAreaIdentifierLen(const std::vector<unsigned short>&);
			inline std::vector<unsigned short>& refBroadcastAreaIdentifierLen(void);
			inline const std::vector<unsigned short>& getBroadcastAreaIdentifierLen(void) const;

			inline void setBroadcastAreaSuccessLen(const unsigned short);
			inline unsigned short& refBroadcastAreaSuccessLen(void);
			inline const unsigned short getBroadcastAreaSuccessLen(void) const;

			inline void setUserMessageReferenceLen(const unsigned short);
			inline unsigned short& refUserMessageReferenceLen(void);
			inline const unsigned short getUserMessageReferenceLen(void) const;

			inline void setBroadcastEndTimeLen(const unsigned short);
			inline unsigned short& refBroadcastEndTimeLen(void);
			inline const unsigned short getBroadcastEndTimeLen(void) const;
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
			unsigned char m_nMessageState;
			std::vector<BroadcastAreaIdentifier> m_aBroadcastAreaIdentifier;
			unsigned char m_nBroadcastAreaSuccess;
			/**
			 * A optional fields
			 *
			 */
			unsigned short m_nUserMessageReference;
			std::string m_sBroadcastEndTime;

			/**
			 * A present fields for optional AVP
			 *
			 */
			bool m_bPresentMessageState;
			bool m_bPresentBroadcastAreaIdentifier;
			bool m_bPresentBroadcastAreaSuccess;
			bool m_bPresentUserMessageReference;
			bool m_bPresentBroadcastEndTime;

			/**
			 * A optional fields
			 *
			 */
			unsigned short m_nMessageStateLen;
			std::vector<unsigned short> m_aBroadcastAreaIdentifierLen;
			unsigned short m_nBroadcastAreaSuccessLen;
			unsigned short m_nUserMessageReferenceLen;
			unsigned short m_nBroadcastEndTimeLen;


		};
	}
}

// Include inline files
#include "SMPPQueryBroadcastSMResp.inl"

#endif // SMPPQUERYBROADCASTSMRESP_HPP
