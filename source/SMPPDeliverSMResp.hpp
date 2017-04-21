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

#ifndef SMPPDELIVERSMRESPRESP_HPP
#define SMPPDELIVERSMRESPRESP_HPP

#include "SMPPResp.hpp"
#include "SMPPDeliverSM.hpp"

namespace anthill {
	namespace smpp {
		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPDeliverSMResp  : public SMPPResp, 
			public boost::enable_shared_from_this < SMPPDeliverSMResp >{
		public:
			typedef boost::shared_ptr<SMPPDeliverSMResp> SharedPtr;
		public:
			SMPPDeliverSMResp(void);
			SMPPDeliverSMResp(const SMPPDeliverSMResp&);
			SMPPDeliverSMResp(const SMPPDeliverSM&);
			SMPPDeliverSMResp(const SMPPDeliverSM&, const unsigned nCommandStatus);
			SMPPDeliverSMResp(const SMPPDeliverSM::SharedPtr);
			SMPPDeliverSMResp(const SMPPDeliverSM::SharedPtr, const unsigned nCommandStatus);
			virtual ~SMPPDeliverSMResp();
		public:
			/**
			 * Setters and getters for optional fields
			 */
			inline const bool isPresentAdditionalStatusInfoText(void) const;
			inline void omitPresentAdditionalStatusInfoText(void);
			inline void setPresentAdditionalStatusInfoText(const bool);

			inline const bool isPresentDeliveryFailureReason(void) const;
			inline void omitPresentDeliveryFailureReason(void);
			inline void setPresentDeliveryFailureReason(const bool);

			inline const bool isPresentNetworkErrorCode(void) const;
			inline void omitPresentNetworkErrorCode(void);
			inline void setPresentNetworkErrorCode(const bool);
			/**
			 * Setters and getters for mandatory fields
			 */
			inline void setMessageId(const std::string&);
			inline std::string& refMessageId(void);
			inline const std::string& getMessageId(void) const;

			/**
			 * Setters and getters for optional fields
			 */
			inline void setAdditionalStatusInfoText(const std::vector<unsigned char>&);
			inline void setAdditionalStatusInfoText(const std::string&);
			inline std::vector<unsigned char>& refAdditionalStatusInfoText(void);
			inline const std::vector<unsigned char>& getAdditionalStatusInfoText(void) const;

			inline void setDeliveryFailureReason(const unsigned char);
			inline unsigned char& refDeliveryFailureReason(void);
			inline const unsigned char getDeliveryFailureReason(void) const;

			inline void setNetworkErrorCode(const unsigned char nNetworkCode, const unsigned short nErrorCode);
			inline void setNetworkErrorCode(const NetworkErrorCode&);
			inline NetworkErrorCode& refNetworkErrorCode(void);
			inline const NetworkErrorCode& getNetworkErrorCode(void) const;

			/**
			 * Setters and getters for len fields
			 */
			inline void setAdditionalStatusInfoTextLen(const unsigned short);
			inline unsigned short& refAdditionalStatusInfoTextLen(void);
			inline const unsigned short getAdditionalStatusInfoTextLen(void) const;

			inline void setDeliveryFailureReasonLen(const unsigned short);
			inline unsigned short& refDeliveryFailureReasonLen(void);
			inline const unsigned short getDeliveryFailureReasonLen(void) const;

			inline void setNetworkErrorCodeLen(const unsigned short);
			inline unsigned short& refNetworkErrorCodeLen(void);
			inline const unsigned short getNetworkErrorCodeLen(void) const;

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
			std::vector<unsigned char> m_aAdditionalStatusInfoText;
			unsigned char m_nDeliveryFailureReason;
			NetworkErrorCode m_oNetworkErrorCode;

			/**
			 * A present fields for optional AVP
			 *
			 */
			bool m_bPresentAdditionalStatusInfoText;
			bool m_bPresentDeliveryFailureReason;		
			bool m_bPresentNetworkErrorCode;

			/**
			 * A optinal fields
			 *
			 */
			unsigned short m_nAdditionalStatusInfoTextLen;
			unsigned short m_nDeliveryFailureReasonLen;
			unsigned short m_nNetworkErrorCodeLen;


		};
	}
}

// Include inline files
#include "SMPPDeliverSMResp.inl"

#endif // SMPPDELIVERSMRESPRESP_HPP
