#pragma once
#include <iostream>
#include "unordered_map"
#include "location.hpp"

using namespace std;

static int nextTripId = 1;

enum class RATING {
	UNASSIGNED,
	ONE_STAR,
	TWO_STARS,
	THREE_STARS,
	FOUR_STARS,
	FIVE_STARS,
};

enum class TRIP_STATUS {
	UNASSIGNED,
	DRIVER_ON_THE_WAY,
	DRIVER_ARRIVED,
	STARTED,
	PAUSED,
	CANCELLED,
	ENDED,
};

class Util {
public:
	static string ratingToString(RATING pRating) {
		if (pRating == RATING::ONE_STAR)
			return "one star";
		if (pRating == RATING::TWO_STARS)
			return "two stars";
		if (pRating == RATING::THREE_STARS)
			return "three stars";
		if (pRating == RATING::FOUR_STARS)
			return "four stars";
		if (pRating == RATING::FIVE_STARS)
			return "five stars";
		return "invalid rating";
	}

	static bool isHighRating(RATING pRating) {
		return pRating == RATING::FOUR_STARS || pRating == RATING::FIVE_STARS;
	}
};
