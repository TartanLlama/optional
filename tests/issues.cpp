#include "catch.hpp"
#include "optional.hpp"
#include <type_traits>

struct foo{
    int& v() { return i; }
    int i = 0;
};

int& x(int& i) { i = 42; return i;}

TEST_CASE("issue 14") {
    tl::optional<foo> f = foo{};
    auto v = f.map(&foo::v).map(x);
    static_assert(std::is_same<decltype(v), tl::optional<int&>>::value, "Must return a reference");
    REQUIRE(f->i == 42);
    REQUIRE(*v == 42);
    REQUIRE((&f->i) == (&*v));
}
