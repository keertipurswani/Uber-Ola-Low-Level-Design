#pragma once
#include "pricingStrategy.hpp"
#include "common.hpp"

class RatingBasedPricingStrategy :public PricingStrategy {
public:
	double calculatePrice(TripMetaData* pTripMetaData) {
		double price = Util::isHighRating(pTripMetaData->getRiderRating()) ? 55.0 : 65.0;
		cout << "Based on " << Util::ratingToString(pTripMetaData->getRiderRating()) << 
			" rider rating, price of the trip is " << price << endl;
		return price;
	}
};