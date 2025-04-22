#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
// 将所有存在交集的区间合并
void merge(vector<PII>& intervals) {
    vector<PII> res;

    sort(intervals.begin(), intervals.end());

    int l = -1, r = -1;
    for (auto i : intervals) {
        // cout << i.first << " " << i.second << endl;
        if (r < i.first) {
            // 无交集（严格小于）
            // 更新到最后再加入
            if (r != -1) {
                res.push_back({l, r});
            }
            l = i.first, r = i.second;
        } else {
            // 有交集
            r = max(r, i.second);
        }
    }

    if (l != -1) {
        res.push_back({l, r});
    }

    intervals = res;
}

int main() {
    int n;
    cin >> n;
    vector<PII> vec;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        vec.push_back({l, r});
    }

    merge(vec);
    
    cout << vec.size() << endl;
    for (auto v : vec) {
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}