#ifndef INFERENCETOOL_HPP_
#define INFERENCETOOL_HPP_

#include <string>
#include <vector>

#include "tool.hpp"

using std::vector;
using std::string;

namespace pct {

class InferenceTool : public Tool {
public:
	InferenceTool();

	virtual InfoSet run( InfoSet options );

	virtual string getOptionHelp( string name );
};

}

#endif /* INFERENCETOOL_HPP_ */
