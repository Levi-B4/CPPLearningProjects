#include "Employee.h"

//constructor for employees with yearly salary
Employee::Employee(long yearlySalary){
    this->yearlySalary = yearlySalary;
}

//returns employee's yearly salary
long Employee::GetYearlySalary(){
    return yearlySalary;
}

//sets employee's yearly salary
void Employee::SetYearlySalary(long  yearlySalary){
    this->yearlySalary = yearlySalary;
}
