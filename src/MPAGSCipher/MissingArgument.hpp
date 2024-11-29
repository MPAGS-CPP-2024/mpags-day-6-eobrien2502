#ifndef MPAGSCIPHER_MISSINGARGUMENT_HPP
#define MPAGSCIPHER_MISSINGARGUMENT_HPP

#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

/**
 * \file MissingArgument.hpp
 * \brief Contains the declaration of the MissingArgument class
 */

/**
 * \class MissingArgument
 * \brief An exception class to deal with the case when an argument is not given
 */
class MissingArgument : public std::invalid_argument {
    public:
        MissingArgument(const std::string& msg);
};



#endif