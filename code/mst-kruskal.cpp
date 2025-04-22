#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
int n, m;
struct Edge {
    int u, v;
    int len;
} E[MAX_M];
bool cmp (Edge a, Edge b) {
    return a.len < b.len;
}
int fa[MAX_N];
void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}
int get(int x) {
    if (fa[x] == x) {
        return x;
    }
    return fa[x] = get(fa[x]);
}
int kruskal(int n, int m) {
    int sum = 0;
    init();
    sort(E, E + m, cmp);
    for (int i = 0; i < m; i++) {
        int fu = get(E[i].u);
        int fv = get(E[i].v);
        if (fu != fv) {
            fa[fv] = fu;
            sum += E[i].len;
        }
    }
    return sum;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].len;
    }
    cout << kruskal(n, m) << endl;
    return 0;
}
