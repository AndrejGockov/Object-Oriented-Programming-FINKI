/*
Да се имплементира класа List во којашто ќе се чуваат информации за:

броеви што се дел од листата (динамички алоцирана низа од цели броеви)
бројот на броеви што се дел од листата
За класата да се дефинираат следните методи:

конструктор (со аргументи), copy-конструктор, деструктор, оператор =
void pecati()метод што ќе ги печати информациите за листата во форматот: [број на елементи во листата]: x1 x2 .. xn sum: [сума] average: [просек]
int sum() метод што ја враќа сумата на елементите во листата
double average() метод што ќе го враќа просекот на броевите во листата
Дополнително, креирајте класата ListContainer, во која што ќе се чуваат информации за:

низа од листи (динамички алоцирана низа од објекти од класата List)
број на елементи во низата од листи (цел број)
број на обиди за додавање на листа во контејнерот (цел број првично поставен на нула)
За класата потребно е да ги дефинирате следните методи:

конструктор (default), copy-конструктор, деструктор, оператор =
void pecati() метод што ќе ги печати информациите за контејнерот во форматот: List number: [реден број на листата] List info: [испечатени информации за листата со методот List::pecati()] \n sum: [сума] average: [просек]
доколку контејнерот е празен се печати само порака The list is empty.
void addNewList(List l) метод со којшто се додава листа во контејнерот
Напомена: една листа се додава во контејнерот ако и само ако има различна сума од сите листи што се веќе додадени во контејнерот
int sum() метод што ја враќа сумата на сите елементи во сите листи
double average() метод што го враќа просекот на сите елементи во сите листи во контејнерот
For example:

Input:
2
1
1
2
0 1
0

Result:
List number: 1 List info: 1: 1 sum: 1 average: 1
Sum: 1 Average: 1
Successful attempts: 1 Failed attempts: 1
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class ListContainer;

class List{
    private:
        int *broevi;
        int broeviLength;
        
        void Copy(const List &other){
            this->broeviLength = other.broeviLength;
            this->broevi = new int[this->broeviLength];
            for(int i = 0; i < this->broeviLength; i++){
                this->broevi[i] = other.broevi[i];
            }
        }
    public:
        List(){
            this->broeviLength = 0;
            this->broevi = new int[0];
        }
        
        List(int *broevi, int broeviLength){
            this->broeviLength = broeviLength;
            this->broevi = new int[this->broeviLength];
            for(int i = 0; i < this->broeviLength; i++){
                this->broevi[i] = broevi[i];
            }
        }
        
        List(const List &other){
            Copy(other);
        }
        
        ~List(){
            delete []broevi;
        }
        
        List &operator=(const List &other){
            if(this != &other){
                delete []broevi;
                Copy(other);
            }
            return *this;
        }
        
        int Sum(){
            int total = 0;
            for(int i = 0; i < broeviLength; i++){
                total += broevi[i];
            }
            return total;
        }
        
        double average(){
            double s = this->Sum();
            double n = (double)this->broeviLength;
            return (s / broeviLength);
        }
        
        void pecati(){
            cout<< broeviLength<<": ";
            for(int i = 0; i < broeviLength; i++){
                cout<<broevi[i]<<" ";
            }
            cout<<"sum: "<<this->Sum()<<" average: "<<this->average()<<endl;
        }
        
        friend class ListContainer;
};

class ListContainer{
    private:
        int success, fail;
        List *lists;
    public:
        ListContainer(){
            this->success = 0;
            this->fail = 0;
            this->lists = nullptr;
        }
        
        ~ListContainer(){
            delete []lists;
        }
        
        ListContainer &operator=(const ListContainer &other){
            if(this != &other){
                delete []lists;
                this->lists = new List[other.success];
                for (int i = 0; i < other.success; i++) {
                    this->lists[i] = other.lists[i];
                }
                this->success = other.success;
                this->fail = other.fail;
            }
            // success++;
            return *this;
        }
        
        void addNewList(List &other){
            for(int i = 0; i < success; i++){
                if(this->lists[i].Sum() == other.Sum()){
                    fail++;
                    return;
                }
            }
            
            List *temp = new List[success + 1];
            for (int i = 0; i < success; i++){
                temp[i] = lists[i];
            }
            temp[success] = other;
            delete[] lists;
            this->lists = temp;
            this->success++;
        }
        
        int sum(){
            int totalSum = 0;
            for(int i = 0; i < success; i++){
                totalSum += this->lists[i].Sum();
            }
            return totalSum;
        }
        
        double average(){
            double avg = 0, n = 0;
            for(int i = 0; i < success; i++){
                avg += this->lists[i].Sum(); 
                n += this->lists[i].broeviLength;
            }
            return avg / n;
        }
        
        void print(){
            if(success == 0){
                cout<<"The list is empty"<<endl;
                return;
            }
            for(int i = 0; i < success; i++){
                cout<<"List number: "<<i + 1<<" List info: ";
                this->lists[i].pecati();
            }
            cout<<"Sum: "<< this->sum() <<" Average: " <<  this->average()<<endl;
            cout<<"Successful attempts: "<<success<<" Failed attempts: "<<fail<<endl;
        }
};


int main() {
	
	ListContainer lc;
	int N;	
	cin>>N;	
    
	for (int i=0;i<N;i++) {
		int n;
		int niza[100];
		
		cin>>n;
       
		for (int j=0;j<n;j++){
			cin>>niza[j];
            
		}
       
		List l=List(niza,n);
	
		lc.addNewList(l);
	}	
	
    
    int testCase;
    cin>>testCase;
    
    if (testCase==1) {
        cout<<"Test case for operator ="<<endl;
        ListContainer lc1;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1=lc;
        lc1.print();
        cout<<lc1.sum()<<" "<<lc.sum()<<endl;
        lc1.sum();
        lc1.average();
        
    }
    else {
        lc.print();
    }
}