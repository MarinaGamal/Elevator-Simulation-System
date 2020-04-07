#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <vector>
#include <windows.h>
#include "Request.h"
using namespace std;
class Elevator
{
private:
	int CurrentFloor;	
	int DestinationFloor;
	int PassengerCount;
	string Status; //{UP , DOWN , WAIT , IDLE , MAINTAINANCE}
	//priority_queue<InsideRequest> InsideRequests;
	//priority_queue<OutsideRequest> OutsideRequests;
	list<int> Up;
	list<int> Down;
	list<int> Destination;
	vector<int> I_R;
	vector<int> O_R;
	vector<InsideRequest> IR;
	vector<OutsideRequest> OR;

public:
	Elevator()
	{
		CurrentFloor = 0;
		DestinationFloor = 0 ;
		PassengerCount = 1;
		Status = "IDLE";
		Up = list<int>();
		Down = list<int>();
		Destination = list<int>();
		I_R = vector<int>();
		O_R = vector<int>();
		IR = vector<InsideRequest>();
		OR = vector<OutsideRequest>();
	}

    int getCurrentFloor()
	{
		return CurrentFloor;
	}

	void setCurrentFloor(int CF)
	{
		CurrentFloor = CF;
		DestinationFloor = CF;
	}

	string getStatus()
	{
		return Status;
	}

	void addInsideRequest_1(InsideRequest r)
	{
		int DF = r.getDestinationFloor();
		if(Up.empty() && Down.empty())
		{
			if(DF > CurrentFloor)
			{
				Up.push_back(DF);
				Status = "UP";
				Destination.push_back(DF);
				I_R.push_back(DF);
			}
			else
			{
				Down.push_back(DF);
				Status = "DOWN";
				Destination.push_back(DF);
				I_R.push_back(DF);
			}
		}
		else
		{
			if(Status == "UP")
			{
				if(DF > Destination.front())
				{
					//Destination.push_back(DF);
					//Destination.sort();
					//Up.push_back(DF);
					//Up.sort();
					ManageUpList(Up , Destination , DF);
					I_R.push_back(DF);

				}

				else
				{
					Down.push_back(DF);
					I_R.push_back(DF);
					Down.sort();
					Down.reverse();
				}
			}

			else
			{
				if(DF < Destination.front())
				{
					//Destination.push_back(DF);
					//Destination.sort();
					//Destination.reverse();
					//Down.push_back(DF);
					//Down.sort();
					//Down.reverse();
					ManageDownList(Down , Destination , DF);
					I_R.push_back(DF);

				}

				else
				{
					Up.push_back(DF);
					I_R.push_back(DF);
					Up.sort();
				}
			}
		}
	}

	void addOutsideRequest_1(OutsideRequest r)
	{
		int DF = r.getDestinationFloor();
		if(Up.empty() && Down.empty())
		{
			if(DF > CurrentFloor)
			{
				Up.push_back(DF);
				Status = "UP";
				Destination.push_back(DF);
				O_R.push_back(DF);
			}
			else
			{
				Down.push_back(DF);
				Status = "DOWN";
				Destination.push_back(DF);
				O_R.push_back(DF);
			}
		}
		else
		{
			if(Status == "UP")
			{
				if(DF > Destination.front())
				{
					//Destination.push_back(DF);
					//Destination.sort();
					//Up.push_back(DF);
					//Up.sort();
					ManageUpList(Up , Destination , DF);
					O_R.push_back(DF);

				}

				else
				{
					Down.push_back(DF);
					O_R.push_back(DF);
					Down.sort();
					Down.reverse();
				}
			}

			else
			{
				if(DF < Destination.front())
				{
					//Destination.push_back(DF);
					//Destination.sort();
					//Destination.reverse();
					//Down.push_back(DF);
					//Down.sort();
					//Down.reverse();
					ManageDownList(Down , Destination , DF);
					O_R.push_back(DF);

				}

				else
				{
					Up.push_back(DF);
					Up.sort();
					O_R.push_back(DF);
				}
			}
		}
	}

	//void addInsideRequest_2(InsideRequest r)
	//{
	//	int DF = r.getDestinationFloor();
	//	if(Status == "IDLE")
	//	{
	//		if(DF > CurrentFloor)
	//		{
	//			Up.push_back(DF);
	//			Status = "UP";
	//		}
	//
	//		else
	//		{
	//			Down.push_back(DF);
	//			Status = "DOWN";
	//		}
	//	}
	//
	//	else //(Status == "UP" || Status == "DOWN")
	//	{
	//		if(DF > CurrentFloor)
	//		{
	//			Up.push_back(DF);
	//			Up.sort();
	//		}
	//
	//		else
	//		{
	//			Down.push_back(DF);
	//			Down.sort();
	//			Down.reverse();
	//		}
	//	}
	//}	

	//void addOutsideRequest_2(OutsideRequest r)
	//{
	//	int DF = r.getDestinationFloor();
	//	if(Status == "IDLE")
	//	{
	//		if(DF > CurrentFloor)
	//		{
	//			Up.push_back(DF);
	//			Status = "UP";
	//		}
	//
	//		else
	//		{
	//			Down.push_back(DF);
	//			Status = "DOWN";
	//		}
	//	}
	//
	//	else //(Status == "UP" || Status == "DOWN")
	//	{
	//		if(DF > CurrentFloor)
	//		{
	//			Up.push_back(DF);
	//			Up.sort();
	//		}
	//
	//		else
	//		{
	//			Down.push_back(DF);
	//			Down.sort();
	//			Down.reverse();
	//		}
	//	}
	//}
	
	void addInsideRequest_3(InsideRequest r){IR.push_back(r); I_R.push_back(r.getDestinationFloor());}

	void addOutsideRequest_3(OutsideRequest r){OR.push_back(r); O_R.push_back(r.getDestinationFloor());}

	void MoveUp()
	{
		CurrentFloor++;
	}

	void MoveDown()
	{
		CurrentFloor--;
	}

	void Operate_1()
	{
		if(Status == "IDLE")
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;

		if(Status == "UP")
		{
			while(!Destination.empty())
			{
				 int DF = Destination.front();
				 Destination.pop_front();
				 if(!Up.empty())
					Up.pop_front();
				 while(CurrentFloor != DF)
				 {
					 MoveUp();
					 Sleep(FloorDelay);
					 cout << CurrentFloor <<" - " << Status << endl;
				 }

				 Wait(DF);
			}
			Down.swap(Destination);
			while(!Destination.empty())
			{
				 Status = "DOWN";
				 int DF = Destination.front();
				 Destination.pop_front();
				 while(CurrentFloor != DF)
				 {
					 MoveDown();
					 Sleep(FloorDelay);
					 cout << CurrentFloor <<" - " << Status << endl;
				 }

				 Wait(DF);
			}

			Status = "IDLE";
			cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
			cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
		}

		else if(Status == "DOWN")
		{
			while(!Destination.empty())
			{
				 int DF = Destination.front();
				 Destination.pop_front();
				 if(!Down.empty())
					Down.pop_front();
				 while(CurrentFloor != DF)
				 {
					 MoveDown();
					 Sleep(FloorDelay);
					 cout << CurrentFloor <<" - " << Status << endl;
				 }

				 Wait(DF);
			}
			Up.swap(Destination);
			while(!Destination.empty())
			{
				 Status = "UP";
				 int DF = Destination.front();
				 Destination.pop_front();
				 while(CurrentFloor != DF)
				 {
					 MoveUp();
					 Sleep(FloorDelay);
					 cout << CurrentFloor <<" - " << Status << endl;
				 }
				 Wait(DF);
			}

			Status = "IDLE";
			cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
			cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
		}
	}

	/*void Operate_2()
	{
		if(Status == "IDLE")
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;

		if(Status == "UP")
		{
			while(!Up.empty())
			{
				 int DF = Up.front();
				 Up.pop_front();
				 while(CurrentFloor != DF)
				 {
					 MoveUp();
					 Sleep(FloorDelay);
					 cout << CurrentFloor <<" - " << Status << endl;
				 }
			}

			while(!Down.empty())
			{
				 Status = "DOWN";
				 int DF = Down.front();
				 Down.pop_front();
				 while(CurrentFloor != DF)
				 {
					 MoveDown();
					 Sleep(FloorDelay);
					 cout << CurrentFloor <<" - " << Status << endl;
				 }
			}
			Status = "IDLE";
			cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
			cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
		}

		else if(Status == "DOWN")
		{
			while(!Down.empty())
			{
				 int DF = Down.front();
				 Down.pop_front();
				 while(CurrentFloor != DF)
				 {
					 MoveDown();
					 Sleep(FloorDelay);
					 cout << CurrentFloor <<" - " << Status << endl;
				 }
			}
			
			while(!Destination.empty())
			{
				 Status = "UP";
				 int DF = Up.front();
				 Up.pop_front();
				 while(CurrentFloor != DF)
				 {
					 MoveUp();
					 Sleep(FloorDelay);
					 cout << CurrentFloor <<" - " << Status << endl;
				 }
			}
			Status = "IDLE";
			cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
			cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
		}
	}*/

	void Operate_3()
	{
		if(IR.empty() && OR.empty())
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;

		else
		{
			while(!IR.empty() || !OR.empty())
			{
				int DF = STR(IR , OR , CurrentFloor);
				while(DF != CurrentFloor)
				{
					if(DF - CurrentFloor > 0)
					{
						Status = "UP";
						MoveUp();
						Sleep(FloorDelay);
						cout << CurrentFloor <<" - " << Status << endl;
					}

					else
					{
						Status = "DOWN";
						MoveDown();
						Sleep(FloorDelay);
						cout << CurrentFloor <<" - " << Status << endl;
					}
				}	
				Wait(DF);
			}	
			Status = "IDLE";
			cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
			cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
			DestinationFloor = CurrentFloor;
		}
	}

	void OperateOnce_1()
	{
		if(Status == "IDLE")
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;

		else if(Status == "UP")
		{
			int DF = Destination.front();

			if(DF == CurrentFloor)
			{
				Wait(DF);
				Destination.pop_front();
				if(!Up.empty())
					Up.pop_front();

				if(Up.empty() && Down.empty() && Destination.empty())
					{
						Status = "IDLE";
						cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
						cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
					}
			 
				else if(Up.empty() && !Down.empty())
					{
						Down.swap(Destination);
		   				Status = "DOWN";
						int DF = Destination.front();
						MoveDown();
						Sleep(FloorDelay);
						cout << CurrentFloor <<" - " << Status << endl;
					}
			}

			else
			{
				MoveUp();
				Sleep(FloorDelay);
				cout << CurrentFloor <<" - " << Status << endl;
			}
		}

		else if(Status == "DOWN")
		{
			int DF = Destination.front();

			if(DF == CurrentFloor)
			{
				Wait(DF);
				Destination.pop_front();

				if(!Down.empty())
					Down.pop_front();

				if(Down.empty() && Up.empty() && Destination.empty())
				{
					Status = "IDLE";
					cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
					cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
				}
			 
				else if(Down.empty() && !Up.empty())
				{
					Up.swap(Destination);
		   			Status = "UP";
					int DF = Destination.front();
					MoveUp();
					Sleep(FloorDelay);
					cout << CurrentFloor <<" - " << Status << endl;
				}						
			}

			else
			{
				MoveDown();
				Sleep(FloorDelay);
				cout << CurrentFloor <<" - " << Status << endl;
			}
		}
	}

	/*void OperateOnce_2()
	{
		if(Status == "IDLE")
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;

		else if(Status == "UP")
		{
			int DF = Up.front();

			if(DF == CurrentFloor)
			{
				Up.pop_front();

				if(Up.empty() && Down.empty())
					{
						Status = "IDLE";
						cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
						cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
					}
			 
				else if(Up.empty() && !Down.empty())
					{
		   				Status = "DOWN";
						int DF = Down.front();
						MoveDown();
						Sleep(FloorDelay);
						cout << CurrentFloor <<" - " << Status << endl;
					}
			}

			else
			{
				MoveUp();
				Sleep(FloorDelay);
				cout << CurrentFloor <<" - " << Status << endl;
			}
		}

		else if(Status == "DOWN")
		{
			int DF = Down.front();

			if(DF == CurrentFloor)
			{
				Down.pop_front();

				if(Down.empty() && Up.empty())
				{
					Status = "IDLE";
					cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
					cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
				}
			 
				else if(Down.empty() && !Up.empty())
				{
		   			Status = "UP";
					int DF = Up.front();
					MoveUp();
					Sleep(FloorDelay);
					cout << CurrentFloor <<" - " << Status << endl;
				}						
			}

			else
			{
				MoveDown();
				Sleep(FloorDelay);
				cout << CurrentFloor <<" - " << Status << endl;
			}
		}
	}*/

	void OperateOnce_3()
	{
		if(IR.empty() && OR.empty() && Status == "IDLE")
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;

		else
		{
			if(CurrentFloor == DestinationFloor)
				DestinationFloor = STR(IR , OR , CurrentFloor);

			if(CurrentFloor == DestinationFloor)
				Wait(DestinationFloor);

			else if(DestinationFloor - CurrentFloor > 0)
			{
				Status = "UP";
				MoveUp();
				Sleep(FloorDelay);
				cout << CurrentFloor <<" - " << Status << endl;
			}

			else
			{
				Status = "DOWN";
				MoveDown();
				Sleep(FloorDelay);
				cout << CurrentFloor <<" - " << Status << endl;
			}

			if(CurrentFloor == DestinationFloor && IR.empty() && OR.empty())
			{
				Status = "IDLE";
				cout << CurrentFloor <<" - " << Status << " - Elevator has finished working." <<endl;
				cout << Up.empty() << " - " << Down.empty() << " - " << Destination.empty() << endl;
			}

			else if(CurrentFloor == DestinationFloor)
					Wait(DestinationFloor);
		}	
	}

	void Operate_n_1(int n)
	{
		if(Status == "IDLE")
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;
		else
			for(int i=0 ; i <= n ; i++)
				OperateOnce_1();
	}

	/*void Operate_n_2(int n)
	{
		if(Status == "IDLE")
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;
		else
			for(int i=0 ; i <= n ; i++)
				OperateOnce_2();
	}*/

	void Operate_n_3(int n)
	{
		if(IR.empty() && OR.empty())
			cout << "Elevator is IDLE at Floor " << CurrentFloor << endl;
		else
			for(int i=0 ; i <= n ; i++)
				OperateOnce_3();
	}

	void Wait(int DF)
	{
		string OldStatus = Status;
		Status = "WAIT";
		int flag = 0;
		for(int i=0 ; i < I_R.size() ; i++)
			if(I_R[i] == DF)
			{
				 flag = 1;
				 cout << CurrentFloor << " - " << Status << " - Passenger " << PassengerCount << " is out." << endl;
				 PassengerCount++;
				 I_R[i] = 0;
				 Status = OldStatus;
				 break;
			 }

			if(flag == 1)
				return;

			else
				for(int i=0 ; i < O_R.size() ; i++)
					if(O_R[i] == DF)
					{
						cout << CurrentFloor << " - " << Status << " - Passenger " << PassengerCount << " is in." << endl;
						PassengerCount++;
						O_R[i] = 0;
						 Status = OldStatus;
						break;
					}

	}

	int STR(vector<InsideRequest>& inside , vector<OutsideRequest>& outside , int CF)
	{
		if(!inside.empty() && !outside.empty())
		{
			int min_time_1 = inside[0].RequestTime(CF);
			int index_1 = 0;

			for(int i=0 ; i < inside.size() ; i++)
			{
				if(inside[i].RequestTime(CF) < min_time_1)
				{
					min_time_1 = inside[i].RequestTime(CF);
					index_1 = i;
				}
			}

			int min_time_2 = outside[0].RequestTime(CF);
			int index_2 = 0;
			for(int i=0 ; i < outside.size() ; i++)
			{
				if(outside[i].RequestTime(CF) < min_time_2)
				{
					min_time_2 = outside[i].RequestTime(CF);
					index_2 = i;
				}	
			}

			if(min_time_1 < min_time_2)
			{
				int DF = inside[index_1].getDestinationFloor();
				inside.erase(inside.begin()+index_1);
				return DF;
			}

			else
			{
				int DF = outside[index_2].getDestinationFloor();
				outside.erase(outside.begin()+index_2);
				return DF;
			}
		}

		else if(!inside.empty() && outside.empty())
		{
			int min_time_1 = inside[0].RequestTime(CF);
			int index_1 = 0;

			for(int i=0 ; i < inside.size() ; i++)
			{
				if(inside[i].RequestTime(CF) < min_time_1)
				{
					min_time_1 = inside[i].RequestTime(CF);
					index_1 = i;
				}
			}

				int DF = inside[index_1].getDestinationFloor();
				inside.erase(inside.begin()+index_1);
				return DF;
		}

		else
		{
			int min_time_2 = outside[0].RequestTime(CF);
			int index_2 = 0;

			for(int i=0 ; i < outside.size() ; i++)
			{
				if(outside[i].RequestTime(CF) < min_time_2)
				{
					min_time_2 = inside[i].RequestTime(CF);
					index_2 = i;
				}
			}

				int DF = outside[index_2].getDestinationFloor();
				outside.erase(outside.begin()+index_2);
				return DF;
		}
	}

	void ManageUpList(list<int>& up , list<int>& destination , int DF)
	{
		destination.push_back(DF);
		destination.sort();
		up.push_back(DF);
		up.sort();
	}

	void ManageDownList(list<int>& down , list<int>& destination , int DF)
	{
		destination.push_back(DF);
		destination.sort();
		destination.reverse();
		down.push_back(DF);
		down.sort();
		down.reverse();
	}
};



