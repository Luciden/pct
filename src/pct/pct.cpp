/*
 * pct.cpp
 *
 *  Created on: 27 Jan 2014
 *      Author: Dennis
 */
#include "pct.hpp"
#include "infoset.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

namespace pct {

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

}
