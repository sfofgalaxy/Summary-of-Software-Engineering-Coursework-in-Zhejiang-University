#include <iostream>
#include "namesp.h"

namespace pers{
	int counter;   //定义性声明
 	void getPerson(Person &rp){
		counter++;
        std::cout << "Enter first name: ";
        std::cin >> rp.fname;
        std::cout << "Enter last name: ";
        std::cin >> rp.lname;
    } 
    void showPerson(const Person &rp){
		counter++;
        std::cout << rp.lname << ", " << rp.fname;
    }
}

namespace debts{
   void getDebt(Debt & rd){
        getPerson(rd.name);
        std::cout << "Enter debt: ";
        std::cin >> rd.amount;
    }
    
    void showDebt(const Debt &rd){
        showPerson(rd.name);
        std::cout << ": $" << rd.amount << std::endl;
    }
    
    double sumDebts(const Debt ar[], int n){
        double total  = 0;
        for(int i = 0; i < n; i++){
            total += ar[i].amount;
        }
        
        return total;
    }
}