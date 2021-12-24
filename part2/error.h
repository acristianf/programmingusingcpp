#ifndef GUARD_error_h
#define GUARD_error_h

#include <string>
#include <stdexcept>
  
inline void error(std::string msg, std::string fn = "")
{
    throw std::runtime_error(msg + fn);
}

#endif