#ifndef BOOST_RANGE_ADAPTOR_TAPPED_INCLUDE
#define BOOST_RANGE_ADAPTOR_TAPPED_INCLUDE

// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Akira Takahashi 2011-2012.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "./detail/tap_iterator.hpp"
#include <boost/concept_check.hpp>
#include <boost/range/concepts.hpp>
#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_const.hpp>
#include <boost/range/adaptor/argument_fwd.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/range/regular.hpp>
#include <boost/range/adaptor/regular_operator.hpp>
#include <boost/range/adaptor/memoized.hpp>

namespace boost {
namespace range_detail {

template <class UnaryFunction, class ForwardRng>
struct tapped_range_base {
    typedef
        typename boost::mpl::if_<
            boost::is_const<ForwardRng>,
            const memoized_range<const ForwardRng>,
            memoized_range<ForwardRng>
        >::type
    base_range;

    typedef
        iterator_range<
            boost::adaptors::detail::tap_iterator<
                UnaryFunction,
                typename range_iterator<base_range>::type
            >
        >
    type;
};

template <class UnaryFunction, class ForwardRng>
struct tapped_range : tapped_range_base<UnaryFunction, ForwardRng>::type {
    typedef
        tapped_range_base<UnaryFunction, ForwardRng>
    base_traits;

    typedef typename base_traits::type base;
    typedef typename base_traits::base_range base_range;
    typedef typename base::iterator iterator;

    BOOST_RANGE_CONCEPT_ASSERT((ForwardRangeConcept<ForwardRng>));

    tapped_range(UnaryFunction f, base_range rng)
        : base(iterator(f, boost::begin(rng), boost::end(rng)), iterator(boost::end(rng)))
    {}
};

template <class T>
struct tap_holder : holder<T> {
    tap_holder(T r) : holder<T>(r) {}
};

template <class ForwardRng, class UnaryFunction>
inline tapped_range<UnaryFunction, ForwardRng>
    operator|(ForwardRng& rng, const tap_holder<UnaryFunction>& f)
{
    return tapped_range<UnaryFunction, ForwardRng>
                       (f.val, rng | boost::adaptors::memoized);
}

template <class ForwardRng, class UnaryFunction>
inline tapped_range<UnaryFunction, const ForwardRng>
    operator|(const ForwardRng& rng, const tap_holder<UnaryFunction>& f)
{
    return tapped_range<UnaryFunction, const ForwardRng>
                       (f.val, rng | boost::adaptors::memoized);
}


BOOST_RANGE_ADAPTOR_MAKE_REGULAR_OPERATOR(tap_holder);

} // namespace range_detail

namespace adaptors {

using range_detail::tapped_range;

namespace
{
    const range_detail::forwarder<range_detail::tap_holder>
            tapped =
              range_detail::forwarder<range_detail::tap_holder>();
}


template <class ForwardRng, class UnaryFunction>
inline tapped_range<UnaryFunction, ForwardRng>
    tap(ForwardRng& rng, UnaryFunction f)
{
    return rng | tapped(f);
}

template <class ForwardRng, class UnaryFunction>
inline tapped_range<UnaryFunction, const ForwardRng>
    tap(const ForwardRng& rng, UnaryFunction f)
{
    return rng | tapped(f);
}

}} // namespace boost::adaptors

#endif // BOOST_RANGE_ADAPTOR_TAPPED_INCLUDE

