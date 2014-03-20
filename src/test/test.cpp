#include "test.hpp"

#include <iostream>

#include "../pct/util/parser.hpp"

using namespace pct;

void Test::runTests() {
	testParser1();
	testParser2();
}

void Test::testParser1() {
	Parser parser = Parser();

	Query test = parser.parse( "P( X )" );

	vector<Variable> obs = test.getObserved();
	vector<Variable> pri = test.getPriors();

	if( pri.size() == 0 && obs.size() == 1 && obs.at(0).name == "X" && !obs.at(0).instantiated ) {
		std::cout << "Parser test 1 passed!" << std::endl;
	}
	else {
		std::cout << "Parser test 1 failed!" << std::endl;
	}
}

void Test::testParser2() {
	Parser parser = Parser();

	Query test = parser.parse( "P( X | Y )" );

	vector<Variable> obs = test.getObserved();
	vector<Variable> pri = test.getPriors();

	if( pri.size() == 1 && pri.at(0).name == "Y" && !pri.at(0).instantiated
	 && obs.size() == 1 && obs.at(0).name == "X" && !obs.at(0).instantiated ) {
		std::cout << "Parser test 2 passed!" << std::endl;
	}
	else {
		std::cout << "Parser test 2 failed!" << std::endl;
	}
}
