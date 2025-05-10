#pragma once
#include "Lkw.hpp"

class Lkw : public Fahrzeug {
public:
    std::string info() const override {
        return "Ich bin ein LKW";
    }
};
