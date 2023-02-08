#include "../include/random_string.h"

std::string RandomString::StringGenerator(const unsigned int& n) const{
  /**
   * call CharVectorGenerator() function which return
   * std::vector<char> type
   **/
  std::vector<char> output = CharVectorGenerator(n);
  return std::string(output.begin(), output.end());
}

std::vector<char> RandomString::CharVectorGenerator(const unsigned int& n) const{
  std::vector<char> output;
  output.reserve(n);
  TinyMT32 random(SeedGenerator());
  for( unsigned int index=0; index < n; index++ ){
    output.push_back(CharacterGenerator(random));
  }
  return output;
}

uint32_t RandomString::SeedGenerator() const{
  return (time(NULL) * getpid() << 3); 
}

char RandomString::CharacterGenerator(TinyMT32& random) const{
  random.NextState();
  return 33 + (random.Temper() % 93);
}
