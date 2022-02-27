#include <GeneralUtility.h>
#include "Catch2.h"
#include <string>

// Tests that the Ord method works with characters in a string
TEST_CASE(__FILE__"/WorksWithCharsInString", "[Ord]")
{
    const std::string set = "0123456789abcdef";

    REQUIRE(GeneralUtility::Ord('0', set) == 0);
    REQUIRE(GeneralUtility::Ord('1', set) == 1);
    REQUIRE(GeneralUtility::Ord('2', set) == 2);
    REQUIRE(GeneralUtility::Ord('3', set) == 3);
    REQUIRE(GeneralUtility::Ord('4', set) == 4);
    REQUIRE(GeneralUtility::Ord('5', set) == 5);
    REQUIRE(GeneralUtility::Ord('6', set) == 6);
    REQUIRE(GeneralUtility::Ord('7', set) == 7);
    REQUIRE(GeneralUtility::Ord('8', set) == 8);
    REQUIRE(GeneralUtility::Ord('9', set) == 9);
    REQUIRE(GeneralUtility::Ord('a', set) == 10);
    REQUIRE(GeneralUtility::Ord('b', set) == 11);
    REQUIRE(GeneralUtility::Ord('c', set) == 12);
    REQUIRE(GeneralUtility::Ord('d', set) == 13);
    REQUIRE(GeneralUtility::Ord('e', set) == 14);
    REQUIRE(GeneralUtility::Ord('f', set) == 15);
}
