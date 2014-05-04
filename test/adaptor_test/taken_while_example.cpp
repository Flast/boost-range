// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Kohei Takahashi 2014.
// Copyright Akira Takahashi 2011.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//[taken_while_example
#include <boost/range/adaptor/taken_while.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <iostream>
#include <vector>

struct is_even
{
    bool operator()( int x ) const { return x % 2 == 0; }
};

int main()
{
    using namespace boost::assign;
    using namespace boost::adaptors;

    std::vector<int> input;
    input += 2,4,6,1,3;

    boost::copy(
        input | taken_while(is_even()),
        std::ostream_iterator<int>(std::cout, " "));
}
//]

/*
output:
2 4 6 
*/

