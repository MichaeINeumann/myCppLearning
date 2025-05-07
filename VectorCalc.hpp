#pragma once
#include <vector>
#include <list>
#include <optional>

class VectorCalc
{
private:
    std::vector<int> numbers = {};

    double calculate();

public:
    VectorCalc(const std::list<int>& inputList)
    {
        numbers.assign(inputList.begin(), inputList.end());
    }

    double addVector();
};


