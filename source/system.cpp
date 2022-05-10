
#include <iostream>

#include "system.hpp"

HMS::System::System() {}

HMS::System::~System() {}

int HMS::System::startup()
{
  std::cout << "Initializing subsystems...\n";
  return 0;
}

int HMS::System::shutdown()
{
  std::cout << "Shutting down subsystems...\n";
  return 0;
}

int HMS::System::restart_subsystem(int subsystem_id)
{
  std::cout << "Restarting Subsystem " << subsystem_id << "\n";
  return 0;
}

int HMS::System::check_subsystem_status(subsystem_t subsystem,
                                        subsystem_status* status)
{
  std::cout << "Querying subsystem status...\n";
  return 0;
}

int HMS::System::check_all_subsystems_status(
    std::array<subssytem_status*, PLUGIN>* status_list)
{
  std::cout << "Checking all subsystems...\n";
  return 0;
}