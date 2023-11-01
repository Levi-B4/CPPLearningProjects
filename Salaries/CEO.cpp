#include "CEO.h"
#include "Employee.h"

//constructor for CEO with yearly salary and bonus; inherits from Employee(yearlySalary)
CEO::CEO(long yearlySalary, long bonus) : Employee(yearlySalary){
    this->bonus = bonus;
}

//returns CEO bonus
long CEO::GetBonus(){
    return bonus;
}

//sets CEO bonus
void CEO::SetBonus(long bonus){
    this->bonus = bonus;
}
