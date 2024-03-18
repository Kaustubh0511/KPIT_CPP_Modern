#include<iostream>
#include<map>

class Vendor
{
    std::string m_name;
    double m_charges;
    public:
    Vendor(std::string,double);
    double get_charges() const;
    operator std::string();
    operator double();

};

class VendorRepository
{
    static std::map<std::string,Vendor*> record;
    public:
    static void Enroll(Vendor*);
    static Vendor* Access(std::string);
};



class Car
{
    int m_number{0};
    int m_seat_count{0};
    int m_per_km_charge{0};
    Vendor* m_v;
    public:
    Car(int,int,int,std::string);
    std::string vendor_name();
    double vendor_charges();

    int get_number() const { return m_number; }
    void setNumber(int number) { m_number = number; }

    int get_seatCount() const { return m_seat_count; }
    void setSeatCount(int seat_count) { m_seat_count = seat_count; }

    int get_perKmCharge() const { return m_per_km_charge; }
    void setPerKmCharge(int per_km_charge) { m_per_km_charge = per_km_charge; }
    
};

class Helper
{
    std::map<int,Car*> enrollment;
    public:
    void Subscribe(Car*);
    void Unsubscribe(int);
    void List();
    void List(std::string);
};