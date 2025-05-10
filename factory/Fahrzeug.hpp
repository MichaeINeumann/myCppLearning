#pragma once
#include <string>

//Basisklasse

class Fahrzeug {
public:
    virtual std::string info() const = 0;
    virtual ~Fahrzeug() = default;
};
