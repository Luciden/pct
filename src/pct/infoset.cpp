#include "infoset.hpp"
#include "info.hpp"

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::to_string;

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
	if( this->contains(name) ) {
		return *last;
	}
	else {
		std::cout << "Info '" << name << "' was not found." << std::endl;
	}
}

string InfoSet::display() {
	string render = "";

	for( vector<Info>::iterator it = infos.begin();
		 it != infos.end();
		 ++it ) {
		string name = it->getName();

		Info::Type type = it->getType();
		switch(type) {
		case Info::Integer:
			render += "[i] " + name + " " + to_string( static_cast<long long>(it->getIntValue() ) );
			break;
		case Info::Double:
			render += "[d] " + name + " " + to_string( static_cast<long double>(it->getDoubleValue()) );
			break;
		case Info::String:
			render += "[s] " + name + " " + it->getStringValue();
			break;
		}

		render += "\n";
	}

	return render;
}

}
