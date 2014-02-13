#include "analysistool.hpp"

#include <tuple>
#include <iostream>

#include "../infoset.hpp"
#include "../network.hpp"

using std::cout;
using std::endl;
using std::tuple;

namespace pct {

AnalysisTool::AnalysisTool() {	
	name = "analyze";
	description = "Analyze an algorithm.";

	required = OptionList();
	optional = OptionList();

	required.push_back( Option( "algorithm", Info::String ) );
}

InfoSet AnalysisTool::run( InfoSet options ) {
	InfoSet results = InfoSet();

	return results;
}

}
