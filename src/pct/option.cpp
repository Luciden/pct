/*
 * option.cpp
 *
 *  Created on: 3 Feb 2014
 *      Author: Dennis
 */
#include "option.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace pct {

string Option::getName() {
	return name;
}

OptionType Option::getType() {
	return type;
}

Options::Options() {
	options = vector<Option>();
}

void Options::addOption( Option option ) {
	//TODO: add existing check
	options.push_back( option );
}

bool Options::contains( string name ) {
	for( vector<Option>::iterator it = options.begin();
		 it != options.end(); ++it ) {
		if( it->getName() == name ) {
			last = *it;
			return true;
		}
	}

	return false;
}

Option Options::getOption( string name ) {
	if( last.getName() == name ) {
		return last;
	}
	else {
		if( this->contains(name) ) {
			return last;
		}
		else {
			// throw exception
		}
	}
}

NumberOption::NumberOption( string name, long value ) {
	this->name = name;
	this->type = Number;
	this->value = value;
}

long NumberOption::getValue() {
	return value;
}

FileNameOption::FileNameOption( string name, string file ) {
	this->name = name;
	this->type = FileName;

	// Split the filename
	string::size_type pos = file.find(".");
	if( pos != string::npos ) {
		this->filename = file.substr(0, pos);
		string value = file.substr(pos + 1);
	}
	else {
		this->filename = file;
		this->extension = "";
	}
}

string FileNameOption::getFileName() {
	return filename;
}

string FileNameOption::getExtension() {
	return extension;
}

string FileNameOption::getWholeName() {
	if( !extension.empty() ) {
		return filename + '.' + extension;
	}
	else {
		return filename;
	}
}

}
