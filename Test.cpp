#include "doctest.h"
#include <stdexcept>
#include "Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Dividing by zero"){
    Fraction one(1,1);
    CHECK_THROWS(one/0.0);
    CHECK_NOTHROW(one - one); // should be (0,1)
}

TEST_CASE("+ operator"){
    Fraction one(1,1);
    Fraction tow(2,1);

    CHECK_EQ(one + one, tow);
    CHECK_EQ((one + 1), tow);
    CHECK_EQ((1 + one), tow);
}