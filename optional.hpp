///
// optional - An implementation of std::optional with extensions
// Written in 2017 by Simon Brand (@TartanLlama)
//
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#include <exception>
#include <functional>
#include <new>
#include <type_traits>
#include <utility>

#if __cplusplus == 201103L
#define TL_OPTIONAL_11_CONSTEXPR
#else
#define TL_OPTIONAL_11_CONSTEXPR constexpr
#endif

namespace tl {
template <class T> class optional;
class monostate {};
namespace detail {
template <class T> using remove_cv_t = typename std::remove_cv<T>::type;
template <class T> using remove_const_t = typename std::remove_const<T>::type;
template <class T>
using remove_volatile_t = typename std::remove_volatile<T>::type;
template <class T> using add_cv_t = typename std::add_cv<T>::type;
template <class T> using add_const_t = typename std::add_const<T>::type;
template <class T> using add_volatile_t = typename std::add_volatile<T>::type;
template <class T>
using remove_reference_t = typename std::remove_reference<T>::type;
template <class T>
using add_lvalue_reference_t = typename std::add_lvalue_reference<T>::type;
template <class T>
using add_rvalue_reference_t = typename std::add_rvalue_reference<T>::type;
template <class T>
using remove_pointer_t = typename std::remove_pointer<T>::type;
template <class T> using add_pointer_t = typename std::add_pointer<T>::type;
template <class T> using make_signed_t = typename std::make_signed<T>::type;
template <class T> using make_unsigned_t = typename std::make_unsigned<T>::type;
template <class T> using remove_extent_t = typename std::remove_extent<T>::type;
template <class T>
using remove_all_extents_t = typename std::remove_all_extents<T>::type;
template <std::size_t N, std::size_t A = N>
using aligned_storage_t = typename std::aligned_storage<N, A>::type;
template <std::size_t N, class... Ts>
using aligned_union_t = typename std::aligned_union<N, Ts...>::type;
template <class T> using decay_t = typename std::decay<T>::type;
template <bool E, class T = void>
using enable_if_t = typename std::enable_if<E, T>::type;
template <bool B, class T, class F>
using conditional_t = typename std::conditional<B, T, F>::type;
template <class... Ts>
using common_type_t = typename std::common_type<Ts...>::type;
template <class T>
using underlying_type_t = typename std::underlying_type<T>::type;
template <class T> using result_of_t = typename std::result_of<T>::type;

template <class...> struct conjunction : std::true_type {};
template <class B> struct conjunction<B> : B {};
template <class B, class... Bs>
struct conjunction<B, Bs...>
    : std::conditional<bool(B::value), conjunction<Bs...>, B>::type {};

template <class...> struct voider { using type = void; };
template <class... Ts> using void_t = typename voider<Ts...>::type;

template <class T> struct is_optional_impl : std::false_type {};

template <class T> struct is_optional_impl<optional<T>> : std::true_type {};

template <class T> using is_optional = is_optional_impl<decay_t<T>>;

// https://stackoverflow.com/questions/38288042/c11-14-invoke-workaround
template <typename Fn, typename... Args,
          enable_if_t<std::is_member_pointer<decay_t<Fn>>{}, int> = 0>
constexpr auto invoke(Fn &&f, Args &&... args) noexcept(
    noexcept(std::mem_fn(f)(std::forward<Args>(args)...)))
    -> decltype(std::mem_fn(f)(std::forward<Args>(args)...)) {
  return std::mem_fn(f)(std::forward<Args>(args)...);
}

template <typename Fn, typename... Args,
          enable_if_t<!std::is_member_pointer<decay_t<Fn>>{}, int> = 0>
constexpr auto invoke(Fn &&f, Args &&... args) noexcept(
    noexcept(std::forward<Fn>(f)(std::forward<Args>(args)...)))
    -> decltype(std::forward<Fn>(f)(std::forward<Args>(args)...)) {
  return std::forward<Fn>(f)(std::forward<Args>(args)...);
}

template <class F, class, class... Us> struct invoke_result_impl;

template <class F, class... Us>
struct invoke_result_impl<
    F, decltype(invoke(std::declval<F>(), std::declval<Us>()...), void()),
    Us...> {
  using type = decltype(invoke(std::declval<F>(), std::declval<Us>()...));
};

template <class F, class... Us>
using invoke_result = invoke_result_impl<F, void, Us...>;

template <class F, class... Us>
using invoke_result_t = typename invoke_result<F, Us...>::type;

template <class U>
using fixup_void = conditional_t<std::is_void<U>::value, monostate, U>;

template <class F, class... U> struct get_invoke_optional_ret {
  using type = invoke_result_t<
      conditional_t<std::is_lvalue_reference<F>::value,
                    typename remove_reference_t<F>::value_type &,
                    typename remove_reference_t<F>::value_type &&>,
      U...>;
};

template <class F, class... U>
using get_invoke_ret = typename conditional_t<is_optional<F>::value,
                                              get_invoke_optional_ret<F, U...>,
                                              invoke_result<F, U...>>::type;

template <class F, class U>
using get_map_return = optional<fixup_void<get_invoke_ret<F, U>>>;

template <class F, class... U>
using returns_void = std::is_void<get_invoke_ret<F, U...>>;

template <class T>
using disable_if_optional = enable_if_t<!is_optional<T>::value>;

template <class T>
using enable_if_optional = enable_if_t<is_optional<T>::value>;

template <class T, class... U>
using enable_if_ret_void = enable_if_t<returns_void<T &&, U...>::value>;

template <class T, class... U>
using disable_if_ret_void = enable_if_t<!returns_void<T &&, U...>::value>;
}

struct in_place_t {
  explicit in_place_t() = default;
};
static constexpr in_place_t in_place{};

// [optional.optional], class template optional
template <class T> class optional;

namespace detail {
template <class T, class U>
using enable_forward_value =
    detail::enable_if_t<std::is_constructible<T, U &&>::value &&
                        !std::is_same<detail::decay_t<U>, in_place_t>::value &&
                        !std::is_same<optional<T>, detail::decay_t<U>>::value>;

template <class T, class U, class Other>
using enable_from_other = detail::enable_if_t<
    std::is_constructible<T, Other>::value &&
    !std::is_constructible<T, optional<U> &>::value &&
    !std::is_constructible<T, optional<U> &&>::value &&
    !std::is_constructible<T, const optional<U> &>::value &&
    !std::is_constructible<T, const optional<U> &&>::value &&
    !std::is_convertible<optional<U> &, T>::value &&
    !std::is_convertible<optional<U> &&, T>::value &&
    !std::is_convertible<const optional<U> &, T>::value &&
    !std::is_convertible<const optional<U> &&, T>::value>;

template <class T, class U>
using enable_assign_forward = detail::enable_if_t<
    !std::is_same<optional<T>, detail::decay_t<U>>::value &&
    !detail::conjunction<std::is_scalar<T>,
                         std::is_same<T, detail::decay_t<U>>>::value &&
    std::is_constructible<T, U>::value && std::is_assignable<T &, U>::value>;

template <class T, class U, class Other>
using enable_assign_from_other = detail::enable_if_t<
    std::is_constructible<T, Other>::value &&
    std::is_assignable<T &, Other>::value &&
    !std::is_constructible<T, optional<U> &>::value &&
    !std::is_constructible<T, optional<U> &&>::value &&
    !std::is_constructible<T, const optional<U> &>::value &&
    !std::is_constructible<T, const optional<U> &&>::value &&
    !std::is_convertible<optional<U> &, T>::value &&
    !std::is_convertible<optional<U> &&, T>::value &&
    !std::is_convertible<const optional<U> &, T>::value &&
    !std::is_convertible<const optional<U> &&, T>::value &&
    !std::is_assignable<T &, optional<U> &>::value &&
    !std::is_assignable<T &, optional<U> &&>::value &&
    !std::is_assignable<T &, const optional<U> &>::value &&
    !std::is_assignable<T &, const optional<U> &&>::value>;

// https://stackoverflow.com/questions/26744589/what-is-a-proper-way-to-implement-is-swappable-to-test-for-the-swappable-concept
namespace swap_adl_tests {
// if swap ADL finds this then it would call std::swap otherwise (same
// signature)
struct tag {};

template <class T> tag swap(T &, T &);
template <class T, std::size_t N> tag swap(T (&a)[N], T (&b)[N]);

// helper functions to test if an unqualified swap is possible, and if it
// becomes std::swap
template <class, class> std::false_type can_swap(...) noexcept(false);
template <class T, class U,
          class = decltype(swap(std::declval<T &>(), std::declval<U &>()))>
std::true_type can_swap(int) noexcept(noexcept(swap(std::declval<T &>(),
                                                    std::declval<U &>())));

template <class, class> std::false_type uses_std(...);
template <class T, class U>
std::is_same<decltype(swap(std::declval<T &>(), std::declval<U &>())), tag>
uses_std(int);

template <class T>
struct is_std_swap_noexcept
    : std::integral_constant<bool,
                             std::is_nothrow_move_constructible<T>::value &&
                                 std::is_nothrow_move_assignable<T>::value> {};

template <class T, std::size_t N>
struct is_std_swap_noexcept<T[N]> : is_std_swap_noexcept<T> {};

template <class T, class U>
struct is_adl_swap_noexcept
    : std::integral_constant<bool, noexcept(can_swap<T, U>(0))> {};
}

#ifdef _MSC_VER
    // TODO make a version which works with MSVC
    template <class T, class U = T>
    sturct is_swappable : std::true_type{};

    template <class T, class U = T>
    struct is_nothrow_swappable : std::true_type{};
#else
template <class T, class U = T>
struct is_swappable
    : std::integral_constant<
          bool,
          decltype(detail::swap_adl_tests::can_swap<T, U>(0))::value &&
              (!decltype(detail::swap_adl_tests::uses_std<T, U>(0))::value ||
               (std::is_move_assignable<T>::value &&
                std::is_move_constructible<T>::value))> {};

template <class T, std::size_t N>
struct is_swappable<T[N], T[N]>
    : std::integral_constant<
          bool,
          decltype(detail::swap_adl_tests::can_swap<T[N], T[N]>(0))::value &&
              (!decltype(
                   detail::swap_adl_tests::uses_std<T[N], T[N]>(0))::value ||
               is_swappable<T, T>::value)> {};

template <class T, class U = T>
struct is_nothrow_swappable
    : std::integral_constant<
          bool,
          is_swappable<T, U>::value &&
              ((decltype(detail::swap_adl_tests::uses_std<T, U>(0))::value
                    &&detail::swap_adl_tests::is_std_swap_noexcept<T>::value) ||
               (!decltype(detail::swap_adl_tests::uses_std<T, U>(0))::value &&
                    detail::swap_adl_tests::is_adl_swap_noexcept<T,
                                                                 U>::value))> {
};
#endif

}

// [optional.nullopt], no-value state indicator
struct nullopt_t {
  struct do_not_use {};
  constexpr explicit nullopt_t(do_not_use, do_not_use) noexcept {}
};
static constexpr nullopt_t nullopt{nullopt_t::do_not_use{},
                                   nullopt_t::do_not_use{}};

// [optional.bad.access], class bad_optional_access
class bad_optional_access : public std::exception {
public:
  bad_optional_access() = default;
  const char *what() const noexcept { return "Optional has no value"; }
};

// [optional.relops], relational operators
template <class T, class U>
inline constexpr bool operator==(const optional<T> &lhs,
                                 const optional<U> &rhs) {
  return lhs.has_value() == rhs.has_value() &&
         (!lhs.has_value() || *lhs == *rhs);
}
template <class T, class U>
inline constexpr bool operator!=(const optional<T> &lhs,
                                 const optional<U> &rhs) {
  return lhs.has_value() != rhs.has_value() ||
         (lhs.has_value() && *lhs != *rhs);
}
template <class T, class U>
inline constexpr bool operator<(const optional<T> &lhs,
                                const optional<U> &rhs) {
  return rhs.has_value() && (!lhs.has_value() || *lhs < *rhs);
}
template <class T, class U>
inline constexpr bool operator>(const optional<T> &lhs,
                                const optional<U> &rhs) {
  return lhs.has_value() && (!rhs.has_value() || *lhs > *rhs);
}
template <class T, class U>
inline constexpr bool operator<=(const optional<T> &lhs,
                                 const optional<U> &rhs) {
  return !lhs.has_value() || (rhs.has_value() && *lhs <= *rhs);
}
template <class T, class U>
inline constexpr bool operator>=(const optional<T> &lhs,
                                 const optional<U> &rhs) {
  return !rhs.has_value() || (lhs.has_value() && *lhs >= *rhs);
}

// [optional.nullops], comparison with nullopt
template <class T>
inline constexpr bool operator==(const optional<T> &lhs, nullopt_t) noexcept {
  return !lhs.has_value();
}
template <class T>
inline constexpr bool operator==(nullopt_t, const optional<T> &rhs) noexcept {
  return !rhs.has_value();
}
template <class T>
inline constexpr bool operator!=(const optional<T> &lhs, nullopt_t) noexcept {
  return lhs.has_value();
}
template <class T>
inline constexpr bool operator!=(nullopt_t, const optional<T> &rhs) noexcept {
  return rhs.has_value();
}
template <class T>
inline constexpr bool operator<(const optional<T> &, nullopt_t) noexcept {
  return false;
}
template <class T>
inline constexpr bool operator<(nullopt_t, const optional<T> &rhs) noexcept {
  return rhs.has_value();
}
template <class T>
inline constexpr bool operator<=(const optional<T> &lhs, nullopt_t) noexcept {
  return !lhs.has_value();
}
template <class T>
inline constexpr bool operator<=(nullopt_t, const optional<T> &) noexcept {
  return true;
}
template <class T>
inline constexpr bool operator>(const optional<T> &lhs, nullopt_t) noexcept {
  return lhs.has_value();
}
template <class T>
inline constexpr bool operator>(nullopt_t, const optional<T> &) noexcept {
  return false;
}
template <class T>
inline constexpr bool operator>=(const optional<T> &, nullopt_t) noexcept {
  return true;
}
template <class T>
inline constexpr bool operator>=(nullopt_t, const optional<T> &rhs) noexcept {
  return !rhs.has_value();
}

// [optional.comp_with_t], comparison with T
template <class T, class U>
inline constexpr bool operator==(const optional<T> &lhs, const U &rhs) {
  return lhs.has_value() ? *lhs == rhs : false;
}
template <class T, class U>
inline constexpr bool operator==(const U &lhs, const optional<T> &rhs) {
  return rhs.has_value() ? lhs == *rhs : false;
}
template <class T, class U>
inline constexpr bool operator!=(const optional<T> &lhs, const U &rhs) {
  return lhs.has_value() ? *lhs != rhs : true;
}
template <class T, class U>
inline constexpr bool operator!=(const U &lhs, const optional<T> &rhs) {
  return rhs.has_value() ? lhs != *rhs : true;
}
template <class T, class U>
inline constexpr bool operator<(const optional<T> &lhs, const U &rhs) {
  return lhs.has_value() ? *lhs < rhs : true;
}
template <class T, class U>
inline constexpr bool operator<(const U &lhs, const optional<T> &rhs) {
  return rhs.has_value() ? lhs < *rhs : false;
}
template <class T, class U>
inline constexpr bool operator<=(const optional<T> &lhs, const U &rhs) {
  return lhs.has_value() ? *lhs <= rhs : true;
}
template <class T, class U>
inline constexpr bool operator<=(const U &lhs, const optional<T> &rhs) {
  return rhs.has_value() ? lhs <= *rhs : false;
}
template <class T, class U>
inline constexpr bool operator>(const optional<T> &lhs, const U &rhs) {
  return lhs.has_value() ? *lhs > rhs : false;
}
template <class T, class U>
inline constexpr bool operator>(const U &lhs, const optional<T> &rhs) {
  return rhs.has_value() ? lhs > *rhs : true;
}
template <class T, class U>
inline constexpr bool operator>=(const optional<T> &lhs, const U &rhs) {
  return lhs.has_value() ? *lhs >= rhs : false;
}
template <class T, class U>
inline constexpr bool operator>=(const U &lhs, const optional<T> &rhs) {
  return rhs.has_value() ? lhs >= *rhs : true;
}

// [optional.specalg], specialized algorithms
template <class T,
          detail::enable_if_t<std::is_move_constructible<T>::value> * = nullptr,
          detail::enable_if_t<detail::is_swappable<T>::value> * = nullptr>
void swap(optional<T> &lhs,
          optional<T> &rhs) noexcept(noexcept(lhs.swap(rhs))) {
  return lhs.swap(rhs);
}

template <class T>
inline constexpr optional<detail::decay_t<T>> make_optional(T &&v) {
  return optional<detail::decay_t<T>>(std::forward<T>(v));
}
template <class T, class... Args>
inline constexpr optional<T> make_optional(Args &&... args) {
  return optional<T>(in_place, std::forward<Args>(args)...);
}
template <class T, class U, class... Args>
inline constexpr optional<T> make_optional(std::initializer_list<U> il,
                                           Args &&... args) {
  return optional<T>(in_place, il, std::forward<Args>(args)...);
}
}

// [optional.hash], hash support
namespace std {
// TODO SFINAE
template <class T> struct hash<tl::optional<T>> {
  ::std::size_t operator()(const tl::optional<T> &o) const {
    if (!o.has_value())
      return 0;

    return hash<tl::detail::remove_const_t<T>>()(*o);
  }
};
}

namespace tl {
namespace detail {
template <class T, bool = ::std::is_trivially_destructible<T>::value>
struct optional_storage_base {
  constexpr optional_storage_base() noexcept : m_dummy(), m_has_value(false) {}

  template <class... U>
  constexpr optional_storage_base(in_place_t, U &&... u) noexcept
      : m_value(std::forward<U>(u)...), m_has_value(true) {}

  ~optional_storage_base() {
    if (m_has_value) {
      m_value.~T();
      m_has_value = false;
    }
  }

  struct dummy {};
  union {
    dummy m_dummy;
    T m_value;
  };

  bool m_has_value;
};

template <class T> struct optional_storage_base<T, true> {
  constexpr optional_storage_base() noexcept : m_dummy(), m_has_value(false) {}

  template <class... U>
  constexpr optional_storage_base(in_place_t, U &&... u) noexcept
      : m_value(std::forward<U>(u)...), m_has_value(true) {}

  ~optional_storage_base() = default;

  struct dummy {};
  union {
    dummy m_dummy;
    T m_value;
  };

  bool m_has_value = false;
};
}

template <class T> class optional : private detail::optional_storage_base<T> {
  using base = detail::optional_storage_base<T>;

public:
  using value_type = T;

  // [optional.ctor], constructors
  constexpr optional() noexcept = default;
  constexpr optional(nullopt_t) noexcept {};
  TL_OPTIONAL_11_CONSTEXPR optional(const optional &rhs) {
    if (rhs.has_value()) {
      this->m_has_value = true;
      new (std::addressof(this->m_value)) T(*rhs);
    }
  }

  // TODO conditionally disable
  TL_OPTIONAL_11_CONSTEXPR optional(optional &&rhs) noexcept(
      std::is_nothrow_move_constructible<T>::value) {
    if (rhs.has_value()) {
      this->m_has_value = true;
      new (std::addressof(this->m_value)) T(std::move(*rhs));
    }
  }
  template <class... Args>
  constexpr explicit optional(
      detail::enable_if_t<std::is_constructible<T, Args...>::value, in_place_t>,
      Args &&... args)
      : base(in_place, std::forward<Args>(args)...) {}
  template <class U, class... Args>
  TL_OPTIONAL_11_CONSTEXPR explicit optional(
      detail::enable_if_t<std::is_constructible<T, std::initializer_list<U> &,
                                                Args &&...>::value,
                          in_place_t>,
      std::initializer_list<U> il, Args &&... args) {
    this->m_has_value = true;
    new (std::addressof(this->m_value)) T(il, std::forward<Args>(args)...);
  }

  template <
      class U = T,
      detail::enable_if_t<std::is_convertible<U &&, T>::value> * = nullptr,
      detail::enable_forward_value<T, U> * = nullptr>
  constexpr optional(U &&u) : base(in_place, std::forward<U>(u)) {}

  template <
      class U = T,
      detail::enable_if_t<!std::is_convertible<U &&, T>::value> * = nullptr,
      detail::enable_forward_value<T, U> * = nullptr>
  constexpr explicit optional(U &&u) : base(in_place, std::forward<U>(u)) {}

  template <
      class U, detail::enable_from_other<T, U, const U &> * = nullptr,
      detail::enable_if_t<std::is_convertible<const U &, T>::value> * = nullptr>
  optional(const optional<U> &rhs) {
    this->m_has_value = true;
    new (std::addressof(this->m_value)) T(*rhs);
  }

  template <class U, detail::enable_from_other<T, U, const U &> * = nullptr,
            detail::enable_if_t<!std::is_convertible<const U &, T>::value> * =
                nullptr>
  optional(const optional<U> &rhs) {
    this->m_has_value = true;
    new (std::addressof(this->m_value)) T(*rhs);
  }

  template <
      class U, detail::enable_from_other<T, U, U &&> * = nullptr,
      detail::enable_if_t<std::is_convertible<U &&, T>::value> * = nullptr>
  optional(optional<U> &&rhs) {
    this->m_has_value = true;
    new (std::addressof(this->m_value)) T(std::move(*rhs));
  }

  template <
      class U, detail::enable_from_other<T, U, U &&> * = nullptr,
      detail::enable_if_t<!std::is_convertible<U &&, T>::value> * = nullptr>
  explicit optional(optional<U> &&rhs) {
    this->m_has_value = true;
    new (std::addressof(this->m_value)) T(std::move(*rhs));
  }

  // [optional.dtor], destructor
  ~optional() = default;

  // [optional.assign], assignment
  optional &operator=(nullopt_t) noexcept {
    if (has_value()) {
      this->m_value.~T();
      this->m_has_value = false;
    }
  }

  // TODO conditionally delete, check exception guarantee
  optional &operator=(const optional &rhs) {
    if (has_value()) {
      if (rhs.has_value()) {
        this->m_value = rhs.m_value;
      } else {
        this->m_value.~T();
        this->m_has_value = false;
      }
    }

    if (rhs.has_value()) {
      new (std::addressof(this->m_value)) T(rhs.m_value);
      this->m_has_value = true;
    }
  }

  // TODO conditionally delete, check exception guarantee
  optional &operator=(optional &&rhs) noexcept(
      std::is_nothrow_move_assignable<T>::value
          &&std::is_nothrow_move_constructible<T>::value) {
    if (has_value()) {
      if (rhs.has_value()) {
        this->m_value = std::move(rhs.m_value);
      } else {
        this->m_value.~T();
        this->m_has_value = false;
      }
    }

    if (rhs.has_value()) {
      new (std::addressof(this->m_value)) T(std::move(rhs.m_value));
      this->m_has_value = true;
    }
  }

  // TODO conditionally delete, check exception guarantee
  template <class U = T, detail::enable_assign_forward<T, U> * = nullptr>
  optional &operator=(U &&u) {
    if (has_value()) {
      this->m_value = std::forward<U>(u);
    } else {
      new (std::addressof(this->m_value)) T(std::forward<U>(u));
      this->m_has_value = true;
    }
  }

  // TODO check exception guarantee
  template <class U,
            detail::enable_assign_from_other<T, U, const U &> * = nullptr>
  optional &operator=(const optional<U> &rhs) {
    if (has_value()) {
      if (rhs.has_value()) {
        this->m_value = rhs.m_value;
      } else {
        this->m_value.~T();
        this->m_has_value = false;
      }
    }

    if (rhs.has_value()) {
      new (std::addressof(this->m_value)) T(rhs.m_value);
      this->m_has_value = true;
    }
  }

  // TODO check exception guarantee
  template <class U, detail::enable_assign_from_other<T, U, U> * = nullptr>
  optional &operator=(optional<U> &&rhs) {
    if (has_value()) {
      if (rhs.has_value()) {
        this->m_value = std::move(rhs.m_value);
      } else {
        this->m_value.~T();
        this->m_has_value = false;
      }
    }

    if (rhs.has_value()) {
      new (std::addressof(this->m_value)) T(std::move(rhs.m_value));
      this->m_has_value = true;
    }
  }

  template <class... Args> T &emplace(Args &&... args) {
    static_assert(std::is_constructible<T, Args &&...>::value,
                  "T must be constructible with Args");

    *this = nullopt;
    new (std::addressof(this->m_value)) T(std::forward<Args>(args)...);
  }

  template <class U, class... Args>
  detail::enable_if_t<
      std::is_constructible<T, std::initializer_list<U> &, Args &&...>::value,
      T &>
  emplace(std::initializer_list<U> il, Args &&... args) {
    *this = nullopt;
    new (std::addressof(this->m_value)) T(il, std::forward<Args>(args)...);
  }

  // [optional.swap], swap
  void
  swap(optional &rhs) noexcept(std::is_nothrow_move_constructible<T>::value
                                   &&detail::is_nothrow_swappable<T>::value) {
    if (has_value()) {
      if (rhs.has_value()) {
        using std::swap;
        swap(**this, *rhs);
      } else {
        new (&rhs.m_value) T(std::move(this->m_value));
        this->m_value.T::~T();
      }
    } else if (rhs.has_value()) {
      new (std::addressof(this->m_value)) T(std::move(rhs.m_value));
      rhs.m_value.T::~T();
    }
  }

  // [optional.observe], observers
  constexpr const T *operator->() const {
    return std::addressof(this->m_value);
  }
  TL_OPTIONAL_11_CONSTEXPR T *operator->() {
    return std::addressof(this->m_value);
  }
  constexpr const T &operator*() const & { return this->m_value; }
  TL_OPTIONAL_11_CONSTEXPR T &operator*() & { return this->m_value; }
  TL_OPTIONAL_11_CONSTEXPR T &&operator*() && {
    return std::move(this->m_value);
  }
  constexpr const T &&operator*() const && { return std::move(this->m_value); }
  constexpr explicit operator bool() const noexcept {
    return this->m_has_value;
  }
  constexpr bool has_value() const noexcept { return this->m_has_value; }
  TL_OPTIONAL_11_CONSTEXPR const T &value() const & {
    if (has_value())
      return this->m_value;
    throw bad_optional_access();
  }
  TL_OPTIONAL_11_CONSTEXPR T &value() & {
    if (has_value())
      return this->m_value;
    throw bad_optional_access();
  }
  TL_OPTIONAL_11_CONSTEXPR T &&value() && {
    if (has_value())
      return std::move(this->m_value);
    throw bad_optional_access();
  }
  constexpr const T &&value() const && {
    if (has_value())
      return std::move(this->m_value);
    throw bad_optional_access();
  }
  template <class U> constexpr T value_or(U &&u) const & {
    static_assert(std::is_copy_constructible<T>::value &&
                      std::is_convertible<U &&, T>::value,
                  "T must be copy constructible and convertible from U");
    return has_value() ? **this : static_cast<T>(std::forward<U>(u));
  }
  template <class U> constexpr T value_or(U &&u) && {
    static_assert(std::is_move_constructible<T>::value &&
                      std::is_convertible<U &&, T>::value,
                  "T must be move constructible and convertible from U");
    return has_value() ? **this : static_cast<T>(std::forward<U>(u));
  }

  // [optional.mod], modifiers
  void reset() noexcept {
    if (has_value()) {
      this->m_value.~T();
      this->m_has_value = false;
    }
  }

  template <class F>
  TL_OPTIONAL_11_CONSTEXPR detail::invoke_result_t<F, T> and_then(F &&f) & {
    using result = detail::invoke_result_t<F, T>;
    static_assert(detail::is_optional<result>::value,
                  "F must return an optional");

    return has_value() ? detail::invoke(std::forward<F>(f), **this)
                       : result(nullopt);
  }

  template <class F>
  TL_OPTIONAL_11_CONSTEXPR detail::invoke_result_t<F, T> and_then(F &&f) && {
    using result = detail::invoke_result_t<F, T>;
    static_assert(detail::is_optional<result>::value,
                  "F must return an optional");

    return has_value() ? detail::invoke(std::forward<F>(f), std::move(**this))
                       : result(nullopt);
  }

  template <class F>
  constexpr detail::invoke_result_t<F, T> and_then(F &&f) const & {
    using result = detail::invoke_result_t<F, T>;
    static_assert(detail::is_optional<result>::value,
                  "F must return an optional");

    return has_value() ? detail::invoke(std::forward<F>(f), **this)
                       : result(nullopt);
  }

  template <class F>
  constexpr detail::invoke_result_t<F, T> and_then(F &&f) const && {
    using result = detail::invoke_result_t<F, T>;
    static_assert(detail::is_optional<result>::value,
                  "F must return an optional");

    return has_value() ? detail::invoke(std::forward<F>(f), std::move(**this))
                       : result(nullopt);
  }

  template <class F, detail::disable_if_optional<F> * = nullptr,
            detail::disable_if_ret_void<F, T &> * = nullptr>
      detail::get_map_return<F, T &> map(F &&f) &
      noexcept(noexcept(detail::invoke(std::forward<F>(f),
                                       std::declval<T &>()))) {
    using result = detail::get_map_return<F, T &>;
    return has_value() ? detail::invoke(std::forward<F>(f), **this)
                       : result(nullopt);
  }

  template <class F, detail::disable_if_optional<F> * = nullptr,
            detail::enable_if_ret_void<F, T &> * = nullptr>
  detail::get_map_return<F, T &> map(F &&f) & {
    if (!has_value())
      return nullopt;

    detail::invoke(std::forward<F>(f), **this);
    return monostate{};
  }

  template <class F, detail::enable_if_optional<F> * = nullptr,
            detail::disable_if_ret_void<F, T &> * = nullptr>
  detail::get_map_return<F, T &> map(F &&f) & {
    using result = detail::get_map_return<F, T &>;
    return (f.has_value() && has_value())
               ? detail::invoke(*std::forward<F>(f), **this)
               : result(nullopt);
  }

  template <class F, detail::enable_if_optional<F> * = nullptr,
            detail::enable_if_ret_void<F, T &> * = nullptr>
  detail::get_map_return<F, T &> map(F &&f) & {
    if (!f.has_value() || !has_value())
      return nullopt;

    detail::invoke(*std::forward<F>(f), **this);
    return monostate{};
  }

  template <class F, detail::disable_if_optional<F> * = nullptr,
            detail::disable_if_ret_void<F, T &&> * = nullptr>
  detail::get_map_return<F, T &&> map(F &&f) && {
    using result = detail::get_map_return<F, T &&>;
    return has_value() ? detail::invoke(std::forward<F>(f), std::move(**this))
                       : result(nullopt);
  }

  template <class F, detail::disable_if_optional<F> * = nullptr,
            detail::enable_if_ret_void<F, T &&> * = nullptr>
  detail::get_map_return<F, T &&> map(F &&f) && {
    if (!has_value())
      return nullopt;

    detail::invoke(std::forward<F>(f), std::move(**this));
    return monostate{};
  }

  template <class F, detail::enable_if_optional<F> * = nullptr,
            detail::disable_if_ret_void<F, T &&> * = nullptr>
  detail::get_map_return<F, T &&> map(F &&f) && {
    using result = detail::get_map_return<F, T &&>;
    return (f.has_value() && has_value())
               ? detail::invoke(*std::forward<F>(f), std::move(**this))
               : result(nullopt);
  }

  template <class F, detail::enable_if_optional<F> * = nullptr,
            detail::enable_if_ret_void<F, T &&> * = nullptr>
  detail::get_map_return<F, T &&> map(F &&f) && {
    if (!f.has_value() || !has_value())
      return nullopt;

    detail::invoke(*std::forward<F>(f), std::move(**this));
    return monostate{};
  }

  template <class F, detail::disable_if_optional<F> * = nullptr,
            detail::disable_if_ret_void<F, T const &> * = nullptr>
  constexpr detail::get_map_return<F, T const &> map(F &&f) const & {
    using result = detail::get_map_return<F, T const &>;
    return this->has_value()
               ? result(detail::invoke(std::forward<F>(f), **this))
               : result(nullopt);
  }

  template <class F, detail::disable_if_optional<F> * = nullptr,
            detail::enable_if_ret_void<F, T const &> * = nullptr>
  detail::get_map_return<F, T const &> map(F &&f) const & {
    if (!has_value())
      return nullopt;

    detail::invoke(std::forward<F>(f), **this);
    return monostate{};
  }

  template <class F, detail::enable_if_optional<F> * = nullptr,
            detail::disable_if_ret_void<F, T const &> * = nullptr>
  constexpr detail::get_map_return<F, T const &> map(F &&f) const & {
    using result = detail::get_map_return<F, const T &>;
    return (f.has_value() && has_value())
               ? detail::invoke(*std::forward<F>(f), **this)
               : result(nullopt);
  }

  template <class F, detail::enable_if_optional<F> * = nullptr,
            detail::enable_if_ret_void<F, T const &> * = nullptr>
  detail::get_map_return<F, T const &> map(F &&f) const & {
    if (!f.has_value() || !has_value())
      return nullopt;

    detail::invoke(*std::forward<F>(f), **this);
    return monostate{};
  }

  template <class F, detail::disable_if_optional<F> * = nullptr,
            detail::disable_if_ret_void<F, T const &&> * = nullptr>
  constexpr detail::get_map_return<F, T const &&> map(F &&f) const && {
    using result = detail::get_map_return<F, const T &&>;
    return has_value() ? detail::invoke(std::forward<F>(f), std::move(**this))
                       : result(nullopt);
  }

  template <class F, detail::disable_if_optional<F> * = nullptr,
            detail::enable_if_ret_void<F, T const &&> * = nullptr>
  detail::get_map_return<F, T const &&> map(F &&f) const && {
    if (!has_value())
      return nullopt;

    detail::invoke(std::forward<F>(f), std::move(**this));
    return monostate{};
  }

  template <class F, detail::enable_if_optional<F> * = nullptr,
            detail::disable_if_ret_void<F, T const &&> * = nullptr>
  constexpr detail::get_map_return<F, T const &&> map(F &&f) const && {
    using result = detail::get_map_return<F, const T &&>;
    return (f.has_value() && has_value())
               ? detail::invoke(*std::forward<F>(f), std::move(**this))
               : result(nullopt);
  }

  template <class F, detail::enable_if_optional<F> * = nullptr,
            detail::enable_if_ret_void<F, T const &&> * = nullptr>
  detail::get_map_return<F, T &> map(F &&f) const && {
    if (!f.has_value() || !has_value())
      return nullopt;

    detail::invoke(*std::forward<F>(f), std::move(**this));
    return monostate{};
  }

  template <class F, detail::enable_if_ret_void<F> * = nullptr>
  optional<T> constexpr or_else(F &&f) & {
    if (has_value())
      return *this;

    std::forward<F>(f)();
    return nullopt;
  }

  template <class F, detail::disable_if_ret_void<F> * = nullptr>
  optional<T> constexpr or_else(F &&f) & {
    return has_value() ? *this : std::forward<F>(f)();
  }

  template <class F, detail::enable_if_ret_void<F> * = nullptr>
  optional<T> or_else(F &&f) && {
    if (has_value())
      return std::move(*this);

    std::forward<F>(f)();
    return nullopt;
  }

  template <class F, detail::disable_if_ret_void<F> * = nullptr>
  optional<T> constexpr or_else(F &&f) && {
    return has_value() ? std::move(*this) : std::forward<F>(f)();
  }

  template <class F, detail::enable_if_ret_void<F> * = nullptr>
  optional<T> or_else(F &&f) const & {
    if (has_value())
      return *this;

    std::forward<F>(f)();
    return nullopt;
  }

  template <class F, detail::disable_if_ret_void<F> * = nullptr>
  optional<T> constexpr or_else(F &&f) const & {
    return has_value() ? *this : std::forward<F>(f)();
  }

  template <class F, detail::enable_if_ret_void<F> * = nullptr>
  optional<T> or_else(F &&f) const && {
    if (has_value())
      return std::move(*this);

    std::forward<F>(f)();
    return nullopt;
  }

  template <class F, detail::disable_if_ret_void<F> * = nullptr>
  optional<T> or_else(F &&f) const && {
    return has_value() ? std::move(*this) : std::forward<F>(f)();
  }

  template <class F, class U> U map_or(F &&f, U &&u) & {
    return has_value() ? detail::invoke(std::forward<F>(f), **this)
                       : std::forward<U>(u);
  }

  template <class F, class U> U map_or(F &&f, U &&u) && {
    return has_value() ? detail::invoke(std::forward<F>(f), std::move(**this))
                       : std::forward<U>(u);
  }

  template <class F, class U> U map_or(F &&f, U &&u) const & {
    return has_value() ? detail::invoke(std::forward<F>(f), **this)
                       : std::forward<U>(u);
  }

  template <class F, class U> U map_or(F &&f, U &&u) const && {
    return has_value() ? detail::invoke(std::forward<F>(f), std::move(**this))
                       : std::forward<U>(u);
  }

  template <class F, class U> U map_or_else(F &&f, U &&u) & {
    return has_value() ? detail::invoke(std::forward<F>(f), **this)
                       : std::forward<U>(u)();
  }

  template <class F, class U> U map_or_else(F &&f, U &&u) && {
    return has_value() ? detail::invoke(std::forward<F>(f), std::move(**this))
                       : std::forward<U>(u)();
  }

  template <class F, class U> U map_or_else(F &&f, U &&u) const & {
    return has_value() ? detail::invoke(std::forward<F>(f), **this)
                       : std::forward<U>(u)();
  }

  template <class F, class U> U map_or_else(F &&f, U &&u) const && {
    return has_value() ? detail::invoke(std::forward<F>(f), std::move(**this))
                       : std::forward<U>(u)();
  }
};

// template <class T> optional(T)->optional<T>;
}
