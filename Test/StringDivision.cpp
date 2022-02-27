#include <GeneralUtility.h>
#include "Catch2.h"
#include <string>
#include <vector>
#include <time.h>
#include <sstream>

// Tests that basic division (base10) is working, with oracle values
TEST_CASE(__FILE__"/Base10", "[StringDivision]")
{
    const std::string set = "0123456789";

    SECTION("No rest") {
        const auto res = GeneralUtility::StringDivision("200", 10, set);
        REQUIRE(res.first == "20");
        REQUIRE(res.second == 0);
    }

    SECTION("With rest") {
        const auto res = GeneralUtility::StringDivision("205", 10, set);
        REQUIRE(res.first == "20");
        REQUIRE(res.second == 5);
    }

    SECTION("With rest, and divisor > dividend") {
        const auto res = GeneralUtility::StringDivision("205", 299, set);
        REQUIRE(res.first == "0");
        REQUIRE(res.second == 205);
    }
}

// Tests that basic division (base10) is working, by doing a lot of random, precalculated divisions
TEST_CASE(__FILE__"/Base10_Randoms", "[StringDivision]")
{
    srand(time(0));
    const std::string set = "0123456789";

    // Test 1000 random numbers
    for (std::size_t i = 0; i < 1000; i++) {
        // Generate random input
        const std::uint64_t i_dividend = rand();
        const std::uint32_t i_divisor = rand() % 1000000;

        // Precalculate expected output
        const std::uint32_t expected_result = i_dividend / i_divisor;
        const std::uint32_t expected_rest   = i_dividend % i_divisor;

        // Convert dividend to a string
        std::stringstream ss;
        ss << i_dividend;
        const std::string dividend = ss.str();

        // Compute results
        const auto res = GeneralUtility::StringDivision(dividend, i_divisor, set);
        const std::uint32_t actual_result = std::stoi(res.first);
        const std::uint32_t actual_rest   = res.second;

        // Assertions
        REQUIRE(actual_result == expected_result);
        REQUIRE(actual_rest == expected_rest);
    }
}

// Tests that base16 division is working, with oracle values
TEST_CASE(__FILE__"/Base16", "[StringDivision]")
{
    const std::string set = "0123456789abcdef";

    SECTION("No rest") {
        const auto res = GeneralUtility::StringDivision("1f4", 10, set);
        REQUIRE(res.first == "32");
        REQUIRE(res.second == 0);
    }

    SECTION("With rest") {
        const auto res = GeneralUtility::StringDivision("1fd", 10, set);
        REQUIRE(res.first == "32");
        REQUIRE(res.second == 9);
    }

    SECTION("With rest, and divisor > dividend") {
        const auto res = GeneralUtility::StringDivision("1f4", 999, set);
        REQUIRE(res.first == "0");
        REQUIRE(res.second == 500);
    }
}

// Tests that base2 division is working, with oracle values
TEST_CASE(__FILE__"/Base2", "[StringDivision]")
{
    const std::string set = "01";

    SECTION("No rest") {
        const auto res = GeneralUtility::StringDivision("111110100", 10, set);
        REQUIRE(res.first == "110010");
        REQUIRE(res.second == 0);
    }

    SECTION("With rest") {
        const auto res = GeneralUtility::StringDivision("111111011", 10, set);
        REQUIRE(res.first == "110010");
        REQUIRE(res.second == 7);
    }
    SECTION("With rest, and divisor > dividend") {
        const auto res = GeneralUtility::StringDivision("111110100", 599, set);
        REQUIRE(res.first == "0");
        REQUIRE(res.second == 500);
    }
}

// Tests that fucking big bases are working, with oracle values
TEST_CASE(__FILE__"/BaseFuckingBig", "[StringDivision]")
{
    const std::string set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    SECTION("No rest") {
        const auto res = GeneralUtility::StringDivision("9RieQV", 29915, set);
        REQUIRE(res.first == "1DGL");
        REQUIRE(res.second == 0);
    }

    SECTION("With rest") {
        const auto res = GeneralUtility::StringDivision("9RieQZ", 29915, set);
        REQUIRE(res.first == "1DGL");
        REQUIRE(res.second == 4);
    }
    SECTION("With rest, and divisor > dividend") {
        const auto res = GeneralUtility::StringDivision("8x", 600, set);
        REQUIRE(res.first == "0");
        REQUIRE(res.second == 555);
    }
}
