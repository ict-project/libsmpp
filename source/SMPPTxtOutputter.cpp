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
#include "SMPPTxtOutputter.hpp"


namespace anthill {
	namespace smpp {

		SMPPTxtOutputter::SMPPTxtOutputter(std::ostream& oOutStream):
			SMPPOutputterBase(),
			TextOutputter(oOutStream){
		}

		SMPPTxtOutputter::SMPPTxtOutputter(std::ostream& oOutStream, const bool bShowHex):
			SMPPOutputterBase(),
			TextOutputter(oOutStream),
			m_bShowHeximal(bShowHex),
			m_bShowEsminfo(true),
			m_bShowFmtinfo(true){
		}

		SMPPTxtOutputter::SMPPTxtOutputter(std::ostream& oOutStream, const bool bShowHex, const bool bShowEsm):
			SMPPOutputterBase(),
			TextOutputter(oOutStream),
			m_bShowHeximal(bShowHex),
			m_bShowEsminfo(bShowEsm),
			m_bShowFmtinfo(true){

		}

		SMPPTxtOutputter::SMPPTxtOutputter(std::ostream& oOutStream, const bool bShowHex, const bool bShowEsm, const bool bShowFmt):
			SMPPOutputterBase(),
			TextOutputter(oOutStream),
			m_bShowHeximal(bShowHex),
			m_bShowEsminfo(bShowEsm),
			m_bShowFmtinfo(bShowFmt){
		}

		SMPPTxtOutputter::~SMPPTxtOutputter(){
		}

		void SMPPTxtOutputter::outputHeader(const Header& oHeader){
			
			// Output command length
			this->m_oOutStream << std::setiosflags( std::ios::left );
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::HEADER;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::COMMAND_LENGTH;
			this->m_oOutStream << oHeader.getCommandLength();
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeUnsigned32(oHeader.getCommandLength());
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);

			}
			this->m_oOutStream << std::endl;

			// Output comnadn id
			std::string sCommandName(this->getCommandName(oHeader.getCommandId()));
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::HEADER;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::COMMAND_ID;
			this->m_oOutStream << Outputter::HEXSIGN << std::hex << oHeader.getCommandId();
			this->m_oOutStream << std::dec << Outputter::EQUAL << sCommandName;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeUnsigned32(oHeader.getCommandId());
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

			// Output command statuts
			this->m_oOutStream << std::setiosflags( std::ios::left );
			std::string sErrorName(this->getErrorName(oHeader.getCommandStatus()));
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::HEADER;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::COMMAND_STATUS;
			this->m_oOutStream << oHeader.getCommandStatus() << Outputter::EQUAL << sErrorName;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeUnsigned32(oHeader.getCommandStatus());
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

			// Output sequence number
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::HEADER;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SEQUENCE_NUMBER;
			this->m_oOutStream << oHeader.getSequenceNumber();
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeUnsigned32(oHeader.getSequenceNumber());
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputSystemId(const std::string& sSystemId){

			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SYSTEM_ID;
			this->m_oOutStream << sSystemId;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSystemId(sSystemId);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputPassword(const std::string& sPassword){

			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::PASSWORD;
			this->m_oOutStream << sPassword;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodePassword(sPassword);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSystemType(const std::string& sSystemType){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SYSTEM_TYPE;
			this->m_oOutStream << sSystemType;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSystemType(sSystemType);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputInterfaceVersion(const unsigned char nInterfaceVersion){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SC_INTERFACE_VERSION;
			this->m_oOutStream << Outputter::HEXSIGN << std::hex << (int)nInterfaceVersion << std::dec;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeInterfaceVersion(nInterfaceVersion);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputAddrTON(const unsigned char nAddrTON){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::ADDR_TON;
			this->m_oOutStream << (int)nAddrTON;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeAddrTON(nAddrTON);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputAddrNPI(const unsigned char nAddrNPI){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::ADDR_NPI;
			this->m_oOutStream << (int)nAddrNPI;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeAddrNPI(nAddrNPI);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputAddressRange(const std::string& sAddressRange){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::ADDRESS_RANGE;
			this->m_oOutStream << sAddressRange;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeAddressRange(sAddressRange);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputServiceType(const std::string& sServiceType){

			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SERVICE_TYPE;
			this->m_oOutStream << sServiceType;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeServiceType(sServiceType);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputSourceAddrTON(const unsigned char nSourceAddrTON){

			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SOURCE_ADDR_TON;
			this->m_oOutStream << (int)nSourceAddrTON;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceAddrTON(nSourceAddrTON);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputSourceAddrNPI(const unsigned char nSourceAddrNPI){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SOURCE_ADDR_NPI;
			this->m_oOutStream << (int)nSourceAddrNPI;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceAddrNPI(nSourceAddrNPI);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSourceAddr21(const std::string& sSourceAddr){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SOURCE_ADDR;
			this->m_oOutStream << sSourceAddr;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceAddr21(sSourceAddr);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputSourceAddr65(const std::string& sSourceAddr){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SOURCE_ADDR;
			this->m_oOutStream << sSourceAddr;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceAddr65(sSourceAddr);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDestAddrTON(const unsigned char nDestAddrTON){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::DEST_ADDR_TON;
			this->m_oOutStream << (int)nDestAddrTON;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestAddrTON(nDestAddrTON);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDestAddrNPI(const unsigned char nDestAddrNPI){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::DEST_ADDR_NPI;
			this->m_oOutStream << (int)nDestAddrNPI;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestAddrNPI(nDestAddrNPI);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDestAddr21(const std::string& sDestAddr){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::DEST_ADDR;
			this->m_oOutStream << sDestAddr;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestAddr21(sDestAddr);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDestAddr65(const std::string& sDestAddr){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::DEST_ADDR;
			this->m_oOutStream << sDestAddr;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestAddr65(sDestAddr);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputEsmClass(const unsigned char nEsmClass){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::ESM_CLASS;
			this->m_oOutStream << (int)nEsmClass;

			if(this->m_bShowEsminfo){
				// Explain esm class
				std::string sMessagingMode(this->getMessagingMode(nEsmClass));
				this->m_oOutStream << Outputter::COMMA << EsmClass::MESSAGING_MODE;
				this->m_oOutStream << Outputter::EQUAL << sMessagingMode;

				std::string sMessageType(this->getMessageType(nEsmClass));
				this->m_oOutStream << Outputter::COMMA << EsmClass::MESSAGE_TYPE;
				this->m_oOutStream << Outputter::EQUAL << sMessageType;

				std::string sMessageFeatures(this->getMessageFeatures(nEsmClass));
				this->m_oOutStream << Outputter::COMMA << EsmClass::MESSAGE_FEATURES;
				this->m_oOutStream << Outputter::EQUAL << sMessageFeatures;
			}

			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeEsmClass(nEsmClass);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputProtocolId(const unsigned char nProtocolId){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::PROTOCOLID;
			this->m_oOutStream << (int)nProtocolId;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeProtocolId(nProtocolId);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputPriorityFlag(const unsigned char nPriorityFlag){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::PRIORITY_FLAG;
			this->m_oOutStream << (int)nPriorityFlag;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodePriorityFlag(nPriorityFlag);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SCHEDULE_DELIVERY_TIME;
			this->m_oOutStream << sScheduleDeliveryTime;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeScheduleDeliveryTime(sScheduleDeliveryTime);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputValidityPeriod(const std::string& sValidityPeriod){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::VALIDITY_PERIOD;
			this->m_oOutStream << sValidityPeriod;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeValidityPeriod(sValidityPeriod);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputRegisteredDelivery(const unsigned char nRegisteredDelivery){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::REGISTERED_DELIVERY;
			this->m_oOutStream << (int)nRegisteredDelivery;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeRegisteredDelivery(nRegisteredDelivery);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::REPLACE_IF_PRESENT;
			this->m_oOutStream << (int)nReplaceIfPresentFlag;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeReplaceIfPresentFlag(nReplaceIfPresentFlag);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDataCoding(const unsigned char nDataCoding){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::DATA_CODING;
			this->m_oOutStream << (int)nDataCoding;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDataCoding(nDataCoding);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SM_DEFAULT_MSG_ID;
			this->m_oOutStream << (int)nSMDefaultMsgId;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSMDefaultMsgId(nSMDefaultMsgId);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
	
		}

		void SMPPTxtOutputter::outputSMLength(const unsigned char nSMLength){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SM_LENGTH;
			this->m_oOutStream << (int)nSMLength;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSMLength(nSMLength);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputShortMessage(std::vector<unsigned char>& aShortMessage){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::SHORT_MESSAGE;
			if(aShortMessage.empty() == false){
				ByteBuffer oBuffer(aShortMessage);
				oBuffer.writeDump(this->m_oOutStream);
			}

			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeShortMessage(aShortMessage);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputMessageId(const std::string& sMessageId){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::MESSAGE_ID;
			this->m_oOutStream << sMessageId;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMessageId(sMessageId);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputESMEAddrTON(const unsigned char nESMEAddrTON){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::ESME_ADDR_TON;
			this->m_oOutStream << (int)nESMEAddrTON;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeESMEAddrTON(nESMEAddrTON);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputESMEAddrNPI(const unsigned char nESMEAddrNPI){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::ESME_ADDR_NPI;
			this->m_oOutStream << (int)nESMEAddrNPI;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeESMEAddrNPI(nESMEAddrNPI);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputESMEAddr(const std::string& sESMEAddr){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::ESME_ADDR;
			this->m_oOutStream << sESMEAddr;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeESMEAddr(sESMEAddr);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputNumberOfDest(const unsigned char nNumberOfDest){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::NUMBER_OF_DEST;
			this->m_oOutStream << (int)nNumberOfDest;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeNumberOfDest(nNumberOfDest);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDestAddresses(const std::vector<DestAddress>& aDestAddresses){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::DEST_ADDRESSES;

			// Output all distribution lest and addresses
			for(unsigned i = 0; i < aDestAddresses.size(); ++i){
				if(i == 0){
					this->m_oOutStream << Outputter::LCURLYBRACE;
				}
				// Output destination address
				this->m_oOutStream << Outputter::LBRACKET << FieldsName::DESTFLAG;
				this->m_oOutStream << Outputter::COLON << Outputter::SPACE;
				this->m_oOutStream << (int)aDestAddresses[i].getDestFlag();
				switch(aDestAddresses[i].getDestFlag()){
					case DestFlag::SME_ADDRESS:{
						this->m_oOutStream << Outputter::SPACE << FieldsName::TON;
						this->m_oOutStream << Outputter::COLON << Outputter::SPACE;;
						this->m_oOutStream << (int)aDestAddresses[i].getAddress().getTON();
						this->m_oOutStream << Outputter::SPACE << FieldsName::NPI;
						this->m_oOutStream << Outputter::COLON << Outputter::SPACE;;
						this->m_oOutStream << (int)aDestAddresses[i].getAddress().getNPI();
						this->m_oOutStream << Outputter::SPACE << FieldsName::ADDRESS;
						this->m_oOutStream << Outputter::COLON << Outputter::SPACE;;
						this->m_oOutStream << aDestAddresses[i].getAddress().getAddress();
						break;
					}
					case DestFlag::DISTR_LIST_NAME:{
						this->m_oOutStream << Outputter::SPACE << FieldsName::DISTR_LIST_NAME;
						this->m_oOutStream << Outputter::COLON << Outputter::SPACE;
						this->m_oOutStream << aDestAddresses[i].getDistrListName();
						break;
					}
					default:{
						this->m_oOutStream << Outputter::SPACE << FieldsName::INV_DEST_FLAG;
						this->m_oOutStream << Outputter::SPACE;
						break;
					}
				}
				this->m_oOutStream << Outputter::RBRACKET;

				// Next or last element
				if(i != (aDestAddresses.size() - 1)){
					this->m_oOutStream << Outputter::COMMA;
				} else {
					this->m_oOutStream << Outputter::RCURLYBRACE;
				}
			}

			//Output hex representation
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestAddresses(aDestAddresses);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputNoUnsuccess(const unsigned char nNoUnsuccess){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::NO_UNSUCCESS;
			this->m_oOutStream << (int)nNoUnsuccess;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeNoUnsuccess(nNoUnsuccess);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputUnsuccessSMEs(const std::vector<UnsuccessSME>& aUnsuccessSMEs){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::UNSUCCESS_SMES;


			// Output all unsuccess SMSEs
			for(unsigned i = 0; i < aUnsuccessSMEs.size(); ++i){
				if(i == 0){
					this->m_oOutStream << Outputter::LCURLYBRACE;
				}
				// Output destination address
				this->m_oOutStream << Outputter::LBRACKET << FieldsName::ERROR_STATUS_CODE;
				this->m_oOutStream << Outputter::COLON << Outputter::SPACE;
				this->m_oOutStream << aUnsuccessSMEs[i].getErrorStatusCode();

				this->m_oOutStream << Outputter::SPACE << FieldsName::TON;
				this->m_oOutStream << Outputter::COLON << Outputter::SPACE;;
				this->m_oOutStream << (int)aUnsuccessSMEs[i].getSMEAddress().getTON();
				this->m_oOutStream << Outputter::SPACE << FieldsName::NPI;
				this->m_oOutStream << Outputter::COLON << Outputter::SPACE;;
				this->m_oOutStream << (int)aUnsuccessSMEs[i].getSMEAddress().getNPI();
				this->m_oOutStream << Outputter::SPACE << FieldsName::ADDRESS;
				this->m_oOutStream << Outputter::COLON << Outputter::SPACE;;
				this->m_oOutStream << aUnsuccessSMEs[i].getSMEAddress().getAddress();
				this->m_oOutStream << Outputter::RBRACKET;

				// Next or last element
				if(i != (aUnsuccessSMEs.size() - 1)){
					this->m_oOutStream << Outputter::COMMA;
				} else {
					this->m_oOutStream << Outputter::RCURLYBRACE;
				}
			}

			//Output hex representation
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeUnsuccessSMEs(aUnsuccessSMEs);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputFinalDate(const std::string& sFinalDate){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::FINAL_DATE;
			this->m_oOutStream << sFinalDate;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeFinalDate(sFinalDate);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputMessageState(const unsigned char nMessageState){
			std::string sMessageStateName(this->getMessageStateName(nMessageState));
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::MESSAGE_STATE;
			this->m_oOutStream << (int)nMessageState << Outputter::EQUAL << sMessageStateName;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMessageState(nMessageState);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputMessageStateTLV(const unsigned char nMessageState, const unsigned short nMessageStateLen){
			std::string sMessageStateName(this->getMessageStateName(nMessageState));
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << nMessageStateLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::MESSAGE_STATE;
			this->m_oOutStream << (int)nMessageState << Outputter::EQUAL << sMessageStateName;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMessageStateTLV(nMessageState, nMessageStateLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputErrorCode(const unsigned char nErrorCode){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER ) << Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH ) << Outputter::EMPTY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME ) << FieldsName::ERROR_CODE;
			this->m_oOutStream << (int)nErrorCode;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeErrorCode(nErrorCode);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){
			// Output all broadcast area identifiers
			for(unsigned i = 0; i < aBroadcastAreaIdentifier.size(); ++i){
				this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::MANDATORY;
				this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< aBroadcastAreaIdentifierLen[i];
				this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_AREA_IDENTIFIER;
				if(aBroadcastAreaIdentifier[i].getValue().empty() == false){
					ByteBuffer oBuffer(aBroadcastAreaIdentifier[i].getValue());
					oBuffer.writeDump(this->m_oOutStream);

					if(this->m_bShowFmtinfo){
						// Explain broadcast area identifier
						const char nAreaFormat = aBroadcastAreaIdentifier[i].getValue()[0];
						std::string sAreaFormatName(this->getAreaFormatName(nAreaFormat));
						this->m_oOutStream << Outputter::COMMA << (int)nAreaFormat;
						this->m_oOutStream << Outputter::EQUAL << sAreaFormatName;
					}
				}
				if(this->m_bShowHeximal){
					this->m_oEncoder.resetBuffer();
					this->m_oEncoder.encodeBroadcastAreaIdentifier(aBroadcastAreaIdentifier[i], aBroadcastAreaIdentifierLen[i]);
					this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
					this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
					ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
					oBuffer.writeDump(this->m_oOutStream);
				}
				this->m_oOutStream << std::endl;
			}
		}

		void SMPPTxtOutputter::outputBroadcastRepNum(const unsigned short nBroadcastRepNum, const unsigned short nBroadcastRepNumLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastRepNumLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_REP_NUM;
			this->m_oOutStream << nBroadcastRepNum;

			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastRepNum(nBroadcastRepNum, nBroadcastRepNumLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastFrequencyInterval(const std::vector<unsigned char>& aBroadcastFrequencyInterval, const unsigned short nBroadcastFrequencyIntervalLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastFrequencyIntervalLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_FREQUENCY_INTERVAL;
			if(aBroadcastFrequencyInterval.empty() == false){
				ByteBuffer oBuffer(aBroadcastFrequencyInterval);
				oBuffer.writeDump(this->m_oOutStream);
			}
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastFrequencyInterval(aBroadcastFrequencyInterval, nBroadcastFrequencyIntervalLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastContentType(const std::vector<unsigned char>& aBroadcastContentType, const unsigned short nBroadcastContentTypeLen){

			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastContentTypeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_CONTENT_TYPE;
			if(aBroadcastContentType.empty() == false){
				ByteBuffer oBuffer(aBroadcastContentType);
				oBuffer.writeDump(this->m_oOutStream);
			}

			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastContentType(aBroadcastContentType, nBroadcastContentTypeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastAreaSuccess(const unsigned char nBroadcastAreaSuccess, const unsigned short nBroadcastAreaSuccessLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::MANDATORY;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastAreaSuccessLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_AREA_SUCCESS;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastAreaSuccess(nBroadcastAreaSuccess,nBroadcastAreaSuccessLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputScInterfaceVersion(const unsigned char nScInterfaceVersion, const unsigned short nScInterfaceVersionLen){

			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nScInterfaceVersionLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SC_INTERFACE_VERSION;
			this->m_oOutStream << Outputter::HEXSIGN << std::hex << (int)nScInterfaceVersion << std::dec;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeScInterfaceVersion(nScInterfaceVersion, nScInterfaceVersionLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputMSAvailabilityStatus(const unsigned char nMSAvailabilityStatus, const unsigned short nMSAvailabilityStatusLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nMSAvailabilityStatusLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::MS_AVAILABILITY_STATUS;
			this->m_oOutStream << (int)nMSAvailabilityStatus;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMSAvailabilityStatus(nMSAvailabilityStatus, nMSAvailabilityStatusLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery, const unsigned short nAlertOnMsgDeliveryLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nAlertOnMsgDeliveryLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::ALERT_ON_MSG_DELIVERY;
			this->m_oOutStream << (int)nAlertOnMsgDelivery;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeAlertOnMsgDelivery(nAlertOnMsgDelivery, nAlertOnMsgDeliveryLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastChannelIndicator(const unsigned char nBroadcastChannelIndicator, const unsigned short nBroadcastChannelIndicatorLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastChannelIndicatorLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_CHANNEL_INDICATOR;
			this->m_oOutStream << (int)nBroadcastChannelIndicator;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastChannelIndicator(nBroadcastChannelIndicator, nBroadcastChannelIndicatorLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastContentTypeInfo(const std::vector<unsigned char>& aBroadcastContentTypeInfo, const unsigned short nBroadcastContentTypeInfoLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastContentTypeInfoLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_CONTENT_TYPE_INFO;
			if(aBroadcastContentTypeInfo.empty() == false){
				ByteBuffer oBuffer(aBroadcastContentTypeInfo);
				oBuffer.writeDump(this->m_oOutStream);
			}
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastContentTypeInfo(aBroadcastContentTypeInfo, nBroadcastContentTypeInfoLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputBroadcastMessageClass(const unsigned char nBroadcastMessageClass, const unsigned short nBroadcastMessageClassLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastMessageClassLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_MESSAGE_CLASS;
			this->m_oOutStream << (int)nBroadcastMessageClass;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastMessageClass(nBroadcastMessageClass, nBroadcastMessageClassLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastServiceGroup(const std::vector<unsigned char>& aBroadcastServiceGroup, const unsigned short nBroadcastServiceGroupLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastServiceGroupLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_SERVICE_GROUP;
			if(aBroadcastServiceGroup.empty() == false){
				ByteBuffer oBuffer(aBroadcastServiceGroup);
				oBuffer.writeDump(this->m_oOutStream);
			}
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastServiceGroup(aBroadcastServiceGroup, nBroadcastServiceGroupLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputCallbackNum(const std::vector<unsigned char>& aCallbackNum, const unsigned short nCallbackNumLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nCallbackNumLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::CALLBACK_NUM;
			if(aCallbackNum.empty() == false){
				ByteBuffer oBuffer(aCallbackNum);
				oBuffer.writeDump(this->m_oOutStream);
			}
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeCallbackNum(aCallbackNum, nCallbackNumLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag, const unsigned short nCallbackNumAtagLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nCallbackNumAtagLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::CALLBACK_NUM_ATAG;
			if(aCallbackNumAtag.empty() == false){
				ByteBuffer oBuffer(aCallbackNumAtag);
				oBuffer.writeDump(this->m_oOutStream);
			}
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeCallbackNumAtag(aCallbackNumAtag, nCallbackNumAtagLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputCallbackNumPresInd(const unsigned char nCallbackNumPresInd, const unsigned short nCallbackNumPresIndLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nCallbackNumPresIndLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::CALLBACK_NUM_PRES_IND;
			this->m_oOutStream << (int)nCallbackNumPresInd;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeCallbackNumPresInd(nCallbackNumPresInd, nCallbackNumPresIndLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDestAddrSubunit(const unsigned char nDestAddrSubunit, const unsigned short nDestAddrSubunitLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDestAddrSubunitLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DEST_ADDR_SUBUNIT;
			this->m_oOutStream << (int)nDestAddrSubunit;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestAddrSubunit(nDestAddrSubunit, nDestAddrSubunitLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputDestSubaddress(const std::vector<unsigned char>& aDestSubaddress, const unsigned short nDestSubaddressLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDestSubaddressLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DEST_SUBADDRESS;
			if(aDestSubaddress.empty() == false){
				ByteBuffer oBuffer(aDestSubaddress);
				oBuffer.writeDump(this->m_oOutStream);
			}

			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestSubaddress(aDestSubaddress, nDestSubaddressLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputDisplayTime(const unsigned char nDisplayTime, const unsigned short nDisplayTimeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDisplayTimeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DISPLAY_TIME;
			this->m_oOutStream << (int)nDisplayTime;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDisplayTime(nDisplayTime, nDisplayTimeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputLanguageIndicator(const unsigned char nLanguageIndicator, const unsigned short nLanguageIndicatorLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nLanguageIndicatorLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::LANGUAGE_INDICATOR;
			this->m_oOutStream << (int)nLanguageIndicator;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeLanguageIndicator(nLanguageIndicator, nLanguageIndicatorLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputMessagePayload(const std::vector<unsigned char>& aMessagePayload, const unsigned short nMessagePayloadLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nMessagePayloadLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::MESSAGE_PAYLOAD;
			if(aMessagePayload.empty() == false){
				ByteBuffer oBuffer(aMessagePayload);
				oBuffer.writeDump(this->m_oOutStream);
			}
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMessagePayload(aMessagePayload, nMessagePayloadLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputMsValidity(const unsigned char nMsValidity, const unsigned short nMsValidityLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nMsValidityLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::MS_VALIDITY;
			this->m_oOutStream << (int)nMsValidity;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMsValidity(nMsValidity, nMsValidityLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputPayloadType(const unsigned char nPayloadType, const unsigned short nPayloadTypeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nPayloadTypeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::PAYLOAD_TYPE;
			this->m_oOutStream << (int)nPayloadType;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodePayloadType(nPayloadType, nPayloadTypeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputPrivacyIndicator(const unsigned char nPrivacyIndicator, const unsigned short nPrivacyIndicatorLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nPrivacyIndicatorLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::PRIVACY_INDICATOR;
			this->m_oOutStream << (int)nPrivacyIndicator;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodePrivacyIndicator(nPrivacyIndicator, nPrivacyIndicatorLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSmsSignal(const unsigned short nSmsSignal, const unsigned short nSmsSignalLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSmsSignalLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SMS_SIGNAL;
			this->m_oOutStream << nSmsSignal;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSmsSignal(nSmsSignal, nSmsSignalLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSourceAddrSubunit(const unsigned char nSourceAddrSubunit, const unsigned short nSourceAddrSubunitLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSourceAddrSubunitLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SOURCE_ADDR_SUBUNIT;
			this->m_oOutStream << (int)nSourceAddrSubunit;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceAddrSubunit(nSourceAddrSubunit, nSourceAddrSubunitLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSourcePort(const unsigned short nSourcePort, const unsigned short nSourcePortLen){

			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSourcePortLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SOURCE_PORT;
			this->m_oOutStream << nSourcePort;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourcePort(nSourcePort, nSourcePortLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress, const unsigned short nSourceSubaddressLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSourceSubaddressLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SOURCE_SUBADDRESS;
			if(aSourceSubaddress.empty() == false){
				ByteBuffer oBuffer(aSourceSubaddress);
				oBuffer.writeDump(this->m_oOutStream);
			}
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceSubaddress(aSourceSubaddress, nSourceSubaddressLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputUserMessageReference(const unsigned short nUserMessageReference, const unsigned short nUserMessageReferenceLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nUserMessageReferenceLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::USER_MESSAGE_REFERENCE;
			this->m_oOutStream << nUserMessageReference;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeUserMessageReference(nUserMessageReference, nUserMessageReferenceLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastErrorStatus(const unsigned char nBroadcastErrorStatus, const unsigned short nBroadcastErrorStatusLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastErrorStatusLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_ERROR_STATUS;
			this->m_oOutStream << (int)nBroadcastErrorStatus;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastErrorStatus(nBroadcastErrorStatus, nBroadcastErrorStatusLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){

			// Output all broadcast area identifiers
			for(unsigned i = 0; i < aBroadcastAreaIdentifier.size(); ++i){
				this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
				this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< aBroadcastAreaIdentifierLen[i];
				this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::FAILED_BROADCAST_AREA_IDENTIFIER;
				if(aBroadcastAreaIdentifier[i].getValue().empty() == false){
					ByteBuffer oBuffer(aBroadcastAreaIdentifier[i].getValue());
					oBuffer.writeDump(this->m_oOutStream);

					if(this->m_bShowFmtinfo){
						// Explain broadcast area identifier
						const char nAreaFormat = aBroadcastAreaIdentifier[i].getValue()[0];
						std::string sAreaFormatName(this->getAreaFormatName(nAreaFormat));
						this->m_oOutStream << Outputter::COMMA << (int)nAreaFormat;
						this->m_oOutStream << Outputter::EQUAL << sAreaFormatName;
					}
				}
				if(this->m_bShowHeximal){
					this->m_oEncoder.resetBuffer();
					this->m_oEncoder.encodeBroadcastAreaIdentifier(aBroadcastAreaIdentifier[i], aBroadcastAreaIdentifierLen[i]);
					this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
					this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
					ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
					oBuffer.writeDump(this->m_oOutStream);
				}
				this->m_oOutStream << std::endl;
			}

		}

		void SMPPTxtOutputter::outputBroadcastContentTypeOpt(const std::vector<unsigned char>& aBroadcastContentType, const unsigned short nBroadcastContentTypeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastContentTypeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_CONTENT_TYPE;
			if(aBroadcastContentType.empty() == false){
				ByteBuffer oBuffer(aBroadcastContentType);
				oBuffer.writeDump(this->m_oOutStream);
			}

			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastContentType(aBroadcastContentType, nBroadcastContentTypeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputSourceNetworkType(const unsigned char nSourceNetworkType, const unsigned short nSourceNetworkTypeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSourceNetworkTypeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SOURCE_NETWORK_TYPE;
			this->m_oOutStream << (int)nSourceNetworkType;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceNetworkType(nSourceNetworkType, nSourceNetworkTypeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSourceBearerType(const unsigned char nSourceBearerType, const unsigned short nSourceBearerTypeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSourceBearerTypeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SOURCE_BEARER_TYPE;
			this->m_oOutStream << (int)nSourceBearerType;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceBearerType(nSourceBearerType, nSourceBearerTypeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSourceTelematicsId(const unsigned char nSourceTelematicsId, const unsigned short nSourceTelematicsIdLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSourceTelematicsIdLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SOURCE_TELEMATICS_ID;
			this->m_oOutStream << (int)nSourceTelematicsId;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSourceTelematicsId(nSourceTelematicsId, nSourceTelematicsIdLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;


		}

		void SMPPTxtOutputter::outputDestinationPort(const unsigned short nDestinationPort, const unsigned short nDestinationPortLen){

			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDestinationPortLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DESTINATION_PORT;
			this->m_oOutStream << nDestinationPort;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestinationPort(nDestinationPort, nDestinationPortLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputDestNetworkType(const unsigned char nDestNetworkType, const unsigned short nDestNetworkTypeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDestNetworkTypeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DEST_NETWORK_TYPE;
			this->m_oOutStream << (int)nDestNetworkType;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestNetworkType(nDestNetworkType, nDestNetworkTypeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDestBearerType(const unsigned char nDestBearerType, const unsigned short nDestBearerTypeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDestBearerTypeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DEST_BEARER_TYPE;
			this->m_oOutStream << (int)nDestBearerType;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestBearerType(nDestBearerType, nDestBearerTypeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;


		}

		void SMPPTxtOutputter::outputDestTelematicsId(const unsigned char nDestTelematicsId, const unsigned short nDestTelematicsIdLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDestTelematicsIdLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DEST_TELEMATICS_ID;
			this->m_oOutStream << (int)nDestTelematicsId;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDestTelematicsId(nDestTelematicsId, nDestTelematicsIdLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSarMsgRefNum(const unsigned short nSarMsgRefNum, const unsigned short nSarMsgRefNumLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSarMsgRefNumLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SAR_MSG_REF_NUM;
			this->m_oOutStream << nSarMsgRefNum;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSarMsgRefNum(nSarMsgRefNum, nSarMsgRefNumLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSarTotalSegments(const unsigned char nSarTotalSegments, const unsigned short nSarTotalSegmentsLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSarTotalSegmentsLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SAR_TOTAL_SEGMENTS;
			this->m_oOutStream << (int)nSarTotalSegments;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSarTotalSegments(nSarTotalSegments, nSarTotalSegmentsLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum, const unsigned short nSarSegmentSeqnumLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSarSegmentSeqnumLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SAR_SEGMENT_SEQNUM;
			this->m_oOutStream << (int)nSarSegmentSeqnum;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSarSegmentSeqnum(nSarSegmentSeqnum, nSarSegmentSeqnumLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputMoreMessagesToSend(const unsigned char nMoreMessagesToSend, const unsigned short nMoreMessagesToSendLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nMoreMessagesToSendLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::MORE_MESSAGES_TO_SEND;
			this->m_oOutStream << (int)nMoreMessagesToSend;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMoreMessagesToSend(nMoreMessagesToSend, nMoreMessagesToSendLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputQosTimeToLive(const unsigned nQosTimeToLive, const unsigned short nQosTimeToLiveLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nQosTimeToLiveLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::QOS_TIME_TO_LIVE;
			this->m_oOutStream << nQosTimeToLive;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeQosTimeToLive(nQosTimeToLive, nQosTimeToLiveLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputSetDpf(const unsigned char nSetDpf, const unsigned short nSetDpfLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nSetDpfLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::SET_DPF;
			this->m_oOutStream << (int)nSetDpf;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeSetDpf(nSetDpf, nSetDpfLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputReceiptedMessageId(const std::string& sReceiptedMessageId, const unsigned short nReceiptedMessageIdLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nReceiptedMessageIdLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::RECEIPTED_MESSAGE_ID;
			this->m_oOutStream << sReceiptedMessageId;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeReceiptedMessageId(sReceiptedMessageId, nReceiptedMessageIdLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputMessageStateTLVOpt(const unsigned char nMessageState, const unsigned short nMessageStateLen){
			std::string sMessageStateName(this->getMessageStateName(nMessageState));
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nMessageStateLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::MESSAGE_STATE;
			this->m_oOutStream << (int)nMessageState << Outputter::EQUAL << sMessageStateName;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMessageStateTLV(nMessageState, nMessageStateLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode, const unsigned short nNetworkErrorCodeLen){

			std::string sNetworkName(this->getNetworkErrorName(oNetworkErrorCode.getNetworkCode()));
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nNetworkErrorCodeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::NETWORK_ERROR_CODE;
			this->m_oOutStream << (int)oNetworkErrorCode.getNetworkCode() << Outputter::EQUAL << sNetworkName;
			this->m_oOutStream << Outputter::COMMA << Outputter::SPACE << oNetworkErrorCode.getErrorCode();
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeNetworkErrorCode(oNetworkErrorCode, nNetworkErrorCodeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputMsMsgWaitFacilities(const unsigned char nMsMsgWaitFacilities, const unsigned short nMsMsgWaitFacilitiesLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nMsMsgWaitFacilitiesLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::MS_MSG_WAIT_FACILITIES;
			this->m_oOutStream << (int)nMsMsgWaitFacilities;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeMsMsgWaitFacilities(nMsMsgWaitFacilities, nMsMsgWaitFacilitiesLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;


		}

		void SMPPTxtOutputter::outputNumberOfMessages(const unsigned char nNumberOfMessages, const unsigned short nNumberOfMessagesLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nNumberOfMessagesLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::NUMBER_OF_MESSAGES;
			this->m_oOutStream << (int)nNumberOfMessages;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeNumberOfMessages(nNumberOfMessages, nNumberOfMessagesLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;



		}

		void SMPPTxtOutputter::outputItsReplyType(const unsigned char nItsReplyType, const unsigned short nItsReplyTypeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nItsReplyTypeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::ITS_REPLY_TYPE;
			this->m_oOutStream << (int)nItsReplyTypeLen;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeItsReplyType(nItsReplyType, nItsReplyTypeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputItsSessionInfo(const unsigned short nItsSessionInfo, const unsigned short nItsSessionInfoLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nItsSessionInfoLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::ITS_SESSION_INFO;
			this->m_oOutStream << nItsSessionInfo;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeItsSessionInfo(nItsSessionInfo, nItsSessionInfoLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputUserResponseCode(const unsigned char nUserResponseCode, const unsigned short nUserResponseCodeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nUserResponseCodeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::USER_RESPONSE_CODE;
			this->m_oOutStream << (int)nUserResponseCode;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeUserResponseCode(nUserResponseCode, nUserResponseCodeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputDeliveryFailureReason(const unsigned char nDeliveryFailureReason, const unsigned short nDeliveryFailureReasonLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDeliveryFailureReasonLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DELIVERY_FAILURE_REASON;
			this->m_oOutStream << (int)nDeliveryFailureReason;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDeliveryFailureReason(nDeliveryFailureReason, nDeliveryFailureReasonLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputAdditionalStatusInfoText(const std::vector<unsigned char>& aAdditionalStatusInfoText, const unsigned short nAdditionalStatusInfoTextLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nAdditionalStatusInfoTextLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::ADDITIONAL_STATUS_INFO_TEXT;
			if(aAdditionalStatusInfoText.empty() == false){
				ByteBuffer oBuffer(aAdditionalStatusInfoText);
				oBuffer.writeDump(this->m_oOutStream);
			}
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeAdditionalStatusInfoText(aAdditionalStatusInfoText, nAdditionalStatusInfoTextLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputDpfResult(const unsigned char nDpfResult, const unsigned short nDpfResultLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nDpfResultLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::DPF_RESULT;
			this->m_oOutStream << (int)nDpfResult;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeDpfResult(nDpfResult, nDpfResultLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}

		void SMPPTxtOutputter::outputBroadcastEndTime(const std::string& sBroadcastEndTime, const unsigned short nBroadcastEndTimeLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nBroadcastEndTimeLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::BROADCAST_END_TIME;
			this->m_oOutStream << sBroadcastEndTime;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastEndTime(sBroadcastEndTime, nBroadcastEndTimeLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;
		}

		void SMPPTxtOutputter::outputUssdServiceOp(const unsigned char nUssdServiceOp, const unsigned short nUssdServiceOpLen){
			this->m_oOutStream << std::setw( Outputter::WIDTH_HEADER )<< Outputter::OPTIONAL_;
			this->m_oOutStream << std::setw( Outputter::WIDTH_LENGTH )<< nUssdServiceOpLen;
			this->m_oOutStream << std::setw( Outputter::WIDTH_FLDNAME )<< FieldsName::USSD_SERVICE_OP;
			this->m_oOutStream << (int)nUssdServiceOp;
			if(this->m_bShowHeximal){
				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeUssdServiceOp(nUssdServiceOp, nUssdServiceOpLen);
				this->m_oOutStream << Outputter::SEMICOLON << Outputter::SPACE;
				this->m_oOutStream << Outputter::HEX << Outputter::EQUAL;
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << std::endl;

		}
	}
}

