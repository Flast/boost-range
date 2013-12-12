// Boost.Range 2.0 Extension library
// via PStade Oven Library
//
// Copyright Akira Takahashi 2011.
// Copyright Shunsuke Sogame 2005-2007.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <boost/detail/lightweight_test.hpp>

#include <boost/range/regular.hpp>
#include <boost/lambda/lambda.hpp>

#define NO_USE(x) static_cast<void>(x)

template< class F >
void regular_check(F const f)
{
    F f1(f);
    F f2; // Default Constructible
    f2 = f1; // Copy Assignable

    bool less = f1 < f2;
    bool lesseq = f1 <= f2;
    bool greater = f1 > f2;
    bool greatereq = f1 >= f2;
    bool eq = f1 == f2;
    bool noteq = f1 != f2;

    NO_USE(less);
    NO_USE(lesseq);
    NO_USE(greater);
    NO_USE(greatereq);
    NO_USE(eq);
    NO_USE(noteq);
}

int main()
{
    namespace bll = boost::lambda;
    ::regular_check(boost::regular(bll::_1 != 'c'));
    ::regular_check(boost::regular(bll::_1 += 1));

    return boost::report_errors();
}


