#pragma once

class Location {
public:
	double latitude;
	double longitude;
	Location(double pLatitude, double pLongitude) : latitude(pLatitude), longitude(pLongitude) {}
};