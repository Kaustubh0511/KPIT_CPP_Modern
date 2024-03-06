#include "CA.h"
#include "Factory.cpp"
#include "CB.h"
// #include "Smart.cpp"
int main()
{
    // CA obj;
    // line();
    smart<CA> smt1 = make_smart<CA>();
    line();
    // smart<CA> smt2 = make_smart<CA>();
    line();
    // smt1 = smt2;
    line();
    smart<CA> smt3 = std::move(smt1);
    line();
    smt1->fun();
    // delete smt3;
    // Smart smt2 = make_smart<CB>(10);
    return 0;
}