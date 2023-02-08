#include "../include/tinymt32.h"

// Parametrized constructor used for initialization
TinyMT32::TinyMT32(const uint32_t& seed){
  Init(seed);  // call initialization function   
}

void TinyMT32::Init(const uint32_t& seed){
  status_ = {seed, kMat1_, kMat2_, kTMat_};
  mat1_ = kMat1_;
  mat2_ = kMat2_;
  tmat_ = kTMat_;

  for(std::size_t index=1; index<kMinLoop_; index++)
    status_[index & 3] ^= index + UINT32_C(1812433253) * (status_[(index-1) & 3]
		          ^ (status_[(index-1) & 3] >> 30));

  /**
   * If u want to use other parameters, u need to call
   * check_period(); function, here.
   * Check documentation for TinyMT32 algorithm.
   **/

  for(std::size_t index=0; index < kPreLoop_; index++)
    NextState();
}

// change internal state
void TinyMT32::NextState(){
  uint32_t x,y;
  y = status_[3];
  x = (status_[0] & kMask_)^status_[1]^status_[2];
  x ^= (x << kSH0_);
  y ^= (y >> kSH0_) ^ x;
  status_[0] = status_[1];
  status_[1] = status_[2];
  status_[2] = x ^ (y << kSH1_);
  status_[3] = y;
  status_[1] ^= (uint32_t)-((int32_t)(y & 1)) & mat1_;
  status_[2] ^= (uint32_t)-((int32_t)(y & 1)) & mat2_;
}

// return 32 unsigned integer from internal state (generated random number)
uint32_t TinyMT32::Temper() const{
  uint32_t t0, t1;
  t0 = status_[3];
  t1 = status_[0] + (status_[2] >> kSH8_);
  t0 ^= t1;
  t0 ^= (uint32_t)-((int32_t)(t1 & 1)) & tmat_;
  return t0;
}

/**
 * prevent all-zero 127-bit internal state
 * called in NextState() function
 **/
void TinyMT32::check_period(){
  if((status_[0] & kMask_) == 0 && 
      status_[1] == 0 && 
      status_[2] == 0 &&
      status_[3] == 0){
    status_[0] = 'H';
    status_[1] = 'A';
    status_[2] = 'C';
    status_[3] = 'K';
  }
}
