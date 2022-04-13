#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<int, int> umap;
    cout << umap.size() << " " << umap.bucket_count() << endl;
    // cout << umap[12];
    umap[12] = 100;
    umap[19] = 90;
    umap[3] = 2;
    for (auto& ite : umap) {
        cout << ite.first << "_" << ite.second << endl;
    }
    cout << (1 >> 1) << "__" << (0 >> 1) << endl;
    unsigned int num  = 12;
    cout << ~num << endl;
    cout << ~-12 << endl;
    return 0;
}
