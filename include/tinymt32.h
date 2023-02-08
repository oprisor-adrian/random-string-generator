#ifndef RANDOM_STRING_TINYMT_INCLUDE_TINYMT32_H_
#define RANDOM_STRING_TINYMT_INCLUDE_TINYMT32_H_

#include <cstdint>
#include <array>

class TinyMT32{
  public:
    TinyMT32() = default;
    TinyMT32(const uint32_t& seed);
    ~TinyMT32() = default;
    void Init(const uint32_t& seed); // initialize internal state
    void NextState(); // change internal state
    uint32_t Temper() const; // return unit32_t from internal state
  private:
    static const uint32_t kMat1_ = UINT32_C(0x8f7011ee);
    static const uint32_t kMat2_ = UINT32_C(0xfc78ff1f);
    static const uint32_t kTMat_ = UINT32_C(0x3793fdff);
    static const uint32_t kMinLoop_ = 8;
    static const uint32_t kPreLoop_ = 8;
    static const uint32_t kSH0_ = 1;
    static const uint32_t kSH1_ = 10;
    static const uint32_t kSH8_ = 8;
    static const uint32_t kMask_ = UINT32_C(0x7fffffff);

    void check_period();  // prevent all-zero 127-bit internal state

    std::array<uint32_t, 4> status_;
    uint32_t mat1_, mat2_, tmat_;
}; 
#endif  // RANDOM_STRING_TINYMT_INCLUDE_TINYMT32_H_
