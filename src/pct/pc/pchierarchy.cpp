#include "pchierarchy.hpp"

namespace pct {

namespace pc {

PCHierarchy::PCHierarchy() {
	networks = vector<PCNetwork*>();
	links = vector<Linkage>();
}

PCNetwork* PCHierarchy::getNetwork( string name ) {
	for( vector<PCNetwork*>::iterator it = networks.begin();
		 it != networks.end();
		 ++it )
	{
		if( (*it)->getPCName() == name )
			return (*it);
	}

	//TODO: error not found
}

void PCHierarchy::addNetwork( PCNetwork* net ) {
	networks.push_back( net );
}

void PCHierarchy::addNetwork( PCNetwork* net, string parent, Linkage link ) {
	// Check if parent exists
	if( hasNetwork( parent ) ) {
		
		// Check if parent's predictions line up with child's hypotheses
		if( link.checkPredictions( getNetwork( parent ) ) && link.checkHypotheses( net ) ) {
			links.push_back( link );
		}
	}
	else {
		//TODO: error
	}
}

bool PCHierarchy::hasNetwork( string name ) {
	for( vector<PCNetwork*>::iterator it = networks.begin();
		it != networks.end();
		++it )
	{
		if( (*it)->getPCName() == name )
			return true;
	}

	return false;
}

}
}
