
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

int hms::system::startup()
{
  std::cout << "Initializing subsystems...\n";
  return 0;
}

int hms::system::shutdown()
{
  std::cout << "Shutting down subsystems...\n";
  return 0;
}

int hms::system::restart_subsystem(int subsystem_id)
{
  std::cout << "Restarting Subsystem " << subsystem_id << "\n";
  return 0;
}

int hms::system::check_subsystem_status(subsystem_t subsystem,
                                         subsystem_status status)
{
  std::cout << "Querying subsystem status...\n";
  return 0;
}

int hms::system::check_all_subsystems_status(const std::vector<hms::subsystem_status>& status_list)
{
  std::cout << "Checking all subsystems...\n";
  return 0;
}

int hms::subsystem_factory::init_subsystem(hms::subsystem_t system_type,
                                            hms::subsystem * sub_system)
{
  return 0;
}
