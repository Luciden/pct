#ifndef FILEINPUTMODULE_HPP_
#define FILEINPUTMODULE_HPP_

#include "module.hpp"

#include "../network.hpp"

namespace pct {

/**
 * Provides file reading functionalities.
 */
class FileInputModule : public Module {
public:
	/**
	 * Reads a Bayesian network using the SMILE library.
	 */
	static SMILEBayesianNetwork load( string name );
};

}

#endif /* FILEINPUTMODULE_HPP_ */
