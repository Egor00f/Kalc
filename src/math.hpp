#ifndef __MATH_HPP__
#define __MATH_HPP__

#include <math.h>
#include <string>
#include <vector>

#include "fraction.hpp"

unsigned factorial(unsigned number)
{
    unsigned result = 1;
    for(unsigned i = 1; i <= number; i++)
    {
        result *= number;
    }
    return result;
}


struct Number
{
    enum Type
    {
        Int = 0,
        Unsigned,
        Float,
        Double
    };
    union
    {
        int i;
        unsigned u;
        float f;
        double d;
    };
    unsigned _type;
};



template<class T>
T MathThis(std::string input)
{
    std::vector<Number> Number;

    std::string buff;

    for(unsigned i = 0; i <= input.length(); i++)
    {
        if(input[i] > 47 && input[i] < 58) //Если символ - число
        {
            buff.push_back(input[i]);
        }
    }
}



#endif
