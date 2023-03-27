#include "strategyMgr.hpp"

StrategyMgr* StrategyMgr::strategyMgrInstance = nullptr;
mutex StrategyMgr::mtx;

StrategyMgr* StrategyMgr::getStrategyMgr() {
	if (strategyMgrInstance == nullptr) {
		mtx.lock();
		if (strategyMgrInstance == nullptr) {
			strategyMgrInstance = new StrategyMgr();
		}
		mtx.unlock();
	}
	return strategyMgrInstance;
}

PricingStrategy* StrategyMgr::determinePricingStrategy(TripMetaData* metaData) {
	cout << "Based on location and other factors, setting pricing strategy" << endl;
	return new DefaultPricingStrategy();
}

DriverMatchingStrategy* StrategyMgr::determineMatchingStrategy(TripMetaData* metaData) {
	cout << "Based on location and other factors, setting matching strategy" << endl;
	return new LeastTimeBasedMatchingStrategy();
}