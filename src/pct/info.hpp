#ifndef INFO_HPP_
#define INFO_HPP_

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace pct {

/**
 * A piece of information that can be either a string or a number.
 *
 * This can be used to represent parameters or as results.
 */
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
	/**
	 * Create a string valued piece.
	 */
	Info( string name, string value );

	/**
	 * Create an integer valued piece.
	 */
	Info( string name, int value );

	/**
	 * Create a decimal valued piece.
	 */
	Info( string name, double value );

	string getName();
	Type getType();

	int getIntValue();
	
	double getDoubleValue();

	string getStringValue();
};

}

#endif /* INFO_HPP_ */
