#include "VectorCalc.hpp"

double VectorCalc::calculate()
{
    double sum = 0.0;
    for (size_t i = 0; i < numbers.max_size() ; i++)
    {
        sum = sum + numbers[i];
    }
    
    return sum;
}

double VectorCalc::addVector()
{
    return calculate();
}
