#ifndef MPAGSCIPHER_UNKNOWNARGUMENT_HPP
#define MPAGSCIPHER_UNKNOWNARGUMENT_HPP

#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

/**
 * \file UnknownArgument.hpp
 * \brief Contains the declaration of the UnknownArgument class
 */

/**
 * \class UnknownArgument
 * \brief A custom exception class to deal with the case when an argument given is not one we were expecting
 */
class UnknownArgument : public std::invalid_argument {
    public:
        UnknownArgument(const std::string& ukn);
};



#endif