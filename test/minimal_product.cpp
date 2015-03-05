/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <test/minimal_product.hpp>

#include <boost/hana/assert.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>

#include <test/auto/base.hpp>
#include <test/auto/product.hpp>
#include <test/cnumeric.hpp>
#include <test/injection.hpp>
#include <test/tracked.hpp>

#include <utility>
using namespace boost::hana;


namespace boost { namespace hana { namespace test {
    template <>
    auto instances<MinimalProduct> = make<Tuple>(
        type<Product>
    );

    template <>
    auto objects<MinimalProduct> = make<Tuple>(
          minimal_product(cnumeric<int, 0>, cnumeric<int, 0>)
        , minimal_product(cnumeric<int, 0>, cnumeric<int, 1>)
        , minimal_product(cnumeric<int, 1>, cnumeric<int, 0>)
        , minimal_product(cnumeric<int, 1>, cnumeric<int, 1>)
    );
}}}


int main() {
    test::check_datatype<test::MinimalProduct>();

    // make sure `first` and `second` are "accessors"
    auto prod = test::minimal_product(test::Tracked{1}, test::Tracked{2});
    first(std::move(prod));
    second(std::move(prod));
}
