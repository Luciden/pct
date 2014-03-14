#ifndef PCNETWORK_HPP_
#define PCNETWORK_HPP_

#include "../network.hpp"

namespace pct {

namespace pc {

/**
 * A single network within the Predictive Coding framework.
 *
 * This network specifies both hypothesis nodes and prediction nodes.
 */
class PCNetwork {
private:
	string pcName;

	BayesianNetwork* network;

	vector<string> hypotheses;
	vector<string> predictions;

public:
	PCNetwork( string name );
	PCNetwork( string name, BayesianNetwork* net );

	void setHypothesis( string name );
	void setPrediction( string name );

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
