//============================================================================
// Name        : Michael Jordan
// Author      : michjord0001
// Version     :
// Copyright   : Your copyright notice
// Description : Object Oriented Program Example: (Smart) Home Appliances
//============================================================================

#include <iostream>
using namespace std;

//Household Appliance
class HomeAppliance
{
protected:
	bool power;
	//virtual int electricityUsed()=0;
};

//Washing Appliances, inheriting homeAppliance
class Washing : protected HomeAppliance
{
public:
	int delay;
	float wp; //Water Pressure
	virtual int electricityUsed()=0;
	void wash()
	{
		pumpWater();
		drainWater();
	};

private:
	void pumpWater(){};
	void drainWater(){};
};

//Dish Washer ,inheriting washing class (which inherits homeAppliance)
class Dishwasher : Washing
{
public:
	int level;
	virtual int electricityUsed();
private:
	void spinBlades(){};
	void dry(){};
};

int  Dishwasher::electricityUsed(){
	int eu=30;
	cout << "Electricity usage for Dishwasher Machine is: " << eu << endl;
	return eu;
}

//Washing Machine, inheriting washing class (which inherits homeAppliance)
class WashingMachine : Washing
{
public:
	int temperature;
	virtual int electricityUsed();
	friend void addDelay(WashingMachine&, int);
	//Constructor
	WashingMachine()
	{
		power = true;
		delay = 0;
		temperature = 0;
		wp = 0;
		cout << "Washing machine constructed. " << endl ;
	};
	//Overloading constructor with delay and temperature inputs
	WashingMachine(int inDelay, int inTemperature, float inWp)
		{
			power = true;
			delay = inDelay;
			temperature = inTemperature;
			wp = inWp;
			cout << "Washing machine constructed with delay and temperature set. " << endl ;
		};
	//Destructor
	virtual ~WashingMachine()
	{
		cout << "Washing machine destructed. " << endl;
	}
	void wash()
	{
		cout << "Wash started. ";
		prewash();
		detergent();
		softener();
		spin();
		cout << "Wash ended. " << endl;
	};
	void addDelay(WashingMachine &wm, int inDelay)
	{
		wm.delay = wm.delay + inDelay;
		cout << "Added delay: " << inDelay << endl;
	};

private:
	void prewash(){ cout << "Prewash. ";};
	void detergent(){ cout << "Detergent. ";};
	void softener(){ cout << "Softener. ";};
	void spin(){ cout << "Spin. ";};
};

int  WashingMachine::electricityUsed(){
	int eu=50;
	cout << "Electricity usage for Washing Machine is: " << eu << endl;
	return eu;
}


int main()
{
	int delay = 0;
	WashingMachine *jeans; //Calls constructor
	jeans = new WashingMachine(delay, 40, 150); //Overloads constructor with arguments.
	jeans->wash();
	jeans->electricityUsed();
	delete jeans; //Calls destructor

	/*WashingMachine *cotton; //Calls constructor
	cotton = new WashingMachine(delay, 50, 110); //Overloads constructor with arguments.*/
	WashingMachine cotton;
	//addDelay(cotton, 10);
	/*delete cotton; //Calls destructor*/

	return 0;
}
