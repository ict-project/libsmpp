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
	namespace smpp {

		////////////////////////////////////////////////////////////
		// BroadcastAreaIdentifier
		////////////////////////////////////////////////////////////
		inline const bool BroadcastAreaIdentifier::isAlias(void) const{
			if(this->aValue.empty()) return false;
			return (this->aValue[0] == BroadcastAreaFormat::ALIAS);
		}

		inline const bool BroadcastAreaIdentifier::isEllipsoid(void) const{
			if(this->aValue.empty()) return false;
			return (this->aValue[0] == BroadcastAreaFormat::ELLIPSOID);
		}

		inline const bool BroadcastAreaIdentifier::isPolygon(void) const{
			if(this->aValue.empty()) return false;
			return (this->aValue[0] == BroadcastAreaFormat::POLYGON);
		}

		inline const unsigned char BroadcastAreaIdentifier::getBroadcastAreaFormat(void) const{
			if(this->aValue.empty()) return BroadcastAreaFormat::UNKNOWN;
			if(this->aValue[0] == BroadcastAreaFormat::ALIAS || 
				this->aValue[0] == BroadcastAreaFormat::ELLIPSOID ||
				this->aValue[0] == BroadcastAreaFormat::POLYGON ){
				return this->aValue[0];
			}
			return BroadcastAreaFormat::UNKNOWN;
		}

		inline void BroadcastAreaIdentifier::setAlias(const std::vector<unsigned char>& aValue){
			this->aValue.push_back(BroadcastAreaFormat::ALIAS);
			this->aValue.insert(this->aValue.end(), aValue.begin(), aValue.end());
		}


		inline void BroadcastAreaIdentifier::setEllipsoid(const std::vector<unsigned char>& aValue){
			this->aValue.push_back(BroadcastAreaFormat::ELLIPSOID);
			this->aValue.insert(this->aValue.end(), aValue.begin(), aValue.end());
		}


		inline void BroadcastAreaIdentifier::setPolygon(const std::vector<unsigned char>& aValue){
			this->aValue.push_back(BroadcastAreaFormat::POLYGON);
			this->aValue.insert(this->aValue.end(), aValue.begin(), aValue.end());
		}

		inline void BroadcastAreaIdentifier::setValue(const std::vector<unsigned char>& aValue){
			this->aValue = aValue;
		}

		inline std::vector<unsigned char>& BroadcastAreaIdentifier::refValue(void){
			return this->aValue;
		}

		inline const std::vector<unsigned char>& BroadcastAreaIdentifier::getValue(void) const{
			return this->aValue;
		}

		////////////////////////////////////////////////////////////
		// SmppDateTime
		////////////////////////////////////////////////////////////
		inline void SMPPDateTime::setValue(const std::vector<unsigned char>& aValue){
			this->aValue = aValue;
		}

		inline std::vector<unsigned char>& SMPPDateTime::refValue(void){
			return this->aValue;
		}

		inline const std::vector<unsigned char>& SMPPDateTime::getValue(void) const{
			return this->aValue;
		}

	}
}
