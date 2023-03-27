#pragma once
#include "tripMetaData.hpp"

class PricingStrategy {
public:
	virtual double calculatePrice(TripMetaData* pTripMetaData) = 0;
};