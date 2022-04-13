#include <stdio.h>

// 接收地址
void change(int* a) {
    // 修改 a 所指向的位置上的元素
    *a = 2;
}

int main() {
    int a = 1;
    change(&a);  // 传入地址
    printf("a = %d", a);
    return 0;
}