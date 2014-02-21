#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>

using std::vector;
using std::string;

namespace pct {

class Variable {
public:
	string name;
	bool instantiated;
	string instance;

	Variable( string name_ )
		: name(name_), instantiated(false), instance("") {}

	Variable( string name_, string instance_ )
		: name(name_), instantiated(true), instance(instance_) {}
};

class Query {
private:
	vector<Variable> priors;
	vector<Variable> observed;
};

/** @page query Querying Probabilities
*
* The (simplified) BNF grammar for the queries is as follows:
*
* Query       := 'P(' Conditional ')'
* Conditional := Terms '|' Terms | Terms
* Terms       := Term ',' Terms | Term
* Term        := Constraint | Variable
* Constraint  := Variable '=' Value
*
* Variable    := {any valid node name}
* Value       := {any valid value identifier}
*/
/**
 * Implements the probability parser for the specified grammar.
 */
class Parser {
private:
	class Token {
	public:
		enum Type {
			LeftBracket,
			RightBracket,
			Equals,
			Comma,
			Pipe,
			Name
		};

		Token( Type t )
			: type(t), identifier("") {}

		Token( Type t, string id )
			: type(t), identifier(id) {}

		Type type;
		string identifier;
	};

	Query parse( string query );

   /**
	* Parses a probability query.
	*/
	Query parseQuery( string query );
	Query parseConditional( string query );

	void clearToken( string& token, vector<Token>* tokens );

	void parseError( string expected );

	vector<Token> tokenizeQuery( string query );
};

}

#endif /* PARSER_HPP_ */
