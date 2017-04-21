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
#include "SMPPCSVOutputter.hpp"


namespace anthill {
	namespace smpp {


		SMPPCSVOutputter::SMPPCSVOutputter(std::ostream& oOutStream):
			SMPPOutputterBase(),
			TextOutputter(oOutStream){
		}

		SMPPCSVOutputter::SMPPCSVOutputter(std::ostream& oOutStream, const bool bShowEsm):
			SMPPOutputterBase(),
			TextOutputter(oOutStream),
			m_bShowEsminfo(bShowEsm),
			m_bShowFmtinfo(true){
		}

		SMPPCSVOutputter::SMPPCSVOutputter(std::ostream& oOutStream, const bool bShowEsm, const bool bShowFmt):
			SMPPOutputterBase(),
			TextOutputter(oOutStream),
			m_bShowEsminfo(bShowEsm),
			m_bShowFmtinfo(bShowFmt){
		}

		SMPPCSVOutputter::~SMPPCSVOutputter(){
		}

		void SMPPCSVOutputter::outputHeader(const Header& oHeader){
			std::string sCommandName(this->getCommandName(oHeader.getCommandId()));
			std::string sErrorName(this->getErrorName(oHeader.getCommandStatus()));

			// Output command lengtht
			this->m_oOutStream << Outputter::HEADER << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::COMMAND_LENGTH;
			this->m_oOutStream << Outputter::SEPARATOR << oHeader.getCommandLength();
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUnsigned32(oHeader.getCommandLength());
			ByteBuffer oBuffer1(this->m_oEncoder.refBuffer());
			oBuffer1.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

			// Output command id
			this->m_oOutStream << Outputter::HEADER << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::COMMAND_ID;
			this->m_oOutStream << Outputter::SEPARATOR << Outputter::HEXSIGN << std::hex; 
			this->m_oOutStream << oHeader.getCommandId() << std::dec << Outputter::EQUAL;
			this->m_oOutStream << sCommandName << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUnsigned32(oHeader.getCommandId());
			ByteBuffer oBuffer2(this->m_oEncoder.refBuffer());
			oBuffer2.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

			// Output command status
			this->m_oOutStream << Outputter::HEADER << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::COMMAND_STATUS;
			this->m_oOutStream << Outputter::SEPARATOR << oHeader.getCommandStatus();
			this->m_oOutStream << Outputter::EQUAL << sErrorName << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUnsigned32(oHeader.getCommandStatus());
			ByteBuffer oBuffer3(this->m_oEncoder.refBuffer());
			oBuffer3.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

			// Output sequence number
			this->m_oOutStream << Outputter::HEADER << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SEQUENCE_NUMBER;
			this->m_oOutStream << Outputter::SEPARATOR << oHeader.getSequenceNumber();
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUnsigned32(oHeader.getSequenceNumber());
			ByteBuffer oBuffer4(this->m_oEncoder.refBuffer());
			oBuffer4.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}


		void SMPPCSVOutputter::outputSystemId(const std::string& sSystemId){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SYSTEM_ID;
			this->m_oOutStream << Outputter::SEPARATOR << sSystemId;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSystemId(sSystemId);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputPassword(const std::string& sPassword){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::PASSWORD; 
			this->m_oOutStream << Outputter::SEPARATOR << sPassword;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodePassword(sPassword);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSystemType(const std::string& sSystemType){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SYSTEM_TYPE; 
			this->m_oOutStream << Outputter::SEPARATOR << sSystemType;
			this->m_oOutStream << Outputter::SEPARATOR;


			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSystemType(sSystemType);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputInterfaceVersion(const unsigned char nInterfaceVersion){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::INTERFACE_VERSION; 
			this->m_oOutStream << Outputter::SEPARATOR << Outputter::HEXSIGN << std::hex;
			this->m_oOutStream << (int)nInterfaceVersion << std::dec << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeInterfaceVersion(nInterfaceVersion);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputAddrTON(const unsigned char nAddrTON){

			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::ADDR_TON; 
			this->m_oOutStream << Outputter::SEPARATOR << (int)nAddrTON;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAddrTON(nAddrTON);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputAddrNPI(const unsigned char nAddrNPI){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::ADDR_NPI; 
			this->m_oOutStream << Outputter::SEPARATOR << (int)nAddrNPI;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAddrNPI(nAddrNPI);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputAddressRange(const std::string& sAddressRange){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::ADDRESS_RANGE;
			this->m_oOutStream << Outputter::SEPARATOR << sAddressRange;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAddressRange(sAddressRange);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputServiceType(const std::string& sServiceType){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SERVICE_TYPE;
			this->m_oOutStream << Outputter::SEPARATOR << sServiceType;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeServiceType(sServiceType);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceAddrTON(const unsigned char nSourceAddrTON){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SOURCE_ADDR_TON;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nSourceAddrTON;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddrTON(nSourceAddrTON);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceAddrNPI(const unsigned char nSourceAddrNPI){

			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SOURCE_ADDR_NPI;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nSourceAddrNPI;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddrNPI(nSourceAddrNPI);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceAddr21(const std::string& sSourceAddr){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SOURCE_ADDR;
			this->m_oOutStream << Outputter::SEPARATOR << sSourceAddr;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddr21(sSourceAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceAddr65(const std::string& sSourceAddr){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SOURCE_ADDR;
			this->m_oOutStream << Outputter::SEPARATOR << sSourceAddr;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddr65(sSourceAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestAddrTON(const unsigned char nDestAddrTON){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::DEST_ADDR_TON;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nDestAddrTON;
			this->m_oOutStream << Outputter::SEPARATOR;


			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddrTON(nDestAddrTON);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestAddrNPI(const unsigned char nDestAddrNPI){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::DEST_ADDR_NPI;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nDestAddrNPI;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddrNPI(nDestAddrNPI);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestAddr21(const std::string& sDestAddr){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::DEST_ADDR;
			this->m_oOutStream << Outputter::SEPARATOR << sDestAddr;
			this->m_oOutStream << Outputter::SEPARATOR;


			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddr21(sDestAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestAddr65(const std::string& sDestAddr){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::DEST_ADDR;
			this->m_oOutStream << Outputter::SEPARATOR << sDestAddr;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddr65(sDestAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputEsmClass(const unsigned char nEsmClass){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::ESM_CLASS;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nEsmClass ;

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

			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeEsmClass(nEsmClass);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputProtocolId(const unsigned char nProtocolId){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::PROTOCOLID;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nProtocolId ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeProtocolId(nProtocolId);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputPriorityFlag(const unsigned char nPriorityFlag){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::PRIORITY_FLAG;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nPriorityFlag ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodePriorityFlag(nPriorityFlag);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputScheduleDeliveryTime(const std::string& sScheduleDeliveryTime){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SCHEDULE_DELIVERY_TIME;
			this->m_oOutStream << Outputter::SEPARATOR << sScheduleDeliveryTime ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeScheduleDeliveryTime(sScheduleDeliveryTime);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputValidityPeriod(const std::string& sValidityPeriod){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::VALIDITY_PERIOD;
			this->m_oOutStream << Outputter::SEPARATOR << sValidityPeriod ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeValidityPeriod(sValidityPeriod);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputRegisteredDelivery(const unsigned char nRegisteredDelivery){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::REGISTERED_DELIVERY;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nRegisteredDelivery ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeRegisteredDelivery(nRegisteredDelivery);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputReplaceIfPresentFlag(const unsigned char nReplaceIfPresentFlag){

			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::REPLACE_IF_PRESENT;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nReplaceIfPresentFlag ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeReplaceIfPresentFlag(nReplaceIfPresentFlag);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDataCoding(const unsigned char nDataCoding){

			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::DATA_CODING;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nDataCoding ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDataCoding(nDataCoding);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSMDefaultMsgId(const unsigned char nSMDefaultMsgId){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SM_DEFAULT_MSG_ID;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nSMDefaultMsgId ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSMDefaultMsgId(nSMDefaultMsgId);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSMLength(const unsigned char nSMLength){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SM_LENGTH;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nSMLength ;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSMLength(nSMLength);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputShortMessage(std::vector<unsigned char>& aShortMessage){
			
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::SHORT_MESSAGE;
			this->m_oOutStream << Outputter::SEPARATOR;
			if(aShortMessage.empty() == false){
				ByteBuffer oBuffer(aShortMessage);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;


			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeShortMessage(aShortMessage);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputMessageId(const std::string& sMessageId){

			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::MESSAGE_ID;
			this->m_oOutStream << Outputter::SEPARATOR << sMessageId;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessageId(sMessageId);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputESMEAddrTON(const unsigned char nESMEAddrTON){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::ESME_ADDR_TON;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nESMEAddrTON;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeESMEAddrTON(nESMEAddrTON);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputESMEAddrNPI(const unsigned char nESMEAddrNPI){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::ESME_ADDR_NPI;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nESMEAddrNPI;
			this->m_oOutStream << Outputter::SEPARATOR;


			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeESMEAddrNPI(nESMEAddrNPI);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputESMEAddr(const std::string& sESMEAddr){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::ESME_ADDR;
			this->m_oOutStream << Outputter::SEPARATOR << sESMEAddr;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeESMEAddr(sESMEAddr);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputNumberOfDest(const unsigned char nNumberOfDest){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::NUMBER_OF_DEST;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nNumberOfDest;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeNumberOfDest(nNumberOfDest);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestAddresses(const std::vector<DestAddress>& aDestAddresses){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::DEST_ADDRESSES;
			this->m_oOutStream << Outputter::SEPARATOR;

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
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddresses(aDestAddresses);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputNoUnsuccess(const unsigned char nNoUnsuccess){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::NO_UNSUCCESS;
			this->m_oOutStream << Outputter::SEPARATOR << (int)nNoUnsuccess;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeNoUnsuccess(nNoUnsuccess);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputUnsuccessSMEs(const std::vector<UnsuccessSME>& aUnsuccessSMEs){

			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::UNSUCCESS_SMES;
			this->m_oOutStream << Outputter::SEPARATOR;

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
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUnsuccessSMEs(aUnsuccessSMEs);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputFinalDate(const std::string& sFinalDate){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::FINAL_DATE; 
			this->m_oOutStream << Outputter::SEPARATOR << sFinalDate;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeFinalDate(sFinalDate);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputMessageState(const unsigned char nMessageState){
			std::string sMessageStateName(this->getMessageStateName(nMessageState));
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::MESSAGE_STATE; 
			this->m_oOutStream << Outputter::SEPARATOR << (int)nMessageState;
			this->m_oOutStream << Outputter::EQUAL << sMessageStateName;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessageState(nMessageState);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputMessageStateTLV(const unsigned char nMessageState, const unsigned short nMessageStateLen){
			std::string sMessageStateName(this->getMessageStateName(nMessageState));
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << nMessageStateLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::MESSAGE_STATE << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nMessageState << Outputter::EQUAL;
			this->m_oOutStream << sMessageStateName << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessageState(nMessageState);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputErrorCode(const unsigned char nErrorCode){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::SEPARATOR << FieldsName::ERROR_CODE; 
			this->m_oOutStream << Outputter::SEPARATOR << (int)nErrorCode;
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeErrorCode(nErrorCode);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){

			// Output all broadcast area identifiers
			for(unsigned i = 0; i < aBroadcastAreaIdentifier.size(); ++i){
				this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
				this->m_oOutStream << aBroadcastAreaIdentifierLen[i] << Outputter::SEPARATOR;
				this->m_oOutStream << FieldsName::BROADCAST_AREA_IDENTIFIER << Outputter::SEPARATOR;

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

				this->m_oOutStream << Outputter::SEPARATOR;

				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastAreaIdentifier(aBroadcastAreaIdentifier[i], aBroadcastAreaIdentifierLen[i]);
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
				this->m_oOutStream << std::endl;
			}
		}

		void SMPPCSVOutputter::outputBroadcastRepNum(const unsigned short nBroadcastRepNum, const unsigned short nBroadcastRepNumLen){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastRepNumLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_REP_NUM << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastRepNum << Outputter::SEPARATOR;
			

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastRepNum(nBroadcastRepNum, nBroadcastRepNumLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputBroadcastFrequencyInterval(const std::vector<unsigned char>& aBroadcastFrequencyInterval, const unsigned short nBroadcastFrequencyIntervalLen){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastFrequencyIntervalLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_FREQUENCY_INTERVAL << Outputter::SEPARATOR;
			if(aBroadcastFrequencyInterval.empty() == false){
				ByteBuffer oBuffer(aBroadcastFrequencyInterval);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastFrequencyInterval(aBroadcastFrequencyInterval, nBroadcastFrequencyIntervalLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputBroadcastContentType(const std::vector<unsigned char>& aBroadcastContentType, const unsigned short nBroadcastContentTypeLen){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastContentTypeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_CONTENT_TYPE << Outputter::SEPARATOR;
			if(aBroadcastContentType.empty() == false){
				ByteBuffer oBuffer(aBroadcastContentType);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastContentType(aBroadcastContentType, nBroadcastContentTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputBroadcastAreaSuccess(const unsigned char nBroadcastAreaSuccess, const unsigned short nBroadcastAreaSuccessLen){
			this->m_oOutStream << Outputter::MANDATORY << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastAreaSuccessLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_AREA_SUCCESS << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nBroadcastAreaSuccess<< Outputter::SEPARATOR;

			// Show hex dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastAreaSuccess(nBroadcastAreaSuccess, nBroadcastAreaSuccessLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputScInterfaceVersion(const unsigned char nScInterfaceVersion, const unsigned short nScInterfaceVersionLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nScInterfaceVersionLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SC_INTERFACE_VERSION << Outputter::SEPARATOR;
			this->m_oOutStream << Outputter::HEXSIGN << std::hex << (int)nScInterfaceVersion;
			this->m_oOutStream << std::dec << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeScInterfaceVersion(nScInterfaceVersion, nScInterfaceVersionLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputMSAvailabilityStatus(const unsigned char nMSAvailabilityStatus, const unsigned short nMSAvailabilityStatusLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nMSAvailabilityStatusLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::MS_AVAILABILITY_STATUS << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nMSAvailabilityStatus << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMSAvailabilityStatus(nMSAvailabilityStatus, nMSAvailabilityStatusLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputAlertOnMsgDelivery(const unsigned char nAlertOnMsgDelivery, const unsigned short nAlertOnMsgDeliveryLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nAlertOnMsgDeliveryLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::ALERT_ON_MSG_DELIVERY << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nAlertOnMsgDelivery << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAlertOnMsgDelivery(nAlertOnMsgDelivery, nAlertOnMsgDeliveryLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputBroadcastChannelIndicator(const unsigned char nBroadcastChannelIndicator, const unsigned short nBroadcastChannelIndicatorLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastChannelIndicatorLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_CHANNEL_INDICATOR << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nBroadcastChannelIndicator << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastChannelIndicator(nBroadcastChannelIndicator, nBroadcastChannelIndicatorLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputBroadcastContentTypeInfo(const std::vector<unsigned char>& aBroadcastContentTypeInfo, const unsigned short nBroadcastContentTypeInfoLen){
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastContentTypeInfoLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_CONTENT_TYPE_INFO << Outputter::SEPARATOR;
			if(aBroadcastContentTypeInfo.empty() == false){
				ByteBuffer oBuffer(aBroadcastContentTypeInfo);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastContentTypeInfo(aBroadcastContentTypeInfo, nBroadcastContentTypeInfoLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputBroadcastMessageClass(const unsigned char nBroadcastMessageClass, const unsigned short nBroadcastMessageClassLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastMessageClassLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_MESSAGE_CLASS << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nBroadcastMessageClass << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastMessageClass(nBroadcastMessageClass, nBroadcastMessageClassLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputBroadcastServiceGroup(const std::vector<unsigned char>& aBroadcastServiceGroup, const unsigned short nBroadcastServiceGroupLen){
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastServiceGroupLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_SERVICE_GROUP << Outputter::SEPARATOR;
			if(aBroadcastServiceGroup.empty() == false){
				ByteBuffer oBuffer(aBroadcastServiceGroup);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastServiceGroup(aBroadcastServiceGroup, nBroadcastServiceGroupLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputCallbackNum(const std::vector<unsigned char>& aCallbackNum, const unsigned short nCallbackNumLen){
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nCallbackNumLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::CALLBACK_NUM << Outputter::SEPARATOR;
			if(aCallbackNum.empty() == false){
				ByteBuffer oBuffer(aCallbackNum);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeCallbackNum(aCallbackNum, nCallbackNumLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputCallbackNumAtag(const std::vector<unsigned char>& aCallbackNumAtag, const unsigned short nCallbackNumAtagLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nCallbackNumAtagLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::CALLBACK_NUM_ATAG << Outputter::SEPARATOR;
			if(aCallbackNumAtag.empty() == false){
				ByteBuffer oBuffer(aCallbackNumAtag);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeCallbackNumAtag(aCallbackNumAtag, nCallbackNumAtagLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputCallbackNumPresInd(const unsigned char nCallbackNumPresInd, const unsigned short nCallbackNumPresIndLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nCallbackNumPresIndLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::CALLBACK_NUM_PRES_IND << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nCallbackNumPresInd << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeCallbackNumPresInd(nCallbackNumPresInd, nCallbackNumPresIndLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestAddrSubunit(const unsigned char nDestAddrSubunit, const unsigned short nDestAddrSubunitLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDestAddrSubunitLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DEST_ADDR_SUBUNIT << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nDestAddrSubunit << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestAddrSubunit(nDestAddrSubunit, nDestAddrSubunitLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestSubaddress(const std::vector<unsigned char>& aDestSubaddress, const unsigned short nDestSubaddressLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDestSubaddressLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DEST_SUBADDRESS << Outputter::SEPARATOR;
			if(aDestSubaddress.empty() == false){
				ByteBuffer oBuffer(aDestSubaddress);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestSubaddress(aDestSubaddress, nDestSubaddressLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputDisplayTime(const unsigned char nDisplayTime, const unsigned short nDisplayTimeLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDisplayTimeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DISPLAY_TIME << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nDisplayTime << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDisplayTime(nDisplayTime, nDisplayTimeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputLanguageIndicator(const unsigned char nLanguageIndicator, const unsigned short nLanguageIndicatorLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nLanguageIndicatorLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::LANGUAGE_INDICATOR << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nLanguageIndicator << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeLanguageIndicator(nLanguageIndicator, nLanguageIndicatorLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputMessagePayload(const std::vector<unsigned char>& aMessagePayload, const unsigned short nMessagePayloadLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nMessagePayloadLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::MESSAGE_PAYLOAD << Outputter::SEPARATOR;
			if(aMessagePayload.empty() == false){
				ByteBuffer oBuffer(aMessagePayload);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessagePayload(aMessagePayload, nMessagePayloadLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputMsValidity(const unsigned char nMsValidity, const unsigned short nMsValidityLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nMsValidityLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::MS_VALIDITY << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nMsValidity << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMsValidity(nMsValidity, nMsValidityLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputPayloadType(const unsigned char nPayloadType, const unsigned short nPayloadTypeLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nPayloadTypeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::PAYLOAD_TYPE << Outputter::SEPARATOR;
			this->m_oOutStream << (int) nPayloadType << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodePayloadType(nPayloadType, nPayloadTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputPrivacyIndicator(const unsigned char nPrivacyIndicator, const unsigned short nPrivacyIndicatorLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nPrivacyIndicatorLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::PRIVACY_INDICATOR << Outputter::SEPARATOR;
			this->m_oOutStream << (int) nPrivacyIndicator << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodePrivacyIndicator(nPrivacyIndicator, nPrivacyIndicatorLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSmsSignal(const unsigned short nSmsSignal, const unsigned short nSmsSignalLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSmsSignalLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SMS_SIGNAL << Outputter::SEPARATOR;
			this->m_oOutStream << nSmsSignal << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSmsSignal(nSmsSignal, nSmsSignalLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceAddrSubunit(const unsigned char nSourceAddrSubunit, const unsigned short nSourceAddrSubunitLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSourceAddrSubunitLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SOURCE_ADDR_SUBUNIT << Outputter::SEPARATOR;
			this->m_oOutStream << (int) nSourceAddrSubunit << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceAddrSubunit(nSourceAddrSubunit, nSourceAddrSubunitLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourcePort(const unsigned short nSourcePort, const unsigned short nSourcePortLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSourcePortLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SOURCE_PORT << Outputter::SEPARATOR;
			this->m_oOutStream << nSourcePort << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourcePort(nSourcePort, nSourcePortLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceSubaddress(const std::vector<unsigned char>& aSourceSubaddress, const unsigned short nSourceSubaddressLen){
		
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSourceSubaddressLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SOURCE_SUBADDRESS << Outputter::SEPARATOR;
			if(aSourceSubaddress.empty() == false){
				ByteBuffer oBuffer(aSourceSubaddress);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceSubaddress(aSourceSubaddress, nSourceSubaddressLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputUserMessageReference(const unsigned short nUserMessageReference, const unsigned short nUserMessageReferenceLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nUserMessageReferenceLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::USER_MESSAGE_REFERENCE << Outputter::SEPARATOR;
			this->m_oOutStream << nUserMessageReference << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUserMessageReference(nUserMessageReference, nUserMessageReferenceLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputBroadcastErrorStatus(const unsigned char nBroadcastErrorStatus, const unsigned short nBroadcastErrorStatusLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastErrorStatusLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_ERROR_STATUS << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nBroadcastErrorStatus << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastErrorStatus(nBroadcastErrorStatus, nBroadcastErrorStatusLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputFailedBroadcastAreaIdentifier(const std::vector<BroadcastAreaIdentifier>& aBroadcastAreaIdentifier, const std::vector<unsigned short>& aBroadcastAreaIdentifierLen){
			// Output all broadcast area identifiers
			for(unsigned i = 0; i < aBroadcastAreaIdentifier.size(); ++i){
				this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
				this->m_oOutStream << aBroadcastAreaIdentifierLen[i] << Outputter::SEPARATOR;
				this->m_oOutStream << FieldsName::FAILED_BROADCAST_AREA_IDENTIFIER << Outputter::SEPARATOR;

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

				this->m_oOutStream << Outputter::SEPARATOR;

				this->m_oEncoder.resetBuffer();
				this->m_oEncoder.encodeBroadcastAreaIdentifier(aBroadcastAreaIdentifier[i], aBroadcastAreaIdentifierLen[i]);
				ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
				oBuffer.writeDump(this->m_oOutStream);
				this->m_oOutStream << std::endl;
			}			
		}

		void SMPPCSVOutputter::outputBroadcastContentTypeOpt(const std::vector<unsigned char>& aBroadcastContentType, const unsigned short nBroadcastContentTypeLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastContentTypeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_CONTENT_TYPE << Outputter::SEPARATOR;
			if(aBroadcastContentType.empty() == false){
				ByteBuffer oBuffer(aBroadcastContentType);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastContentType(aBroadcastContentType, nBroadcastContentTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceNetworkType(const unsigned char nSourceNetworkType, const unsigned short nSourceNetworkTypeLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSourceNetworkTypeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SOURCE_NETWORK_TYPE << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nSourceNetworkType << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceNetworkType(nSourceNetworkType, nSourceNetworkTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceBearerType(const unsigned char nSourceBearerType, const unsigned short nSourceBearerTypeLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSourceBearerTypeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SOURCE_BEARER_TYPE << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nSourceBearerType << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceBearerType(nSourceBearerType, nSourceBearerTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSourceTelematicsId(const unsigned char nSourceTelematicsId, const unsigned short nSourceTelematicsIdLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSourceTelematicsIdLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SOURCE_TELEMATICS_ID << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nSourceTelematicsId << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSourceTelematicsId(nSourceTelematicsId, nSourceTelematicsIdLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputDestinationPort(const unsigned short nDestinationPort, const unsigned short nDestinationPortLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDestinationPortLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DESTINATION_PORT << Outputter::SEPARATOR;
			this->m_oOutStream << nDestinationPort << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestinationPort(nDestinationPort, nDestinationPortLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestNetworkType(const unsigned char nDestNetworkType, const unsigned short nDestNetworkTypeLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDestNetworkTypeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DEST_NETWORK_TYPE << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nDestNetworkType << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestNetworkType(nDestNetworkType, nDestNetworkTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDestBearerType(const unsigned char nDestBearerType, const unsigned short nDestBearerTypeLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDestBearerTypeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DEST_BEARER_TYPE << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nDestBearerType << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestBearerType(nDestBearerType, nDestBearerTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputDestTelematicsId(const unsigned char nDestTelematicsId, const unsigned short nDestTelematicsIdLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDestTelematicsIdLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DEST_TELEMATICS_ID << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nDestTelematicsId << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDestTelematicsId(nDestTelematicsId, nDestTelematicsIdLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSarMsgRefNum(const unsigned short nSarMsgRefNum, const unsigned short nSarMsgRefNumLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSarMsgRefNumLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SAR_MSG_REF_NUM << Outputter::SEPARATOR;
			this->m_oOutStream << nSarMsgRefNum << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSarMsgRefNum(nSarMsgRefNum, nSarMsgRefNumLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSarTotalSegments(const unsigned char nSarTotalSegments, const unsigned short nSarTotalSegmentsLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSarTotalSegmentsLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SAR_TOTAL_SEGMENTS << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nSarTotalSegments << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSarTotalSegments(nSarTotalSegments, nSarTotalSegmentsLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSarSegmentSeqnum(const unsigned char nSarSegmentSeqnum, const unsigned short nSarSegmentSeqnumLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSarSegmentSeqnumLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SAR_SEGMENT_SEQNUM << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nSarSegmentSeqnum << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSarSegmentSeqnum(nSarSegmentSeqnum, nSarSegmentSeqnumLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputMoreMessagesToSend(const unsigned char nMoreMessagesToSend, const unsigned short nMoreMessagesToSendLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nMoreMessagesToSendLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::MORE_MESSAGES_TO_SEND << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nMoreMessagesToSend << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMoreMessagesToSend(nMoreMessagesToSend, nMoreMessagesToSendLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputQosTimeToLive(const unsigned nQosTimeToLive, const unsigned short nQosTimeToLiveLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nQosTimeToLiveLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::QOS_TIME_TO_LIVE << Outputter::SEPARATOR;
			this->m_oOutStream << nQosTimeToLive << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeQosTimeToLive(nQosTimeToLive, nQosTimeToLiveLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputSetDpf(const unsigned char nSetDpf, const unsigned short nSetDpfLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nSetDpfLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::SET_DPF << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nSetDpf << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeSetDpf(nSetDpf, nSetDpfLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputReceiptedMessageId(const std::string& sReceiptedMessageId, const unsigned short nReceiptedMessageIdLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nReceiptedMessageIdLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::RECEIPTED_MESSAGE_ID << Outputter::SEPARATOR;
			this->m_oOutStream << sReceiptedMessageId << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeReceiptedMessageId(sReceiptedMessageId, nReceiptedMessageIdLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputMessageStateTLVOpt(const unsigned char nMessageState, const unsigned short nMessageStateLen){
			std::string sMessageStateName(this->getMessageStateName(nMessageState));
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nMessageStateLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::MESSAGE_STATE << Outputter::SEPARATOR;
			this->m_oOutStream << (int) nMessageState << Outputter::EQUAL ;
			this->m_oOutStream << sMessageStateName << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMessageStateTLV(nMessageState, nMessageStateLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputNetworkErrorCode(const NetworkErrorCode& oNetworkErrorCode, const unsigned short nNetworkErrorCodeLen){

			std::string sNetworkName(this->getNetworkErrorName(oNetworkErrorCode.getNetworkCode()));
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nNetworkErrorCodeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::NETWORK_ERROR_CODE << Outputter::SEPARATOR;
			this->m_oOutStream << (int)oNetworkErrorCode.getNetworkCode() << Outputter::EQUAL << sNetworkName;
			this->m_oOutStream << Outputter::COMMA << Outputter::SPACE << oNetworkErrorCode.getErrorCode();
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeNetworkErrorCode(oNetworkErrorCode, nNetworkErrorCodeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputMsMsgWaitFacilities(const unsigned char nMsMsgWaitFacilities, const unsigned short nMsMsgWaitFacilitiesLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nMsMsgWaitFacilitiesLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::MS_MSG_WAIT_FACILITIES << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nMsMsgWaitFacilities << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeMsMsgWaitFacilities(nMsMsgWaitFacilities, nMsMsgWaitFacilitiesLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputNumberOfMessages(const unsigned char nNumberOfMessages, const unsigned short nNumberOfMessagesLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nNumberOfMessagesLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::NUMBER_OF_MESSAGES << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nNumberOfMessages << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeNumberOfMessages(nNumberOfMessages, nNumberOfMessagesLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputItsReplyType(const unsigned char nItsReplyType, const unsigned short nItsReplyTypeLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nItsReplyTypeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::ITS_REPLY_TYPE << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nItsReplyType << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeItsReplyType(nItsReplyType, nItsReplyTypeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputItsSessionInfo(const unsigned short nItsSessionInfo, const unsigned short nItsSessionInfoLen){
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nItsSessionInfoLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::ITS_SESSION_INFO << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nItsSessionInfo << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeItsSessionInfo(nItsSessionInfo, nItsSessionInfoLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputUserResponseCode(const unsigned char nUserResponseCode, const unsigned short nUserResponseCodeLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nUserResponseCodeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::USER_RESPONSE_CODE << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nUserResponseCode << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUserResponseCode(nUserResponseCode, nUserResponseCodeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDeliveryFailureReason(const unsigned char nDeliveryFailureReason, const unsigned short nDeliveryFailureReasonLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDeliveryFailureReasonLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DELIVERY_FAILURE_REASON << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nDeliveryFailureReason << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDeliveryFailureReason(nDeliveryFailureReason, nDeliveryFailureReasonLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputAdditionalStatusInfoText(const std::vector<unsigned char>& aAdditionalStatusInfoText, const unsigned short nAdditionalStatusInfoTextLen){
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nAdditionalStatusInfoTextLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::ADDITIONAL_STATUS_INFO_TEXT << Outputter::SEPARATOR;
			if(aAdditionalStatusInfoText.empty() == false){
				ByteBuffer oBuffer(aAdditionalStatusInfoText);
				oBuffer.writeDump(this->m_oOutStream);
			}
			this->m_oOutStream << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeAdditionalStatusInfoText(aAdditionalStatusInfoText, nAdditionalStatusInfoTextLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputDpfResult(const unsigned char nDpfResult, const unsigned short nDpfResultLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nDpfResultLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::DPF_RESULT << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nDpfResult << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeDpfResult(nDpfResult, nDpfResultLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;

		}

		void SMPPCSVOutputter::outputBroadcastEndTime(const std::string& sBroadcastEndTime, const unsigned short nBroadcastEndTimeLen){

			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nBroadcastEndTimeLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::BROADCAST_END_TIME << Outputter::SEPARATOR;
			this->m_oOutStream << sBroadcastEndTime << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeBroadcastEndTime(sBroadcastEndTime, nBroadcastEndTimeLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}

		void SMPPCSVOutputter::outputUssdServiceOp(const unsigned char nUssdServiceOp, const unsigned short nUssdServiceOpLen){
			
			this->m_oOutStream << Outputter::OPTIONAL_ << Outputter::SEPARATOR;
			this->m_oOutStream << nUssdServiceOpLen << Outputter::SEPARATOR;
			this->m_oOutStream << FieldsName::USSD_SERVICE_OP << Outputter::SEPARATOR;
			this->m_oOutStream << (int)nUssdServiceOp << Outputter::SEPARATOR;

			// Show dump
			this->m_oEncoder.resetBuffer();
			this->m_oEncoder.encodeUssdServiceOp(nUssdServiceOp, nUssdServiceOpLen);
			ByteBuffer oBuffer(this->m_oEncoder.refBuffer());
			oBuffer.writeDump(this->m_oOutStream);
			this->m_oOutStream << std::endl;
		}


	}
}

