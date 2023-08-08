#ifndef NETWORK_H
#define NETWORK_H

#include "subsystem.hpp"

namespace hms::network
{
class manager : public hms::subsystem
{
  public:
  manager() : status(hms::status::stopped){}

  auto startup() -> int override;
  auto shutdown() -> int override;
  auto restart() -> int override;
  auto check_status() -> hms::status::type override;
  auto get_status_info() -> hms::status::info override;
  auto get_subsystem_type() -> hms::subsystem_t override;

  private:
  static const hms::subsystem_t m_type = hms::network_t;
  const std::string name = "Network Manager";
  hms::status::type status;
};

class protocol
{
  public:
  virtual auto configure() -> int = 0;
};

}  // namespace hms::network

#endif
