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

TEST_CASE("issue 66") {
    int i = 42;
    int j = 43;
    tl::optional<std::reference_wrapper<int>> a = std::ref(i);
    REQUIRE(&a.value().get() == &i);
    a = std::ref(j);
    REQUIRE(&a.value().get() == &j);

    tl::optional<int&> b = std::ref(i);
    REQUIRE(&b.value() == &i);
    b = std::ref(j);
    REQUIRE(&b.value() == &j);
}
