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

#ifndef ANTHILLSMPP_HPP
#define ANTHILLSMPP_HPP

// C++ Standard Libraries (STL, ANSI C)
#include <stdio.h>
#include <exception>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <typeinfo>
#include <string>
#include <list>
#include <map>
#include <algorithm>

// Boost library
#include <boost/tokenizer.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/recursive_mutex.hpp>

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

// AntHill
#include "AntHill.hpp"
#include "ByteBuffer.hpp"

// Current library
#include "SMPPConstants.hpp"


#ifndef ANTHILLSMPP_DLLPRFX
	#ifdef WIN32
		#ifdef ANTHILLSMPP_EXPORTS
			#define ANTHILLSMPP_DLLPRFX __declspec(dllexport)
		#else
			#define ANTHILLSMPP_DLLPRFX __declspec(dllimport)
		#endif
	#else
		#define ANTHILLSMPP_DLLPRFX
	#endif
#endif


#define ANTHILLSMPP_VERSION_STR		"0.5.0"



#endif // ANTHILLSMPP_HPP
