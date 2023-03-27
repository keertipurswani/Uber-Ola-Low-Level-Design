#pragma once
#include "common.hpp"

class Driver {
	string name;
	bool avail;
	RATING rating;
public:
	Driver(string pName, RATING pRating) : name(pName), rating(pRating) {
		avail = false;
	}
	void updateAvail(bool pAvail) {
		avail = pAvail;
	}
	string getDriverName() {
		return name;
	}
	RATING getRating() {
		return rating;
	}
};