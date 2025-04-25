#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 15;

int n;
ll m[N], a[N];
ll M = 1;
ll x = 0;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m[i] >> a[i];
        M = M * m[i];
    }
    for (int i = 1; i <= n; i++) {
        ll Mi = M / m[i];
        ll ti, ty;
        exgcd(Mi, m[i], ti, ty);           //! 使用扩展欧几里得算法
        ti = (ti % m[i] + m[i]) % m[i];    //! 确保逆元是正数
        for (int k = 1; k <= a[i]; k++) {  //! 使用多次加法代替乘法 
            x = (x + Mi * ti % M) % M;     //! 得到在 [0, M) 范围内的唯一解（最小非负解） 
        }
    }
    cout << x << endl;
    return 0;
}
