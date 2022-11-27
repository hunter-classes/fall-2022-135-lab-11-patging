/*
	Patrick	Ging
	Professor Zamanksy
	Lab 11
	tests.cpp
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Testing Profile Class") {

	Profile p1("Name1","Disp");

	CHECK(p1.get_username() == "Name1");
	CHECK(p1.get_display_name() == "Disp");

	// rejected entries
	Profile p2("","Disp");
	Profile p3("Nam_e","Disp2");

	CHECK(p2.get_username() == "");
	CHECK(p2.get_display_name() != "Disp");

	CHECK(p3.get_username() == "");
	CHECK(p3.get_display_name() != "Disp2");

	Profile p4;
	CHECK(p4.get_username() == "");
	CHECK(p4.get_display_name() == "");
}

TEST_CASE("Testing network Class") {
	Network nw;

	//adding entries
	CHECK(nw.addUser("0","Ging"));
	CHECK(nw.addUser("1","Dragon"));

	//reject entries
	CHECK(! nw.addUser("0","Ging"));
	CHECK(! nw.addUser("1","Ging"));
	CHECK(! nw.addUser("","Ging"));
	CHECK(! nw.addUser("Pat_","Ging"));

	//follow 

	CHECK(nw.follow("0","1"));
	CHECK(nw.follow("1","0"));
	CHECK(!nw.follow("000","1"));
	CHECK(!nw.follow("0","0"));

	//capacity
	Network nw2;
	for(int i=0; i<20;i++) {
		nw2.addUser("Pat" + std::to_string(i), "ssss");
	}
	CHECK(! nw2.addUser("Pat","Ging"));


}