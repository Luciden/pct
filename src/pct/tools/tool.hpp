/*
 * tool.hpp
 *
 *  Created on: 3 Feb 2014
 *      Author: Dennis
 */

#ifndef TOOL_HPP_
#define TOOL_HPP_

#include <string>

using std::string;

namespace pct {

class Tool {
protected:
	string name;
	string usage;
	string description;

public:
	virtual Results run( Options opts ) = 0;
};

}

#endif /* TOOL_HPP_ */
