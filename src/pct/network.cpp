/*
 * network.cpp
 *
 *  Created on: 3 Feb 2014
 *      Author: Dennis
 */
#include "network.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "smile.h"

#include "util\parser.hpp"

using std::cout;
using std::endl;

namespace pct {

string BayesianNetwork::displayPossibleAlgorithms() {
	vector<string> algs = vector<string>();

	algs.push_back("smile_lauritzen");
	algs.push_back("smile_henrion");
	algs.push_back("smile_pearl");
	algs.push_back("smile_lsampling");
	algs.push_back("smile_selfimportance");
	algs.push_back("smile_backsampling");
	algs.push_back("smile_aissampling");
	algs.push_back("smile_epissampling");
	algs.push_back("smile_lbp");
	algs.push_back("smile_lauritzen_old");

	string display = "";

	for( vector<string>::iterator it = algs.begin();
		 it != algs.end();
		 ++it )
	{
		display += "\t" + (*it) + "\n";
	}

	return display;
}

SMILEBayesianNetwork::SMILEBayesianNetwork() {
	net = DSL_network();
	nodes = map<string, int>();
}

SMILEBayesianNetwork::SMILEBayesianNetwork( DSL_network network ) {
	net = network;

	// make sure the names are mapped to the indexes (?)
	nodes = map<string, int>();
}

void SMILEBayesianNetwork::addNode( string name, vector<string> values ) {
	// Create the node and get the reference to it
	int node = net.AddNode( DSL_CPT, name.c_str() );

	// Add the possible states to it
	DSL_stringArray states;
	for( vector<string>::iterator it = values.begin(); it != values.end(); ++it ) {
		states.Add( (*it).c_str() );
	}

	net.GetNode(node)->Definition()->SetNumberOfOutcomes(states);
	nodes[name] = node;
}

void SMILEBayesianNetwork::addDependency( string from, string to ) {
	// Check if nodes exist
	if( nodes.find(from) == nodes.end() || nodes.find(to) == nodes.end() ) {
		cout << from << " or " << to << " does not exist." << endl;
		return;
	}

	net.AddArc( nodes[from], nodes[to] );
}

void SMILEBayesianNetwork::writeFile( string name, FileFormat format ) {
	switch(format) {
	case DSL:
		net.WriteFile( name.c_str() );
		break;
	default:
		cout << "This file format is not supported by this network type." << endl;
	}
}

void SMILEBayesianNetwork::setAlgorithm( string name ) {
	int alg;
    if(      name == "smile_lauritzen" ) {
		alg = DSL_ALG_BN_LAURITZEN;
	}
	else if( name == "smile_henrion" ) {
		alg = DSL_ALG_BN_HENRION ;
	}
	else if( name == "smile_pearl" ) {
		alg = DSL_ALG_BN_PEARL;
	}
	else if( name == "smile_lsampling" ) {
		alg = DSL_ALG_BN_LSAMPLING ;
	}
	else if( name == "smile_selfimportance" ) {
		alg = DSL_ALG_BN_SELFIMPORTANCE;
	}
	else if( name == "smile_backsampling" ) {
		alg = DSL_ALG_BN_BACKSAMPLING;
	}
	else if( name == "smile_aissampling" ) {
		alg = DSL_ALG_BN_AISSAMPLING;
	}
	else if( name == "smile_epissampling" ) {
		alg = DSL_ALG_BN_EPISSAMPLING;
	}
	else if( name == "smile_lbp" ) {
		alg = DSL_ALG_BN_LBP ;
	}
	else if( name == "smile_lauritzen_old" ) {
		alg = DSL_ALG_BN_LAURITZEN_OLD;
	}
	else {
		cout << "The requested algorithm was not found. Aborting." << endl;
		exit(EXIT_FAILURE);
	}

	net.SetDefaultBNAlgorithm( alg );
}

void SMILEBayesianNetwork::update() {
	net.UpdateBeliefs();
}

void SMILEBayesianNetwork::calculateDistribution( Query query ) {
	// Differentiate cases
	Variables priors = query.getPriors();
	Variables observed = query.getObserved();

	// 1. Only observed
	if( observed.size() == 1 && priors.size() == 0 ) {
		// 1a. Particular observed
		if( observed.at(0).instantiated ) {
			// TODO: add check for correct node/name here
			int node = net.FindNode( observed.at(0).name.c_str() );

			DSL_sysCoordinates coords(*net.GetNode(node)->Value());
		
			DSL_idArray* names;
			names = net.GetNode(node)->Definition()->GetOutcomesNames();

			int index = names->FindPosition( observed.at(0).instance.c_str() );
			coords[0] = index;
			coords.GoToCurrentPosition();

			double value = coords.UncheckedValue();
			std::ostringstream os;
			os << value;

			string result = observed.at(0).name + " " + observed.at(0).instance + '\n'
				+ os.str();

			std::ofstream file;
			file.open("result.txt");
			file << result;
			file.close();
		}
		// 1b. Uninstantiated observed
		// i.e. get the whole probability distribution over the node
		else {
			string result = "";

			int node = net.FindNode( observed.at(0).name.c_str() );

			result += observed.at(0).name;

			DSL_sysCoordinates coords(*net.GetNode(node)->Value());
		
			DSL_idArray* names;
			names = net.GetNode(node)->Definition()->GetOutcomesNames();

			result += '\n';

			int size = names->GetSize();

			for( int i = 0; i < size; i++ ) {
				coords[0] = i;
				coords.GoToCurrentPosition();

				double value = coords.UncheckedValue();
				std::ostringstream os;
				os << value;

				result += os.str() + ' ';
			}

			std::ofstream file;
			file.open("result.txt");
			file << result;
			file.close();
		}
	}
	// 2. Also priors
	else {
		// Set all the evidence
		for( Variables::iterator it = priors.begin();
			 it != priors.end();
			 ++it ) {
			int node = net.FindNode( it->name.c_str() );

			DSL_idArray* names;
			names = net.GetNode(node)->Definition()->GetOutcomesNames();

			int pos = names->FindPosition( it->instance.c_str() );

			// Set evidence
			net.GetNode(node)->Value()->SetEvidence(pos);
		}

		// Now get the result value
		int node = net.FindNode( observed.at(0).name.c_str() );

		DSL_sysCoordinates coords(*net.GetNode(node)->Value());

		DSL_idArray* names;
		names = net.GetNode(node)->Definition()->GetOutcomesNames();

		int index = names->FindPosition( observed.at(0).instance.c_str() );
		coords[0] = index;
		coords.GoToCurrentPosition();

		double value = coords.UncheckedValue();
		std::ostringstream os;
		os << value;

		string result = observed.at(0).name + " " + observed.at(0).instance + '\n'
			+ os.str();

		std::ofstream file;
		file.open("result.txt");
		file << result;
		file.close();
	}
}

}
