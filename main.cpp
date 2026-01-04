#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include<cstdio>
#include"Header.h"
using namespace std;
int TMS::count = 0;
int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	//Till line 57 the code is for Login
	char opt;
	bool flag = false;
	int count = 1;
	string pass, id;
	Login objLog;
	cout << endl << endl;
	cout << setw(70) << "Login in your account" << endl << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	do
	{

		cout << endl;
		cout << "Please Enter the Admin ID " << endl;
		getline(cin, id);
		cout << "Please Enter the Admin Password " << endl;
		getline(cin, pass);
		flag = objLog.check(id, pass);
		if (!flag)
		{
			cout << "Wrong user name Paswword. You have " << 5 - count << " Attempts Remainig" << endl;
			count++;
		}
		else
		{
			cout << "You Successfully Login" << endl;
			Sleep(1000);
			system("cls");
			TMS* ptr;
			do
			{
				//After Successfully Login we are moving Towards the Dash Board
				int choice;

				cout << endl << endl;
				cout << setw(70) << "WelCome To Dash Board" << endl << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << setw(72) << "1- Manage Customer" << endl;
				cout << setw(72) << "2- Manage Driver  " << endl;
				cout << setw(72) << "3- Manage Vehicle " << endl;
				cout << setw(71) << "4- Manage Service" << endl;
				cout << setw(67) << "5_view report" << endl;
				cout << setw(72) << "6- Change Password" << endl;
				cout << setw(65) << "7- log out " << endl << endl << endl;
				do
				{
					cout << setw(70) << "Please Enter the Choice : "; cin >> choice;
					if (choice < 1 || choice>7)
						cout << "Invalid Input. Enter Again" << endl;
				} while (choice < 1 || choice>7);
				Sleep(1000);
				system("cls");
				if (choice == 1)
				{
					cout << "<-----------Manage customer----------->" << endl << endl;
					cout << "1- Add customer" << endl;
					cout << "2- Remover customer" << endl;
					cout << "3- Search customer" << endl;
					cout << "4- Update customer" << endl;
					cout << "5- View customer" << endl << endl;
					do
					{
						cout << setw(70) << "Please Entre the Choice : "; cin >> choice;
						if (choice < 1 || choice>5)
							cout << "Invalid Input. Entre Again" << endl;
					} while (choice < 1 || choice>5);
					Sleep(500);
					system("cls");
					customer obj;
					ptr = &obj;
					if (choice == 1)
					{
						cout << "<-------------------Add  Customer------------------->" << endl << endl;

						customer* objUser = new customer;
						objUser->add();
					}
					else if (choice == 2)
					{
						cout << "<-------------------Delete Customer------------------->" << endl << endl;

						ptr->Delete();
					}
					else if (choice == 3)
					{
						cout << "<-------------------Search Customer------------------->" << endl << endl;

						ptr->search();
					}
					else if (choice == 4)
					{
						cout << "<-------------------Update Customer------------------->" << endl << endl;

						ptr->update();
					}
					else if (choice == 5)
					{
						cout << "<-------------------View Customer------------------->" << endl << endl << endl;

						cout << "Customer ID \t\t Customer FName \t\t Customer LName  \t\t Customer Phone \t\t Customer Service name \t\t  Member Payment Method" << endl;
						ptr->view();

					}
				}
				else if (choice == 2)
				{
					cout << "<-----------Manage driver----------->" << endl << endl;
					cout << "1- Add driver" << endl;
					cout << "2- Remover driver" << endl;
					cout << "3- Search driver" << endl;
					cout << "4- Update driver" << endl;
					cout << "5- View driver" << endl << endl;;
					do
					{
						cout << setw(70) << "Please Entre the Choice : "; cin >> choice;
						if (choice < 1 || choice>5)
							cout << "Invalid Input. Entre Again" << endl;
					} while (choice < 1 || choice>5);
					Sleep(500);
					system("cls");
					driver obj;
					if (choice == 1)
					{
						cout << "<-------------------Add driver------------------->" << endl << endl;

						driver* objTrainer = new driver;
						objTrainer->add();
					}
					else if (choice == 2)
					{
						cout << "<-------------------Delete driver------------------->" << endl << endl;

						obj.Delete();
					}
					else if (choice == 3)
					{
						cout << "<-------------------Search driver------------------->" << endl << endl;

						obj.search();
					}
					else if (choice == 4)
					{
						cout << "<-------------------Update driver------------------->" << endl << endl;

						obj.update();
					}
					else if (choice == 5)
					{
						cout << "<-------------------View driver------------------->" << endl << endl << endl;

						cout << "driver ID \t\t driver Name \t\t driver lname \t\tdriver rank \t\t driver input \t\t driver Salary" << endl;
						obj.view();
					}
				}
				else if (choice == 3)
				{
					cout << "<-----------Manage vehicle----------->" << endl << endl;
					cout << "1- Add vehicle" << endl;
					cout << "2- Remover vehicle" << endl;
					cout << "3- Search vehicle" << endl;
					cout << "4- Update vehicle" << endl;
					cout << "5- View vehicle" << endl << endl;;
					do
					{
						cout << setw(70) << "Please Entre the Choice : "; cin >> choice;
						if (choice < 1 || choice>5)
							cout << "Invalid Input. Entre Again" << endl;
					} while (choice < 1 || choice>5);
					Sleep(500);
					system("cls");
					vehicle obj;
					vehicle* objveh = new vehicle;
					if (choice == 1)
					{
						cout << "<-------------------Add vehicle------------------->" << endl << endl;
							objveh->add();
					}
					else if (choice == 2)
					{
						cout << "<-------------------Delete vehicle------------------->" << endl << endl;

						obj.Delete();
					}
					else if (choice == 3)
					{
						cout << "<-------------------Search vehicle------------------->" << endl << endl;

						obj.search();
					}
					else if (choice == 4)
					{
						cout << "<-------------------Update vehicle------------------->" << endl << endl;

						obj.update();
					}
					else if (choice == 5)
					{
						cout << "<-------------------View vehicle------------------->" << endl << endl << endl;

						cout << "vehicle ID \tvehicle_maintype \t\tvehicle_subtype \t\t Hiring Date" << endl;
						objveh->view();
					}
				}
				else if (choice == 4)
				{
					cout << "<-----------Manage service----------->" << endl << endl;
					cout << "1- Add service" << endl;
					cout << "2- Remover service" << endl;
					cout << "3- Search service" << endl;
					cout << "4- Update service" << endl;
					cout << "5- View service" << endl << endl;
					do
					{
						cout << setw(70) << "Please Entre the Choice : "; cin >> choice;
						if (choice < 1 || choice>5)
							cout << "Invalid Input. Entre Again" << endl;
					} while (choice < 1 || choice>5);
					Sleep(500);
					system("cls");
				    service obj;
					if (choice == 1)
					{
						cout << "<-------------------Add service------------------->" << endl << endl;

						service* objStaff = new service;
						objStaff->add();
					}
					else if (choice == 2)
					{
						cout << "<-------------------Delete service------------------->" << endl << endl;

						obj.Delete();
					}
					else if (choice == 3)
					{
						cout << "<-------------------Search service------------------->" << endl << endl;

						obj.search();
					}
					else if (choice == 4)
					{
						cout << "<-------------------Update service------------------->" << endl << endl;

						obj.update();
					}
					else if (choice == 5)
					{
						cout << "<-------------------View service------------------->" << endl << endl << endl;

						cout << "vehicle  ID \t\t DISTANCE   \t\t fuel  Type \t\t  air_conditioner \t comfort_level \t booking date " << endl;
						obj.view();
					}
				}
	
				else if (choice == 5)
				{
					cout << "<-----------Reports----------->" << endl << endl;
					cout << "1- View Customer" << endl;
					cout << "2- View Driver" << endl;
					cout << "3- View Vehicle" << endl;
					cout << "4- View Service" << endl;
					do
					{
						cout << setw(70) << "Please Enter the Choice : "; cin >> choice;
						if (choice < 1 || choice>4)
							cout << "Invalid Input. Enter Again" << endl;
					} while (choice < 1 || choice>4);
					Sleep(500);
					system("cls");
					if (choice == 1)
					{
						customer obj;
						cout << "<-------------------View Customer------------------->" << endl << endl;
						cout << endl << endl;
						cout << "Customer ID \t\t Customer FName \t\t Customer LName  \t\t Customer Phone \t\t Customer Service name \t\t  Member Payment Method" << endl;
						obj.view();
					}
					else if (choice == 2)
					{
						driver obj;
						cout << "<-------------------View Driver------------------->" << endl << endl;
						cout << "driver ID \t\t driver Name \t\t driver lname \t\tdriver rank \t\t driver input \t\t driver Salary" << endl;
						obj.view();
					}
					else if (choice == 3)
					{
						vehicle obj;
						cout << "<-------------------View  vehicle------------------->" << endl << endl;
						cout << "vehicle ID \tvehicle_maintype \t\tvehicle_subtype \t\t Hiring Date" << endl;
						obj.view();
					}
					else if (choice == 4)
					{
						service obj;
						cout << "<-------------------View service------------------->" << endl << endl;
						cout << endl << endl;
						cout << "vehicle  ID \t\t DISTANCE   \t\t fuel  Type \t\t  air_conditioner \t comfort_level \t booking date " << endl;
						obj.view();
					}
				}
				else if (choice == 6)
				{
					string id, user_password, user_name, user_email, pass;
					cout << "Please Enter new Password " << endl; cin.ignore(); getline(cin, pass);
					ifstream getData("LoginClass.txt");
					ofstream writeData("demo.txt");
					if (!getData.is_open())
						cout << "Error While Openning the File" << endl;
					else
					{
						while (!getData.eof())
						{
							getData >> id >> user_password >> user_email >> user_name;
							writeData << id << " " << pass << " " << user_email << " " << user_name;
						}
						cout << endl;
						cout << "Password Change Successfully" << endl;
					}
					getData.close();
					writeData.close();
					remove("LoginClass.txt");
					rename("demo.txt", "LoginClass.txt");

				}

				else if (choice == 7)
				{
					break;
				}
				cout << endl << endl;
				cout << "Press Y to Return on Dash Board" << endl;
				cin >> opt;
				Sleep(250);
				system("cls");
			} while (opt == 'Y' || opt == 'y');
		}

	} while (!(flag) && count <= 5);
	if (count > 5)
		cout << setw(70) << "Account is Locked Permanently :-(" << endl;
	system("Pause");
	return 0;
}