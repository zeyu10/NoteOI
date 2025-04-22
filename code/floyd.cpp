#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
const int INF = 1e9;
int g[N][N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                g[i][j] = 0;
            } else {
                g[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = w;
        // g[v][u] = w;
    }

    // Floyd 多源最短路算法核心代码
    for (int k = 1; k <= n; k++) { // 中间点
        for (int i = 1; i <= n; i++) { // 起点
            for (int j = 1; j <= n; j++) { // 终点
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << g[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
