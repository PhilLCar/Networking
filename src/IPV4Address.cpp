#include <IPV4Address.hpp>

namespace std {
  string to_string(Networking::IPV4Address address) {
    return address.addr_str + ":" + to_string(address._port);
  }
}

namespace Networking {
  IPV4Address::IPV4Address(const char *address) {
    std::string current = "";
    int b = 4;
    for (int i = 0; address[i]; i++) {
      char c = address[i];
      if (c != '.' && c != ':') {
        current += c;
      } else {
        bytes[--b] = std::stoi(current);
        current = "";
      }
    }
    _port    = std::stoi(current);
    addr_str = std::to_string(bytes[3]) + "." +
               std::to_string(bytes[2]) + "." +
               std::to_string(bytes[1]) + "." +
               std::to_string(bytes[0]);
  }

  IPV4Address::IPV4Address(const unsigned int address, const unsigned short port)
    : addr_int(address)
    , _port(port)
  {
    addr_str = std::to_string(bytes[3]) + "." +
               std::to_string(bytes[2]) + "." +
               std::to_string(bytes[1]) + "." +
               std::to_string(bytes[0]);
  }
}
