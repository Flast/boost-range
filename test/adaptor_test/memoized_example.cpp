// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Kohei Takahashi 2014.
// Copyright Akira Takahashi 2011.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//[memoized_example
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/memoized.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <iterator>
#include <iostream>
#include <vector>

struct add
{
    typedef int result_type;
    int operator()( int x ) const
    {
        std::cout << "add function : " << x << std::endl;
        return x + 1;
    }
};

struct true_
{
    bool operator()( int x ) { return true; }
};

int main()
{
    using namespace boost::adaptors;

    const int input[] = {1,2,3};
    boost::copy(
        input | transformed(add())
              | memoized
              | filtered(true_()),
        std::ostream_iterator<int>(std::cout, "\n"));
}
//]

/*
output:
add function : 1
2
add function : 2
3
add function : 3
4
*/

