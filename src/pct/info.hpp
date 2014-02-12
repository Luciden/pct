#ifndef INFO_HPP_
#define INFO_HPP_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace pct {

class Info {
public:
	enum Type {
	Integer,
	Double,
	String
	};

private:
	string name;
	Type type;

	int intValue;
	double doubleValue;
	string stringValue;

public:
	Info( string name, string value );
	Info( string name, int value );
	Info( string name, double value );

	string getName();
	Type getType();

	int getIntValue();
	
	double getDoubleValue();

	string getStringValue();
};

}

#endif /* INFO_HPP_ */
