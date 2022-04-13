#ifndef INITBT_H_
#define INITBT_H_

#include "bt.h"

// 初始化二叉树
class InitBt {
private:
    Bt *root;

public:
    InitBt() : root(nullptr){};
    Bt *initBt(Bt *root, int length);  // 初始化 length 长度的二叉树
};

#endif