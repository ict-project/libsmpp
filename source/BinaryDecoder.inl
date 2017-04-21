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


namespace anthill {


	inline void BinaryDecoder::skipNBytes(const unsigned nBytes){
		if(nBytes == 0) return;
		if (m_nOffset <= (m_aBuffer.size() - nBytes)){
			m_nOffset += nBytes;
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_SKIPPING)%m_nOffset).str());
		}
			
	}

	inline void BinaryDecoder::paddingNBytes(const unsigned nBytes){
		if(nBytes == 0) return;
		unsigned nShift = nBytes - m_nOffset%nBytes;
		nShift = (nShift == nBytes ? 0 : nShift);
		if(nShift == 0) return;


		if (m_nOffset <= (m_aBuffer.size() - nShift)){
			m_nOffset += nShift;
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_PADDING)%m_nOffset).str());
		}
			
	}

	inline void BinaryDecoder::decodeChar(char& nValue){
		const unsigned int nSizeof = 1;
		memset(&nValue, 0, sizeof(nValue));
		if (m_nOffset <= (m_aBuffer.size() - nSizeof))
		{
			nValue = m_aBuffer[m_nOffset];
			m_nOffset++;
		}
		else
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_CHAR)%m_nOffset).str());
	}

	inline void BinaryDecoder::decodeChar(unsigned char& nValue){
		const unsigned int nSizeof = 1;
		memset(&nValue, 0, sizeof(nValue));
		if (m_nOffset <= (m_aBuffer.size() - nSizeof))
		{
			nValue = m_aBuffer[m_nOffset];
			m_nOffset++;
		}
		else
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_UNSIGNED_CHAR)%m_nOffset).str());
	}

	inline void BinaryDecoder::decodeInteger32(int& nValue){
		const unsigned int nSizeof = 4;
		memset(&nValue, 0, sizeof(nValue));
		if (m_nOffset <= (m_aBuffer.size() - nSizeof))
		{
			memcpy(&nValue, &m_aBuffer[m_nOffset], nSizeof);
			nValue = ntohl(nValue);
			m_nOffset += nSizeof;
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_INTEGER32)%m_nOffset).str());
		}
	}

	inline void BinaryDecoder::decodeInteger16(short& nValue){
		assert(false);
	}


	inline void BinaryDecoder::decodeInteger24(int& nValue){
		const unsigned int nSizeof = 3;
		memset(&nValue, 0, sizeof(nValue));
		if (m_nOffset <= (m_aBuffer.size() - nSizeof))
		{
			memcpy(((char*)&nValue) + sizeof(char), &m_aBuffer[m_nOffset],nSizeof);
			nValue = ntohl(nValue);
			m_nOffset += nSizeof;
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_INTEGER24)%m_nOffset).str());
		}
	}

	inline void BinaryDecoder::decodeUnsigned32(unsigned& nValue){
		const unsigned int nSizeof = 4;
		memset(&nValue, 0, sizeof(nValue));
		if (m_nOffset <= (m_aBuffer.size() - nSizeof))
		{
			memcpy(&nValue, &m_aBuffer[m_nOffset],nSizeof);
			nValue = ntohl(nValue);
			m_nOffset += nSizeof;
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_UNSIGNED32)%m_nOffset).str());
		}
	}

	inline void BinaryDecoder::decodeUnsigned16(unsigned short& nValue){
		const unsigned int nSizeof = 2;
		memset(&nValue, 0, sizeof(nValue));
		if (m_nOffset <= (m_aBuffer.size() - nSizeof))
		{
			memcpy(&nValue, &m_aBuffer[m_nOffset],nSizeof);
			nValue = ntohs(nValue);
			m_nOffset += nSizeof;
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_UNSIGNED16)%m_nOffset).str());
		}
	}

	inline void BinaryDecoder::decodeCString(std::string& sValue){
		if (m_nOffset <= m_aBuffer.size()){
			sValue.clear();
			while (m_nOffset < m_aBuffer.size() && m_aBuffer[m_nOffset] != 0 ){
				sValue += m_aBuffer[m_nOffset++];
			}
			m_nOffset++;
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_CSTRING)%m_nOffset).str());
		}
	}

	inline void BinaryDecoder::decodeCStringMax(std::string& sValue, const unsigned nLimit){
		if (m_nOffset <= m_aBuffer.size())
		{
			sValue.clear();
			while (m_nOffset < m_aBuffer.size() &&
				m_aBuffer[m_nOffset] != 0 )
			{
				sValue += m_aBuffer[m_nOffset++];
				if (sValue.size() + 1 > nLimit) {
					throw std::logic_error((boost::format(CodecErrors::DECODER_OVERFLOW_CSTRING)%m_nOffset).str());
				}

			}
			m_nOffset++;
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_CSTRING)%m_nOffset).str());
		}
	}

	inline void BinaryDecoder::decodeBinary(std::vector<unsigned char>& aValue, unsigned nSize){
		if (m_nOffset <= m_aBuffer.size())
		{
			aValue.clear();
			unsigned int nPos=0;
			while ( m_nOffset < m_aBuffer.size()&& nPos < nSize)
			{
				aValue.push_back(m_aBuffer[m_nOffset++]);
				++nPos;
			}
		}
		else{
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_BINARY)%m_nOffset).str());
		}
	}

	inline void BinaryDecoder::skipNBytes(const unsigned nBytes, const unsigned nLimit){
		this->skipNBytes(nBytes);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::paddingNBytes(const unsigned nBytes, const unsigned nLimit){
		this->paddingNBytes(nBytes);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}


	inline void BinaryDecoder::decodeChar(char& nValue, const unsigned nLimit){
		this->decodeChar(nValue);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeChar(unsigned char& nValue, const unsigned nLimit){
		this->decodeChar(nValue);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeInteger32(int& nValue, const unsigned nLimit){
		this->decodeInteger32(nValue);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeInteger24(int& nValue, const unsigned nLimit){
		this->decodeInteger24(nValue);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeInteger16(short& nValue, const unsigned nLimit){
		this->decodeInteger16(nValue);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeUnsigned32(unsigned& nValue, const unsigned nLimit){
		this->decodeUnsigned32(nValue);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeUnsigned16(unsigned short& nValue, const unsigned nLimit){
		this->decodeUnsigned16(nValue);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeCString(std::string& sValue, const unsigned nLimit){
		this->decodeCString(sValue);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeCStringMax(std::string& sValue, const unsigned nMaxlen, const unsigned nLimit){
		this->decodeCStringMax(sValue, nMaxlen);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}

	inline void BinaryDecoder::decodeBinary(std::vector<unsigned char>& aValue, unsigned nSize, const unsigned nLimit){
		this->decodeBinary(aValue, nSize);
		if (this->m_nOffset > nLimit){
			throw std::logic_error((boost::format(CodecErrors::DECODER_DUE_TO_LIMIT)%m_nOffset %nLimit).str());
		}
	}
}
