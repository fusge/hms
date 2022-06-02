#include <iostream>
#include <string>
#include "hmsConfig.hpp"

auto main() -> int
{
  std::cout << "Welcome to HMS version "
            << HMS_VERSION_MAJOR << "."
            << HMS_VERSION_MINOR << "."
            << HMS_VERSION_PATCH << "\n";
  return 0;
}
