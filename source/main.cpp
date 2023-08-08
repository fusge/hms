#include <iostream>
#include <string>
#include "hmsConfig.hpp"

int main(int  /*argc*/, char*  /*argv*/[])
{
  std::cout << "Welcome to HMS version "
            << hms_version_major << "."
            << hms_version_minor << "."
            << hms_version_patch << "\n";
  return 0;
}
