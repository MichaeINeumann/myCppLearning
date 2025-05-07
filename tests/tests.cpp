#include "catch_amalgamated.hpp"
#include "../Rechner.h"

TEST_CASE("Addition funktioniert", "[rechner]") {
    Rechner r(3.0, 4.0, '+');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(7.0));
}

TEST_CASE("Addition negativ nummbers funktioniert", "[rechner]") {
    Rechner r(0, 0, '+');
    r.input_a = -42;
    r.input_b = 8.0;
    r.input_op = '+';
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(-34.0));
}

TEST_CASE("Subtraktion funktioniert", "[rechner]") {
    Rechner r(10.0, 5.0, '-');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(5.0));
}

TEST_CASE("Multiplikation funktioniert", "[rechner]") {
    Rechner r(3.0, 4.0, '*');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(12.0));
}

TEST_CASE("Multiplikation mit Null funktioniert", "[rechner]") {
    Rechner r(0.0, 4.0, '*');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(0.0));
}

TEST_CASE("Division funktioniert", "[rechner]") {
    Rechner r(10.0, 2.0, '/');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(5.0));
}

TEST_CASE("Division durch Null liefert kein Ergebnis", "[rechner]") {
    Rechner r(10.0, 0.0, '/');
    auto result = r.berechne();
    REQUIRE_FALSE(result.has_value());
}

TEST_CASE("Ungültiger Operator liefert kein Ergebnis", "[rechner]") {
    Rechner r(10.0, 2.0, '#');
    auto result = r.berechne();
    REQUIRE_FALSE(result.has_value());
}
