#include <stdexcept>
#include <sstream>
#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Fraction initialization"){
    Fraction a(5,11);
    Fraction c = a;

    CHECK_EQ( Fraction(3400,1000),  Fraction(17,5));
    CHECK_THROWS(Fraction(1,0));
    CHECK_EQ(a, c);
       
}

TEST_CASE("operator+"){
    Fraction one(1,1);
    Fraction two(2,1);
    Fraction three_half(7,2);
    Fraction two_half(5,2);

    CHECK_EQ(one + one, two);
    CHECK_EQ(one + 1, two);
    CHECK_EQ(2.5 + one, three_half);
    CHECK_EQ(two_half + one, three_half);
    CHECK_EQ(1.5 + one + two, two + 2.5);
}

TEST_CASE("operator-"){
    Fraction one(1,1);
    Fraction two(2,1);

    CHECK_EQ(two - one, one);
    CHECK_EQ(two - 1, one);
    CHECK_EQ(3 - two, one);
    CHECK_EQ(2.2 + two - 1.2 - one, two);
    CHECK_NOTHROW(one - one);
}

TEST_CASE("operator*"){
    Fraction zero(0,1);
    Fraction one(1,1);
    Fraction two(2,1);

    CHECK_EQ(two * one, two);
    CHECK_EQ(two * zero, zero);
    CHECK_EQ(2 * one * 1, two);
    CHECK_EQ(two * 0.5 * one, one);
}

TEST_CASE("operator/"){
    Fraction zero(0,1);
    Fraction one(1,1);
    Fraction two(2,1);

    CHECK_THROWS(one / zero);
    CHECK_THROWS(two / 0);
    CHECK_EQ(two / two, one);
    CHECK_EQ(two / 0.5, two * two);
    CHECK_EQ(0 / one, zero);
}

TEST_CASE("operator=="){
    Fraction one_half(3,2);
    Fraction one_half_tag(6,4);

    CHECK(one_half == 1.5);
    CHECK(1.5 == one_half);
    CHECK(one_half_tag == one_half);
}

TEST_CASE("operator>"){
    Fraction one_half(3,2);
    Fraction two_half(5,2);

    CHECK(two_half > 1.5);
    CHECK(3.5 > two_half);
    CHECK(two_half > one_half);
}

TEST_CASE("operator<"){
    Fraction one_half(3,2);
    Fraction two_half(5,2);

    CHECK(1.5 < two_half);
    CHECK(two_half < 3.5);
    CHECK(one_half < two_half);
}

TEST_CASE("operator>="){
    Fraction one_half(3,2);
    Fraction two_half(5,2);

    CHECK(two_half >= 1.5);
    CHECK(one_half >= 1.5);
    CHECK(3.5 >= two_half);
    CHECK(2.5 >= two_half);
    CHECK(two_half >= one_half);
    CHECK(two_half >= two_half);
}

TEST_CASE("operator<="){
    Fraction one_half(3,2);
    Fraction two_half(5,2);

    CHECK(1.5 <= two_half);
    CHECK(1.5 <= one_half);
    CHECK(two_half <= 3.5);
    CHECK(two_half <= 2.5);
    CHECK(one_half <= two_half);
    CHECK(two_half <= two_half);
}

TEST_CASE("++operator (prefix)"){
    Fraction one_half(3,2);
    Fraction two_half(5,2);

    CHECK_NE(one_half, two_half);
    CHECK_EQ(++one_half, two_half);
}

TEST_CASE("--operator (prefix)"){
    Fraction one_half(3,2);
    Fraction two_half(5,2);

    CHECK_NE(one_half, two_half);
    CHECK_EQ(one_half, --two_half);
}

TEST_CASE("operator++ (postfix)"){
    Fraction one_half(3,2);
    Fraction two_half(5,2);

    CHECK_NE(one_half++, two_half);
    CHECK_EQ(one_half, two_half);
}

TEST_CASE("operator-- (postfix)"){
    Fraction one_half(3,2);
    Fraction two_half(5,2);

    CHECK_NE(one_half, two_half--);
    CHECK_EQ(one_half, two_half);
}

TEST_CASE("operator<< overload")
{
    SUBCASE("fraction with denominator 1")
    {
        Fraction frac(3,1);
        ostringstream output;
        output << frac;
        CHECK(output.str() == "3/1");
    }

    SUBCASE("fraction with denominator > 1")
    {
        Fraction frac(2, 3);
        ostringstream output;
        output << frac;
        CHECK(output.str() == "2/3");
    }
}

TEST_CASE("operator>> overload"){
    SUBCASE("valid input")
    {
        Fraction frac;
        istringstream input("2/3");
        input >> frac;
        CHECK(frac.getNumerator() == 2);
        CHECK(frac.getDenominator() == 3);
    }

    SUBCASE("invalid input")
    {
        Fraction frac;
        istringstream input("2.3");
        input >> frac;
        CHECK(frac.getNumerator() == 0);
        CHECK(frac.getDenominator() == 1);
    }
}

TEST_CASE("combinning all of the operators"){
    Fraction zero(0,1);
    Fraction one(1,1);
    Fraction one_half(3,2);
    Fraction two(2,1);
    Fraction two_half(5,2);

    CHECK(one + 2.5 - one_half == 1.5 + one_half - 1);
    CHECK(zero * (1.5 + two) == 0);
}

