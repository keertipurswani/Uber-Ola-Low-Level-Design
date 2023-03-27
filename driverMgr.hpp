#pragma once

#include "driver.hpp"
#include "mutex"

class DriverMgr {
	DriverMgr(){}
	static DriverMgr* driverMgrInstance;
	static mutex mtx;	
	unordered_map<string, Driver*> driversMap;
public:
	static DriverMgr* getDriverMgr();
	void addDriver(string pDriverName, Driver* pDriver);
	Driver* getDriver(string pDriverName);
	unordered_map<string, Driver*> getDriversMap();
};
