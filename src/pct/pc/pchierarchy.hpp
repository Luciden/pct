#ifndef PCHIERARCHY_HPP_
#define PCHIERARCHY_HPP_

#include <tuple>
#include <string>

#include "pcnetwork.hpp"
#include "../util/parser.hpp"

using std::tuple;
using std::string;

namespace pct {

namespace pc {

typedef tuple<string, string> Link;

class PCHierarchy {
private:
	vector<PCNetwork*> networks;

public:
	/**
	 * Adds a parentless network to the hierarchy.
	 */
	void addNetwork( PCNetwork net );

	/**
	 * Connects a network to an existing network in the hierarchy.
	 *
	 * This checks if the networks can be linked with the provided information.
	 * To be able to link network A to parent P:
	 *
	 * @li P should have the same number of predictions as the number of
	 *     hypotheses in A;
	 * @li the values of these predictions and hypotheses should be matched
	 *
	 * If these conditions are met, then the new network is linked to the
	 * parent in the hierarchy and the linked nodes are considered as one.
	 *
	 * @param parent name of the parent network to connect this to.
	 * @param links this specifies which of the parent network's prediction
	 *        are linked to which of the hypotheses in the new network.
	 */
	void addNetwork( PCNetwork net, string parent, vector<Link> links );

	void performInference( Query query );
};

}

}

#endif