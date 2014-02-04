#include "fileinputtool.hpp"

#include "smile.h"

#include "../result.hpp"
#include "../option.hpp"

namespace pct {

FileInputTool::FileInputTool() {
	name = "read";
	description = "read a network from a file";

	required = vector<string>();
	optional = vector<string>();

	required.push_back( "filename" );
}

Results FileInputTool::run( Options opts ) {
	DSL_network network;

	return Results();
}

}