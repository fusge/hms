#ifndef SUBSYSTEM_H
#define SUBSYSTEM_H

#include <string>
#include <array>

namespace hms
{
enum subsystem_t : int
{
  device_t,
  task_t,
  event_t,
  network_t,
  plugin_t,
  logger_t,
  unknown_t
};

const std::array<subsystem_t, 7> ALL_SUBSYSTEM_TYPES {device_t, task_t, // NOLINT
                                                      event_t, network_t, 
                                                      plugin_t, logger_t, 
                                                      unknown_t};

namespace status
{
enum type
{
  running,
  stopped,
  unknown
};

struct info
{
  std::string system_name;
  subsystem_t subsystem_type;
  hms::status::type status;
  std::string msg;
};
}  // namespace status

class subsystem
{
public:
  virtual auto startup() -> int = 0;
  virtual auto shutdown() -> int = 0;
  virtual auto restart() -> int = 0;
  virtual auto check_status() -> hms::status::type = 0;
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