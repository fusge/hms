
#include <iostream>

#include "system.hpp"

hms::system::system()
{
  this->startup();
}

hms::system::~system()
{
  this->shutdown();
}

auto hms::system::startup() -> int
{
  std::cout << "Initializing subsystems...\n";
  return 0;
}

auto hms::system::shutdown() -> int
{
  std::cout << "Shutting down subsystems...\n";
  return 0;
}

auto hms::system::restart_subsystem(int subsystem_id) -> int
{
  std::cout << "Restarting Subsystem " << subsystem_id << "\n";
  return 0;
}

auto hms::system::check_subsystem_status(subsystem_t subsystem,
                                         subsystem_status* status) -> int
{
  std::cout << "Querying subsystem status...\n";
  return 0;
}

auto hms::system::check_all_subsystems_status(
    std::array<hms::subsystem_status, hms::logger_t>* status_list) -> int
{
  std::cout << "Checking all subsystems...\n";
  return 0;
}

auto hms::subsystem_factory::init_subsystem(hms::subsystem_t system_type,
                                            hms::subsystem * sub_system) -> int
{
  return 0;
}