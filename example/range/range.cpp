/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/static_assert.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/range.hpp>
using namespace boost::hana;
using namespace literals;


int main() {
    //! [main]
    BOOST_HANA_STATIC_ASSERT(head(range(0_c, 5_c)) == 0_c);
    BOOST_HANA_STATIC_ASSERT(last(range(0_c, 5_c)) == 4_c);
    BOOST_HANA_STATIC_ASSERT(tail(range(0_c, 5_c)) == range(1_c, 5_c));
    //! [main]
}
