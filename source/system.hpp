
#include <array>
#include <string>

namespace hms
{
enum subsystem_t
{
  device_t = 0,
  task_t,
  event_t,
  network_t,
  plugin_t,
  logger_t
};

enum status_t
{
  running,
  stopped,
  unknown
};

struct subsystem_status
{
  std::string system_name;
  int subsystem_id;
  subsystem_t subsystem_type;
  status_t status;
  std::string msg;
};

class subsystem
{
public:
  virtual auto startup() -> int = 0;
  virtual auto shutdown() -> int = 0;
  virtual auto restart() -> int = 0;
  virtual auto check_status(subsystem_status* status) -> int = 0;
};

class subsystem_factory
{
public:
  auto init_subsystem(hms::subsystem_t system_type,
                      hms::subsystem * sub_system) -> int;
};

class system
{
public:
  system();
  ~system();

  auto startup() -> int;
  auto shutdown() -> int;
  auto restart_subsystem(int subsystem_id) -> int;
  auto check_subsystem_status(subsystem_t subsystem, subsystem_status* status)
      -> int;
  auto check_all_subsystems_status(
      std::array<subsystem_status, logger_t>* status_list) -> int;

private:
  std::string m_owner_name;
  std::string m_home_address;
  std::array<subsystem*, hms::logger_t> m_subsystems;
};

}  // namespace hms