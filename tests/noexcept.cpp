#include "catch.hpp"
#include "optional.hpp"

TEST_CASE("Noexcept", "[noexcept]") {
  tl::optional<int> o1{4};
  tl::optional<int> o2{42};

  SECTION("comparison with nullopt") {
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

  SECTION("swap") {
    REQUIRE(noexcept(swap(o1, o2)) == noexcept(o1.swap(o2)));

    struct nothrow_swappable {
      nothrow_swappable &swap(const nothrow_swappable &) noexcept {
        return *this;
      }
    };

    struct throw_swappable {
      throw_swappable &swap(const throw_swappable &) { return *this; }
    };

    REQUIRE(noexcept(std::declval<nothrow_swappable>().swap(
        std::declval<nothrow_swappable>())));
    REQUIRE(!noexcept(
        std::declval<throw_swappable>().swap(std::declval<throw_swappable>())));
  }

  SECTION("constructors") {
    REQUIRE(noexcept(tl::optional<int>{}));
    REQUIRE(noexcept(tl::optional<int>{tl::nullopt}));

    struct nothrow_move {
      nothrow_move() = default;
      nothrow_move(nothrow_move &&) noexcept = default;
    };

    struct throw_move {
      throw_move() = default;
      throw_move(throw_move &&) = default;
    };

    REQUIRE(noexcept(tl::optional<nothrow_move>{std::declval<nothrow_move>()}));
    REQUIRE(!noexcept(tl::optional<throw_move>{std::declval<throw_move>()}));
  }

  SECTION("assignment") {
    REQUIRE(noexcept(o1 = tl::nullopt));

    struct nothrow_move_assign {
      nothrow_move_assign() = default;
      nothrow_move_assign(nothrow_move_assign &&) noexcept = default;
      nothrow_move_assign &operator=(const nothrow_move_assign &) = default;
    };

    struct throw_move_assign {
      throw_move_assign() = default;
      throw_move_assign(throw_move_assign &&){};
      throw_move_assign &operator=(const throw_move_assign &) {}
    };

    REQUIRE(noexcept(std::declval<nothrow_move_assign>() =
                         std::declval<nothrow_move_assign>()));
    REQUIRE(!noexcept(std::declval<throw_move_assign>() =
                          std::declval<throw_move_assign>()));
  }

  SECTION("observers") {
    REQUIRE(noexcept(static_cast<bool>(o1)));
    REQUIRE(noexcept(o1.has_value()));
  }

  SECTION("modifiers") {
    REQUIRE(noexcept(o1.reset()));
  }
}
