#include "parser.hpp"

#include <tuple>
#include <iostream>

using std::cout;
using std::endl;
using std::tuple;

namespace pct {

Query Parser::parse( string query ) {
	// find the queried nodes/variables
	Query q = Query();

	return q;
}

Query Parser::parseQuery( string query ) {
	Query q = Query();

	return q;
}

void Parser::parseError( string expected ) {
	cout << "Ill-formed query. " << expected << " expected. Aborting" << endl;
	exit(EXIT_FAILURE);
}

vector<Parser::Token> Parser::tokenizeQuery( string query ) {
	vector<Token> tokens = vector<Token>();

	string t = "";

	for( int i = 0; i < query.size(); i++ ) {
		char c = query[i];

		if( c == '(' ) {
			clearToken( t, &tokens );
			tokens.push_back( Token( Token::LeftBracket ) );
		}
		else if( c == ')' ) {
			clearToken( t, &tokens );
			tokens.push_back( Token( Token::RightBracket ) );
		}
		else if( c == ',' ) {
			clearToken( t, &tokens );
			tokens.push_back( Token( Token::Comma ) );
		}
		else if( c == '|' ) {
			clearToken( t, &tokens );
			tokens.push_back( Token( Token::Pipe ) );
		}
		else if( c == '=' ) {
			clearToken( t, &tokens );
			tokens.push_back( Token( Token::Equals ) );
		}
		else if( isspace(c) ) {
			clearToken( t, &tokens );
		}
		else {
			t += c;
		}
	}

	clearToken( t, &tokens );

	return tokens;
}

void Parser::clearToken( string& token, vector<Token>* tokens ) {
	if( token != "" ) {
		tokens->push_back( Token( Token::Name, token ) );
	}

	token = "";
}

}