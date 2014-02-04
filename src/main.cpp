/*
 * @author Dennis Merkus
 */
#include <iostream>

#include "pct/pct.hpp"

using namespace pct;

using std::cout;
using std::endl;

using std::string;

void description() {
	cout << "Predictive Coding Toolbox by Dennis Merkus (dennis.merkus@gmail.com)" << endl;
	cout << "This toolbox uses the SMILE library (provided on an \"as is\" basis). Available at http://genie.sis.pitt.edu/" << endl;
}

int main( int argc, char *argv[] ) {
	PredictiveCodingToolbox tb = PredictiveCodingToolbox();

	// read command line parameters and decide what to do
	if( argc <= 1 ) {
		cout << "Usage: pct {command} [options]" << endl
			 << endl
			 << "For a list of possible commands and their options, type 'pct help'" << endl;
	}
	else {
		string command = argv[1];

		if( command == "about" ) {
			description();
		}
		else if( command == "help" ) {
			cout << "Possible commands: " << endl
				 << "about" << "\t\t information about this toolbox" << endl
				 << "help" << "\t\t this help" << endl
			     << "analysis" << endl
			     << "inference" << endl;
		}
		else {
			Options opts = tb.parseCommand( argc, argv );
			tb.useTool( command, opts );
		}
	}

	return 0;
}
