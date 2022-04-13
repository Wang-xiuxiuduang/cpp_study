#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int main() {
    // 测试 vector 的容量扩充规则
    std::vector<int> arr;
    std::cout << "arr.size() = " << arr.size() << std::endl;
    std::cout << "arr.capacity() = " << arr.capacity() << std::endl;
    arr.push_back(1);
    std::cout << "arr.size() = " << arr.size() << std::endl;
    std::cout << "arr.capacity() = " << arr.capacity() << std::endl;
    arr.push_back(2);
    std::cout << "arr.size() = " << arr.size() << std::endl;
    std::cout << "arr.capacity() = " << arr.capacity() << std::endl;
    arr.push_back(3);
    std::cout << "arr.size() = " << arr.size() << std::endl;
    std::cout << "arr.capacity() = " << arr.capacity() << std::endl;
    arr.push_back(4);
    arr.push_back(5);
    std::cout << "arr.size() = " << arr.size() << std::endl;
    std::cout << "arr.capacity() = " << arr.capacity() << std::endl;
    std::cout << "===========================" << std::endl;

    // 测试 unordered_map 的容量扩充规则
    std::unordered_map<int, int> umap;
    std::cout << "umap.size() = " << umap.size() << std::endl;
    std::cout << "umap.bucket_count() = " << umap.bucket_count() << std::endl;
    umap.insert(std::pair<int, int>(1, 0));
    std::cout << "umap.size() = " << umap.size() << std::endl;
    std::cout << "umap.bucket_count() = " << umap.bucket_count() << std::endl;
    umap.insert(std::pair<int, int>(2, 0));
    umap.insert(std::pair<int, int>(3, 0));
    std::cout << "umap.size() = " << umap.size() << std::endl;
    std::cout << "umap.bucket_count() = " << umap.bucket_count() << std::endl;
    umap.insert(std::pair<int, int>(4, 0));
    umap.insert(std::pair<int, int>(5, 0));
    umap.insert(std::pair<int, int>(6, 0));
    umap.insert(std::pair<int, int>(7, 0));
    std::cout << "umap.size() = " << umap.size() << std::endl;
    std::cout << "umap.bucket_count() = " << umap.bucket_count() << std::endl;
    std::cout << "===========================" << std::endl;

    // 测试 unordered_set 的容量扩充规则
    std::unordered_set<int> uset;
    std::cout << "uset.size() = " << uset.size() << std::endl;
    std::cout << "uset.bucket_count() = " << uset.bucket_count() << std::endl;
    uset.insert(1);
    std::cout << "uset.size() = " << uset.size() << std::endl;
    std::cout << "uset.bucket_count() = " << uset.bucket_count() << std::endl;
    uset.insert(2);
    uset.insert(3);
    std::cout << "uset.size() = " << uset.size() << std::endl;
    std::cout << "uset.bucket_count() = " << uset.bucket_count() << std::endl;
    uset.insert(4);
    uset.insert(5);
    uset.insert(6);
    uset.insert(7);
    std::cout << "uset.size() = " << uset.size() << std::endl;
    std::cout << "uset.bucket_count() = " << uset.bucket_count() << std::endl;
    std::cout << "===========================" << std::endl;

    // 测试 map 的容量扩充规则
    std::map<int, int> map;
    std::cout << "map.size() = " << map.size() << std::endl;
    std::cout << "map.max_size() = " << map.max_size() << std::endl;
    map.insert(std::pair<int, int>(1, 0));
    std::cout << "map.size() = " << map.size() << std::endl;
    std::cout << "map.max_size() = " << map.max_size() << std::endl;
    map.insert(std::pair<int, int>(2, 0));
    map.insert(std::pair<int, int>(3, 0));
    std::cout << "map.size() = " << map.size() << std::endl;
    std::cout << "map.max_size() = " << map.max_size() << std::endl;
    map.insert(std::pair<int, int>(4, 0));
    map.insert(std::pair<int, int>(5, 0));
    map.insert(std::pair<int, int>(6, 0));
    map.insert(std::pair<int, int>(7, 0));
    std::cout << "map.size() = " << map.size() << std::endl;
    std::cout << "map.max_size() = " << map.max_size() << std::endl;
    std::cout << "===========================" << std::endl;

    // 测试 set 的容量扩充规则
    std::set<int> mset;
    std::cout << "mset.size() = " << mset.size() << std::endl;
    std::cout << "mset.max_size() = " << mset.max_size() << std::endl;
    mset.insert(1);
    std::cout << "mset.size() = " << mset.size() << std::endl;
    std::cout << "mset.max_size() = " << mset.max_size() << std::endl;
    mset.insert(2);
    mset.insert(3);
    std::cout << "mset.size() = " << mset.size() << std::endl;
    std::cout << "mset.max_size() = " << mset.max_size() << std::endl;
    mset.insert(4);
    mset.insert(5);
    mset.insert(6);
    mset.insert(7);
    std::cout << "mset.size() = " << mset.size() << std::endl;
    std::cout << "mset.max_size() = " << mset.max_size() << std::endl;
    std::cout << "===========================" << std::endl;

    return 0;
}
