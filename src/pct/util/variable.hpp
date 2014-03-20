#ifndef VARIABLE_HPP_
#define VARIABLE_HPP_

#include <string>
#include <vector>

using std::vector;
using std::string;

namespace pct {

/**
 * One element in the Query parse tree that specifies a variable/value pair.
 */
class Variable {
public:
	string name;
	bool instantiated;
	string instance;

	Variable( string name_ )
		: name(name_), instantiated(false), instance("") {}

	Variable( string name_, string instance_ )
		: name(name_), instantiated(true), instance(instance_) {}
};

}

#endif /* VARIABLE_HPP_ */
