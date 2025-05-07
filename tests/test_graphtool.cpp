#include "catch_amalgamated.hpp"
#include "../GraphTool.hpp"

TEST_CASE("Kürzester Pfad wird korrekt gefunden") {
    GraphTool tool;

    auto pfad = tool.findeKuerzestenPfad(0, 2);

    REQUIRE(pfad.has_value());
    REQUIRE(pfad.value().size() == 3);
    REQUIRE(pfad.value()[0] == 0);
    REQUIRE(pfad.value()[1] == 1);
    REQUIRE(pfad.value()[2] == 2);
}
