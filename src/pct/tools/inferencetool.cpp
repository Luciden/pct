#include "inferencetool.hpp"

#include <tuple>
#include <iostream>

#include "../infoset.hpp"
#include "../network.hpp"

#include "../modules/fileinputmodule.hpp"

using std::tuple;

namespace pct {

InferenceTool::InferenceTool() {	
	name = "inference";
	description = "Calculate probability distributions of a network.";

	required = OptionList();
	optional = OptionList();

	required.push_back( Option( "filename", Info::String ) );
	required.push_back( Option( "query", Info::String ) );
	required.push_back( Option( "algorithm", Info::String ) );
}

InfoSet InferenceTool::run( InfoSet options ) {
	InfoSet results = InfoSet();

	if( checkOptions( options ) ) {
		// Load a network from a file
		SMILEBayesianNetwork network = FileInputModule::load( options.getInfo("file").getStringValue() );

		// Run inference algorithm


		// Give results


	}
	else {
		std::cout << "Some options are not specified" << std::endl;
		std::cout << getUsage() << std::endl;
	}

	return results;
}

}
