/*
  Testing Procedures for Fowler–Noll–Vo 1a hash function
*/

#include "hash-fnv1a.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("testing the random generator with 8 bit and default constructor") {
    const std::string str1 = "this is the test string 1";
    const std::string str2 = "this is the test string 2";
    CHECK(hash::fnv1a("") == 2166136261);
    CHECK(hash::fnv1a(str1) == 2380602814);
    CHECK(hash::fnv1a(str2) == 2363825195);
    CHECK(hash::fnv1a(str1) != hash::fnv1a(str2));
}