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
#include "SMPPOutputterBase.hpp"


namespace anthill {
	namespace smpp {

		SMPPOutputterBase::SMPPOutputterBase(){
		}


		SMPPOutputterBase::~SMPPOutputterBase(){
		}

		std::string SMPPOutputterBase::getCommandName(const unsigned nCommandId){
			switch(nCommandId){
				case CommandId::CM_GENERIC_NACK:{
					return CommandName::CM_GENERIC_NACK;
				}
				case CommandId::CM_BIND_RECEIVER:{
					return CommandName::CM_BIND_RECEIVER;
				}
				case CommandId::CM_BIND_RECEIVER_RESP:{
					return CommandName::CM_BIND_RECEIVER_RESP;
				}
				case CommandId::CM_BIND_TRANSMITTER:{
					return CommandName::CM_BIND_TRANSMITTER;
				}
				case CommandId::CM_BIND_TRANSMITTER_RESP:{
					return CommandName::CM_BIND_TRANSMITTER_RESP;
				}
				case CommandId::CM_QUERY_SM:{
					return CommandName::CM_QUERY_SM;
				}
				case CommandId::CM_QUERY_SM_RESP:{
					return CommandName::CM_QUERY_SM_RESP;
				}
				case CommandId::CM_SUBMIT_SM:{
					return CommandName::CM_SUBMIT_SM;
				}
				case CommandId::CM_SUBMIT_SM_RESP:{
					return CommandName::CM_SUBMIT_SM_RESP;
				}
				case CommandId::CM_DELIVER_SM:{
					return CommandName::CM_DELIVER_SM;
				}
				case CommandId::CM_DELIVER_SM_RESP:{
					return CommandName::CM_DELIVER_SM_RESP;
				}
				case CommandId::CM_UNBIND:{
					return CommandName::CM_UNBIND;
				}
				case CommandId::CM_UNBIND_RESP:{
					return CommandName::CM_UNBIND_RESP;
				}
				case CommandId::CM_REPLACE_SM:{
					return CommandName::CM_REPLACE_SM;
				}
				case CommandId::CM_REPLACE_SM_RESP:{
					return CommandName::CM_REPLACE_SM_RESP;
				}
				case CommandId::CM_CANCEL_SM:{
					return CommandName::CM_CANCEL_SM;
				}
				case CommandId::CM_CANCEL_SM_RESP:{
					return CommandName::CM_CANCEL_SM_RESP;
				}
				case CommandId::CM_BIND_TRANSCEIVER:{
					return CommandName::CM_BIND_TRANSCEIVER;
				}
				case CommandId::CM_BIND_TRANSCEIVER_RESP:{
					return CommandName::CM_BIND_TRANSCEIVER_RESP;
				}
				case CommandId::CM_OUTBIND:{
					return CommandName::CM_OUTBIND;
				}
				case CommandId::CM_ENQUIRE_LINK:{
					return CommandName::CM_ENQUIRE_LINK;
				}
				case CommandId::CM_ENQUIRE_LINK_RESP:{
					return CommandName::CM_ENQUIRE_LINK_RESP;
				}
				case CommandId::CM_SUBMIT_MULTI:{
					return CommandName::CM_SUBMIT_MULTI;
				}
				case CommandId::CM_SUBMIT_MULTI_RESP:{
					return CommandName::CM_SUBMIT_MULTI_RESP;
				}
				case CommandId::CM_ALERT_NOTIFICATION:{
					return CommandName::CM_ALERT_NOTIFICATION;
				}
				case CommandId::CM_DATA_SM:{
					return CommandName::CM_DATA_SM;
				}
				case CommandId::CM_DATA_SM_RESP:{
					return CommandName::CM_DATA_SM_RESP;
				}
				case CommandId::CM_BROADCAST_SM:{
					return CommandName::CM_BROADCAST_SM;
				}
				case CommandId::CM_BROADCAST_SM_RESP:{
					return CommandName::CM_BROADCAST_SM_RESP;
				}
				case CommandId::CM_QUERY_BROADCAST_SM:{
					return CommandName::CM_QUERY_BROADCAST_SM;
				}
				case CommandId::CM_QUERY_BROADCAST_SM_RESP:{
					return CommandName::CM_QUERY_BROADCAST_SM_RESP;
				}
				case CommandId::CM_CANCEL_BROADCAST_SM:{
					return CommandName::CM_CANCEL_BROADCAST_SM;
				}
				case CommandId::CM_CANCEL_BROADCAST_SM_RESP:{
					return CommandName::CM_CANCEL_BROADCAST_SM_RESP;
				}
				default:{
					return std::string("Unknown command id");
				}
			}
		}

		std::string SMPPOutputterBase::getErrorName(const unsigned nErrorCode){
			switch(nErrorCode){
				case ErrorCode::ESME_ROK:{
					return ErrorName::ESME_ROK;
				}
				case ErrorCode::ESME_RINVMSGLEN:{
					return ErrorName::ESME_RINVMSGLEN;
				}
				case ErrorCode::ESME_RINVCMDLEN:{
					return ErrorName::ESME_RINVCMDLEN;
				}
				case ErrorCode::ESME_RINVCMDID:{
					return ErrorName::ESME_RINVCMDID;
				}
				case ErrorCode::ESME_RINVBNDSTS:{
					return ErrorName::ESME_RINVBNDSTS;
				}
				case ErrorCode::ESME_RALYBND:{
					return ErrorName::ESME_RALYBND;
				}
				case ErrorCode::ESME_RINVPRTFLG:{
					return ErrorName::ESME_RINVPRTFLG;
				}
				case ErrorCode::ESME_RINVREGDLVFLG:{
					return ErrorName::ESME_RINVREGDLVFLG;
				}
				case ErrorCode::ESME_RSYSERR:{
					return ErrorName::ESME_RSYSERR;
				}
				case ErrorCode::ESME_RINVSRCADR:{
					return ErrorName::ESME_RINVSRCADR;
				}
				case ErrorCode::ESME_RINVDSTADR:{
					return ErrorName::ESME_RINVDSTADR;
				}
				case ErrorCode::ESME_RINVMSGID:{
					return ErrorName::ESME_RINVMSGID;
				}
				case ErrorCode::ESME_RBINDFAIL:{
					return ErrorName::ESME_RBINDFAIL;
				}
				case ErrorCode::ESME_RINVPASWD:{
					return ErrorName::ESME_RINVPASWD;
				}
				case ErrorCode::ESME_RINVSYSID:{
					return ErrorName::ESME_RINVSYSID;
				}
				case ErrorCode::ESME_RCANCELFAIL:{
					return ErrorName::ESME_RCANCELFAIL;
				}
				case ErrorCode::ESME_RREPLACEFAIL:{
					return ErrorName::ESME_RREPLACEFAIL;
				}
				case ErrorCode::ESME_RMSGQFUL:{
					return ErrorName::ESME_RMSGQFUL;
				}
				case ErrorCode::ESME_RINVSERTYP:{
					return ErrorName::ESME_RINVSERTYP;
				}
				case ErrorCode::ESME_RINVNUMDESTS:{
					return ErrorName::ESME_RINVNUMDESTS;
				}
				case ErrorCode::ESME_RINVDLNAME:{
					return ErrorName::ESME_RINVDLNAME;
				}
				case ErrorCode::ESME_RINVDESTFLAG:{
					return ErrorName::ESME_RINVDESTFLAG;
				}
				case ErrorCode::ESME_RINVSUBREP:{
					return ErrorName::ESME_RINVSUBREP;
				}
				case ErrorCode::ESME_RINVESMCLASS:{
					return ErrorName::ESME_RINVESMCLASS;
				}
				case ErrorCode::ESME_RCNTSUBDL:{
					return ErrorName::ESME_RCNTSUBDL;
				}
				case ErrorCode::ESME_RSUBMITFAIL:{
					return ErrorName::ESME_RSUBMITFAIL;
				}
				case ErrorCode::ESME_RINVSRCTON:{
					return ErrorName::ESME_RINVSRCTON;
				}
				case ErrorCode::ESME_RINVSRCNPI:{
					return ErrorName::ESME_RINVSRCNPI;
				}
				case ErrorCode::ESME_RINVDSTTON:{
					return ErrorName::ESME_RINVDSTTON;
				}
				case ErrorCode::ESME_RINVDSTNPI:{
					return ErrorName::ESME_RINVDSTNPI;
				}
				case ErrorCode::ESME_RINVSYSTYP:{
					return ErrorName::ESME_RINVSYSTYP;
				}
				case ErrorCode::ESME_RINVREPFLAG:{
					return ErrorName::ESME_RINVREPFLAG;
				}
				case ErrorCode::ESME_RINVNUMMSGS:{
					return ErrorName::ESME_RINVNUMMSGS;
				}
				case ErrorCode::ESME_RTHROTTLED:{
					return ErrorName::ESME_RTHROTTLED;
				}
				case ErrorCode::ESME_RINVSCHED:{
					return ErrorName::ESME_RINVSCHED;
				}
				case ErrorCode::ESME_RINVEXPIRY:{
					return ErrorName::ESME_RINVEXPIRY;
				}
				case ErrorCode::ESME_RINVDFTMSGID:{
					return ErrorName::ESME_RINVDFTMSGID;
				}
				case ErrorCode::ESME_RX_T_APPN:{
					return ErrorName::ESME_RX_T_APPN;
				}
				case ErrorCode::ESME_RX_P_APPN:{
					return ErrorName::ESME_RX_P_APPN;
				}
				case ErrorCode::ESME_RX_R_APPN:{
					return ErrorName::ESME_RX_R_APPN;
				}
				case ErrorCode::ESME_RQUERYFAIL:{
					return ErrorName::ESME_RQUERYFAIL;
				}
				case ErrorCode::ESME_RINVOPTPARSTREAM:{
					return ErrorName::ESME_RINVOPTPARSTREAM;
				}
				case ErrorCode::ESME_ROPTPARNOTALLWD:{
					return ErrorName::ESME_ROPTPARNOTALLWD;
				}
				case ErrorCode::ESME_RINVPARLEN:{
					return ErrorName::ESME_RINVPARLEN;
				}
				case ErrorCode::ESME_RMISSINGOPTPARAM:{
					return ErrorName::ESME_RMISSINGOPTPARAM;
				}
				case ErrorCode::ESME_RINVOPTPARAMVAL:{
					return ErrorName::ESME_RINVOPTPARAMVAL;
				}
				case ErrorCode::ESME_RDELIVERYFAILURE:{
					return ErrorName::ESME_RDELIVERYFAILURE;
				}
				case ErrorCode::ESME_RUNKNOWNERR:{
					return ErrorName::ESME_RUNKNOWNERR;
				}
				case ErrorCode::ESME_RSERTYPUNAUTH:{
					return ErrorName::ESME_RSERTYPUNAUTH;
				}
				case ErrorCode::ESME_RPROHIBITED:{
					return ErrorName::ESME_RPROHIBITED;
				}
				case ErrorCode::ESME_RSERTYPUNAVAIL:{
					return ErrorName::ESME_RSERTYPUNAVAIL;
				}
				case ErrorCode::ESME_RSERTYPDENIED:{
					return ErrorName::ESME_RSERTYPDENIED;
				}
				case ErrorCode::ESME_RINVDCS:{
					return ErrorName::ESME_RINVDCS;
				}
				case ErrorCode::ESME_RINVSRCADDRSUBUNIT:{
					return ErrorName::ESME_RINVSRCADDRSUBUNIT;
				}
				case ErrorCode::ESME_RINVDSTADDRSUBUNIT:{
					return ErrorName::ESME_RINVDSTADDRSUBUNIT;
				}
				case ErrorCode::ESME_RINVBCASTFREQINT:{
					return ErrorName::ESME_RINVBCASTFREQINT;
				}
				case ErrorCode::ESME_RINVBCASTALIAS_NAME:{
					return ErrorName::ESME_RINVBCASTALIAS_NAME;
				}
				case ErrorCode::ESME_RINVBCASTAREAFMT:{
					return ErrorName::ESME_RINVBCASTAREAFMT;
				}
				case ErrorCode::ESME_RINVNUMBCAST_AREAS:{
					return ErrorName::ESME_RINVNUMBCAST_AREAS;
				}
				case ErrorCode::ESME_RINVBCASTCNTTYPE:{
					return ErrorName::ESME_RINVBCASTCNTTYPE;
				}
				case ErrorCode::ESME_RINVBCASTMSGCLASS:{
					return ErrorName::ESME_RINVBCASTMSGCLASS;
				}
				case ErrorCode::ESME_RBCASTFAIL:{
					return ErrorName::ESME_RBCASTFAIL;
				}
				case ErrorCode::ESME_RBCASTQUERYFAIL:{
					return ErrorName::ESME_RBCASTQUERYFAIL;
				}
				case ErrorCode::ESME_RBCASTCANCELFAIL:{
					return ErrorName::ESME_RBCASTCANCELFAIL;
				}
				case ErrorCode::ESME_RINVBCAST_REP:{
					return ErrorName::ESME_RINVBCAST_REP;
				}
				case ErrorCode::ESME_RINVBCASTSRVGRP:{
					return ErrorName::ESME_RINVBCASTSRVGRP;
				}
				case ErrorCode::ESME_RINVBCASTCHANIND:{
					return ErrorName::ESME_RINVBCASTCHANIND;
				}
				default:{
					return std::string("Unknown error code (vendor?)");
				}
			}
		}

		std::string SMPPOutputterBase::getNetworkErrorName(const unsigned char nNetworkErrorCode){
			switch(nNetworkErrorCode){
				case NetworkTypeErrorCode::ANSI_136_ACCESS_DENIED_REASON:{
					return NetworkTypeErrorName::ANSI_136_ACCESS_DENIED_REASON;
				}
				case NetworkTypeErrorCode::IS_95_ACCESS_DENIED_REASON:{
					return NetworkTypeErrorName::IS_95_ACCESS_DENIED_REASON;
				}
				case NetworkTypeErrorCode::GSM:{
					return NetworkTypeErrorName::GSM;
				}
				case NetworkTypeErrorCode::ANSI_136_CAUSE_CODE:{
					return NetworkTypeErrorName::ANSI_136_CAUSE_CODE;
				}
				case NetworkTypeErrorCode::IS_95_CAUSE_CODE:{
					return NetworkTypeErrorName::IS_95_CAUSE_CODE;
				}
				case NetworkTypeErrorCode::ANSI_41_ERROR:{
					return NetworkTypeErrorName::ANSI_41_ERROR;
				}
				case NetworkTypeErrorCode::SMPP_ERROR:{
					return NetworkTypeErrorName::SMPP_ERROR;
				}
				case NetworkTypeErrorCode::MESSAGE_CENTER_SPECIFIC:{
					return NetworkTypeErrorName::MESSAGE_CENTER_SPECIFIC;
				}
				default:{
					return std::string("Unknown network error code");
				}
			}
		}

		std::string SMPPOutputterBase::getMessageStateName(const unsigned char nMessageState){
			switch(nMessageState){
				case MessageState::ENROUTE:{
					return MessageStateName::ENROUTE;
				}
				case MessageState::DELIVERED:{
					return MessageStateName::DELIVERED;
				}
				case MessageState::EXPIRED:{
					return MessageStateName::EXPIRED;
				}
				case MessageState::DELETED:{
					return MessageStateName::DELETED;
				}
				case MessageState::UNDELIVERABLE:{
					return MessageStateName::UNDELIVERABLE;
				}
				case MessageState::ACCEPTED:{
					return MessageStateName::ACCEPTED;
				}
				case MessageState::UNKNOWN:{
					return MessageStateName::UNKNOWN;
				}
				case MessageState::REJECTED:{
					return MessageStateName::REJECTED;
				}
				case MessageState::SKIPPED:{
					return MessageStateName::SKIPPED;
				}
				default:{
					return std::string("Unknown message state code");
				}
			}
		}
		std::string SMPPOutputterBase::getMessagingMode(const unsigned char nEsmClass){
			switch(nEsmClass & 0x3){
				case 0x0:{
					return EsmClass::MODE_DEFAULT;
				}
				case 0x1:{
					return EsmClass::MODE_DATAGRAM;
				}
				case 0x2:{
					return EsmClass::MODE_TRANSACTION;
				}
				case 0x3:{
					return EsmClass::MODE_STORE;
				}
				default:{
					return EsmClass::MODE_UNKNOWN;
				}
			}
		}

		std::string SMPPOutputterBase::getMessageType(const unsigned char nEsmClass){
			switch(nEsmClass & 0x3C){ //0011 1100 = 0õ3Ñ
				case 0x0:{ // 0000 0000 = 0x00
					return EsmClass::TYPE_DEFAULT;
				}
				case 0x4:{ // 0000 0100 = 0x04
					return EsmClass::TYPE_DELIVERY_RECEIPT;
				}
				case 0x8:{ // 0000 1000 = 0x08
					return EsmClass::TYPE_DELIVERY_ACKNOWLEDGEMENT;
				}
				case 0x10:{ // 0001 0000 = 0x10
					return EsmClass::TYPE_USER_ACKNOWLEDGEMENT;
				}
				case 0x18:{ // 0001 1000 = 0x18
					return EsmClass::TYPE_ABORT;
				}
				case 0x20:{ // 0010 0000 = 0x20
					return EsmClass::TYPE_INTERMEDIATE_NOTIFICATION;
				}
				default:{
					return EsmClass::TYPE_UNKNOWN;
				}
			}
		}

		std::string SMPPOutputterBase::getMessageFeatures(const unsigned char nEsmClass){
			switch(nEsmClass & 0xC0){ // //0xC0=1100 0000
				case 0x0:{ // 0000 0000 = 0x40
					return EsmClass::FEATURES_NO_SELECTED;
				}
				case 0x40:{ // 0100 0000 = 0x40
					return EsmClass::FEATURES_UDHI;
				}
				case 0x80:{ // 1000 0000 = 0x80
					return EsmClass::FEATURES_REPLY_PATH;
				}
				case 0xC0:{ // 1100 0000 = 0xC0
					return EsmClass::FEATURES_UDHI_REPLY_PATH;
				}
				default:{
					return EsmClass::FEATURES_UNKNOWN;
				}
			}
		}

		std::string SMPPOutputterBase::getAreaFormatName(const unsigned char nAreaFormat){
			switch(nAreaFormat){
				case BroadcastAreaFormat::ALIAS:{
					return BroadcastAreaFormatName::ALIAS;
				}
				case BroadcastAreaFormat::ELLIPSOID:{
					return BroadcastAreaFormatName::ELLIPSOID;
				}
				case BroadcastAreaFormat::POLYGON:{
					return BroadcastAreaFormatName::POLYGON;
				}
				default:{
					return std::string("Unknown area format code");
				}
			}		
		}
	}
}
