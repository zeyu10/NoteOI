#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

ll a[N];
ll ans[N << 2];
ll tag_mul[N << 2];  //* 乘法懒标记
ll tag_add[N << 2];  //* 加法懒标记
ll mod;

inline constexpr ll ls(ll p) { return p << 1;     }  //* 左儿子 2*p
inline constexpr ll rs(ll p) { return p << 1 | 1; }  //* 右儿子 2*p + 1

//* 向上回溯：更新父节点的值，父节点的值等于左右儿子节点值之和
void push_up(ll p) {
    ans[p] = (ans[ls(p)] + ans[rs(p)]) % mod;
}

//* 建树：从节点 p 开始，构建存储区间 [l, r] 的线段树
void build(ll p, ll l, ll r) {
    tag_mul[p] = 1;                 // 初始化乘法懒标记为 1
    tag_add[p] = 0;                 // 初始化加法懒标记为 0
    if (l == r) {                   // 到达叶子节点
        ans[p] = a[l] % mod;        // 直接存储数组值
        return;
    }
    ll mid = (l + r) >> 1;
    build(ls(p), l    , mid);  // 递归构建左子树
    build(rs(p), mid + 1, r);  // 递归构建右子树
    //* 向上回溯更新父节点（当前结点）的值
    push_up(p);
}

//* 应用标记：将标记 k 应用到节点 p 所代表的区间 [l, r] 上
//! 特别注意：先应用乘法标记
//!          再应用加法标记
void app(ll p, ll l, ll r, ll mul, ll add) {
    tag_mul[p] = (tag_mul[p] * mul      ) % mod;  // 更新乘法标记 -> 当前标记乘以新标记
    tag_add[p] = (tag_add[p] * mul + add) % mod;  // 更新加法标记 -> 当前标记乘以乘数再加上加数
    ans[p] = (ans[p] * mul                      ) % mod;  //! 更新当前节点值 -> 先应用乘法：节点值乘以乘数
    ans[p] = (ans[p] + add * ((r - l + 1) % mod)) % mod;  //! 更新当前节点值 -> 再应用加法：节点值加上加数乘以区间长度
}

//* 向下传导：将节点 p 的标记传递给左右儿子节点
void push_down(ll p, ll l, ll r) {
    ll mid = (l + r) >> 1;
    app(ls(p), l    , mid, tag_mul[p], tag_add[p]);  // 将标记应用到左儿子节点
    app(rs(p), mid + 1, r, tag_mul[p], tag_add[p]);  // 将标记应用到右儿子节点
    //* 清空当前节点的标记
    tag_mul[p] = 1;
    tag_add[p] = 0;
}

//* 区间修改：对区间 [ul, ur] 执行先乘 mul 再加 add 的操作
void update(ll ul, ll ur, ll l, ll r, ll p, ll mul, ll add) {
    //* ul, ur 为要修改的区间
    //*  l,  r 为当前节点所代表的区间
    //*      p 为当前节点位置
    //*    mul 为要相乘的值
    //*    add 为要增加的值
    if (ul <= l && r <= ur) {       // 如果当前节点的区间完全包含在要修改的区间内
        app(p, l, r, mul, add);     // 调用应用标记函数更新当前节点的相关标记数值
        /*
        tag_mul[p] = (tag_mul[p] * mul      ) % mod;
        tag_add[p] = (tag_add[p] * mul + add) % mod;
        ans[p] = (ans[p] * mul                      ) % mod;
        ans[p] = (ans[p] + add * ((r - l + 1) % mod)) % mod;
        */
        return;
    }
    push_down(p, l, r);
    //* 由于是在递归之前不断向下传递
    //* 所以自然每个节点都可以更新到 
    ll mid = (l + r) >> 1;
    if (ul <= mid) update(ul, ur, l    , mid, ls(p), mul, add);     // 如果要修改的区间与左子树有交集，递归修改左子树
    if (ur >  mid) update(ul, ur, mid + 1, r, rs(p), mul, add);     // 如果要修改的区间与右子树有交集，递归修改右子树
    //* 向上回溯更新父节点的值
    push_up(p);
}

//* 区间查询：返回区间 [ql, qr] 的和
ll query(ll ql, ll qr, ll l, ll r, ll p) {
    //* ql, qr 为要查询的区间
    //*  l,  r 为当前节点所代表的区间
    //*      p 为当前节点位置
    ll res = 0;
    if (ql <= l && r <= qr) {  // 如果当前节点的区间完全包含在要查询的区间内
        return ans[p];         // 返回当前结点的答案
    }
    ll mid = (l + r) >> 1;
    //* 向下传导标记
    push_down(p, l, r);
    if (ql <= mid) res = (res + query(ql, qr, l    , mid, ls(p))) % mod;  // 如果要查询的区间与左子树有交集，递归查询左子树
    if (qr >  mid) res = (res + query(ql, qr, mid + 1, r, rs(p))) % mod;  // 如果要查询的区间与右子树有交集，递归查询右子树
    return res;
}

int main() {
    // n-数组大小
    // m-操作次数
    int n, m;
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    //* 构建线段树
    build(1, 1, n);

    while (m--) {
        int op;
        cin >> op;
        switch (op) {
            case 1: {  // 区间乘法修改操作
                ll x, y, k;
                cin >> x >> y >> k;
                update(x, y, 1, n, 1, k, 0);  // 乘 k 相当于先乘 k 再加 0
                break;
            }
            case 2: {  // 区间加法修改操作
                ll x, y, k;
                cin >> x >> y >> k;
                update(x, y, 1, n, 1, 1, k);  // 加 k 相当于先乘 1 再加 k
                break;
            }
            case 3: {  // 区间取模查询操作
                ll x, y;
                cin >> x >> y;
                cout << query(x, y, 1, n, 1) << endl;
                break;
            }
        }
    }

    return 0;
}
