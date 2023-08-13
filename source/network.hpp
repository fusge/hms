#ifndef NETWORK_H
#define NETWORK_H

#include "subsystem.hpp"

namespace hms::network
{
class manager : public hms::subsystem
{
  public:
  auto startup() -> int override;
  auto shutdown() -> int override;
  auto restart() -> int override;
  auto check_status() -> hms::status::type_t override;
  auto get_status_info() -> hms::status::info override;
  auto get_subsystem_type() -> hms::subsystem_t override;

  private:
  static const hms::subsystem_t m_type = hms::network_t;
  std::string_view m_name = "Network Manager";
  hms::status::type_t m_status;
};

class protocol
{
public:
  protocol(const protocol&) = default;
  protocol(protocol&&) = delete;
  protocol& operator=(const protocol&) = default;
  protocol& operator=(protocol&&) = delete;
  virtual ~protocol() = default;
  virtual auto configure() -> int = 0;
};

}  // namespace hms::network

#endif
