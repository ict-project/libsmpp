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

#ifndef BINARYENCODER_HPP
#define BINARYENCODER_HPP

#include "EncoderBase.hpp"

namespace anthill {

	/**
	 * A base encoder
	 */
	class ANTHILL_DLLPRFX BinaryEncoder : public EncoderBase{
	public:
		BinaryEncoder(void);
		BinaryEncoder(const BinaryEncoder&);
		BinaryEncoder& operator=(const BinaryEncoder&);
		virtual ~BinaryEncoder();

	public:
		/**
		 * Padding functions to align
		 */
		inline void skipNBytes(const unsigned nBytes);
		inline void paddingNBytes(const unsigned nBytes);
		
		/**
		 * Encode functions
		 */
		inline void encodeChar(const char nValue);
		inline void encodeChar(const unsigned char nValue);
		inline void encodeInteger32(const int nValue);
		inline void encodeInteger24(const int nValue);
		inline void encodeInteger16(const short nValue);
		inline void encodeUnsigned32(const unsigned nValue);
		inline void encodeUnsigned16(const unsigned short nValue);
		inline void encodeCString(const std::string& sValue);
		inline void encodeCString(const std::string& sValue, const unsigned nLimit);
		inline void encodeBinary(const std::vector<unsigned char>& aValue);

	public:
		void resetBuffer(void);
		std::vector<unsigned char>& refBuffer(void);
		const std::vector<unsigned char>& getBuffer(void) const;
		void appendBuffer(const std::vector<unsigned char>& aBuffer);

	protected:
		unsigned m_nOffset;
		std::vector<unsigned char> m_aBuffer;

	};
}

// Include inline files
#include "BinaryEncoder.inl"

#endif // BINARYENCODER_HPP
