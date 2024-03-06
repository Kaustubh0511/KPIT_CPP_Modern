
#include "CProduct.h"

IMomento *CProduct::clone()
{
    return new CProduct(_category, _name, _price);
}

CProduct::CProduct(int _category, string _name, double _price) : _category(_category), _name(_name), _price(_price)
{
}


void CProduct::ReciveState(IMomento *recivedState)
{
    CProduct *cp = dynamic_cast<CProduct *>(recivedState);
    if (nullptr != cp)
    {
        this->_category = cp->_category;
        this->_name = cp->_name;
        this->_price = cp->_price;
    }
    delete(recivedState);
}
void CProduct::Display()
{
    std::cout << _category << "____________" << _name << "__________" << _price << "\n";
}