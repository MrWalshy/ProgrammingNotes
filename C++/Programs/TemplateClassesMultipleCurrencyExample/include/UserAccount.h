#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H
#include "currency.h"

template<typename Currency>
class UserAccount
{
    public:
        Currency balance;

        UserAccount(Currency balance): balance(balance)
        {
            // the member initialiser list (: balance(balance)) works without a 
            // default constructor being available (compiler will auto generate it)

            // manually assigning the values results in the compiler not generating the 
            // required default constructor, so it must be explicitly specified. This 
            // is because an object is first created of some type Currency with its 
            // fields initialised to default values, then the fields are reassigned
            // to the value in the assignment statement below (balance)
            // this->balance = balance;
        }

        template<typename OtherCurrency>
        void addToBalance(OtherCurrency other)
        {
            balance.value += to<Currency, OtherCurrency>(other).value;
        }
};
#endif