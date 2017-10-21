#include "catch.hpp"
#include "optional.hpp"

TEST_CASE("Constructors", "[constructors]") {
    tl::optional<int> o1;
    REQUIRE(!o1);

    tl::optional<int> o2 = tl::nullopt;
    REQUIRE(!o2);

    tl::optional<int> o3 = 42;
    REQUIRE(*o3 == 42);

    tl::optional<int> o4 = o3;
    REQUIRE(*o4 == 42);

    tl::optional<int> o5 = o1;
    REQUIRE(!o5);

    tl::optional<int> o6 = std::move(o3);
    REQUIRE(*o6 == 42);

    tl::optional<short> o7 = 42;
    REQUIRE(*o7 == 42);

    tl::optional<int> o8 = o7;
    REQUIRE(*o8 == 42);

    tl::optional<int> o9 = std::move(o7);
    REQUIRE(*o9 == 42);
}
