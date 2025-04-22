#include <iostream>
using namespace std;
long long dp[40][1000];
int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << "0" << endl;
        return 0;
    }
    int target = sum / 2;
    // 初始化：选 0 个数凑出 0 只有一种方式，即空集
    dp[0][0] = 1;
    // 0-1 背包动态规划
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= 0; j--) {
            if (j >= i) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // 答案为子集个数
    cout << dp[n][target] << endl;
    return 0;
}
