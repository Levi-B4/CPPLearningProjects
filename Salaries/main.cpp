#include <iostream>

#include "Employee.h"
#include "CEO.h"

using namespace std;

int main()
{
    //CEO Income Info
    long CEO1Salary = 1'000'000;
    long CEO1Bonus = 20'000;

    //Employee Income Info
    long Employee1Salary = 20'000;


    //create CEO
    CEO* CEO1 = new CEO(CEO1Salary, CEO1Bonus);

    //print CEO info
    cout << "CEO 1 Salary: " << CEO1->GetYearlySalary() << endl;
    cout << "CEO 1 Bonus: " << CEO1->GetBonus() << endl << endl;


    //create employee
    Employee* employee1 = new Employee(Employee1Salary);

    //print employee info
    cout << "Employee 1 Salary: " << employee1->GetYearlySalary() << endl;


    return 0;
}
