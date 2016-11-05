#ifndef CHECKINGACCOUNT_H_
#define CHECKINGACCOUNT_H_
#include "Account.h"
#include "Customer.h"
#include "Transaction.h"

class CheckingAccount : public Account
{
public:
    CheckingAccount(Customer *cust, int id)
    {
        customer =cust;
        account_number =id;
        balance =0;
    }
    std::string to_string() {
        std::stringstream ss; // for composing the string that describes this account
        
        // DONE fixme: Add information about the customer who owns this account.
        ss<< customer -> getName()<<std::endl;
        ss<< customer-> getCustomerNumber()<<std::endl;
        ss<<"Checking Account"<<std::endl;
        ss << "  Balance: " << balance << std::endl;
        ss << "  Account ID: " << account_number << std::endl;
       
        return ss.str();
    }
    void add_interest()
    {
            double interest = customer ->getcheckingrate();
            double amt = balance * interest;
            balance = balance + amt;
            std::string fees = get_fees();
            std::string type = "Checking";
            Transaction *tran = new Transaction(customer ->getCustomerNumber(), type, amt, fees);
            // done Create a Transaction object and assign it to the transaction vector.
            
            transactions.push_back(tran);
    }
    

    
    void deposit(double amt)
    {
            balance += amt;
            std::string fees = get_fees();
            std::string type = "Deposit";
            Transaction *tran = new Transaction(customer-> getCustomerNumber(), type, amt, fees);
            // Done Create a Transaction object and assign it to transaction vector.
            transactions.push_back(tran);
    }
    
    void withdraw(double amt)
    {
            balance -= amt;
            std::string fees = get_fees();
            std::string type ="Withdraw";
            Transaction *tran = new Transaction(customer-> getCustomerNumber(), type, amt, fees);
            
            // done Create a Transaction object and assign it to tran.
            
            transactions.push_back(tran);
        }
};



#endif