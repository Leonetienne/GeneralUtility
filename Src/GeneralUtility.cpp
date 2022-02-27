#include "GeneralUtility.h"
#include <string>
#include <sstream>
#include <stdexcept>

namespace {
    // Fast 64-bit int power function
    inline std::uint64_t Powuli(const std::uint64_t &b, const std::uint64_t &e) {
        std::uint64_t buf = 1;

        for (std::uint64_t i = 0; i < e; i++)
            buf *= b;

        return buf;
    }
}

std::uint64_t GeneralUtility::BaseX_2_10(const std::string& num, const std::string& set) {
    // If base is 0, throw logic error
    if (set.length() == 0)
        throw std::logic_error("Can't convert from base0! Please supply a nonempty set!");

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
        throw std::logic_error("Can't divide a number of base0! Please supply a nonempty set!");
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

std::string GeneralUtility::BaseX_2_Y(const std::string &num, const std::string &set_in, const std::string &set_out, const std::uint32_t minOutLen) {
    if ((set_in.length() == 0) || (set_out.length() == 0))
        throw std::logic_error("Can't convert from or to base0! Please supply a nonempty set!");

    std::stringstream ss;

    // Generate a 0-value string for inbase
    ss << set_in[0];
    const std::string zeroInbase = ss.str();
    ss.str("");


    if (num != zeroInbase) {

        std::string buf = num;
        while (buf != zeroInbase) {
            const auto divRes = StringDivision(buf, set_out.length(), set_in);
            const std::uint64_t mod = divRes.second;
            buf = divRes.first;
            ss << set_out[mod];
        }

        // Now reverse buf
        buf = ss.str();
        ss.str("");
        for (std::size_t i = 0; i < buf.length(); i++)
            ss << buf[buf.length() - i - 1];
    }
    else
    {
        // If num is 0, just pass a null-value. The algorithm would hang otherwise.
        ss << set_out[0];
    }


    // Add as much null-values to the left as requested.
    if (ss.str().length() < minOutLen)
    {
        const std::size_t cachedLen = ss.str().length();
        const std::string cachedStr = ss.str();
        ss.str("");
        for (std::size_t i = 0; i < minOutLen - cachedLen; i++)
            ss << set_out[0];
        ss << cachedStr;
    }

    return ss.str();
}

std::string GeneralUtility::Base10_2_X(const std::uint64_t &num, const std::string &set, const std::uint32_t minOutLen) {
    // Convert num to a string
    std::stringstream ss;
    ss << num;
    const std::string numStr = ss.str();

    // Use BaseX_2_Y to convert to outbase
    const std::string convertedNum = BaseX_2_Y(numStr, "0123456789", set, minOutLen);

    // return it
    return convertedNum;
}
