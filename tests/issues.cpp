#include <catch2/catch.hpp>
#include <tl/optional.hpp>
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

struct fail_on_copy_self {
    int value;
    fail_on_copy_self(int v) : value(v) {}
    fail_on_copy_self(const fail_on_copy_self& other) : value(other.value) {
        REQUIRE(&other != this);
    }
};

TEST_CASE("issue 15") {
    tl::optional<fail_on_copy_self> o = fail_on_copy_self(42);

    o = o;
    REQUIRE(o->value == 42);
}

TEST_CASE("issue 33") {
    int i = 0;
    int j = 0;
    tl::optional<int&> a = i;
    a.emplace(j);
    *a = 42;
    REQUIRE(j == 42);
    REQUIRE(*a == 42);
    REQUIRE(a.has_value());
}

namespace issue_58 {
template <class...>
using void_t = void;

template <class, class = void>
struct has_equality : std::false_type {};

template <class T, class U>
struct has_equality<std::pair<T, U>, void_t<decltype(std::declval<T>() == std::declval<U>())>> : std::true_type {};

struct NoCompare {};
struct WithCompare {
    bool operator==(const WithCompare&) const { return true; }
};
}

TEST_CASE("issue 58") {
    using namespace issue_58;
    static_assert(!has_equality<std::pair<tl::optional<NoCompare>, NoCompare>>::value, "NoCompare should not be equality comparable with optional<NoCompare>");
    static_assert(!has_equality<std::pair<NoCompare, tl::optional<NoCompare>>>::value, "optional<NoCompare> should not be equality comparable with NoCompare");
    static_assert(!has_equality<std::pair<tl::optional<NoCompare>, tl::optional<NoCompare>>>::value, "optional<NoCompare> should not be equality comparable with optional<NoCompare>");

    static_assert(has_equality<std::pair<tl::optional<WithCompare>, WithCompare>>::value, "WithCompare should be comparable");
    static_assert(has_equality<std::pair<WithCompare, tl::optional<WithCompare>>>::value, "WithCompare should be comparable");
    static_assert(has_equality<std::pair<tl::optional<WithCompare>, tl::optional<WithCompare>>>::value, "optional<WithCompare> should be comparable");
}

