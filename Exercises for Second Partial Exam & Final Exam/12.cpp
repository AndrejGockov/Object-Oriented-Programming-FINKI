/*
Да се креира класа за опишување на еден сервис за мобилни уреди. За секој мобилен телефон се чуваат податоци за модел (низа од 100 знаци), тип на уред (смартфон или компјутер), потребни часови за основна проверка (децимален број), година на производство (цел број). (5 поени)

Сите уреди имаат исто времетраење за основна проверка и истата изнесува 1 час. Оваа вредност може да се смени со одлука на сервисот. Дополнително, уредите кои се понови од 2015 година имаат потреба од дополнителени 1.5 часа за проверка. При проверка, лаптопите имаат потреба од дополнителни 2 часа за софтверска дијагностика (5 поени).

За оваа класа да се имплементира оператор << за печатење на уред во формат:

[modelnauredotl]
[tipnaured] [casovizaproverka]

Каде часовите за проверка се оние од основната проверка+ дополнителни 2 часа доколку уредот е понов од 2015 + 2 часа доколу уредот е лаптоп (5 поени)

Да се креира класа MobileServis во која се чува адреса (низа од 100 знаци), низа од уреди (динамички алоцирана низа) и број на уреди.(5 поени)

За класата да се обезбедат:

operatoror+= за додавање на нов уред во сервисот.(5 поени) Не смее да се дозволи годината на производство на уредот да биде поголема од 2019 или помала од 2000. Ако се направи обид за додавање на уред со невалидна година, треба да се генерира исклучок InvalidProductionDate. (10 поени)

Функција pecatiUredi со која се печатат сите уреди со времето потребно за нивната проверка во сервисот (5 поени).

Да се обезбедат сите дополнителни методи потребни за правилно функционирање на програмата. (5 поени)

For example:

Input	Result
3
TelService
6
iPhone
0
2020
Samsung
0
1999
Huawei
0
1990
Toshiba
1
2016
OnePlus
0
2009
Fujitsu
1
2010
===== Testiranje na isklucoci ======
Невалидна година на производство
Невалидна година на производство
Невалидна година на производство
Ime: TelService
Toshiba
Laptop 5
OnePlus
Mobilen 1
Fujitsu
Laptop 3
*/

#include <iostream>
#include <cstring>

using namespace std;

enum tip
{
    smartphone,
    laptop
};

class InvalidProductionDate
{
public:
    static void message()
    {
        cout << "Невалидна година на производство" << endl;
    }
};

class Device
{
    char name[100];
    tip deviceType;
    static float hoursNeeded;
    int year;

public:
    Device() {}

    Device(char name[100], tip deviceType, int year)
    {
        strcpy(this->name, name);
        this->deviceType = deviceType;
        this->year = year;
    }

    Device(Device &other)
    {
        strcpy(this->name, other.name);
        this->deviceType = other.deviceType;
        this->year = other.year;
    }

    ~Device() {}

    friend ostream &operator<<(ostream &res, Device &device)
    {
        res << device.name << endl;
        if (device.deviceType == smartphone)
            res << "Mobilen ";
        else
            res << "Laptop ";
        res << device.checkUp() << endl;
        return res;
    }

    int getYear()
    {
        return year;
    }

    static void setPocetniCasovi(float newHoursNeeded)
    {
        Device::hoursNeeded = newHoursNeeded;
    }

    float checkUp()
    {
        float total = hoursNeeded;
        if (year > 2015)
            total += 2;
        if (deviceType == laptop)
            total += 2;

        return total;
    }
};

class MobileServis
{
    char adress[100];
    Device *devices;
    int deviceNum = 0;

    void CopyServis(const MobileServis &other)
    {
        strcpy(this->adress, other.adress);
        this->deviceNum = other.deviceNum;
        this->devices = new Device[this->deviceNum];
        for (int i = 0; i < this->deviceNum; i++)
            this->devices[i] = other.devices[i];
    }

public:
    MobileServis() {}

    MobileServis(char adress[100])
    {
        strcpy(this->adress, adress);
    }

    MobileServis(MobileServis &other)
    {
        CopyServis(other);
    }

    ~MobileServis()
    {
        delete[] devices;
    }

    MobileServis &operator=(MobileServis &other)
    {
        if (this == &other)
            return *this;

        CopyServis(other);
        return *this;
    }

    MobileServis &operator+=(Device &newDevice)
    {
        try
        {
            if (newDevice.getYear() > 2019 || newDevice.getYear() < 2000)
                throw InvalidProductionDate();

            Device *tmp = new Device[deviceNum + 1];

            for (int i = 0; i < deviceNum; i++)
            {
                tmp[i] = devices[i];
            }

            tmp[deviceNum++] = newDevice;
            delete[] devices;
            devices = new Device[deviceNum];
            for (int i = 0; i < deviceNum; i++)
            {
                devices[i] = tmp[i];
            }
            delete[] tmp;
            return *this;
        }
        catch (InvalidProductionDate &err)
        {
            err.message();
        }
    }

    void pecatiCasovi()
    {
        cout << "Ime: " << adress << endl;
        for (int i = 0; i < deviceNum; i++)
        {
            cout << devices[i];
        }
    }
};

float Device::hoursNeeded = 1;

int main()
{
    int testCase;
    cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
    if (testCase == 1)
    {
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> tipDevice;
        cin >> godina;
        Device ig(ime, (tip)tipDevice, godina);
        cin >> ime;
        MobileServis t(ime);
        cout << ig;
    }
    if (testCase == 2)
    {
        cout << "===== Testiranje na operatorot += ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip)tipDevice, godina);
            t += tmp;
        }
        t.pecatiCasovi();
    }
    if (testCase == 3)
    {
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip)tipDevice, godina);
            t += tmp;
        }
        t.pecatiCasovi();
    }
    if (testCase == 4)
    {
        cout << "===== Testiranje na konstruktori ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip)tipDevice, godina);
            try
            {
                t += tmp;
            }
            catch (InvalidProductionDate &err)
            {
                err.message();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }
    if (testCase == 5)
    {
        cout << "===== Testiranje na static clenovi ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip)tipDevice, godina);

            t += tmp;
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
        Device::setPocetniCasovi(2);
        t.pecatiCasovi();
    }

    if (testCase == 6)
    {
        cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip)tipDevice, godina);
            t += tmp;
        }
        Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }

    return 0;
}