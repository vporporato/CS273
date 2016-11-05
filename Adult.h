#ifndef ADULT_H_
#define ADULT_H_
#include "Customer.h"


class Adult : public Customer
{
private:
    double SavingsInterest = 0.018;
    double CheckingsInterest =0.024;
    int CheckCharge = 8;
    int OverDraftFee = 15;
public:
    Adult(std::string name, std::string address, int age, long int telephone);
    double getSavingsInterest(){
        return SavingsInterest;
    }
    
    double getCheckingsInterest(){
        return CheckingsInterest;
    }
    
};



#endif

