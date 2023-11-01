#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
    public:
        //constructor for employees with yearly salary
        Employee(long yearlySalary);

        //returns employee's yearly salary
        long GetYearlySalary();

        //sets employee's yearly salary
        void SetYearlySalary(long yearlySalary);

    private:
        //employees yearly salary
        long yearlySalary;
};



#endif // EMPLOYEE_H
