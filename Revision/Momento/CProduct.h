#ifndef CPRODUCT_H
#define CPRODUCT_H

#include <iostream>
#include "BaseMomento.h"
using std::string;

class CProduct:public BaseMomento
{

public:
    CProduct() = default;
    CProduct(const CProduct &) = delete;
    CProduct(CProduct &&) = delete;
    CProduct &operator=(const CProduct &) = delete;
    CProduct &operator=(const CProduct &&) = delete;
    ~CProduct() = default;
    CProduct(int _category, string _name, double _price);

    void Display();

    int category() const { return _category; }
    void setCategory(int category) { _category = category; }

    string name() const { return _name; }
    void setName(const string &name) { _name = name; }

    double price() const { return _price; }
    void setPrice(double price) { _price = price; }

protected:
    IMomento* clone() override;
    void ReciveState(IMomento* _recieveState) override;

private:
    int _category;
    string _name;
    double _price;
};

#endif // CPRODUCT_H
