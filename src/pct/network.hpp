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

/**
 * A general interface for a Bayesian Network that has the functionality
 * for use with the Predictive Coding Toolbox.
 */
class BayesianNetwork {
private:
public:
	/**
	 * Add a new node to the rest of the network.
	 *
	 * @param name node's name
	 * @param values all possible values/outcomes for the node
	 */
	virtual void addNode( string name, vector<string> values ) =0;

	/**
	 * Add a dependency between two existing nodes.
	 */
	virtual void addDependency( string from, string to ) =0;

	/**
	 * Write a file reprentation of the network in its current state.
	 *
	 * @param format file format to use
	 */
	virtual void writeFile( string name, FileFormat format = DSL ) =0;

	/**
	 * Displays all possible algorithms that can be used with the network.
	 */
	static string displayPossibleAlgorithms();


	/**
	 * Prepare the algorithm that is to be used when updating the network.
	 */
	virtual void setAlgorithm( string name ) =0;

	/**
	 * Update the network.
	 *
	 * This changes the nodes' values instead of returning anything.
	 */
	virtual void update() = 0;

	/**
	 * Calculate the probability (distribution) for a given query.
	 *
	 * See @ref manual_query .
	 */
	virtual void calculateDistribution( Query query ) =0;

	/**
	 * See whether a node with the specified name exists in the network.
	 */
	virtual bool nodeExists( string name ) =0;
	
	/**
	 * Get all possible outcomes for the node with the specified name.
	 */
	virtual vector<string> getNodeValues( string name ) =0;
};

/**
 * Essentially a wrapper for the Bayesian network from the SMILE library.
 */
class SMILEBayesianNetwork : public BayesianNetwork {
private:
	DSL_network net;
	map<string, int> nodes; /**< map node names to their indexes in the DSL_network */

public:
	/**
	 * Create an empty network.
	 */
	SMILEBayesianNetwork();

	/**
	 * Create a network from an existing network supplied by the SMILE
	 * library.
	 */
	SMILEBayesianNetwork( DSL_network network );

	virtual void addNode( string name, vector<string> values );
	virtual void addDependency( string from, string to );
	virtual void writeFile( string name, FileFormat format );

	virtual void setAlgorithm( string name );
	virtual void update();

	virtual void calculateDistribution( Query query );

	virtual bool nodeExists( string name );

	virtual vector<string> getNodeValues( string name );
};

}

#endif /* NETWORK_HPP_ */
