#include "optional.hpp"
#include "catch.hpp"

TEST_CASE("Noexcept", "[noexcept]") {
    tl::optional<int> o1 {4};
    tl::optional<int> o2 {42};

    SECTION ("comparison with nullopt") {
        REQUIRE(noexcept(o1 == tl::nullopt));
        REQUIRE(noexcept(tl::nullopt == o1));
        REQUIRE(noexcept(o1 != tl::nullopt));
        REQUIRE(noexcept(tl::nullopt != o1));
        REQUIRE(noexcept(o1 < tl::nullopt));
        REQUIRE(noexcept(tl::nullopt < o1));
        REQUIRE(noexcept(o1 <= tl::nullopt));
        REQUIRE(noexcept(tl::nullopt <= o1));
        REQUIRE(noexcept(o1 > tl::nullopt));
        REQUIRE(noexcept(tl::nullopt > o1));
        REQUIRE(noexcept(o1 >= tl::nullopt));
        REQUIRE(noexcept(tl::nullopt >= o1));
    }

    SECTION ("swap") {
        REQUIRE(tl::detail::is_swappable<int>::value);
        //REQUIRE(noexcept(swap(o1,o2)) == noexcept(o1.swap(o2)));
    }
}


