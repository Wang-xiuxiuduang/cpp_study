#ifndef ERGODIC_H_
#define ERGODIC_H_

#include <vector>

#include "bt.h"

using namespace std;

class Ergodic {
private:
    vector<int> orderResult;

public:
    Ergodic();
    void preOrder(Bt *root);     // 先序遍历
    void middleOrder(Bt *root);  // 中序遍历
    void poseOrder(Bt *root);    // 后序遍历
    void printfOrderResult();    // 打印 orderResult
};

#endif