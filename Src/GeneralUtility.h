#ifndef GENERALUTILITY_GENERALUTILITY_H
#define GENERALUTILITY_GENERALUTILITY_H

#include <algorithm>
#include <utility>

class GeneralUtility {
public:
    template <typename T_Type, class T_Container>
    static int Ord(const T_Type& item, const T_Container& set);
private:
    // No instanciation! >:(
    GeneralUtility();
};

template<typename T_Type, class T_Container>
int GeneralUtility::Ord(const T_Type &item, const T_Container& set) {
    const auto result =
            std::find_if(set.begin(), set.end(), [item](const char c) -> bool {
                return c == item;
            });

    // No item found
    if (result == set.end())
        return -1;
    else
        return result - set.begin();
}

#endif //GENERALUTILITY_GENERALUTILITY_H
