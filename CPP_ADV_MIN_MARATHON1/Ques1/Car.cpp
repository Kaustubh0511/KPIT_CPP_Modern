#include"Car.h"

std::map<std::string,Vendor*> VendorRepository::record;

void VendorRepository::Enroll(Vendor *vendor)
{
    record[*vendor]=vendor;
}

Vendor* VendorRepository::Access(std::string vendor_name)
{
    return record[vendor_name]!=nullptr?record[vendor_name]:throw "Not a registered vendor\n";
}

Vendor::Vendor(std::string name, double charges):m_name(name),m_charges(charges)
{
}

double Vendor::get_charges() const
{
    return m_charges;
}

Vendor::operator std::string()
{
    return m_name;
}

Vendor::operator double()
{
    return m_charges;
}

Car::Car(int number, int seat_count, int per_km_charge, std::string vendor_name):
        m_number(number),m_seat_count(seat_count),m_per_km_charge(per_km_charge),m_v(VendorRepository::Access(vendor_name))
{
}

std::string Car::vendor_name()
{
    return *m_v;
}

double Car::vendor_charges()
{
    return (*m_v/100)*(m_per_km_charge);
}

void Helper::Subscribe(Car *car)
{
    enrollment[car->get_number()]=car;
}

void Helper::Unsubscribe(int number)
{
    delete enrollment[number];
    enrollment.erase(number);
}

void Helper::List()
{
    for(auto rng:enrollment)
    {
        Car* temp_car=rng.second;
        std::cout<<temp_car->get_number()<<'\t'<<temp_car->get_seatCount()<<'\t'<<"Vendor charges: "<<temp_car->vendor_charges()<<'\n';
    }
}

void Helper::List(std::string vendor_name)
{
    for(auto rng:enrollment)
    {
        Car* temp_car=rng.second;
        if(temp_car)
        std::cout<<temp_car->get_number()<<'\t'<<temp_car->get_seatCount()<<'\t'<<"Vendor charges: "<<temp_car->vendor_charges()<<'\n';
    }
}