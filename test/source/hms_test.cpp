#include <catch2/catch.hpp>

#include "lib.hpp"

TEST_CASE("Name is hms", "[library]")
{
  library lib;
  REQUIRE(lib.name == "hms");
}
