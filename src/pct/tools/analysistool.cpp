#include "analysistool.hpp"

#include <tuple>
#include <iostream>
#include <ctime>

#include "../infoset.hpp"
#include "../network.hpp"

#include "../modules/fileinputmodule.hpp"

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
	required.push_back( Option( "infile", Info::String ) );
	required.push_back( Option( "timefile", Info::String ) );
	required.push_back( Option( "divergencefile", Info::String ) );
}

InfoSet AnalysisTool::run( InfoSet options ) {
	InfoSet results = InfoSet();
	bool verbose = options.isSet("verbose");

	display("Checking options...", verbose );
	if( checkOptions( options ) ) {
		display("Options O.K.", verbose);

		// Load a network from a file
		string infileName = options.getInfo("infile").getStringValue();
		display("Loading network from file \"" + infileName + "\"...", verbose);

		BayesianNetwork* network = &FileInputModule::load( infileName );
		display("Loading O.K.", verbose);

		// Run inference algorithm
		/*
		cout << "Parsing query..." << endl;

		cout << "Query parsed and network prepared." << endl;
		*/
		/*
		string algorithmName = options.getInfo("algorithm").getStringValue();
		display("Initializing algorithm \"" + algorithmName + "\ ...", verbose);

		display("Algorithm initialized!", verbose);
		*/

		// Time the algorithm
		display("Performing inference", verbose);
		clock_t T_start = clock();
		network->update();
		clock_t T_end = clock();
		display("Inference complete.", verbose);

		// Find the divergence
		// (placeholder)


		// Give results
		outputResult( options.getInfo("timefile").getStringValue(), std::to_string((long double)(T_end - T_start) / CLOCKS_PER_SEC) );
		outputResult( options.getInfo("divergencefile").getStringValue(), std::to_string((long double)0.0f));
	}
	else {
		incorrectUsage();
	}

	return results;
}

string AnalysisTool::getOptionHelp( string name ) {
	cout << "getting help for " << name << endl;
	if( name == "algorithm" ) {
		return SMILEBayesianNetwork::displayPossibleAlgorithms();
	}
	else {
		return "No help.";
	}
}

}
