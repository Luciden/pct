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
 * It is assumed the underlying network does not change during runtime.
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

	bool isHypothesis( string name );
	bool isPrediction( string name );

	vector<string> getHypotheses();
	vector<string> getPredictions();

	vector<string> getHypothesisValues( string name );
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
