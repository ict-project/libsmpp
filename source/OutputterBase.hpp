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

#ifndef OUTPUTTERBASE_HPP
#define OUTPUTTERBASE_HPP


namespace anthill {


	/**
	 * A base decoder
	 */
	class ANTHILL_DLLPRFX OutputterBase{
	public:
		OutputterBase(std::ostream&);
		OutputterBase(const OutputterBase&);
		OutputterBase& operator=(const OutputterBase&);
		virtual ~OutputterBase();
	public:
		inline void setOutStream(std::ostream&);
		inline std::ostream& refOutStream(void);
		inline const std::ostream& getOutStream(void) const;

	protected:
		std::ostream& m_oOutStream;

	};
}

// Include inline files
#include "OutputterBase.inl"


#endif // OUTPUTTERBASE_HPP
