//#include "Elevator.h"
//#include <iostream>
//using namespace std;
//int main()
//{
//	Elevator e = Elevator();
//	int choice;
//	int n;
//	int DF;
//	int CF;
//	cout << "Choose desired current floor for elevator: ";
//	cin >> CF;
//	e.setCurrentFloor(CF);
//	cout << "1- Inside Request" << endl;
//	cout << "2- Outside Request" << endl;
//	cout << "3- Run" << endl;
//	cout << "4- Run once" << endl;
//	cout << "5- Run N times" << endl;
//	cout << "6- Exit" << endl;
//	cout << "Enter a choice: ";
//	cin >> choice;
//	while(choice != 6)
//	{
//		if(choice == 1)
//		{
//			cout << "Enter a floor: ";
//			cin >> DF;
//			InsideRequest r = InsideRequest(DF,e.getCurrentFloor());
//			e.addInsideRequest_3(r);
//		}
//
//		if(choice == 2)
//		{
//			cout << "Enter a floor: ";
//			cin >> DF;
//			OutsideRequest r = OutsideRequest(DF,e.getCurrentFloor());
//			e.addOutsideRequest_3(r);
//		}
//
//		if(choice == 3)
//			e.Operate_3();
//	
//		if(choice == 4)
//			e.OperateOnce_3();
//
//		if(choice == 5)
//		{
//			cout << "Enter Number of simulation times: ";
//			cin >> n;
//			e.Operate_n_3(n);
//		}
//
//		cout << "Enter a choice: ";
//		cin >> choice;
//	}
//
//	cout << "GoodBye."  << endl;
//	return 0;
//}