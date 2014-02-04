/*
 * network.hpp
 *
 *  Created on: 26 Jan 2014
 *      Author: Dennis
 */
#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <map>
#include "../libSMILE/smile.h"

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

	virtual void addNode( string name, vector<string> values );
	virtual void addDependency( string from, string to );
	virtual void writeFile( string name, FileFormat format );
};

}

#endif /* NETWORK_HPP_ */
