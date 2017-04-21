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

#ifndef SMPPSTRUCTURES_HPP
#define SMPPSTRUCTURES_HPP

namespace anthill {
	namespace smpp {

		/**
		 * A SMPP header
		 */
		class ANTHILLSMPP_DLLPRFX Header
		{
		public:
			Header();
			Header(const unsigned nCommandId);
			Header(const unsigned nCommandId, const unsigned nSequenceNumber);
			Header(const unsigned nCommandId, const unsigned nSequenceNumber, const unsigned nCommandStatus);
			virtual ~Header();
			const bool operator ==(const Header&) const;
		public:
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

		protected:
			unsigned nCommandLength;
			unsigned nCommandId;
			unsigned nCommandStatus;
			unsigned nSequenceNumber;
		};
		/**
		 * A base class for all AVPs
		 */
		class ANTHILLSMPP_DLLPRFX SMEAddress
		{
		public:
			SMEAddress(void);
			SMEAddress(const unsigned char nTON, const unsigned char nNPI, const std::string& sAddress);
			virtual ~SMEAddress();
			const bool operator ==(const SMEAddress&) const;
			const bool operator !=(const SMEAddress&) const;
		public:

			inline void setTON(const unsigned char nTON);
			inline unsigned char& refTON(void);
			inline const unsigned char getTON(void) const;

			inline void setNPI(const unsigned char nNPI);
			inline unsigned char& refNPI(void);
			inline const unsigned char getNPI(void) const;

			inline void setAddress(const std::string& sAddress);
			inline std::string& refAddress(void);
			inline const std::string& getAddress(void) const;

		protected:
			/**
			 * AVP header fields
			 */
			unsigned char nTON;
			unsigned char nNPI;
			std::string sAddress;
		};

		/**
		 * A base class for all AVPs
		 */
		class ANTHILLSMPP_DLLPRFX DestAddress
		{
		public:
			DestAddress(void);
			DestAddress(const SMEAddress& oAddress);
			DestAddress(const unsigned char nTON, const unsigned char nNPI, const std::string& sAddress);
			DestAddress(const std::string& sDistrListName);
			DestAddress(const unsigned char nDestFlag, const SMEAddress& oAddress, const std::string& sDistrListName);
			virtual ~DestAddress();
			const bool operator ==(const DestAddress&) const;
		public:
			inline void setDestFlag(const unsigned char nDestFlag);
			inline unsigned char& refDestFlag(void);
			inline const unsigned char getDestFlag(void) const;

			inline void setAddress(const SMEAddress& oAddress);
			inline SMEAddress& refAddress(void);
			inline const SMEAddress& getAddress(void) const;

			inline void setDistrListName(const std::string& sDistrListName);
			inline std::string& refDistrListName(void);
			inline const std::string& getDistrListName(void) const;

		protected:
			/**
			 * AVP header fields
			 */
			unsigned char nDestFlag;
			SMEAddress oAddress;
			std::string sDistrListName;

		};

		/**
		 * A base class for all AVPs
		 */
		class ANTHILLSMPP_DLLPRFX UnsuccessSME
		{
		public:
			UnsuccessSME(void);
			UnsuccessSME(const SMEAddress& oAddress, const unsigned nErrorStatusCode);
			UnsuccessSME(const unsigned char nTON, const unsigned char nNPI, const std::string& sAddress, unsigned nErrorStatusCode);
			virtual ~UnsuccessSME();
			const bool operator ==(const UnsuccessSME&) const;
		public:
			inline void setSMEAddress(const SMEAddress& oSMEAddress);
			inline SMEAddress& refSMEAddress(void);
			inline const SMEAddress& getSMEAddress(void) const;

			inline void setErrorStatusCode(const unsigned nErrorStatusCode);
			inline unsigned& refErrorStatusCode(void);
			inline const unsigned getErrorStatusCode(void) const;

		protected:
			/**
			 * AVP header fields
			 */
			SMEAddress oSMEAddress;
			unsigned nErrorStatusCode;

		};

		/**
		 * A base class for all AVPs
		 */
		class ANTHILLSMPP_DLLPRFX NetworkErrorCode
		{
		public:
			NetworkErrorCode(void);
			NetworkErrorCode(unsigned char nNetworkCode, int nErrorCode);
			virtual ~NetworkErrorCode();
			const bool operator ==(const NetworkErrorCode&) const;
		public:
			inline void setNetworkCode(const unsigned char nNetworkCode);
			inline unsigned char& refNetworkCode(void);
			inline const unsigned char getNetworkCode(void) const;

			inline void setErrorCode(const unsigned short nErrorCode);
			inline unsigned short& refErrorCode(void);
			inline const unsigned short getErrorCode(void) const;

		protected:
			/**
			 * AVP header fields
			 */
			unsigned char nNetworkCode;
			unsigned short nErrorCode;

		};
	}
}

// Include inline files
#include "SMPPStructures.inl"

#endif // SMPPSTRUCTURES_HPP
