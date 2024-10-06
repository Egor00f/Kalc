#ifndef __FRACTION_H__
#define __FRACTION_H__


/// @brief Класс для работы с дробями
class Fraction
{
private:
	long _nominator, _denominator;
public:
	Fraction(long nominator = 0, long denominator = 0);
	~Fraction();

	/// @brief Возвращает числитель дроби
	/// @return
	long GetNominator() const;
	/// @brief Возвращает занменатель дроби
	/// @return
	long GetDenominator() const;

	Fraction& operator + (const Fraction& a);

	Fraction &operator - (const Fraction &a);

	Fraction &operator * (const Fraction &a);

	Fraction &operator / (const Fraction &a);

	Fraction &operator ^ (const int& a)
	{
		_nominator		= pow(_nominator, a);
		_denominator	= pow(_denominator, a);
		return *this;
	}

	Fraction &operator^(const unsigned &a)
	{
		_nominator = pow(_nominator, a);
		_denominator = pow(_denominator, a);
		return *this;
	}

	Fraction &operator^(const float &a)
	{
		_nominator = pow(_nominator, a);
		_denominator = pow(_denominator, a);
		return *this;
	}

	Fraction &operator^(const double &a)
	{
		_nominator = pow(_nominator, a);
		_denominator = pow(_denominator, a);
		return *this;
	}

	bool operator == (const Fraction &a) const
	{
		return _nominator == a._nominator && _denominator == a._denominator;
	}
	bool operator !=(const Fraction &a) const
	{
		return _nominator != a._nominator || _denominator != a._denominator;
	}

	bool operator <(const Fraction &a) const
	{
		Fraction buff;

	}
	bool operator > (const Fraction &a) const
	{
		return _nominator != a._nominator || _denominator != a._denominator;
	}
};



#endif // __FRACTIONS_H__
