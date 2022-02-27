#include <GeneralUtility.h>
#include "Catch2.h"

// Tests base 10 to 10
TEST_CASE(__FILE__"/Base10_to_10", "[Base10_2_X]")
{
    // Setup
    const std::string set = "0123456789";
    const std::uint64_t in         =  1990381;
    const std::string expected_out = "1990381";

    // Exercise
    const std::string out = GeneralUtility::Base10_2_X(in, set);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 10 to 16
TEST_CASE(__FILE__"/Base10_to_16", "[Base10_2_X]")
{
    // Setup
    const std::string set = "0123456789abcdef";
    const std::uint64_t in         =  0x1990381;
    const std::string expected_out = "1990381";

    // Exercise
    const std::string out = GeneralUtility::Base10_2_X(in, set);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 10 to 2
TEST_CASE(__FILE__"/Base10_to_2", "[Base10_2_X]")
{
    // Setup
    const std::string set = "01";
    const std::uint64_t in         = 0b10111011;
    const std::string expected_out =  "10111011";

    // Exercise
    const std::string out = GeneralUtility::Base10_2_X(in, set);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 10 to fucking big
TEST_CASE(__FILE__"/Base10_to_FuckingBig", "[Base10_2_X]")
{
    // Setup
    const std::string set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const std::uint64_t in =  189434143264827;
    const std::string expected_out = "rn5qZuTD";

    // Exercise
    const std::string out = GeneralUtility::Base10_2_X(in, set);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests that padding works
TEST_CASE(__FILE__"/TestPadding", "[Base10_2_X]")
{
    // Setup
    const std::string set = "01";
    const std::uint64_t in         = 0b101;
    const std::string expected_out =  "00000101";

    // Exercise
    const std::string out = GeneralUtility::Base10_2_X(in, set, 8);

    // Verify
    REQUIRE(out == expected_out);
}
