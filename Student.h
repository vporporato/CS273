#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include "Customer.h"

class Student : public Customer
{
public:
private:
    double SavingsInterest = 0.016;
    double CheckingsInterest =0.022;
    int CheckCharge = 7;
    int OverDraftFee = 13;
public:
    Student(std::string name, std::string address, int age, long int telephone);

    
    double getSavingsInterest(){
        return SavingsInterest;
    }
    
    double getCheckingsInterest(){
        return CheckingsInterest;
    }
    
};



#endif