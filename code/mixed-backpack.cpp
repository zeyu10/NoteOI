#include <bits/stdc++.h>
using namespace std;
int dp[1010];
struct Node {
    int kind;
    int v, w;
};
vector<Node> vec;
int main() {
    int n, m;
    cin >> n >> m;
    while (n--) {
        int v, w, s;
        cin >> v >> w >> s;
        if (s < 0) {
            // 01 背包
            vec.push_back({-1, v, w});
        } else if (s == 0) {
            // 完全背包
            vec.push_back({0, v, w});
        } else {
            // 多重背包二进制优化
            for (int k = 1; k <= s; k <<= 1) {
                s -= k;
                // 注意是 乘以 k
                vec.push_back({-1, v * k, w * k});
            }
            if (s) {
                // 注意是 乘以 s
                vec.push_back({-1, v * s, w * s});
            }
        }
    }
    for (auto i : vec) {
        if (i.kind < 0) {
            // 01 背包
            // 多重背包
            for (int j = m; j >= i.v; j--) {
                dp[j] = max(dp[j], dp[j - i.v] + i.w);
            }
        } else {
            // 完全背包
            for (int j = i.v; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - i.v] + i.w);
            }
        }
    }
    cout << dp[m];
    return 0;
}
