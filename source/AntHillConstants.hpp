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

#ifndef ANTHILLCONSTANTS_HPP
#define ANTHILLCONSTANTS_HPP

namespace anthill {

	/**
	 * Namespace contains errors code for reporting.
	 */
	const std::string MODULE_PREFIX("AntHill");

	/**
	 * Namespace contains errors code for reporting.
	 */
	namespace CodecErrors{
		const std::string DECODER_INV_SKIPPING = "Unable to padding. Offset is: %1%.";
		const std::string DECODER_INV_PADDING = "Unable to padding. Offset is: %1%.";
		const std::string DECODER_INV_CHAR = "Unable to decode char. Offset is: %1%.";
		const std::string DECODER_INV_UNSIGNED_CHAR = "Unable to decode unsigned char. Offset is: %1%.";

		const std::string DECODER_INV_INTEGER32 = "Unable to decode integer32. Offset is: %1%.";
		const std::string DECODER_INV_INTEGER24 = "Unable to decode integer24. Offset is: %1%.";
		const std::string DECODER_INV_INTEGER16 = "Unable to decode integer16. Offset is: %1%.";

		const std::string DECODER_INV_UNSIGNED32 = "Unable to decode integer32. Offset is: %1%.";
		const std::string DECODER_INV_UNSIGNED24 = "Unable to decode integer24. Offset is: %1%.";
		const std::string DECODER_INV_UNSIGNED16 = "Unable to decode integer16. Offset is: %1%.";

		const std::string DECODER_INV_CSTRING = "Unable to decode cstring. Offset is: %1%.";
		const std::string DECODER_OVERFLOW_CSTRING = "Unable to decode cstring due to overflow. Offset is: %1%.";
		const std::string DECODER_INV_BINARY = "Unable to decode cstring. Offset is: %1%.";

		const std::string DECODER_INV_OFFSET = "Unable to decode package. Offset after decoding is not equal to length. Offset is: %1%. Lenght is: %2%";
		const std::string DECODER_DUE_TO_LIMIT = "Unable to decode package. Offset after decoding is greater than length. Offset is: %1%. Lenght is: %2%";
	}

		/**
		 * Namespace contains errors code for reporting.
		 */
		namespace Errors{
			/**
			 * Error ...
			 */
			const std::string INVALID_DUMP_FORMAT = "Unsupportable dump format. Supportable formats are 01 FF or 1 A.";
			const std::string UNABLE_TO_LOAD_MODULES_FACTORY = "Error: unable to load modules factory.";
			const std::string UNABLE_TO_LOAD_TRANSPORT_MODULE = "Error: unable to load transport module: %1%.";
			const std::string UNABLE_TO_LOAD_TRANSPORT_FACTORY = "Error: unable to load transport factory at transport module.";
		}

}

#endif // ANTHILLCONSTANTS_HPP
