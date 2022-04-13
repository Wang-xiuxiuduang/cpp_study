/**
 * 测试查找算法
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class TestBinarySearch {
private:
    /**
     * 判断 arr 是否有序（升序）
     */
    bool TestSort(const vector<int>& arr) {
        int arr_size = arr.size();
        for (int i = 0, j = 1; j < arr_size; i++, j++) {
            if (arr[i] > arr[j]) {
                return false;
            }
        }
        return true;
    }

public:
    /**
     * 二分查找算法
     */
    int BinarySearch(const vector<int>& arr, const int target) {
        // 判断 arr 是否有序
        if (TestSort(arr)) {
            int arr_size = arr.size();
            int left = 0, right = arr_size - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                cout << "arr[mid] = " << mid << endl;
                if (arr[mid] == target) {
                    left = mid + 1;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else if (arr[mid] > target) {
                    right = mid - 1;
                }
            }
            if (right == -1 || arr[right] != target) {
                return -1;
            }
            return right;
        }
        return -1;
    }
};

int main() {
    srand((unsigned)time(NULL));
    int count = abs(rand() - rand());
    cout << count << endl;
    vector<int> arr(count, -1);
    for (int i = 0; i < count; i++) {
        arr[i] = rand();
    }
    TestBinarySearch testBinarySearch;
    int target = arr[0];
    cout << "arr[target] = " << target << endl;
    sort(arr.begin(), arr.end());
    cout << testBinarySearch.BinarySearch(arr, target) << endl;
    int index = 0;
    while (arr[index] != target) {
        index++;
    }
    while (arr[index] == target) {
        index++;
    }
    cout << "index = " << index - 1 << endl;
    return 0;
}