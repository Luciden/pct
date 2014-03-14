/** @file network.hpp
 */
#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <map>
#include "smile.h"

#include "util\parser.hpp"

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
	virtual void addNode( string name, vector<string> values ) =0;

	virtual void addDependency( string from, string to ) =0;

	virtual void writeFile( string name, FileFormat format = DSL ) =0;

	static string displayPossibleAlgorithms();

	virtual void setAlgorithm( string name ) =0;
	virtual void update() = 0;

	virtual void calculateDistribution( Query query ) =0;
};

class SMILEBayesianNetwork : public BayesianNetwork {
private:
	DSL_network net;
	map<string, int> nodes; /**< map node names to their indexes in the DSL_network */

public:
	SMILEBayesianNetwork();
	SMILEBayesianNetwork( DSL_network network );

	virtual void addNode( string name, vector<string> values );
	virtual void addDependency( string from, string to );
	virtual void writeFile( string name, FileFormat format );

	virtual void setAlgorithm( string name );
	virtual void update();

	virtual void calculateDistribution( Query query );
};

}

#endif /* NETWORK_HPP_ */
