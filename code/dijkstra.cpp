#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int N = 100;
const int INF = 1e9;

struct Edge {
    int v, w;
};

vector<Edge> g[N];
int dis[N], pre[N];  // 记录路径

void printPath(int v) {
    if (pre[v] == -1) {
        cout << v;
        return;
    }
    printPath(pre[v]);
    cout << " -> " << v;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        // g[v].push_back({u, w});
    }

    int s;
    cin >> s;

    // Dijkstra 单源最短路算法核心代码
    priority_queue<pii, vector<pii>, greater<pii>> min_heap;
    fill(dis, dis + N, INF);
    fill(pre, pre + N, -1);
    dis[s] = 0;
    min_heap.push({0, s});

    while (!min_heap.empty()) {
        int mind = min_heap.top().first;  // 当前最小距离
        int u = min_heap.top().second;    // 当前节点
        min_heap.pop();  //! 注意弹出堆顶

        if (mind != dis[u]) {
            continue;  //* 如果距离被更新了不再是这个元素的距离了（已经过时），那么就不用考虑这个元素了，则跳过
        }

        for (auto edge : g[u]) {  // 执行的前提是 mind 等于 dis[u]
            if (dis[edge.v] > dis[u] + edge.w) {  // 松弛操作（更新）
                dis[edge.v] = dis[u] + edge.w;
                pre[edge.v] = u;  //* 记录前驱节点
                min_heap.push({dis[edge.v], edge.v});  // 将更新后的点放入优先队列
            }
        }
    }
    
    cout << "从起点 " << s << " 到各点的最短路径：" << endl;
    for (int i = 1; i <= n; i++) {
        if (dis[i] == INF) {
            cout << "INF ";
        } else {
            cout << "到 " << i << " 的最短距离: " << dis[i] << endl;
            cout << "路径为: ";
            printPath(i);
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}
