#pragma once
#include "riderMgr.hpp"
#include "driverMgr.hpp"
#include "tripMetaData.hpp"
#include "trip.hpp"
#include "mutex"
#include "strategyMgr.hpp"

class TripMgr {
	static TripMgr* tripMgrInstance;
	static mutex mtx;
	TripMgr(){
		riderMgr = RiderMgr::getRiderMgr();
		driverMgr = DriverMgr::getDriverMgr();
	}
	RiderMgr* riderMgr;
	DriverMgr* driverMgr;
	unordered_map<int, TripMetaData*> tripsMetaDataInfo; 
	unordered_map<int, Trip*> tripsInfo;
public:
	static TripMgr* getTripMgr();
	void CreateTrip(Rider* pRider, Location* pSrcLoc, Location* pDstLoc);
	unordered_map<int, Trip*> getTripsMap();
};