/*
 * pct.cpp
 *
 *  Created on: 27 Jan 2014
 *      Author: Dennis
 */
#include "pct.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

#include "infoset.hpp"

#include "tools/tool.hpp"
#include "tools/inferencetool.hpp"

namespace pct {

PredictiveCodingToolbox::PredictiveCodingToolbox() {
	tools = vector<Tool*>();

	tools.push_back( new InferenceTool() );
}

void PredictiveCodingToolbox::run( string command, InfoSet options ) {
	if( command == "about" ) {
		about();
	}
	else if( command == "help" ) {
		help();
	}
	else if( command == "list" ) {
		list();
	}
	else {
		useTool( command, options );
	}
}

InfoSet PredictiveCodingToolbox::parseCommand( int argc, char* argv[] ) {
	InfoSet opts = InfoSet();

	// parse all arguments
	for( int i = 2; i < argc; i++ ) {
		// TODO make simple argument parser with names, name:value
		// this is dependent on the tool used.
		string p = argv[i];

		// Find if it is properly structured and split the name and value
		string::size_type pos = p.find(":");
		if( pos != string::npos ) {
			string name = p.substr(0, pos);
			string value = p.substr(pos + 1);

			// Create the Option
			char* p;
			long number = strtol( value.c_str(), &p, 10 );
			if(*p) {
				// The value was not a number
			}
			else {
				opts.addInfo( Info( name, number ) );
			}
		}
		else {
			cout << "The parameter " << p << " was not properly structured." << endl;
		}
	}

	return opts;
}

InfoSet PredictiveCodingToolbox::useTool( string name, InfoSet opts ) {
	cout << "using the " << name << " tool." << endl;
	// Check if tool exists


	// Check if required options are available

	// Run tool
	InfoSet results = InfoSet();

	// Give results
	return results;
}

void PredictiveCodingToolbox::list() {
	cout << "Available tools:" << endl;

	for( vector<Tool*>::iterator it = tools.begin();
		 it != tools.end();
		 ++it ) {
		Tool* tp = (*it);

		cout << "  " + tp->getName() + "\t" + tp->getDescription() << endl;
		cout << "    " + tp->getUsage() << endl;
	}
}

void PredictiveCodingToolbox::help() {
	cout << "Possible commands:" << endl
		 << "\tabout\tinformation about this toolbox" << endl
		 << "\thelp \tthis help information" << endl
		 << "\tlist \tlist all available tools" << endl;
}

void PredictiveCodingToolbox::about() {
	cout << "Predictive Coding Toolbox by Dennis Merkus (dennis.merkus@gmail.com)" << endl
	     << "This toolbox uses the SMILE library (provided on an \"as is\" basis). Available at http://genie.sis.pitt.edu/" << endl;
}

}
