#ifndef PCNETWORK_HPP_
#define PCNETWORK_HPP_

#include "../network.hpp"

namespace pct {

namespace pc {

/**
 * A single network within the Predictive Coding framework.
 *
 * This network specifies both hypothesis nodes and prediction nodes.
 *
 * It is assumed the underlying bayesian network does not change during runtime.
 */
class PCNetwork {
private:
	string pcName;

	BayesianNetwork* network;

	vector<string> hypotheses;
	vector<string> predictions;

public:
	/**
	 * Create an empty, named network.
	 */
	PCNetwork( string name );

	/**
	 * Give an existing network a name.
	 */
	PCNetwork( string name, BayesianNetwork* net );

	/**
	 * Set an existing node within the network as a hypothesis node.
	 */
	void setHypothesis( string name );

	/**
	 * Set an existing node within the network as a prediction node.
	 */
	void setPrediction( string name );

	
	/**
	 * See whether the node with the specified name is a hypothesis node.
	 */
	bool isHypothesis( string name );
	
	/**
	 * See whether the node with the specified name is a prediction node.
	 */
	bool isPrediction( string name );

	/**
	 * Get a list of all the names of nodes that are hypothesis nodes.
	 */
	vector<string> getHypothesesNames();

	/**
	 * Get a list of all the names of nodes that are prediction nodes.
	 */
	vector<string> getPredictionsNames();

	/**
	 * Get a list of all possible values of the hypothesis node with the
	 * specified name.
	 */
	vector<string> getHypothesisValues( string name );

	/**
	 * Get a list of all possible values of the prediction node with the
	 * specified name.
	 */
	vector<string> getPredictionValues( string name );

	/**
	 * Receive the name that this part of the network has.
	 *
	 * Mostly used within hierarchies to specify connections.
	 */
	string getPCName();
};

}

}

#endif
