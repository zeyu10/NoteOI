# 数据结构（基础）

## 并查集

- [并查集](https://oi-wiki.org/ds/dsu/)

### 1. 实现[并查集维护集合大小](code/union-find-set.cpp)

### 2. [NOIP 2010]关押罪犯

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int fa[20005], f[20005];
int n, m, ans;
struct edge {
    int a;
    int b;
    int c;
};
bool cmp(edge a, edge b) {
    if (a.c != b.c) {
        return a.c > b.c;
    }
    return a.a < b.a;
}
edge e[100005];
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
void merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
        fa[y] = x;
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].a >> e[i].b >> e[i].c;
    }
    init();
    sort(e, e + m, cmp);
    for(int i = 0; i < m; i++) {
        if(get(e[i].a) == get(e[i].b)) {
            ans = e[i].c;
            break;
        } else {
            if (f[e[i].a]) {
                merge(f[e[i].a], e[i].b);
            } else {
                f[e[i].a] = e[i].b;
            }
            if (f[e[i].b]) {
                merge(f[e[i].b], e[i].a);
            } else {
                f[e[i].b] = e[i].a;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
```

- [ ] 单调队列

- [ ] 单调栈

- [ ] Trie 树

- [ ] KMP

- [ ] 堆

- [ ] 哈希
