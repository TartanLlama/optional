#include "catch.hpp"
#include "optional.hpp"

// What is Clang Format up to?!
TEST_CASE("Monadic operations",
          "[monadic]"){SECTION("map"){// lhs is empty
                                      tl::optional<int> o1;
auto o1r = o1.map([](int i) { return i + 2; });
static_assert(std::is_same_v<decltype(o1r), tl::optional<int>>);
REQUIRE(!o1r);

// lhs has value
tl::optional<int> o2 = 40;
auto o2r = o2.map([](int i) { return i + 2; });
static_assert(std::is_same_v<decltype(o2r), tl::optional<int>>);
REQUIRE(o2r.value() == 42);

struct rval_call_map {
  auto operator()(int) && { return 42.0; };
};

// ensure that function object is forwarded
tl::optional<int> o3 = 42;
auto o3r = o3.map(rval_call_map{});
static_assert(std::is_same_v<decltype(o3r), tl::optional<double>>);
REQUIRE(o3r.value() == 42);

// ensure that lhs is forwarded
tl::optional<int> o4 = 40;
auto o4r = std::move(o4).map([](int &&i) { return i + 2; });
static_assert(std::is_same_v<decltype(o4r), tl::optional<int>>);
REQUIRE(o4r.value() == 42);

// ensure that lhs is const-propagated
const tl::optional<int> o5 = 40;
auto o5r = o5.map([](const int &i) { return i + 2; });
static_assert(std::is_same_v<decltype(o5r), tl::optional<int>>);
REQUIRE(o5r.value() == 42);

// test applicative functor
tl::optional<int> o6 = 40;
auto f6 = tl::optional{[](const int &i) { return i + 2; }};
auto o6r = o6.map(f6);
static_assert(std::is_same_v<decltype(o6r), tl::optional<int>>);
REQUIRE(o6r.value() == 42);

// test void return
tl::optional<int> o7 = 40;
auto f7 = tl::optional{[](const int &i) { return; }};
auto o7r = o7.map(f7);
static_assert(std::is_same_v<decltype(o7r), tl::optional<tl::monostate>>);
REQUIRE(o6r.has_value());
}

SECTION("bind") {

  // lhs is empty
  tl::optional<int> o1;
  auto o1r = o1.bind([](int i) { return tl::optional<float>{42}; });
  static_assert(std::is_same_v<decltype(o1r), tl::optional<float>>);
  REQUIRE(!o1r);

  // lhs has value
  tl::optional<int> o2 = 12;
  auto o2r = o2.bind([](int i) { return tl::optional<float>{42}; });
  static_assert(std::is_same_v<decltype(o2r), tl::optional<float>>);
  REQUIRE(o2r.value() == 42.f);

  // lhs is empty, rhs returns empty
  tl::optional<int> o3;
  auto o3r = o3.bind([](int i) { return tl::optional<float>{}; });
  static_assert(std::is_same_v<decltype(o3r), tl::optional<float>>);
  REQUIRE(!o3r);

  // rhs returns empty
  tl::optional<int> o4 = 12;
  auto o4r = o4.bind([](int i) { return tl::optional<float>{}; });
  static_assert(std::is_same_v<decltype(o4r), tl::optional<float>>);
  REQUIRE(!o4r);

  struct rval_call_bind {
    auto operator()(int) && { return tl::optional<double>(42.0); };
  };

  // ensure that function object is forwarded
  tl::optional<int> o5 = 42;
  auto o5r = o5.bind(rval_call_bind{});
  static_assert(std::is_same_v<decltype(o5r), tl::optional<double>>);
  REQUIRE(o5r.value() == 42);

  // ensure that lhs is forwarded
  tl::optional<int> o6 = 42;
  auto o6r =
      std::move(o6).bind([](int &&i) { return tl::optional<double>(i); });
  static_assert(std::is_same_v<decltype(o6r), tl::optional<double>>);
  REQUIRE(o6r.value() == 42);

  // ensure that function object is const-propagated
  const tl::optional<int> o7 = 42;
  auto o7r = o7.bind([](const int &i) { return tl::optional<double>(i); });
  static_assert(std::is_same_v<decltype(o7r), tl::optional<double>>);
  REQUIRE(o7r.value() == 42);
}
}
;
