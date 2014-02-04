#ifndef FILEINPUTTOOL_HPP_
#define FILEINPUTTOOL_HPP_

#include "tool.hpp"

namespace pct {

class FileInputTool : public Tool {
private:

public:
	FileInputTool();

	virtual Results run( Options opts );
}

}

#endif