#include "functions1.hpp"

int main()
{
    Car car;
    Lorry lorry;
    Ox ox;

    DoBuisness(car);
    DoBuisness(lorry);
    DoBuisness(ox);
    line();
    // std::binding
    ExecuteBuisnessFlow(std::bind(&Car::carFun,car));                // call CAR::carFun
    ExecuteBuisnessFlow(std::bind(&Lorry::lorryFun,lorry));            // call Lorry::lorryFun
    ExecuteBuisnessFlow(std::bind(&Ox::OxFun,ox));                  // call Ox::OxFun
    ExecuteBuisnessFlow(std::bind(BookVehicle,11,"Kath")); // call BookVehicle
    ExecuteBuisnessFlow(std::bind(FeedAnimal,"Hay",25));                                       // call FeedAnimal

    return 0;
}
