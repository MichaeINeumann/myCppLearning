#pragma once
#include "Fahrzeug.hpp"

class Auto : public Fahrzeug {
public:
    std::string info() const override {
        return "Ich bin ein Auto";
    }
};
