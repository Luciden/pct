/** @file pct.hpp
 *
 */

#ifndef PCT_HPP_
#define PCT_HPP_

#include <string>

#include "infoset.hpp"
#include "tools/tool.hpp"

using std::string;

/**
 * Contains everything that is part of the Predictive Coding Toolbox.
 */
namespace pct {

/**
 * Contains the parts that the Toolbox was specifically made for.
 */
namespace pc {}

/** Main class for the Predictive Coding Toolbox.
 *
 * This class links all the parts in the toolbox together.
 * It is also responsible for parsing the command line.
 */
class PredictiveCodingToolbox {
private:
	vector<Tool*> tools;

	bool hasTool( string name );
	Tool* fetchTool( string name );

public:
	/**
	 * Initializes all tools for use.
	 *
	 * If any new tools are added, they should be added to the toolbox here.
	 */
	PredictiveCodingToolbox();

	/**
	 * Executes the toolbox.
	 */
	void run( string command, int argc, char* argv[] );

	/**
	 * Takes the command line arguments and parses them for use with the
	 * toolbox.
	 */
	InfoSet parseCommand( int argc, char* argv[] );

	InfoSet useTool( string name, InfoSet opts );

	/**
	 * List all available tools.
	 */
	void list();

	/**
	 * Display some information about the toolbox.
	 */
	void about();

	/**
	 * Display help about the possible commands and tools.
	 */
	void help();
};

}

#endif /* PCT_HPP_ */
