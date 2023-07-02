#include <string>

namespace std {
  string to_string(Networking::IPV4Address address);
}

namespace Networking {
  struct IPV4Address {
  public:
    IPV4Address(const char *address);
    IPV4Address(const unsigned int address, const unsigned short port);

    inline IPV4Address(const std::string& address) : IPV4Address(address.c_str()) {}
    inline IPV4Address() : IPV4Address(0, 0) {}

  public:
    inline const std::string&   address_str() const { return addr_str; }
    inline       unsigned int   address_int() const { return addr_int; }
    inline       unsigned short port()        const { return _port;    }

    inline bool operator ==(IPV4Address& other) {
      return addr_int == other.addr_int && _port == other._port;
    }

  public:
    friend std::string std::to_string(IPV4Address address);

  private:
    union {
      unsigned char bytes[4];
      unsigned int  addr_int;
    };
    unsigned short _port;
    std::string    addr_str;
  };
}