#pragma once
#include "driverMatchingStrategy.hpp"

class LeastTimeBasedMatchingStrategy : public DriverMatchingStrategy {
public:
	Driver* matchDriver(TripMetaData* pMetaData) {
		DriverMgr* driverMgr = DriverMgr::getDriverMgr();

		if ((driverMgr->getDriversMap()).size() == 0) {
			cout << "No drivers! What service is this huh?" << endl;
		}
		cout << "Using quadtree to see nearest cabs, using driver manager to get details of drivers and send notifications" << endl;
		Driver* driver = ((driverMgr->getDriversMap()).begin())->second; //here we can call quadtree algo to get nearest cabs
		cout << "Setting " << driver->getDriverName() << " as driver" << endl;
		pMetaData->setDriverRating(driver->getRating());
		return driver;
	}
};