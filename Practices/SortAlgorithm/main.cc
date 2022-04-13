#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 对 vec 在区间 [start, end] 中以 vec[end] 为 pivot 进行区间划分
 */
int quicklyPartition(vector<int>& vec, int start, int end) {
    // 1.以末尾位置上的值作为划分值，小于等于的放左边，大于等于的放右边
    int base_index = end;  // pivot 的下标
    int pivot = vec[base_index];
    while (start < end) {
        // 1.先找到可以交换的左指针
        while (start < end && vec[start] <= pivot) {
            ++start;
        }
        // 2.找到可以交换的右指针
        while (start < end && vec[end] >= pivot) {
            --end;
        }
        // 3. 交换 start 与 end 所指向的那两个位置上的值
        swap(vec[start], vec[end]);
    }
    vec[base_index] = vec[start];
    vec[start] = pivot;
    return start;
}

/**
 * 快速排序主体部分
 */
void quicklySortMainFunction(vector<int>& vec, int start, int end) {
    // 1.找到一个 pivot；
    // 2.对 pivot 进行 partition
    // 3.另外两边重复以上动作
    if (start >= end) {
        return;
    } else {
        int partition_index = quicklyPartition(vec, start, end);   // 计算分界位置
        quicklySortMainFunction(vec, start, partition_index - 1);  // 递归左边
        quicklySortMainFunction(vec, partition_index + 1, end);    // 递归右边
    }
    return;
}

/**
 * author: wzz
 * date: 2021/11/25
 * description: 重写的排序算法
 */
namespace overwrite_sort {
/**
 * 冒泡排序（升序排序）
 */
void bubbleSort(vector<int>& vec) {
    if (vec.size() <= 1) {
        return;
    } else {
        int vec_size = vec.size();
        for (int left = 0; left < vec_size - 1; ++left) {
            for (int right = left + 1; right < vec_size; ++right) {
                if (vec[right] < vec[left]) {
                    swap(vec[right], vec[left]);
                }
            }
        }
    }
}

/**
 * 插入排序
 */
void insertSort(vector<int>& vec) {
    if (vec.size() <= 1) {
        return;
    } else {
        int pivot = 0, temp_index = 0, vec_size = vec.size();
        for (int i = 0; i < vec_size - 1; ++i) {
            pivot = vec[i + 1];
            temp_index = i;
            // 升序排序，将 vec[i] 放置到第一个小于等于 pivot 的数之后
            while (pivot < vec[temp_index] && temp_index >= 0) {
                vec[temp_index + 1] = vec[temp_index];
                --temp_index;
            }
            vec[temp_index + 1] = pivot;  // 放置好 pivot
        }
    }
}

/**
 * 快速排序
 */
void quicklySort(vector<int>& vec) {
    if (vec.size() <= 1) {
        return;
    } else {
        quicklySortMainFunction(vec, 0, vec.size() - 1);
    }
}
}  // namespace overwrite_sort

/**
 * author: wzz
 * date: 2021/11/25
 * description: 对排序算法进行测试
 */
namespace test_sort {
/**
 * 对排序算法测试指定次数
 * 注意：
 *      测试时一定要使用全局变量来存储测试值，就 “冒泡排序” 而言
 *      测试 100 次不使用全局变量耗费时间为：54429ms，单次 562ms，10 次为: 5490ms，单次 622ms；
 *      使用全局变量耗费时间为：660ms，单次 569ms，10 次为: 630ms，单次595ms；缩短了 90+ 倍
 *      （有时甚至会出现单次比多次耗时更长的情况）
 */
bool testSortIsTrue(int test_count, int sort_function) {
    vector<int> vec(10000);
    for (int i = 0; i < test_count; ++i) {
        srand((unsigned)time(NULL));  // 设定一个随机种子
        for (int len = 0; len < 10000; ++len) {
            vec[len] = rand();
        }
        vector<int> copy_vec(vec.begin(), vec.end());
        sort(vec.begin(), vec.end());
        switch (sort_function) {
            case 1:
                overwrite_sort::bubbleSort(copy_vec);
                break;
            case 2:
                overwrite_sort::insertSort(copy_vec);
                break;
            case 3:
                overwrite_sort::quicklySort(copy_vec);
                break;
            case -1:
                sort(copy_vec.begin(), copy_vec.end());
                break;
            default:
                break;
        }
        // 判断自定义算法与 STL 内置算法结果是否相同
        if (vec != copy_vec) {
            return false;
        }
        vec.clear();

        // vector<int>().swap(vec);  // 清空内容并回收内存的第一种写法
        vector<int> null_vec;  // 第二种写法
        copy_vec.swap(null_vec);
    }
    return true;
}

/**
 * 计算具体所需时间
 */
float calculateTime(vector<int>& vec) {
    clock_t start_time = clock();
    overwrite_sort::bubbleSort(vec);
    clock_t finish_time = clock();
    return finish_time - start_time;
}
}  // namespace test_sort

int main() {
    srand((unsigned)time(NULL));  // 设定一个随机种子
    vector<int> vec(10);
    for (int len = 0; len < 10; ++len) {
        vec[len] = rand();
    }

    // ==================== 测试冒泡排序 ====================
    clock_t start = clock();
    cout << "bubbleSort is true ?  "
         << (test_sort::testSortIsTrue(100000, 1) > 0 ? "Yes\n" : "No\n");
    clock_t finish = clock();
    cout << "bubbleSort required time: " << finish - start << " ms\n";
    // ==================== 测试插入排序 ====================
    start = clock();
    cout << "insertSort is true ?  "
         << (test_sort::testSortIsTrue(100000, 2) > 0 ? "Yes\n" : "No\n");
    finish = clock();
    cout << "insertSort required time: " << finish - start << " ms\n";
    // ==================== 测试快速排序 ====================
    start = clock();
    cout << "quicklySort is true ?  "
         << (test_sort::testSortIsTrue(100000, 3) > 0 ? "Yes\n" : "No\n");
    finish = clock();
    cout << "quicklySort required time: " << finish - start << " ms\n";
    // ==================== 测试内置排序 ====================
    start = clock();
    cout << "quicklySort is true ?  "
         << (test_sort::testSortIsTrue(100000, -1) > 0 ? "Yes\n" : "No\n");
    finish = clock();
    cout << "stlSort required time: " << finish - start << " ms\n";
    return 0;
}