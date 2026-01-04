#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include<cstdio>
#include"Header.h"
using namespace std;
//Login Class Functions
void printLicenseType(LicenseType L)
{
	switch (L)
	{
	case LicenseType::MOTORCAR_JEEP:
		cout << "MOTORCAR_JEEP" << endl;
		break;
	case LicenseType::MOTORBIKE_RICKSHAW:
		cout << "MOTORBIKE_RICKSHAW" << endl;
		break;
	case LicenseType::LTV:
		cout << "LTV" << endl;
		break;
	case LicenseType::HTV:
		cout << "HTV" << endl;
		break;
	case LicenseType::TRACTOR:
		cout << "TRACTOR" << endl;
		break;
	case LicenseType::PSV:
		cout << "PSV" << endl;
		break;
	case LicenseType::INTERNATIONAL:
		cout << "INTERNATIONAL" << endl;
		break;
	}
}
Login::Login()
{
	id = "1234";
	user_password = "abc";
	user_email = "f223343@cfd.nu.edu.pk";
	user_name = "22F-3414";
	ofstream writeData("LoginClass.txt");
	writeData << id << " " << user_password << " " << user_email << " " << user_name;
	writeData.close();
}
Login::~Login() {}
bool Login::check(string ad_id, string pass)
{
	ifstream getData("LoginClass.txt");
	if (getData.is_open())
		getData >> id >> user_password;
	if ((user_password == pass) && (id == ad_id))
		return true;
	else
		return false;
}
//Users Class             Abstract Class
TMS::TMS()
{
	count += 1;
}
int TMS::getCount()
{
	return count;
}
void TMS::setId(string i)
{
	id = i;
}
string TMS::getID()
{
	return id;
}
void TMS::set_FName(string fn)
{
	name = fn;
}
string TMS::get_FName()
{
	return name;
}
void TMS::set_Lname(string ln)
{
	lname = ln;
}
string TMS::get_Lname()
{
	return lname;
}
void TMS::setPhone(string ph)
{
	phone = ph;
}
string TMS::getPhone()
{
	return phone;
}
// Class driver
driver::driver() {}
void driver::add()
{
	float rank;
	float salary = 10000;
	int input;
	TMS* ptr;
	driver obj;
	ptr = &obj;
	cout << "Enter The driver ID" << endl; cin.ignore(); getline(cin, id); ptr->setId(id);
	cout << "Enter The driver's first Name" << endl; getline(cin, name); ptr->set_FName(name);
	cout << "Enter The driver's last Name" << endl; getline(cin, lname); ptr->set_Lname(lname);
	cout << "Salary of driver is " << salary << endl;
	cout << "Enter  Rank  of driver out of 5 " << endl; cin >> rank;
	cout << "enter license type of driver( 0 = MOTORCAR_JEEP , 1 = MOTORBIKE_RICKSHAW , 2 = LTV , 3 = HTV ,4 = TRACTOR ,5 = PSV , 6 = INTERNATIONAL ) " << endl;
	cin >> input;
	LicenseType L = static_cast<LicenseType>(input);
	printLicenseType(L);
	if (rank >= 4.5 && rank <= 5) {
		cout << "Salary updated due to rank is : " << salary + 500 << endl;
	}
	else {
		cout << "As Rank is below 4.5 so salary remains same : " << salary << endl;
	}
	//Witing in File
	ofstream writeData("driver.txt", ios::app);
	writeData << id << " " << name << " " << lname << " " << rank << " " << input << "  " << salary << endl;
	writeData.close();
}
void driver::Delete()
{
	int input;
	string id, name, lname;
	float salary;
	string getId;
	cout << "Please Entre the ID For Delete" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	ifstream getData("driver.txt");
	ofstream writeData("demo.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> name >> lname >> rank>>input >>salary;
		while (!getData.eof())
		{
			if (id != getId)
				writeData << id << " " << name << " " << lname << " " << rank << " " << input << "  " << salary << endl;
			else
				cout << "Your Record is Deleted..." << endl << endl;

			getData >> id >> name >> lname >>rank >> input >> salary;
		}
	}
	getData.close();
	writeData.close();
	remove("driver.txt");
	rename("demo.txt", "driver.txt");
}
void driver::search()
{
	int input;
	float rank;
	string id, name, lname;
	float salary;
	string getId;
	cout << "Please Entre the ID For Search" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	cout << endl << endl;
	cout << "driver ID \t\t driver  fisrt Name \t\t driver  last name \t\t rank\t\tinput \t\t driver Salary" << endl;
	ifstream getData("driver.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> name >> lname >>rank >> input >> salary;
		while (!getData.eof())
		{
			if (id == getId)
			{
				cout << id << "\t\t\t" << name << "\t\t\t" << lname << "\t\t "  << rank << "\t\t " << input << "\t\t" << salary << endl;
			}
			getData >> id >> name >> lname >>rank>> input >> salary;
		}
	}
	getData.close();
}
void driver::update()
{
	int input;
	float rank;
	string id, name, lname;
	float salary;
	string getId;
	cout << "Please Entre the ID For Update" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	ifstream getData("driver.txt");
	ofstream writeData("demo.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> name >> lname >>rank>> input >> salary;
		while (!getData.eof())
		{
			if (id != getId)
				writeData << id << " " << name << " " << lname << " "<< rank <<" "<<input<<" "<< salary << endl;
			else
			{
				int choice = 0;
				cout << "1- Update first Name" << endl;
				cout << "2- Update last name " << endl;
				cout << "3- Update rank" << endl;
				cout << "4_Update license type" << endl;
				cout << "5- Update All" << endl << endl << endl;
				do
				{
					cout << " Enter the Choice : "; cin >> choice;
					if (choice < 1 || choice > 5)
						cout << "Invalid Input..." << endl << endl << endl;
				} while (choice < 1 || choice > 5);
				if (choice == 1)
				{
					cout << " Enter the New Name : "; cin.ignore(); getline(cin, name);
				}
				else if (choice == 2)
				{
					cout << " Enter the new last name  : "; cin.ignore(); getline(cin, lname);
				}
				else if (choice == 3)
				{
					cout << " Enter the New rank  : "; cin.ignore(); (cin, rank);
				}
				else if (choice == 4)
				{
					cout << " Enter the new license type of driver( 0 = MOTORCAR_JEEP , 1 = MOTORBIKE_RICKSHAW , 2 = LTV , 3 = HTV ,4 = TRACTOR ,5 = PSV , 6 = INTERNATIONAL ) " << endl;
					cin >> input;
					LicenseType L = static_cast<LicenseType>(input);
					printLicenseType(L);
				}
				else if (choice == 5)
				{
					TMS* ptr;
					driver obj;
					ptr = &obj;
					cout << "Enter The driver ID" << endl; cin.ignore(); getline(cin, id); ptr->setId(id);
					cout << "Enter The driver's first  Name" << endl; getline(cin, name); ptr->set_FName(name);
					cout << "Enter The driver;s last name " << endl; getline(cin, lname); ptr->set_Lname(lname);
					cout << " Enter the new license type of driver( 0 = MOTORCAR_JEEP , 1 = MOTORBIKE_RICKSHAW , 2 = LTV , 3 = HTV ,4 = TRACTOR ,5 = PSV , 6 = INTERNATIONAL ) " << endl;
					cin >> input;
					LicenseType L = static_cast<LicenseType>(input);
					printLicenseType(L);
					cout << "Enter The rank of driver" << endl; cin >> rank;
				}
				cout << endl << endl << endl;
				cout << "Record Updated..." << endl << endl << endl;
				writeData << id << " " << name << " " << lname << " " <<rank <<" " << input << "  " << salary << endl;

			}

			getData >> id >> name >> lname >>rank >> input >> salary;
		}
	}
	getData.close();
	writeData.close();
	remove("driver.txt");
	rename("demo.txt", "driver.txt");

}
void driver::view()
{
	//Reading From The File Of Trainer
	int input;
	float rank;
	string id, name, lname;
	float salary;
	ifstream getData("driver.txt");
	if (getData.is_open())
	{
		getData >> id >> name >> lname >> rank >>input >> salary;
		while (!getData.eof())
		{
			if (!getData.eof())
			{
				cout << id << "\t\t\t" << name << "\t\t\t" << lname << "\t\t\t" << rank << "\t\t\t" << input << "\t\t\t\t" << salary << endl;
			}
			getData >> id >> name >> lname >>rank >>  input >> salary;
		}
	}
	else
		cout << "File is Not Found..." << endl << endl;
	getData.close();
}
// Class Customer
customer::customer() {}
void customer::add()
{
	TMS* ptr;
	customer obj;
	ptr = &obj;
	string id, name, lname, phone, ser_name;
	cout << " Enter The customers ID" << endl; cin.ignore(); getline(cin, id); ptr->setId(id);
	cout << " Enter The customer first  Name" << endl; getline(cin, name); ptr->set_FName(name);
	cout << " Enter The customer last name " << endl; getline(cin, lname); ptr->set_Lname(lname);
	cout << " Enter The cutsomers Phone" << endl; getline(cin, phone); ptr->setPhone(phone);
	cout << " Enter The customers service name " << endl; getline(cin, ser_name);
	cout << " Enter the Payment Method" << endl; getline(cin, payMethod);
	//Writing in the File
	ofstream writeData1("customer.txt", ios::app);
	writeData1 << id << " " << name << " " << lname << " " << phone << " " << ser_name << " " << payMethod << endl;
	writeData1.close();
}
void customer::Delete()
{
	string getId, id, name, lname, phone, ser_name;
	cout << "Please Entre the ID For Delete" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	ifstream getData("customer.txt");
	ofstream writeData("demo.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> name >> lname >> phone >> ser_name >> payMethod;
		while (!getData.eof())
		{
			if (id != getId)
				writeData << id << " " << name << " " << lname << " " << phone << " " << ser_name << " " << payMethod << endl;
			else
				cout << "Your Record is Deleted..." << endl << endl;

			getData >> id >> name >> lname >> phone >> ser_name >> payMethod;
		}
	}
	getData.close();
	writeData.close();
	remove("customer.txt");
	rename("demo.txt", "customer.txt");
}
void customer::search()
{
	string getId, id, name, lname, phone, ser_name, paymethod;
	cout << "Please Entre the ID For Search" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	cout << endl << endl;
	cout << "customer  ID \t\t customer Name \t\t customer lname \t\t customer Phone \t\t Member Payment Method" << endl;
	ifstream getData("customer.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> name >> lname >> phone >> ser_name >> payMethod;
		while (!getData.eof())
		{
			if (id == getId)
			{
				cout << id << "\t\t\t" << name << "\t\t\t" << lname << "\t\t\t" << phone << "\t\t" << ser_name << "\t\t" << payMethod << endl;
			}

			getData >> id >> name >> lname >> phone >> ser_name >> payMethod;
		}
	}
	getData.close();
}
void customer::update()
{
	string getId, id, name, lname, phone, ser_name, payMethod;
	cout << "Please Entre the ID For Update" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	ifstream getData("customer.txt");
	ofstream writeData("demo.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> name >> lname >> phone >> ser_name >> payMethod;
		while (!getData.eof())
		{
			if (id != getId)
				writeData << id << " " << name << " " << lname << " " << phone << " " << ser_name << " " << payMethod << endl;
			else
			{
				int choice = 0;
				cout << "1- Update first_Name" << endl;
				cout << "2- Update last_name " << endl;
				cout << "3- Update Phone number " << endl;
				cout << "4- Update service name " << endl;
				cout << "5- Update payment method " << endl;
				cout << "6- Update All" << endl << endl << endl;
				do
				{
					cout << "Please Enter the Choice : "; cin >> choice;
					if (choice < 1 || choice > 6)
						cout << "Invalid Input..." << endl << endl << endl;
				} while (choice < 1 || choice > 6);
				if (choice == 1)
				{
					cout << "Enter the New first Name : "; cin.ignore(); getline(cin, name);
				}
				else if (choice == 2)
				{
					cout << "Enter the New last name : "; cin.ignore(); getline(cin, lname);
				}
				else if (choice == 3)
				{
					cout << "Enter the New Phone : "; cin.ignore(); getline(cin, phone);
				}
				else if (choice == 4)
				{
					cout << "Enter the New service name  : "; cin.ignore(); getline(cin, ser_name);
				}
				else if (choice == 5)
				{
					cout << "Please Enter the New Payment Method : "; cin.ignore(); getline(cin, payMethod);
				}
				else if (choice == 6)
				{
					cout << "Enter The customer's ID" << endl; cin.ignore(); getline(cin, id); TMS::setId(id);
					cout << "Enter The customer's first  Name" << endl; getline(cin, name); TMS::set_FName(name);
					cout << "Enter The customer's last  name" << endl; getline(cin, lname); TMS::set_Lname(lname);
					cout << "Enter The customer's Phone number " << endl; getline(cin, phone); TMS::setPhone(phone);
					cout << "Enter The customers's service name " << endl; getline(cin, ser_name);
					cout << "Enter the customer's Payment Method" << endl; getline(cin, payMethod);
				}
				cout << endl << endl << endl;
				cout << "Record UPdated..." << endl << endl << endl;
				writeData << id << " " << name << " " << lname << " " << phone << " " << ser_name << " " << payMethod << endl;

			}

			getData >> id >> name >> lname >> phone >> ser_name >> payMethod;
		}
	}
	getData.close();
	writeData.close();
	remove("customer.txt");
	rename("demo.txt", "customer.txt");
}
void customer::view()
{
	//Reading From The File Of Member
	string getId, id, name, lname, phone, ser_name, payMethod;
	ifstream getData1("customer.txt");
	if (getData1.is_open())
	{
		getData1 >> id >> name >> lname >> phone >> ser_name >> payMethod;

		while (!getData1.eof())
		{
			cout << id << "\t\t\t" << name << "\t\t\t" << lname << "\t\t\t" << phone << "\t\t" << ser_name << "\t\t" << payMethod << endl;
			getData1 >> id >> name >> lname >> phone >> ser_name >> payMethod;
		}
	}
	else
		cout << "File is Not Found..." << endl << endl;
	getData1.close();
}
void print_smallvehicle(smallvehicle s)
{
	switch (s) {
	case smallvehicle::bike:
		cout << "bike" << endl;
		break;
	case smallvehicle::scooter:
		cout << "scooter" << endl;
		break;
	case smallvehicle::car:
		cout << "car" << endl;
		break;
	case smallvehicle::rickshaw:
		cout << "rickshaw" << endl;
		break;
	}
}
void print_largevehicle(largevehicle l) {
	switch (l) {
	case largevehicle::Van:
		cout << "van" << endl;
		break;
	case largevehicle::Bus:
		cout << "bus" << endl;
		break;
	case largevehicle::APV:
		cout << "APV" << endl;
		break;
	case largevehicle::Campervans:
		cout << "Campervans" << endl;
		break;
	case largevehicle::Caravan:
		cout << "Caravan" << endl;
		break;
	}
}
void print_heavyvehicle(heavyvehicle h) {
	switch (h) {
	case heavyvehicle::Trucks:
		cout << "Trucks" << endl;
		break;
	case heavyvehicle::Tractor_Trailor:
		cout << "Tractor_Trailor" << endl;
		break;
	case heavyvehicle::Car_Transporter:
		cout << "Car_Transporter" << endl;
		break;
	case heavyvehicle::Tanker_Truck:
		cout << "Tanker_Truck)" << endl;
		break;
	}
}
void print_lightvehicle(lightvehicle li) {
	switch (li) {
	case lightvehicle::Shahzor:
		cout << "Shahzor" << endl;
		break;
	case lightvehicle::Mazda_Titan:
		cout << "Mazda_Titan" << endl;
		break;
	}
}
// Class  vehicle 
vehicle::vehicle() {}
void vehicle::add()
{
	Date objdate;
	string id;
	int m;
	string sub_type;
	string veh_type;
	TMS* ptr;
	vehicle obj;
	ptr = &obj;
	cout << " Enter The vehicle  ID" << endl; cin.ignore(); getline(cin, id); ptr->setId(id);
	cout << " Enter The vehicle main type (ride or transportation) " << endl; getline(cin, veh_type);
	if (veh_type == "ride") {
		cout << "enter subtype of vehicle(small or large)=" << endl;
		cin >> sub_type;
		if (sub_type == "small") {
			cout << "enter model of vehicle (0= bike , 1 = scooter , 2 = car , 3= rickshaw)" << endl;
			cin >> m;
			smallvehicle s = static_cast<smallvehicle>(m);
			print_smallvehicle(s);
		}
		else if (sub_type == "large") {
			cout << "enter model of vehicle(0 = van , 1 = bus , 2 = APV , 3 = Campervans , 4 = caravan) " << endl;
			cin >> m;
			largevehicle l = static_cast<largevehicle>(m);
			print_largevehicle(l);
		}
		else {
			cout << "invalid choice" << endl;
		}
	}
	else if (veh_type == "transportation") {
		cout << "enter subtype ( light or heavy)" << endl;
		cin >> sub_type;
		if (sub_type == "light") {
			cout << "enter model of vehicle (0 = shehzor , 1 =mazda_titan)" << endl;
			cin >> m;
			lightvehicle li = static_cast<lightvehicle>(m);
			print_lightvehicle(li);
		}
		else if (sub_type == "heavy") {
			cout << "enter model of vehicle(0=trucks , 1= tractor_trailor , 2 = car_transporter , 3 = tanker_truck) " << endl;
			cin >> m;
			heavyvehicle h = static_cast<heavyvehicle>(m);
			print_heavyvehicle(h);
		}
		else {
			cout << "invalid choice" << endl;
		}
	}

	else {
		cout << "invalid choice" << endl;
	}

	cout << "Please Entre Hiring Date" << endl;
	//Date
	do
	{
		cout << "Date : ";
		cin >> objdate.date;
		if (objdate.date < 1 || objdate.date > 30)
		{
			cout << "Invalid Input..." << endl << endl;
		}
	} while (objdate.date < 1 || objdate.date > 30);
	//Month
	do
	{
		cout << "Month : ";
		cin >> objdate.month;
		if (objdate.month < 1 || objdate.month > 12)
		{
			cout << "Invalid Input..." << endl << endl;
		}
	} while (objdate.month < 1 || objdate.month > 12);
	do
	{
		cout << "Year : ";
		cin >> objdate.year;
		if (objdate.year < 2023)
		{
			cout << "Invalid Input..." << endl << endl;
		}
	} while (objdate.year < 2023);
	//Witing in File
	ofstream writeData("vehicle.txt", ios::app);
	writeData << id << " " << veh_type << " " << sub_type << " " << objdate.date << " " << objdate.month << " " << objdate.year << endl;
	writeData.close();

}
void vehicle::Delete()
{
	string sub_type;
	Date objDate;
	string id, veh_type;
	string getId;
	cout << "Please Entre the ID For Delete" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	ifstream getData("vehicle.txt");
	ofstream writeData("demo.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> veh_type >> sub_type >> objDate.date >> objDate.month >> objDate.year;
		while (!getData.eof())
		{
			if (id != getId)
				writeData << id << " " << veh_type << " " << sub_type << objDate.date << " " << objDate.month << " " << objDate.year << endl;
			else
				cout << "Your Record is Deleted..." << endl << endl;

			getData >> id >> veh_type >> sub_type >> objDate.date >> objDate.month >> objDate.year;
		}
	}
	getData.close();
	writeData.close();
	remove("vehicle.txt");
	rename("demo.txt", "vehicle.txt");
}
void vehicle::search()
{
	string sub_type;
	Date objDate;
	string id, veh_type;
	string getId;
	cout << "Please Entre the ID For Search" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	cout << endl << endl;
	cout << "vehicle ID \t vehicle  type \t\t sub_type \t\t Hiring Date" << endl;
	ifstream getData("vehicle.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> veh_type >> sub_type >> objDate.date >> objDate.month >> objDate.year;

		while (!getData.eof())
		{
			if (id == getId)
			{
				cout << id << "\t\t\t" << veh_type << "\t\t  " << objDate.date << "\\" << objDate.month << "\\" << objDate.year << endl;
			}
			getData >> id >> veh_type >> sub_type >> objDate.date >> objDate.month >> objDate.year;
		}
	}
	getData.close();
}
void vehicle::update()
{
	string sub_type;
	string id, veh_type;
	Date objDate;
	string getId;
	cout << "Please Entre the ID For Update" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	ifstream getData("vehicle.txt");
	ofstream writeData("demo.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> id >> veh_type >> sub_type >> objDate.date >> objDate.month >> objDate.year;
		while (!getData.eof())
		{
			if (id != getId)
				writeData << id << " " << veh_type << "  " << sub_type << " " << objDate.date << " " << objDate.month << " " << objDate.year << endl;
			else
			{
				int choice = 0;
				cout << "1- Update id " << endl;
				cout << "2- Update main type" << endl;
				cout << "3- Update All" << endl << endl << endl;
				do
				{
					cout << "Please Enter the Choice : "; cin >> choice;
					if (choice < 1 || choice > 3)
						cout << "Invalid Input..." << endl << endl << endl;
				} while (choice < 1 || choice > 3);
				if (choice == 1)
				{
					cout << "Enter the New id  : "; cin.ignore(); getline(cin, id);
				}
				else if (choice == 2)
				{
					cout << "Enter the New vehicle main type  : "; cin.ignore(); getline(cin, veh_type);
				}
				else if (choice == 3)
				{
					TMS* ptr;
					vehicle obj;
					ptr = &obj;
					cout << "Enter The vehicle ID" << endl; cin.ignore(); getline(cin, id); ptr->setId(id);
					cout << "Enter The vihicle main type" << endl; getline(cin, veh_type);
					cout << "Please Entre Hiring Date" << endl;
					//Date
					do
					{
						cout << "Date : ";
						cin >> objDate.date;
						if (objDate.date < 1 || objDate.date > 30)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.date < 1 || objDate.date > 30);
					//Month
					do
					{
						cout << "Month : ";
						cin >> objDate.month;
						if (objDate.month < 1 || objDate.month > 12)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.month < 1 || objDate.month > 12);
					//Year
					do
					{
						cout << "Year : ";
						cin >> objDate.year;
						if (objDate.year < 2023)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.year < 2023);
				}
				cout << endl << endl << endl;
				cout << "Record Updated..." << endl << endl << endl;
				writeData << id << " " << veh_type << " " << sub_type << " " << objDate.date << " " << objDate.month << " " << objDate.year << endl;

			}

			getData >> id >> veh_type >> sub_type >> objDate.date >> objDate.month >> objDate.year;
		}
	}
	getData.close();
	writeData.close();
	remove("vehicle.txt");
	rename("demo.txt", "vehicle.txt");
}
void vehicle::view()
{
	string sub_type;
	Date objDate;
	string id, veh_type;
	ifstream getData("vehicle.txt");
	if (getData.is_open())
	{
		getData >> id >> veh_type >> sub_type >> objDate.date >> objDate.month >> objDate.year;
		while (!getData.eof())
		{
			cout << id << "\t\t\t" << veh_type << "\t\t  " << sub_type << "\t\t  " << objDate.date << "\\" << objDate.month << "\\" << objDate.year << endl;
			getData >> id >> veh_type >> sub_type >> objDate.date >> objDate.month >> objDate.year;
		}
	}
	else
		cout << "File is Not Found..." << endl << endl;
	getData.close();
}

// Class service

void service::add()
{
	string vehicleID;
	int distance ;
	string feul_type;
	bool air_conditionor;
	string comfort_level;
	Date objDate;
	TMS* ptr;
	service obj;
	ptr = &obj;
	cout << "Enter The vehicle  ID" << endl; cin.ignore(); getline(cin, vehicleID); ptr->setId(vehicleID);
	cout << "Enter The  distance" << endl; cin >> distance;
	cout << "Enter The feul_Type (petrol , diesel)" << endl; cin >> feul_type;
    cout << "Enter The Air-Conditionor service ( 0 for no and 1 for yes )" << endl; cin >> air_conditionor;
	cout << " Entre comfort_level (yes to no ) " << endl;  cin>> comfort_level;
	cout << "Enter the booking date:" << endl;
	//Date
	do
	{
		cout << "Date : ";
		cin >> objDate.date;
		if (objDate.date < 1 || objDate.date > 30)
		{
			cout << "Invalid Input..." << endl << endl;
		}
	} while (objDate.date < 1 || objDate.date > 30);
	//Month
	do
	{
		cout << "Month : ";
		cin >> objDate.month;
		if (objDate.month < 1 || objDate.month > 12)
		{
			cout << "Invalid Input..." << endl << endl;
		}
	} while (objDate.month < 1 || objDate.month > 12);
	//Year
	do
	{
		cout << "Year : ";
		cin >> objDate.year;
		if (objDate.year < 2023)
		{
			cout << "Invalid Input..." << endl << endl;
		}
	} while (objDate.year < 2023);
	if (feul_type == "petrol") {

		if (distance <= 50 && air_conditionor ==1 && comfort_level == "yes") {
			cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 200 * 10 * 5 * 5 << endl;
		}
		else if  (distance <= 50 && air_conditionor == 0 && comfort_level == "no") {
			cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 200 * 10  << endl;
		}
		else if (distance <= 50 && air_conditionor == 0 && comfort_level == "yes") {
			cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 200 * 10 * 5 << endl;
		}
		else if (distance <= 50 && air_conditionor == 1 && comfort_level == "no") {
			cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 200 * 10 * 5 << endl;
		}
		else {
			if (distance > 50 && air_conditionor == 1 && comfort_level == "yes") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 200 * 20 * 5 * 5 << endl;
			}
			else if (distance >50 && air_conditionor == 0 && comfort_level == "no") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 200 * 20 << endl;
			}
			else if (distance > 50 && air_conditionor == 0 && comfort_level == "yes") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 200 * 20 * 5 << endl;
			}
			else if (distance > 50 && air_conditionor == 1 && comfort_level == "no") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 200 * 20 * 5 << endl;
			}
		}
	}
	else {
		if (distance <= 50) {
			if (distance <= 50 && air_conditionor == 1 && comfort_level == "yes") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 150 * 10 * 5 * 5 << endl;
			}
			else if (distance <= 50 && air_conditionor == 0 && comfort_level == "no") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level : " << 150 * 10 << endl;
			}
			else if (distance <= 50 && air_conditionor == 0 && comfort_level == "yes") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level  is : " << 150 * 10 * 5 << endl;
			}
			else if (distance <= 50 && air_conditionor == 1 && comfort_level == "no") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 150 * 10 * 5 << endl;
			}
		}
		else {
			if (distance > 50 && air_conditionor == 1 && comfort_level == "yes") {
				cout << " Total fair depending upon the distance  , air_conditioner and comfort_level is : " << 150 * 20 * 5 * 5 << endl;
			}
			else if (distance > 50 && air_conditionor == 0 && comfort_level == "no") {
				cout << " Total fair depending upon the distance  , air_conditioner and comfort_level is : " << 150 * 20 << endl;
			}
			else if (distance > 50 && air_conditionor == 0 && comfort_level == "yes") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 150 * 20 * 5 << endl;
			}
			else if (distance > 50 && air_conditionor == 1 && comfort_level == "no") {
				cout << " Total fair depending upon the distance , air_conditioner and comfort_level is : " << 150 * 20 * 5 << endl;
			}
		}
	}
	//Witing in File
	ofstream writeData("service.txt", ios::app);
	writeData << vehicleID << " " << distance << " " << feul_type << " " << air_conditionor << " " << comfort_level<< " " << objDate.date << " " << objDate.month << " " << objDate.year << endl;
	writeData.close();

}
void service::Delete()
{
	string vehicleID;
	int distance;
	string feul_type;
	bool air_conditionor;
	string comfort_level;
	Date objDate;
	string getId;
	cout << "Please Entre the ID For Delete" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	ifstream getData("service.txt");
	ofstream writeData("demo.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> vehicleID >> distance >> feul_type >> air_conditionor >> comfort_level >> objDate.date >> objDate.month >> objDate.year;
		while (!getData.eof())
		{
			if (vehicleID != getId)
				writeData << vehicleID << " " << distance << " " << feul_type << " " << air_conditionor << " " << comfort_level << " " << objDate.date << " " << objDate.month << " " << objDate.year << endl;
			else
				cout << "Your Record is Deleted..." << endl << endl;

			getData >> vehicleID >> distance >> feul_type >> air_conditionor >> comfort_level >> objDate.date >> objDate.month >> objDate.year;
		}
	}
	getData.close();
	writeData.close();
	remove("service.txt");
	rename("demo.txt", "service.txt");
}
void service::search()
{
	string vehicleID;
	int distance;
	string feul_type;
	bool air_conditionor;
	string comfort_level;
	Date objDate;
	string getId;
	cout << "Please Entre the ID For Search" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	cout << endl << endl;
	cout << "vehicle  ID \t\t Distance  \t\t Fuel_Type \t\t Air Conditoner \t\t Comfort _ level " << endl;
	ifstream getData("service.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{
		getData >> vehicleID >> distance >> feul_type >> air_conditionor >> comfort_level >> objDate.date >> objDate.month >> objDate.year;

		while (!getData.eof())
		{
			if (vehicleID == getId)
			{
				cout << vehicleID << "\t\t\t " << distance << " \t\t\t" << feul_type << " \t\t\t" << air_conditionor << " \t\t\t" << comfort_level << "\t\t\t " << objDate.date << " / " << objDate.month << " / " << objDate.year << endl;
			}
			getData >> vehicleID >> distance >> feul_type >> air_conditionor >> comfort_level >> objDate.date >> objDate.month >> objDate.year;
		}
		
	}
	getData.close();
}
void service::update()
{
	string vehicleID;
	int distance;
	string feul_type;
	bool air_conditionor;
	string comfort_level;
	Date objDate;
	string getId;
	cout << "Please Entre the ID For Update" << endl; cin.ignore(); getline(cin, getId); cout << endl;
	ifstream getData("service.txt");
	ofstream writeData("demo.txt");
	if (!getData.is_open())
	{
		cout << "File is Not Found..." << endl << endl;
	}
	else
	{

		getData >> vehicleID >> distance >> feul_type >> air_conditionor >> comfort_level >> objDate.date >> objDate.month >> objDate.year;
		while (!getData.eof())
		{
			if (vehicleID != getId)
				writeData << vehicleID << " " << distance << " " << feul_type << " " << air_conditionor << " " << comfort_level << " " << objDate.date << " " << objDate.month << " " << objDate.year << endl;
			else
			{
				int choice = 0;
				cout << "1-Update Vehicle ID" << endl;
				cout << "2- Update distance" << endl;
				cout << "3- Update fuel_type" << endl;
				cout << "4- Update air conditionor " << endl;
				cout << "5- Update comfort_level" << endl;
				cout << "6- Update hiring Date" << endl;
				cout << "7- Update All" << endl << endl << endl;
				do
				{
					cout << "Please Enter the Choice : "; cin >> choice;
					if (choice < 1 || choice > 7)
						cout << "Invalid Input..." << endl << endl << endl;
				} while (choice < 1 || choice >7);
				if (choice == 1) {
					cout << "Enter The vehicle  ID" << endl; cin.ignore(); getline(cin, vehicleID);
				}
				if (choice == 2)
				{
					cout << "Please Enter the New distance : "; cin >> distance;
				}
				else if (choice == 3)
				{
					cout << "Please Enter the New fuel type  (petrol or diesel ) : "; cin.ignore(); getline(cin, feul_type);
				}
				else if (choice == 4)
				{
					cout << "Please Enter the New air_conditioner (0 for no and 1 for yes ) : "; cin >> air_conditionor; 
				}
				else if (choice == 5)
				{
					cout << "Please Enter the New comfort_level (yes or no )  : "; cin >> comfort_level;
				}
				else if (choice == 6)
				{
					cout << "Please Entre New hiring  Date" << endl;
					//Date
					do
					{
						cout << "Date : ";
						cin >> objDate.date;
						if (objDate.date < 1 || objDate.date > 30)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.date < 1 || objDate.date > 30);
					//Month
					do
					{
						cout << "Month : ";
						cin >> objDate.month;
						if (objDate.month < 1 || objDate.month > 12)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.month < 1 || objDate.month > 12);
					//Year
					do
					{
						cout << "Year : ";
						cin >> objDate.year;
						if (objDate.year < 2023)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.year < 2023);
				}
				else if (choice == 7)
				{
					Date objDate;
					TMS* ptr;
					service obj;
					ptr = &obj;
					cout << "Enter The new vehicle  ID" << endl; cin.ignore(); getline(cin, vehicleID); ptr->setId(vehicleID);
					cout << "Enter The  new distance" << endl; cin >> distance;
					cout << "Enter The new feul_Type (petrol , diesel)" << endl; cin >> feul_type;
					cout << "Enter The new Air-Conditionor service ( 0 for no and 1 for yes )" << endl; cin >> air_conditionor;
					cout << "Entre new  comfort_level (yes to no ) " << endl;  cin >> comfort_level;
					cout << "Enter the new booking date:" << endl;
					//Date
					do
					{
						cout << "Date : ";
						cin >> objDate.date;
						if (objDate.date < 1 || objDate.date > 30)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.date < 1 || objDate.date > 30);
					//Month
					do
					{
						cout << "Month : ";
						cin >> objDate.month;
						if (objDate.month < 1 || objDate.month > 12)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.month < 1 || objDate.month > 12);
					//Year
					do
					{
						cout << "Year : ";
						cin >> objDate.year;
						if (objDate.year < 2023)
						{
							cout << "Invalid Input..." << endl << endl;
						}
					} while (objDate.year < 2023);
				}
				cout << endl << endl << endl;
				cout << "Record UPdated..." << endl << endl << endl;

				writeData << vehicleID << " " << distance << " " << feul_type << " " << air_conditionor << " " << comfort_level << " " << objDate.date << " " << objDate.month << " " << objDate.year << endl;
			}


			getData >> vehicleID >> distance >> feul_type >> air_conditionor >> comfort_level >> objDate.date >> objDate.month >> objDate.year;
		}
	}
	getData.close();
	writeData.close();
	remove("service.txt");
	rename("demo.txt", "service.txt");
}
void service::view()
{
	string vehicleID;
	int distance;
	string feul_type;
	bool air_conditionor;
	string comfort_level;
	Date objDate;
	ifstream getData("service.txt");
	if (getData.is_open())
	{

		getData >> vehicleID >> distance >> feul_type >> air_conditionor >> comfort_level >> objDate.date >> objDate.month >> objDate.year;
		while (!getData.eof())
		{

			cout << vehicleID << "\t\t\t " << distance << " \t\t\t" << feul_type << " \t\t\t" << air_conditionor << " \t\t\t" << comfort_level << "\t\t\t " << objDate.date << " / " << objDate.month << " / " << objDate.year << endl;


			getData >> vehicleID >> distance >> feul_type >> air_conditionor >> comfort_level >> objDate.date >> objDate.month >> objDate.year;
		}
	}
	else
		cout << "File is Not Found..." << endl << endl;
	getData.close();
}
