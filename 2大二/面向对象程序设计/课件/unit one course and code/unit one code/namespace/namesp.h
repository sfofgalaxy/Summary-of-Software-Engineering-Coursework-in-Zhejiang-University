namespace pers{
    const int LEN = 40;
	extern int counter;  //引用性声明
    struct Person{
        char fname[LEN];
        char lname[LEN];
    };
    void getPerson(Person &);
    void showPerson(const Person &);
}

namespace debts{
    struct Debt{
        pers::Person name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
}