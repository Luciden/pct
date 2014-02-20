#ifndef ANALYSISTOOL_HPP_
#define ANALYSISTOOL_HPP_

#include <string>
#include <vector>

#include "tool.hpp"

using std::vector;
using std::string;

namespace pct {

typedef unsigned long long timestamp_t;

class AnalysisTool : public Tool {
public:
	AnalysisTool();

	virtual InfoSet run( InfoSet options );
};

}

#endif /* ANALYSISTOOLL_HPP_ */
