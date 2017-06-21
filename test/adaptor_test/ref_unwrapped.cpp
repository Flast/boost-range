// Boost.Range library
//
//  Copyright Robin Eckert 2015. Use, modification and distribution is
//  subject to the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
//
// For more information, see http://www.boost.org/libs/range/
//
#include <boost/range/begin.hpp>
#include <boost/range/end.hpp>
#include <boost/range/adaptor/ref_unwrapped.hpp>

#define BOOST_TEST_MAIN

#include <boost/test/test_tools.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/foreach.hpp>

#include <vector>
#include <functional>

namespace boost
{

    BOOST_AUTO_TEST_CASE(test_mutable)
    {
        int one = 1;
        int two = 2;
        int three = 3;

        std::vector<std::reference_wrapper<int>> input_values;
        input_values.push_back(std::ref(one));
        input_values.push_back(std::ref(two));
        input_values.push_back(std::ref(three));

        int* _expected[] = {&one, &two, &three};
        const std::vector<int*> expected(boost::begin(_expected), boost::end(_expected));
        std::vector<int*> actual;

        BOOST_FOREACH(int& value, input_values | adaptors::ref_unwrapped)
        {
          actual.push_back(&value);
        }

        BOOST_CHECK_EQUAL_COLLECTIONS(expected.begin(),
                                      expected.end(),
                                      actual.begin(),
                                      actual.end());
    }

    BOOST_AUTO_TEST_CASE(test_const_range)
    {
        int one = 1;
        int two = 2;
        int three = 3;

        std::vector<std::reference_wrapper<int>> _input_values;
        _input_values.push_back(std::ref(one));
        _input_values.push_back(std::ref(two));
        _input_values.push_back(std::ref(three));
        const std::vector<std::reference_wrapper<int>> input_values = _input_values;

        int* _expected[] = {&one, &two, &three};
        const std::vector<int*> expected(boost::begin(_expected), boost::end(_expected));
        std::vector<int*> actual;

        BOOST_FOREACH(int& value, input_values | adaptors::ref_unwrapped)
        {
          actual.push_back(&value);
        }

        BOOST_CHECK_EQUAL_COLLECTIONS(expected.begin(),
                                      expected.end(),
                                      actual.begin(),
                                      actual.end());
    }

    BOOST_AUTO_TEST_CASE(test_const_reference)
    {
        const int one = 1;
        const int two = 2;
        const int three = 3;

        std::vector<std::reference_wrapper<const int>> _input_values;
        _input_values.push_back(std::ref(one));
        _input_values.push_back(std::ref(two));
        _input_values.push_back(std::ref(three));
        const std::vector<std::reference_wrapper<const int>> input_values = _input_values;

        const int* _expected[] = {&one, &two, &three};
        const std::vector<const int*> expected(boost::begin(_expected), boost::end(_expected));
        std::vector<const int*> actual;

        BOOST_FOREACH(const int& value, input_values | adaptors::ref_unwrapped)
        {
          actual.push_back(&value);
        }

        BOOST_CHECK_EQUAL_COLLECTIONS(expected.begin(),
                                      expected.end(),
                                      actual.begin(),
                                      actual.end());
    }


}
