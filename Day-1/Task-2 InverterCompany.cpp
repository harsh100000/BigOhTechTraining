#include <bits/stdc++.h>
using namespace std;

// Parent class Inverter representing generic Inverter.
class Inverter
{
    public:
    int powerRating;
    string powerCapacity;
    string type;

    Inverter(int current, int voltage, string powerCapacity)
    {
        this->powerRating = current * voltage;
        this->powerCapacity = powerCapacity;
    };
};

// Child class Solar Inverter inherited from Inverter
class SolarInverter : public Inverter
{
    public:
    int solarEnergy;
    bool hasGrid;
    bool hasBattery;

    SolarInverter(int current, int voltage, string powerCapacity, bool hasGrid = false, bool hasBattery = false) : Inverter(current, voltage, powerCapacity)
    {
        this->hasGrid = hasGrid;
        this->hasBattery = hasBattery;
        this->type = "Solar Inverter";
    }
};

// Child class NonSolar Inverter inherited from Inverter
class NonSolarInverter : public Inverter
{
    public:
    bool hasBattery;
    NonSolarInverter(int current, int voltage, string powerCapacity, bool hasBattery = true) : Inverter(current, voltage, powerCapacity)
    {
        this->type = "NonSolar Inverter";
        this->hasBattery=hasBattery;
    }
};

// Child class PCU inherited from SolarInverter
class PCU : public SolarInverter
{
    public:
    PCU(int current, int voltage, string powerCapacity) : SolarInverter(current, voltage, powerCapacity, false, true)
    {
        this->type = "PCU";
    }
};

// Child class GTI inherited from SolarInverter
class GTI : public SolarInverter
{
    public:
    GTI(int current, int voltage, string powerCapacity) : SolarInverter(current, voltage, powerCapacity, true, false)
    {
        this->type = "GTI";
    }
};

// Child class Regalia inherited from SolarInverter
class Regalia : public SolarInverter
{
    public:
    Regalia(int current, int voltage, string powerCapacity) : SolarInverter(current, voltage, powerCapacity, false, false)
    {
        this->type = "Regalia";
    }
};

// Child class Zelio inherited from NonSolarInverter
class Zelio : public NonSolarInverter
{
    public:
    Zelio(int current, int voltage, string powerCapacity) : NonSolarInverter(current, voltage, powerCapacity, true)
    {
        this->type = "Zelio";
    }
};

// Child class ICruze inherited from NonSolarInverter
class ICruze : public NonSolarInverter
{
    public:
    ICruze(int current, int voltage, string powerCapacity) : NonSolarInverter(current, voltage, powerCapacity)
    {
        this->type = "ICruze";
    }
};

int main()
{
    Inverter *inverter = new Inverter(100, 140, "20000W");
    SolarInverter *solarInverter = new SolarInverter(100, 140, "20000W");
    PCU *pcu = new PCU(100, 140, "20000W");
    GTI *gti = new GTI(100, 140, "20000W");
    Regalia *regalia = new Regalia(100, 140, "20000W");
    Zelio *zelio = new Zelio(100, 140, "20000W");
    ICruze *icruze = new ICruze(100, 140, "20000W");


    cout << "Solar Inverter has battery: " << solarInverter->hasBattery << endl;
    cout << "Solar Inverter has grid: " << solarInverter->hasGrid << endl;

    cout <<pcu->type << endl;
    cout << "PCU has battery: " << pcu->hasBattery << endl;
    cout << "PCU has grid: " << pcu->hasGrid << endl;

    cout << gti->type << endl;
    cout << "GTI has battery: " << gti->hasBattery << endl;
    cout << "GTI has grid: " << gti->hasGrid << endl;

    cout << regalia->type << endl;
    cout << "Regalia has battery: " << regalia->hasBattery << endl;
    cout << "Regalia has grid: " << regalia->hasGrid << endl;

    cout << zelio->type << endl;
    cout << "zelio has battery: " << zelio->hasBattery << endl;

    cout << icruze->type << endl;
    cout << "icruze has battery: " << icruze->hasBattery << endl;

    return 0;
}