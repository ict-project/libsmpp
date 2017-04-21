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

		inline void SMPPPDU::setHeader(const Header oHeader){
			this->m_oHeader = oHeader;
		}

		inline Header& SMPPPDU::refHeader(void){
			return this->m_oHeader;
		}
		inline const Header& SMPPPDU::getHeader(void) const{
			return this->m_oHeader;
		}


		inline void SMPPPDU::setCommandLength(const unsigned nCommandLength){
			this->m_oHeader.setCommandLength(nCommandLength);
		}

		inline unsigned& SMPPPDU::refCommandLength(void){
			return this->m_oHeader.refCommandLength();
		}

		inline const unsigned SMPPPDU::getCommandLength(void) const{
			return this->m_oHeader.getCommandLength();
		}


		inline void SMPPPDU::setCommandId(const unsigned nCommandId){
			this->m_oHeader.setCommandId(nCommandId);
		}

		inline unsigned& SMPPPDU::refCommandId(void){
			return this->m_oHeader.refCommandId();
		}

		inline const unsigned SMPPPDU::getCommandId(void) const{
			return this->m_oHeader.getCommandId();
		}


		inline void SMPPPDU::setCommandStatus(const unsigned nCommandStatus){
			this->m_oHeader.setCommandStatus(nCommandStatus);
		}

		inline unsigned& SMPPPDU::refCommandStatus(void){
			return this->m_oHeader.refCommandStatus();
		}

		inline const unsigned SMPPPDU::getCommandStatus(void) const{
			return this->m_oHeader.getCommandStatus();
		}


		inline void SMPPPDU::setSequenceNumber(const unsigned nSequenceNumber){
			this->m_oHeader.setSequenceNumber(nSequenceNumber);
		}

		inline unsigned& SMPPPDU::refSequenceNumber(void){
			return this->m_oHeader.refSequenceNumber();
		}

		inline const unsigned SMPPPDU::getSequenceNumber(void) const{
			return this->m_oHeader.getSequenceNumber();
		}

	}
}
