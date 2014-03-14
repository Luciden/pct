#ifndef PCHIERARCHY_HPP_
#define PCHIERARCHY_HPP_

#include <tuple>
#include <string>

#include "linkage.hpp"
#include "pcnetwork.hpp"
#include "../util/parser.hpp"

using std::tuple;
using std::string;

namespace pct {

namespace pc {

class PCHierarchy {
private:
	vector<PCNetwork*> networks;
	vector<Linkage> links;

	PCNetwork* getNetwork( string name );

public:
	/**
	 * Creates an empty hierarchy.
	 */
	PCHierarchy();

	/**
	 * Adds a parentless network to the hierarchy.
	 */
	void addNetwork( PCNetwork* net );

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
	 * This particular implementation considers the networks that make up
	 * the hierarchy as individual networks, as opposed to a single
	 * connected network.
	 *
	 * @param parent name of the parent network to connect this to.
	 * @param links this specifies which of the parent network's prediction
	 *        are linked to which of the hypotheses in the new network.
	 */
	void addNetwork( PCNetwork* net, string parent, Linkage link );

	// void performInference( Query query );

	bool hasNetwork( string name );
};

}

}

#endif