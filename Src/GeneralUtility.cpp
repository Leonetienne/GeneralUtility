#include "GeneralUtility.h"
#include <string>

std::string GeneralUtility::Base10_2_X(const std::uint64_t &num, const std::string &set, const std::uint32_t minOutLen) {
    // Convert num to a string
    std::stringstream ss;
    ss << num;
    const std::string numStr = ss.str();

    // Use BaseX_2_Y to convert to outbase
    const std::string convertedNum = BaseX_2_Y<std::string, std::string>(numStr, "0123456789", set, minOutLen);

    // return it
    return convertedNum;
}
