#pragma once
#include "Fahrzeug.hpp"

class Motorrad : public Fahrzeug {
public:
    std::string info() const override {
        return "Ich bin ein Motorrad";
    }
};
