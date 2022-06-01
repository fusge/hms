#ifndef SYSTEM_TESTS_H
#define SYSTEM_TESTS_H

#include <gtest/gtest.h>

#include "system.hpp"

class systemTests : public ::testing::Test
{
  protected:
  systemTests() { };
  ~systemTests() { };
};

#endif
