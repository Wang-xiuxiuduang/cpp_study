#include "../headerFile/ergodic.h"

#include <iostream>
using std::cout;

// 先序遍历
void Ergodic::preOrder(Bt *root) {
    if (root == nullptr) {
        return;
    }
    orderResult.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void Ergodic::preOrder(Bt *root) {
    if (root == nullptr) {
        return;
    }
    preOrder(root->left);
    orderResult.push_back(root->val);
    preOrder(root->right);
}

// 后序遍历
void Ergodic::preOrder(Bt *root) {
    if (root == nullptr) {
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    orderResult.push_back(root->val);
}

// 打印遍历结果
void Ergodic::printfOrderResult() {
    for (auto num = orderResult.begin(); num != orderResult.end(); ++num) {
        cout << *num << " ";
    }
    cout << endl << "遍历结果打印完毕..." << endl;
}
