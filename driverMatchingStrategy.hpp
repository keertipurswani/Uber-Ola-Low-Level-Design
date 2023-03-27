#pragma once

#include "tripMetaData.hpp"
#include "driverMgr.hpp"

class DriverMatchingStrategy {
public:
	virtual Driver* matchDriver(TripMetaData* pTripMetaData) = 0;
};