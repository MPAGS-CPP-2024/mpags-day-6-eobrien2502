//! Unit Tests for MPAGSCipher processCommandLine interface
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("Help found correctly", "[commandline]")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--help"};
    const ProgramSettings res{processCommandLine(cmdLine)};

    REQUIRE(settings.helpRequested);
}

TEST_CASE("Version found correctly", "[commandline]")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--version"};
    const ProgramSettings res{processCommandLine(cmdLine)};

    
    REQUIRE(settings.versionRequested);
}

TEST_CASE("Encrypt mode activated")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--encrypt"};
    const ProgramSettings res{processCommandLine(cmdLine)};

    
    REQUIRE(settings.cipherMode == CipherMode::Encrypt);
}

TEST_CASE("Decrypt mode activated")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--decrypt"};
    const ProgramSettings res{processCommandLine(cmdLine)};

    
    REQUIRE(settings.cipherMode == CipherMode::Decrypt);
}

/*TEST_CASE("Key entered with no key specified")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-k"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}
*/

TEST_CASE("Key entered with key specified")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-k", "4"};
    const ProgramSettings res{processCommandLine(cmdLine)};

   
    REQUIRE(settings.cipherKey.size() == 1);
    REQUIRE(settings.cipherKey[0] == "4");
}
/*
TEST_CASE("Input file declared without using input file")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-i"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Input file declared")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-i", "input.txt"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.inputFile == "input.txt");
}

TEST_CASE("Output file declared without specifying output file")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-o"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Output file declared")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-o", "output.txt"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.outputFile == "output.txt");
}

TEST_CASE("Cipher type declared without specifying cipher")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Cipher type declared with unknown cipher")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c", "rubbish"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Cipher type declared with Caesar cipher")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c", "caesar"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.cipherType.size() == 1);
    REQUIRE(settings.cipherType[0] == CipherType::Caesar);
}

TEST_CASE("Cipher type declared with Playfair cipher")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c", "playfair"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.cipherType.size() == 1);
    REQUIRE(settings.cipherType[0] == CipherType::Playfair);
}

TEST_CASE("Cipher type declared with Vigenere cipher")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "-c", "vigenere"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.cipherType.size() == 1);
    REQUIRE(settings.cipherType[0] == CipherType::Vigenere);
}

TEST_CASE("Multi-cipher with no following argument")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--multi-cipher"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Multi-cipher with invalid following argument")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher", "--multi-cipher", "a"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Multi-cipher with mismatching number of cipher-type/keys specified")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{
        "mpags-cipher", "--multi-cipher", "2", "-c", "caesar", "-k", "23"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(!res);
}

TEST_CASE("Multi-cipher with matching number of cipher-type/keys specified")
{
    ProgramSettings settings{false, false, "", "", {}, {}, CipherMode::Encrypt};
    const std::vector<std::string> cmdLine{"mpags-cipher",
                                           "--multi-cipher",
                                           "2",
                                           "-c",
                                           "caesar",
                                           "-k",
                                           "23",
                                           "-c",
                                           "playfair",
                                           "-k",
                                           "playfairexample"};
    const bool res{processCommandLine(cmdLine, settings)};

    REQUIRE(res);
    REQUIRE(settings.cipherType.size() == 2);
    REQUIRE(settings.cipherType[0] == CipherType::Caesar);
    REQUIRE(settings.cipherType[1] == CipherType::Playfair);
    REQUIRE(settings.cipherKey.size() == 2);
    REQUIRE(settings.cipherKey[0] == "23");
    REQUIRE(settings.cipherKey[1] == "playfairexample");
}
*/