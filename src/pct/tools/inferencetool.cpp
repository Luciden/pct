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

	required.push_back( Option( "filename", Info::String ) );
	//required.push_back( Option( "query", Info::String ) );
	//required.push_back( Option( "algorithm", Info::String ) );
}

InfoSet InferenceTool::run( InfoSet options ) {
	InfoSet results = InfoSet();

	std::cout << "Checking options..." << std::endl;
	if( checkOptions( options ) ) {
		cout << "Options O.K." << endl;

		// Load a network from a file
		cout << "Loading network..." << endl;

		Info fileInfo = options.getInfo("filename");
		string fileName = fileInfo.getStringValue();

		SMILEBayesianNetwork network = FileInputModule::load( fileName );
		cout << "Loading O.K." << endl;

		// Run inference algorithm
		/*
		cout << "Parsing query..." << endl;

		cout << "Query parsed and network prepared." << endl;
		*/
		/*
		cout << "Initializing algorithm..." << endl;

		cout << "Algorithm initialized." << endl;
		*/

		cout << "Performing inference" << endl;
		for( int i = 0; i < 100; i++ ) {
			network.update();
		}
		cout << "Inference complete." << endl;

		// Give results
		network.writeFile( "updated.xdsl" );
		cout << "Wrote the result to 'updated.xdsl'" << endl;
	}
	else {
		std::cout << "Some required options are not specified" << std::endl;
		std::cout << getUsage() << std::endl;
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
