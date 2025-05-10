#pragma once
#include "Fahrzeug.hpp"
#include "Auto.hpp"
#include "Motorrad.hpp"
#include "Lkw.hpp"
#include <memory>
#include <string>

class FahrzeugFactory {
public:
    static std::unique_ptr<Fahrzeug> erstelle(const std::string& typ) {
        if (typ == "auto") {
            return std::make_unique<Auto>();
        } else if (typ == "motorrad") {
            return std::make_unique<Motorrad>();
        } else if (typ == "lkw") {
            return std::make_unique<Lkw>();
        } else {
            return nullptr;
        }
    }
};
