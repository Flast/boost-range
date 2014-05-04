// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Kohei Takahashi 2014.
// Copyright Akira Takahashi 2011.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
//[elements_example
#include <boost/range/adaptor/elements.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>

struct Person
{
    int id;
    std::string name;

    Person(int id_, const std::string& name_)
        : id(id_), name(name_) {}
};

BOOST_FUSION_ADAPT_STRUCT(
    Person,
    (int, id)
    (std::string, name)
)

int main(int argc, const char* argv[])
{
    using namespace boost::assign;
    using namespace boost::adaptors;

    std::vector<Person> input;
    input += Person(1, "Alice"),
             Person(2, "Millia"),
             Person(3, "Bob");

    boost::copy(
        input | elements<1>(),
        std::ostream_iterator<std::string>(std::cout, "\n"));
}
//]

/*
output:
Alice
Millia
Bob
*/

