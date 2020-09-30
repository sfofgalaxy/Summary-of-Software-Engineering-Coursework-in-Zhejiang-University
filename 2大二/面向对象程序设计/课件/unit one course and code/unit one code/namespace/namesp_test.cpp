#include <iostream>
#include "namesp.h"

int main(void)
{
    //using debts::Debt;
    //using debts::showDebt;
    debts::Debt golf = { {"Benny","Goatsniff"},120.0};
    debts::showDebt(golf);
     
    return 0;
}