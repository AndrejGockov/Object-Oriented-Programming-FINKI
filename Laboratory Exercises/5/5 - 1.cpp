/*
 Да се дефинира класа Account која претставува банкарска сметка на еден корисник. За класата Account се чуваат:
Име на корисникот (текстуална низа од 30 знаци)

Идентификациски број (цел број)

Тип на корисник (енумерациски тип, физичко или правно лице) 

салдо (децимален број)

Идентификацискиот број е единствен за секој корисник, неговата почетна вредност е 111110.  Да се обезбеди секвенцијално генерирање на овој број, така што првата сметка ќе има идентификациски број 111111, втората 111112, третата 111113 итн. (5 поени)

За оваа класа да се обезбедат потребните конструктори, set и get методи. (5 поени)

Да се имплементира оператор за печатење << со кој ќе се печатат информациите за секој објект во формат: [идентификациски број]-[име] [тип на корисник] [салдо] (5 поени).

Да се имплементира оператор -= кој како аргумент ќе прима реален број, што ќе ја означува провизијата која треба да се плати кон банката, односно да се одземе од салдото на сметката. (5 поени)

Потоа, да се дефинира класа Bank во која се чуваат информации за:
Име на банка (текстуална низа од 20 знаци)

Листа од сметки (динамички алоцирана низа објекти од класата Account)

Број на сметки (број на елементи во низата од сметки, иницијално е 0)


За оваа класа да се дефинираат потребните конструктори, деструктор, set и get методи.  (5 поени).

Оператор за печатење << во формат [име] и сите сметки поединечно. (види формат во тест примерите). (5 поени)

Oператор += за додавање нова сметка во банката. Во банката сметките се менаџираат според нивниот идентификациски број кој е уникатен. Во банката не смее да се дозволи додавање нова сметка со идентификациски број кој веќе постои во банката (10 поени).

Оператор < кој споредува две банки според бројот на сметки во банката. (5 поени)

Да се дефинира метод void bankFee() - со кој банката наплатува месечна банкарска провизија за сите сметки на почеток на тековниот месец. Банкарската провизија се пресметува во зависност од тоа за каков тип на корисник се работи. За физички лица банкарската провизија изнесува 0.8% од парите кои се на сметката, а за правни лица банкарската провизија е 1.5% од парите кои се на сметката. (10 поени)

Да се дефинира глобален метод leastLiquid() - кој прима низа од објекти од класатa Bank и бројот на банки, а ја враќа онаа банка која има најмал број на сметки. Доколку повеќе банки имаат ист број на сметки, се враќа онаа која е прва најдена. (5 поени)

-------------------------------------------------------------------------------------------------------



Define the class Account, representing a bank account for a user. The class Account holds:

User name (a textual string of 30 characters)
Identification number (integer)
User type (enumerated type, either individual or company entity)
Balance (decimal number)
The identification number is unique for each user, with its initial value being 111110. Implement sequential generation of this number, so the first account will have the identification number 111111, the second 111112, the third 111113, and so on. (5 points)

For this class, provide the necessary constructors, set and get methods.(5 points)

Implement the << operator to print the information for each object in the format:  [identification number]-[name] [type] [balance] (5 points).

Implement the -= operator which takes a real number as an argument, representing the commission to be paid to the bank, i.e., subtracting it from the account balance. (5 points).

Then, define the class Bank which stores information about:

Bank name (a textual array of 20 characters)
List of accounts (dynamically allocated array of Account objects)
Number of accounts (number of elements in the array of accounts, initially 0)
For this class, define the necessary constructors, destructor, set and get methods. (5 points).

Implement the << operator in the format [name] and all individual accounts.(see test cases)(5 points).

Implement the += operator to add a new account to the bank. Accounts in the bank are managed according to their unique identification number. Adding a new account with an identification number that already exists in the bank is not allowed.(10 points).

Implement the < operator to compare two banks based on the number of accounts in the bank. (5 points).

Define a method void bankFee() to collect monthly banking fees for all accounts at the beginning of the current month. The banking fee is calculated depending on the type of user. For individual users, it is 0.8% of the money on the account, while for company entities, it is 1.5% of the money on the account (10 points).

Define a global method leastLiquid() - which takes an array of Bank objects and the number of banks and returns the bank with the fewest number of accounts. If multiple banks have the same number of accounts, the first one found is returned. (5 points).



For example:

Input	Result
1
TESTING ACCOUNT OPERATOR <<
111111 - Paul person 32000
111112 - Globex company 500000
111113 - Anna person 8700
TEST PASSED
4
TESTING BANK OPERATOR += and <<
Capital One Bank
111111 - Paul person 32000
111112 - Globex Industries company 500000
111113 - Anna person 8700
TEST PASSED
*/

#include <iostream>
#include <cstring>
using namespace std;

enum Type{person, company};
class Account
{
private:
    char name[30];
    int id;
    static int TOTAL;
    const static int ID_init;
    Type type;
    float money;
public:
    Account()
    {

    }
    Account(const char *name,int type, float money)
    {
        strcpy(this->name,name);
        TOTAL++;
        id=ID_init+TOTAL;
        this->type=(Type)type;
        this->money=money;
    }
    friend ostream &operator<<(ostream &out,Account &a)
    {
        out<<a.id<<" - "<<a.name<<" ";
        if(a.type==person)
            out<<"person ";
        else
            out<<"company ";
        out<<a.money<<endl;
        return out;
    }
    Account& operator-=(float amount)
    {
        money-=amount;
        return *this;
    }
    bool isSame(const Account &a)
    {
        return id==a.id;
    }
    Type getType()
    {
        return type;
    }
    float getMoney()
    {
        return money;
    }
};

int Account::TOTAL=0;
const int Account::ID_init=111110;

class Bank
{
private:
    char name[20];
    Account *accounts;
    int numOfAccounts;
public:
    Bank(const char *name="")
    {
        strcpy(this->name,name);
        accounts= nullptr;
        numOfAccounts=0;
    }
    Bank(const Bank &b)
    {
        strcpy(this->name,b.name);
        numOfAccounts=b.numOfAccounts;
        accounts=new Account[numOfAccounts];
        for(int i=0;i<numOfAccounts;i++)
        {
            accounts[i]=b.accounts[i];
        }
    }
    Bank& operator=(const Bank &b)
    {
        if (this != &b)
        {
            delete[] accounts;
            strcpy(this->name, b.name);
            numOfAccounts = b.numOfAccounts;
            accounts = new Account[numOfAccounts];
            for (int i = 0; i < numOfAccounts; i++)
            {
                accounts[i] = b.accounts[i];
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out,const Bank &b)
    {
        out<<b.name<<endl;
        for(int i=0;i<b.numOfAccounts;i++)
        {
            out<<b.accounts[i];
        }
        return out;
    }
    bool operator<(const Bank &b)
    {
        return numOfAccounts<b.numOfAccounts;
    }
    Bank &operator+=(const Account &a)
    {
        for(int i=0;i<numOfAccounts;i++)
        {
            if(accounts[i].isSame(a))
            {
                return *this;
            }
        }
        Account *tmp=new Account[numOfAccounts+1];
        for(int i=0;i<numOfAccounts;i++)
        {
            tmp[i]=accounts[i];
        }
        tmp[numOfAccounts++]=a;
        delete [] accounts;
        accounts=tmp;
        return *this;
    }
    void bankFee()
    {
        for(int i=0;i<numOfAccounts;i++)
        {
            if(accounts[i].getType() == person)
            {
                float fee=accounts[i].getMoney()*0.008;
                accounts[i]-=fee;
            }
            else
            {   float fee=accounts[i].getMoney()*0.015;
                accounts[i]-=fee;
            }
        }
    }
    ~Bank(){
        delete [] accounts;
    }
};
Bank leastLiquid(Bank *banks, int n)
{
    Bank b=banks[0];
    for(int i=1;i<n;i++)
    {
        if(banks[i]<b)
        {
            b=banks[i];
        }
    }
    return b;
}
int main() {
    int testCase;
    cin>>testCase;
    if(testCase==0)
    {
        cout<<"TESTING ACCOUNT CONSTRUCTOR"<<endl;
        Account account1("Paul",0,32000);
        Account account2("Globex",1,500000);
        Account account3("Anna",0,8700);
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==1)
    {
        cout<<"TESTING ACCOUNT OPERATOR <<"<<endl;
        Account account1("Paul",0,32000);
        Account account2("Globex",1,500000);
        Account account3("Anna",0,8700);
        cout<<account1;
        cout<<account2;
        cout<<account3;
        cout<<"TEST PASSED"<<endl;
    } else if(testCase==2)
    {
        cout<<"TESTING ACCOUNT OPERATOR -="<<endl;
        Account account1("Paul",0,32000);
        Account account2("Globex Industries",1,500000);
        Account account3("Anna",0,8700);
        cout<<account1;
        cout<<account2;
        cout<<account3;
        account1-=350;
        account2-=20000;
        account3-=500;
        cout<<"===== DECREASE ====="<<endl;
        cout<<account1;
        cout<<account2;
        cout<<account3;
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==3)
    {
        cout<<"TESTING BANK CONSTRUCTOR and <<"<<endl;
        Bank bank1("Capital One Bank");
        cout<<bank1;
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==4)
    {
        cout<<"TESTING BANK OPERATOR += and <<"<<endl;
        Account account1("Paul",0,32000);
        Account account2("Globex Industries",1,500000);
        Account account3("Anna",0,8700);
        Bank bank1("Capital One Bank");
        bank1+=account1;
        bank1+=account2;
        bank1+=account3;
        cout<<bank1;
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==5)
    {
        cout<<"TESTING BANK OPERATOR += and <<"<<endl;
        Account account1("Paul",0,32000);
        Account account2("Globex Industries",1,500000);
        Account account3("Anna",0,8700);
        Bank bank1("Capital One Bank");
        bank1+=account1;
        bank1+=account2;
        bank1+=account3;
        bank1+=account1;
        cout<<bank1;
        cout<<"TEST PASSED"<<endl;
    }
    else if(testCase==6)
    {
        cout<<"TESTING BANK COPY-CONSTRUCTOR and OPERATOR ="<<endl;
        Account account1("Paul",0,32000);
        Account account2("Globex Industries",1,500000);
        Account account3("Anna",0,8700);
        Account account4("Umbrella Corporation",1,300000);
        Account account5("Theo",0,15500);
        Bank bank1("Capital One Bank");
        bank1+=account1;
        bank1+=account2;
        bank1+=account3;
        Bank bank2(bank1);
        Bank bank4;
        {
            Bank bank3("First National Bank");
            bank3+=account4;
            bank3+=account5;
            bank4=bank3;
        }
        cout<<bank2;
        cout<<bank4;
        cout<<"TEST PASSED"<<endl;
    }else if(testCase==7)
    {
        cout<<"TESTING BANK OPERATOR < "<<endl;
        Account account1("Paul",0,32000);
        Account account2("Globex Industries",1,500000);
        Account account3("Anna",0,8700);
        Account account4("Umbrella Corporation",1,300000);
        Account account5("Theo",0,15500);
        Bank bank1("Capital One Bank");
        bank1+=account1;
        bank1+=account2;
        bank1+=account3;
        Bank bank3("First National Bank");
        bank3+=account4;
        bank3+=account5;
        if(bank1<bank3)
        {
            cout<<"TEST FAILED"<<endl;
        }
        else
        {
            cout<<"TEST PASSED"<<endl;
        }
    }else if(testCase==8)
    {
        cout<<"TESTING METHOD bankFee()"<<endl;
        char name[30],name1[30];
        int type, numberOfBanks, numberOfAccounts;
        float money;
        cin>>numberOfBanks;
        cin.ignore();
        Bank banks[10];
        for(int i=0;i<numberOfBanks;i++)
        {
            cin.getline(name,20);
            banks[i]=Bank(name);
            cin>>numberOfAccounts;
            cin.ignore();
            Account accounts[10];
            for(int j=0;j<numberOfAccounts;j++)
            {
                cin >> name1 >> type >> money;
                cin.ignore();
                accounts[j]=Account(name1,type,money);
                banks[i]+=accounts[j];
            }
        }
        for(int i=0;i<numberOfBanks;i++)
        {
            cout<<banks[i];
            cout<<"FEE-PAID"<<endl;
            banks[i].bankFee();
            cout<<banks[i];
        }
    }else if(testCase==9)
    {
        cout<<"TESTING METHOD leastLiquid()"<<endl;
        char name[30],name1[30];
        int type, numberOfBanks, numberOfAccounts;
        float money;
        cin>>numberOfBanks;
        cin.ignore();
        Bank banks[10];
        for(int i=0;i<numberOfBanks;i++)
        {
            cin.getline(name,20);
            banks[i]=Bank(name);
            cin>>numberOfAccounts;
            cin.ignore();
            Account accounts[10];
            for(int j=0;j<numberOfAccounts;j++)
            {
                cin >> name1 >> type >> money;
                cin.ignore();
                accounts[j]=Account(name1,type,money);
                banks[i]+=accounts[j];
            }
        }
        cout<<leastLiquid(banks,numberOfBanks);
    }
    return 0;
}