#include <GeneralUtility.h>
#include "Catch2.h"

// Tests base 10 to 10
TEST_CASE(__FILE__"/Base10_to_10", "[BaseX_2_10]")
{
    // Setup
    const std::string set = "0123456789";
    const std::string in             = "1990381";
    const std::uint64_t expected_out =  1990381;

    // Exercise
    const std::uint64_t out = GeneralUtility::BaseX_2_10(in, set);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 16 to 10
TEST_CASE(__FILE__"/Base16_to_10", "[BaseX_2_10]")
{
    // Setup
    const std::string set = "0123456789abcdef";
    const std::string in             =  "1a83f9cefa";
    const std::uint64_t expected_out = 0x1a83f9cefa;

    // Exercise
    const std::uint64_t out = GeneralUtility::BaseX_2_10(in, set);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 2 to 10
TEST_CASE(__FILE__"/Base2_to_10", "[BaseX_2_10]")
{
    // Setup
    const std::string set = "01";
    const std::string in             =  "10101010110000111111";
    const std::uint64_t expected_out = 0b10101010110000111111;

    // Exercise
    const std::uint64_t out = GeneralUtility::BaseX_2_10(in, set);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base fucking big to 10
TEST_CASE(__FILE__"/BaseFuckingBig_to_10", "[BaseX_2_10]")
{
    // Setup
    const std::string set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const std::string in =  "rn5qZuTD";
    const std::uint64_t expected_out = 189434143264827;

    // Exercise
    const std::uint64_t out = GeneralUtility::BaseX_2_10(in, set);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests that a logic error is thrown when the supplied set is empty
TEST_CASE(__FILE__"/NoSetSupplied", "[BaseX_2_10]")
{
    REQUIRE_THROWS_AS(
            GeneralUtility::BaseX_2_10("699", "")
    , std::logic_error);
}
