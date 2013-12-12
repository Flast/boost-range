// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Akira Takahashi 2011.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <boost/detail/lightweight_test.hpp>
#include <boost/range/algorithm/equal.hpp>

#include <vector>
#include <deque>
#include <list>

#include <boost/assign/list_of.hpp>
#include <boost/range/adaptor/filtered.hpp>
#include <boost/range/as_container.hpp>

bool is_odd(int x) { return x % 2 == 0; }

template <class Container>
void test()
{
    // pipe operator style
    {
        const Container c1 = boost::assign::list_of(1)(2)(3)(4)(5);

        const Container c2 = c1 | boost::adaptors::filtered(is_odd) | boost::as_container;

        BOOST_TEST(boost::equal(
            c2,
            boost::assign::list_of(2)(4)
        ));

        Container c3;
        c3 = c1 | boost::adaptors::filtered(is_odd) | boost::as_container;

        BOOST_TEST(boost::equal(
            c3,
            boost::assign::list_of(2)(4)
        ));
    }

    // function style
    {
        const Container c1 = boost::assign::list_of(1)(2)(3)(4)(5);
        const Container c2 = boost::as_container(boost::adaptors::filter(c1, is_odd));

        BOOST_TEST(boost::equal(
            c2,
            boost::assign::list_of(2)(4)
        ));

        Container c3;
        c3 = boost::as_container(boost::adaptors::filter(c1, is_odd));

        BOOST_TEST(boost::equal(
            c3,
            boost::assign::list_of(2)(4)
        ));
    }
}

int main()
{
    test<std::vector<int> >();
    test<std::deque<int> >();
    test<std::list<int> >();

    return boost::report_errors();
}


