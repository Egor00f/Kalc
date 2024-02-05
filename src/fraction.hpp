#ifndef __FRACTION_H__
#define __FRACTION_H__


/// @brief Класс для работы с дробями
class fraction
{
private:
    /* data */
    long _nominator, _denominator;
public:
    fraction(long nominator, long denominator);
    ~fraction();

    /// @brief Возвращает числитель дроби
    /// @return
    long GetNominator();
    /// @brief Возвращает занменатель дроби
    /// @return
    long GetDenominator();
};



/// @brief Переводит дробь в число
/// @param F
/// @return _Number_
double Fraction_to_Number(fraction F);

fraction float_to_fraction(double f);


/// @brief Сложение дробей
/// @param A
/// @param B
/// @return (fraction) A + B
fraction Sum_of_Fractions(fraction A, fraction B);


/// @brief Вычитание из дроби A дроби B
/// @param A
/// @param B
/// @return (fraction) A - B
fraction Diff_of_fractions(fraction A, fraction B);


/// @brief Умножение дроби на дробь
/// @param A
/// @param B
/// @return (fraction) A * B
fraction Multiply_of_fractions(fraction A, fraction B);


/// @brief Деление дроби A на дробь B
/// @param A
/// @param B
/// @return (fraction) A /
fraction Divide_of_fractions(fraction A, fraction B);


fraction pow(fraction number, int n);
fraction pow(fraction number, fraction n);



fraction::fraction(long nominator, long denominator)
{
    _nominator      = nominator;
    _denominator    = denominator;
}

fraction::~fraction()
{
}

long fraction::GetNominator()
{
    return _nominator;
}

long fraction::GetDenominator()
{
    return _denominator;
}

double Fraction_to_Number(fraction F)
{
    return F.GetNominator() / F.GetDenominator();//Просто тупо делим
}

fraction float_to_fraction(double f)
{
//    return { , 10 };
}

fraction Sum_of_Fractions(fraction A, fraction B)
{
    return { (A.GetNominator() * B.GetDenominator()) + (B.GetNominator() * A.GetDenominator()),		A.GetDenominator() * B.GetDenominator() };
}

fraction Diff_of_fractions(fraction A, fraction B)
{
    return { (A.GetNominator() * B.GetDenominator()) - (B.GetNominator() * A.GetDenominator()),     A.GetDenominator() * B.GetDenominator() };
}

fraction Multiply_of_fractions(fraction A, fraction B)
{
    return { A.GetNominator() * B.GetNominator(),		A.GetDenominator() * B.GetDenominator()};
}

fraction Divide_of_fractions(fraction A, fraction B)
{
    return { A.GetNominator() * B.GetDenominator(),		A.GetDenominator() * B.GetNominator() };
}

fraction pow(fraction number, int n)
{
	return {pow(number.GetNominator, n), pow(number.GetDenominator, n)};
}


#endif // __FRACTIONS_H__
