#include "pcnetwork.hpp"

namespace pct {
namespace pc {

PCNetwork::PCNetwork(string name) {
	pcName = name;

	network = new SMILEBayesianNetwork();
}

PCNetwork::PCNetwork( string name, BayesianNetwork* net ) {
	pcName = name;
	network = net;
}

void PCNetwork::setHypothesis( string name ) {
	// Check if exists

	// Add to hypotheses
}

string PCNetwork::getPCName() {
	return pcName;
}

}
}
