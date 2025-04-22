#include <bits/stdc++.h>
using namespace std;
int dp[2010];
struct Node {
    int v, w;
};
vector<Node> vec;
int main() {
    int n, m;
    cin >> n >> m;
    while (n--) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k <<= 1) {
            s -= k;
            // 注意是 乘以 k
            vec.push_back({v * k, w * k});
        }
        if (s) {
            // 注意是 乘以 s
            vec.push_back({v * s, w * s});
        }
    }
    for (auto i : vec) {
        for (int j = m; j >= i.v; j--) {
            dp[j] = max(dp[j], dp[j - i.v] + i.w);
        }
    }
    cout << dp[m];
    return 0;
}
