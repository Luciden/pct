#include "infoset.hpp"
#include "info.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace pct {

InfoSet::InfoSet() {
	infos = vector<Info>();
}

void InfoSet::addInfo( Info info ) {
	//TODO: add existing check
	infos.push_back( info );
}

bool InfoSet::contains( string name ) {
	for( vector<Info>::iterator it = infos.begin();
		 it != infos.end(); ++it ) {
		if( it->getName() == name ) {
			last = &(*it);
			return true;
		}
	}

	return false;
}

Info InfoSet::getInfo( string name ) {
	if( last->getName() == name ) {
		return *last;
	}
	else {
		if( this->contains(name) ) {
			return *last;
		}
		else {
			// throw exception
		}
	}
}

}