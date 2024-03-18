#include "Savings.hpp"
#include "Current.hpp"
#include "Mongo.hpp"
#include "SQL.hpp"

void Start()
{
    Mongo mn;
    Savings sa;

    sa.setDB(mn);
    sa.DoJob(101, 2000);

    line();
    
    Current curr;
    curr.setDB(new SQL());
    curr.DoJob(102, 3000);
}