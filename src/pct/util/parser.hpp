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

	/**
	 * Sets the current token to the next available token.
	 */
	void nextToken();

	/**
	 * Makes sure the string that was built up so far is cleared,
	 * so that a new identifier can take its place.
	 */
	void clearToken( string& token, vector<Token>* tokens );

	/**
	 * Shows a parser error.
	 */
	void parseError( string expected );

	/**
	 * Produces a set of tokens from a query string.
	 */
	void tokenizeQuery( string query );

public:
	/**
	 * Instantiates the current token et cetera.
	 */
	Parser();
	
    /**
	 * Parses and evaluates a specified query.
	 *
	 * Also see @ref manual_query
	 */
	Query parse( string query );
};

}

#endif /* PARSER_HPP_ */
