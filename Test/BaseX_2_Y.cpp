#include <GeneralUtility.h>
#include "Catch2.h"

// Tests base 10 to 10
TEST_CASE(__FILE__"/Base10_to_10", "[BaseX_2_Y]")
{
    // Setup
    const std::string set_in  = "0123456789";
    const std::string set_out = "0123456789";
    const std::string in           = "1990381";
    const std::string expected_out = "1990381";

    // Exercise
    const std::string out = GeneralUtility::BaseX_2_Y(in, set_in, set_out);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 10 to 16
TEST_CASE(__FILE__"/Base10_to_16", "[BaseX_2_Y]")
{
    // Setup
    const std::string set_in  = "0123456789";
    const std::string set_out = "0123456789abcdef";
    const std::string in           = "1990381";
    const std::string expected_out = "1e5eed";

    // Exercise
    const std::string out = GeneralUtility::BaseX_2_Y(in, set_in, set_out);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 16 to 10
TEST_CASE(__FILE__"/Base16_to_10", "[BaseX_2_Y]")
{
    // Setup
    const std::string set_in  = "0123456789abcdef";
    const std::string set_out = "0123456789";
    const std::string in           = "1e5eed";
    const std::string expected_out = "1990381";

    // Exercise
    const std::string out = GeneralUtility::BaseX_2_Y(in, set_in, set_out);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 2 to 16
TEST_CASE(__FILE__"/Base2_to_16", "[BaseX_2_Y]")
{
    // Setup
    const std::string set_in  = "01";
    const std::string set_out = "0123456789abcdef";
    const std::string in           = "110000110001110011010111101011111";
    const std::string expected_out = "18639af5f";

    // Exercise
    const std::string out = GeneralUtility::BaseX_2_Y(in, set_in, set_out);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests base 16 to 2
TEST_CASE(__FILE__"/Base16_to_2", "[BaseX_2_Y]")
{
    // Setup
    const std::string set_in  = "0123456789abcdef";
    const std::string set_out = "01";
    const std::string in           = "18639af5f";
    const std::string expected_out = "110000110001110011010111101011111";

    // Exercise
    const std::string out = GeneralUtility::BaseX_2_Y(in, set_in, set_out);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests that padding works
TEST_CASE(__FILE__"/TestPadding_ResultSmallEnough", "[BaseX_2_Y]")
{
    // Setup
    const std::string set_in  = "0123456789";
    const std::string set_out = "01";
    const std::string in           = "3";
    const std::string expected_out = "00000011"; // We are expecting the output to be padded to 8 digits.

    // Exercise
    const std::string out = GeneralUtility::BaseX_2_Y(in, set_in, set_out, 8);

    // Verify
    REQUIRE(out == expected_out);
}

// Tests that nothing gets padded if the result is longer than the pad-length
TEST_CASE(__FILE__"/TestPadding_ResultLargerThanPad", "[BaseX_2_Y]")
{
    // Setup
    const std::string set_in  = "0123456789";
    const std::string set_out = "01";
    const std::string in           = "500";
    const std::string expected_out = "111110100";

    // Exercise
    const std::string out = GeneralUtility::BaseX_2_Y(in, set_in, set_out, 8);

    // Verify
    REQUIRE(out == expected_out);
}
