#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct Edge {
    int v, next;
    int len;
} E[MAX_M];
int p[MAX_N], eid = 0;
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int maxlen, point;
void dfs(int u, int pre, int step) {
    if (step > maxlen) {
        maxlen = step;
        point = u;
    }
    for (int i = p[u]; i != -1; i = E[i].next) {
        if (E[i].v != pre) {
            dfs(E[i].v, u, step + 1);
        }
    }
}
int diameter() {
    maxlen = -1;
    dfs(1, 0, 0);
    maxlen = -1;
    dfs(point, 0, 0);
    return maxlen;
}
int main() {
    int n;
    cin >> n;
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    cout << diameter() << endl;
    return 0;
}
