#ifndef CEO_H
#define CEO_H

#include "Employee.h"

//CEO inherits from Employee
class CEO : public Employee{
    public:
        //constructor for CEO with yearly salary and bonus; inherits from Employee(yearlySalary)
        CEO(long yearlySalary, long bonus);

        //returns CEO bonus
        long GetBonus();

        //sets CEO bonus
        void SetBonus(long bonus);

    private:
        //CEO end of year bonus
        long bonus;

};

#endif // CEO_H
