// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Akira Takahashi 2011-2012.
// Copyright Shunsuke Sogame 2005-2007.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/lambda/lambda.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/adaptor/transformed.hpp>
#include <boost/range/experimental/adaptor/tapped.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <iostream>
#include <vector>

struct add
{
    typedef int result_type;
    int operator()( int x ) const { return x + 1; }
};

struct is_even
{
    bool operator()( int x ) { return x % 2 == 0; }
};

int main(int argc, const char* argv[])
{
    using namespace boost::assign;
    using namespace boost::adaptors;

    std::vector<int> input;
    input += 1,2,3,4,5;

    using boost::lambda::_1;
    boost::copy(
        input | transformed(add())
              |+ tapped(std::cout << _1 << " is tapped\n")
              | filtered(is_even()),
        std::ostream_iterator<int>(std::cout, "\n"));
}
/*
output:
2 is tapped
3 is tapped
4 is tapped
5 is tapped
6 is tapped
2
4
6
*/

