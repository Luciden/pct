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

}
