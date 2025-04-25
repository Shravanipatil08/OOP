// 24UAM310-Car Rental System.
#include <iostream>
#include <vector>
using namespace std;

// Base vehicle class
class Vehicle
{
    // Base class attributes
    protected:
        string vehicleID,make,model;
        int year;
        bool isRented;
        double dailyRentalRate;
    
    // Base class methods
    public:
        Vehicle(string v_id,string v_make,string v_model,int v_year,double v_rate)
        {
            vehicleID=v_id;
            make=v_make;
            model=v_model;
            year=v_year;
            isRented=false;
            dailyRentalRate=v_rate;
        }
        
        bool getRentalStatus()
        {
            return isRented;
        }

        string getVehicleID()
        {
            return vehicleID;
        }

        virtual double calculateRentalCost(int days)=0;
        virtual void displayDetails()
        {
            cout<<"\nVehicle ID:"<<vehicleID<<",\nMake:"<<make<<",\nModel:"<<model<<",\nYear:"<<year<<",\nRate:$"<<dailyRentalRate<<",\nRented:"<<(isRented ? "Yes":"No")<<",";
        }
        void rentVehicle()
        {
            isRented=true;
        }
        void returnVehicle()
        {
            isRented=false;
        }
};

// Car derived class
class Car : public Vehicle
{
    // derived class attributes
    int numberOfDoors;
    string fuelType;

    // derived class methods
    public:
        Car(string c_id,string c_make,string c_model,int c_year,double c_rate,int no_doors,string fuel)
        :Vehicle(c_id,c_make,c_model,c_year,c_rate)
        {
            numberOfDoors=no_doors;
            fuelType=fuel;
        }
        
        double calculateRentalCost(int days) 
        {
            return dailyRentalRate*days;
        }

        void displayDetails()
        {
            Vehicle::displayDetails();
            cout<<"\nDoors:"<<numberOfDoors<<",\nFuel:"<<fuelType<<endl;
        }
};

// Motorcycle derived class
class Motorcycle : public Vehicle
{
    // derived class attributes
    string engineType;
    bool hasSidecar;

    // derived class method
    public:
        Motorcycle(string m_id,string m_make,string m_model,int m_year,double m_rate,string eng_type,bool sideCar)
        :Vehicle(m_id,m_make,m_model,m_year,m_rate)
        {
            engineType=eng_type;
            hasSidecar=sideCar;
        }

        double calculateRentalCost(int days)
        {
            return dailyRentalRate*days+(hasSidecar ? 20*days:0);
        }

        void displayDetails()
        {
            Vehicle::displayDetails();
            cout<<"\nEngine:"<<engineType<<",\nSide Car:"<<(hasSidecar?"Yes":"No")<<endl;
        }
};

// Truck derived class
class Truck : public Vehicle
{
    // derived class attributes
    double cargoCapacity;
    int numberOfAxels;

    // derived class method
    public:
        Truck(string t_id,string t_make,string t_model,int t_year,double t_rate,double Capacity,int axels)
        :Vehicle(t_id,t_make,t_model,t_year,t_rate)
        {
            cargoCapacity=Capacity;
            numberOfAxels=axels;
        }

        double calculateRentalCost(int days)
        {
            return dailyRentalRate*days+(cargoCapacity*10*days);
        }

        void displayDetails()
        {
            Vehicle::displayDetails();
            cout<<"\nCargo Capacity:"<<cargoCapacity<<" cubic meters,\nAxles:"<<numberOfAxels<<endl;
        }
};

// Rental System class
class RentalSystem
{
    vector <Vehicle*> Vehicles;
    public:
        void addVehicle(Vehicle *vehicle)
        {
            Vehicles.push_back(vehicle);
        }

        void displayAvailableVehicles()
        {
            for(auto v:Vehicles)
            {
                if(v->getRentalStatus()!=true)
                {
                    v->displayDetails();
                }
            }
        }

        Vehicle *findVehicle(string target_id)
        {
            for(auto v:Vehicles)
            {
                if(v->getVehicleID()==target_id)
                {
                    return v;
                }
            }
            return nullptr;
        }

        void rentVehicle(string v_id,int days)
        {
            Vehicle* v= findVehicle(v_id);
            if(v && v->getRentalStatus()!=true)
            {
                v->rentVehicle();
                cout<<"Rental Cost:$"<<v->calculateRentalCost(days)<<endl;
            }
            else
            {
                cout<<"Vehicle with id="<<v_id<<" is not available."<<endl;
            }
        }

        void returnVehicle(string v_id)
        {
            Vehicle* v=findVehicle(v_id);
            if(v && v->getRentalStatus()==true)
            {
                v->returnVehicle();
                cout<<"Vehicle with id="<<v_id<<" is returned successfully."<<endl;
            }
            else
            {
                cout<<"Vehicle with id="<<v_id<<" is not rented or does't exist."<<endl;
            }
        }

        ~RentalSystem()
        {
            for(auto v : Vehicles) 
            {
                delete v;
            }
        }
};

// main function
int main()
{
    RentalSystem sys;
    sys.addVehicle(new Car("Car123","Toyota","Fortuner",2020,50,5,"Petrol"));
    sys.addVehicle(new Motorcycle("Bike123","Honda","CBR",2024,20,"Inline-4",false));
    sys.addVehicle(new Truck("Truck123","Ford","F-150",2018,80,5,2));

    int ch;
    string vehicle_id;
    int days;

    do 
    {
        cout<<"\n1.Display Available Vehicles.\n2.Rent a vehicle.\n3.Return a vehicle.\n4.Find Vehicle and Display its details.\n5.Exit the program."<<endl;
        cout<<"Enter Choice:";
        cin>>ch;

        switch(ch)
        {
            case 1:
                sys.displayAvailableVehicles();
                break;
            case 2:
                cout<<"Enter Vehicle ID:";
                cin>>vehicle_id;
                cout<<"Enter Number of days:";
                cin>>days;
                sys.rentVehicle(vehicle_id,days);
                break;
            case 3:
                cout<<"Enter Vehicle ID:";
                cin>>vehicle_id;
                sys.returnVehicle(vehicle_id);
                break;
            case 4:
                cout<<"Enter Vehicle ID:";
                cin>>vehicle_id;
                if(Vehicle* v=sys.findVehicle(vehicle_id))
                    v->displayDetails();
                else
                    cout<<"Vehicle not found.";
                break;
            case 5:
                cout<<"Exiting..";
                exit(0);
                break;
            default:
                cout<<"Invalid Choice."<<endl;
        }
    }while(ch!=5);
    return 0;
}
