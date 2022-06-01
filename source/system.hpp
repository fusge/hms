
#include <array>
#include <string>

namespace HMS
{
enum subsystem_t
{
  DEVICE = 0,
  TASK,
  EVENT,
  NETWORK,
  PLUGIN,
  LOGGER
};

enum status_t
{
  RUNNING,
  STOPPED,
  UNKNOWN
};

struct subsystem_status
{
  std::string system_name;
  int subsystem_id;
  subsystem_t subsystem_type;
  status_t status;
  std::string msg;
};

class Subsystem
{
public:
  virtual int startup()=0;
  virtual int shutdown()=0;
  virtual int restart()=0;
  virtual int check_status(subsystem_status* status)=0;
};

class System
{
public:
  System();
  ~System();

  int startup();
  int shutdown();
  int restart_subsystem(int subsystem_id);
  int check_subsystem_status(subsystem_t subsystem, subsystem_status* status);
  int check_all_subsystems_status(
      std::array<subsystem_status, LOGGER>* status_list);

private:
  std::string owner_name;
  std::string home_address;
  std::array<Subsystem*, LOGGER> subsystems;
};

}  // namespace HMS