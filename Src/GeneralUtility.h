#ifndef GENERALUTILITY_GENERALUTILITY_H
#define GENERALUTILITY_GENERALUTILITY_H

#include <algorithm>
#include <utility>

class GeneralUtility {
public:
    //! Will return the index of `item` in `set`.
    //! \tparam T_Type The type of `item`
    //! \tparam T_Container The type of container
    //! \param item The item to find the index for
    //! \param set The container to be looking in
    //! \return The index of `item` in `set`. -1 if not found.
    template <typename T_Type, class T_Container>
    static int Ord(const T_Type& item, const T_Container& set);

    //! Will divide a number of arbitrary base in `dividend` by an integer divisor.
    //! This is a specific helper function for the base conversion functions.
    //! \param dividend The number to be divided in string form
    //! \param divisor The integer divisor
    //! \param set The set/base of `dividend`
    //! \return A pair of the result. (result, rest)
    static std::pair<std::string, int> StringDivision(const std::string& dividend, const unsigned int divisor, const std::string& set = "0123456789");

    //! Will convert a number of arbitrary base to base 10
    //! \param num A string representing the number
    //! \param set The set/base of the number
    //! \return A 64-bit integer representing the number
    static std::uint64_t BaseX_2_10(const std::string& num, const std::string& set);

    //! Will convert a number to an arbitrary base.
    //! This just a wrapper for BaseX_2_Y.
    //! \param num The number to be converted
    //! \param set The desired set/base for the output to be in
    //! \return `num` in base `set`
    static std::string Base10_2_X(const std::uint64_t& num, const std::string& set, const std::uint32_t minOutLen = 1);

    //! Will convert a number from an arbitrary base to another arbitrary base.
    //! \param num A string representation of a number
    //! \param set_in The set/base of the input
    //! \param set_out The desired set/base to output
    //! \param minLen The minimum output length. Setting this will result in zero-padded output (Like, 00000001 instead of 1)
    //! \return `num` in base `set_out`
    static std::string BaseX_2_Y(const std::string& num, const std::string& set_in, const std::string& set_out, const std::uint32_t minOutLen = 1);

private:
    // No instantiation! >:(
    GeneralUtility();
};

template<typename T_Type, class T_Container>
int GeneralUtility::Ord(const T_Type& item, const T_Container& set) {
    const auto result =
            std::find_if(set.begin(), set.end(), [item](const T_Type& c) -> bool {
                return c == item;
            });

    // No item found
    if (result == set.end())
        return -1;
    else
        return result - set.begin();
}

#endif //GENERALUTILITY_GENERALUTILITY_H
