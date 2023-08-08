#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include <string>
#include <array>

namespace hms
{
enum subsystem_t : size_t 
{
  device_t,
  task_t,
  event_t,
  network_t,
  plugin_t,
  logger_t,
  unknown_t
};

constexpr std::array<subsystem_t, 7> all_subsystem_types {device_t, task_t, // NOLINT
                                                      event_t, network_t, 
                                                      plugin_t, logger_t, 
                                                      unknown_t};

namespace status
{
enum type_t
{
  running,
  stopped,
  unknown
};

struct info
{
  std::string system_name;
  subsystem_t subsystem_type;
  hms::status::type_t status;
  std::string msg;
};
}  // namespace status

class subsystem
{
public:
  subsystem(const subsystem&) = default;
  subsystem(subsystem&&) = delete;
  subsystem& operator=(const subsystem&) = default;
  subsystem& operator=(subsystem&&) = delete;
  virtual ~subsystem() = default;
  virtual auto startup() -> int = 0;
  virtual auto shutdown() -> int = 0;
  virtual auto restart() -> int = 0;
  virtual auto check_status() -> hms::status::type_t = 0;
  virtual auto get_status_info() -> hms::status::info = 0;
  virtual auto get_subsystem_type() -> hms::subsystem_t = 0;
};

// class subsystem_factory
// {
// public:
//   auto init_subsystem(hms::subsystem_t system_type, hms::subsystem* sub_system)
//       -> int;
// };
}  // namespace hms

#endif
