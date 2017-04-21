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

#ifndef BINARYOUTPUTTER_HPP
#define BINARYOUTPUTTER_HPP

#include "OutputterBase.hpp"

namespace anthill {


	/**
	 * A base decoder
	 */
	class ANTHILL_DLLPRFX BinaryOutputter : public OutputterBase{
	public:
		BinaryOutputter(std::ostream&);
		BinaryOutputter(const BinaryOutputter&);
		BinaryOutputter& operator=(const BinaryOutputter&);
		virtual ~BinaryOutputter();
	public:

	};
}

#endif // BINARYOUTPUTTER_HPP
