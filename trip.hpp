#pragma once
#include "rider.hpp"
#include "driver.hpp"
#include "pricingStrategy.hpp"
#include "driverMatchingStrategy.hpp"

class Trip {
	Rider* rider;
	Driver* driver;
	Location* srcloc;
	Location* dstLoc;
	TRIP_STATUS status;
	int tripId;
	double price;
	PricingStrategy* pricingStrategy;
	DriverMatchingStrategy* driverMatchingStrategy;
public:
	Trip(Rider* pRider, Driver* pDriver, Location* pSrcLoc, Location* pDstLoc, double pPrice,
		PricingStrategy* pPricingStrategy, DriverMatchingStrategy* pDriverMatchingStrategy) : 
		rider(pRider), driver(pDriver), srcloc(pSrcLoc), dstLoc(pDstLoc), price(pPrice),
		pricingStrategy(pPricingStrategy), driverMatchingStrategy(pDriverMatchingStrategy) {
		status = TRIP_STATUS::DRIVER_ON_THE_WAY;
		//This is not threadsafe and is just for demo purposes
		tripId = nextTripId;
		nextTripId++;
	}
	int getTripId() {
		return tripId;
	}
	void displayTripDetails() {
		cout << endl;
		cout << "Trip id - " << tripId << endl;
		cout << "Rider - " << rider->getRiderName() << endl;
		cout << "Driver - " << driver->getDriverName() << endl;
		cout << "Price - " << price << endl;
		cout << "Locations - " <<srcloc->latitude<<","<<srcloc->longitude<<" and "<<dstLoc->latitude<<","<<dstLoc->longitude << endl;
	}
};