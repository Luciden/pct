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

/**
 * Interface for a set of functions that can be called from the command line.
 *
 */
class Tool {
private:
	/**
	 * Typesets usage information for the current tool.
	 */
	string makeOptionUsage( string name, Info::Type type );

protected:
	string name;
	string description;

	OptionList required;
	OptionList optional;

	/**
	 * See if all required options are specified.
	 */
	bool checkOptions( InfoSet options );

	/**
	 * Debugging information.
	 */
	void display( string msg, bool verbose );

	/**
	 * Writes a result to the specified file.
	 */
	void outputResult( string file, string result );

public:
	/**
	 * Executes the tool with the specified options.
	 */
	virtual InfoSet run( InfoSet options ) = 0;

	string getName();
	
	string getDescription();

	string getUsage();

	/**
	 * Displays information if the tool was used incorrectly.
	 */
	void incorrectUsage();

	/**
	 * Gives information for a particular command with the specified
	 * name.
	 */
	virtual string getOptionHelp( string name ) = 0;
};

}

#endif /* TOOL_HPP_ */
