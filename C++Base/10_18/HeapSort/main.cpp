#include <ctime>
#include <iostream>
#include <vector>

#include "HeaderFiles/heap_sort.h"

using namespace std;

int main() {
    clock_t start, end;
    start = clock();
    HeapSort m_heapSort;
    vector<int> arr;
    m_heapSort.getRandomArray(arr, 100000);
    m_heapSort.getHeap(arr);
    end = clock();
    cout << "spend time: " << end - start << endl;
    return 0;
}
