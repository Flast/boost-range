// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Kohei Takahashi 2014.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "mock_kv_range.hpp"
#include <boost/range/adaptor/elements.hpp>

int main(int, const char**)
{
    using boost::range::unit_test::mock_kv_range;

    // This next line should fail when Boost.Range concept checking is
    // enabled since the filtered adaptor takes at least a SinglePassRange.
    return boost::adaptors::extract_elements_key<key_tag>(
        mock_kv_range<boost::incrementable_traversal_tag>()).front();
}
