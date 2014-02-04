/** @file pct.hpp
 *
 *
 *  Created on: 26 Jan 2014
 * @author Dennis Merkus
 */

#ifndef PCT_HPP_
#define PCT_HPP_

#include <string>

#include "option.hpp"
#include "result.hpp"

using std::string;

namespace pct {

class PredictiveCodingToolbox {
public:
	/**
	 * 
	 */
	Options parseCommand( int argc, char* argv[] );

	Results useTool( string name, Options opts );
};

}

#endif /* PCT_HPP_ */
