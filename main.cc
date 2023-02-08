#include <iostream>
#include <chrono>

#include "include/random_string.h"

int main(){
  auto start = std::chrono::system_clock::now();

  RandomString rs;
  std::cout << rs.StringGenerator(14) << std::endl;

  auto end = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << " microseconds" << std::endl;
  return 0;    
}
