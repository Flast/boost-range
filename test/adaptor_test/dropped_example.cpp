// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Kohei Takahashi 2014.
// Copyright Akira Takahashi 2011.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//[dropped_example
#include <boost/range/adaptor/dropped.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <iostream>
#include <vector>

int main()
{
    using namespace boost::assign;
    using namespace boost::adaptors;

    std::vector<int> input;
    input += 3,1,4,2,5;

    boost::copy(
        input | dropped(2),
        std::ostream_iterator<int>(std::cout, " "));
}
//]

/*
output:
4 2 5 
*/

