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

class Query {
private:
	vector<Variable> priors;
	vector<Variable> observed;

public:
	Query();

	void addPrior( Variable p );
	void addObserved( Variable v );

	vector<Variable> getPriors();
	vector<Variable> getObserved();
};

}

#endif /* QUERY_HPP_ */
