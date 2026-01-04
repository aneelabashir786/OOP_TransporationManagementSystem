#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include<cstdio>
using namespace std;
//Classes
class Login
{
private:
	string id;
	string user_password, user_name, user_email;
public:
	Login();
	~Login();
	bool check(string ad_id, string pass);
};

class Date
{
public:
	int date, month, year;
};
class TMS
{
private:
	string id, name, lname, phone;
	static int count;
public:
	TMS();
	static int getCount();
	virtual void setId(string i);
	virtual string getID();
	virtual void set_FName(string na);
	virtual string get_FName();
	virtual void set_Lname(string ln);
	virtual string get_Lname();
	virtual void setPhone(string ph);
	virtual string getPhone();
	virtual void add() = 0;
	virtual void Delete() = 0;
	virtual void search() = 0;
	virtual void update() = 0;
	virtual void view() = 0;
};
enum  LicenseType
{

	MOTORCAR_JEEP, MOTORBIKE_RICKSHAW, LTV, HTV, TRACTOR, PSV, INTERNATIONAL
};
void printLicenseType(enum LicenseType);
class driver : public TMS
{
private:
	float rank;
	string id, name, lname;
	LicenseType lt;
	float salary;
public:
	driver();
	void add();
	void Delete();
	void search();
	void update();
	void view();
};
class customer : public TMS, public driver
{
private:
	string ser_name, phone;                          // This will inharit fromm classes
	string payMethod;
	double Amount;
public:
	customer();
	void add();
	void Delete();
	void search();
	void update();
	void view();
};
// class customer : public TMS
// {
// private:
//     string ser_name, phone;
//     string payMethod;
//     double Amount;
// public:
//     customer();
//     void add();
//     void Delete();
//     void search();
//     void update();
//     void view();
// };

enum class smallvehicle { bike, scooter, car, rickshaw };
void print_smallvehicle(smallvehicle);
enum class largevehicle { Van, Bus, APV, Campervans, Caravan };
void print_largevehicle(largevehicle);
enum class heavyvehicle { Trucks, Tractor_Trailor, Car_Transporter, Tanker_Truck };
void print_heavyvehicle(heavyvehicle);
enum class lightvehicle { Shahzor, Mazda_Titan };
void print_lightvehicle(lightvehicle);
class vehicle : public TMS
{
private:
	string vehicle_type;
	smallvehicle s;
	largevehicle l;
	heavyvehicle h;
	lightvehicle ll;
public:
	vehicle();
	void add();
	void Delete();
	void search();
	void update();
	void view();
};

class service : public TMS
{
	string vehicleID;
	int distance;
	string feul_type;
	bool air_conditionor;
	string comfort_level;
	double fair;
	
public:
	void add();
	void Delete();
	void search();
	void update();
	void view();
};

