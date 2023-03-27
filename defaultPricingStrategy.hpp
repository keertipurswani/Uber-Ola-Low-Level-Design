#pragma once
#include "pricingStrategy.hpp"

class DefaultPricingStrategy : public PricingStrategy {
public:
	double calculatePrice(TripMetaData* pTripMetaData) {
		cout << "Based on default strategy, price is 100" << endl;
		return 100.0;
	}
};