#ifndef INFERENCETOOL_HPP_
#define INFERENCETOOL_HPP_

#include <string>
#include <vector>

#include "tool.hpp"

using std::vector;
using std::string;

namespace pct {

class InferenceTool : public Tool {
private:
	class Token {
	public:
		enum Type {
			P,
			LeftBracket,
			RightBracket,
			Equals,
			Comma,
			Pipe,
			Name
		};

		Type type;
		string identifier;
	};

	enum ParseState {
		Start,

	};

   /** @page query Querying Probabilities
    *
	* The (simplified) BNF grammar for the queries is as follows:
	*
	* Query       := 'P(' Conditional ')'
	* Conditional := Variables '|' Commital
	* Commital    := Variable '=' Value
	* Variables   := Variable | Variable ',' Variables
	* Variable    := {any valid node name}
	* Value       := {any valid value identifier}
	*/
   /**
	* Parses a probability query.
	*/
	void parseQuery( string query );

	vector<Token> tokenizeQuery( string query );

public:
	InferenceTool();

	virtual InfoSet run( InfoSet options );
};

}

#endif /* INFERENCETOOL_HPP_ */
