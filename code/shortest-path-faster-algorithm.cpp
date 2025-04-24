#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;

struct Node {
    int v, w;
};
vector<Node> G[N];

int n, m;
int dis[N];
int cnt[N];   //* cnt[i] 表示点 i 被松弛的次数（用于判断是否有负环）
bool vis[N];  //* vis[i] 表示点 i 是否在队列中
queue<int> q;

bool spfa() {
    dis[1] = 0;
    vis[1] = true;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();  //* 取出队头节点
        q.pop();
        vis[x] = false;     //* 标记 x 已出队
        for (int i = 0; i < G[x].size(); i++) {
            int v = G[x][i].v;
            int w = G[x][i].w;
            if (dis[v] > dis[x] + w) {
                dis[v] = dis[x] + w;
                cnt[v] = cnt[x] + 1;
                if (cnt[v] >= n) {  //* 如果某点被松弛超过 n 次，说明存在负环
                    return true;
                }
                if (!vis[v]) {      //* 如果 v 不在队列中，加入队列
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            G[i].clear();  //! 清空图
        }
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].push_back({v, w});
            if (w >= 0) G[v].push_back({u, w});
        }

        memset(dis, 0x3f, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        while (!q.empty()) q.pop();
        
        cout << (spfa() ? "YES" : "NO") << endl;
    }
    return 0;
}
