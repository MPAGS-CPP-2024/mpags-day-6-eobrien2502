#ifndef MPAGSCIPHER_INVALIDKEY_HPP
#define MPAGSCIPHER_INVALIDKEY_HPP

#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"

#include <cstddef>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

/**
 * \file InvalidKey.hpp
 * \brief Contains the declaration of the InvalidKey class
 */

/**
 * \class InvalidKey
 * \brief An exception class to deal with the case when a key supplied to a cipher is invalid
 */
class InvalidKey : public std::invalid_argument {
    public:
        InvalidKey(const std::string& invk);
};



#endif