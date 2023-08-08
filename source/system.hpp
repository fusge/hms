
#ifndef SYSTEM_H
#define SYSTEM_H

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
    system(const system& sys)=delete;
    auto operator=(system sys) -> system& = delete;
    system(system&& sys)=delete;
    auto operator=(system&& sys) -> system& = delete;
    ~system();
  
    int startup();
    int shutdown();
    int restart_subsystem(int subsystem_id);
    hms::status::info check_subsystem_status(hms::subsystem_t subsystem);
    std::vector<hms::status::info> check_all_subsystems_status();
  
  private:
    std::string m_owner_name;
    std::string m_home_address;
    std::vector<std::unique_ptr<subsystem>> m_subsystems;
};

}  // namespace hms

#endif
