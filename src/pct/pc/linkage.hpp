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

class Combination {
public:
	string parent;
	string child;

	vector<Link> links;
};

/**
 * Provides all necessary information to link two PCNs in the PCH
 * together.
 */
class Linkage {
private:
	string parent;
	string child;

	vector<tuple<string, string, vector<Link>>> links;

	tuple<string, string, vector<Link>> findPredictionLink( string name );
	tuple<string, string, vector<Link>> findHypothesisLink( string name );

	bool isSingleMatch( string a, vector<string> b );

public:
	Linkage( string p, string c );

	/**
	 *
	 * @param a parent's node name
	 * @param b child's node name
	 * @param values Links between the values that should be linked together
	 */
	void addLink( string a, string b, vector<Link> values );

	bool checkPrediction( PCNetwork* net, string name );
	bool checkPredictions( PCNetwork* net );

	bool checkHypothesis( PCNetwork* net, string name );
	bool checkHypotheses( PCNetwork* net );

	bool isMatch( vector<string> a, vector<Link> b, bool x );
};

}

}

#endif
