#include <iostream>
#include <vector>

#include "headerFile/zero_one_bag.h"

int main() {
    std::vector<int> weight = {1, 3, 4};
    std::vector<int> value = {15, 20, 30};
    ZeroOneBag zeroOneBag;
    int result = zeroOneBag.getBigResult1(weight, value);
    std::cout << "result1: " << result << std::endl;
    result = zeroOneBag.getBigResult2(weight, value);
    std::cout << "result2: " << result << std::endl;
    return 0;
}