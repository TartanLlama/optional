#include "catch.hpp"
#include "optional.hpp"

TEST_CASE("Assignment", "[assignment]") {
    tl::optional<int> o1 = 42;
    tl::optional<int> o2 = 12;
    tl::optional<int> o3;

    o1 = o1;
    REQUIRE(*o1 == 42);

    o1 = o2;
    REQUIRE(*o1 == 12);

    o1 = o3;
    REQUIRE(!o1);

    o1 = 42;
    REQUIRE(*o1 == 42);

    o1 = tl::nullopt;
    REQUIRE(!o1);

    o1 = std::move(o2);
    REQUIRE(*o1 == 12);

    tl::optional<short> o4 = 42;

    o1 = o4;
    REQUIRE(*o1 == 42);

    o1 = std::move(o4);
    REQUIRE(*o1 == 42);
}
