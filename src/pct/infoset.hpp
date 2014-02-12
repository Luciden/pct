#ifndef INFOSET_HPP_
#define INFOSET_HPP_

#include "info.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace pct {

/**
 * Provides labeled information.
 *
 * Can be used both to specify parameters or to give results.
 */
class InfoSet {
private:
	vector<Info> infos; /**< Information that is known */
	vector<string> flags; /**< Flags that are set */

	Info* last; /**< Latest requested information for efficiency */

public:
	/**
	 * Creates a container without any information.
	 */
	InfoSet();

	/**
     * Add one particular piece of information.
	 *
	 * When there is a conflict with an already existing piece of information,
	 * nothing is altered.
	 */
	void addInfo( Info info );

	/**
	 * Sets the flag with the specified name
	 */
	void setFlag( string name );

	/**
	 * Determine whether information with the specified name is already present.
	 */
	bool contains( string name );

	/**
	 * Determine whether the flag with the specified name is set.
	 */
	bool isSet( string name );

	/**
	 * Get the piece of information with the specified name.
	 */
	Info getInfo( string name );

	/**
	 * Create a visual representation of all the current information.
	 */
	string display();
};

}

#endif /* INFOSET_HPP_ */
