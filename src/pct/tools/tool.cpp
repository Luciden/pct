#include "tool.hpp"

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;

namespace pct {

string Tool::getName() {
	return name;
}

string Tool::getDescription() {
	return description;
}

bool Tool::checkOptions( InfoSet options ) {
	for( OptionList::iterator it = required.begin();
		 it != required.end();
		 ++it ) {
		if( !options.contains( std::get<0>(*it) ) )
			return false;
	}

	return true;
}

void Tool::display( string msg, bool verbose ) {
	if( verbose ) {
		cout << msg << endl;
	}
}

void Tool::outputResult( string file, string result ) {
	std::ofstream filestr;

	filestr.open(file);
	filestr << result;
	filestr.close();
}

string Tool::makeOptionUsage( string optName, Info::Type optType ) {
	string result = "-";

	result += optName + " ";

	switch(optType) {
	case Info::Integer:
		result += "<int>";
		break;
	case Info::Double:
		result += "<real>";
		break;
	case Info::String:
		result += "<string>";
		break;
	}

	return result;
}

string Tool::getUsage() {
	string usage = name;

	for( OptionList::iterator it = required.begin();
		 it != required.end();
		 ++it ) {
		string optName = std::get<0>(*it);
		Info::Type optType = std::get<1>(*it);

		usage += " " + makeOptionUsage( optName, optType );
	}

	for( OptionList::iterator it = optional.begin();
		 it != optional.end();
		 ++it ) {
		string optName = std::get<0>(*it);
		Info::Type optType = std::get<1>(*it);

		usage += " [" + makeOptionUsage( optName, optType ) + "]";
	}

	return usage;
}

void Tool::incorrectUsage() {
	cout << "Some required options are not specified" << endl;
	cout << "\t" << getUsage() << endl;
}

}
