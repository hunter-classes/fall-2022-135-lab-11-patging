#pragma once

#include <iostream>

class Profile {
	/*
		Profile Class

		Has info about as user's username and display_name
	*/
	private:
		std::string username;
		std::string display_name;

	public:
		// constructor
		Profile(std::string uname, std::string dname);
		Profile();
		//getters
		std::string get_username();
		std::string get_display_name();

		//setters
		void set_display_name(std::string new_display_name);

		//methods
		std::string get_full_name(); // formats as displayName (@username)

};