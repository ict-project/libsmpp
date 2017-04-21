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
#include "SMPPDatatypes.hpp"


namespace anthill {
	namespace smpp {


		////////////////////////////////////////////////////////////
		// BroadcastAreaIdentifier
		////////////////////////////////////////////////////////////
		BroadcastAreaIdentifier::BroadcastAreaIdentifier(void):
			aValue(){
		}

		BroadcastAreaIdentifier::BroadcastAreaIdentifier(const std::vector<unsigned char>& aVal):
			aValue(aVal){
		}

		BroadcastAreaIdentifier::~BroadcastAreaIdentifier(){
		}

		const bool BroadcastAreaIdentifier::operator ==(const BroadcastAreaIdentifier& rhs) const{
			if(this->aValue != rhs.aValue) return false;
			return true;
		}

		const bool BroadcastAreaIdentifier::operator !=(const BroadcastAreaIdentifier& rhs) const{
			return !this->operator ==(rhs);
		}
		////////////////////////////////////////////////////////////
		// SMPPDateTime
		////////////////////////////////////////////////////////////
		SMPPDateTime::SMPPDateTime(void):
			aValue(){
		}

		SMPPDateTime::SMPPDateTime(const std::vector<unsigned char>& aVal):
			aValue(aVal){
		}

		SMPPDateTime::~SMPPDateTime(){
		}

		const bool SMPPDateTime::operator ==(const SMPPDateTime& rhs) const{
			if(this->aValue != rhs.aValue) return false;
			return true;
		}

		const bool SMPPDateTime::operator !=(const SMPPDateTime& rhs) const{
			return !this->operator ==(rhs);
		}

	}
}
