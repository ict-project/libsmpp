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

#ifndef BYTEBUFFER_HPP
#define BYTEBUFFER_HPP

namespace anthill {


	/**
	 * A base decoder
	 */
	class ANTHILL_DLLPRFX ByteBuffer{
	public:
		ByteBuffer(std::vector<unsigned char>&);
		ByteBuffer(const std::vector<unsigned char>&);
		ByteBuffer(const ByteBuffer&);
		ByteBuffer& operator=(const ByteBuffer&);
		virtual ~ByteBuffer();
	public:
		inline void dumpBuffer() const;
		inline void readDump(std::istream&);
		inline void writeDump(std::ostream&) const;
		inline void readData(std::istream&);
		inline void writeData(std::ostream&) const;


	protected:
		std::vector<unsigned char>& m_aBuffer;
	};
}

// Include inline files
#include "ByteBuffer.inl"

#endif // BYTEBUFFER_HPP
