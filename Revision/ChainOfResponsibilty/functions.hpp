#include "Cashier.hpp"
#include "Manager.hpp"
#include "Director.hpp"
#include "RequestLoan.hpp"

void functions()
{
    Cashier kaustubh;
    Manager Vardaan;
    Director Aman;

    kaustubh.set_successor(Vardaan);
    Vardaan.set_successor(Aman);

    RequestLoan(150000, kaustubh);
    line();
    RequestLoan(250000, kaustubh);
    line();
    RequestLoan(450000, kaustubh);
    line();
    RequestLoan(750000, kaustubh);
    line();
}