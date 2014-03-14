/*
 * @author Dennis Merkus
 */
#include <iostream>

#include "pct/pct.hpp"

using namespace pct;

using std::cout;
using std::endl;

using std::string;

#ifdef RUNTESTS

#include "test/test.hpp"

int main( int argc, char *argv[] ) {
	Test t = Test();

	t.runTests();
}
#else
int main( int argc, char *argv[] ) {
	PredictiveCodingToolbox toolbox = PredictiveCodingToolbox();

	// read command line parameters and decide what to do
	if( argc <= 1 ) {
		cout << "Usage: pct {command} [options]" << endl
			 << endl
			 << "For a list of possible commands and their options, type 'pct help'" << endl;
	}
	else {
		toolbox.run( argv[1], argc, argv );
	}

	return 0;
#endif

}
