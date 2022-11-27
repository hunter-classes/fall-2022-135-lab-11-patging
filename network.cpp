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

	if (p.get_username() == "") { // if the profile breaks rules it will be blank dont add
		return false;
	} else if(numUsers >= MAX_USERS) {
		return false; // cannot add more users, returns false
	} else if (findID(username) != -1) {
		return false; // cannot add a dupe name
	}else {
		profiles[numUsers] = p;
		numUsers += 1;
		return true; // add profile and return true
	}

}

int Network::findID(std::string username) {
	/*
		Conducts linear search on profiles, will return ID corresponding to the username
		which is its index or -1 if username is not found
	*/

	for(int i = 0; i < numUsers; i++) {
		if (profiles[i].get_username() == username) {
			return i; // return index
		}
	}
	return -1; // no entry found
}

bool Network::follow(std::string usr1, std::string usr2) {
	// updates following matrix to have usr1 follow usr2

	int id1 = findID(usr1);
	int id2 = findID(usr2);

	if(id1 == -1 || id2 == -1 || id1 == id2) {
		return false;
	}

	//updating matrix
	following[id1][id2] = true;

	return true; //successful
}

void Network::printDot() {
	/*
		Generates a dot network in raw format displaying
		relationships in the following matrix 
	*/

	std::string return_string = "digraph {\n";

	for(int i=0; i<numUsers;i++) {
		return_string = return_string + "\t\"@" + profiles[i].get_username() + "\"" + "\n"; 
	} // adding the existing nodes

	return_string = return_string + "\n";

	//adding relationships
	for(int i = 0; i<numUsers;i++) {
		for(int j = 0;j<numUsers;j++) {
			// for each relationship add a connection for each one true
			if(following[i][j]) { // if i follows j
				return_string = return_string + "\t\"@" + profiles[i].get_username() + "\"" + " -> " + "\"@" + profiles[j].get_username() + "\"" + "\n";
			}
		}
	}

	// closing the brackets
	return_string = return_string + "}";	

	std::cout << return_string << std::endl;
}