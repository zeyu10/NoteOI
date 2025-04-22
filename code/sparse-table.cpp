#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 1000005;
int n, m, a[maxn], f[maxn][25], l, r;
void prepare() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][0] = a[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int l, int r) {
    int i = (int)(log2(r - l + 1));
    return max(f[l][i], f[r - (1 << i) + 1][i]);
}
int main() {
    prepare();
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
    return 0;
}
