#ifndef SENIOR_H_
#define SENIOR_H_
#include "Customer.h"

class Senior : public Customer
{
private:
    double SavingsInterest = 0.014;
    double CheckingsInterest =0.019;
    int CheckCharge = 6;
    int OverDraftFee = 12;
public:
    Senior (std::string name, std::string address, int age, long int telephone);
    
    double getSavingsInterest(){
        return SavingsInterest;
    }
    
    double getCheckingsInterest(){
        return CheckingsInterest;
    }
    

};



#endif

