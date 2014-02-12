#ifndef INFOSET_HPP_
#define INFOSET_HPP_

#include "info.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace pct {

class InfoSet {
private:
	vector<Info> infos;

	Info* last;

public:
	InfoSet();

	void addInfo( Info info );

	bool contains( string name );

	Info getInfo( string name );
};

}

#endif /* INFOSET_HPP_ */
