/*
 * @author Dennis Merkus
 */
#include <iostream>

#include "pct.hpp"

using namespace pct;

using std::cout;
using std::endl;

using std::string;

void description() {
	cout << "Predictive Coding Toolbox by Dennis Merkus (dennis.merkus@gmail.com)" << endl;
	cout << "This toolbox uses the SMILE library (provided on an \"as is\" basis)." << endl;
}

int main( int argc, char *argv[] ) {
	description();

	PredictiveCodingToolbox tb = PredictiveCodingToolbox();

	// read command line parameters and decide what to do
	if( argc <= 1 ) {
		cout << "Usage: pct {command} [options]" << endl
			 << endl
			 << "For a list of possible commands and their options, type 'pct help'" << endl;
	}
	else {
		string command = argv[1];
		Options opts = tb.parseCommand( argc, argv );

		if( command == "help" ) {
			cout << "Possible : " << endl
			     << "analysis" << endl
			     << "inference" << endl;
		}
		else if( command == "analysis" ) {
			tb.useTool( command, opts );
		}
		else if( command == "inference" ) {

		}
		else {
			cout << "Invalid command \"" << argv[1] << "\"" << endl;
		}
	}

	return 0;
}
