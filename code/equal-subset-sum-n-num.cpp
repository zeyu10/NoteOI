#include <iostream>
using namespace std;
int num[100];
int sum = 0;
long long dp[10005];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    if (sum % 2 != 0) {
        cout << "0" << endl;
        return 0;
    }
    int target = sum / 2;
    // 初始化：选 0 个数凑出 0 只有一种方式，即空集
    dp[0] = 1;
    // 0-1 背包动态规划
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= num[i]; j--) {
            dp[j] += dp[j - num[i]];
        }
    }
    // 答案为子集个数
    cout << dp[target] << endl;  
    return 0;
}
