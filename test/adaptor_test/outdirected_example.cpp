// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Kohei Takahashi 2014.
// Copyright Akira Takahashi 2011.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//[outdirected_example
#include <boost/range/adaptor/outdirected.hpp>
#include <boost/range/adaptor/indirected.hpp>
#include <boost/range/algorithm/sort.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <vector>
#include <iostream>

struct indirect_less
{
    template <typename I>
    bool operator()( I l, I r ) const { return *l < *r; }
};

int main()
{
    using namespace boost::assign;
    using namespace boost::adaptors;

    std::vector<int> input;
    input += 3,1,4,2,5;

    std::vector<std::vector<int>::const_iterator> iinput;
    boost::copy(
        input | outdirected,
        std::back_inserter(iinput));
    boost::sort(iinput, indirect_less());

    boost::copy(
        iinput | indirected,
        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    boost::copy(
        input,
        std::ostream_iterator<int>(std::cout, " "));
}
//]

/*
output:
1 2 3 4 5 
3 1 4 2 5 
*/

