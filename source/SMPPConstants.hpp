/*
   Copyright 2007 Majoron.com (developers@majoron.com)
   Original sources are available at www.majoron.com

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE_2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef SMPPCONSTANTS_HPP
#define SMPPCONSTANTS_HPP

namespace anthill {
	namespace smpp {

		/**
		 * Namespace contains command codes.
		 */
		namespace CommandId{
			const unsigned long CM_GENERIC_NACK					= 0x80000000ul;
			const unsigned long CM_BIND_RECEIVER				= 0x00000001ul;
			const unsigned long CM_BIND_RECEIVER_RESP			= 0x80000001ul;
			const unsigned long CM_BIND_TRANSMITTER				= 0x00000002ul;
			const unsigned long CM_BIND_TRANSMITTER_RESP		= 0x80000002ul;
			const unsigned long CM_QUERY_SM						= 0x00000003ul;
			const unsigned long CM_QUERY_SM_RESP				= 0x80000003ul;
			const unsigned long CM_SUBMIT_SM					= 0x00000004ul;
			const unsigned long CM_SUBMIT_SM_RESP				= 0x80000004ul;
			const unsigned long CM_DELIVER_SM					= 0x00000005ul;
			const unsigned long CM_DELIVER_SM_RESP				= 0x80000005ul;
			const unsigned long CM_UNBIND						= 0x00000006ul;
			const unsigned long CM_UNBIND_RESP					= 0x80000006ul;
			const unsigned long CM_REPLACE_SM					= 0x00000007ul;
			const unsigned long CM_REPLACE_SM_RESP				= 0x80000007ul;
			const unsigned long CM_CANCEL_SM					= 0x00000008ul;
			const unsigned long CM_CANCEL_SM_RESP				= 0x80000008ul;
			const unsigned long CM_BIND_TRANSCEIVER				= 0x00000009ul;
			const unsigned long CM_BIND_TRANSCEIVER_RESP		= 0x80000009ul;
			const unsigned long CM_OUTBIND						= 0x0000000Bul;
			const unsigned long CM_ENQUIRE_LINK					= 0x00000015ul;
			const unsigned long CM_ENQUIRE_LINK_RESP			= 0x80000015ul;
			const unsigned long CM_SUBMIT_MULTI					= 0x00000021ul;
			const unsigned long CM_SUBMIT_MULTI_RESP			= 0x80000021ul;
			const unsigned long CM_ALERT_NOTIFICATION			= 0x00000102ul;
			const unsigned long CM_DATA_SM						= 0x00000103ul;
			const unsigned long CM_DATA_SM_RESP					= 0x80000103ul;
			const unsigned long CM_BROADCAST_SM					= 0x00000111ul;
			const unsigned long CM_BROADCAST_SM_RESP			= 0x80000111ul;
			const unsigned long CM_QUERY_BROADCAST_SM			= 0x00000112ul;
			const unsigned long CM_QUERY_BROADCAST_SM_RESP		= 0x80000112ul;
			const unsigned long CM_CANCEL_BROADCAST_SM			= 0x00000113ul;
			const unsigned long CM_CANCEL_BROADCAST_SM_RESP		= 0x80000113ul;
		}
		/**
		 * Namespace contains diamter command codes.
		 */
		namespace CommandName{
			const std::string CM_GENERIC_NACK				= "CM_GENERIC_NACK";
			const std::string CM_BIND_RECEIVER				= "CM_BIND_RECEIVER";
			const std::string CM_BIND_RECEIVER_RESP			= "CM_BIND_RECEIVER_RESP";
			const std::string CM_BIND_TRANSMITTER			= "CM_BIND_TRANSMITTER";
			const std::string CM_BIND_TRANSMITTER_RESP		= "CM_BIND_TRANSMITTER_RESP";
			const std::string CM_QUERY_SM					= "CM_QUERY_SM";
			const std::string CM_QUERY_SM_RESP				= "CM_QUERY_SM_RESP";
			const std::string CM_SUBMIT_SM					= "CM_SUBMIT_SM";
			const std::string CM_SUBMIT_SM_RESP				= "CM_SUBMIT_SM_RESP";
			const std::string CM_DELIVER_SM					= "CM_DELIVER_SM";
			const std::string CM_DELIVER_SM_RESP			= "CM_DELIVER_SM_RESP";
			const std::string CM_UNBIND						= "CM_UNBIND";
			const std::string CM_UNBIND_RESP				= "CM_UNBIND_RESP";
			const std::string CM_REPLACE_SM					= "CM_REPLACE_SM";
			const std::string CM_REPLACE_SM_RESP			= "CM_REPLACE_SM_RESP";
			const std::string CM_CANCEL_SM					= "CM_CANCEL_SM";
			const std::string CM_CANCEL_SM_RESP				= "CM_CANCEL_SM_RESP";
			const std::string CM_BIND_TRANSCEIVER			= "CM_BIND_TRANSCEIVER";
			const std::string CM_BIND_TRANSCEIVER_RESP		= "CM_BIND_TRANSCEIVER_RESP";
			const std::string CM_OUTBIND					= "CM_OUTBIND";
			const std::string CM_ENQUIRE_LINK				= "CM_ENQUIRE_LINK";
			const std::string CM_ENQUIRE_LINK_RESP			= "CM_ENQUIRE_LINK_RESP";
			const std::string CM_SUBMIT_MULTI				= "CM_SUBMIT_MULTI";
			const std::string CM_SUBMIT_MULTI_RESP			= "CM_SUBMIT_MULTI_RESP";
			const std::string CM_ALERT_NOTIFICATION			= "CM_ALERT_NOTIFICATION";
			const std::string CM_DATA_SM					= "CM_DATA_SM";
			const std::string CM_DATA_SM_RESP				= "CM_DATA_SM_RESP";
			const std::string CM_BROADCAST_SM				= "CM_BROADCAST_SM";
			const std::string CM_BROADCAST_SM_RESP			= "CM_BROADCAST_SM_RESP";
			const std::string CM_QUERY_BROADCAST_SM			= "CM_QUERY_BROADCAST_SM";
			const std::string CM_QUERY_BROADCAST_SM_RESP	= "CM_QUERY_BROADCAST_SM_RESP";
			const std::string CM_CANCEL_BROADCAST_SM		= "CM_CANCEL_BROADCAST_SM";
			const std::string CM_CANCEL_BROADCAST_SM_RESP	= "CM_CANCEL_BROADCAST_SM_RESP";
		}
	
		/**
		 * SMPP padding for OctetString datatypes.
		 */
		namespace ErrorCode{
			const unsigned long ESME_ROK						= 0x00000000ul;
			const unsigned long ESME_RINVMSGLEN					= 0x00000001ul;
			const unsigned long ESME_RINVCMDLEN					= 0x00000002ul;
			const unsigned long ESME_RINVCMDID					= 0x00000003ul;
			const unsigned long ESME_RINVBNDSTS					= 0x00000004ul;
			const unsigned long ESME_RALYBND					= 0x00000005ul;
			const unsigned long ESME_RINVPRTFLG					= 0x00000006ul;
			const unsigned long ESME_RINVREGDLVFLG				= 0x00000007ul;
			const unsigned long ESME_RSYSERR					= 0x00000008ul;
			const unsigned long ESME_RINVSRCADR					= 0x0000000Aul;
			const unsigned long ESME_RINVDSTADR					= 0x0000000Bul;
			const unsigned long ESME_RINVMSGID					= 0x0000000Cul;
			const unsigned long ESME_RBINDFAIL					= 0x0000000Dul;
			const unsigned long ESME_RINVPASWD					= 0x0000000Eul;
			const unsigned long ESME_RINVSYSID					= 0x0000000Ful;
			const unsigned long ESME_RCANCELFAIL				= 0x00000011ul;
			const unsigned long ESME_RREPLACEFAIL				= 0x00000013ul;
			const unsigned long ESME_RMSGQFUL					= 0x00000014ul;
			const unsigned long ESME_RINVSERTYP					= 0x00000015ul;
			const unsigned long ESME_RINVNUMDESTS				= 0x00000033ul;
			const unsigned long ESME_RINVDLNAME					= 0x00000034ul;
			const unsigned long ESME_RINVDESTFLAG				= 0x00000040ul;
			const unsigned long ESME_RINVSUBREP					= 0x00000042ul;
			const unsigned long ESME_RINVESMCLASS				= 0x00000043ul;
			const unsigned long ESME_RCNTSUBDL					= 0x00000044ul;
			const unsigned long ESME_RSUBMITFAIL				= 0x00000045ul;
			const unsigned long ESME_RINVSRCTON					= 0x00000048ul;
			const unsigned long ESME_RINVSRCNPI					= 0x00000049ul;
			const unsigned long ESME_RINVDSTTON					= 0x00000050ul;
			const unsigned long ESME_RINVDSTNPI					= 0x00000051ul;
			const unsigned long ESME_RINVSYSTYP					= 0x00000053ul;
			const unsigned long ESME_RINVREPFLAG				= 0x00000054ul;
			const unsigned long ESME_RINVNUMMSGS				= 0x00000055ul;
			const unsigned long ESME_RTHROTTLED					= 0x00000058ul;
			const unsigned long ESME_RINVSCHED					= 0x00000061ul;
			const unsigned long ESME_RINVEXPIRY					= 0x00000062ul;
			const unsigned long ESME_RINVDFTMSGID				= 0x00000063ul;
			const unsigned long ESME_RX_T_APPN					= 0x00000064ul;
			const unsigned long ESME_RX_P_APPN					= 0x00000065ul;
			const unsigned long ESME_RX_R_APPN					= 0x00000066ul;
			const unsigned long ESME_RQUERYFAIL					= 0x00000067ul;
			const unsigned long ESME_RINVOPTPARSTREAM			= 0x000000C0ul;
			const unsigned long ESME_ROPTPARNOTALLWD			= 0x000000C1ul;
			const unsigned long ESME_RINVPARLEN					= 0x000000C2ul;
			const unsigned long ESME_RMISSINGOPTPARAM			= 0x000000C3ul;
			const unsigned long ESME_RINVOPTPARAMVAL			= 0x000000C4ul;
			const unsigned long ESME_RDELIVERYFAILURE			= 0x000000FEul;
			const unsigned long ESME_RUNKNOWNERR				= 0x000000FFul;
			const unsigned long ESME_RSERTYPUNAUTH				= 0x00000100ul;
			const unsigned long ESME_RPROHIBITED				= 0x00000101ul;
			const unsigned long ESME_RSERTYPUNAVAIL				= 0x00000102ul;
			const unsigned long ESME_RSERTYPDENIED				= 0x00000103ul;
			const unsigned long ESME_RINVDCS					= 0x00000104ul;
			const unsigned long ESME_RINVSRCADDRSUBUNIT			= 0x00000105ul;
			const unsigned long ESME_RINVDSTADDRSUBUNIT			= 0x00000106ul;
			const unsigned long ESME_RINVBCASTFREQINT			= 0x00000107ul;
			const unsigned long ESME_RINVBCASTALIAS_NAME		= 0x00000108ul;
			const unsigned long ESME_RINVBCASTAREAFMT			= 0x00000109ul;
			const unsigned long ESME_RINVNUMBCAST_AREAS			= 0x0000010Aul;
			const unsigned long ESME_RINVBCASTCNTTYPE			= 0x0000010Bul;
			const unsigned long ESME_RINVBCASTMSGCLASS			= 0x0000010Cul;
			const unsigned long ESME_RBCASTFAIL					= 0x0000010Dul;
			const unsigned long ESME_RBCASTQUERYFAIL			= 0x0000010Eul;
			const unsigned long ESME_RBCASTCANCELFAIL			= 0x0000010Ful;
			const unsigned long ESME_RINVBCAST_REP				= 0x00000110ul;
			const unsigned long ESME_RINVBCASTSRVGRP			= 0x00000111ul;
			const unsigned long ESME_RINVBCASTCHANIND			= 0x00000112ul;
		}
		
		/**
		 * SMPP padding for OctetString datatypes.
		 */
		namespace ErrorName{
			const std::string ESME_ROK							= "ESME_ROK";
			const std::string ESME_RINVMSGLEN					= "ESME_RINVMSGLEN";
			const std::string ESME_RINVCMDLEN					= "ESME_RINVCMDLEN";
			const std::string ESME_RINVCMDID					= "ESME_RINVCMDID";
			const std::string ESME_RINVBNDSTS					= "ESME_RINVBNDSTS";
			const std::string ESME_RALYBND						= "ESME_RALYBND";
			const std::string ESME_RINVPRTFLG					= "ESME_RINVPRTFLG";
			const std::string ESME_RINVREGDLVFLG				= "ESME_RINVREGDLVFLG";
			const std::string ESME_RSYSERR						= "ESME_RSYSERR";
			const std::string ESME_RINVSRCADR					= "ESME_RINVSRCADR";
			const std::string ESME_RINVDSTADR					= "ESME_RINVDSTADR";
			const std::string ESME_RINVMSGID					= "ESME_RINVMSGID";
			const std::string ESME_RBINDFAIL					= "ESME_RBINDFAIL";
			const std::string ESME_RINVPASWD					= "ESME_RINVPASWD";
			const std::string ESME_RINVSYSID					= "ESME_RINVSYSID";
			const std::string ESME_RCANCELFAIL					= "ESME_RCANCELFAIL";
			const std::string ESME_RREPLACEFAIL					= "ESME_RREPLACEFAIL";
			const std::string ESME_RMSGQFUL						= "ESME_RMSGQFUL";
			const std::string ESME_RINVSERTYP					= "ESME_RINVSERTYP";
			const std::string ESME_RINVNUMDESTS					= "ESME_RINVNUMDESTS";
			const std::string ESME_RINVDLNAME					= "ESME_RINVDLNAME";
			const std::string ESME_RINVDESTFLAG					= "ESME_RINVDESTFLAG";
			const std::string ESME_RINVSUBREP					= "ESME_RINVSUBREP";
			const std::string ESME_RINVESMCLASS					= "ESME_RINVESMCLASS";
			const std::string ESME_RCNTSUBDL					= "ESME_RCNTSUBDL";
			const std::string ESME_RSUBMITFAIL					= "ESME_RSUBMITFAIL";
			const std::string ESME_RINVSRCTON					= "ESME_RINVSRCTON";
			const std::string ESME_RINVSRCNPI					= "ESME_RINVSRCNPI";
			const std::string ESME_RINVDSTTON					= "ESME_RINVDSTTON";
			const std::string ESME_RINVDSTNPI					= "ESME_RINVDSTNPI";
			const std::string ESME_RINVSYSTYP					= "ESME_RINVSYSTYP";
			const std::string ESME_RINVREPFLAG					= "ESME_RINVREPFLAG";
			const std::string ESME_RINVNUMMSGS					= "ESME_RINVNUMMSGS";
			const std::string ESME_RTHROTTLED					= "ESME_RTHROTTLED";
			const std::string ESME_RINVSCHED					= "ESME_RINVSCHED";
			const std::string ESME_RINVEXPIRY					= "ESME_RINVEXPIRY";
			const std::string ESME_RINVDFTMSGID					= "ESME_RINVDFTMSGID";
			const std::string ESME_RX_T_APPN					= "ESME_RX_T_APPN";
			const std::string ESME_RX_P_APPN					= "ESME_RX_P_APPN";
			const std::string ESME_RX_R_APPN					= "ESME_RX_R_APPN";
			const std::string ESME_RQUERYFAIL					= "ESME_RQUERYFAIL";
			const std::string ESME_RINVOPTPARSTREAM				= "ESME_RINVOPTPARSTREAM";
			const std::string ESME_ROPTPARNOTALLWD				= "ESME_ROPTPARNOTALLWD";
			const std::string ESME_RINVPARLEN					= "ESME_RINVPARLEN";
			const std::string ESME_RMISSINGOPTPARAM				= "ESME_RMISSINGOPTPARAM";
			const std::string ESME_RINVOPTPARAMVAL				= "ESME_RINVOPTPARAMVAL";
			const std::string ESME_RDELIVERYFAILURE				= "ESME_RDELIVERYFAILURE";
			const std::string ESME_RUNKNOWNERR					= "ESME_RUNKNOWNERR";
			const std::string ESME_RSERTYPUNAUTH				= "ESME_RSERTYPUNAUTH";
			const std::string ESME_RPROHIBITED					= "ESME_RPROHIBITED";
			const std::string ESME_RSERTYPUNAVAIL				= "ESME_RSERTYPUNAVAIL";
			const std::string ESME_RSERTYPDENIED				= "ESME_RSERTYPDENIED";
			const std::string ESME_RINVDCS						= "ESME_RINVDCS";
			const std::string ESME_RINVSRCADDRSUBUNIT			= "ESME_RINVSRCADDRSUBUNIT";
			const std::string ESME_RINVDSTADDRSUBUNIT			= "ESME_RINVDSTADDRSUBUNIT";
			const std::string ESME_RINVBCASTFREQINT				= "ESME_RINVBCASTFREQINT";
			const std::string ESME_RINVBCASTALIAS_NAME			= "ESME_RINVBCASTALIAS_NAME";
			const std::string ESME_RINVBCASTAREAFMT				= "ESME_RINVBCASTAREAFMT";
			const std::string ESME_RINVNUMBCAST_AREAS			= "ESME_RINVNUMBCAST_AREAS";
			const std::string ESME_RINVBCASTCNTTYPE				= "ESME_RINVBCASTCNTTYPE";
			const std::string ESME_RINVBCASTMSGCLASS			= "ESME_RINVBCASTMSGCLASS";
			const std::string ESME_RBCASTFAIL					= "ESME_RBCASTFAIL";
			const std::string ESME_RBCASTQUERYFAIL				= "ESME_RBCASTQUERYFAIL";
			const std::string ESME_RBCASTCANCELFAIL				= "ESME_RBCASTCANCELFAIL";
			const std::string ESME_RINVBCAST_REP				= "ESME_RINVBCAST_REP";
			const std::string ESME_RINVBCASTSRVGRP				= "ESME_RINVBCASTSRVGRP";
			const std::string ESME_RINVBCASTCHANIND				= "ESME_RINVBCASTCHANIND";
		}
		/**
		 * SMPP padding for OctetString datatypes.
		 */
		namespace OptTags{
			const unsigned short TAG_DEST_ADDR_SUBUNIT				= 0x0005;		// GSM
			const unsigned short TAG_DEST_NETWORK_TYPE				= 0x0006;		// Generic
			const unsigned short TAG_DEST_BEARER_TYPE				= 0x0007;		// Generic
			const unsigned short TAG_DEST_TELEMATICS_ID				= 0x0008;		// GSM
			const unsigned short TAG_SOURCE_ADDR_SUBUNIT			= 0x000D;		// GSM
			const unsigned short TAG_SOURCE_NETWORK_TYPE			= 0x000E;		// Generic
			const unsigned short TAG_SOURCE_BEARER_TYPE				= 0x000F;		// Generic
			const unsigned short TAG_SOURCE_TELEMATICS_ID			= 0x0010;		// GSM
			const unsigned short TAG_QOS_TIME_TO_LIVE				= 0x0017;		// Generic
			const unsigned short TAG_PAYLOAD_TYPE					= 0x0019;		// Generic
			const unsigned short TAG_ADDITIONAL_STATUS_INFO_TEXT	= 0x001D;		// Generic
			const unsigned short TAG_RECEIPTED_MESSAGE_ID			= 0x001E;		// Generic
			const unsigned short TAG_MS_MSG_WAIT_FACILITIES			= 0x0030;		// GSM
			const unsigned short TAG_PRIVACY_INDICATOR				= 0x0201;		// CDMA, TDMA
			const unsigned short TAG_SOURCE_SUBADDRESS				= 0x0202;		// CDMA, TDMA
			const unsigned short TAG_DEST_SUBADDRESS				= 0x0203;		// CDMA, TDMA
			const unsigned short TAG_USER_MESSAGE_REFERENCE			= 0x0204;		// Generic
			const unsigned short TAG_USER_RESPONSE_CODE				= 0x0205;		// CDMA, TDMA
			const unsigned short TAG_SOURCE_PORT					= 0x020A;		// Generic
			const unsigned short TAG_DESTINATION_PORT				= 0x020B;		// Generic
			const unsigned short TAG_SAR_MSG_REF_NUM				= 0x020C;		// Generic
			const unsigned short TAG_LANGUAGE_INDICATOR				= 0x020D;		// CDMA, TDMA
			const unsigned short TAG_SAR_TOTAL_SEGMENTS				= 0x020E;		// Generic
			const unsigned short TAG_SAR_SEGMENT_SEQNUM				= 0x020F;		// Generic
			const unsigned short TAG_SC_INTERFACE_VERSION			= 0x0210;		// Generic
			const unsigned short TAG_CALLBACK_NUM_PRES_IND			= 0x0302;		// TDMA
			const unsigned short TAG_CALLBACK_NUM_ATAG				= 0x0303;		// TDMA
			const unsigned short TAG_NUMBER_OF_MESSAGES				= 0x0304;		// CDMA
			const unsigned short TAG_CALLBACK_NUM					= 0x0381;		// CDMA, TDMA, GSM, iDEN
			const unsigned short TAG_DPF_RESULT						= 0x0420;		// Generic
			const unsigned short TAG_SET_DPF						= 0x0421;		// Generic
			const unsigned short TAG_MS_AVAILABILITY_STATUS			= 0x0422;		// Generic
			const unsigned short TAG_NETWORK_ERROR_CODE				= 0x0423;		// Generic
			const unsigned short TAG_MESSAGE_PAYLOAD				= 0x0424;		// Generic
			const unsigned short TAG_DELIVERY_FAILURE_REASON		= 0x0425;		// Generic
			const unsigned short TAG_MORE_MESSAGES_TO_SEND			= 0x0426;		// GSM
			const unsigned short TAG_MESSAGE_STATE					= 0x0427;		// Generic
			const unsigned short TAG_USSD_SERVICE_OP				= 0x0501;		// GSM (USSD)
			const unsigned short TAG_DISPLAY_TIME					= 0x1201;		// CDMA, TDMA
			const unsigned short TAG_SMS_SIGNAL						= 0x1203;		// TDMA
			const unsigned short TAG_MS_VALIDITY					= 0x1204;		// CDMA, TDMA
			const unsigned short TAG_ALERT_ON_MESSAGE_DELIVERY		= 0x130C;		// CDMA
			const unsigned short TAG_ITS_REPLY_TYPE					= 0x1380;		// CDMA
			const unsigned short TAG_ITS_SESSION_INFO				= 0x1383;		// CDMA
			const unsigned short TAG_BROADCAST_CHANNEL_INDICATOR	= 0x0600;		// GSM
			const unsigned short TAG_BROADCAST_CONTENT_TYPE			= 0x0601;		// CDMA, TDMA, GSM
			const unsigned short TAG_BROADCAST_CONTENT_TYPE_INFO	= 0x0602;		// CDMA, TDMA
			const unsigned short TAG_BROADCAST_MESSAGE_CLASS		= 0x0603;		// GSM
			const unsigned short TAG_BROADCAST_REP_NUM				= 0x0604;		// GSM
			const unsigned short TAG_BROADCAST_FREQUENCY_INTERVAL	= 0x0605;		// CDMA, TDMA, GSM
			const unsigned short TAG_BROADCAST_AREA_IDENTIFIER		= 0x0606;		// CDMA, TDMA, GSM
			const unsigned short TAG_BROADCAST_ERROR_STATUS			= 0x0607;		// CDMA, TDMA, GSM
			const unsigned short TAG_BROADCAST_AREA_SUCCESS			= 0x0608;		// GSM
			const unsigned short TAG_BROADCAST_END_TIME				= 0x0609;		// CDMA, TDMA, GSM
			const unsigned short TAG_BROADCAST_SERVICE_GROUP		= 0x060A;		// CDMA, TDMA
			const unsigned short TAG_BILLING_IDENTIFICATION			= 0x060B;		// Generic
			const unsigned short TAG_SOURCE_NETWORK_ID				= 0x060D;		// Generic
			const unsigned short TAG_DEST_NETWORK_ID				= 0x060E;		// Generic
			const unsigned short TAG_SOURCE_NODE_ID					= 0x060F;		// Generic
			const unsigned short TAG_DEST_NODE_ID					= 0x0610;		// Generic
			const unsigned short TAG_DEST_ADDR_NP_RESOLUTION		= 0x0611;		// CDMA, TDMA (US Only)
			const unsigned short TAG_DEST_ADDR_NP_INFORMATION		= 0x0612;		// CDMA, TDMA (US Only)
			const unsigned short TAG_DEST_ADDR_NP_COUNTRY			= 0x0613;		// CDMA, TDMA (US Only)
		}

		/**
		 * Namespace contains diamter command codes.
		 */
		namespace DestFlag{
			const unsigned char UNKNOWN = 0;
			const unsigned char SME_ADDRESS = 1;
			const unsigned char DISTR_LIST_NAME = 2;
		}

		/**
		 * Namespace contains diamter command codes.
		 */
		namespace BroadcastAreaFormat{
			const unsigned char ALIAS = 0x00;
			const unsigned char ELLIPSOID = 0x01;
			const unsigned char POLYGON = 0x02;
			const unsigned char UNKNOWN = 0xFF;
		}

		/**
		 * Namespace contains diamter command codes.
		 */
		namespace BroadcastAreaFormatName{
			const std::string ALIAS			= "ALIAS";
			const std::string ELLIPSOID		= "ELLIPSOID";
			const std::string POLYGON		= "POLYGON";
			const std::string UNKNOWN		= "UNKNOWN";
		}
		/**
		 * The following is a list of allowable states for a short message. 
		 * The message_state value is returned by the SMSC to the ESME as 
		 * part of the query_sm_resp PDU.
		 */
		namespace MessageState{
			/**
			 * The message is in enroute state.
			 */
			const unsigned char ENROUTE = 0x01;
			/**
			 * Message is delivered todestination.
			 */
			const unsigned char DELIVERED = 0x02;
			/**
			 * Message validity period hasexpired.
			 */
			const unsigned char EXPIRED = 0x03;
			/**
			 * Message has been deleted.
			 */
			const unsigned char DELETED = 0x04;
			/**
			 * Message is undeliverable.
			 */
			const unsigned char UNDELIVERABLE = 0x05;
			/**
			 * Message is in accepted state (i.e. has been manually read
			 * on behalf of the subscriber by customer service).
			 */
			const unsigned char ACCEPTED = 0x06;
			/**
			 * Message is in invalid state.
			 */
			const unsigned char UNKNOWN = 0x07;
			/**
			 * Message is in a rejected state.
			 */
			const unsigned char REJECTED = 0x08;
			/**
			 * The message was accepted but not transmitted or 
			 *  broadcast on the network.
			 */
			const unsigned char SKIPPED = 0x09;
		}
		/**
		 * The following is a list of allowable states for a short message. 
		 * The message_state value is returned by the SMSC to the ESME as 
		 * part of the query_sm_resp PDU.
		 */
		namespace MessageStateName{
			/**
			 * Message is delivered todestination.
			 */
			const std::string ENROUTE = "ENROUTE";
			/**
			 * Message is delivered todestination.
			 */
			const std::string DELIVERED = "DELIVRD";
			/**
			 * Message validity period hasexpired.
			 */
			const std::string EXPIRED = "EXPIRED";
			/**
			 * Message has been deleted.
			 */
			const std::string DELETED = "DELETED";
			/**
			 * Message is undeliverable.
			 */
			const std::string UNDELIVERABLE = "UNDELIV";
			/**
			 * Message is in accepted state (i.e. has been manually read
			 * on behalf of the subscriber by customer service).
			 */
			const std::string ACCEPTED = "ACCEPTD";
			/**
			 * Message is in invalid state.
			 */
			const std::string UNKNOWN = "UNKNOWN";
			/**
			 * Message is in a rejected state.
			 */
			const std::string REJECTED = "REJECTD";
			/**
			 * The message was accepted but not transmitted or 
			 *  broadcast on the network.
			 */
			const std::string SKIPPED = "SKIPPED";
		}


		/**
		 * The network_error_code parameter is used to indicate the actual network 
		 * error code for a delivery failure. 
		 */
		namespace NetworkTypeErrorCode{
			const unsigned char ANSI_136_ACCESS_DENIED_REASON = 0x01;
			const unsigned char IS_95_ACCESS_DENIED_REASON = 0x02;
			const unsigned char GSM = 0x03;
			const unsigned char ANSI_136_CAUSE_CODE = 0x04;
			const unsigned char IS_95_CAUSE_CODE = 0x05;
			const unsigned char ANSI_41_ERROR = 0x06;
			const unsigned char SMPP_ERROR = 0x07;
			const unsigned char MESSAGE_CENTER_SPECIFIC = 0x08;
		}

		/**
		 * The network_error_code parameter is used to indicate the actual network 
		 * error code for a delivery failure. 
		 */
		namespace NetworkTypeErrorName{
			const std::string ANSI_136_ACCESS_DENIED_REASON = "ANSI 136 Access Denied Reason";
			const std::string IS_95_ACCESS_DENIED_REASON = "IS 95 Access Denied Reason";
			const std::string GSM = "GSM";
			const std::string ANSI_136_CAUSE_CODE = "ANSI 136 Cause Code";
			const std::string IS_95_CAUSE_CODE = "IS 95 Cause Code";
			const std::string ANSI_41_ERROR = "ANSI-41 Error";
			const std::string SMPP_ERROR = "SMPP Error";
			const std::string MESSAGE_CENTER_SPECIFIC = "Message Center Specific";
		}

		/**
		 * This parameter is used to indicate the version of the SMPP protocol.
		 */
		namespace InterfaceVersion{
			/**
			 * Indicates that the ESME supports version 3.3 or earlier of 
			 * the SMPPprotocol.
			 */
			const unsigned char SMPP_VER_0_0 = 0x00;
			/**
			 * Indicates that the ESME supports version 3.3 or earlier of 
			 * the SMPPprotocol.
			 */
			const unsigned char SMPP_VER_3_3 = 0x33;
			/**
			 * Indicates that the ESME is supporting SMPP version 3.4.
			 */
			const unsigned char SMPP_VER_3_4 = 0x34;
			/**
			 * Indicates that the ESME is supporting SMPP version 5.0.
			 */
			const unsigned char SMPP_VER_5_0 = 0x50;
		}
		/**
		 * These fields define the Type of Number (TON) to be used in the SME address parameters.
		 */
		namespace TON{
			/**
			 * 
			 */
			const unsigned char UNKNOWN = 0x00;
			/**
			 * 
			 */
			const unsigned char INTERNATIONAL = 0x01;
			/**
			 * 
			 */
			const unsigned char NATIONAL = 0x02;
			/**
			 * 
			 */
			const unsigned char NETWORK_SPECIFIC = 0x03;
			/**
			 * 
			 */
			const unsigned char SUBSCRIBER_NUMBER = 0x04;
			/**
			 * 
			 */
			const unsigned char ALPHANUMERIC = 0x05;
			/**
			 * 
			 */
			const unsigned char ABBREVIATED = 0x06;
		}

		/**
		 * These fields define the Numeric Plan Indicator (NPI) to be used in the SME address parameters.
		 */
		namespace NPI{
			/**
			 * 
			 */
			const unsigned char UNKNOWN = 0x00;
			/**
			 * 
			 */
			const unsigned char ISDN = 0x01;
			/**
			 * 
			 */
			const unsigned char DATA = 0x02;
			/**
			 * 
			 */
			const unsigned char TELEX = 0x03;
			/**
			 * 
			 */
			const unsigned char LAND_MOBILE = 0x04;
			/**
			 * 
			 */
			const unsigned char NATIONAL = 0x05;
			/**
			 * 
			 */
			const unsigned char PRIVATE = 0x06;
			/**
			 * 
			 */
			const unsigned char ERMES = 0x07;
			/**
			 * 
			 */
			const unsigned char INTERNET = 0x08;
			/**
			 * 
			 */
			const unsigned char WAP_CLIENT_ID = 0x09;
		}

		/**
		 * The service_type parameter can be used to indicate the SMS Application 
		 * service associated with the message.
		 */
		namespace ServiceType{
			const std::string NULL_ = "NULL";
			const std::string CMT = "CMT";
			const std::string CPT = "CPT";
			const std::string VMN = "VMN";
			const std::string VMA = "VMA";
			const std::string WAP = "WAP";
			const std::string USSD = "USSD";
		}
		/**
		 * The priority_flag parameter allows the originating SME to assign a 
		 * priority level to the short message.
		 */
		namespace PriorityFlag{
			const unsigned char LOWEST = 0x00;
			const unsigned char LEVEL1 = 0x01;
			const unsigned char LEVEL2 = 0x02;
			const unsigned char HIGHEST = 0x03;
		}
		/**
		 * The replace_if_present_flag parameter is used to request the SMSC 
		 * to replace a previously submitted message, that is still pending delivery.
		 */
		namespace ReplaceIfPresentFlag{
			const unsigned char DONT_REPLACE = 0x00;
			const unsigned char REPLACE = 0x01;
		}	

		/**
		 * The network type is used to indicate a network type 
		 * associated with the destination address of a message.
		 */
		namespace NetworkType{
			const unsigned char UNKNOWN = 0x00;
			const unsigned char GSM = 0x01;
			const unsigned char TDMA = 0x02;
			const unsigned char CDMA = 0x03;
			const unsigned char PDC = 0x04;
			const unsigned char PHS = 0x05;
			const unsigned char IDEN = 0x06;
			const unsigned char AMPS = 0x07;
			const unsigned char PAGING = 0x08;
		}	

		/**
		 * The bearer type parameter is used to request the desired 
		 * bearer for delivery of the message to the destination address.
		 */
		namespace BearerType{
			const unsigned char UNKNOWN = 0x00;
			const unsigned char SMS = 0x01;
			const unsigned char CSD = 0x02;
			const unsigned char PACKET_DATA = 0x03;
			const unsigned char USSD = 0x04;
			const unsigned char CDPD = 0x05;
			const unsigned char DATATAC = 0x06;
			const unsigned char FLEX = 0x07;
			const unsigned char CELLCAST = 0x08;
		}	

		/**
		 * The privacy indicator indicates the privacy level of the message.
		 */
		namespace PrivacyIndicator{
			const unsigned char NOT_RESTRICTED = 0x00;
			const unsigned char RESTRICTED = 0x01;
			const unsigned char CONFIDENTIAL = 0x02;
			const unsigned char SECRET = 0x03;
		}	

		/**
		 * The display time parameter is used to associate a display time of 
		 * the short message on the MS.
		 */
		namespace DisplayTime{
			const unsigned char TEMPORARY = 0x00;
			const unsigned char DEFAULT = 0x01;
			const unsigned char INVOKE = 0x02;
		}	

		/**
		 * The ms validity parameter is used to provide an MS with validity 
		 * information associated with the received short message.
		 */
		namespace MsValidity{
			const unsigned char Store_Indefinitely = 0x00;
			const unsigned char POWER_DOWN = 0x01;
			const unsigned char SID_BASED_RA = 0x02;
			const unsigned char DISPLAY_ONLY = 0x03;
		}	

		/**
		 * The dpf result parameter is used in the data_sm_resp PDU to indicate 
		 * if delivery pending flag (DPF) was set for a delivery failure of 
		 * the short message.
		 */
		namespace DpfResult{
			const unsigned char DPF_NOT_SET = 0x00;
			const unsigned char DPF_SET = 0x01;
		}	

		/**
		 * .
		 */
		namespace SetDpf{
			const unsigned char NOT_REQUESTED = 0x00;
			const unsigned char REQUESTED = 0x01;
		}	

		/**
		 * The ms_availability_status parameter is used in the alert_notification 
		 * operation to indicate the availability state of the MS to the ESME.
		 */
		namespace MsAvailabilityStatus{
			const unsigned char AVAILABLE = 0x00;
			const unsigned char DENIED = 0x01;
			const unsigned char UNAVAILABLE = 0x02;
		}	

		/**
		 * The delivery failure_reason parameter is used in the data_sm_resp operation to 
		 * indicate the outcome of the message delivery attempt (only applicable for 
		 * transaction message mode).
		 */
		namespace DeliveryFailureReason{
			const unsigned char DESTINATION_UNAVAILABLE = 0x00;
			const unsigned char DESTINATION_ADDRESS_INVALID = 0x01;
			const unsigned char PERMANENT_NETWORK_ERROR = 0x02;
			const unsigned char TEMPORARY_NETWORK_ERROR = 0x03;
		}	

		/**
		 * The more messages to send parameter is used by the ESME in the submit_sm and 
		 * data_sm operations to indicate to the SMSC that there are further messages 
		 * for the same destination SME.
		 */
		namespace MoreMessagesToSend{
			const unsigned char NO_MORE_MESSAGES = 0x00;
			const unsigned char MORE_MESSAGES = 0x01;
		}	

		/**
		 * The its reply type parameter is a required parameter for the CDMA 
		 * Interactive Teleservice as defined by the Korean PCS carriers [KORITS]. 
		 * It indicates and controls the MS user’s reply method to an SMS delivery 
		 * message received from the ESME.
		 */
		namespace ItsReplyType{
			const unsigned char DIGIT = 0x00;
			const unsigned char NUMBER = 0x01;
			const unsigned char TELEPHONE_NO = 0x02;
			const unsigned char PASSWORD = 0x03;
			const unsigned char CHARACTER_LINE = 0x04;
			const unsigned char MENU = 0x05;
			const unsigned char DATE = 0x06;
			const unsigned char TIME = 0x07;
			const unsigned char CONTINUE = 0x07;
		}	

		/**
		 * The ussd service op parameter is required to define the USSD service 
		 * operation when SMPP is being used as an interface to a (GSM) USSD system..
		 */
		namespace UssdServiceOp{
			const unsigned char PSSD_INDICATION = 0x00;
			const unsigned char PSSR_INDICATION = 0x01;
			const unsigned char USSR_REQUEST = 0x02;
			const unsigned char USSN_REQUEST = 0x03;
			const unsigned char PSSD_RESPONSE = 0x10;
			const unsigned char PSSR_RESPONSE = 0x11;
			const unsigned char USSR_CONFIRM = 0x12;
			const unsigned char USSN_CONFIRM = 0x13;
		}	

		/**
		 * Namespace contains limitation for SMPP fields.
		 */
		namespace SMPPMaxLen{
			/**
			 * A max len for field.
			 */
			const unsigned SYSTEM_ID_MAX_LEN = 16;
			/**
			 * A max len for field.
			 */
			const unsigned PASSWORD_MAX_LEN = 9;
			/**
			 * A max len for field.
			 */
			const unsigned SYSTEM_TYPE_MAX_LEN = 13;
			/**
			 * A max len for field.
			 */
			const unsigned ADDRESS_RANGE_MAX_LEN = 41;
			/**
			 * A max len for field.
			 */
			const unsigned SERVICE_TYPE_MAX_LEN = 6;
			/**
			 * A max len for field.
			 */
			const unsigned SOURCE_ADDR_MAX_LEN_21 = 21;
			/**
			 * A max len for field.
			 */
			const unsigned DESTINATION_ADDR_MAX_LEN_21 = 21;
			/**
			 * A max len for field.
			 */
			const unsigned SOURCE_ADDR_MAX_LEN_65 = 65;
			/**
			 * A max len for field.
			 */
			const unsigned DESTINATION_ADDR_MAX_LEN_65 = 65;
			/**
			 * A max len for field.
			 */
			const unsigned SMPP_DATETIME_MAX_LEN = 17;
			/**
			 * A max len for field.
			 */
			const unsigned MESSAGE_ID_MAX_LEN = 65;
			/**
			 * A max len for field.
			 */
			const unsigned ESME_ADDR_MAX_LEN = 65;
			/**
			 * A max len for field.
			 */
			const unsigned DL_NAME_MAX_LEN = 21;
			/**
			 * A max len for field.
			 */
			const unsigned SCHEDULE_DELIVERY_TIME_MAX_LEN = 17;
			/**
			 * A max len for field.
			 */
			const unsigned VALIDITY_PERIOD_MAX_LEN = 17;
			/**
			 * A max len for field.
			 */
			const unsigned BROADCAST_END_TIME_MAX_LEN = 17;
		}

		/**
		 * Namespace contains limitation for SMPP fields.
		 */
		namespace SMPPTLVLen{
			/**
			 * A len for TLV field .
			 */
			const unsigned BYTE_LEN = 1;
			const unsigned WORD_LEN = 2;
			const unsigned THREE_BYTE_LEN = 3;
			const unsigned DWORD_LEN = 4;
		}


		/**
		 * Namespace contains diamter different fields
		   offsets inside command header and AVP header.
		 */
		namespace SMPPOffset{
			/**
			 * SMPP's header size in the bytes.
			 */
			const int SMPP_HEADER_SIZE = 16;
			/**
			 * Offset or shift for message lenght field at header.
			 */
			const int COMMAND_LENGTH_POS = 0;
			/**
			 * Offset or shift for command code field at header.
			 */
			const int COMMAND_ID_POS = 4;
			/**
			 * Offset or shift for command code field at header.
			 */
			const int TLV_CODE_POS = 0;
			/**
			 * SMPP tag size at TLV structure.
			 */
			const int TLV_TAG_LENGHT = 2;
			/**
			 * SMPP length size at TLV structure..
			 */
			const int TLV_LENGTH_LENGHT = 2;
		}

		/**
		 * Namespace contains errors code for validator.
		 */
		namespace CodecErrors{
			/**
			 * Error ...
			 */
			const std::string ENCODER_INV_DSTFLAG = "Unable to encode dest addresses due to invalid dest flag. Offset is: %1%. Dest flag is: %2%";

			const std::string DECODER_INV_DSTFLAG = "Unable to decode dest addresses due to invalid dest flag. Offset is: %1%. Dest flag is: %2%";

			const std::string VALIDATE_PASSWORD_MAX_LEN = "Password is greater than max size according to spec.";
			const std::string VALIDATE_SYSTEM_TYPE_MAX_LEN = "System type is greater than max size according to spec.";
			const std::string VALIDATE_ADDRESS_RANGE_MAX_LEN = "Address range is greater than max size according to spec.";
			const std::string VALIDATE_SCHEDULE_DELIVERY_TIME_MAX_LEN = "Schedule delivery time is greater than max size according to spec.";
			const std::string VALIDATE_SCHEDULE_DELIVERY_TIME_RANGE_LEN = "Schedule delivery time size is not according to spec.";
			const std::string VALIDATE_VALIDITY_PERIOD_MAX_LEN = "Validity period is greater than max size according to spec.";
			const std::string VALIDATE_VALIDITY_PERIOD_RANGE_LEN = "Validity period size is not according to spec.";
			const std::string VALIDATE_DEST_ADDRESSES_LEN = "Dest addresses len should be equal to number of dests.";
			const std::string VALIDATE_UNSUCCESS_SMES_LEN = "Unsuccess SMEs len should be equal to no unsuccess.";
			const std::string VALIDATE_TLV_BYTE_LEN = "Len value for TLV is not according to spec. It should be equal to 1. Len is: %1% Tag is: %2%";
			const std::string VALIDATE_TLV_WORD_LEN = "Len value for TLV is not according to spec. It should be equal to 2. Len is: %2% Tag is: %2%";
			const std::string VALIDATE_TLV_THREE_BYTE_LEN = "Len value for TLV is not according to spec. It should be equal to 3. Len is: %2% Tag is: %2%";
			const std::string VALIDATE_TLV_DWORD_LEN = "Len value for TLV is not according to spec. It should be equal to 4. Len is: %2% Tag is: %2%";
			const std::string VALIDATE_BROADCAST_END_TIME_MAX_LEN = "Broadcast end time is greater than max size according to spec.";
			const std::string VALIDATE_BROADCAST_END_TIME_RANGE_LEN = "Broadcast end time size is not according to spec.";
			const std::string VALIDATE_BROADCAST_AREA_IDENTIFIER_MIN_LEN = "Broadcast area identifier is mandatory fields. It should present";
			const std::string VALIDATE_BROADCAST_AREA_IDENTIFIER_LEN = "Broadcast area identifier and broadcast area identifier len should be the same size.";
			const std::string VALIDATE_FAILED_BROADCAST_AREA_IDENTIFIER_LEN = "Failed broadcast area identifier and failed broadcast area identifier len should be the same size.";

			const std::string VALIDATE_INTERFACE_VERSION_VALUE = "Interface version or sc interface version is not according to spec. Allowed values between 0x00 and 0x34 or 0x50. Version is: %1%";
			const std::string VALIDATE_MESSAGE_STATE_VALUE = "Message State is not according to spec. Allowed values between 1 and 9. Message state is: %1%";

			const std::string VALIDATE_MESSAGE_ID_NULL_LEN = "Message id should be NULL.";
			const std::string VALIDATE_SHORT_MESSAGE_PAYLOAD_LEN = "Short message and message payload shoult not be used simultaneously.";

		}

		/**
		 * Namespace contains errors code for reporting.
		 */
		namespace Errors{
			/**
			 * Error ...
			 */
			const int DECODE_FAILURE_CODE = 10001;
			const std::string DECODE_FAILURE_MSG = "Error: unable to decode packet. ";

			const int UNKNOWN_TAG_CODE = 10002;
			const std::string UNKNOWN_TAG_MSG = "Error: unable to decode TLV due to unknown tag. ";

		}

		/**
		 * Namespace contains errors code for reporting.
		 */
		namespace FieldsName{
			const std::string COMMAND_LENGTH = "Command length";
			const std::string COMMAND_ID = "Command id";
			const std::string COMMAND_STATUS = "Command status";
			const std::string SEQUENCE_NUMBER = "Sequence number";
			const std::string SYSTEM_ID = "System id";
			const std::string PASSWORD = "Password";
			const std::string SYSTEM_TYPE = "System type";
			const std::string INTERFACE_VERSION = "Interface version";
			const std::string ADDR_TON = "Addr TON";
			const std::string ADDR_NPI = "Addr NPI";
			const std::string ADDRESS_RANGE = "Address range";
			const std::string SERVICE_TYPE = "Service type";
			const std::string SOURCE_ADDR_TON = "Source addr TON";
			const std::string SOURCE_ADDR_NPI = "Source addr NPI";
			const std::string SOURCE_ADDR = "Source addr";
			const std::string DEST_ADDR_TON = "Dest addr TON";
			const std::string DEST_ADDR_NPI = "Dest addr NPI";
			const std::string DEST_ADDR = "Dest addr";
			const std::string ESM_CLASS = "ESM class";
			const std::string PROTOCOLID = "ProtocolId";
			const std::string PRIORITY_FLAG = "Priority flag";
			const std::string SCHEDULE_DELIVERY_TIME = "Schedule delivery time";
			const std::string VALIDITY_PERIOD = "Validity period";
			const std::string REGISTERED_DELIVERY = "Registered delivery";
			const std::string REPLACE_IF_PRESENT = "Replace if present";
			const std::string DATA_CODING = "Data coding";
			const std::string SM_DEFAULT_MSG_ID = "SM default msg id";
			const std::string SM_LENGTH = "SM length";
			const std::string SHORT_MESSAGE = "Short message";
			const std::string MESSAGE_ID = "Message id";
			const std::string ESME_ADDR_TON = "ESME addr TON";
			const std::string ESME_ADDR_NPI = "ESME addr NPI";
			const std::string ESME_ADDR = "ESME addr";
			const std::string NUMBER_OF_DEST = "Number of dest";
			const std::string DEST_ADDRESSES = "Dest addresses";
			const std::string DESTFLAG = "DestFlag";
			const std::string TON = "TON";
			const std::string NPI = "NPI";
			const std::string ADDRESS = "Address";
			const std::string DISTR_LIST_NAME = "Distr List Name";
			const std::string NO_UNSUCCESS = "No unsuccess";
			const std::string UNSUCCESS_SMES = "Unsuccess SMEs";
			const std::string FINAL_DATE = "Final date";
			const std::string MESSAGE_STATE = "Message state";
			const std::string ERROR_CODE = "Error code";
			const std::string BROADCAST_AREA_SUCCESS = "Broadcast area success";
			const std::string BROADCAST_AREA_IDENTIFIER = "Broadcast area identifier";
			const std::string BROADCAST_REP_NUM = "Broadcast rep num";
			const std::string BROADCAST_FREQUENCY_INTERVAL = "Broadcast frequency interval";
			const std::string BROADCAST_CONTENT_TYPE = "Broadcast content type";
			const std::string SC_INTERFACE_VERSION = "Sc interface version";
			const std::string MS_AVAILABILITY_STATUS = "MS availability status";
			const std::string ALERT_ON_MSG_DELIVERY = "Alert on msg delivery";
			const std::string BROADCAST_CHANNEL_INDICATOR = "Broadcast channel indicator";
			const std::string BROADCAST_CONTENT_TYPE_INFO = "Broadcast content type info";
			const std::string BROADCAST_MESSAGE_CLASS = "Broadcast message class";
			const std::string BROADCAST_SERVICE_GROUP = "Broadcast service group";
			const std::string CALLBACK_NUM = "Callback num";
			const std::string CALLBACK_NUM_ATAG = "Callback num atag";
			const std::string CALLBACK_NUM_PRES_IND = "Callback num pres ind";
			const std::string DEST_ADDR_SUBUNIT = "Dest addr subunit";
			const std::string DEST_SUBADDRESS = "Dest subaddress";
			const std::string DISPLAY_TIME = "Display time";
			const std::string LANGUAGE_INDICATOR = "Language indicator";
			const std::string MESSAGE_PAYLOAD = "Message payload";
			const std::string MS_VALIDITY = "Ms validity";
			const std::string PAYLOAD_TYPE = "Payload type";
			const std::string PRIVACY_INDICATOR = "Privacy indicator";
			const std::string SMS_SIGNAL = "Sms signal";
			const std::string SOURCE_ADDR_SUBUNIT = "Source addr subunit";
			const std::string SOURCE_PORT = "Source port";
			const std::string SOURCE_SUBADDRESS = "Source subaddress";
			const std::string USER_MESSAGE_REFERENCE = "User message reference";
			const std::string BROADCAST_ERROR_STATUS = "Broadcast error status";
			const std::string FAILED_BROADCAST_AREA_IDENTIFIER = "Failed broadcast area identifier";
			const std::string SOURCE_NETWORK_TYPE = "Source network type";
			const std::string SOURCE_BEARER_TYPE = "Source bearer type";
			const std::string SOURCE_TELEMATICS_ID = "Source telematics id";
			const std::string DESTINATION_PORT = "Destination port";
			const std::string DEST_NETWORK_TYPE = "Dest network type";
			const std::string DEST_BEARER_TYPE = "Dest bearer type";
			const std::string DEST_TELEMATICS_ID = "Dest telematics id";
			const std::string SAR_MSG_REF_NUM = "Sar msg ref num";
			const std::string SAR_TOTAL_SEGMENTS = "Sar total segments";
			const std::string SAR_SEGMENT_SEQNUM = "Sar segment seqnum";
			const std::string MORE_MESSAGES_TO_SEND = "More messages to send";
			const std::string QOS_TIME_TO_LIVE = "Qos time to live";
			const std::string SET_DPF = "Set dpf";
			const std::string RECEIPTED_MESSAGE_ID = "Receipted message id";
			const std::string NETWORK_ERROR_CODE = "Network error code";
			const std::string MS_MSG_WAIT_FACILITIES = "Ms msg wait facilities";
			const std::string NUMBER_OF_MESSAGES = "Number of messages";
			const std::string ITS_REPLY_TYPE = "Its reply type";
			const std::string ITS_SESSION_INFO = "Its session info";
			const std::string USER_RESPONSE_CODE = "User response code";
			const std::string DELIVERY_FAILURE_REASON = "Delivery failure reason";
			const std::string ADDITIONAL_STATUS_INFO_TEXT = "Additional status info text";
			const std::string DPF_RESULT = "Dpf result";
			const std::string BROADCAST_END_TIME = "Broadcast end time";
			const std::string USSD_SERVICE_OP = "Ussd service op";
			const std::string ERROR_STATUS_CODE = "Error status code";

			const std::string INV_DEST_FLAG = "Inv dest flag";

		}

		/**
		 * Namespace contains errors code for reporting.
		 */
		namespace Outputter{
			const unsigned char WIDTH_HEADER = 3;
			const unsigned char WIDTH_LENGTH = 7;
			const unsigned char WIDTH_FLDNAME = 40;
			const std::string HEADER = "H";
			const std::string MANDATORY = "M";
			const std::string OPTIONAL_ = "O";
			const std::string COMMA = ",";
			const std::string LBRACKET = "[";
			const std::string RBRACKET = "]";
			const std::string LCURLYBRACE = "{";
			const std::string RCURLYBRACE = "}";
			const std::string SEPARATOR = "|";
			const std::string COLON = ":";
			const std::string SEMICOLON = ";";
			const std::string SPACE = " ";
			const std::string EQUAL = "=";
			const std::string HEX = "HEX";
			const std::string HEXSIGN = "0x";
			const std::string ZEROSIGN = "0";
			const std::string EMPTY = "";
		}

		/**
		 * Namespace contains constant about esm class.
		 */
		namespace EsmClass{
			const std::string MESSAGING_MODE = "Messaging mode";
			const std::string MESSAGE_TYPE = "Message type";
			const std::string MESSAGE_FEATURES = "Message features";

			/**
			 * Available messing mode.
			 */
			const std::string MODE_UNKNOWN = "Unknown";
			const std::string MODE_DEFAULT = "Default SMSC Mode";
			const std::string MODE_DATAGRAM = "Datagram mode";
			const std::string MODE_TRANSACTION = "Forward (i.e. Transaction) mode";
			const std::string MODE_STORE = "Store and Forward mode";

			/**
			 * Available message type.
			 */
			const std::string TYPE_UNKNOWN = "Unknown";
			const std::string TYPE_DEFAULT = "Default message Type (i.e. normal message)";
			const std::string TYPE_DELIVERY_RECEIPT = "Short Message contains SMSC Delivery Receipt";
			const std::string TYPE_DELIVERY_ACKNOWLEDGEMENT = "Short Message contains SMSC Delivery Acknowledgment";
			const std::string TYPE_USER_ACKNOWLEDGEMENT = "Short Message contains SME Manual/User Acknowledgment";
			const std::string TYPE_ABORT = "Short Message contains Conversation Abort (Korean CDMA)";
			const std::string TYPE_INTERMEDIATE_NOTIFICATION = "Short Message contains Intermediate Delivery Notification";

			/**
			 * Available message features.
			 */
			const std::string FEATURES_UNKNOWN = "Unknown";
			const std::string FEATURES_NO_SELECTED = "No specific features selected";
			const std::string FEATURES_UDHI = "UDHI Indicator set";
			const std::string FEATURES_REPLY_PATH = "Reply Path";
			const std::string FEATURES_UDHI_REPLY_PATH = "UDHI and Reply Path";
		}
	}
}

#endif // SMPPCONSTANTS_HPP
