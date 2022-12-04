#include <iostream>

#include "network.hpp"

auto hms::network::manager::startup() -> int
{
  std::cout << "Network Subsystem Initialized\n";
  this->status = hms::status::running;
  return 0;
}

auto hms::network::manager::shutdown() -> int
{
  std::cout << "Network Subsystem Shutdown\n";
  this->status = hms::status::stopped;
  return 0;
}

auto hms::network::manager::restart() -> int
{
  int result = 0;
  try{
    this->shutdown();
    this->startup();
  } catch (...){
    std::cerr << "Unable to restart Network Manager\n";
    this->status = hms::status::unknown;
    result = -1;
  }
  this->startup();
}

auto hms::network::manager::check_status() -> hms::status::type
{
  return this->status;
}

auto hms::network::manager::get_status_info() -> hms::status::info
{
  hms::status::info sys_info {};
  sys_info.system_name = this->name;
  sys_info.status = this->status;
  sys_info.msg = std::string("");
  return sys_info;
}

auto hms::network::manager::get_subsystem_type() -> hms::subsystem_t
{
  return this->m_type;
}


