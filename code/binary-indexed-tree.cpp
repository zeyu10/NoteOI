#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

int n, m;
int s[N];
int c[2][N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k, bool t) {  //* 单点修改
    while (x <= n) {
        c[t][x] += k;
        x += lowbit(x);
    }
}

int getsum(int x, bool t) {  //* 查询 s[1]...s[x] 的和
    int res = 0;
    while (x > 0) {
        res += c[t][x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        add(i, s[i]           , 0);  //* 直接初始化 c[x] 的管辖范围
        add(i, s[i] - s[i - 1], 1);  //* 差分初始化 c[x] 的管辖范围
    }

    /*
    * 1 x k   -> 单点加法：s[x] += k
    * 2 l r   -> 区间求和：sum[l...r]
    * 3 l r k -> 区间加法：s[l...r] += k
    * 4 x     -> 单点查询：s[x]
    */

    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1: {  //* 单点加法
                int x, k;
                cin >> x >> k;
                add(x, k, 0);
                break;
            }
            case 2: {  //* 区间求和
                int l, r;
                cin >> l >> r;
                //! 区间和为 sum[r] - sum[l - 1] 注意减一
                cout << getsum(r, 0) - getsum(l - 1, 0) << endl;
                break;
            }
            case 3: {  //* 区间修改
                int l, r, k;
                cin >> l >> r >> k;
                add(l, k, 1), add(r + 1, -k, 1);
                break;
            }
            case 4: {  //* 单点查询
                int x;
                cin >> x;
                cout << getsum(x, 1) << endl;
                break;
            }
        }
    }

    return 0;
}
