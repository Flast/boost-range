#ifndef BOOST_RANGE_ALGORITHM_EXT_FUSED_FOR_EACH
#define BOOST_RANGE_ALGORITHM_EXT_FUSED_FOR_EACH

// Boost.Range 2.0 Extension library
//
// Copyright Akira Takahashi 2011.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/concept_check.hpp>
#include <boost/range/concepts.hpp>
#include <boost/range/algorithm/for_each.hpp>
#include <boost/fusion/include/make_fused.hpp>

namespace boost {
namespace range {

template <class SinglePassRange, class UnaryFunction>
inline void fused_for_each(SinglePassRange& rng, UnaryFunction f)
{
    BOOST_RANGE_CONCEPT_ASSERT((SinglePassRangeConcept<SinglePassRange>));
    ::boost::range::for_each(rng, ::boost::fusion::make_fused(f));
}

template <class SinglePassRange, class UnaryFunction>
inline void fused_for_each(const SinglePassRange& rng, UnaryFunction f)
{
    BOOST_RANGE_CONCEPT_ASSERT((SinglePassRangeConcept<SinglePassRange>));
    ::boost::range::for_each(rng, ::boost::fusion::make_fused(f));
}

} // namespace range

using range::fused_for_each;

} // namespace boost

#endif // BOOST_RANGE_ALGORITHM_EXT_FUSED_FOR_EACH
