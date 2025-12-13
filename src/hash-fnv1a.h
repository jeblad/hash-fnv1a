/*

Fowler–Noll–Vo 1a (or FNV1a) non-cryptographic hash function

This is a pretty stright-forward implementation of the hash function, 

*/

#pragma once

#include <string>
#include <cstdint>
#include <concepts>

#define NO_FNV_GCC_OPTIMIZATION false

namespace hash{

    uint32_t fnv1a(
        std::string str
    ) {
        const uint32_t offset = 2166136261;
        const uint32_t prime = 16777619;

        uint32_t hash = offset;

            for (unsigned int i = 0; i < str.length(); i++) {
                hash ^= (uint32_t) str[i];
#if defined(NO_FNV_GCC_OPTIMIZATION)
                hash *= prime;
#else
                hash += (hash << 1) + (hash << 4) + (hash << 7) + (hash << 8) + (hash << 24);
#endif
            }
        return hash;
    }

}