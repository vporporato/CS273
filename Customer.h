#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>


/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer // done Complete the implementation!
{
private:
    std::string name;
    std::string address;
	int age;
    long int telephone;
    int customerNumber;
    
    
public:
    virtual std::string getName() {return name;}
    virtual std::string getAddress(){return address;}
    virtual int getAge(){return age;}
    virtual long int getTelephone(){return telephone;}
    virtual int getCustomerNumber(){return customerNumber;}
    virtual const int OverdraftFee()=0;
    virtual const int checkingFee()=0;
    
    virtual const double getcheckingrate()=0;
    virtual const double getsavingsrate() =0;
};


#endif