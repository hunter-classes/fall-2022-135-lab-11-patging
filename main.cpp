/*
	Patrick Ging
	Professor Zamanksy
	Lab 11
	main.cpp
*/

#include <iostream>

#include "network.h"
#include "profile.h"

int main() {
	//profile functionalities
	Profile pat("Patrick", "pat");
	std::cout << "Creating profile w/ name Patrick and display name pat | " << pat.get_full_name() << std::endl;
	std::cout << "Set display name to patging" << std::endl;
	pat.set_display_name("patging");
	std::cout << "New name and displayname " << pat.get_full_name() << std::endl;

	// network functionalities

	Network nw;
	std::cout << "Initalizing network" << std::endl;

	nw.addUser("User1","Display1");
	nw.addUser("User2","Display3");
	nw.addUser("User3","Display3");

	//rejected additions b/c of duplicates and alphanumericy
	nw.addUser("User3","Display4");
	nw.addUser("/User", "display5");
	nw.addUser("","");
	std::cout << "Added three users" << std::endl;
	
	nw.follow("User1","User2");
	nw.follow("User2","User3");
	nw.follow("User3","User1");
	nw.follow("User4","User2"); // should be rejected

	std::cout << "User1 follows User2 and User2 follows User3 and User3 follows User 1" << std::endl;

	// task C printDot

	std::cout << "Viewdot of relationship.\n\n";

	nw.printDot();

	return 0;
}