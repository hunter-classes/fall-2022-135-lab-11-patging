/*
	Patrick Ging
	Professor Zamanksy
	Lab 11
	social.cpp

	has implementation of Profile class in profile.h
*/
#include <iostream>
#include <cctype>
#include "profile.h"

Profile::Profile() {
	/*
		Default constructor, will init empty fields for username and displayname
	*/
	username = "";
	display_name = "";	
}

Profile::Profile(std::string uname, std::string dname) {
	/*
		Profile constuctor. Assigns username and display_name

		username cannot be blank or non-alphanumeric and must be unique
		or else returns blank profile
	*/

	//checking username for blank & alphanumericy
	if (uname == "") {
		username = "";
		display_name = "";	
		return;
	}

	for(int i=0; i<uname.length();i++) {
		if (! std::isalnum(uname[i])) {
			username = "";
			display_name = "";	
			return;
		}
	}

	username = uname;
	display_name = dname;	
}

//getters
std::string Profile::get_username() {
	// getter for username
	return username;
}

std::string Profile::get_display_name() {
	//getter for display_name
	return display_name;
	}

//setters
void Profile::set_display_name(std::string new_display_name) {
	//sets display_name to new_display_name
	display_name = new_display_name;
	}

std::string Profile::get_full_name() {
	/*
		Returns string in format display_name (@username)
	*/
	return display_name + " (@" + username + ")";
}