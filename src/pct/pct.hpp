/** @file pct.hpp
 *
 *
 *  Created on: 26 Jan 2014
 * @author Dennis Merkus
 */

#ifndef PCT_HPP_
#define PCT_HPP_

#include <string>

using std::string;

namespace pct {

class PredictiveCodingToolbox {
public:
	PredictiveCodingToolbox();

	void parseCommand( int argc, char* argv[] );

	Results useTool( string name, Options opts );
};

class Option {

};

class Options {

};

class Result {
private:
	string name;
};

class IntResult {

};

class Results {

};

class Module {
public:
	virtual Results run( Options opts ) = 0;
};

class FileInputModule : public Module {

};

class FileOutputModule : public Module {

};

class AlgorithmAnalysisTool : public Tool {
private:
	AlgorithmAnalysisTool() {
		name = "analysis";
	}
};

/**
 * Interface for algorithms.
 *
 * Provides a uniform way to access algorithms.
 * This includes several types of algorithms.
 */
class AlgorithmWrapper {
private:
public:
	virtual Results call() = 0;
};

}

#endif /* PCT_HPP_ */
