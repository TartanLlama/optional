///
// optional - An implementation of std::optional with extensions
// Written in 2017 by Simon Brand (@TartanLlama)
//
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
///

#include <type_traits>
#include "tl/type_traits.hpp"

namespace tl {
  // [optional.optional], class template optional
  template <class T>
  class optional;

  // [optional.nullopt], no-value state indicator
  struct nullopt_t{
      struct do_not_use{};
      constexpr explicit nullopt(do_not_use, do_not_use) noexcept{}
  };
    inline constexpr nullopt_t nullopt{nullopt_t::do_not_use{}, nullopt_t::do_not_use{}};

  // [optional.bad.access], class bad_­optional_­access
    class bad_optional_access : public std::exception {
        bad_optional_access() = default;
        const char* what() const {
            return "Optional has no value";
        }
    };

  // [optional.relops], relational operators
  template <class T, class U>
  inline constexpr bool operator==(const optional<T>& lhs, const optional<U>& rhs) {
      if (lhs.has_value() != rhs.has_value())
          return false;
      if (lhs.has_value())
          return true;

      return lhs.value() == rhs.value();
  }
  template <class T, class U>
  inline constexpr bool operator!=(const optional<T>& lhs, const optional<U>& rhs) {
      if (lhs.has_value() != rhs.has_value())
          return true;
      if (lhs.has_value())
          return false;

      return lhs.value() != rhs.value();
  }
  template <class T, class U>
  inline constexpr bool operator<(const optional<T>& lhs, const optional<U>& rhs) {
      if (!rhs.has_value())
          return false;
      if (!lhs.has_value())
          return true;

      return lhs.value() < rhs.value();
  }
  template <class T, class U>
  inline constexpr bool operator>(const optional<T>& lhs, const optional<U>& rhs) {
      if (!lhs.has_value())
          return false;
      if (!rhs.has_value())
          return true;

      return lhs.value() > rhs.value();
  }
  template <class T, class U>
  inline constexpr bool operator<=(const optional<T>& lhs, const optional<U>& rhs) {
      if (!lhs.has_value())
          return true;
      if (!rhs.has_value())
          return false;

      return lhs.value() <= rhs.value();
  }
  }
  template <class T, class U>
  inline constexpr bool operator>=(const optional<T>& lhs, const optional<U>& rhs) {
      if (!rhs.has_value())
          return true;
      if (!lhs.has_value())
          return false;

      return lhs.value() >= rhs.value();
  }

  // [optional.nullops], comparison with nullopt
template <class T> inline constexpr bool operator==(const optional<T>& lhs, nullopt_t) noexcept {
    return !lhs.has_value();
}
template <class T> inline constexpr bool operator==(nullopt_t, const optional<T>& rhs) noexcept {
    return !rhs.has_value();
}
template <class T> inline constexpr bool operator!=(const optional<T>& lhs, nullopt_t) noexcept {
    return lhs.has_value();
}
template <class T> inline constexpr bool operator!=(nullopt_t, const optional<T>& rhs) noexcept {
    return rhs.has_value();
}
template <class T> inline constexpr bool operator<(const optional<T>&, nullopt_t) noexcept {
    return false;
}
template <class T> inline constexpr bool operator<(nullopt_t, const optional<T>& rhs) noexcept {
    return rhs.has_value();
}
template <class T> inline constexpr bool operator<=(const optional<T>& lhs, nullopt_t) noexcept {
    return !lhs.has_value();
}
template <class T> inline constexpr bool operator<=(nullopt_t, const optional<T>&) noexcept {
    return true;
}
template <class T> inline constexpr bool operator>(const optional<T>& lhs, nullopt_t) noexcept {
    return lhs.has_value();
}
template <class T> inline constexpr bool operator>(nullopt_t, const optional<T>&) noexcept {
    return false;
}
template <class T> inline constexpr bool operator>=(const optional<T>&, nullopt_t) noexcept {
    return true;
}
template <class T> inline constexpr bool operator>=(nullopt_t, const optional<T>& rhs) noexcept {
    return !rhs.has_value();
}

  // [optional.comp_with_t], comparison with T
template <class T, class U> inline constexpr bool operator==(const optional<T>& lhs, const U& rhs) {
    return lhs.has_value() ? *lhs == rhs : false;
}
template <class T, class U> inline constexpr bool operator==(const U& lhs, const optional<T>& rhs) {
    return rhs.has_value() ? lhs == rhs.value() : false;
}
template <class T, class U> inline constexpr bool operator!=(const optional<T>& lhs, const U& rhs) {
    return lhs.has_value() ? lhs.value() != lhs : true;
}
template <class T, class U> inline constexpr bool operator!=(const U& lhs, const optional<T>& rhs) {
    return rhs.has_value() ? lhs != rhs.value() : true;
}
template <class T, class U> inline constexpr bool operator<(const optional<T>& lhs, const U& rhs) {
    return lhs.has_value() ? lhs.value() < lhs : true;
}
template <class T, class U> inline constexpr bool operator<(const U& lhs, const optional<T>& rhs) {
    return rhs.has_value() ? lhs < rhs.value() : false;
}
template <class T, class U> inline constexpr bool operator<=(const optional<T>& lhs, const U& rhs) {
    return lhs.has_value() ? lhs.value() <= lhs : true;
}
template <class T, class U> inline constexpr bool operator<=(const U& lhs, const optional<T>& rhs) {
    return rhs.has_value() ? lhs <= rhs.value() : false;
}
template <class T, class U> inline constexpr bool operator>(const optional<T>& lhs, const U& rhs) {
    return lhs.has_value() ? lhs.value() > lhs : false;
}
template <class T, class U> inline constexpr bool operator>(const U& lhs, const optional<T>& rhs) {
    return rhs.has_value() ? lhs > rhs.value() : true;
}
template <class T, class U> inline constexpr bool operator>=(const optional<T>& lhs, const U& rhs) {
    return lhs.has_value() ? lhs.value() >= lhs : false;
}
template <class T, class U> inline constexpr bool operator>=(const U& lhs, const optional<T>& rhs) {
    return rhs.has_value() ? lhs >= rhs.value() : true;
}


  // [optional.specalg], specialized algorithms
template <class T, tl::enable_if_t<std::is_move_constructible<T>::value* = nullptr,
                   tl:enable_if_t<std::is_swappable_v<T>>* = nullptr>
void swap(optional<T>& lhs, optional<T>& rhs) noexcept(noexcept(lhs.swap(rhs))) {
    return lhs.swap(rhs);
}

  template <class T>
  inline constexpr optional<tl::decay_t<T>> make_optional(T&& v) {
      return optional<decay_t<T>>(std​::​forward<T>(v));
  }
  template <class T, class... Args>
  inline constexpr optional<T> make_optional(Args&&... args) {
      return optional<T>(in_place, std​::​forward<Args>(args)...);
  }
  template <class T, class U, class... Args>
  inline constexpr optional<T> make_optional(initializer_list<U> il, Args&&... args) {
      return optional<T>(in_place, il, std​::​forward<Args>(args)...);
  }
}

  // [optional.hash], hash support
namespace std {
    template <class T> struct hash;
    template <class T, class = decltype(hash<tl::remove_const_t<T>>{})>
    struct hash<tl::optional<T>> {
        std::size_t operator() (const tl::optional<T>& o) {
            if (!o.has_value())
                return 0;

            return hash<tl::remove_const_t<T>>()(o.value());
        }
    }
}

namespace tl {

template <class T>
  class optional {
  public:
    using value_type = T;

    // [optional.ctor], constructors
    constexpr optional() noexcept : m_has_value(false) {
        new (&m_storage.d) dummy;
    }
    constexpr optional(nullopt_t) noexcept : optional() {}

    constexpr optional(const optional& rhs);
    constexpr optional(optional&&) noexcept(see below);
    template <class... Args>
      constexpr explicit optional(in_place_t, Args&&...);
    template <class U, class... Args>
      constexpr explicit optional(in_place_t, initializer_list<U>, Args&&...);
    template <class U = T>
      EXPLICIT constexpr optional(U&&);
    template <class U>
      EXPLICIT optional(const optional<U>&);
    template <class U>
      EXPLICIT optional(optional<U>&&);

    // [optional.dtor], destructor
    ~optional();

    // [optional.assign], assignment
    optional& operator=(nullopt_t) noexcept;
    optional& operator=(const optional&);
    optional& operator=(optional&&) noexcept(see below);
    template <class U = T> optional& operator=(U&&);
    template <class U> optional& operator=(const optional<U>&);
    template <class U> optional& operator=(optional<U>&&);
    template <class... Args> T& emplace(Args&&...);
    template <class U, class... Args> T& emplace(initializer_list<U>, Args&&...);

    // [optional.swap], swap
    void swap(optional&) noexcept(see below);

    // [optional.observe], observers
    constexpr const T* operator->() const {
        return std::addressof(m_storage.t);
    }
    constexpr T* operator->() {
        return std::addressof(m_storage.t);
    }
    constexpr const T& operator*() const& {
        return m_storage.t;
    }
    constexpr T& operator*() & {
        return m_storage.t;
    }
    constexpr T&& operator*() && {
        return std::move(m_storage.t);
    }
    constexpr const T&& operator*() const&& {
        return std::move(m_storage.t);
    }
    constexpr explicit operator bool() const noexcept {
        return m_has_value;
    }
    constexpr bool has_value() const noexcept {
        return m_has_value;
    }
    constexpr const T& value() const& {
        return has_value() ? m_storage.t : throw bad_optional_access();
    }
    constexpr T& value() & {
        return has_value() ? m_storage.t : throw bad_optional_access();
    }
    constexpr T&& value() && {
        return has_value() ? std::move(m_storage.t) : throw bad_optional_access();
    }
    constexpr const T&& value() const&& {
        return has_value() ? std::move(m_storage.t) : throw bad_optional_access();
    }
    template <class U> constexpr T value_or(U&&) const& {
        static_assert(std::is_copy_constructible<T>::value && std::is_convertible<U&&, T>::value,
                      "T must be copy constructible and convertible from U");
        return has_value() ? value() : static_cast<T>(std::forward<U>(v));
    }
    template <class U> constexpr T value_or(U&&) && {
        static_assert(std::is_move_constructible<T>::value && std::is_convertible<U&&, T>::value,
                      "T must be move constructible and convertible from U");
        return has_value() ? value() : static_cast<T>(std::forward<U>(v));
    }

    // [optional.mod], modifiers
    void reset() noexcept;

  private:
    struct dummy{};
    union {
        dummy d;
        T t;
    } m_storage;

    bool m_has_value;
  };
}
