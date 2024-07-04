/*
Да се дефинира класа NetworkDevice која ќе претставува еден мрежен уред. Треба да ги содржи следните полиња:
brand, компанија-производител на мрежниот уред
model, модел на мрежниот уред.
За класата треба да се дефинира параметризиран конструктор и print() метод.

Да се дефинира класа NetworkInterface, која ќе ги претставува мрежните параметри на мрежниот уред. Таа треба да ги содржи следните полиња:

ipAddress, низа од 4 броеви наречени октети кои се составен дел од IP адресата.
ports, низа од 5 броеви кои ги означуваат портите кои се достапни на мрежниот интерфејс.
За класата треба да се дефинира параметризиран конструктор и print() метод. Во параметризираниот конструктор треба да се провери валидноста на IP адресата и портите, и доколку се наиде на невалиден податок да се фрли соодветен исклучок (треба да ги креирате класите InvalidIPAddressException и InvalidPortException, соодветно).

За IP адреса велиме дека е невалидна доколку било кој од октетите кои ја сочинуваат е помал од 1 или поголем од 254.

За порта велиме дека е невалидна доколку е помала од 0 или поголема од 65535.

Напомена: прво се проверува IP адресата, потоа портите. Исклучоците треба да се фатат на означеното место во main функцијата.

Define a class NetworkDevice which will represent a network device. It should contain the following fields:
brand, the company that manufactures the network device
model, the model of the network device.
The class should define a parameterized constructor and a print() method.

Define a class NetworkInterface, which will represent the network parameters of the network device. It should contain the following fields:

ipAddress, an array of 4 numbers called octets that make up the IP address.
ports, an array of 5 numbers that denote the ports available on the network interface.
The class should define a parameterized constructor and a print() method. In the parameterized constructor, the validity of the IP address and the ports should be checked, and if an invalid value is encountered, an appropriate exception should be thrown (you need to create the classes InvalidIPAddressException and InvalidPortException, respectively).

An IP address is considered invalid if any of the octets that make it up is less than 1 or greater than 254.

A port is considered invalid if it is less than 0 or greater than 65535.

Note: first check the IP address, then the ports. Exceptions should be caught at the designated place in the main function.
*/

#include <iostream>
#include <string>
using namespace std;

class InvalidIPAddressException{
    public:
        void message(){
            cout<<"IP address invalid."<<endl;
        }
};

class InvalidPortException{
    public:
        void message(int port){
            cout<<"Port number "<<port<<" is invalid."<<endl;
        }
};

class NetworkDevice{
    protected:
        string brand,model;
    public:
        NetworkDevice(){}
        NetworkDevice(string brand, string model){
            this->brand = brand;
            this->model = model;
        }
        ~NetworkDevice(){}
        void print() const{
            cout<<brand<<" "<<model<<endl;
        }
};

class NetworkInterface{
    protected:
        int ipAddress[4];
        int ports[5];
    public:
        NetworkInterface(){}
        
        NetworkInterface(int ipAddress[4], int ports[5]){
            for(int i = 0; i < 4; i++)
                this->ipAddress[i] = ipAddress[i];
            for(int i = 0; i < 5; i++)
                this->ports[i] = ports[i];
        }
        
        ~NetworkInterface(){}
        
        void print() const{
            cout<<"IP octets: ";
            for(int i = 0; i < 4; i++)
                cout<<ipAddress[i]<<" ";
            cout<<endl;
            cout<<"Allowed ports: ";
            for(int i = 0; i < 5; i++)
                cout<<ports[i]<<" ";
            cout<<endl;
        }
};

class Host : public NetworkDevice, public NetworkInterface {
    string brand, model;
    int ipAddress[4];
    int ports[5];
public:
    Host(string brand, string model, int ipAddress[4], int ports[5]) : NetworkDevice(brand, model),
    NetworkInterface(ipAddress, ports) {}

    void print() const {
        cout << "Host:" << endl;
        NetworkDevice::print();
        NetworkInterface::print();
    }
};

class Firewall : public NetworkDevice, public NetworkInterface {
public:
    Firewall(string brand, string model, int ipAddress[4], int ports[5]) : NetworkDevice(brand, model),
    NetworkInterface(ipAddress, ports) {}

    void print() const {
        cout << "Firewall:" << endl;
        NetworkDevice::print();
        NetworkInterface::print();
    }
};


int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string brand,model;
        cin>>brand>>model;
        int ipAddress[4];
        for (int j = 0; j < 4; ++j) {
            cin>>ipAddress[j];
            cin.ignore(1);
        }
        int ports[5];
        for (int j = 0; j < 5; ++j) {
            cin>>ports[j];
        }
        //TODO: Catch any potential exceptions here.
        if (i % 2 == 0) {
            bool errCaught = false;
            try{
                for(int i = 0; i < 4; i++){
                    if(ipAddress[i] < 1 || ipAddress[i] > 254){
                        errCaught = true;
                        throw InvalidIPAddressException();
                    }
                }
            }catch(InvalidIPAddressException &err){
                err.message();
            }
            
            if(!errCaught){
                int invalidPort = 0;
                try{
                    for(int i = 0; i < 5; i++){
                        if(ports[i] < 0 || ports[i] > 65535){
                            errCaught = true;
                            invalidPort = ports[i];
                            throw InvalidPortException();
                        }
                    }
                }catch(InvalidPortException &err){
                    err.message(invalidPort);
                }
            }
            
            if(!errCaught){
                Host h(brand, model, ipAddress, ports);
                h.print();
            }
        } else {
            bool errCaught = false;
            try{
                for(int i = 0; i < 4; i++){
                    if(ipAddress[i] < 1 || ipAddress[i] > 254){
                        errCaught = true;
                        throw InvalidIPAddressException();
                    }
                }
            }catch(InvalidIPAddressException &err){
                err.message();
            }
            
            if(!errCaught){
                int invalidPort = 0;
                try{
                    for(int i = 0; i < 5; i++){
                        if(ports[i] < 0 || ports[i] > 65535){
                            errCaught = true;
                            invalidPort = ports[i];
                            throw InvalidPortException();
                        }
                    }
                }catch(InvalidPortException &err){
                    err.message(invalidPort);
                }
            }
            
            if(!errCaught){
                Firewall f(brand, model, ipAddress, ports);
                f.print();
            }
        }
    }
    return 0;
}
