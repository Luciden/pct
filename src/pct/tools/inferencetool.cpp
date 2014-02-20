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
	required.push_back( Option( "outfile", Info::String ) );
	//required.push_back( Option( "query", Info::String ) );
	//required.push_back( Option( "algorithm", Info::String ) );

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
		/*
		cout << "Parsing query..." << endl;

		cout << "Query parsed and network prepared." << endl;
		*/
		/*
		string algorithmName = options.getInfo("algorithm").getStringValue();
		display("Initializing algorithm \"" + algorithmName + "\ ...", verbose);

		display("Algorithm initialized!", verbose);
		*/

		display("Performing inference", verbose);

		network.update();
		display("Inference complete.", verbose);

		// Give results
		string outfileName = options.getInfo("outfile").getStringValue();
		network.writeFile( outfileName );
		display("Wrote resulting network to\"" + outfileName + "\"!", verbose);
	}
	else {
		incorrectUsage();
	}

	return results;
}

void InferenceTool::parseQuery( string query ) {
	// find the queried nodes/variables
	vector<string> queried;
	// find the specified variables
	tuple<string, string> conditions;

	vector<Token> tokens = tokenizeQuery( query );

	ParseState s = Start;

	for( vector<Token>::iterator it = tokens.begin();
		 it != tokens.end();
		 ++it ) {
		switch(s) {
		case Start:
		
			break;
		}
	}
}

vector<InferenceTool::Token> InferenceTool::tokenizeQuery( string query ) {
	vector<InferenceTool::Token> tokens = vector<InferenceTool::Token>();

	return tokens;
}

}
