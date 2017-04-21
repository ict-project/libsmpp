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

#ifndef SMPPDATASMRESP_HPP
#define SMPPDATASMRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPDataSM.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPDataSMResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPDataSMResp >{
		public:
			typedef boost::shared_ptr<SMPPDataSMResp> SharedPtr;
		public:
			SMPPDataSMResp(void);
			SMPPDataSMResp(const SMPPDataSMResp&);
			SMPPDataSMResp(const SMPPDataSM&);
			SMPPDataSMResp(const SMPPDataSM&, const unsigned nCommandStatus);
			SMPPDataSMResp(const SMPPDataSM::SharedPtr);
			SMPPDataSMResp(const SMPPDataSM::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPDataSMResp();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentDeliveryFailureReason(void) const;
			inline void omitPresentDeliveryFailureReason(void);
			inline void setPresentDeliveryFailureReason(const bool);

			inline const bool isPresentNetworkErrorCode(void) const;
			inline void omitPresentNetworkErrorCode(void);
			inline void setPresentNetworkErrorCode(const bool);

			inline const bool isPresentAdditionalStatusInfoText(void) const;
			inline void omitPresentAdditionalStatusInfoText(void);
			inline void setPresentAdditionalStatusInfoText(const bool);

			inline const bool isPresentDpfResult(void) const;
			inline void omitPresentDpfResult(void);
			inline void setPresentDpfResult(const bool);

			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

			inline void setDeliveryFailureReason(const unsigned char);
			inline unsigned char& refDeliveryFailureReason(void);
			inline const unsigned char getDeliveryFailureReason(void) const;

			inline void setNetworkErrorCode(const unsigned char nNetworkCode, const unsigned short nErrorCode);
			inline void setNetworkErrorCode(const NetworkErrorCode&);
			inline NetworkErrorCode& refNetworkErrorCode(void);
			inline const NetworkErrorCode& getNetworkErrorCode(void) const;

			inline void setAdditionalStatusInfoText(const std::vector<unsigned char>&);
			inline void setAdditionalStatusInfoText(const std::string&);
			inline std::vector<unsigned char>& refAdditionalStatusInfoText(void);
			inline const std::vector<unsigned char>& getAdditionalStatusInfoText(void) const;

			inline void setDpfResult(const unsigned char);
			inline unsigned char& refDpfResult(void);
			inline const unsigned char getDpfResult(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setDeliveryFailureReasonLen(const unsigned short);
			inline unsigned short& refDeliveryFailureReasonLen(void);
			inline const unsigned short getDeliveryFailureReasonLen(void) const;

			inline void setNetworkErrorCodeLen(const unsigned short);
			inline unsigned short& refNetworkErrorCodeLen(void);
			inline const unsigned short getNetworkErrorCodeLen(void) const;

			inline void setAdditionalStatusInfoTextLen(const unsigned short);
			inline unsigned short& refAdditionalStatusInfoTextLen(void);
			inline const unsigned short getAdditionalStatusInfoTextLen(void) const;

			inline void setDpfResultLen(const unsigned short);
			inline unsigned short& refDpfResultLen(void);
			inline const unsigned short getDpfResultLen(void) const;

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
			 * A optinal fields
			 *
			 */
			unsigned char m_nDeliveryFailureReason;
			NetworkErrorCode m_oNetworkErrorCode;
			std::vector<unsigned char> m_aAdditionalStatusInfoText;
			unsigned char m_nDpfResult;

			/**
			 * A present fields for optional AVP
			 *
			 */
			bool m_bPresentDeliveryFailureReason;		
			bool m_bPresentNetworkErrorCode;
			bool m_bPresentAdditionalStatusInfoText;
			bool m_bPresentDpfResult;

			/**
			 * A optinal fields
			 *
			 */
			unsigned short m_nDeliveryFailureReasonLen;
			unsigned short m_nNetworkErrorCodeLen;
			unsigned short m_nAdditionalStatusInfoTextLen;
			unsigned short m_nDpfResultLen;


		};
	}
}

// Include inline files
#include "SMPPDataSMResp.inl"

#endif // SMPPDATASMRESP_HPP
