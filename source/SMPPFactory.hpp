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

#ifndef SMPPFACTORY_HPP
#define SMPPFACTORY_HPP

#include "ISMPPClient.hpp"
#include "ISMPPServer.hpp"
#include "IReliableNetwork.hpp"
#include "SMPPSharedResources.hpp"


namespace anthill {
	namespace smpp {

		class ISMPPServerListener;
		class ISMPPSessionListener;

		/**
		 * A SMPP client 
		 */
		class ANTHILLSMPP_DLLPRFX SMPPFactory {
		public:
			SMPPFactory();
			virtual ~SMPPFactory();

			static SMPPFactory* getInstance(void);

			ISMPPServer::SharedPtr createSMPPServer(IReliableNetwork::SharedPtr poNetwork, ISMPPServerListener* poListener = NULL);
			ISMPPClient::SharedPtr createSMPPClient(IReliableNetwork::SharedPtr poNetwork, ISMPPSessionListener* poListener = NULL);

			ISMPPServer::SharedPtr createSMPPServer(IReliableNetwork::SharedPtr poNetwork, ICoordinator::SharedPtr poCoordinator, ISMPPServerListener* poListener = NULL);
			ISMPPClient::SharedPtr createSMPPClient(IReliableNetwork::SharedPtr poNetwork, ICoordinator::SharedPtr poCoordinator, ISMPPSessionListener* poListener = NULL);

		private:
			static SMPPFactory m_oInstance;
			SMPPSharedResources::SharedPtr m_poSharedResources;
			boost::recursive_mutex m_mxFactory;
		};
	}
}

#endif // SMPPFACTORY_HPP
