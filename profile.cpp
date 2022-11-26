/*
	Patrick Ging
	Professor Zamanksy
	Lab 11
	social.cpp

	has implementation of Profile class in profile.h
*/
#include <iostream>

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
	*/
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
	return new_display_name;
	}

std::string get_full_name() {
	/*
		Returns string in format display_name (@username)
	*/
	return display_name + " (@" + username + ")";
}