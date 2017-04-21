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

#include "AntHillSMPP.hpp"
#include "SMPPPDU.hpp"
#include "SMPPEncoder.hpp"


namespace anthill {
	namespace smpp {


		SMPPEncoder::SMPPEncoder(void):
			BinaryEncoder(){
		}

		SMPPEncoder::~SMPPEncoder(){
		}

		std::vector<unsigned char>& SMPPEncoder::encodePacket(SMPPPDU* poPDU){
			this->resetBuffer();
			poPDU->encodePacket(this);
			this->encodeCommandLength();
			return this->m_aBuffer;
		}

		void SMPPEncoder::encodeCommandLength(void){

			const unsigned int nSizeof = 4;
			int nTemp = dohtonl(this->m_nOffset);
			std::vector<unsigned char> aData;
			for (unsigned j = 0; j < nSizeof; ++j)
				aData.push_back(((char*)&nTemp)[j]);

			const unsigned nShift = SMPPOffset::COMMAND_LENGTH_POS;
			unsigned char* aStart = &m_aBuffer[nShift];
			memcpy(aStart, &aData[0], aData.size());

		}

		void SMPPEncoder::encodeTLV(const unsigned short nTag, const unsigned char nValue, const unsigned short nLen){
			this->encodeUnsigned16(nTag);
			this->encodeUnsigned16(nLen);
			this->encodeChar(nValue);
		}

		void SMPPEncoder::encodeTLV(const unsigned short nTag, const unsigned short nValue, const unsigned short nLen){
			this->encodeUnsigned16(nTag);
			this->encodeUnsigned16(nLen);
			this->encodeUnsigned16(nValue);
		}

		void SMPPEncoder::encodeTLV(const unsigned short nTag, const unsigned nValue, const unsigned short nLen){
			this->encodeUnsigned16(nTag);
			this->encodeUnsigned16(nLen);
			this->encodeUnsigned32(nValue);
		}

		void SMPPEncoder::encodeTLV(const unsigned short nTag, const std::string& sValue, const unsigned short nLen){
			this->encodeUnsigned16(nTag);
			this->encodeUnsigned16(nLen);
			this->encodeCString(sValue);
		}

		void SMPPEncoder::encodeTLV(const unsigned short nTag, const std::vector<unsigned char>& aValue, const unsigned short nLen){
			this->encodeUnsigned16(nTag);
			this->encodeUnsigned16(nLen);
			this->encodeBinary(aValue);
		}
	}
}
