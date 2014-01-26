/*
 * @author Dennis Merkus
 */
#include <iostream>

using std::cout;
using std::endl;

using std::string;

void description() {
	cout << "Predictive Coding Toolbox by Dennis Merkus (dennis.merkus@gmail.com)" << endl;
}

int main( int argc, char *argv[] ) {
	description();

	// read command line parameters and decide what to do
	if( argc <= 1 ) {
		cout << "Usage: pct {command} [options]" << endl
			 << endl
			 << "For further help, type 'pct help'" << endl;
	}
	else {
		string command = argv[1];

		if( command == "help" ) {
			cout << "Possible commands: " << endl;
		}
		else {
			cout << "Invalid command." << endl;
		}
	}

	return 0;
}
