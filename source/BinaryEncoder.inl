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



	inline void BinaryEncoder::skipNBytes(const unsigned nBytes){
		if(nBytes == 0) return;
		std::vector<unsigned char> aData(nBytes);
		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		m_nOffset += nBytes;
	}


	inline void BinaryEncoder::paddingNBytes(const unsigned nBytes){
		if(nBytes == 0) return;
		unsigned nShift = nBytes - m_nOffset%nBytes;
		nShift = (nShift == nBytes ? 0 : nShift);
		if(nShift == 0) return;

		std::vector<unsigned char> aData(nShift);
		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		m_nOffset += nShift;
	}


	inline void BinaryEncoder::encodeChar(const char nValue){
		std::vector<unsigned char> aData;
		aData.push_back(nValue);
		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		++m_nOffset;
	}

	inline void BinaryEncoder::encodeChar(const unsigned char nValue){
		std::vector<unsigned char> aData;
		aData.push_back(nValue);
		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		++m_nOffset;
	}

	inline void BinaryEncoder::encodeInteger32(const int nValue){
		int nTemp = htonl(nValue);
		const unsigned int nSizeof = 4;
		std::vector<unsigned char> aData;
		for (unsigned j = 0; j < nSizeof; ++j)
			aData.push_back(((char*)&nTemp)[j]);
		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		m_nOffset += nSizeof;
	}

	inline void BinaryEncoder::encodeInteger24(const int nValue){
		int nTemp = htonl(nValue);
		const unsigned int nSizeof = 3;
		std::vector<unsigned char> aData;
		for (unsigned j = 0; j < nSizeof; ++j)
			aData.push_back(((char*)&nTemp)[j + 1]);
		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		m_nOffset += nSizeof;
	}

	inline void BinaryEncoder::encodeUnsigned32(const unsigned nValue){
		unsigned int nTemp = htonl(nValue);
		std::vector<unsigned char> aData;
		const unsigned int nSizeof = 4;
		for (unsigned j = 0; j < nSizeof; ++j)
			aData.push_back(((char*)&nTemp)[j]);
		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		m_nOffset += nSizeof;
	}

	inline void BinaryEncoder::encodeUnsigned16(const unsigned short nValue){
		unsigned int nTemp = htons(nValue);
		std::vector<unsigned char> aData;
		const unsigned int nSizeof = 2;
		for (unsigned j = 0; j < nSizeof; ++j)
			aData.push_back(((char*)&nTemp)[j]);
		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		m_nOffset += nSizeof;
	}
	inline void BinaryEncoder::encodeCString(const std::string& sValue){
		std::vector<unsigned char> aData;
		for (unsigned j = 0; j < sValue.size(); ++j)
			aData.push_back(sValue[j]);
		aData.push_back(0);

		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		m_nOffset += aData.size();
	}

	inline void BinaryEncoder::encodeCString(const std::string& sValue, const unsigned nLimit){
		std::vector<unsigned char> aData;
		for (unsigned j = 0; j < sValue.size() && j < nLimit; ++j)
			aData.push_back(sValue[j]);
		aData.push_back(0);

		m_aBuffer.insert( m_aBuffer.end(), aData.begin(), aData.end() );
		m_nOffset += aData.size();
	}

	inline void BinaryEncoder::encodeBinary(const std::vector<unsigned char>& aValue){
		if(aValue.empty()) return;
		m_aBuffer.insert( m_aBuffer.end(), aValue.begin(), aValue.end() );
		m_nOffset += aValue.size();
	}



}
