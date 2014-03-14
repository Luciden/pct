#include "inferencetool.hpp"

#include <tuple>
#include <iostream>

#include "../infoset.hpp"
#include "../network.hpp"

#include "../modules/fileinputmodule.hpp"

using std::cout;
using std::endl;
using std::tuple;

namespace pct {

InferenceTool::InferenceTool() {	
	name = "inference";
	description = "Calculate probability distributions of a network.";

	required = OptionList();
	optional = OptionList();

	required.push_back( Option( "infile", Info::String ) );
	required.push_back( Option( "algorithm", Info::String ) );
	required.push_back( Option( "query", Info::String ) );

	optional.push_back( Option( "samples", Info::Integer ) );
}

InfoSet InferenceTool::run( InfoSet options ) {
	InfoSet results = InfoSet();
	bool verbose = options.isSet("verbose");

	display("Checking options...", verbose );
	if( checkOptions( options ) ) {
		display("Options O.K.", verbose);

		// Load a network from a file
		string infileName = options.getInfo("infile").getStringValue();
		display("Loading network from file \"" + infileName + "\"...", verbose);

		SMILEBayesianNetwork network = FileInputModule::load( infileName );
		display("Loading O.K.", verbose);

		// Run inference algorithm
		display("Parsing query...", verbose);
		Parser parser = Parser();

		Query query = parser.parse( options.getInfo("query").getStringValue() );
		display("Query parsed and network prepared.", verbose);
		
		string algorithmName = options.getInfo("algorithm").getStringValue();
		display("Initializing algorithm \"" + algorithmName + "\" ...", verbose);
		network.setAlgorithm(algorithmName);
		display("Algorithm initialized!", verbose);

		display("Performing inference", verbose);
		network.calculateDistribution( query );
		display("Inference complete.", verbose);
	}
	else {
		incorrectUsage();
	}

	return results;
}

string InferenceTool::getOptionHelp( string name ) {
	cout << "getting help for " << name << endl;
	if( name == "algorithm" ) {
		return SMILEBayesianNetwork::displayPossibleAlgorithms();
	}
	else {
		return "No help.";
	}
}

}
