/*
 * tool.hpp
 *
 *  Created on: 3 Feb 2014
 *      Author: Dennis
 */

#ifndef TOOL_HPP_
#define TOOL_HPP_

#include <string>
#include <vector>

#include "../result.hpp"
#include "../option.hpp"

using std::vector;
using std::string;

namespace pct {

class Tool {
protected:
	string name;
	string description;

	vector<string> required;
	vector<string> optional;

public:
	virtual Results run( Options opts ) = 0;

	string getName();
	
	string getDescription();

	string getUsage();
};

}

#endif /* TOOL_HPP_ */
