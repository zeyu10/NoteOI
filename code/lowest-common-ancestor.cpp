#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 100005;
const int MAX_M = 200005;
struct Edge {
    int v, next;
} e[MAX_M];
int p[MAX_N], eid;
void init() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v) {
    e[eid].v = v;
    e[eid].next = p[u];
    p[u] = eid++;
}
int f[MAX_N][20], d[MAX_N];
void dfs(int u) {
    d[u] = d[f[u][0]] + 1;  //* 初始化 d 数组
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (v == f[u][0]) {
            continue;
        }
        f[v][0] = u;  //* 初始化 f 数组
        dfs(v);
    }
}
int lca(int x, int y) {
    if (d[x] < d[y]) {
        swap(x, y);
    }
    int K = 0;
    while ((1 << (K + 1)) <= d[x]) {
        K++;
    }
    for (int j = K; j >= 0; j--) {
        if (d[f[x][j]] >= d[y]) {  //! 注意是比较深度（大于等于）
            x = f[x][j];
        }
    }
    if (x == y) {
        return x;
    }
    for (int j = K; j >= 0; j--) {
        if (f[x][j] != f[y][j]) {  //! 注意是比较父节点（不等于）
            x = f[x][j];
            y = f[y][j];
        }
    }
    return f[x][0];
}
int main() {
    int n, q;
    cin >> n >> q;
    init();
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    dfs(1);
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}
