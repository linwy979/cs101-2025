#include <iostream>
using namespace std;
class Car {
    protected:
    string m_mode;
    public:
    string brand;
    string model;
    int year;
    int seats;
    Car(string x,string y,int z,int s){
        brand=x;
        model=y;
        year=z;
        seats=s;
    }
    string get_mode(){
        m_mode ="IDK";
        return m_mode;
    }
};

class BMW:public Car{
    public:
    BMW(string y,int z ,int s):Car("BMW",y,z,s){
        cout<<"constructing BMW\n";
        m_mode ="rear_wheel";
    }
    string get_mode(){
        return m_mode;
    }
};
class AUDI:public Car{
    public:
    AUDI(string y,int z ,int s):Car("AUDI",y,z,s){
        cout<<"constructing AUDI\n";
        m_mode ="front_wheel";
    }
    string get_mode(){
        return m_mode;
    }
};
class BENZ:public Car{
    public:
    BENZ(string y,int z ,int s):Car("BENZ",y,z,s){
        cout<<"constructing BENZ\n";
        m_mode ="front_wheel";
    }
    string get_mode(){
        return m_mode;
    }
};
int main()
{
  BMW car_1("gay",6684,100);
  cout<<car_1.brand;
  cout<<": Drive mode = "<<car_1.get_mode()<<endl;
  AUDI car_3("gay",6684,100);
  cout<<car_3.brand;
  cout<<": Drive mode = "<<car_3.get_mode()<<endl;
  BENZ car_2("gay",6684,100);
  cout<<car_2.brand;
  cout<<": Drive mode = "<<car_2.get_mode()<<endl;
 
}
