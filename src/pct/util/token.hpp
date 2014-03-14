#ifndef TOKEN_HPP_
#define TOKEN_HPP_

#include <string>
#include <vector>

using std::vector;
using std::string;

namespace pct {

class Token {
public:
	enum Type {
		LeftBracket,
		RightBracket,
		Equals,
		Comma,
		Pipe,
		Name,
		EOL
	};

	Token()
		: type(EOL), identifier("") {}

	Token( Type t )
		: type(t), identifier("") {}

	Token( Type t, string id )
		: type(t), identifier(id) {}

	Type type;
	string identifier;
};

}

#endif /* TOKEN_HPP_ */
