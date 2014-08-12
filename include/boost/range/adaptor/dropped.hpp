#ifndef BOOST_RANGE_ADAPTOR_DROPPED_IMPL_HPP
#define BOOST_RANGE_ADAPTOR_DROPPED_IMPL_HPP

// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Akira Takahashi 2011.
// Copyright Shunsuke Sogame 2005-2007.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <algorithm> // min
#include <boost/config.hpp>
#include <boost/concept_check.hpp>
#include <boost/range/concepts.hpp>
#include <boost/range/adaptor/argument_fwd.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/range/iterator.hpp>
#include <boost/range/difference_type.hpp>
#include <boost/range/traversal.hpp>

namespace boost {

namespace range_detail {

    template< class Range >
    struct dropped_range  : iterator_range<typename range_iterator<Range>::type> {
        typedef typename range_difference<Range>::type diff_t;
        typedef typename range_iterator<Range>::type iter_t;
        typedef iterator_range<iter_t> base;

        BOOST_RANGE_CONCEPT_ASSERT((SinglePassRangeConcept<Range>));

        dropped_range(Range& rng, diff_t n)
            : base(make_first_iterator(::boost::begin(rng),
                                       ::boost::end(rng),
                                       n,
                                       typename boost::range_traversal<Range>::type()
                                       ),
                    ::boost::end(rng))
        {}

    private:
        template <class Iterator>
        static iter_t make_first_iterator(Iterator first,
                                          Iterator last,
                                          diff_t n,
                                          boost::random_access_traversal_tag)
        {
            return first + (std::min)(last - first, n);
        }

        template <class Iterator>
        static iter_t make_first_iterator(Iterator first,
                                          Iterator last,
                                          diff_t n,
                                          boost::single_pass_traversal_tag)
        {
            while (n != 0 && first != last) {
                ++first;
                --n;
            }
            return first;
        }
    };

    template <class T>
    struct dropped_holder : holder<T> {
        dropped_holder( T r ) : holder<T>(r) {}
    };

    template <class SinglePassRng, class Difference>
    inline dropped_range<SinglePassRng>
    operator|(SinglePassRng& r, const dropped_holder<Difference>& f)
    {
        return dropped_range<SinglePassRng>(r, f.val);
    }

    template <class SinglePassRng, class Difference>
    inline dropped_range<const SinglePassRng>
    operator|(const SinglePassRng& r, const dropped_holder<Difference>& f)
    {
        return dropped_range<const SinglePassRng>(r, f.val);
    }
} // namespace range_detail

    using range_detail::dropped_range;

    namespace adaptors
    {
        namespace
        {
            const range_detail::forwarder<range_detail::dropped_holder>
                dropped =
                   range_detail::forwarder<range_detail::dropped_holder>();
        }

        template<class SinglePassRng>
        inline dropped_range<SinglePassRng>
        drop(SinglePassRng& rng, BOOST_DEDUCED_TYPENAME boost::range_difference<SinglePassRng>::type n)
        {
            return dropped_range<SinglePassRng>(rng, n);
        }

        template<class SinglePassRng>
        inline dropped_range<const SinglePassRng>
        drop(const SinglePassRng& rng, BOOST_DEDUCED_TYPENAME boost::range_difference<SinglePassRng>::type n)
        {
            return dropped_range<const SinglePassRng>(rng, n);
        }

    } // namespace adaptors


} // namespace boost

#endif // BOOST_RANGE_ADAPTOR_DROPPED_IMPL_HPP

