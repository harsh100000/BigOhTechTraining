#include<bits/stdc++.h>
using namespace std;

// Parent class representing a general Vehicle
class Vehicle
{
public:
    string name, type;
    Vehicle(string name, string type)
    {
        this->name = name;
        this->type = type;
    }
    void getVehicleName()
    {
        cout<<"Name: "<<name<<endl;
    }
};

// Child class Aircraft inherited from Vehicle
class Aircraft : public Vehicle
{
public:
    int noOfEngines=4;
    Aircraft(string name, int noOfEngines) : Vehicle(name, "Aircraft")
    {
        this->noOfEngines = noOfEngines;
    }
};

// Child class Car inherited from Vehicle
class Car : public Vehicle
{
public:
    string  name, color, fuelType;
    Car(string name, string color, string fuelType) : Vehicle(name, "Car")
    {
        this->color = color;
        this->fuelType = fuelType;
    }
};

// Parent class representing a general Person
class Person
{
public:
    string name;
    Person(string name)
    {
        this->name = name;
    }
    void display()
    {
        cout<<name<<endl;
    }
    
    virtual ~Person(){};
};

// Child class MP inherited from Person
class MP : public Person
{
public:
    string name;
    string constituency;
    string driverName;
    int expenses;
    int expensesLimit = 100000;
    vector<Vehicle*> vehicles;

    MP(string name, string constituency, string driverName, int expenses) : Person(name)
    {
        this->constituency = constituency;
        this->driverName = driverName;
        this->expenses = expenses;
        
        Car *car = new Car("Scorpio-N", "Black", "Diesal");
        vehicles.push_back(car);
    }
    
    void display()
    {
        cout <<"Name: "<<name<<endl;
        cout <<"Constituency: "<<constituency<<endl;
        cout <<"Driver Name: "<<driverName<<endl;
        cout <<"Expenses: "<<expenses<<endl;
    }
    string getConstituency()
    {
        return constituency;
    }
    string getDriver()
    {
        return driverName;
    }
    virtual bool isExpensesLimitExceeded()
    {
        return expenses > expensesLimit;
    }
    vector<Vehicle*> getVehicles()
    {
        return vehicles;
    }
};

// Child class Minister inherited from MP
class Minister : public MP
{
public:
    Minister(string name, string constituency, string driverName, int expenses) : MP(name, constituency, driverName, expenses)
    {
        this->expensesLimit = 1000000;
    }
};

// Child class PM inherited from Minister
class PM : public Minister
{
public:
    PM(string name, string constituency, string driverName, int expenses) : Minister(name, constituency, driverName, expenses)
    {
        this->expensesLimit = 10000000;
        Aircraft *aircraft = new Aircraft("Rafael", 2);
        vehicles.push_back(aircraft);
    }
    bool arrestMinister(Minister *minister)
    {
        return false;
    }
};

// Child class Commissioner inherited from Person
class Commissioner : public Person
{
public:
    Commissioner(string name) : Person(name) {}
    bool canArrest(Person *p, PM *primeMinister = NULL)
    {
        if (PM *pm = dynamic_cast<PM*>(p))
            return false; 
        else if (Minister* minister = dynamic_cast<Minister*>(p))
        {
            if (minister->isExpensesLimitExceeded())
                return true;
            return primeMinister->arrestMinister(minister);
        }
        else if (MP* mp = dynamic_cast<MP*>(p))
        {
            return mp->isExpensesLimitExceeded();
        }
        return true;
    }
};


int main()
{
    // Creating instances of politicians and the Commissioner
    MP* mp1 = new MP("MP1", "Ghaziabad", "MP-1-Driver", 65120);
    MP* mp2 = new MP("MP2", "Delhi", "MP-2-Driver", 215000);
    Minister* m1 = new Minister("Minister1", "Ghaziabad", "Minister-1-Driver", 900000);
    Minister* m2 = new Minister("Minister2", "Delhi", "Minister-2-Driver", 1100000);
    PM* pm = new PM("PM", "Delhi", "PM-Driver", 11000000);
    Commissioner *comissioner = new Commissioner("Commissioner");

    // Display whether politician can be arrested or not
    cout << "Can MP1 be arrested: " << comissioner->canArrest(mp1, pm) << endl;
    cout << "Can MP2 be arrested: " << comissioner->canArrest(mp2, pm) << endl;
    cout << "Can Minister1 be arrested: " << comissioner->canArrest(m1, pm) << endl;
    cout << "Can Minister2 be arrested: " << comissioner->canArrest(m2, pm) << endl;
    cout << "Can PM be arrested: " << comissioner->canArrest(pm, pm) << endl;

   
    // // Freeing memory allocated for objects
    delete mp1;
    delete mp2;
    delete m1;
    delete m2;
    delete pm;
    delete comissioner;

    return 0;
}
