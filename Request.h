#include <iostream>
#include <string>
#include <math.h>
using namespace std;	
const int FloorDelay = 1000;

class InsideRequest
{
private:
	int DestinationFloor;
	string Direction; //{UP , DOWN}

public:
	InsideRequest(int DF , int CF)
	{
		DestinationFloor = DF;
		if(CF > DestinationFloor)
			Direction = "DOWN";
		else
			Direction = "UP";
	}

	int RequestTime(int CF) 
	{
		return abs(DestinationFloor - CF)*FloorDelay;
	}

	int getDestinationFloor()
	{
		return DestinationFloor;
	}

	string getDirection()
	{
		return Direction;
	}
};

class OutsideRequest
{
private:
	int DestinationFloor;
	string Direction; //{UP , DOWN}
public:
	OutsideRequest(int DF , int CF)
	{
		DestinationFloor = DF;
		if(CF > DestinationFloor)
			Direction = "DOWN";
		else
			Direction = "UP";
	}

	int RequestTime(int CF) 
	{
		return abs(DestinationFloor - CF)*FloorDelay;
	}

	int getDestinationFloor()
	{
		return DestinationFloor;
	}

	string getDirection()
	{
		return Direction;
	}
};
