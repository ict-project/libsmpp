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

	inline void OutputterBase::setOutStream(std::ostream& oOutStream){
		// Assign new stream value
		std::ostream* poOutStream = &this->m_oOutStream;
		std::ostream* poStream = &oOutStream;
		poOutStream = poStream;
	}

	inline std::ostream& OutputterBase::refOutStream(void){
		return this->m_oOutStream;
	}

	inline const std::ostream& OutputterBase::getOutStream(void) const{
		return this->m_oOutStream;
	}

}

