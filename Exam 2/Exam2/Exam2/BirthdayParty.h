#ifndef _BIRTHDAY_PARTY_H_
#define _BIRTHDAY_PARTY_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Party.h"
#include "BirthdayPartyTicket.h"

// FIXME 2: Create BirthdayParty and BirthdayPartyTicket to host birthday parties!
// FIXME 3: Update PartyFactory::factory() to allow it to be the ONLY method for creating a BirthdayParty
/**
* BirthdayParty is derived from Party
*/
class BirthdayParty : public Party
{
private:
	std::list<std::string> room; // Data structure for containing the party goers in this dinner party

								 /**
								 * Constructor for creating a BirthdayParty
								 */
	BirthdayParty() {}

	friend class PartyFactory;

public:

	/**
	* Add a person to the party
	* @param name the name of the party goer
	*/
	PartyTicket * add(std::string name) {
		/**
		* FIXME 1a:
		*   Pseudo-code
		*    1. add name to the front of room
		*    2. get iterator to the front of the room (this points to the recently added party goer)
		*    3. create a new dinner party ticket (DinnerPartyTicket) with its constructor
		*            Pass to the constructor "this" party, and the iterator from step 2
		*    4. return this new party ticket
		*/
		room.push_front(name);
		return new BirthdayPartyTicket(this, room.begin());

	}

	/**
	* List all the persons currently in the party
	*/
	void list() {
		// FIXME 1b: iterate through all the persons here.
		std::list<std::string>::iterator listIter = room.begin();
		while (listIter != room.end())
		{
			std::cout << *listIter << std::endl;
			++listIter;
		}
	}

	/**
	* Remove the person identified by the iterator from the party
	*/
	void remove(std::list<std::string>::iterator it) {
		//FIXME 1c: someone's getting out of hand. Let's ask them to leave.
		room.erase(it);
	}
};

#endif