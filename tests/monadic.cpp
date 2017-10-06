#include "catch.hpp"
#include "optional.hpp"

#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define STATIC_REQUIRE(e)                                                      \
  constexpr bool TOKENPASTE2(rqure, __LINE__) = e;                             \
  REQUIRE(e);

constexpr int get_int(int) { return 42; }
constexpr tl::optional<int> get_opt_int(int) { return 42; }

// What is Clang Format up to?!
TEST_CASE("Monadic operations",
          "[monadic]"){SECTION("map"){// lhs is empty
                                      tl::optional<int> o1;
auto o1r = o1.map([](int i) { return i + 2; });
STATIC_REQUIRE((std::is_same<decltype(o1r), tl::optional<int>>::value));
REQUIRE(!o1r);

// lhs has value
tl::optional<int> o2 = 40;
auto o2r = o2.map([](int i) { return i + 2; });
STATIC_REQUIRE((std::is_same<decltype(o2r), tl::optional<int>>::value));
REQUIRE(o2r.value() == 42);

struct rval_call_map {
  double operator()(int) && { return 42.0; };
};

// ensure that function object is forwarded
tl::optional<int> o3 = 42;
auto o3r = o3.map(rval_call_map{});
STATIC_REQUIRE((std::is_same<decltype(o3r), tl::optional<double>>::value));
REQUIRE(o3r.value() == 42);

// ensure that lhs is forwarded
tl::optional<int> o4 = 40;
auto o4r = std::move(o4).map([](int &&i) { return i + 2; });
STATIC_REQUIRE((std::is_same<decltype(o4r), tl::optional<int>>::value));
REQUIRE(o4r.value() == 42);

// ensure that lhs is const-propagated
const tl::optional<int> o5 = 40;
auto o5r = o5.map([](const int &i) { return i + 2; });
STATIC_REQUIRE((std::is_same<decltype(o5r), tl::optional<int>>::value));
REQUIRE(o5r.value() == 42);

// test applicative functor
tl::optional<int> o6 = 40;
auto f6 = tl::make_optional([](const int &i) { return i + 2; });
auto o6r = o6.map(f6);
STATIC_REQUIRE((std::is_same<decltype(o6r), tl::optional<int>>::value));
REQUIRE(o6r.value() == 42);

// test void return
tl::optional<int> o7 = 40;
auto f7 = tl::make_optional([](const int &i) { return; });
auto o7r = o7.map(f7);
STATIC_REQUIRE(
    (std::is_same<decltype(o7r), tl::optional<tl::monostate>>::value));
REQUIRE(o6r.has_value());

// test each overload in turn
tl::optional<int> o8 = 42;
auto o8r = o8.map([](int) { return 42; });
REQUIRE(*o8r == 42);

tl::optional<int> o9 = 42;
auto o9r = o9.map([](int) { return; });
REQUIRE(o9r);

tl::optional<int> o10 = 42;
auto o10r = o10.map(tl::make_optional([](int) { return 42; }));
REQUIRE(*o10r == 42);

tl::optional<int> o11 = 42;
auto o11r = o11.map(tl::make_optional([](int) { return; }));
REQUIRE(o11r);

tl::optional<int> o12 = 42;
auto o12r = std::move(o12).map([](int) { return 42; });
REQUIRE(*o12r == 42);

tl::optional<int> o13 = 42;
auto o13r = std::move(o13).map([](int) { return; });
REQUIRE(o13r);

tl::optional<int> o14 = 42;
auto o14r = std::move(o14).map(tl::make_optional([](int) { return 42; }));
REQUIRE(*o14r == 42);

tl::optional<int> o15 = 42;
auto o15r = std::move(o15).map(tl::make_optional([](int) { return; }));
REQUIRE(o15r);

const tl::optional<int> o16 = 42;
auto o16r = o16.map([](int) { return 42; });
REQUIRE(*o16r == 42);

const tl::optional<int> o17 = 42;
auto o17r = o17.map([](int) { return; });
REQUIRE(o17r);

const tl::optional<int> o18 = 42;
auto o18r = o18.map(tl::make_optional([](int) { return 42; }));
REQUIRE(*o18r == 42);

const tl::optional<int> o19 = 42;
auto o19r = o19.map(tl::make_optional([](int) { return; }));
REQUIRE(o19r);

const tl::optional<int> o20 = 42;
auto o20r = std::move(o20).map([](int) { return 42; });
REQUIRE(*o20r == 42);

const tl::optional<int> o21 = 42;
auto o21r = std::move(o21).map([](int) { return; });
REQUIRE(o21r);

const tl::optional<int> o22 = 42;
auto o22r = std::move(o22).map(tl::make_optional([](int) { return 42; }));
REQUIRE(*o22r == 42);

const tl::optional<int> o23 = 42;
auto o23r = std::move(o23).map(tl::make_optional([](int) { return; }));
REQUIRE(o23r);

tl::optional<int> o24 = tl::nullopt;
auto o24r = o24.map([](int) { return 42; });
REQUIRE(!o24r);

tl::optional<int> o25 = tl::nullopt;
auto o25r = o25.map([](int) { return; });
REQUIRE(!o25r);

tl::optional<int> o26 = tl::nullopt;
auto o26r = o26.map(tl::make_optional([](int) { return 42; }));
REQUIRE(!o26r);

tl::optional<int> o27 = tl::nullopt;
auto o27r = o27.map(tl::make_optional([](int) { return; }));
REQUIRE(!o27r);

tl::optional<int> o28 = tl::nullopt;
auto o28r = std::move(o28).map([](int) { return 42; });
REQUIRE(!o28r);

tl::optional<int> o29 = tl::nullopt;
auto o29r = std::move(o29).map([](int) { return; });
REQUIRE(!o29r);

tl::optional<int> o30 = tl::nullopt;
auto o30r = std::move(o30).map(tl::make_optional([](int) { return 42; }));
REQUIRE(!o30r);

tl::optional<int> o31 = tl::nullopt;
auto o31r = std::move(o31).map(tl::make_optional([](int) { return; }));
REQUIRE(!o31r);

const tl::optional<int> o32 = tl::nullopt;
auto o32r = o32.map([](int) { return 42; });
REQUIRE(!o32r);

const tl::optional<int> o33 = tl::nullopt;
auto o33r = o33.map([](int) { return; });
REQUIRE(!o33r);

const tl::optional<int> o34 = tl::nullopt;
auto o34r = o34.map(tl::make_optional([](int) { return 42; }));
REQUIRE(!o34r);

const tl::optional<int> o35 = tl::nullopt;
auto o35r = o35.map(tl::make_optional([](int) { return; }));
REQUIRE(!o35r);

const tl::optional<int> o36 = tl::nullopt;
auto o36r = std::move(o36).map([](int) { return 42; });
REQUIRE(!o36r);

const tl::optional<int> o37 = tl::nullopt;
auto o37r = std::move(o37).map([](int) { return; });
REQUIRE(!o37r);

const tl::optional<int> o38 = tl::nullopt;
auto o38r = std::move(o38).map(tl::make_optional([](int) { return 42; }));
REQUIRE(!o38r);

const tl::optional<int> o39 = tl::nullopt;
auto o39r = std::move(o39).map(tl::make_optional([](int) { return; }));
REQUIRE(!o39r);
}

SECTION("map constexpr") {
  // test each overload in turn
  constexpr tl::optional<int> o16 = 42;
  constexpr auto o16r = o16.map(get_int);
  STATIC_REQUIRE(*o16r == 42);

  constexpr tl::optional<int> o18 = 42;
  constexpr auto opt_int = tl::make_optional(get_int);
  constexpr auto o18r = o18.map(opt_int);
  STATIC_REQUIRE(*o18r == 42);

  constexpr tl::optional<int> o20 = 42;
  constexpr auto o20r = std::move(o20).map(get_int);
  STATIC_REQUIRE(*o20r == 42);

  constexpr tl::optional<int> o22 = 42;
  constexpr auto o22r = std::move(o22).map(opt_int);
  STATIC_REQUIRE(*o22r == 42);

  constexpr tl::optional<int> o32 = tl::nullopt;
  constexpr auto o32r = o32.map(get_int);
  STATIC_REQUIRE(!o32r);

  constexpr tl::optional<int> o34 = tl::nullopt;
  constexpr auto o34r = o34.map(opt_int);
  STATIC_REQUIRE(!o34r);

  constexpr tl::optional<int> o36 = tl::nullopt;
  constexpr auto o36r = std::move(o36).map(get_int);
  STATIC_REQUIRE(!o36r);

  constexpr tl::optional<int> o38 = tl::nullopt;
  constexpr auto o38r = std::move(o38).map(opt_int);
  STATIC_REQUIRE(!o38r);
}

SECTION("and_then") {

  // lhs is empty
  tl::optional<int> o1;
  auto o1r = o1.and_then([](int i) { return tl::optional<float>{42}; });
  STATIC_REQUIRE((std::is_same<decltype(o1r), tl::optional<float>>::value));
  REQUIRE(!o1r);

  // lhs has value
  tl::optional<int> o2 = 12;
  auto o2r = o2.and_then([](int i) { return tl::optional<float>{42}; });
  STATIC_REQUIRE((std::is_same<decltype(o2r), tl::optional<float>>::value));
  REQUIRE(o2r.value() == 42.f);

  // lhs is empty, rhs returns empty
  tl::optional<int> o3;
  auto o3r = o3.and_then([](int i) { return tl::optional<float>{}; });
  STATIC_REQUIRE((std::is_same<decltype(o3r), tl::optional<float>>::value));
  REQUIRE(!o3r);

  // rhs returns empty
  tl::optional<int> o4 = 12;
  auto o4r = o4.and_then([](int i) { return tl::optional<float>{}; });
  STATIC_REQUIRE((std::is_same<decltype(o4r), tl::optional<float>>::value));
  REQUIRE(!o4r);

  struct rval_call_and_then {
    tl::optional<double> operator()(int) && {
      return tl::optional<double>(42.0);
    };
  };

  // ensure that function object is forwarded
  tl::optional<int> o5 = 42;
  auto o5r = o5.and_then(rval_call_and_then{});
  STATIC_REQUIRE((std::is_same<decltype(o5r), tl::optional<double>>::value));
  REQUIRE(o5r.value() == 42);

  // ensure that lhs is forwarded
  tl::optional<int> o6 = 42;
  auto o6r =
      std::move(o6).and_then([](int &&i) { return tl::optional<double>(i); });
  STATIC_REQUIRE((std::is_same<decltype(o6r), tl::optional<double>>::value));
  REQUIRE(o6r.value() == 42);

  // ensure that function object is const-propagated
  const tl::optional<int> o7 = 42;
  auto o7r = o7.and_then([](const int &i) { return tl::optional<double>(i); });
  STATIC_REQUIRE((std::is_same<decltype(o7r), tl::optional<double>>::value));
  REQUIRE(o7r.value() == 42);

  // test each overload in turn
  tl::optional<int> o8 = 42;
  auto o8r = o8.and_then([](int i) { return tl::make_optional(42); });
  REQUIRE(*o8r == 42);

  tl::optional<int> o9 = 42;
  auto o9r =
      std::move(o9).and_then([](int i) { return tl::make_optional(42); });
  REQUIRE(*o9r == 42);

  const tl::optional<int> o10 = 42;
  auto o10r = o10.and_then([](int i) { return tl::make_optional(42); });
  REQUIRE(*o10r == 42);

  const tl::optional<int> o11 = 42;
  auto o11r =
      std::move(o11).and_then([](int i) { return tl::make_optional(42); });
  REQUIRE(*o11r == 42);

  tl::optional<int> o16 = tl::nullopt;
  auto o16r = o16.and_then([](int i) { return tl::make_optional(42); });
  REQUIRE(!o16r);

  tl::optional<int> o17 = tl::nullopt;
  auto o17r =
      std::move(o17).and_then([](int i) { return tl::make_optional(42); });
  REQUIRE(!o17r);

  const tl::optional<int> o18 = tl::nullopt;
  auto o18r = o18.and_then([](int i) { return tl::make_optional(42); });
  REQUIRE(!o18r);

  const tl::optional<int> o19 = tl::nullopt;
  auto o19r =
      std::move(o19).and_then([](int i) { return tl::make_optional(42); });
  REQUIRE(!o19r);
}

SECTION("constexpr and_then") {
  constexpr tl::optional<int> o10 = 42;
  constexpr auto o10r = o10.and_then(get_opt_int);
  REQUIRE(*o10r == 42);

  constexpr tl::optional<int> o11 = 42;
  constexpr auto o11r = std::move(o11).and_then(get_opt_int);
  REQUIRE(*o11r == 42);

  constexpr tl::optional<int> o18 = tl::nullopt;
  constexpr auto o18r = o18.and_then(get_opt_int);
  REQUIRE(!o18r);

  constexpr tl::optional<int> o19 = tl::nullopt;
  constexpr auto o19r = std::move(o19).and_then(get_opt_int);
  REQUIRE(!o19r);
}

SECTION("or else") {
    //TODO
}
}
;
