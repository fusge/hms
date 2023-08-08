
#include <cstdlib>
#include <iostream>
#include <algorithm>

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
  int result = EXIT_SUCCESS;
  for(auto& subsystem : this->m_subsystems)
  {
    if(subsystem->startup() == EXIT_FAILURE) { result = EXIT_FAILURE; }
  }
  return result;
}

int hms::system::shutdown()
{
  std::cout << "Shutting down subsystems...\n";
  int result = EXIT_SUCCESS;
  for(auto& subsystem : this->m_subsystems)
  {
    if(subsystem->shutdown() == EXIT_FAILURE) { result = EXIT_FAILURE; }
  }
  return result;
}

int hms::system::restart_subsystem(int subsystem_id)
{
  std::cout << "Restarting Subsystem " << subsystem_id << "\n";
  int result = EXIT_SUCCESS;
  for(auto& subsystem : this->m_subsystems)
  {
    if(subsystem->restart() == EXIT_FAILURE){ result = EXIT_FAILURE; }
  }
  return result;
}

hms::status::info hms::system::check_subsystem_status(subsystem_t subsystem)
{
  std::cout << "Querying subsystem status...\n";
  auto iter = std::find_if(this->m_subsystems.begin(), 
                           this->m_subsystems.end(), 
                           [&subsystem](const std::unique_ptr<hms::subsystem>& subsys){
                             return subsys->get_subsystem_type() == subsystem;
                           });
  hms::status::info result {};
  result.system_name = "n/a";
  result.subsystem_type = subsystem;
  result.status = hms::status::unknown;
  result.msg = std::string("");
  if(iter != this->m_subsystems.end()){
    result = (*iter)->get_status_info();
  }
  return result;
}

std::vector<hms::status::info> hms::system::check_all_subsystems_status()
{
  std::cout << "Checking all subsystems...\n";
  std::vector<hms::status::info> stat_info_list;
  stat_info_list.reserve(hms::all_subsystem_types.size());
  for(auto subsys : hms::all_subsystem_types){
    stat_info_list.push_back(this->check_subsystem_status(subsys));
  }
  return stat_info_list;
}

