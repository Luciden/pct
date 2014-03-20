#ifndef LINKAGE_HPP_
#define LINKAGE_HPP_

#include <tuple>
#include <string>

#include "pcnetwork.hpp"
#include "../util/parser.hpp"

using std::tuple;
using std::string;

namespace pct {

namespace pc {

typedef tuple<string, string> Link; /**< Link between two nodes */

/**
 * Provides all necessary information to link two PCNs in the PCH
 * together.
 *
 * This does not create an actual link (i.e. pointer) between two networks,
 * but only provides the necessary information to check if networks are
 * connected.
 */
class Linkage {
private:
	string parent;
	string child;

	vector<tuple<string, string, vector<Link>>> links;

	/**
	 * See whether a link exists with the specified prediction name and get its
	 * data.
	 */
	tuple<string, string, vector<Link>> findPredictionLink( string name );

	/**
	 * See whether a link exists with the specified hypothesis name and get its
	 * data.
	 */
	tuple<string, string, vector<Link>> findHypothesisLink( string name );

	/**
	 * Helper function for isMatch().
	 */
	bool isSingleMatch( string a, vector<string> b );

	/**
	 * See whether all links are present.
	 *
	 * @param a all names to check
	 * @param b all links to check against
	 * @param x when set to true, check for predictions; when set to false
	 * check hypotheses
	 */
	bool isMatch( vector<string> a, vector<Link> b, bool x );

public:
	/**
	 * Create an empty information container for a link between two networks
	 * with the specified name.
	 *
	 * The parent network's prediction nodes will be linked with the child
	 * network's hypothesis nodes.
	 *
	 * @param p name of the parent network (which will link its predictions)
	 * @param c name of the child network (which will link its hypotheses)
	 */
	Linkage( string p, string c );

	/**
	 * Add new information that links two nodes between two networks together.
	 *
	 * @param a parent's node name
	 * @param b child's node name
	 * @param values Links between the values that should be linked together
	 */
	void addLink( string a, string b, vector<Link> values );

	/**
	 * Helper function for checkPredictions().
	 */
	bool checkPrediction( PCNetwork* net, string name );

	/**
	 * Check whether all specified predictions in the specified network
	 * line up with the predictions in this Linkage.
	 */
	bool checkPredictions( PCNetwork* net );

	/**
	 * Helper function for checkHypothesis().
	 */
	bool checkHypothesis( PCNetwork* net, string name );

	/**
	 * Check whether all specified hypotheses in the specified network
	 * line up with the hypotheses in this Linkage.
	 */
	bool checkHypotheses( PCNetwork* net );
};

}

}

#endif
