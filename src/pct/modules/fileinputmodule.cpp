#include "fileinputmodule.hpp"

#include <string>

#include "smile.h"

namespace pct {

SMILEBayesianNetwork FileInputModule::load( string name ) {
	DSL_network net;

	net.ReadFile( name.c_str() );

	return SMILEBayesianNetwork( net );
}

}
