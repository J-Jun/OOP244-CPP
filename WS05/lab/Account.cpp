//==============================================
// Name:           Jason Jun
// Student Number: 126 683 200
// Email:          jjun10@myseneca.ca
// Section:        OOP244 NCC
// Workshop:       Workshop 5 - LAB
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"


using namespace std;
namespace sdds {

   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }

   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(int number, double balance ) {

      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }

   std::ostream& Account::display() const{

      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   // type conversion operators:

   Account::operator bool()const {

       // Variable:
       bool isValid = false;

       if ((m_number >= 10000 && m_number <= 99999) || m_balance > 0)
           isValid = true;

       return isValid;
   }

   Account::operator int()const {

       return m_number;
   }

   Account::operator double()const {

       return m_balance;
   }

   // Unary member operator:
   
   bool Account::operator ~()const {

       return (m_number == 0);
   }

   // Binary member operators:

   Account& Account::operator= (int integerValue) {
       
       if (m_balance < 0)
           setEmpty();
       else if (m_number == 0)
           m_number = integerValue;
       
       return *this;
   }

   Account& Account::operator= (Account& newAccount) {

       if (m_number == 0 && newAccount.m_balance >= 0) {
           
           m_number = newAccount.m_number;
           newAccount.m_number = 0;

           m_balance = newAccount.m_balance;
           newAccount.m_balance = 0.0;
       }

       return *this;
   }

   Account& Account::operator+= (double moneyDeposit) {

       if (moneyDeposit >= 0 && m_balance >= 0)
           m_balance += moneyDeposit;

       return *this;
   }
   
   Account& Account::operator-= (double moneyWithrawl) {

       if (moneyWithrawl >= 0 && m_balance >= 0 && m_balance > moneyWithrawl)
           m_balance -= moneyWithrawl;

       return *this;
   }

   Account& Account::operator<< (Account& anotherAccount) {

       if (m_number != anotherAccount.m_number) {
           m_balance += anotherAccount.m_balance;
           anotherAccount.m_balance = 0.0;
       }

       return *this;
   }

   Account& Account::operator>> (Account& anotherAccount) {

       if (m_number != anotherAccount.m_number) {
           anotherAccount.m_balance += m_balance;
           m_balance = 0.0;
       }

       return *this;
   }

   // Binary helper operators:

   double operator+ (const Account& mainAccount, const Account& anotherAccount) {

       // Variable:
       double sumValue = 0.0;

       if (mainAccount.m_balance >= 0 && anotherAccount.m_balance >= 0)
           sumValue = mainAccount.m_balance + anotherAccount.m_balance;

       return sumValue;
   }

   double operator+= (double& sumValue, const Account& anotherAccount) {

       if (anotherAccount.m_balance >= 0)
           sumValue += anotherAccount.m_balance;

       return (sumValue);
   }
}