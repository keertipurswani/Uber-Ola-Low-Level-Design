#pragma once

#include "rider.hpp"
#include "mutex"

class RiderMgr {
	RiderMgr(){}
	static RiderMgr* riderMgrInstance;
	static mutex mtx;
	unordered_map<string, Rider*> ridersMap;
public:
	static RiderMgr* getRiderMgr();
	void addRider(string pRiderName, Rider* pRider);
	Rider* getRider(string pRiderName);
};