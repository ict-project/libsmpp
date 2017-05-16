################################################################
cmake_minimum_required(VERSION 2.6)
################################################################
project(libsmpp)

set(CMAKE_CXX_STANDARD 11)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_SOURCE_FILES 
 AntHill.cpp          SMPPAlertNotification.cpp    SMPPBroadcastSM.cpp            SMPPDatatypes.cpp        SMPPOutbind.cpp               SMPPResp.cpp             SMPPValidator.cpp
 AntHillSMPP.cpp      SMPPBind.cpp                 SMPPBroadcastSMResp.cpp        SMPPDecoder.cpp          SMPPOutputterBase.cpp         SMPPStructures.cpp       SMPPXMLOutputter.cpp
 BinaryDecoder.cpp    SMPPBindReceiver.cpp         SMPPCancelBroadcastSM.cpp      SMPPDeliverSM.cpp        SMPPPDU.cpp                   SMPPSubmitMulti.cpp      TextOutputter.cpp
 BinaryEncoder.cpp    SMPPBindReceiverResp.cpp     SMPPCancelBroadcastSMResp.cpp  SMPPDeliverSMResp.cpp    SMPPQueryBroadcastSM.cpp      SMPPSubmitMultiResp.cpp  ValidatorBase.cpp
 BinaryOutputter.cpp  SMPPBindResp.cpp             SMPPCancelSM.cpp               SMPPEncoder.cpp          SMPPQueryBroadcastSMResp.cpp  SMPPSubmitSM.cpp         XMLOutputter.cpp
 ByteBuffer.cpp       SMPPBindTransceiver.cpp      SMPPCancelSMResp.cpp           SMPPEnquireLink.cpp      SMPPQuerySM.cpp               SMPPSubmitSMResp.cpp
 DecoderBase.cpp      SMPPBindTransceiverResp.cpp  SMPPCSVOutputter.cpp           SMPPEnquireLinkResp.cpp  SMPPQuerySMResp.cpp           SMPPTxtOutputter.cpp
 EncoderBase.cpp      SMPPBindTransmitter.cpp      SMPPDataSM.cpp                 SMPPGenericNack.cpp      SMPPReplaceSM.cpp             SMPPUnbind.cpp
 OutputterBase.cpp    SMPPBindTransmitterResp.cpp  SMPPDataSMResp.cpp             SMPPHexOutputter.cpp     SMPPReplaceSMResp.cpp         SMPPUnbindResp.cpp
)

add_library(smpp-static STATIC ${CMAKE_SOURCE_FILES})
set_target_properties(smpp-static  PROPERTIES OUTPUT_NAME smpp)
target_link_libraries(smpp-static ${Boost_LIBRARIES})

add_library(smpp-shared SHARED ${CMAKE_SOURCE_FILES})
set_target_properties(smpp-shared  PROPERTIES OUTPUT_NAME smpp)
target_link_libraries(smpp-shared ${Boost_LIBRARIES})

#add_executable(libsmpp-test test.cpp ${CMAKE_SOURCE_FILES})
#target_compile_definitions(libsmpp-test PUBLIC -DENABLE_TESTING)

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../.git)
  find_package(Git)
  if(GIT_FOUND)
    execute_process(
      COMMAND ${GIT_EXECUTABLE} describe
      WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
      OUTPUT_VARIABLE "GIT_VERSION"
      ERROR_QUIET
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    message( STATUS "Git version: ${GIT_VERSION}" )
  else(GIT_FOUND)
    set(GIT_VERSION unknown)
  endif(GIT_FOUND)
else(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../.git)
 set(GIT_VERSION unknown)
endif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../.git)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/git_version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/git_version.h @ONLY)

install(TARGETS smpp-static smpp-shared DESTINATION lib COMPONENT libraries)
install(FILES
 AntHillConstants.hpp  SMPPAlertNotification.hpp    SMPPBindTransmitterResp.hpp    SMPPDataSM.hpp         SMPPEnquireLinkResp.hpp       SMPPQuerySM.inl          SMPPSubmitSM.inl
 AntHill.hpp           SMPPAlertNotification.inl    SMPPBindTransmitterResp.inl    SMPPDataSM.inl         SMPPEnquireLinkResp.inl       SMPPQuerySMResp.hpp      SMPPSubmitSMResp.hpp
 AntHillSMPP.hpp       SMPPBind.hpp                 SMPPBroadcastSM.hpp            SMPPDataSMResp.hpp     SMPPFactory.hpp               SMPPQuerySMResp.inl      SMPPSubmitSMResp.inl
 BinaryDecoder.hpp     SMPPBind.inl                 SMPPBroadcastSM.inl            SMPPDataSMResp.inl     SMPPGenericNack.hpp           SMPPReplaceSM.hpp        SMPPTxtOutputter.hpp
 BinaryDecoder.inl     SMPPBindReceiver.hpp         SMPPBroadcastSMResp.hpp        SMPPDatatypes.hpp      SMPPGenericNack.inl           SMPPReplaceSM.inl        SMPPUnbind.hpp
 BinaryEncoder.hpp     SMPPBindReceiver.inl         SMPPBroadcastSMResp.inl        SMPPDatatypes.inl      SMPPHexOutputter.hpp          SMPPReplaceSMResp.hpp    SMPPUnbind.inl
 BinaryEncoder.inl     SMPPBindReceiverResp.hpp     SMPPCancelBroadcastSM.hpp      SMPPDecoder.hpp        SMPPOutbind.hpp               SMPPReplaceSMResp.inl    SMPPUnbindResp.hpp
 BinaryOutputter.hpp   SMPPBindReceiverResp.inl     SMPPCancelBroadcastSM.inl      SMPPDecoder.inl        SMPPOutbind.inl               SMPPResp.hpp             SMPPUnbindResp.inl
 ByteBuffer.hpp        SMPPBindResp.hpp             SMPPCancelBroadcastSMResp.hpp  SMPPDeliverSM.hpp      SMPPOutputterBase.hpp         SMPPResp.inl             SMPPValidator.hpp
 ByteBuffer.inl        SMPPBindResp.inl             SMPPCancelBroadcastSMResp.inl  SMPPDeliverSM.inl      SMPPPDU.hpp                   SMPPStructures.hpp       SMPPValidator.inl
 DecoderBase.hpp       SMPPBindTransceiver.hpp      SMPPCancelSM.hpp               SMPPDeliverSMResp.hpp  SMPPPDU.inl                   SMPPStructures.inl       SMPPXMLOutputter.hpp
 EncoderBase.hpp       SMPPBindTransceiver.inl      SMPPCancelSM.inl               SMPPDeliverSMResp.inl  SMPPQueryBroadcastSM.hpp      SMPPSubmitMulti.hpp      TextOutputter.hpp
 ISMPPOutputter.hpp    SMPPBindTransceiverResp.hpp  SMPPCancelSMResp.hpp           SMPPEncoder.hpp        SMPPQueryBroadcastSM.inl      SMPPSubmitMulti.inl      ValidatorBase.hpp
 OsSpecific.hpp        SMPPBindTransceiverResp.inl  SMPPCancelSMResp.inl           SMPPEncoder.inl        SMPPQueryBroadcastSMResp.hpp  SMPPSubmitMultiResp.hpp  XMLOutputter.hpp
 OutputterBase.hpp     SMPPBindTransmitter.hpp      SMPPConstants.hpp              SMPPEnquireLink.hpp    SMPPQueryBroadcastSMResp.inl  SMPPSubmitMultiResp.inl
 OutputterBase.inl     SMPPBindTransmitter.inl      SMPPCSVOutputter.hpp           SMPPEnquireLink.inl    SMPPQuerySM.hpp               SMPPSubmitSM.hpp
DESTINATION include/libsmpp COMPONENT headers)
################################################################
#enable_testing()
#set(CMAKE_CURRENT_TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../tests)
#set(CMAKE_CURRENT_TEST_TOOL ${CMAKE_CURRENT_BINARY_DIR}/libsmpp-test)

#add_test(NAME smpp-utf8-tc1 WORKING_DIRECTORY ${CMAKE_CURRENT_TESTS_DIR}  COMMAND ${CMAKE_CURRENT_TEST_TOOL} smpp utf8 tc1)
################################################################
#set(CPACK_GENERATOR "TZ;TGZ;STGZ;DEB;RPM") # Linux
#set(CPACK_GENERATOR "TZ;TGZ;STGZ")         # MacOS

set(CPACK_PACKAGE_NAME "libsmpp")
set(CPACK_PACKAGE_VENDOR "majoron.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Mariusz Ornowski <mariusz.ornowski@ict-project.pl>")
set(CPACK_RPM_PACKAGE_LICENSE "Apache Licence 2.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "libsmpp - The AntHill SMPP is a library (C++, Ruby) that implements SMPP protocol (v 3.4 & v 5.0 draft 6).")
set(CPACK_PACKAGE_VERSION ${GIT_VERSION})

set(CPACK_COMPONENTS_ALL libraries headers)

set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION "Libraries for libsmpp - The AntHill SMPP is a library (C++, Ruby) that implements SMPP protocol (v 3.4 & v 5.0 draft 6).")

set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C++ Headers")
set(CPACK_COMPONENT_HEADERS_DESCRIPTION  "C++ Headers for libsmpp - The AntHill SMPP is a library (C++, Ruby) that implements SMPP protocol (v 3.4 & v 5.0 draft 6).")
set(CPACK_COMPONENT_HEADERS_DEPENDS libraries)

include(CPack)
################################################################