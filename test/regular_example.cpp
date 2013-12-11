// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Akira Takahashi 2011.
// Copyright Shunsuke Sogame 2005-2007.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/range/regular.hpp>
#include <boost/range/iteration.hpp>
#include <boost/range/adaptor/taken.hpp>
#include <boost/lambda/lambda.hpp>

void disp(int x)
{
    std::cout << x << std::endl;
}

template <class InputIterator, class F>
void for_each_(InputIterator first, InputIterator last, F f)
{
    InputIterator it; // Default Constructible
    it = first; // Copy Assignable
    for (; it != last; ++it) {
        f(*it);
    }
}

template <class SinglePassRange, class F>
void for_each_(const SinglePassRange& rng, F f)
{
    return for_each_(boost::begin(rng), boost::end(rng), f);
}

int main()
{
    using boost::lambda::_1;

    for_each_(boost::iteration(1, boost::regular(_1 * 2)) | boost::adaptors::taken(5), disp);
}

