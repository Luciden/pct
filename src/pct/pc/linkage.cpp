#include "linkage.hpp"

#include <tuple>

namespace pct {

namespace pc {

Linkage::Linkage( string p, string c ) {
	parent = p;
	child = c;
}

void Linkage::addLink( string a, string b, vector<Link> values ) {
	links.push_back( tuple<string, string, vector<Link>>( a, b, values ) );
}

tuple<string, string, vector<Link>> Linkage::findPredictionLink( string name ) {
	for( vector<tuple<string, string, vector<Link>>>::iterator it = links.begin();
		 it != links.end();
		 ++it )
	{
		if( std::get<0>(*it) == name )
			return *it;
	}

	//TODO: error not found
}

tuple<string, string, vector<Link>> Linkage::findHypothesisLink( string name ) {
	for( vector<tuple<string, string, vector<Link>>>::iterator it = links.begin();
		 it != links.end();
		 ++it )
	{
		if( std::get<1>(*it) == name )
			return *it;
	}

	//TODO: error not found
}

bool Linkage::isSingleMatch( string a, vector<string> b ) {
	for( vector<string>::iterator it = b.begin(); 
		 it != b.end();
		 ++it )
	{
		if( *it == a )
			return true;
	}

	return false;
}

bool Linkage::isMatch( vector<string> a, vector<Link> b, bool x ) {
	for( vector<Link>::iterator it = b.begin();
		 it != b.end();
		 ++it )
	{
		if( x && isSingleMatch( std::get<0>(*it), a ) ) {
		}
		else if( !x && isSingleMatch( std::get<1>(*it), a ) ) {
		}
		else {
			return false;
		}
	}

	return true;
}

bool Linkage::checkPrediction( PCNetwork* net, string name ) {
	// Find the matching information in the linkage, if it exists
	tuple<string, string, vector<Link>> match = findPredictionLink( name );
	vector<Link> matchValues = std::get<2>(match);
	
	// Get the node's possible values
	vector<string> values = net->getPredictionValues( name );

	return isMatch( values, matchValues, true );
}

bool Linkage::checkPredictions( PCNetwork* net ) {
	// Check number of nodes
	vector<string> names = net->getPredictionsNames();

	if( names.size() != links.size() ) {
		return false;
	}

	// Check, for all predictions, the values
	for( vector<string>::iterator it = names.begin();
		 it != names.end();
		 ++it )
	{
		if( !checkPrediction( net, *it ) )
			return false;
	}

	return true;
}

bool Linkage::checkHypothesis( PCNetwork* net, string name ) {
	// Find the matching information in the linkage, if it exists
	tuple<string, string, vector<Link>> match = findHypothesisLink( name );
	vector<Link> matchValues = std::get<2>(match);
	
	// Get the node's possible values
	vector<string> values = net->getHypothesisValues( name );

	return isMatch( values, matchValues, false );
}

bool Linkage::checkHypotheses( PCNetwork* net ) {
	// Check number of nodes
	vector<string> names = net->getHypothesesNames();

	if( names.size() != links.size() ) {
		return false;
	}

	// Check, for all predictions, the values
	for( vector<string>::iterator it = names.begin();
		 it != names.end();
		 ++it )
	{
		if( !checkHypothesis( net, *it ) )
			return false;
	}

	return true;
}

}
}
