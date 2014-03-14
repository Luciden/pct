#include "pchierarchy.hpp"

namespace pct {

namespace pc {

PCHierarchy::PCHierarchy() {
	networks = vector<PCNetwork*>();
}

bool PCHierarchy::doLineUp( vector<string> hyps, vector<Link> links ) {
	for( vector<string>::iterator it = hyps.begin();
		 it != hyps.end();
		 ++it )
	{
		bool found = false;

		for( vector<Link>::iterator itt = links.begin();
			 !found && itt != links.end();
			 ++itt )
		{
			if( *it == std::get<0>(*itt) ) {
				found = true;
			}
		}

		if( !found ) {
			return false;
		}
	}

	return true;
}

void PCHierarchy::addNetwork( PCNetwork* net ) {
	networks.push_back( net );
}

void PCHierarchy::addNetwork( PCNetwork* net, string parent, vector<Link> links ) {
	// Check if parent exists
	if( hasNetwork( parent ) ) {
		// Check if new net's hypotheses line up with links and then with
		// parent's predictions
		vector<string> newHyps = net->getHypotheses();

		if( doLineUp( newHyps, links ) ) {
		}


	}
	else {
		//TODO: error
	}
}

}
}
