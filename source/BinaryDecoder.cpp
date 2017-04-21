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

#include "AntHill.hpp"
#include "BinaryDecoder.hpp"


namespace anthill {

	BinaryDecoder::BinaryDecoder(void):
		m_nOffset(0){
	}

	BinaryDecoder::BinaryDecoder(const BinaryDecoder& rhs):
		m_nOffset(rhs.m_nOffset){
	}

	BinaryDecoder& BinaryDecoder::operator=(const BinaryDecoder&){
		return *this;
	}


	BinaryDecoder::~BinaryDecoder(){
	}

	void BinaryDecoder::resetBuffer(void){
		this->m_aBuffer.clear();
		m_nOffset = 0;
	}

	std::vector<unsigned char>& BinaryDecoder::refBuffer(void){
		return this->m_aBuffer;
	}

	const std::vector<unsigned char>& BinaryDecoder::getBuffer(void) const{
		return this->m_aBuffer;
	}

	void BinaryDecoder::appendBuffer(const std::vector<unsigned char>& aBuffer){
		this->m_aBuffer.insert( m_aBuffer.end(), aBuffer.begin(), aBuffer.end() );
	}

	void BinaryDecoder::validateOffset(const unsigned nLength){
		if(this->m_nOffset != nLength) 
			throw std::logic_error((boost::format(CodecErrors::DECODER_INV_OFFSET)%m_nOffset %nLength).str());
	}
}
