/*
 * network.hpp
 *
 *  Created on: 26 Jan 2014
 *      Author: Dennis
 */

// TODO

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include "smile.h"

using std::string;
using std::vector;
using std::map;

namespace pct {

enum FileFormat {
	DSL,
	TXT
};

class BayesianNetwork {
private:
public:
	BayesianNetwork();

	virtual void addNode( string name, vector<string> values ) = 0;

	virtual void addDependency( string from, string to ) = 0;

	virtual void writeFile( string name, FileFormat format ) = 0;
};

class SMILEBayesianNetwork : public BayesianNetwork {
private:
	DSL_network net;
	map<string, int> nodes;

public:
	SMILEBayesianNetwork();
};

}

#endif /* NETWORK_HPP_ */
