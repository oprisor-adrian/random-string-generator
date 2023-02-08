#ifndef RANDOM_STRING_TINYMT_INCLUDE_RANDOM_STRING_H_
#define RANDOM_STRING_TINYMT_INCLUDE_RANDOM_STRING_H_

#include <cstdint>
#include <string>

#include <time.h>
#include <unistd.h>
#include <vector>

#include "tinymt32.h"

class RandomString{
  public:
    RandomString() = default;
    ~RandomString() = default;

    // return random string as string type
    std::string StringGenerator(const unsigned int&) const;

    // return vector of random chars
    std::vector<char> CharVectorGenerator(const unsigned int&) const;
  private:
    uint32_t SeedGenerator() const;
    char CharacterGenerator(TinyMT32&) const;  // generate and return random char
};
#endif  // RANDOM_STRING_TINYMT_INCLUDE_RANDOM_STRING_H_
