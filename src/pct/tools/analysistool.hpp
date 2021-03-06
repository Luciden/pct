#ifndef ANALYSISTOOL_HPP_
#define ANALYSISTOOL_HPP_

#include <string>
#include <vector>

#include "tool.hpp"

using std::vector;
using std::string;

namespace pct {

typedef unsigned long long timestamp_t;

/**
 * Analyses algorithms during inference.
 */
class AnalysisTool : public Tool {
public:
	AnalysisTool();

	virtual InfoSet run( InfoSet options );

	virtual string getOptionHelp( string name );
};

}

#endif /* ANALYSISTOOLL_HPP_ */
