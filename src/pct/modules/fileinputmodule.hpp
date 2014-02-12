#ifndef FILEINPUTMODULE_HPP_
#define FILEINPUTMODULE_HPP_

#include "module.hpp"

#include "../network.hpp"

namespace pct {

class FileInputModule : public Module {
public:
	static SMILEBayesianNetwork load( string name );
};

}

#endif /* FILEINPUTMODULE_HPP_ */
