#include "inferencetool.hpp"

#include <tuple>

#include "../infoset.hpp"

using std::tuple;

namespace pct {

InferenceTool::InferenceTool() {	
	name = "inference";
	description = "Calculate probability distributions of a network.";

	required = OptionList();
	optional = OptionList();

	required.push_back( Option( "file", Info::String ) );
	required.push_back( Option( "dist", Info::String ) );
}

InfoSet run( InfoSet options ) {

}

}
