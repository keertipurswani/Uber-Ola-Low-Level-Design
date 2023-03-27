#pragma once
#include "common.hpp"

class Rider {
	string name;
	RATING rating;
public:
	Rider(string pName, RATING pRating) : name(pName), rating(pRating) {}
	string getRiderName() {
		return name;
	}
	RATING getRating() {
		return rating;
	}
}; 