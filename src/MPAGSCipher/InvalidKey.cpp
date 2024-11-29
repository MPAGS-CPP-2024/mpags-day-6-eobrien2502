#include "InvalidKey.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

InvalidKey::InvalidKey(const std::string& invk) : std::invalid_argument{invk}
{
    
}