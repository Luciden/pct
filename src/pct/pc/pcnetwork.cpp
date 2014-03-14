#include "pcnetwork.hpp"

namespace pct {
namespace pc {

PCNetwork::PCNetwork(string name) {
	pcName = name;

	network = new SMILEBayesianNetwork();

	hypotheses = vector<string>();
	predictions = vector<string>();
}

PCNetwork::PCNetwork( string name, BayesianNetwork* net ) {
	pcName = name;
	network = net;

	hypotheses = vector<string>();
	predictions = vector<string>();
}

void PCNetwork::setHypothesis( string name ) {
	if( network->nodeExists( name ) && !isPrediction( name ) && !isHypothesis( name ) ) {
		hypotheses.push_back( name );
	}
}

void PCNetwork::setPrediction( string name ) {
	if( network->nodeExists( name ) && !isHypothesis( name ) && !isPrediction( name ) ) {
		predictions.push_back( name );
	}
}

bool PCNetwork::isHypothesis( string name ) {
	return std::find( hypotheses.begin(), hypotheses.end(), name ) != hypotheses.end();
}

bool PCNetwork::isPrediction( string name ) {
	return std::find( predictions.begin(), predictions.end(), name ) != predictions.end();
}

string PCNetwork::getPCName() {
	return pcName;
}

}
}
