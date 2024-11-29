#include "CaesarCipher.hpp"
#include "MissingArgument.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

MissingArgument::MissingArgument(const std::string& msg) : std::invalid_argument{msg}
{
    
}