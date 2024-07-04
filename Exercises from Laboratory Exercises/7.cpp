/*
На влезот корисникот внесува тектуална низа која содржи информации за тоа кој корисник со која email адреса се има најавено на некоја социјална мрежа и колку пати(логови се имаат креирано) во текот на денот (притоа во тектуалната низа може да има повеќе корисници). Ваша задача е да креирате класа EmailLogs и во неа да ги дефинирате следните функции:

void parseInput(const string& line)  - парсирање на влезот и одредување на сервис провајдерот и логовите. Потоа во неа да се повика функцијата countDomainOccurrences. И на крај да се ипечати добиениот резултат.

void countDomainOccurrences(int logs, const string& domain) - пресметува колку пати се појавил некој сервис провајдер, и ги сумира логовите од тој провајдер.

At the input, the user enters a textual string containing information about which user has logged in with which email address to a social network and how many times (logs have been created) during the day (the textual string may contain multiple users). Your task is to create the class EmailLogs and define the following functions within it:

void parseInput(const string& line) - parsing the input and determining the service provider and the logs. Then, call the function countDomainOccurrences within it. Finally, print the obtained result.

void countDomainOccurrences(int logs, const string& domain) - calculates how many times a service provider has appeared and sums the logs from that provider.


For example:

Input	Result
teodora@gmail.com 4 dimitrij@hotmail.com 2 sandra@gmail.com 1
Domain gmail.com occurs 2 times with daily 5 logs
Domain hotmail.com occurs 1 times with daily 2 logs
sandra@yahoo.com 2 pece@gmail.com 7 dimitrij@hotmail.com 2 ace@gmail.com 1 teodora@yahoo.com 2
Domain yahoo.com occurs 2 times with daily 4 logs
Domain gmail.com occurs 2 times with daily 8 logs
Domain hotmail.com occurs 1 times with daily 2 logs
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class EmailLogs{
        string mailList;
    public:
        EmailLogs(){}
        
        EmailLogs(string mailList){
            this->mailList = mailList;
        }
        
        ~EmailLogs(){}
        
        int logCounter(string domain){
            int res = 0;
            for(int i = 0;i < mailList.size(); i++){
                if(mailList[i] == '@'){
                    i++;
                    string tmp = "";
                    while(mailList[i] != ' '){
                        tmp += mailList[i];
                        i++;
                    }
                    
                    if(domain == tmp){
                        string digit = "";
                        digit+=mailList[i + 1];
                        res += stoi(digit);
                    }
                }
            }
            return res;
        }
        
        void parseInput(const string mailList){
            this->mailList = mailList;
            bool gmail = false, hotmail = false, yahoo = false;
            
            for(int i = 0; i < mailList.size(); i++){
                if(mailList[i] == '@'){
                    i++;
                    string newDomain = "";
                    while(mailList[i] != ' '){
                        newDomain += mailList[i];
                        i++;
                    }
                    
                    if(newDomain == "gmail.com" && gmail == false){
                        gmail = true;
                        countDomainOccurrences(logCounter(newDomain), newDomain);
                    }else if(newDomain == "hotmail.com" && hotmail == false){
                        hotmail = true;
                        countDomainOccurrences(logCounter(newDomain), newDomain);
                    }else if(newDomain == "yahoo.com" && yahoo == false){
                        yahoo = true;
                        countDomainOccurrences(logCounter(newDomain), newDomain);
                    }
                }
            }
        }
        
        void countDomainOccurrences(int logs, const string& domain){
            int cnt = 0;
            for(int i = 0; i < mailList.size(); i++){
                if(mailList[i] == '@'){
                    i++;
                    string tmp = "";
                    while(mailList[i] != ' '){
                        tmp += mailList[i];
                        i++;
                    }
                    
                    if(tmp == domain)
                        cnt++;
                }
            }
            cout<<"Domain "<<domain << " occurs " << cnt <<" times with daily " << logs << " logs"<<endl;
        }
};

int main() {
    string input;
    getline(cin, input); 
    EmailLogs em;
    em.parseInput(input);
    return 0;
}