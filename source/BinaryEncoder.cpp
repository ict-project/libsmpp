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
#include "BinaryEncoder.hpp"


namespace anthill {

	BinaryEncoder::BinaryEncoder(void):
		m_nOffset(0){
	}

	BinaryEncoder::BinaryEncoder(const BinaryEncoder& rhs):
		m_nOffset(rhs.m_nOffset){
	}

	BinaryEncoder& BinaryEncoder::operator=(const BinaryEncoder& rhs){
		EncoderBase::operator =(rhs);
		return *this;
	}


	BinaryEncoder::~BinaryEncoder(){
	}


	void BinaryEncoder::resetBuffer(void){
		this->m_aBuffer.clear();
		this->m_nOffset = 0;
	}

	std::vector<unsigned char>& BinaryEncoder::refBuffer(void){
		return this->m_aBuffer;
	}

	const std::vector<unsigned char>& BinaryEncoder::getBuffer(void) const{
		return this->m_aBuffer;
	}

	void BinaryEncoder::appendBuffer(const std::vector<unsigned char>& aBuffer){
		this->m_aBuffer.insert( m_aBuffer.end(), aBuffer.begin(), aBuffer.end() );
	}

}
