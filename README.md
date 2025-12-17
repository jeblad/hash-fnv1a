# hash-fnv1a

![stability-unstable](https://img.shields.io/badge/stability-experimental-orange.svg?style=for-the-badge)
![GitHub issues](https://img.shields.io/github/issues-raw/jeblad/hash-fnv1a?style=for-the-badge)

## Scope

Fowler–Noll–Vo 1a (or FNV1a) non-cryptographic hash function

From the page [FNV Hash](http://www.isthe.com/chongo/tech/comp/fnv/index.html) by _Landon Curt Noll_ with additional edits by [jeblad](mailto:jeblad@gmail.com) (Dec 13, 2025).

The basis of the FNV hash algorithm is an idea sent as reviewer comments to the IEEE POSIX P1003.2 committee by Glenn Fowler and Phong Vo in 1991, with Landon Curt Noll improving their algorithm.

The library uses preset _offset_ and _prime_, with the original offset being `chongo <Landon Curt Noll> /\../\` and the prime for 32 bit set by the initial IEEE POSIX P1003.2 committee proposal.

The current implementation is meant for a specific use case, and might not be generally usable.

## Usage

The _hash-fnv1a_ library is in a single header file. Simply grab the file and put it wherever it is needed, or pull the repo as a submodule.

```bash
wget https://raw.githubusercontent.com/jeblad/hash-fnv1a/refs/heads/main/hash-fnv1a.h
```

or

```bash
git submodule add git@github.com:jeblad/hash-fnv1a.git path-to-submodule
```

The _path-to-submodule_ would typically be something like `include/hash-fnv1a` if you're in the project folder.

If you're adding the _hash-fnv1a_ as a submodule, then pull an updated version.

The most common use is to use the library to generate a hash from a string

```C++
#include "hash-fnv1a.h"

// with a non-standard prime or base the general implementation will be used
// the base will be calculated if missing
hash::FNV1a<uint32_t, 16777499ULL> fnv1a{};
// with a standard prime and base the specialization will be used
// unless it is blocked at compile time with NO_FNV_OPTIMIZATION
hash::FNV1a<uint32_t, 16777619ULL, 2166136261ULL> fnv1a{};
// then call the hash function
uint32_t result = fnv1a.hash("some string");
```

It is possible to force the library to use ordinary multiply by setting `NO_FNV_OPTIMIZATION`. Otherwise, it will use bit shifts.

## Development

The testing library [doctest](https://github.com/doctest/doctest) is used during development, but it isn't part of the library as such. It is although necessary for running the tests. Likewise, the implementation in `hash-fnv1a-test.cpp` isn't necessary for non-development use, it is only used during tests.

The _doctest_ library is in a single header file. Simply grab the file and put it wherever it is needed, or pull the repo as a submodule.

```bash
wget https://raw.githubusercontent.com/doctest/doctest/refs/heads/master/doctest/doctest.h
```

or

```bash
git submodule add git@github.com:doctest/doctest.git path-to-submodule
```

The _path-to-submodule_ would typically be something like `include/doctest` if you're in the project folder.

If you're adding the _doctest_ as a submodule, then pull an updated version.

The usual development cycle is to compile the test file, and then run it

```bash
# when doctest.h residews in ./include
g++ -Wall -Wextra -Werror -std=c++20  -O3 -I ./include -I ./src/ -o hash-fnv1a-test test/hash-fnv1a-test.cpp
# when doctest.h residews in an module in ./include
g++ -Wall -Wextra -Werror -std=c++20  -O3 -I ./include/doctest/doctest -I ./src/ -o hash-fnv1a-test test/hash-fnv1a-test.cpp
```

It should be compiled with optimization level 3 to get a speedup from the bit shift multiply.

Then run the executable `hash-fnv1a-test` that has the actual tests.

```bash

./hash-fnv1a-test
```

The executable can take several arguments. Check the _doctest_ manual for examples.
