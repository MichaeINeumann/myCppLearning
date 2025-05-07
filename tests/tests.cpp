#include "catch_amalgamated.hpp"
#include "../Rechner.h"

TEST_CASE("Addition funktioniert", "[rechner]") {
    Rechner r(3.0, 4.0, '+');
    auto result = r.berechne();
    REQUIRE(result.has_value());
    REQUIRE(result.value() == Catch::Approx(7.0));
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
