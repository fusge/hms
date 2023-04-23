
#include <vector>
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
  logger_t,
  unknown_t
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
  subsystem(const subsystem&) = delete;
  subsystem& operator=(const subsystem&) = delete;
  subsystem(subsystem&&) = delete;
  subsystem& operator=(subsystem&&) = delete;
  virtual ~subsystem() = default;

  virtual int startup() = 0;
  virtual int shutdown() = 0;
  virtual int restart() = 0;
  virtual int check_status(subsystem_status* status) = 0;
};

class subsystem_factory
{
public:
  int init_subsystem(hms::subsystem_t system_type,
                     hms::subsystem * sub_system);
};

class system
{
public:
  system();
  system(const system&) = delete;
  system& operator=(const system&) = delete;
  system(system&&) = delete;
  system& operator=(system&&) = delete;
  ~system();

  int startup();
  int shutdown();
  int restart_subsystem(int subsystem_id);
  int check_subsystem_status(subsystem_t subsystem, subsystem_status status);
  int check_all_subsystems_status(const std::vector<subsystem_status>& status_list);

private:
  std::string m_owner_name;
  std::string m_home_address;
  std::vector<subsystem*> m_subsystems;
};

}  // namespace hms
