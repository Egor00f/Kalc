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

fraction factorial(fraction number)
{

}

template<class T>
T MathThis(std::string input)
{
    for(unsigned i = 0; i < input.length(); i++)
    {
        if (input[i] == "1" || input[i] == "2")
        {
            
        }
    }
}


#endif
