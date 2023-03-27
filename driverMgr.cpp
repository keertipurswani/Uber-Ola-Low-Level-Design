#include "driverMgr.hpp"

DriverMgr* DriverMgr::driverMgrInstance = nullptr;
mutex DriverMgr::mtx;

DriverMgr* DriverMgr::getDriverMgr() {
	if (driverMgrInstance == nullptr) {
		mtx.lock();
		if (driverMgrInstance == nullptr) {
			driverMgrInstance = new DriverMgr();
		}
		mtx.unlock();
	}
	return driverMgrInstance;
}

void DriverMgr::addDriver(string pDriverName, Driver * pDriver) {
	driversMap[pDriverName] = pDriver;
}
Driver* DriverMgr::getDriver(string pDriverName) {
	return driversMap[pDriverName];
}

unordered_map<string, Driver*> DriverMgr::getDriversMap() {
	return driversMap;
}