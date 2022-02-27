#include "GeneralUtility.h"
#include <string>

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
            const auto divRes = DigitstringDivision(buf, set_out.length(), set_in);
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
