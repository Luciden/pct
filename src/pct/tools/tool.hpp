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
#include <tuple>

#include "../infoset.hpp"

using std::vector;
using std::string;
using std::tuple;

namespace pct {

typedef tuple<string, Info::Type> Option;
typedef vector<Option> OptionList;

class Tool {
private:
	string makeOptionUsage( string name, Info::Type type );

protected:
	string name;
	string description;

	OptionList required;
	OptionList optional;

public:
	virtual InfoSet run( InfoSet options ) = 0;

	string getName();
	
	string getDescription();

	string getUsage();
};

}

#endif /* TOOL_HPP_ */
