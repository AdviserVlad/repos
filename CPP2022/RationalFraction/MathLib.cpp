#include "MathLib.h"

unsigned int MathLib::greatestCommonDivisor(unsigned int a, unsigned int b) 
{
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return greatestCommonDivisor(a % b, b);
    return greatestCommonDivisor(a, b % a);
}

unsigned int MathLib::leastCommonMultiple(unsigned int a, unsigned int b) 
{
    return (a * b) / greatestCommonDivisor(a, b);
}
