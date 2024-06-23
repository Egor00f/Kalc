#include "fraction.hpp"

Fraction::Fraction(long nominator, long denominator)
{
    _nominator = nominator;
    _denominator = denominator;
}

Fraction &Fraction::operator+(const Fraction &a)
{
    long buff;

    _nominator *= a._denominator;
    buff = a._nominator;
    buff *= _denominator;

    _nominator += buff;

    _denominator *= a._denominator;

    return *this;
}

Fraction &Fraction::operator-(const Fraction &a)
{
    long buff;

    _nominator *= a._denominator;
    buff = a._nominator;
    buff *= _denominator;

    _nominator -= buff;

    _denominator *= a._denominator;

    return *this;
}

Fraction &Fraction::operator*(const Fraction &a)
{
    _nominator *= a._nominator;
    _denominator *= a._denominator;

    return *this;
}

Fraction &Fraction::operator/(const Fraction &a)
{
    _nominator *= a._denominator;
    _denominator *= a._nominator;

    return *this;
}
