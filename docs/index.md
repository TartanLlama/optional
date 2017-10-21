# Header file `optional.hpp`<a id="optional.hpp"></a>

<pre><code class="language-cpp">#define <a href='doc_optional.md#optional.hpp'>TL_OPTIONAL_11_CONSTEXPR</a>

#define <a href='doc_optional.md#optional.hpp'>TL_OPTIONAL_MSVC_2015_CONSTEXPR</a>

namespace <a href='doc_optional.md#optional.hpp'>tl</a>
{
    class <a href='doc_optional.md#optional.hpp'>monostate</a>;
    
    namespace <a href='doc_optional.md#optional.hpp'>detail</a>
    {
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>remove_cv_t</a> = typename std::remove_cv&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>remove_const_t</a> = typename std::remove_const&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>remove_volatile_t</a> = typename std::remove_volatile&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>add_cv_t</a> = typename std::add_cv&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>add_const_t</a> = typename std::add_const&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>add_volatile_t</a> = typename std::add_volatile&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>remove_reference_t</a> = typename std::remove_reference&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>add_lvalue_reference_t</a> = typename std::add_lvalue_reference&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>add_rvalue_reference_t</a> = typename std::add_rvalue_reference&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>remove_pointer_t</a> = typename std::remove_pointer&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>add_pointer_t</a> = typename std::add_pointer&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>make_signed_t</a> = typename std::make_signed&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>make_unsigned_t</a> = typename std::make_unsigned&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>remove_extent_t</a> = typename std::remove_extent&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>remove_all_extents_t</a> = typename std::remove_all_extents&lt;T&gt;::type;
        
        template &lt;<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::size_t'>std::size_t</a> N, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::size_t'>std::size_t</a> A = N&gt;
        using <a href='doc_optional.md#optional.hpp'>aligned_storage_t</a> = typename std::aligned_storage&lt;N, A&gt;::type;
        
        template &lt;<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::size_t'>std::size_t</a> N, class ... Ts&gt;
        using <a href='doc_optional.md#optional.hpp'>aligned_union_t</a> = typename std::aligned_union&lt;N, Ts...&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>decay_t</a> = typename std::decay&lt;T&gt;::type;
        
        template &lt;bool E, class T = void&gt;
        using <a href='doc_optional.md#optional.hpp'>enable_if_t</a> = typename std::enable_if&lt;E, T&gt;::type;
        
        template &lt;bool B, class T, class F&gt;
        using <a href='doc_optional.md#optional.hpp'>conditional_t</a> = typename std::conditional&lt;B, T, F&gt;::type;
        
        template &lt;class ... Ts&gt;
        using <a href='doc_optional.md#optional.hpp'>common_type_t</a> = typename std::common_type&lt;Ts...&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>underlying_type_t</a> = typename std::underlying_type&lt;T&gt;::type;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>result_of_t</a> = typename std::result_of&lt;T&gt;::type;
        
        template &lt;class&gt;
        struct <a href='doc_optional.md#optional.hpp'>conjunction</a>;
        
        template &lt;class B&gt;
        struct <a href='doc_optional.md#optional.hpp'>conjunction&lt;B&gt;</a>;
        
        template &lt;class B, class ... Bs&gt;
        struct <a href='doc_optional.md#optional.hpp'>conjunction&lt;B, Bs...&gt;</a>;
        
        template &lt;class&gt;
        struct <a href='doc_optional.md#optional.hpp'>voider</a>;
        
        template &lt;class ... Ts&gt;
        using <a href='doc_optional.md#optional.hpp'>void_t</a> = typename voider&lt;Ts...&gt;::type;
        
        template &lt;class T&gt;
        struct <a href='doc_optional.md#optional.hpp'>is_optional_impl</a>;
        
        template &lt;class T&gt;
        struct <a href='doc_optional.md#optional.hpp'>is_optional_impl&lt;optional&lt;T&gt;&gt;</a>;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>is_optional</a> = <a href='doc_optional.md#optional.hpp'>is_optional_impl&lt;decay_t&lt;T&gt;&gt;</a>;
        
        template &lt;typename Fn, typename ... Args, typename = enable_if_t&lt;std::is_member_pointer&lt;decay_t&lt;Fn&gt;&gt;{}&gt;, int=0&gt;
        constexpr decltype(std::mem_fn(f)(std::forward&lt;Args&gt;(args)...)) <a href='doc_optional.md#optional.hpp'>invoke</a>(Fn&amp;&amp; f, Args&amp;&amp;... args) noexcept(noexcept(std::mem_fn(f)(std::forward&lt;Args&gt;(args)...)));
        
        template &lt;typename Fn, typename ... Args, typename = enable_if_t&lt;!std::is_member_pointer&lt;decay_t&lt;Fn&gt;&gt;{}&gt;&gt;
        constexpr decltype(std::forward&lt;Fn&gt;(f)(std::forward&lt;Args&gt;(args)...)) <a href='doc_optional.md#optional.hpp'>invoke</a>(Fn&amp;&amp; f, Args&amp;&amp;... args) noexcept(noexcept(std::forward&lt;Fn&gt;(f)(std::forward&lt;Args&gt;(args)...)));
        
        template &lt;class F, class ... Us&gt;
        struct <a href='doc_optional.md#optional.hpp'>invoke_result_impl&lt;F, decltype(invoke(std::declval&lt;F&gt;(), std::declval&lt;Us&gt;()...), void()), Us...&gt;</a>;
        
        template &lt;class F, class ... Us&gt;
        using <a href='doc_optional.md#optional.hpp'>invoke_result</a> = invoke_result_impl&lt;F, void, Us...&gt;;
        
        template &lt;class F, class ... Us&gt;
        using <a href='doc_optional.md#optional.hpp'>invoke_result_t</a> = typename invoke_result&lt;F, Us...&gt;::type;
        
        template &lt;class U&gt;
        using <a href='doc_optional.md#optional.hpp'>fixup_void</a> = <a href='doc_optional.md#optional.hpp'>conditional_t&lt;std::is_void&lt;U&gt;::value, monostate, U&gt;</a>;
        
        template &lt;class F, class ... U&gt;
        struct <a href='doc_optional.md#optional.hpp'>get_invoke_optional_ret</a>;
        
        template &lt;class F, class ... U&gt;
        using <a href='doc_optional.md#optional.hpp'>get_invoke_ret</a> = typename conditional_t&lt;is_optional&lt;F&gt;::value, get_invoke_optional_ret&lt;F, U...&gt;, invoke_result&lt;F, U...&gt;&gt;::type;
        
        template &lt;class F, class U&gt;
        using <a href='doc_optional.md#optional.hpp'>get_map_return</a> = <a href='doc_optional.md#tl::optional-T-'>optional&lt;fixup_void&lt;get_invoke_ret&lt;F, U&gt;&gt;&gt;</a>;
        
        template &lt;class F, class ... U&gt;
        using <a href='doc_optional.md#optional.hpp'>returns_void</a> = <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::is_void%3cget_invoke_ret%3cF,U...%3e%3e'>std::is_void&lt;get_invoke_ret&lt;F, U...&gt;&gt;</a>;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>disable_if_optional</a> = <a href='doc_optional.md#optional.hpp'>enable_if_t&lt;!is_optional&lt;T&gt;::value&gt;</a>;
        
        template &lt;class T&gt;
        using <a href='doc_optional.md#optional.hpp'>enable_if_optional</a> = <a href='doc_optional.md#optional.hpp'>enable_if_t&lt;is_optional&lt;T&gt;::value&gt;</a>;
        
        template &lt;class T, class ... U&gt;
        using <a href='doc_optional.md#optional.hpp'>enable_if_ret_void</a> = <a href='doc_optional.md#optional.hpp'>enable_if_t&lt;returns_void&lt;T&amp;&amp;, U...&gt;::value&gt;</a>;
        
        template &lt;class T, class ... U&gt;
        using <a href='doc_optional.md#optional.hpp'>disable_if_ret_void</a> = <a href='doc_optional.md#optional.hpp'>enable_if_t&lt;!returns_void&lt;T&amp;&amp;, U...&gt;::value&gt;</a>;
    }
    
    struct <a href='doc_optional.md#optional.hpp'>in_place_t</a>;
    
    constexpr <a href='doc_optional.md#optional.hpp'>in_place_t{}</a> <a href='doc_optional.md#optional.hpp'>in_place</a>;
    
    namespace <a href='doc_optional.md#optional.hpp'>detail</a>
    {
        template &lt;class T, class U&gt;
        using <a href='doc_optional.md#optional.hpp'>enable_forward_value</a> = <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_constructible&lt;T, U&amp;&amp;&gt;::value&amp;&amp;!std::is_same&lt;detail::decay_t&lt;U&gt;, in_place_t&gt;::value&amp;&amp;!std::is_same&lt;optional&lt;T&gt;, detail::decay_t&lt;U&gt;&gt;::value&gt;</a>;
        
        template &lt;class T, class U, class Other&gt;
        using <a href='doc_optional.md#optional.hpp'>enable_from_other</a> = <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_constructible&lt;T, Other&gt;::value&amp;&amp;!std::is_constructible&lt;T, optional&lt;U&gt;&amp;&gt;::value&amp;&amp;!std::is_constructible&lt;T, optional&lt;U&gt;&amp;&amp;&gt;::value&amp;&amp;!std::is_constructible&lt;T, const optional&lt;U&gt;&amp;&gt;::value&amp;&amp;!std::is_constructible&lt;T, const optional&lt;U&gt;&amp;&amp;&gt;::value&amp;&amp;!std::is_convertible&lt;optional&lt;U&gt;&amp;, T&gt;::value&amp;&amp;!std::is_convertible&lt;optional&lt;U&gt;&amp;&amp;, T&gt;::value&amp;&amp;!std::is_convertible&lt;const optional&lt;U&gt;&amp;, T&gt;::value&amp;&amp;!std::is_convertible&lt;const optional&lt;U&gt;&amp;&amp;, T&gt;::value&gt;</a>;
        
        template &lt;class T, class U&gt;
        using <a href='doc_optional.md#optional.hpp'>enable_assign_forward</a> = <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;!std::is_same&lt;optional&lt;T&gt;, detail::decay_t&lt;U&gt;&gt;::value&amp;&amp;!detail::conjunction&lt;std::is_scalar&lt;T&gt;, std::is_same&lt;T, detail::decay_t&lt;U&gt;&gt;&gt;::value&amp;&amp;std::is_constructible&lt;T, U&gt;::value&amp;&amp;std::is_assignable&lt;T&amp;, U&gt;::value&gt;</a>;
        
        template &lt;class T, class U, class Other&gt;
        using <a href='doc_optional.md#optional.hpp'>enable_assign_from_other</a> = <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_constructible&lt;T, Other&gt;::value&amp;&amp;std::is_assignable&lt;T&amp;, Other&gt;::value&amp;&amp;!std::is_constructible&lt;T, optional&lt;U&gt;&amp;&gt;::value&amp;&amp;!std::is_constructible&lt;T, optional&lt;U&gt;&amp;&amp;&gt;::value&amp;&amp;!std::is_constructible&lt;T, const optional&lt;U&gt;&amp;&gt;::value&amp;&amp;!std::is_constructible&lt;T, const optional&lt;U&gt;&amp;&amp;&gt;::value&amp;&amp;!std::is_convertible&lt;optional&lt;U&gt;&amp;, T&gt;::value&amp;&amp;!std::is_convertible&lt;optional&lt;U&gt;&amp;&amp;, T&gt;::value&amp;&amp;!std::is_convertible&lt;const optional&lt;U&gt;&amp;, T&gt;::value&amp;&amp;!std::is_convertible&lt;const optional&lt;U&gt;&amp;&amp;, T&gt;::value&amp;&amp;!std::is_assignable&lt;T&amp;, optional&lt;U&gt;&amp;&gt;::value&amp;&amp;!std::is_assignable&lt;T&amp;, optional&lt;U&gt;&amp;&amp;&gt;::value&amp;&amp;!std::is_assignable&lt;T&amp;, const optional&lt;U&gt;&amp;&gt;::value&amp;&amp;!std::is_assignable&lt;T&amp;, const optional&lt;U&gt;&amp;&amp;&gt;::value&gt;</a>;
        
        namespace <a href='doc_optional.md#optional.hpp'>swap_adl_tests</a>
        {
            struct <a href='doc_optional.md#optional.hpp'>tag</a>;
            
            template &lt;class T&gt;
            <a href='doc_optional.md#optional.hpp'>tag</a> <a href='doc_optional.md#optional.hpp'>swap</a>(T&amp;, T&amp;);
            
            template &lt;class T, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::size_t'>std::size_t</a> N&gt;
            <a href='doc_optional.md#optional.hpp'>tag</a> <a href='doc_optional.md#optional.hpp'>swap</a>(T(&amp;)[N] a, T(&amp;)[N] b);
            
            template &lt;class, class&gt;
            <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::false_type'>std::false_type</a> <a href='doc_optional.md#optional.hpp'>can_swap</a>(...) noexcept(false);
            
            template &lt;class T, class U, class = decltype(swap(std::declval&lt;T&amp;&gt;(), std::declval&lt;U&amp;&gt;()))&gt;
            )&gt;std::true_type <a href='doc_optional.md#optional.hpp'>can_swap</a>(int) noexcept(noexcept(swap(std::declval&lt;T&amp;&gt;(), std::declval&lt;U&amp;&gt;())));
            
            template &lt;class, class&gt;
            <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::false_type'>std::false_type</a> <a href='doc_optional.md#optional.hpp'>uses_std</a>(...);
            
            template &lt;class T, class U&gt;
            <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::is_same%3cdecltype(swap(std::declval%3cT&%3e(),std::declval%3cU&%3e())),tag%3e'>std::is_same&lt;decltype(swap(std::declval&lt;T&amp;&gt;(), std::declval&lt;U&amp;&gt;())), tag&gt;</a> <a href='doc_optional.md#optional.hpp'>uses_std</a>(int);
            
            template &lt;class T&gt;
            struct <a href='doc_optional.md#optional.hpp'>is_std_swap_noexcept</a>;
            
            template &lt;class T, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::size_t'>std::size_t</a> N&gt;
            struct <a href='doc_optional.md#optional.hpp'>is_std_swap_noexcept&lt;T[N]&gt;</a>;
            
            template &lt;class T, class U&gt;
            struct <a href='doc_optional.md#optional.hpp'>is_adl_swap_noexcept</a>;
        }
        
        template &lt;class T, class U = T&gt;
        struct <a href='doc_optional.md#optional.hpp'>is_swappable</a>;
        
        template &lt;class T, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::size_t'>std::size_t</a> N&gt;
        struct <a href='doc_optional.md#optional.hpp'>is_swappable&lt;T[N], T[N]&gt;</a>;
        
        template &lt;class T, class U = T&gt;
        struct <a href='doc_optional.md#optional.hpp'>is_nothrow_swappable</a>;
    }
    
    struct <a href='doc_optional.md#optional.hpp'>nullopt_t</a>;
    
    constexpr <a href='doc_optional.md#optional.hpp'>nullopt_t{nullopt_t::do_not_use{}, nullopt_t::do_not_use{}}</a> <a href='doc_optional.md#optional.hpp'>nullopt</a>;
    
    class <a href='doc_optional.md#optional.hpp'>bad_optional_access</a>;
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator==</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator!=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator==</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#optional.hpp'>nullopt_t</a>) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator==</a>(<a href='doc_optional.md#optional.hpp'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator!=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#optional.hpp'>nullopt_t</a>) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator!=</a>(<a href='doc_optional.md#optional.hpp'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.md#optional.hpp'>nullopt_t</a>) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;</a>(<a href='doc_optional.md#optional.hpp'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#optional.hpp'>nullopt_t</a>) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;=</a>(<a href='doc_optional.md#optional.hpp'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#optional.hpp'>nullopt_t</a>) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;</a>(<a href='doc_optional.md#optional.hpp'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp;, <a href='doc_optional.md#optional.hpp'>nullopt_t</a>) noexcept;
    
    template &lt;class T&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;=</a>(<a href='doc_optional.md#optional.hpp'>nullopt_t</a>, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept;
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator==</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator==</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator!=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator!=</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&lt;=</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, const U&amp; rhs);
    
    template &lt;class T, class U&gt;
    constexpr bool <a href='doc_optional.md#optional.hpp'>operator&gt;=</a>(const U&amp; lhs, const <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs);
    
    template &lt;class T, <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_move_constructible&lt;T&gt;::value&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;detail::is_swappable&lt;T&gt;::value&gt;*=nullptr</a>&gt;
    void <a href='doc_optional.md#optional.hpp'>swap</a>(<a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; lhs, <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a>&amp; rhs) noexcept(noexcept(lhs.swap(rhs)));
    
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
    namespace <a href='doc_optional.md#optional.hpp'>detail</a>
    {
        template &lt;class T, bool=::std::is_trivially_destructible&lt;T&gt;::value&gt;
        struct <a href='doc_optional.md#optional.hpp'>optional_storage_base</a>;
        
        template &lt;class T&gt;
        struct <a href='doc_optional.md#optional.hpp'>optional_storage_base&lt;T, true&gt;</a>;
    }
    
    template &lt;class T&gt;
    class <a href='doc_optional.md#tl::optional-T-'>optional</a>;
}</code></pre>

-----

-----

## Class template `tl::optional`<a id="tl::optional-T-"></a>

<pre><code class="language-cpp">template &lt;class T&gt;
class optional
{
public:
    using <a href='doc_optional.md#tl::optional-T-'>value_type</a> = T;
    
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>() noexcept = default;
    
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(<a href='doc_optional.md#optional.hpp'>nullopt_t</a>) noexcept;
    
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(const <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; rhs);
    
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(<a href='doc_optional.md#tl::optional-T-'>optional</a>&amp;&amp; rhs) noexcept(std::is_nothrow_move_constructible&lt;T&gt;::value);
    
    template &lt;class ... Args&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(<a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_constructible&lt;T, Args...&gt;::value, in_place_t&gt;</a>, Args&amp;&amp;... args);
    
    template &lt;class U, class ... Args&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(<a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_constructible&lt;T, std::initializer_list&lt;U&gt;&amp;, Args&amp;&amp;...&gt;::value, in_place_t&gt;</a>, <a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args);
    
    template &lt;class U = T, <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_convertible&lt;U&amp;&amp;, T&gt;::value&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_forward_value&lt;T, U&gt;*=nullptr</a>&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(U&amp;&amp; u);
    
    template &lt;class U = T, <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;!std::is_convertible&lt;U&amp;&amp;, T&gt;::value&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_forward_value&lt;T, U&gt;*=nullptr</a>&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional</a>(U&amp;&amp; u);
    
    template &lt;class U, <a href='doc_optional.md#optional.hpp'>detail::enable_from_other&lt;T, U, const U&amp;&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_convertible&lt;const U&amp;, T&gt;::value&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class U, <a href='doc_optional.md#optional.hpp'>detail::enable_from_other&lt;T, U, const U&amp;&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;!std::is_convertible&lt;const U&amp;, T&gt;::value&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class U, <a href='doc_optional.md#optional.hpp'>detail::enable_from_other&lt;T, U, U&amp;&amp;&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_convertible&lt;U&amp;&amp;, T&gt;::value&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>(<a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp;&amp; rhs);
    
    template &lt;class U, <a href='doc_optional.md#optional.hpp'>detail::enable_from_other&lt;T, U, U&amp;&amp;&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;!std::is_convertible&lt;U&amp;&amp;, T&gt;::value&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>(<a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp;&amp; rhs);
    
    <a href='doc_optional.md#tl::optional-T-'>~optional</a>() = default;
    
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(<a href='doc_optional.md#optional.hpp'>nullopt_t</a>) noexcept;
    
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; rhs);
    
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(<a href='doc_optional.md#tl::optional-T-'>optional</a>&amp;&amp; rhs) noexcept(std::is_nothrow_move_assignable&lt;T&gt;::value&amp;&amp;std::is_nothrow_move_constructible&lt;T&gt;::value);
    
    template &lt;class U = T, <a href='doc_optional.md#optional.hpp'>detail::enable_assign_forward&lt;T, U&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(U&amp;&amp; u);
    
    template &lt;class U, <a href='doc_optional.md#optional.hpp'>detail::enable_assign_from_other&lt;T, U, const U&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(const <a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp; rhs);
    
    template &lt;class U, <a href='doc_optional.md#optional.hpp'>detail::enable_assign_from_other&lt;T, U, U&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional</a>&amp; <a href='doc_optional.md#tl::optional-T-'>operator=</a>(<a href='doc_optional.md#tl::optional-T-'>optional&lt;U&gt;</a>&amp;&amp; rhs);
    
    template &lt;class ... Args&gt;
    T&amp; <a href='doc_optional.md#tl::optional-T-'>emplace</a>(Args&amp;&amp;... args);
    
    template &lt;class U, class ... Args&gt;
    <a href='doc_optional.md#optional.hpp'>detail::enable_if_t&lt;std::is_constructible&lt;T, std::initializer_list&lt;U&gt;&amp;, Args&amp;&amp;...&gt;::value, T&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-'>emplace</a>(<a href='http://en.cppreference.com/mwiki/index.php?title=Special%3ASearch&search=std::initializer_list%3cU%3e'>std::initializer_list&lt;U&gt;</a> il, Args&amp;&amp;... args);
    
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
    constexpr <a href='doc_optional.md#optional.hpp'>detail::invoke_result_t&lt;F, T&gt;</a> <a href='doc_optional.md#tl::optional-T-::and_then(F&&)&'>and_then</a>(F&amp;&amp; f) &amp;;
    template &lt;class F&gt;
    constexpr <a href='doc_optional.md#optional.hpp'>detail::invoke_result_t&lt;F, T&gt;</a> <a href='doc_optional.md#tl::optional-T-::and_then(F&&)&'>and_then</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F&gt;
    constexpr <a href='doc_optional.md#optional.hpp'>detail::invoke_result_t&lt;F, T&gt;</a> <a href='doc_optional.md#tl::optional-T-::and_then(F&&)&&'>and_then</a>(F&amp;&amp; f) &amp;&amp;;
    template &lt;class F&gt;
    constexpr <a href='doc_optional.md#optional.hpp'>detail::invoke_result_t&lt;F, T&gt;</a> <a href='doc_optional.md#tl::optional-T-::and_then(F&&)&&'>and_then</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F&gt; auto map(F &amp;&amp;f) &amp;;
    template &lt;class F&gt; auto map(F &amp;&amp;f) const &amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::disable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_ret_void&lt;F, T&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) &amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::enable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::disable_if_ret_void&lt;F, T&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) &amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::enable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_ret_void&lt;F, T&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) &amp;;
    
    template &lt;class F&gt; auto map(F &amp;&amp;f) &amp;;
    template &lt;class F&gt; auto map(F &amp;&amp;f) const &amp;&amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::disable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_ret_void&lt;F, T&amp;&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T&amp;&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) &amp;&amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::enable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::disable_if_ret_void&lt;F, T&amp;&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T&amp;&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) &amp;&amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::enable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_ret_void&lt;F, T&amp;&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T&amp;&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) &amp;&amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::disable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_ret_void&lt;F, T const&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T const&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::enable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::disable_if_ret_void&lt;F, T const&amp;&gt;*=nullptr</a>&gt;
    constexpr <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T const&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::enable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_ret_void&lt;F, T const&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T const&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&'>map</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::disable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_ret_void&lt;F, T const&amp;&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T const&amp;&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::enable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::disable_if_ret_void&lt;F, T const&amp;&amp;&gt;*=nullptr</a>&gt;
    constexpr <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T const&amp;&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::enable_if_optional&lt;F&gt;*=nullptr</a>, <a href='doc_optional.md#optional.hpp'>detail::enable_if_ret_void&lt;F, T const&amp;&amp;&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#optional.hpp'>detail::get_map_return&lt;F, T&amp;&gt;</a> <a href='doc_optional.md#tl::optional-T-::map(F&&)&&'>map</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;;
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::disable_if_ret_void&lt;F&gt;*=nullptr</a>&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#tl::optional-T-::or_else(F&&)&'>or_else</a>(F&amp;&amp; f) &amp;;
    
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) &amp;&amp;;
    template &lt;class F&gt; optional&lt;T&gt; or_else (F &amp;&amp;f) const &amp;&amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::disable_if_ret_void&lt;F&gt;*=nullptr</a>&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#tl::optional-T-::or_else(F&&)&&'>or_else</a>(F&amp;&amp; f) &amp;&amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::disable_if_ret_void&lt;F&gt;*=nullptr</a>&gt;
    constexpr <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#tl::optional-T-::or_else(F&&)&'>or_else</a>(F&amp;&amp; f) const &amp;;
    
    template &lt;class F, <a href='doc_optional.md#optional.hpp'>detail::disable_if_ret_void&lt;F&gt;*=nullptr</a>&gt;
    <a href='doc_optional.md#tl::optional-T-'>optional&lt;T&gt;</a> <a href='doc_optional.md#tl::optional-T-::or_else(F&&)&&'>or_else</a>(F&amp;&amp; f) const &amp;&amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-'>map_or</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-'>map_or_else</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-'>map_or_else</a>(F&amp;&amp; f, U&amp;&amp; u) &amp;&amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-'>map_or_else</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;;
    
    template &lt;class F, class U&gt;
    U <a href='doc_optional.md#tl::optional-T-'>map_or_else</a>(F&amp;&amp; f, U&amp;&amp; u) const &amp;&amp;;
};</code></pre>

An optional object is an object that contains the storage for another object and manages the lifetime of this contained object, if any. The contained object may be initialized after the optional object has been initialized, and may be destroyed before the optional object has been destroyed. The initialization state of the contained object is tracked by the optional object.

### Function template `tl::optional::and_then`<a id="tl::optional-T-::and_then(F&&)&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt;
     constexpr <a href='doc_optional.md#optional.hpp'>detail::invoke_result_t&lt;F, T&gt;</a> and_then(F&amp;&amp; f) &amp;;

(2)  template &lt;class F&gt;
     constexpr <a href='doc_optional.md#optional.hpp'>detail::invoke_result_t&lt;F, T&gt;</a> and_then(F&amp;&amp; f) const &amp;;</code></pre>

Carries out some operation which returns an optional on the stored object if there is one.

*Requires*: `std::invoke(std::forward<F>(f), value())` returns a `std::optional<U>` for some `U`.

*Returns*: Let `U` be the result of `std::invoke(std::forward<F>(f), value())`. Returns a `std::optional<U>`. The return value is empty if `*this` is empty, otherwise the return value of `std::invoke(std::forward<F>(f), value())` is returned.

### Function template `tl::optional::and_then`<a id="tl::optional-T-::and_then(F&&)&&"></a>

<pre><code class="language-cpp">(1)  template &lt;class F&gt;
     constexpr <a href='doc_optional.md#optional.hpp'>detail::invoke_result_t&lt;F, T&gt;</a> and_then(F&amp;&amp; f) &amp;&amp;;

(2)  template &lt;class F&gt;
     constexpr <a href='doc_optional.md#optional.hpp'>detail::invoke_result_t&lt;F, T&gt;</a> and_then(F&amp;&amp; f) const &amp;&amp;;</code></pre>

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

-----

-----
