#include <iostream>
using namespace std;
int fa[110];  // father
int sz[110];  // size  //! 注意命名冲突
int n, m;
void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        sz[i] = 1;
    }
}
int get(int x) {
    return (fa[x] == x ? x : fa[x] = get(fa[x]));
}
void merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
        fa[y] = x;
        sz[x] += sz[y];
    }
}
int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            merge(x, y);
        } else {
            cin >> x;
            cout << sz[get(x)] << endl;
        }
    }
    return 0;
}
