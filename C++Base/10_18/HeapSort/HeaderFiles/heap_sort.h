#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <iostream>
#include <vector>
using std::vector;

class HeapSort {
public:
    HeapSort() {}
    ~HeapSort() {}
    HeapSort(const HeapSort&);
    void getHeap(vector<int>& targetVector);
    void showHeap();
    void getRandomArray(vector<int>& arr, const int& length);
};

#endif