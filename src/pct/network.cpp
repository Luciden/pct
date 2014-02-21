/*
 * network.cpp
 *
 *  Created on: 3 Feb 2014
 *      Author: Dennis
 */
#include "network.hpp"

#include <iostream>

#include "smile.h"

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
	cout << "setting" << name << endl;
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

}
