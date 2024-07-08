/*
Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".

Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
- Идентификациски број (int)
- Платена сума (int)
- Провизија (int)
- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)

Ограничување: 0 < N < 100

Write a program which from standard input receives the integer N (Number of transactions), followed by information about N transactions, and outputs the identification number and total sum (with commission) of all the transactions paid with a credit card. In edge cases where there are no transactions which have been paid with a credit card, output "No credit card transaction".

________________________________________________________________

The structure Transaction must have the following information:

- Identification number (int)

- Paid amount (int)

- Commission (int)

- Was the transaction paid with a debit or credit card (0 - debit, 1 - credit)



Input limit: 0 < N < 100



Input format:

N

id1 sum1 commission1 type1

...

idn sumn Commissionn typen

Структура на влезните податоци:
N
id1 sum1 commission1 type1
...
idn sumn Commissionn typen

For example:

Input	Result
3
1 100 10 0
2 202 20 1
3 10 1 1
2 222
3 11
*/

#include <iostream>
using namespace std;

struct Transakcii{
    int ID, paidAmmount, provizija;
    int nacin;
};

void printTransactions(int n){
    bool transactionFound = false;
    Transakcii trans[n];
    for(int i = 0; i < n; i++){
        cin >> trans[i].ID >> trans[i].paidAmmount >> trans[i].provizija >> trans[i].nacin;
        
        if(trans[i].nacin == 1){
            cout<<trans[i].ID<<" "<< trans[i].paidAmmount + trans[i].provizija<<endl;
            transactionFound = true;
        }
    }
    
    // If no transaction is found
    if(!transactionFound)
        cout<<"No credit card transaction";
}

int main(){
    int n;
    
    cin >> n;
    printTransactions(n);
    
    return 0;
}