#include "infoset.hpp"
#include "info.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace pct {

InfoSet::InfoSet() {
	infos = vector<Info>();
	flags = vector<string>();
}

void InfoSet::addInfo( Info info ) {
	//TODO: add existing check
	infos.push_back( info );
}

void InfoSet::setFlag( string name ) {
	flags.push_back( name );
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

bool InfoSet::isSet( string name ) {
	for( vector<string>::iterator it = flags.begin();
		 it != flags.end();
		 it++ ) {
		if( (*it) == name )
			return true;
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
