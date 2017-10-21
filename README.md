# optional
Single header, Work-in-progress implementation of std::optional with functional-style extensions.

Clang + GCC: [![Linux Build Status](https://travis-ci.org/TartanLlama/optional.png?branch=master)](https://travis-ci.org/TartanLlama/optional)
MSVC: [![Windows Build Status](https://ci.appveyor.com/api/projects/status/k5x00xa11y3s5wsg?svg=true)](https://ci.appveyor.com/project/TartanLlama/optional)

`std::optional` is the preferred way to represent an object which may or may not have a value. Unfortunately, chaining together many computations which may or may not produce a value can be verbose, as empty-checking code will be mixed in with the actual programming logic. This implementation provides a number of utilities to make coding with `optional` cleaner.

For example, instead of writing this code:

```
std::optional<image> get_cute_cat (const image& img) {
    auto cropped = crop_to_cat(img);
    if (!cropped) {
      return std::nullopt;
    }

    auto with_tie = add_bow_tie(*cropped);
    if (!with_tie) {
      return std::nullopt;
    }

    auto with_sparkles = make_eyes_sparkle(*with_tie);
    if (!with_sparkles) {
      return std::nullopt;
    }

    return add_rainbow(make_smaller(*with_sparkles));
}
```

You can do this:

```
std::optional<image> get_cute_cat (const image& img) {
    return crop_to_cat(img)
           .and_then(add_bow_tie)
           .and_then(make_eyes_sparkle)
           .map(make_smaller)
           .map(add_rainbow);
}
```

Full documentation available at [optional.tartanllama.xyz](optional.tartanllama.xyz)

The interface is the same as `std::optional`, but the following member functions are also defined. Explicit types are for clarity.

- `map`: carries out some operation on the stored object if there is one.
  * `tl::optional<std::size_t> s = opt_string.map(&std::string::size);`
- `and_then`: like `map`, but for operations which return a `tl::optional`.
  * `tl::optional<int> stoi (const std::string& s);`
  * `tl::optional<int> i = opt_string.and_then(stoi);`
- `or_else`: calls some function if there is no value stored.
  * `opt.or_else([] { throw std::runtime_error{"oh no"]; });`
- `map_or`: carries out a `map` if there is a value, otherwise returns a default value.
  * `tl::optional<std::size_t> s = opt_string.map_or(&std::string::size, 0);`
- `map_or_else`: carries out a `map` if there is a value, otherwise returns the result of a given default function.
  * `std::size_t get_default();`
  * `tl::optional<std::size_t> s = opt_string.map_or(&std::string::size, get_default);`
- `conjunction`: returns the argument if a value is stored in the optional, otherwise an empty optional.
  * `tl::make_optional(42).conjunction(13); //13`
  * `tl::optional<int>){}.conjunction(13); //empty`
- `disjunction`: returns the argument if the optional is empty, otherwise the current value.
  * `tl::make_optional(42).disjunction(13); //42`
  * `tl::optional<int>){}.disjunction(13); //13`
- `take`: returns the current value, leaving the optional empty.
  * `opt_string.take().map(&std::string::size); //opt_string now empty;`

### Compiler support

Tested on:

- clang 3.9
- clang 3.8
- g++ 7.2
- g++ 5.4
- g++ 4.8.5
- MSVC 2015
- MSVC 2017

### Dependencies

Requires [Standardese](https://github.com/foonathan/standardese) for generating documentation.
Requires [Catch](https://github.com/philsquared/Catch) for testing. This is bundled in the test directory.
