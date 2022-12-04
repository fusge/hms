
#ifndef SYSTEM_H
#define SYSTEM_H

#include <array>
#include <vector>
#include <string>
#include <memory>

#include "subsystem.hpp"

namespace hms
{

class system
{
public:
  system();
  ~system();

  auto startup() -> int;
  auto shutdown() -> int;
  auto restart_subsystem(int subsystem_id) -> int;
  auto check_subsystem_status(hms::subsystem_t subsystem) -> hms::status::info;
  auto check_all_subsystems_status() -> std::vector<hms::status::info>;

private:
  std::string m_owner_name;
  std::string m_home_address;
  std::array<std::unique_ptr<subsystem>, hms::logger_t+1> m_subsystems;
};

}  // namespace hms

#endif