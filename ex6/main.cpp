#include <iostream>

using namespace std;

class Car{
    public:
    string m_brand;
    string m_model;
    int m_year;
    int m_MaxSeating;
    string m_DriveMode;
    Car(string x, string y, int z, int s, string d){
        m_brand = x;
        m_model = y;
        m_year = z;
        m_MaxSeating = s;
        m_DriveMode = d;
    }
    int get_m_MaxSeating(){
        return m_MaxSeating;
    }
};

class BMW_Car : public Car{
    
    public:
    BMW_Car(string y, int z, int s) : Car("BMW", y, z, s, "Rear-wheel") {
        cout << "Constructing BMW_Car\n";
    }
};

class AUDI_Car : public Car{
    
    public:
    AUDI_Car(string y, int z, int s) : Car("ADUI", y, z, s, "Front-wheel") {
        cout << "Constructing ADUI_Car\n";
    }
};

class BENZ_Car : public Car{
    
    public:
    BENZ_Car(string y, int z, int s) : Car("BENZ", y, z, s, "Front-wheel") {
        cout << "Constructing BENZ_Car\n";
    }
};

int main()
{
    BMW_Car car_1("X5", 2023, 6);
    cout << car_1.m_brand;
    cout <<" :Drive Mode = " << car_1.m_DriveMode <<endl;
    AUDI_Car car_2("X5", 2023, 7);
    cout << car_2.m_brand; 
    cout <<" :Drive Mode = " << car_2.m_DriveMode <<endl;
    BENZ_Car car_3("X5", 2022, 10);
    cout << car_3.m_brand;
    cout <<" :Drive Mode = " << car_3.m_DriveMode <<endl;

    return 0;
}
