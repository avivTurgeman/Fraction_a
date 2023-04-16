#include "doctest.h"
#include <stdexcept>
#include "Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("+ operator"){
    Fraction one(1,1);
    Fraction two(2,1);

    CHECK_EQ(one + one, two);
    CHECK_EQ(one + 1, two);
    CHECK_EQ(1 + one, two);
    CHECK_EQ(1.5 + one + two, two + 2.5);
}

TEST_CASE("- operator"){
    Fraction one(1,1);
    Fraction two(2,1);

    CHECK_EQ(two - one, one);
    CHECK_EQ(two - 1, one);
    CHECK_EQ(3 - two, one);
    CHECK_EQ(2.2 + two - 1.2 - one, two);
    CHECK_NOTHROW(one - one);
}

TEST_CASE("* operator"){
    Fraction zero(0,1);
    Fraction one(1,1);
    Fraction two(2,1);

    CHECK_EQ(two * one, two);
    CHECK_EQ(two * zero, zero);
    CHECK_EQ(2 * one * 1, two);
    CHECK_EQ(two * 0.5 * one, one);

}

TEST_CASE("Dividing by zero"){
    Fraction one(1,1);
    CHECK_THROWS(one/0.0);
    CHECK_NOTHROW(one - one); // should be (0,1)
    CHECK_THROWS(Fraction(1,0));
}

