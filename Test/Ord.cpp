#include <GeneralUtility.h>
#include "Catch2.h"
#include <string>
#include <vector>

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

// Tests that, if an object is not found, -1 is returned
TEST_CASE(__FILE__"/ReturnsNeg1IfNotFound", "[Ord]")
{
    const std::string set = "0123456789abcdef";

    REQUIRE(GeneralUtility::Ord('z', set) == -1);
}

// Tests that Ord works with vectors <string>
TEST_CASE(__FILE__"/WorksWithVector_String", "[Ord]")
{
    const std::vector<std::string> vec = { "Apple", "Banana", "Tomato", "Olives" };

    REQUIRE(GeneralUtility::Ord(std::string("Apple"), vec) == 0);
    REQUIRE(GeneralUtility::Ord(std::string("Banana"), vec) == 1);
    REQUIRE(GeneralUtility::Ord(std::string("Tomato"), vec) == 2);
    REQUIRE(GeneralUtility::Ord(std::string("Olives"), vec) == 3);

    INFO("Now testing that unknown is -1");
    REQUIRE(GeneralUtility::Ord(std::string("Pepper"), vec) == -1);
}

// Tests that Ord works with vectors <int>
TEST_CASE(__FILE__"/WorksWithVector_Int", "[Ord]")
{
    const std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (std::size_t i = 0 ; i < 10; i++)
        REQUIRE(GeneralUtility::Ord((int)i, vec) == i);

    INFO("Now testing that unknown is -1");
    REQUIRE(GeneralUtility::Ord((int)99, vec) == -1);
}
