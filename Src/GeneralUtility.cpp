#include "GeneralUtility.h"
#include <string>
#include <sstream>
#include <stdexcept>

// Fast 64-bit int power function
std::uint64_t Powuli(const std::uint64_t& b, const std::uint64_t& e) {
    std::uint64_t buf = 1;

    for (std::uint64_t i = 0; i < e; i++)
        buf *= b;

    return buf;
}

std::uint64_t GeneralUtility::BaseX_2_10(const std::string& num, const std::string& set) {
    unsigned long long int buf = 0;
    for (std::size_t i = 0; i < num.length(); i++) {
        for (std::size_t j = 0; j < set.length(); j++) {
            if (num[i] == set[j]) {
                buf += Powuli((std::uint64_t)set.length(), (uint64_t)(num.length() - (i + 1))) * j;
                break;
            }
        }
    }

    return buf;
}

// Based on: https://www.geeksforgeeks.org/divide-large-number-represented-string/
std::pair<std::string, int>
GeneralUtility::StringDivision(const std::string& dividend, const unsigned int divisor, const std::string& set) {
    // No set? Throw logic error
    if (set.length() == 0)
        throw std::logic_error("Can't divide a number of base0! Please supple a nonempty set!");
    // No division by 0
    if (divisor == 0)
        throw std::overflow_error("Division by zero!");

    // As result can be very large store it in string
    std::stringstream ss;

    // Find prefix of number that is larger than divisor.
    int idx = 0;
    int temp = Ord(dividend[idx], set);
    while (temp < divisor)
        temp = temp * set.length() + Ord(dividend[++idx], set);

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    int curRest = temp % divisor;
    while (dividend.size() > idx) {
        // Store result in answer i.e. temp / divisor
        ss << (char)(set[(temp / divisor)]);
        curRest = temp % divisor;

        // Take next digit of number
        temp = (temp % divisor) * set.length() + Ord(dividend[++idx], set);
    }

    // If divisor is greater than number
    if (ss.str().length() == 0)
    {
        // Generate 0-value string
        std::stringstream ss;
        ss << set[0];
        return std::make_pair(ss.str(), BaseX_2_10(dividend, set));
    }

    // else return the answer
    return std::make_pair(ss.str(), curRest);
}
