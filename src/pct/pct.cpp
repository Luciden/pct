/*
 * pct.cpp
 */
#include "pct.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;

#include "infoset.hpp"

#include "tools/tool.hpp"
#include "tools/inferencetool.hpp"
#include "tools/analysistool.hpp"

namespace pct {

PredictiveCodingToolbox::PredictiveCodingToolbox() {
	tools = vector<Tool*>();

	tools.push_back( new InferenceTool() );
	tools.push_back( new AnalysisTool() );
}

void PredictiveCodingToolbox::run( string command, InfoSet options ) {
	if( command == "about" ) {
		about();
	}
	else if( command == "help" ) {
		help();
	}
	else if( command == "list" ) {
		list();
	}
	else {
		useTool( command, options );
	}
}

InfoSet PredictiveCodingToolbox::parseCommand( int argc, char* argv[] ) {
	InfoSet opts = InfoSet();

	bool readName = false;
	string prevName = "";

	// parse all arguments
	for( int i = 2; i < argc; i++ ) {
		// TODO make simple argument parser with names, name:value
		// this is dependent on the tool used.
		string p = argv[i];

		if( !readName ) {
			// parse a name
			if( p[0] != '-' ) {
				cout << "Parameters not structured properly." << endl;
				cout << "Name expected instead of " << p << endl;

				break;
			}
			else {
				// Check for another '-' (flag), otherwise parse as an option name
				if( p[1] == '-' ) {
					opts.setFlag( p.substr(2) );
				}
				else {
					prevName = p.substr(1);
					readName = true;
				}
			}
		}
		else {
			// Read either an int, a double or a string
			char* null;
			long l = strtol( p.c_str(), &null, 10 );
			

			if(l != 0L ) {
				opts.addInfo( Info( prevName, l ) );
			}
			else {
				double d = strtod( p.c_str(), &null );

				if( l != 0.0 ) {
					opts.addInfo( Info( prevName, d ) );
				}
				else {
					opts.addInfo( Info( prevName, p ) );
				}
			}

			readName = false;
		}
	}

	return opts;
}

InfoSet PredictiveCodingToolbox::useTool( string name, InfoSet opts ) {
	if( opts.isSet("debug") ) {
		cout << opts.display() << endl;
	}

	// Check if tool exists and run it
	for( vector<Tool*>::iterator it = tools.begin();
		 it != tools.end();
		 ++it ) {
		if( (*it)->getName() == name ) {
			return (*it)->run( opts );
		}
	}

	cout << "The " + name + " tool was not found!" << endl;

	return InfoSet();
}

void PredictiveCodingToolbox::list() {
	cout << "Available tools:" << endl;

	for( vector<Tool*>::iterator it = tools.begin();
		 it != tools.end();
		 ++it ) {
		Tool* tp = (*it);

		cout << endl << "\t" + tp->getName() + "\t" + tp->getDescription() << endl;
		cout << "Usage:\t" + tp->getUsage() << endl;
	}
}

void PredictiveCodingToolbox::help() {
	cout << "Possible commands:" << endl
		 << "\tabout\tinformation about this toolbox" << endl
		 << "\thelp \tthis help information" << endl
		 << "\tlist \tlist all available tools" << endl;
}

void PredictiveCodingToolbox::about() {
	cout << "Predictive Coding Toolbox by Dennis Merkus (dennis.merkus@gmail.com)" << endl
	     << "This toolbox uses the SMILE library (provided on an \"as is\" basis). Available at http://genie.sis.pitt.edu/" << endl;
}

}
