#include "tripMgr.hpp"

TripMgr* TripMgr::tripMgrInstance = nullptr;
mutex TripMgr::mtx;


TripMgr* TripMgr::getTripMgr() {
	if (tripMgrInstance == nullptr) {
		mtx.lock();
		if (tripMgrInstance == nullptr) {
			tripMgrInstance = new TripMgr();
		}
		mtx.unlock();
	}
	return tripMgrInstance;
}

void TripMgr::CreateTrip(Rider* pRider, Location* pSrcLoc, Location* pDstLoc) {
	
	TripMetaData* metaData = new TripMetaData(pSrcLoc, pDstLoc, pRider->getRating());
	StrategyMgr* strategyMgr = StrategyMgr::getStrategyMgr();
	PricingStrategy* pricingStrategy = strategyMgr->determinePricingStrategy(metaData);
	DriverMatchingStrategy* driverMatchingStrategy = strategyMgr->determineMatchingStrategy(metaData);
	
	Driver* driver = driverMatchingStrategy->matchDriver(metaData);
	double tripPrice = pricingStrategy->calculatePrice(metaData);

	Trip* trip = new Trip(pRider, driver, pSrcLoc, pDstLoc, tripPrice, pricingStrategy, driverMatchingStrategy);
	int tripId = trip->getTripId();
	tripsInfo[tripId] = trip;
	tripsMetaDataInfo[tripId] = metaData;
}

unordered_map<int, Trip*> TripMgr::getTripsMap() {
	return tripsInfo;
}