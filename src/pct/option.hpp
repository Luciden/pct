/*
 * option.hpp
 *
 *  Created on: 3 Feb 2014
 *      Author: Dennis
 */

#ifndef OPTION_HPP_
#define OPTION_HPP_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace pct {

enum OptionType {
	Number,
	String,
	FileName
};

class Option {
private:
	string name;
	OptionType type;

public:
	string getName();
	OptionType getType();
};

class Options {
private:
	vector<Option> options;

	Option last;

	Option findOption( string name );

public:
	Options();

	void addOption( Option option );

	bool contains( string name );

	Option getOption( string name );
};

class NumberOption : public Option {
private:
	long value;

public:
	NumberOption( string name, long value );

	long getValue();
};

class FileNameOption : public Option {
private:
	string filename;
	string extension;

public:
	FileNameOption( string name, string filename );

	string getFileName();

	string getExtension();

	string getWholeName();
};

}

#endif /* OPTION_HPP_ */
