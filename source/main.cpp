#include <memory>

#include "system.hpp"

int main()
{
  auto system = std::make_unique<hms::system>();
  return 0;
}
