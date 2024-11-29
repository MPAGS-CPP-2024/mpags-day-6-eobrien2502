#include "UnknownArgument.hpp"

#include <iostream>
#include <string>

UnknownArgument::UnknownArgument(const std::string& unk) : std::invalid_argument{unk}
{
    
}