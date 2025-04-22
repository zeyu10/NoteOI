#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
//* 1. 结构体定义
struct Node {
    int to;
    int w;
    int next;
};
//* 2. 初始化
Node edge[2 * N];
int cnt = 0;
int head[N];
int p = 0;
//* 3. 添加函数
void add(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].w = w;
    // 每个顶点的最后一条边（排在最后打印的边）的 next 会被赋值为 -1
    // 其余边的 next 被赋值为邻接边（打印时的下一条边）的编号 cnt
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int main() {
    int n;
    cin >> n;
    int u, v, w;
    //* 4. 初始化 head 数组
    memset(head, -1, sizeof(head));
    //* 5. 添加边
    for (int i = 0; i < n; i++) {
        cin >> u >> v >> w;
        add(u, v, w);  // 有向图加一次
        add(v, u, w);  // 无向图加两次
        p = max(p, max(u, v));
    }
    //* 6. 打印邻接表
    for (int i = 1; i <= p; i++) {
        cout << "Node " << i << ":\n";
        for (int j = head[i]; j != -1; j = edge[j].next) {
            cout << " -> " << edge[j].to << " (weight: " << edge[j].w << ")\n";
        }
    }
    return 0;
}

/*
! 以 u 为顶点的第一条边：：最先打印的边（最后添加的边）
! 以 u 为顶点的最后一条边：最后打印的边（最先添加的边）
*/