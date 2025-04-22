// P1525 [NOIP 2010 提高组] 关押罪犯
#include <bits/stdc++.h>
using namespace std;
const int N = 20005, M = 100005;
int fa[N], s[N];
int n, m, ans = 0;
struct Node {
    int a, b, c;
};
Node p[M];
bool cmp(Node a, Node b) {
    return a.c > b.c;
}
int get(int x) {
    if (fa[x] == x) {
        return x;
    }
    return fa[x] = get(fa[x]);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p[i].a >> p[i].b >> p[i].c;
    }
    sort(p, p + m, cmp);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        if (get(p[i].a) == get(p[i].b)) {
            ans = p[i].c;
            break;
        } else {
            if (!s[p[i].a]) {
            	//如果 a 的敌人还没标记，就先标记 
            	s[p[i].a] = p[i].b;
            } else {
            	//如果 a 的敌人被标记 
            	//把 a 的敌人与 b 分到一个监狱 
				//实际上是 b 指向 a 的敌人 
				fa[get(p[i].b)] = get(s[p[i].a]);
            }
            if (!s[p[i].b]) {
            	//如果 b 的敌人还没标记，就先标记
            	s[p[i].b] = p[i].a;
            } else {
            	//如果 b 的敌人被标记 
            	//把 b 的敌人与 a 分到一个监狱
				//实际上是 a 指向 b 的敌人 
				fa[get(p[i].a)] = get(s[p[i].b]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}