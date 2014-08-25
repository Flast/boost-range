// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Neil Groves 2014.
// Copyright Kohei Takahashi 2014.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_RANGE_UNIT_TEST_ADAPTOR_MOCK_KV_ITERATOR_HPP_INCLUDED
#define BOOST_RANGE_UNIT_TEST_ADAPTOR_MOCK_KV_ITERATOR_HPP_INCLUDED

#include <string>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/fusion/include/adapt_assoc_struct.hpp>

namespace boost
{
    namespace range
    {
        namespace unit_test
        {

struct key_value
{
    int key;
    std::string value;

    key_value() { }

    key_value(int k, std::string v)
      : key(k), value(v)
    {
    }
};


inline bool operator==(const key_value& kv1, const key_value& kv2)
{
    return kv1.key == kv2.key;
}

        } // namespace unit_test
    } // namespace range
} // namespace boost

struct key_tag { };
struct value_tag { };
BOOST_FUSION_ADAPT_ASSOC_STRUCT(
    boost::range::unit_test::key_value,
    (int        , key  , key_tag)
    (std::string, value, value_tag)
)

namespace boost
{
    namespace range
    {
        namespace unit_test
        {

template<typename TraversalTag>
class mock_kv_iterator
        : public boost::iterator_facade<
                    mock_kv_iterator<TraversalTag>,
                    key_value,
                    TraversalTag,
                    const key_value&
        >
{
public:
    mock_kv_iterator()
        : m_value()
    {
    }

    explicit mock_kv_iterator(key_value value)
        : m_value(value)
    {
    }

    mock_kv_iterator(int k, std::string v)
        : m_value(k, v)
    {
    }

private:

    void increment()
    {
        ++m_value.key;
    }

    void decrement()
    {
        --m_value.key;
    }

    bool equal(const mock_kv_iterator& other) const
    {
        return m_value == other.m_value;
    }

    void advance(std::ptrdiff_t offset)
    {
        m_value.key += offset;
    }

    std::ptrdiff_t distance_to(const mock_kv_iterator& other) const
    {
        return other.m_value.key - m_value;
    }

    const int& dereference() const
    {
        return m_value.key;
    }

    key_value m_value;
    friend class boost::iterator_core_access;
};

        } // namespace unit_test
    } // namespace range
} // namespace boost

#endif // include guard
