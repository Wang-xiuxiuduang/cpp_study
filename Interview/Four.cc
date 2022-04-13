#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n < m) {
        return -1;
    }
    vector<int> a(n, 0);
    set<int> us;
    // 过滤重复值，其使其有序
    for (int i = 0; i < n; ++i) {
        cin >> a[i], us.insert(a[i]);
    }
    vector<int> d(n, 0);
    for (int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y, a[x - 1] > a[y - 1] ? d[x - 1]++ : d[y - 1]++;
    }
    unordered_map<int, int> nums;
    //同样密度的点的度
    for (int i = 0; i < n; ++i) {
        nums[a[i]] += d[i];
    }
    auto iter = us.rbegin();
    m--;
    while (m >= 0 && iter != us.rend()) {
        // 连通块数量和点的度相关
        m -= nums[*iter];
        ++iter;
    }
    cout << (iter == us.rend() ? -1 : *prev(iter) + 1);
    return 0;
}