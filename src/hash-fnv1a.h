/*

Fowler–Noll–Vo 1a (or FNV1a) non-cryptographic hash function

This is a pretty stright-forward implementation of the hash function

*/

#pragma once

#include <string>
#include <cstdint>
#include <concepts>
#include <iostream>

namespace hash{

    template<std::unsigned_integral T, uint64_t prime, uint64_t offset=0>
    class FNV1a {
        private:
        const T _prime{static_cast<T>(prime)};
        T _offset{0};

        public:

        FNV1a() {
            std::cout << "generalization" << "\n";
            if (offset) {
                _offset = static_cast<T>(offset);
            }
            else {
                _offset = hash("chongo <Landon Curt Noll> /\\../\\");
            }
        }

        T hash(
            std::string str
        ) {

            T _hval = _offset;
            for (unsigned int i = 0; i < str.length(); i++) {
                _hval ^= (T) str[i];
                _hval *= _prime;
            }
            return _hval;
        }
    };

    #if !defined(NO_FNV_GCC_OPTIMIZATION)

    template<std::unsigned_integral T>
    class FNV1a<T, 16777619ULL, 2166136261ULL> {
        private:
        const T _offset{static_cast<T>(2166136261ULL)};

        public:

        FNV1a() {
            std::cout << "spesialization" << "\n";
        }

        T hash(
            std::string str
        ) {
            T _hval = _offset;
            for (unsigned int i = 0; i < str.length(); i++) {
                _hval ^= (T) str[i];
                _hval += (_hval << 1) + (_hval << 4) + (_hval << 7)
                    + (_hval << 8) + (_hval << 24);
            }
            return _hval;
        }
    };

    template<std::unsigned_integral T>
    class FNV1a<T, 1099511628211ULL, 14695981039346656037ULL> {
        private:
        const T _offset{static_cast<T>(14695981039346656037ULL)};

        public:

        FNV1a() {}

        T hash(
            std::string str
        ) {
            T _hval = _offset;
            for (unsigned int i = 0; i < str.length(); i++) {
                _hval ^= (T) str[i];
                _hval += (_hval << 1) + (_hval << 4) + (_hval << 5)
                    + (_hval << 7) + (_hval << 8) + (_hval << 40);
            }
            return _hval;
        }
    };

    #endif

}