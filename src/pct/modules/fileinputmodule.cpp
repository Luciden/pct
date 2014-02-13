#include "fileinputmodule.hpp"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

#include "smile.h"

namespace pct {

SMILEBayesianNetwork FileInputModule::load( string name ) {
	cout << "Loading file " << name << endl;
	DSL_network net;

	net.ReadFile( name.c_str() );

	return SMILEBayesianNetwork( net );
}

}
