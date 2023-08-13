#include <memory>
#include <iostream>

#ifdef _WIN32
#define _WIN32_WINNT 0X0A00
#endif

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>
#include <entt/entt.hpp>

#include "system.hpp"

int main()
{
  std::string github_addr = "140.82.114.4";
  std::string local_addr = "192.168.1.1";
  asio::error_code ec;
  asio::io_context context;

  asio::ip::tcp::endpoint endpoint(asio::ip::make_address(local_addr, ec), 80);
  asio::ip::tcp::socket socket(context);
  socket.connect(endpoint, ec);

  if (!ec) {
    std::cout << "Connected to endpoint with ip address " << endpoint.address().to_string() << std::endl;
  } else {
    std::cout << "ERROR: Unable to connect to endpoint " << ec.message() << std::endl;
    return -1;
  }


  auto system = std::make_unique<hms::system>();
  return 0;
}
