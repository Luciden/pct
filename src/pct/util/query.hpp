#ifndef QUERY_HPP_
#define QUERY_HPP_

#include <string>
#include <vector>

#include "variable.hpp"
#include "token.hpp"

using std::vector;
using std::string;

namespace pct {

typedef vector<Variable> Variables;

/**
 * Represents a specification of what probability distribution to calculate.
 *
 * See @ref manual_query for more information on how these are used.
 */
class Query {
private:
	vector<Variable> priors;
	vector<Variable> observed;

public:
	Query();

	/**
	 * Add a prior variable (with value)
	 */
	void addPrior( Variable p );

	/**
	 * Add a queried observed variable (with value)
	 */
	void addObserved( Variable v );

	vector<Variable> getPriors();
	vector<Variable> getObserved();
};

}

#endif /* QUERY_HPP_ */
