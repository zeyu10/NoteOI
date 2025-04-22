#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;

ll a[N];
ll ans[N << 2];
ll tag_mul[N << 2];
ll tag_add[N << 2];
ll mod;

inline constexpr ll ls(ll p) { return p << 1; }
inline constexpr ll rs(ll p) { return p << 1 | 1; }

void push_up(ll p) {
    ans[p] = (ans[ls(p)] + ans[rs(p)]) % mod;
}

void build(ll p, ll l, ll r) {
    tag_mul[p] = 1;
    tag_add[p] = 0;
    if (l == r) {
        ans[p] = a[l] % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}

void app(ll p, ll l, ll r, ll mul, ll add) {
    tag_mul[p] = (tag_mul[p] * mul) % mod;
    tag_add[p] = (tag_add[p] * mul + add) % mod;
    ans[p] = (ans[p] * mul) % mod;
    ans[p] = (ans[p] + add * ((r - l + 1) % mod)) % mod;
}

void push_down(ll p, ll l, ll r) {
    ll mid = (l + r) >> 1;
    app(ls(p), l, mid, tag_mul[p], tag_add[p]);
    app(rs(p), mid + 1, r, tag_mul[p], tag_add[p]);
    tag_mul[p] = 1;
    tag_add[p] = 0;
}

void update(ll ul, ll ur, ll l, ll r, ll p, ll mul, ll add) {
    if (ul <= l && r <= ur) {
        app(p, l, r, mul, add);
        return;
    }
    push_down(p, l, r);
    ll mid = (l + r) >> 1;
    if (ul <= mid) update(ul, ur, l, mid, ls(p), mul, add);
    if (ur > mid) update(ul, ur, mid + 1, r, rs(p), mul, add);
    push_up(p);
}

ll query(ll ql, ll qr, ll l, ll r, ll p) {
    ll res = 0;
    if (ql <= l && r <= qr) {
        return ans[p];
    }
    ll mid = (l + r) >> 1;
    push_down(p, l, r);
    if (ql <= mid) res = (res + query(ql, qr, l, mid, ls(p))) % mod;
    if (qr > mid) res = (res + query(ql, qr, mid + 1, r, rs(p))) % mod;
    return res;
}

int main() {
    int n, m;
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (m--) {
        int op;
        cin >> op;
        switch (op) {
        case 1: {
            ll x, y, k;
            cin >> x >> y >> k;
            update(x, y, 1, n, 1, k, 0);
            break;
        }
        case 2: {
            ll x, y, k;
            cin >> x >> y >> k;
            update(x, y, 1, n, 1, 1, k);
            break;
        }
        case 3: {
            ll x, y;
            cin >> x >> y;
            cout << query(x, y, 1, n, 1) << endl;
            break;
        }
        }
    }

    return 0;
}
