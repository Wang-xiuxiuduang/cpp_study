#include "../headerFile/zero_one_bag.h"

#include <iostream>
#include <vector>
using std::vector;

// 二维数组
int ZeroOneBag::getBigResult1(const vector<int>& weight, const vector<int>& value) {
    int bagWeight = 4;
    // 定义 dp 数组  行——物品数量  列——背包容量
    vector<vector<int>> dp(value.size(), vector<int>(bagWeight + 1, 0));
    // 当背包中只装第 0 个物品时，最大价值为第 0 个物品的价值
    for (int j = weight[0]; j <= bagWeight; ++j) {
        dp[0][j] = value[0];
    }

    // 先遍历物品，后遍历背包
    for (int i = 1; i < weight.size(); ++i) {
        for (int j = 0; j <= bagWeight; ++j) {
            // 如果不装物品 i 的话
            if (j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    // std::cout << "dp array: " << std::endl;
    // for (int i = 0; i <= weight.size(); ++i) {
    //     for (int j = 0; j <= bagWeight; ++j) {
    //         std::cout << dp[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return dp[weight.size() - 1][bagWeight];
}

// 滚动数组
int ZeroOneBag::getBigResult2(const vector<int>& weight, const vector<int>& value) {
    int bagWeight = 4;
    int weightSize = weight.size();
    vector<int> dp(bagWeight + 1, 0);
    for (int i = 0; i < weightSize; ++i) {
        for (int j = bagWeight; j >= weight[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
        for (int i = 0; i <= bagWeight; ++i) {
            std::cout << dp[i] << " ";
        }
        std::cout << std::endl;
    }
    return dp[bagWeight];
}
