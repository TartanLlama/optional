# Header file `optional.hpp`<a id="optional.hpp"></a>

<pre><code class="language-cpp">namespace <a href='doc_optional.md#optional.hpp'>tl</a>
{
    class <a href='doc_optional.md#tl::monostate'>monostate</a>;
    
    struct <a href='doc_optional.md#tl::in_place_t'>in_place_t</a>;
    
    constexpr <a href='doc_optional.md#tl::in_place_t'>in_place_t{}</a> <a href='doc_optional.md#tl::in_place'>in_place</a>;
    
    struct <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>;
    
    static constexpr nullopt_t nullopt;
    
    class <a href='doc_optional.md#optional.hpp'>bad_optional_access</a>;
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator==</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator!=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator&lt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator&gt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator&lt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constoptional-U-&)'>operator&gt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator==</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator==</a>(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator!=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator!=</a>(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&lt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&lt;</a>(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&lt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&lt;=</a>(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&gt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&gt;</a>(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&gt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,tl::nullopt_t)'>operator&gt;=</a>(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator==</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator==</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator!=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator!=</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator&lt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator&lt;</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator&lt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator&lt;=</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator&gt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator&gt;</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator&gt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#tl::operator==(constoptional-T-&,constU&)'>operator&gt;=</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    
    template &lt;class T&gt;
    void swap(optional&lt;T&gt; &amp;lhs, optional&lt;T&gt; &amp;rhs);
    
    template &lt;class T&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;detail::decay_t&lt;T&gt;&gt;</a> <a href='doc_optional.md#optional.hpp'>make_optional</a>(T&amp;&amp; v);
    
    template &lt;class T, class ... Args&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#optional.hpp'>make_optional</a>(Args&amp;&amp;... args);
    
    template &lt;class T, class U, class ... Args&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#optional.hpp'>make_optional</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args);
}

namespace <a href='doc_optional.md#optional.hpp'>std</a>
{
}

namespace <a href='doc_optional.md#optional.hpp'>tl</a>
{
    template &lt;class T&gt;
    class <a href='doc_optional.md#tl::optional-T-'>optional</a>;
}</code></pre>

## Class `tl::monostate`<a id="tl::monostate"></a>

<pre><code class="language-cpp">class monostate
{
};</code></pre>

Represents an optional with no data; essentially a bool

## Struct `tl::in_place_t`<a id="tl::in_place_t"></a>

<pre><code class="language-cpp">struct in_place_t
{
    <a href='doc_optional.md#tl::in_place_t'>in_place_t</a>() = default;
};</code></pre>

A tag type to tell optional to construct its value in-place

## Variable `tl::in_place`<a id="tl::in_place"></a>

<pre><code class="language-cpp">constexpr <a href='doc_optional.md#tl::in_place_t'>in_place_t{}</a> in_place;</code></pre>

A tag to tell optional to construct its value in-place

## Struct `tl::nullopt_t`<a id="tl::nullopt_t"></a>

<pre><code class="language-cpp">struct nullopt_t
{
    struct <a href='doc_optional.md#tl::nullopt_t'>do_not_use</a>;
    
    constexpr <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>(<a href='doc_optional.md#tl::nullopt_t'>do_not_use</a>, <a href='doc_optional.md#tl::nullopt_t'>do_not_use</a>) noexcept;
};</code></pre>

A tag type to represent an empty optional

## Variable `tl::nullopt`<a id="tl::nullopt"></a>

<pre><code class="language-cpp">static constexpr nullopt_t nullopt;</code></pre>

Represents an empty optional

*Examples*:

    tl::optional<int> a = tl::nullopt;
    void foo (tl::optional<int>);
    foo(tl::nullopt); //pass an empty optional

## Comparison operator `tl::operator==`<a id="tl::operator==(constoptional-T-&,constoptional-U-&)"></a>

<pre><code class="language-cpp">(1)  template &lt;class T, class U&gt;
     constexpr bool operator==(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(2)  template &lt;class T, class U&gt;
     constexpr bool operator!=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(3)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(4)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(5)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);

(6)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);</code></pre>

Compares two optional objects

If both optionals contain a value, they are compared with `T`s relational operators. Otherwise `lhs` and `rhs` are equal only if they are both empty, and `lhs` is less than `rhs` only if `rhs` is empty and `lhs` is not.

## Comparison operator `tl::operator==`<a id="tl::operator==(constoptional-T-&,tl::nullopt_t)"></a>

<pre><code class="language-cpp">(1)  template &lt;class T&gt;
     constexpr bool operator==(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;

(2)  template &lt;class T&gt;
     constexpr bool operator==(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;

(3)  template &lt;class T&gt;
     constexpr bool operator!=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;

(4)  template &lt;class T&gt;
     constexpr bool operator!=(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;

(5)  template &lt;class T&gt;
     constexpr bool operator&lt;(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;

(6)  template &lt;class T&gt;
     constexpr bool operator&lt;(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;

(7)  template &lt;class T&gt;
     constexpr bool operator&lt;=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;

(8)  template &lt;class T&gt;
     constexpr bool operator&lt;=(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;

(9)  template &lt;class T&gt;
     constexpr bool operator&gt;(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;

(10)  template &lt;class T&gt;
     constexpr bool operator&gt;(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;

(11)  template &lt;class T&gt;
     constexpr bool operator&gt;=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;

(12)  template &lt;class T&gt;
     constexpr bool operator&gt;=(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;</code></pre>

Compares an optional to a `nullopt`

Equivalent to comparing the optional to an empty optional

## Comparison operator `tl::operator==`<a id="tl::operator==(constoptional-T-&,constU&)"></a>

<pre><code class="language-cpp">(1)  template &lt;class T, class U&gt;
     constexpr bool operator==(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(2)  template &lt;class T, class U&gt;
     constexpr bool operator==(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(3)  template &lt;class T, class U&gt;
     constexpr bool operator!=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(4)  template &lt;class T, class U&gt;
     constexpr bool operator!=(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(5)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(6)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(7)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(8)  template &lt;class T, class U&gt;
     constexpr bool operator&lt;=(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(9)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(10)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);

(11)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;=(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);

(12)  template &lt;class T, class U&gt;
     constexpr bool operator&gt;=(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);</code></pre>

Compares the optional with a value.

If the optional has a value, it is compared with the other value using `T`s relational operators. Otherwise, the optional is considered less than the value.

-----

## Class template `tl::optional`<a id="tl::optional-T-"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
class optional
{
public:
    using <a href='doc_optional.md#tl::optional-T-'>value_type</a> = T;
    
    constexpr <a href='doc_optional.md#tl::optional-T-::optional()'>optional</a>() noexcept = default;
    
    constexpr <a href='doc_optional.md#tl::optional-T-::optional(tl::nullopt_t)'>optional</a>(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;
    
    constexpr <a href='doc_optional.md#tl::optional-T-::optional(constoptional-T-&)'>optional</a>(const <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; rhs);
    
    constexpr <a href='doc_optional.md#tl::optional-T-::optional(optional-T-&&)'>optional</a>(<a href='doc_optional.md#tl::optional-T-'>optional</a>&amp;&amp; rhs) noexcept(std::is_nothrow_move_constructible&lt;T&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>('hidden', Args&amp;&amp;... args);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>('hidden', <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args);
    
    template &lt;class U = T, 'hidden', 'hidden'&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(U&amp;&amp; u);
    
    template &lt;class U = T, 'hidden', 'hidden'&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(U&amp;&amp; u);
    
    template &lt;class U, 'hidden', 'hidden'&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class U, 'hidden', 'hidden'&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class U, 'hidden', 'hidden'&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>(<a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp;&amp; rhs);
    
    template &lt;class U, 'hidden', 'hidden'&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>(<a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp;&amp; rhs);
    
    <a href='doc_optional.md#tl::optional-T-'>~optional</a>() = default;
    
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;
    
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; rhs);
    
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(<a href='doc_optional.md#tl::optional-T-'>optional</a>&amp;&amp; rhs) noexcept(std::is_nothrow_move_assignable&lt;T&gt;::value&amp;&amp;std::is_nothrow_move_constructible&lt;T&gt;::value);
    
    template &lt;class U = T, 'hidden'&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(U&amp;&amp; u);
    
    template &lt;class U, 'hidden'&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class U, 'hidden'&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(<a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp;&amp; rhs);
    
    template &lt;class ... Args&gt;
    T&amp; <a href='doc_optional.md#tl::optional-T-'>emplace</a>(Args&amp;&amp;... args);
    
    template &lt;class U, class ... Args&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-'>emplace</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args);
    
    void <a href='doc_optional.md#tl::optional-T-'>swap</a>(<a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; rhs) noexcept(std::is_nothrow_move_constructible&lt;T&gt;::value&amp;&amp;detail::is_nothrow_swappable&lt;T&gt;::value);
    
    constexpr const T* <a href='doc_optional.md#tl::optional-T-'>operator-&gt;</a>() const;
    
    constexpr T* <a href='doc_optional.md#tl::optional-T-'>operator-&gt;</a>();
    
    constexpr const T&amp; <a href='doc_optional.md#tl::optional-T-'>operator*</a>() const &amp;;
    
    constexpr T&amp; <a href='doc_optional.md#tl::optional-T-'>operator*</a>() &amp;;
    
    constexpr T&amp;&amp; <a href='doc_optional.md#tl::optional-T-'>operator*</a>() &amp;&amp;;
    
    constexpr const T&amp;&amp; <a href='doc_optional.md#tl::optional-T-'>operator*</a>() const &amp;&amp;;
    
    constexpr <a href='doc_optional.md#tl::optional-T-'>operator bool</a>() const noexcept;
    
    constexpr bool <a href='doc_optional.md#tl::optional-T-'>has_value</a>() const noexcept;
    
    constexpr const T&amp; <a href='doc_optional.md#tl::optional-T-'>value</a>() const &amp;;
    
    constexpr T&amp; <a href='doc_optional.md#tl::optional-T-'>value</a>() &amp;;
    
    constexpr T&amp;&amp; <a href='doc_optional.md#tl::optional-T-'>value</a>() &amp;&amp;;
    
    constexpr const T&amp;&amp; <a href='doc_optional.md#tl::optional-T-'>value</a>() const &amp;&amp;;
    
    template &lt;class U&gt;
    constexpr T <a href='doc_optional.md#tl::optional-T-'>value_or</a>(U&amp;&amp; u) const &amp;;
    
    template &lt;class U&gt;
    constexpr T <a href='doc_optional.md#tl::optional-T-'>value_or</a>(U&amp;&amp; u) &amp;&amp;;
    
    void <a href='doc_optional.md#tl::optional-T-'>reset</a>() noexcept;
    
    template &lt;class F&gt;
    constexpr 'hidden' <a href='doc_optional.md#tl::optional-T-::and_then(F&&)&'>and_then</a>(F&amp;&amp; f) &amp;;
    template &lt;class F&gt;
    constexpr 'hidden' <a href='doc_optional.md#tl::optional-T-::and_then(F&&)&'>and_then</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F&gt;
    constexpr 'hidden' <a href='doc_optional.md#tl::optional-T-::and_then(F&&)&&'>and_then</a>(F&amp;&amp; f) &amp;&amp;;
    template &lt;class F&gt;
    constexpr 'hidden' <a href='doc_optional.md#tl::optional-T-::and_then(F&&)&&'>and_then</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F&gt; auto map(F &amp;&amp;f) &amp;;
    template &lt;class F&gt; auto map(F &amp;&amp;f) const &amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) &amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) &amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) &amp;;
    
    template &lt;class F&gt; auto map(F &amp;&amp;f) &amp;;
    template &lt;class F&gt; auto map(F &amp;&amp;f) const &amp;&amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) &amp;&amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) &amp;&amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) &amp;&amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    constexpr 'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    constexpr 'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F, 'hidden', 'hidden'&gt;
    'hidden' <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;;
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;;
    
    template &lt;class F, 'hidden'&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#tl::optional-T-::or_else(F&&)&'>or_else</a>(F&amp;&amp; f) &amp;;
    
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;&amp;;
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;&amp;;
    
    template &lt;class F, 'hidden'&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#tl::optional-T-::or_else(F&&)&&'>or_else</a>(F&amp;&amp; f) &amp;&amp;;
    
    template &lt;class F, 'hidden'&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#tl::optional-T-::or_else(F&&)&'>or_else</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F, 'hidden'&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#tl::optional-T-::or_else(F&&)&&'>or_else</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-::map_or(F&&,U&&)&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-::map_or(F&&,U&&)&&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-::map_or(F&&,U&&)&&'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-::map_or_else(F&&,U&&)&'>map_or_else</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-::map_or_else(F&&,U&&)&'>map_or_else</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-::map_or_else(F&&,U&&)&&'>map_or_else</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-::map_or_else(F&&,U&&)&&'>map_or_else</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;
};</code></pre>

An optional object is an object that contains the storage for another object and manages the lifetime of this contained object, if any. The contained object may be initialized after the optional object has been initialized, and may be destroyed before the optional object has been destroyed. The initialization state of the contained object is tracked by the optional object.

### Default constructor `tl::optional::optional`<a id="tl::optional-T-::optional()"></a>

<pre><code class="language-cpp">constexpr optional() noexcept = default;</code></pre>

Constructs an optional that does not contain a value.

### Constructor `tl::optional::optional`<a id="tl::optional-T-::optional(tl::nullopt_t)"></a>

<pre><code class="language-cpp">constexpr optional(<a href='doc_optional.md#tl::nullopt_t'>nullopt_t</a>) noexcept;</code></pre>

Constructs an optional that does not contain a value.

### Constructor `tl::optional::optional`<a id="tl::optional-T-::optional(constoptional-T-&)"></a>

<pre><code class="language-cpp">constexpr optional(const <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; rhs);</code></pre>

Copy constructor

If `rhs` contains a value, the stored value is direct-initialized with it. Otherwise, the constructed optional is empty.

### Constructor `tl::optional::optional`<a id="tl::optional-T-::optional(optional-T-&&)"></a>

<pre><code class="language-cpp">constexpr optional(<a href='doc_optional.md#tl::optional-T-'>optional</a>&amp;&amp; rhs) noexcept(std::is_nothrow_move_constructible&lt;T&gt;::value);</code></pre>

Move constructor

If `rhs` contains a value, the stored value is direct-initialized with it. Otherwise, the constructed optional is empty.

### Function template `tl::optional::and_then`<a id="tl::optional-T-::and_then(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt;
     constexpr 'hidden' and_then(F&amp;&amp; f) &amp;;

(2)  template &lt;class F&gt;
     constexpr 'hidden' and_then(F&amp;&amp; f) const &amp;;</code></pre>

Carries out some operation which returns an optional on the stored object if there is one.

*Requires*: `std::invoke(std::forward<F>(f), value())` returns a `std::optional<U>` for some `U`.

*Returns*: Let `U` be the result of `std::invoke(std::forward<F>(f), value())`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise the return value of `std::invoke(std::forward<F>(f), value())` is returned.

### Function template `tl::optional::and_then`<a id="tl::optional-T-::and_then(F&&)&&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt;
     constexpr 'hidden' and_then(F&amp;&amp; f) &amp;&amp;;

(2)  template &lt;class F&gt;
     constexpr 'hidden' and_then(F&amp;&amp; f) const &amp;&amp;;</code></pre>

Carries out some operation which returns an optional on the stored object if there is one.

*Requires*: `std::invoke(std::forward<F>(f), std::move(value()))` returns a `std::optional<U>` for some `U`.

*Returns*: Let `U` be the result of `std::invoke(std::forward<F>(f), std::move(value()))`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise the return value of `std::invoke(std::forward<F>(f), std::move(value()))` is returned.

### Function template `tl::optional::map`<a id="tl::optional-T-::map(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt; auto map(F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt; auto map(F &amp;&amp;f) const &amp;;</code></pre>

Carries out some operation on the stored object if there is one.

*Returns*: Let `U` be the result of `std::invoke(std::forward<F>(f), value())`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise an `optional<U>` is constructed from the return value of `std::invoke(std::forward<F>(f), value())` and is returned.

### Function template `tl::optional::map`<a id="tl::optional-T-::map(F&&)&&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt; auto map(F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt; auto map(F &amp;&amp;f) const &amp;&amp;;</code></pre>

Carries out some operation on the stored object if there is one.

*Returns*: Let `U` be the result of `std::invoke(std::forward<F>(f), std::move(value()))`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise an `optional<U>` is constructed from the return value of `std::invoke(std::forward<F>(f), std::move(value()))` and is returned.

### Function template `tl::optional::or_else`<a id="tl::optional-T-::or_else(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;;

(2)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;;</code></pre>

Calls `f` if the optional is empty

*Requires*: `std::invoke_result_t<F>` must be void or convertible to `optional<T>`.

*Effects*: If `*this` has a value, returns `*this`. Otherwise, if `f` returns `void`, calls `std::forward<F>(f)` and returns `std::nullopt`. Otherwise, returns `std::forward<F>(f)()`.

### Function template `tl::optional::or_else`<a id="tl::optional-T-::or_else(F&&)&&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;&amp;;

(2)  template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;&amp;;</code></pre>

Calls `f` if the optional is empty

*Requires*: `std::invoke_result_t<F>` must be void or convertible to `optional<T>`.

*Effects*: If `*this` has a value, returns `std::move(*this)`. Otherwise, if `f` returns `void`, calls `std::forward<F>(f)` and returns `std::nullopt`. Otherwise, returns `std::forward<F>(f)()`.

### Function template `tl::optional::map_or`<a id="tl::optional-T-::map_or(F&&,U&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) &amp;;

(2)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) const &amp;;</code></pre>

Maps the stored value with `f` if there is one, otherwise returns `u`

If there is a value stored, then `f` is called with `**this` and the value is returned. Otherwise `u` is returned.

### Function template `tl::optional::map_or`<a id="tl::optional-T-::map_or(F&&,U&&)&&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;

(2)  template &lt;class F, class U&gt;
     U map_or(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;</code></pre>

Maps the stored value with `f` if there is one, otherwise returns `u`

If there is a value stored, then `f` is called with `std::move(**this)` and the value is returned. Otherwise `u` is returned.

### Function template `tl::optional::map_or_else`<a id="tl::optional-T-::map_or_else(F&&,U&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F, class U&gt;
     U map_or_else(F&amp;&amp; f, U&amp;&amp; u) &amp;;

(2)  template &lt;class F, class U&gt;
     U map_or_else(F&amp;&amp; f, U&amp;&amp; u) const &amp;;</code></pre>

Maps the stored value with `f` if there is one, otherwise calls `u` and returns the result.

If there is a value stored, then `f` is called with `**this` and the value is returned. Otherwise `std::forward<U>(u)()` is returned.

### Function template `tl::optional::map_or_else`<a id="tl::optional-T-::map_or_else(F&&,U&&)&&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F, class U&gt;
     U map_or_else(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;

(2)  template &lt;class F, class U&gt;
     U map_or_else(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;</code></pre>

Maps the stored value with `f` if there is one, otherwise calls `u` and returns the result.

If there is a value stored, then `f` is called with `std::move(**this)` and the value is returned. Otherwise `std::forward<U>(u)()` is returned.

-----

-----
