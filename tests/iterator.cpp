#include <catch2/catch.hpp>
#include <tl/optional.hpp>

TEST_CASE("iterator reference", "[iterator.ref]") {
  int val = 3;

  tl::optional<int &> o = val;
  REQUIRE(o.begin() != o.end());
  REQUIRE(*o.begin() == 3);

  o = tl::nullopt;
  REQUIRE(o.begin() == o.end());
}

TEST_CASE("iterator value constexpr", "[iterator.value.constexpr]") {
  constexpr tl::optional<int> empty;
  STATIC_REQUIRE(empty.begin() == empty.end());

  constexpr tl::optional<int> value = 3;
  STATIC_REQUIRE(value.begin() != value.end());
  STATIC_REQUIRE(*value.begin() == 3);
}
