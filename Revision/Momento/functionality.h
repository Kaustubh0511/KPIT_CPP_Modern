#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include "CareTaker.h"
#include "CEmployee.h"
#include "CProduct.h"
#include <vector>

void CreatObjectPoduct(std::vector<CProduct *> &data);
void TestProduct(std::vector<CProduct *> &data, CareTaker &r);
void DeleteObj(std::vector<CProduct *> &data);

#endif // FUNCTIONALITY_H
