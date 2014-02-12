/** @file pct.hpp
 *
 */

#ifndef PCT_HPP_
#define PCT_HPP_

#include <string>

#include "infoset.hpp"

using std::string;

namespace pct {

/** Main class for the Predictive Coding Toolbox.
 *
 * This class links all the parts in the toolbox together.
 * It is also responsible for parsing the command line.
 */
class PredictiveCodingToolbox {
public:
	/**
	 * 
	 */
	InfoSet parseCommand( int argc, char* argv[] );

	InfoSet useTool( string name, InfoSet opts );
};

}

#endif /* PCT_HPP_ */
