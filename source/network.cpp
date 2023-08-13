#include <cstdlib>
#include <iostream>

#include "network.hpp"

auto hms::network::manager::startup() -> int
{
  std::cout << "Network Subsystem Initialized\n";
  this->m_status = hms::status::running;
  return EXIT_SUCCESS;
}

auto hms::network::manager::shutdown() -> int
{
  std::cout << "Network Subsystem Shutdown\n";
  this->m_status = hms::status::stopped;
  return EXIT_SUCCESS;
}

auto hms::network::manager::restart() -> int
{
  int result = EXIT_SUCCESS;
  try{
    if(this->shutdown() == EXIT_FAILURE) { result = EXIT_FAILURE; }
    if(this->startup() == EXIT_FAILURE) { result = EXIT_FAILURE; }
  } catch (...){
    std::cerr << "Unable to restart Network Manager\n";
    this->m_status = hms::status::unknown;
    result = EXIT_FAILURE;
  }
  return result;
}

auto hms::network::manager::check_status() -> hms::status::type_t
{
  return this->m_status;
}

auto hms::network::manager::get_status_info() -> hms::status::info
{
  hms::status::info sys_info {};
  sys_info.system_name = this->m_name;
  sys_info.status = this->m_status;
  sys_info.msg = std::string("");
  return sys_info;
}

auto hms::network::manager::get_subsystem_type() -> hms::subsystem_t
{
  return hms::network::manager::m_type;
}


