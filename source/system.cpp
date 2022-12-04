
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

auto hms::system::check_subsystem_status(subsystem_t subsystem) -> hms::status::info
{
  std::cout << "Querying subsystem status...\n";
  hms::status::info result {};
  result.system_name = "n/a";
  result.subsystem_type = subsystem;
  result.status = hms::status::unknown;
  result.msg = std::string("");
  return result;
}

auto hms::system::check_all_subsystems_status() -> std::vector<hms::status::info>
{
  std::cout << "Checking all subsystems...\n";
  std::vector<hms::status::info> stat_info_list;
  for(auto subsys : hms::ALL_SUBSYSTEM_TYPES){
    stat_info_list.push_back(this->check_subsystem_status(subsys));
  }
  return stat_info_list;
}

// auto hms::subsystem_factory::init_subsystem(hms::subsystem_t system_type,
//                                             hms::subsystem * sub_system) -> int
// {
//   return 0;
// }