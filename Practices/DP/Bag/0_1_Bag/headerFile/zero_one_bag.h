#ifndef ZERO_ONE_BAG_H
#define ZERO_ONE_BAG_H

#include <vector>

using std::vector;

class ZeroOneBag {
public:
    // 二维数组
    int getBigResult1(const vector<int>& weight, const vector<int>& value);
    // 滚动数组
    int getBigResult2(const vector<int>& weight, const vector<int>& value);
};

#endif