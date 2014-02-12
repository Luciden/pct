#include "info.hpp"

namespace pct {
/*
Info::Info() :
	name(""), type(Integer), intValue(0), stringValue(""), doubleValue(0.0f) {}
	*/
Info::Info( string name_, string value ) :
	name(name_), stringValue(value), type(String) {}

Info::Info( string name_, int value ) :
	name(name_), intValue(value), type(Integer) {}

Info::Info( string name_, double value ) :
	name(name_), doubleValue(value), type(Double) {}

string Info::getName() {
	return name;
}

Info::Type Info::getType() {
	return type;
}

int Info::getIntValue() {
	//TODO: error handling
	if( type == Integer )
		return intValue;
	else
		return -1;
}

double Info::getDoubleValue() {
	//TODO: error handling
	if( type == Double )
		return doubleValue;
	else
		return 0.0f;
}

string Info::getStringValue() {
	//TODO: error handling
	if( type == String )
		return stringValue;
	else
		return "";
}

}
