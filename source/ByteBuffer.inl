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
	inline void ByteBuffer::dumpBuffer() const {
		std::stringstream oOutStream;
		oOutStream << "Buffer instance #" << this << ". Size: " << m_aBuffer.size() << std::endl;
		oOutStream << " [";
		this->writeDump(oOutStream);
		oOutStream << "]" <<std::endl;
		oOutStream << '\0' ;

		// Output stream
		std::cout << oOutStream.str();
	}

	inline void ByteBuffer::readDump(std::istream& oInputStream){

		std::vector<unsigned char> vData;

		// Iterate accross lines
		while(!oInputStream.eof()){
			std::string sLine;
			getline(oInputStream, sLine);
			if (sLine.empty() == false && *(sLine.end() -1) == '\0')
				sLine.erase(sLine.end() -1, sLine.end());

			typedef boost::tokenizer<boost::char_separator<char> > Tokenizer;
			boost::char_separator<char> oSeparators(",; ");	// list of the separators

			Tokenizer oTokenizer(sLine, oSeparators);
			for (Tokenizer::iterator theIter = oTokenizer.begin();
				theIter != oTokenizer.end(); ++theIter){

					// Erase 0x, 0X, X and x
					std::string sItem = *theIter;
					boost::algorithm::replace_first(sItem, "0x","");
					boost::algorithm::replace_first(sItem, "0X","");
					boost::algorithm::replace_first(sItem, "x","");
					boost::algorithm::replace_first(sItem, "X","");

					// Store to buffer
					char* szDummy = NULL;
					unsigned nValue = strtoul(sItem.c_str(),&szDummy,16);
					if(szDummy == &sItem[sItem.size()] && nValue <= 0xFF){
						this->m_aBuffer.push_back((unsigned char) nValue);
					}else{
						throw std::logic_error(Errors::INVALID_DUMP_FORMAT);
					}
			}
		}
	}

	inline void ByteBuffer::writeDump(std::ostream& oOutStream) const{
		std::ios_base::fmtflags nFlags = oOutStream.flags( std::ios::right | std::ios::uppercase);
		char nFiller = oOutStream.fill('0');
		for(unsigned int i=0; i< this->m_aBuffer.size();i++) {
			oOutStream << std::hex << std::setw( 2 );
			oOutStream << (unsigned)this->m_aBuffer[i] << std::dec << " ";
		}
		oOutStream.fill(nFiller);
		oOutStream.flags(nFlags);
	}

	inline void ByteBuffer::readData(std::istream& oInputStream){
		unsigned char aBuffer[256];
		while(!oInputStream.eof()){
			
			oInputStream.read((char*)&aBuffer, sizeof(aBuffer));
			for(int j= 0; j < oInputStream.gcount(); ++j){
				this->m_aBuffer.push_back(aBuffer[j]);
			}
		}

	}

	inline void ByteBuffer::writeData(std::ostream& oOutStream) const{
		oOutStream.write((char*)&this->m_aBuffer[0], this->m_aBuffer.size());
	}
}

