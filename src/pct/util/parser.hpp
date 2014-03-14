#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>

#include "variable.hpp"
#include "token.hpp"
#include "query.hpp"

using std::vector;
using std::string;

namespace pct {

/** @page query Querying Probabilities
*
* The (simplified) BNF grammar for the queries is as follows:
*
* \verbatim
* Query       := 'P(' Body ')'
* Body        := Terms '|' Terms | Terms
* Terms       := Term ',' Terms | Term
* Term        := Variable '=' Value | Variable
*
* Variable    := {any valid node name}
* Value       := {any valid value identifier}
* \endverbatim
*/
/**
 * Implements the probability parser for the specified grammar.
 */
class Parser {
private:
	vector<Token> tokens;
	int index;
	Token tok;

	bool parsingLeft;

   /**
	* Parses a probability query.
	*/
	Query* parseQuery( Query* q );
	Query* parseBody( Query* q );
	Query* parseTerms( Query* q );
	Query* parseTerm( Query* q );
	Query* parseConstraint( Query* q );

	void nextToken();

	/**
	 * Makes sure the string that was built up so far is cleared,
	 * so that a new identifier can take its place.
	 */
	void clearToken( string& token, vector<Token>* tokens );

	void parseError( string expected );

	void tokenizeQuery( string query );

public:
	Parser();
	
    /** @see query
	 */
	Query parse( string query );
};

}

#endif /* PARSER_HPP_ */
