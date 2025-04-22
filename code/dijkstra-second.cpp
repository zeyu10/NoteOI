#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 200010;
const int INF = 1e9;

struct Edge {
    int to;
    int nxt;
    int val;
} e[N];
int h[N], cnt = 0;
void add(int u, int v, int w) {
    e[cnt].to = v;
    e[cnt].val = w;
    e[cnt].nxt = h[u];
    h[u] = cnt++;
}


int dis[2][N];
//* dis[0][u] 存储最短路径
//* dis[1][u] 存储次短路径

int main() {
    int n, m;
    cin >> n >> m;
    memset(h, -1, sizeof(h));  //! 初始化邻接表头指针，-1 表示无边
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    for (int i = 1; i <= n; i++) {
        dis[0][i] = INF;
        dis[1][i] = INF;
    }
    dis[0][1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;  //* 小根堆，保证优先弹出当前最小的距离
    q.push({0, 1});
    
    while (!q.empty()) {
        int d = q.top().first;    //* 当前弹出的点的最短路径或次短路径
        int u = q.top().second;   //* 当前点
        q.pop();

        if (d > dis[1][u]) {  //! 注意和最短路的区别，由于我们维护的是“最短+次短路径”，只要 d 大于当前点的次短路 dis[1][u] 就舍去，这条路径已经无效
            continue;
        }

        for (int i = h[u]; i != -1; i = e[i].nxt) {  //* 执行的前提是 d 小于等于次短路
            int v = e[i].to;
            int w = e[i].val;
            //* 第一种情况：该路径小于已知的最短路 -> 将最短路赋值给次短路，更新最短路、添加到队列
            if (dis[0][v] > d + w) {  //! 这里要使用 d 而不能直接用 dis[0][u]，因为 d 可能是最短路径或次短路径，如果直接使用 dis[0][u]，可能会忽略从次短路径更新 v 的情况
                dis[1][v] = dis[0][v];
                dis[0][v] = d + w;
                q.push({dis[0][v], v});
            }
            //* 第二种情况：该路径小于已知的次短路但是大于最短路 -> 更新次短路、添加到队列
            //! 注意：“由于只有最短路和次短路有效，因此这个点的所有可能的有效路径（更新成功的最短路和次短路）全部都在这个优先队列中。”
            if (dis[1][v] > d + w && dis[0][v] < d + w) {
                dis[1][v] = d + w;
                q.push({dis[1][v], v});
            }
        }
    }

    cout << dis[1][n];
    return 0;
}
