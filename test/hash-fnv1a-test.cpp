/*
  Testing Procedures for Fowler–Noll–Vo 1a hash function
*/

#include <cstdint>

#include "hash-fnv1a.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("testing the general hash function for repeatability") {
    // this use the alternate less-than prime for 32 bit
    hash::FNV1a<uint32_t, 16777499ULL> fnv1a{};
    const std::string str1 = "this is the test string 1";
    const std::string str2 = "this is the test string 2";
    CHECK(fnv1a.hash("") == 2230366783);
    CHECK(fnv1a.hash(str1) == 1452757912);
    CHECK(fnv1a.hash(str2) == 1503090409);
    CHECK(fnv1a.hash(str1) != fnv1a.hash(str2));
}

TEST_CASE("testing the special hash function for repeatability") {
    // this use the IEEE POSIX P1003.2 proposal greater-than prime for 32 bit
    hash::FNV1a<uint32_t, 16777619ULL, 2166136261ULL> fnv1a{};
    const std::string str1 = "this is the test string 1";
    const std::string str2 = "this is the test string 2";
    CHECK(fnv1a.hash("") == 2166136261);
    CHECK(fnv1a.hash(str1) == 2380602814);
    CHECK(fnv1a.hash(str2) == 2363825195);
    CHECK(fnv1a.hash(str1) != fnv1a.hash(str2));
}

TEST_CASE("testing the special hash function for repeatability") {
    hash::FNV1a<uint64_t, 1099511628211ULL, 14695981039346656037ULL> fnv1a{};
    const std::string str1 = "this is the test string 1";
    const std::string str2 = "this is the test string 2";
    CHECK(fnv1a.hash("") == 14695981039346656037ULL);
    CHECK(fnv1a.hash(str1) == 12073451778302911390ULL);
    CHECK(fnv1a.hash(str2) == 12073450678791283179ULL);
    CHECK(fnv1a.hash(str1) != fnv1a.hash(str2));
}
