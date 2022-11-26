#pragma once

#include <iostream>

#include "profile.h"

class Network {
	/*
		A network of users. Has stores Profile (see profile.h) network,
		can add/delete users and can do various operations using their data
	*/

	private:
		static const int MAX_USERS = 20;
		
		int numUsers; // num of usr
		
		Profile profiles[MAX_USERS]; // arr of profiles (see profile.h)

		bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
		/*
			So each col and line is a profile in the network, defined by their id;

			following[col][row] tells us whether or not user with id col and user with
			id row are friends
		*/


		//methods

  		int findID (std::string usrn); // method of returning id for usrname returns -1 elsewise

	public:

		Network(); // blank constructor

		bool addUser(std::string username, std::string display_name); // adds user with a usrname and display name

 		bool follow(string usrn1, string usrn2); // adds following func to network

 		void printDot(); // prints dot file of network

}


