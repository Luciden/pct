#include "query.hpp"

namespace pct {

Query::Query() {
	priors = vector<Variable>();
	observed = vector<Variable>();
}

void Query::addPrior( Variable p ) {
	priors.push_back( p );
}

void Query::addObserved( Variable o ) {
	observed.push_back( o );
}

Variables Query::getObserved() {
	return observed;
}

Variables Query::getPriors() {
	return priors;
}

}
