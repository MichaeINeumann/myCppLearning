#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <optional>


class Rechner {
    private:
        double a, b;
        char op;
        enum error { NONE, DIVISION_BY_ZERO, INVALID_OPERATOR };
        error err = NONE;

        double calculate(const double& a, const double& b, const char& op, enum error& err);
    
    public:
        double input_a, input_b;
        char input_op;
        Rechner(double a_, double b_, char op_) : a(a_), b(b_), op(op_) {
            input_a = a_;
            input_b = b_;
            input_op = op_;
        }
        double readNumber(const std::string& prompt);
        char readOperator();
        std::optional<double> berechne();
    };

