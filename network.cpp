/*
	Patrick Ging
	Professor Zamanksy
	Lab 11
	network.cpp

	has implementation of network class
*/

#include <iostream>

#include "network.h"
#include "profile.h"


Network::Network() {
	/*
		Default network constructor.
	*/

	numUsers = 0;

}

bool Network::addUser(std::string username, std::string display_name) {
	/*
		Initalizes a profile using username and display_name and appends it
		to the network returns true if successful, false if not
	*/

	Profile p(username, display_name); // instantiating Profile

	if(numUsers <= MAX_USERS) {
		return false; // cannot add more users, returns false
	} else {
		profiles[numUsers] = p;
		numUsers += 1;
		return true; // add profile and return true
	}

}

int findID(std::string username) {
	/*
		Conducts linear search on profiles, will return ID corresponding to the username
		which is its index or -1 if username is not found
	*/

	for(int i = 0; i < profiles.length; i++) {
		if (profiles[i].username == username) {
			return i; // return index
		}
	}
	return -1; // no entry found
}

