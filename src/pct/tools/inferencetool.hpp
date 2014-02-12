#ifndef INFERENCETOOL_HPP_
#define INFERENCETOOL_HPP_

#include <string>
#include <vector>

#include "tool.hpp"

using std::vector;
using std::string;

namespace pct {

class InferenceTool : public Tool {
private:

public:
	virtual InfoSet run( InfoSet options );
};

}

#endif /* INFERENCETOOL_HPP_ */
