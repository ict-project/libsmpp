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

#ifndef BINARYDECODER_HPP
#define BINARYDECODER_HPP

#include "DecoderBase.hpp"

namespace anthill {


	/**
	 * A base decoder
	 */
	class ANTHILL_DLLPRFX BinaryDecoder : public DecoderBase{
	public:
		BinaryDecoder(void);
		BinaryDecoder(const BinaryDecoder&);
		BinaryDecoder& operator=(const BinaryDecoder&);
		virtual ~BinaryDecoder();
	public:
		/**
		 * Padding functions to align
		 */
		inline void skipNBytes(const unsigned nBytes);
		inline void paddingNBytes(const unsigned nBytes);
		
		/**
		 * Decode functions
		 */
		inline void decodeChar(char& nValue);
		inline void decodeChar(unsigned char& nValue);
		inline void decodeInteger32(int& nValue);
		inline void decodeInteger24(int& nValue);
		inline void decodeInteger16(short& nValue);
		inline void decodeUnsigned32(unsigned& nValue);
		inline void decodeUnsigned16(unsigned short& nValue);
		inline void decodeCString(std::string& sValue);
		inline void decodeCStringMax(std::string& sValue, const unsigned nMaxlen);
		inline void decodeBinary(std::vector<unsigned char>& aValue, unsigned nSize);

		/**
		 * Padding functions to align with limitation
		 */
		inline void skipNBytes(const unsigned nBytes, const unsigned nLimit);
		inline void paddingNBytes(const unsigned nBytes, const unsigned nLimit);

		/**
		 * Decode functions with limitation
		 */
		inline void decodeChar(char& nValue, const unsigned nLimit);
		inline void decodeChar(unsigned char& nValue, const unsigned nLimit);
		inline void decodeInteger32(int& nValue, const unsigned nLimit);
		inline void decodeInteger24(int& nValue, const unsigned nLimit);
		inline void decodeInteger16(short& nValue, const unsigned nLimit);
		inline void decodeUnsigned32(unsigned& nValue, const unsigned nLimit);
		inline void decodeUnsigned16(unsigned short& nValue, const unsigned nLimit);
		inline void decodeCString(std::string& sValue, const unsigned nLimit);
		inline void decodeCStringMax(std::string& sValue, const unsigned nMaxlen, const unsigned nLimit);
		inline void decodeBinary(std::vector<unsigned char>& aValue, unsigned nSize, const unsigned nLimit);


	public:
		void resetBuffer(void);	
		std::vector<unsigned char>& refBuffer(void);
		const std::vector<unsigned char>& getBuffer(void) const;
		void appendBuffer(const std::vector<unsigned char>& aBuffer);
		void validateOffset(const unsigned nLength);
		

	protected:
		unsigned m_nOffset;
		std::vector<unsigned char> m_aBuffer;
	};
}

// Include inline files
#include "BinaryDecoder.inl"

#endif // BINARYDECODER_HPP
