//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 5 - LAB
//==============================================

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {

        int m_number;
        double m_balance; 
        void setEmpty();

    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;

        // ======================== Type Conversion Operators ===================================

        // Check if the account is valid 
        operator bool()const;

        // Returns the account number
        operator int()const;

        // Returns the balance value
        operator double()const;

        // ======================== Unary Member Operator ===================================

        // Checks if the account is new or not set
        bool operator ~()const;

        // ======================== Binary Member Operators ===================================

        // Overload of "=" operator to an integer
        Account& operator= (int integerValue);

        // Overload of "=" operator to another Account object
        Account& operator= (Account& anotherAccount);

        // Overload of "+=" operator to an account
        Account& operator+= (double moneyDeposit);

        // Overload of "-=" operator to an account
        Account& operator-= (double moneyWithrawl);

        // Overload of "<<" operator to move accounts
        Account& operator<< (Account& anotherAccount);

        // Overload of ">>" operator to move accounts
        Account& operator>> (Account& anotherAccount);


        // ======================== Binary Helper Operators ===================================

        // Overload of "+" operator to sum the balances of two accounts
        friend double operator+ (const Account& mainAccount, const Account& anotherAccount);

        // Overload of "+="  sum the balances of two accounts
        friend double operator+= (double& sumValue, const Account& anotherAccount);
    };
}
#endif // SDDS_ACCOUNT_H_