#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 10000;
struct Edge {
    int v, next;
} E[MAX_M];
int p[MAX_N], eid = 0;
void insert(int u, int v) {
    E[eid].v = v;
    E[eid].next = p[u];
    p[u] = eid++;
}
int n;
int minNode = -1;  // 存储树的重心的编号
int minBalance = MAX_N;  // 存储以重心为根的最大子树的节点数
int dfs(int u, int pre) {
    int sz = 0;  // 表示以节点 u 为根的子树的节点数
    int maxSubtree = 0;  // 表示以节点 u 为根的所有子树中节点数最多的子树的节点数
    for (int i = p[u]; i != -1; i = E[i].next) {
        if (E[i].v != pre) {
            int son = dfs(E[i].v, u);
            sz += son;  // 将子树的节点数累加到 sz 中
            maxSubtree = max(maxSubtree, son);
        }
    }
    sz++;  // 加上节点 u 本身
    maxSubtree = max(maxSubtree, n - sz);  // 考虑去掉以节点 u 为根的子树后，剩余部分的节点数
    if (maxSubtree < minBalance) {
        minBalance = maxSubtree;
        minNode = u;
    } else if (maxSubtree == minBalance) {
        minNode = min(minNode, u);  // 根据题意要求，若有多个节点都为树的重心，则选择节点编号最小的
    }
    return sz;  // 返回以节点 u 为根的子树的节点数
}
int main() {
    cin >> n;
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        insert(u, v);
        insert(v, u);
    }
    dfs(1, 0);
    cout << minNode << endl;
    return 0;
}
