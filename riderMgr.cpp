#include "riderMgr.hpp"
RiderMgr* RiderMgr::riderMgrInstance = nullptr;
mutex RiderMgr::mtx;

RiderMgr* RiderMgr::getRiderMgr() {
	if (riderMgrInstance == nullptr) {
		mtx.lock();
		if (riderMgrInstance == nullptr) {
			riderMgrInstance = new RiderMgr();
		}
		mtx.unlock();
	}
	return riderMgrInstance;
}

void RiderMgr::addRider(string pRiderName, Rider* pRider) {
	ridersMap[pRiderName] = pRider; 
}
Rider* RiderMgr::getRider(string pRiderName) {
	return ridersMap[pRiderName];
}