#include "parser.hpp"

#include <tuple>
#include <iostream>

#include "token.hpp"

using std::cout;
using std::endl;
using std::tuple;

namespace pct {

Parser::Parser() {
	tokens = vector<Token>();
	index = 0;
	tok = Token(Token::EOL);
}

void Parser::nextToken() {
	index++;
	if( index >= tokens.size() ) {
		//TODO: abort
	}
	else {
		tok = tokens.at(index);
	}
}

Query Parser::parse( string query ) {
	tokenizeQuery( query );

	Query* q = new Query();
	index = 0;
	tok = tokens.at(0);

	parsingLeft = true;

	return *parseQuery(q);
}

Query* Parser::parseQuery( Query* q ) {
	if( tok.type == Token::Name && tok.identifier == "P" ) {
		nextToken();
		if( tok.type == Token::LeftBracket ) {
			nextToken();
			parseBody( q );

			if( tok.type == Token::RightBracket ) {
				nextToken();
				if( tok.type == Token::EOL ) {
					// Everything O.K.
				}
				else {
					//TODO: error
				}
			}
			else {
				//TODO: error
			}
		}
		else {
			//TODO: error
		}
	}
	else {
		//TODO: error
	}

	return q;
}

Query* Parser::parseBody( Query* q ) {
	parseTerms( q );

	if( tok.type == Token::Pipe ) {
		parsingLeft = false;
		nextToken();
		parseTerms( q );
		return q;
	}
	else {
		return q;
	}
}

Query* Parser::parseTerms( Query* q ) {
	parseTerm(q);

	if( tok.type == Token::Comma ) {
		nextToken();
		parseTerms(q);
		return q;
	}
	else {
		return q;
	}
}

Query* Parser::parseTerm( Query* q ) {
	if( tok.type == Token::Name ) {
		string first = tok.identifier;

		nextToken();

		if( tok.type == Token::Equals ) {
			nextToken();

			if( tok.type == Token::Name ) {
				string second = tok.identifier;

				Variable v = Variable( first, second );
				if( parsingLeft )
					q->addObserved(v);
				else
					q->addPrior(v);

				nextToken();
				return q;
			}
		}
		else {
			Variable v = Variable( first );
			if( parsingLeft )
				q->addObserved(v);
			else
				q->addPrior(v);

			nextToken();
			return q;
		}
	}
	else {
		//TODO: error
	}
}

void Parser::parseError( string expected ) {
	cout << "Ill-formed query. " << expected << " expected. Aborting" << endl;
	exit(EXIT_FAILURE);
}

void Parser::tokenizeQuery( string query ) {
	tokens = vector<Token>();

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
	tokens.push_back( Token( Token::EOL ) );
}

void Parser::clearToken( string& token, vector<Token>* tokens ) {
	if( token != "" ) {
		tokens->push_back( Token( Token::Name, token ) );
	}

	token = "";
}

}