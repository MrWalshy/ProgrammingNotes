#ifndef CURRENCY_H
#define CURRENCY_H
// templates can have the type of type parameter specified aot it looks like
template<int CurrencyConversion>
struct Currency
{
    static const int conversionRate = CurrencyConversion;
    int value;
    Currency() {}
    Currency(int value): value(value) {}
};

template<typename OtherCurrency, typename SourceCurrency>
OtherCurrency to(const SourceCurrency& source)
{
    float baseValue = source.value / float(SourceCurrency::conversionRate);
    int otherCurrencyValue = int(baseValue * OtherCurrency::conversionRate);
    return OtherCurrency(otherCurrencyValue);
}

using USD = Currency<100>;
using EUR = Currency<87>;
using GBP = Currency<78>;
#endif