#include "../headerFile/initBt.h"

#include <cstdlib>

#include "../headerFile/bt.h"

Bt *InitBt::initBt(Bt *root, int length) {
    if (length <= 0) {
        return nullptr;
    }
    root->left = new Bt(rand());
    --length;
    root->right = new Bt(rand());
    --length;
    root = root->left;
    root = root->right;

    for (int i = 0; i < length; ++i) {
        int dic = rand() % 1 + 1;  // 获取 0~1 之间的随机数
        if (dic == 0) {
        }
    }
}
