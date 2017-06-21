// Boost.Range library
//
//  Copyright Kohei Takahashi 2017
//  Copyright Robin Eckert 2015. Use, modification and distribution is
//  subject to the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
//[ref_unwrapped_example
#include <boost/range/adaptor/ref_unwrapped.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <vector>
#include <functional>

struct example
{
  int value;
};

int main(int argc, const char* argv[])
{
    using boost::adaptors::ref_unwrapped;

    example one = {1};
    example two = {2};
    example three = {3};

    std::vector<std::reference_wrapper<example> > input;
    input.push_back(std::ref(one));
    input.push_back(std::ref(two));
    input.push_back(std::ref(three));

    BOOST_FOREACH(example& entry, input | ref_unwrapped)
    {
      std::cout << entry.value;
    }
}
//]
