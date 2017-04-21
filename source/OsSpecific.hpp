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

#ifndef OSSPECIFIC_HPP
#define OSSPECIFIC_HPP

	#ifdef HAVE_CONFIG_H
		#include "../../Workspaces/autotools/config.h"
	#else
		#define HAVE_STL_WSTRING
	#endif	

	#ifdef WIN32
		#define NOMINMAX // Disable microsoft stupid min/max macros which conflicts with std::min/max functions
		#include <windows.h>

		// DLLs
		typedef HMODULE dlhandle_t;

		// HRTIME
		typedef unsigned __int64 hrtime_t;

		// Shared mem defines
		typedef HANDLE shmutex_t;
		typedef HANDLE shsema_t;
		typedef HANDLE shmemory_t;

		// Processes
		#include <process.h>		
		typedef intptr_t spawn_pid_t;
		
		// Threads
		typedef intptr_t thread_id_t;

		#define HAVE_STL_WSTRING


	#else			
		#include <dlfcn.h>
		#include <sys/types.h>
		#include <errno.h>
		#include <netinet/in.h>
		#include <stdarg.h>

		typedef void* dlhandle_t;

		// HRTIME
		#include <sys/time.h>
		#ifdef __APPLE__
			#include <mach/mach.h>
			#include <mach/mach_time.h>		
			typedef uint64_t hrtime_t;
		#else
			typedef long long hrtime_t;
		#endif

		// Shared mem defines
		#include <sys/ipc.h>
		#include <sys/sem.h>
		#include <sys/shm.h>
			
		typedef int shmutex_t;
		typedef int shsema_t;
		typedef int shmemory_t;

		// Processes
		#include <unistd.h>
		#include <sys/wait.h>
		typedef pid_t spawn_pid_t;
		
		// Threads
		#ifndef __APPLE__
			typedef pthread_t thread_id_t;
		#else
			#include <CoreServices/CoreServices.h>	
			typedef MPTaskID thread_id_t;
		#endif			
		 
	#endif

	// HASH_MAP
	#ifdef _STLPORT
		#define HASH_MAP_INCLUDE <hash_map>
		#define HASH_MAP_USAGE std::hash_map
	#else
		#ifdef WIN32
			#define HASH_MAP_INCLUDE <hash_map>
			#define HASH_MAP_USAGE stdext::hash_map
		#else
			#define HASH_MAP_INCLUDE <ext/hash_map>
			#define HASH_MAP_USAGE __gnu_cxx::hash_map
		#endif
	#endif

	#ifdef WIN32
		#define OS_SHARED_LIBRARY_POSTFIX ".dll"				
	#elif __APPLE__
		#define OS_SHARED_LIBRARY_POSTFIX ".dylib"				
	#else
		#define OS_SHARED_LIBRARY_POSTFIX ".so"		
	#endif
		
	// Errors
	inline std::string getLastOSErrorString() {
		#ifdef WIN32
			CHAR szBuf[1024]={0};
			DWORD dwError = GetLastError();
			if ( FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, 
								NULL, dwError,
								0, 
								szBuf, 1023, NULL)!=0 ){
				CharToOemA(szBuf,szBuf);
				return std::string(szBuf);
			}
				
			else
				return std::string("Unknown error!");
		#else
			return strerror(errno);			
		#endif
	}

	inline int getLastOSError() {
		#ifdef WIN32
			return GetLastError();
		#else
			return errno;
		#endif
	}

	// NTOHLL/HTONLL defs
	#if !defined(HAVE_HTONLL) && !defined(ntohll)
		#define ntohll(x) (((boost::int64_t)(ntohl((int)((x << 32) >> 32))) << 32) | (unsigned int)ntohl(((int)(x >> 32))))
		#define htonll(x) ntohll(x)
	#endif

	inline bool isBigEndian() { 
		return( htonl(1)==1 ); 
	}

#endif // OSSPECIFIC_HPP
