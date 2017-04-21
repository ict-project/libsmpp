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

#ifndef SMPPDATATYPES_HPP
#define SMPPDATATYPES_HPP


namespace anthill {
	namespace smpp {

		
		/**
		 * A smpp datatype
		 */
		class ANTHILLSMPP_DLLPRFX BroadcastAreaIdentifier
		{
		public:
			BroadcastAreaIdentifier(void);
			BroadcastAreaIdentifier(const std::vector<unsigned char>&);
			virtual ~BroadcastAreaIdentifier();
			const bool operator ==(const BroadcastAreaIdentifier&) const;
			const bool operator !=(const BroadcastAreaIdentifier&) const;
		public:
			inline const bool isAlias(void) const;
			inline const bool isEllipsoid(void) const;
			inline const bool isPolygon(void) const;
			inline const unsigned char getBroadcastAreaFormat(void) const;

			inline void setAlias(const std::vector<unsigned char>&);
			inline void setEllipsoid(const std::vector<unsigned char>&);
			inline void setPolygon(const std::vector<unsigned char>&);

			inline void setValue(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refValue(void);
			inline const std::vector<unsigned char>& getValue(void) const;

		public:
			std::vector<unsigned char> aValue;
		};


		/**
		 * A smpp datatype
		 */
		class ANTHILLSMPP_DLLPRFX SMPPDateTime
		{
		public:
			SMPPDateTime(void);
			SMPPDateTime(const std::vector<unsigned char>&);
			virtual ~SMPPDateTime();
			const bool operator ==(const SMPPDateTime&) const;
			const bool operator !=(const SMPPDateTime&) const;
		public:
			inline void setValue(const std::vector<unsigned char>&);
			inline std::vector<unsigned char>& refValue(void);
			inline const std::vector<unsigned char>& getValue(void) const;

		public:
			std::vector<unsigned char> aValue;
		};


	}
}

// Include inline files
#include "SMPPDatatypes.inl"

#endif // SMPPDATATYPES_HPP
