#include "../HeaderFiles/heap_sort.h"

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

// 根据给定的 targetVector 生成对应的小根堆
void HeapSort::getHeap(vector<int>& targetVector) {
    for (int i = 0; i < targetVector.size(); ++i) {
        // 调整元素在小根堆上的位置
        while (i > 0) {
            if (targetVector[i] >= targetVector[(i - 1) / 2]) {
                break;
            } else {
                swap(targetVector[i], targetVector[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }
    }
    cout << "build heap done" << endl;
}

// 以当前时间为随机种子生成 length 长度的随机数组 arr
void HeapSort::getRandomArray(vector<int>& arr, const int& len) {
    arr.resize(len);
    srand((unsigned)time(0));
    for (int i = 0; i < len; ++i) {
        arr[i] = rand();
    }
}
