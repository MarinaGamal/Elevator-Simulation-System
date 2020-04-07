#include <fstream>
#include <time.h>
#include "Elevator.h"
#include <iostream>
using namespace std;
int main()
{
	clock_t startTime = clock();
	ifstream input("elevator_input.txt");
	Elevator e = Elevator();
	int choice;
	int n;
	int DF;
	int CF;
	input >> CF;
	e.setCurrentFloor(CF);
	input >> choice;
	while(choice != 6)
	{
		if(choice == 1)
		{
			input >> DF;
			InsideRequest r = InsideRequest(DF,e.getCurrentFloor());
			e.addInsideRequest_1(r);
		}

		if(choice == 2)
		{
			input >> DF;
			OutsideRequest r = OutsideRequest(DF,e.getCurrentFloor());
			e.addOutsideRequest_1(r);
		}

		if(choice == 3)
			e.Operate_1();
	
		if(choice == 4)
			e.OperateOnce_1();

		if(choice == 5)
		{
			input >> n;
			e.Operate_n_1(n);
		}

		input >> choice;
	}
	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	cout << "GoodBye."  << endl;
	return 0;
}