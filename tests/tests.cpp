#include "catch_amalgamated.hpp"
#include "../Rechner.h"
#include "../VectorCalc.hpp"
#include <list>

TEST_CASE("Addition works", "[rechner]") {
    Rechner r(3.0, 4.0, '+');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(7.0));
}

TEST_CASE("Addition negative nummbers works", "[rechner]") {
    Rechner r(0, 0, '+');
    r.input_a = -42;
    r.input_b = 8.0;
    r.input_op = '+';
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(-34.0));
}

TEST_CASE("Subtraction works", "[rechner]") {
    Rechner r(10.0, 5.0, '-');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(5.0));
}

TEST_CASE("Multiplication works", "[rechner]") {
    Rechner r(3.0, 4.0, '*');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(12.0));
}

TEST_CASE("Multiplication with zero works", "[rechner]") {
    Rechner r(0.0, 4.0, '*');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(0.0));
}

TEST_CASE("Division works", "[rechner]") {
    Rechner r(10.0, 2.0, '/');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(5.0));
}

TEST_CASE("Potentiation works", "[rechner]") {
    Rechner r(2.0, 3.0, 'p');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(8.0));
}

TEST_CASE("Division by zero returns no result", "[rechner]") {
    Rechner r(10.0, 0.0, '/');
    auto result = r.berechne();
    REQUIRE_FALSE(result.has_value());
}

TEST_CASE("Invalid operator returns no result", "[rechner]") {
    Rechner r(10.0, 2.0, '#');
    auto result = r.berechne();
    REQUIRE_FALSE(result.has_value());
}

TEST_CASE("VectorCalc funktioniert", "[vectorcalc]") {
    std::list<int> inputList = {1, 2, 3};
    VectorCalc vc(inputList);
    double result = vc.addVector();
    REQUIRE(result == Catch::Approx(6.0));
}
