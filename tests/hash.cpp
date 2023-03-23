#include <catch2/catch.hpp>
#include <tl/optional.hpp>

template <typename T, typename = tl::detail::void_t<>>
struct is_hashable : std::false_type {};

template <typename T>
struct is_hashable<T, tl::detail::void_t<decltype(std::declval<std::hash<T>>()(
                          std::declval<T>()))>> : std::true_type {};

template <typename T> constexpr bool is_hashable_v = is_hashable<T>::value;

struct not_hashable {};

TEST_CASE("Hashing", "[hash]") {
  SECTION("with value") {
    tl::optional<int> op1(1);

    static_assert(is_hashable_v<tl::optional<int>>,
                  "tl::optional<int> should be hashable");
    static_assert(!is_hashable_v<tl::optional<not_hashable>>,
                  "tl::optional<not_hashable> should not be hashable");

    REQUIRE(std::hash<int>{}(1) == std::hash<tl::optional<int>>{}(op1));
  }
  SECTION("nullopt") {
    tl::optional<int> op1(tl::nullopt);
    REQUIRE(std::hash<tl::optional<int>>{}(op1) == 0);
  }
}
