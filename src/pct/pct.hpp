/** @file pct.hpp
 *
 *
 *  Created on: 26 Jan 2014
 * @author Dennis Merkus
 */

#ifndef PCT_HPP_
#define PCT_HPP_

#include <string>

#include "infoset.hpp"

using std::string;

namespace pct {

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
