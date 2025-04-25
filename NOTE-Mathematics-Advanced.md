# 数学（进阶）

## 模的运算

基本运算：

1. $(a+b)\bmod M=(a\bmod M+b\bmod M)\bmod M$
2. $(a-b)\bmod M=(a\bmod M-b\bmod M)\bmod M$
3. $(a\times b)\bmod M=(a\bmod M\times b\bmod M)\bmod M$

基本性质：

1. 反身性：$x\equiv x\pmod M$
2. 对称性：若 $x\equiv y\pmod M$，则 $y\equiv x\pmod M$
3. 传递性：若 $x\equiv y\pmod M$，且 $y\equiv z\pmod M$，则 $x\equiv z\pmod M$
4. 同加性：若 $x\equiv y\pmod M$，则 $x+z\equiv y+z\pmod M$
5. 同乘性：若 $x\equiv y\pmod M$，则 $x\times z\equiv y\times z\pmod M$
6. 同幂性：若 $x\equiv y\pmod M$，则 $x^n\equiv y^n\pmod M$
7. 等价性：$x\equiv y\pmod b\Leftrightarrow b\mid(x-y)$

## 定理

### 定理 1 裴蜀定理

对于整数 $a,b$，设他们的最大公约数 $\gcd(a,b)=d$，一定存在一组整数 $(x,y)$ 使得 $ax+by=d$ 。

### 定理 2

对于整数 $a,b,c$，$ax+by=c$ 有整数解当且仅当 $\gcd(a,b)\mid c$ 。

### 定理 3 费马小定理

若 $p$ 是质数，且 $a$ 不是 $p$ 的倍数，则 $a^{p-1}\equiv 1 \pmod p\Rightarrow a\cdot a^{p-2}\equiv 1\pmod p$ 。

## 扩展欧几里得算法

对于不定方程 $ax+by=c$，通过[定理 2](#定理-2)，就只需要考虑出 $ax+by=\gcd(a,b)=d$ 的一组解就可以了。而扩展欧几里得算法，常被成为 $\text{exgcd}$，就是用来解决这个问题的。

$$ax+by=d$$

$$bx_0+(a\bmod b)y_0=d$$

$$bx_0+(a-b\left\lfloor\frac{a}{b}\right\rfloor)y_0=d$$

$$ay_0+b(x_0-\left\lfloor\frac{a}{b}\right\rfloor y_0)=d$$

从而得到：

$$(x,y)=(y_0,x_0-\left\lfloor\frac{a}{b}\right\rfloor y_0)$$

代码：

```cpp
void exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
    // y 是上层的 x0
    // x 是上层的 y0
}
```

或者：

```cpp
long long exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
```

示例：

$$
\boxed{
\begin{array}{l}
    求解\ 16x+6y=2 \\ \\ \quad
    \boxed{
    \begin{array}{l}
        求解\ 6x+(16\bmod 6)y=6x+4y=2 \\ \\ \quad
        \boxed{
        \begin{array}{l}
            求解\ 4x+(6\bmod 4)y=4x+2y=2 \\ \\ \quad
            \boxed{
            \begin{array}{l}
                求解\ 2x + (4 \bmod 2)y = 2x + 0y = 2 \quad \\ \\
                x_0=1,y_0=0,有\ 2x_0+0y_0=2
            \end{array}
            } \\ \\
            x_1=y_0=0,y_1=x_0-\left\lfloor\frac{4}{2}\right\rfloor y_0=1,有\ 4x_1+2y_1=2
        \end{array}
        } \\ \\
        x_2=y_1=1,y_2=x_1-\left\lfloor\frac{6}{4}\right\rfloor y_1=-1,有\ 6x_2+4y_2=2
    \end{array}
    } \\ \\
    x_3=y_2=-1,y_3=x_2-\left\lfloor\frac{16}{6}\right\rfloor y_2=3,有\ 16x_3+6y_3=2
\end{array}
}
$$

## 乘法逆元

引入：[P4942 小凯的数字](https://www.luogu.com.cn/problem/P4942)，答案为 $\boxed{\frac{(l+r)(r-l+1)}{2}\bmod 9}$，分子可以直接计算，但是，如何表示出分母？也就是说，在 $\bmod p$ 的意义下，能不能表示出 $\frac{1}{a}$ 呢？（其中 $a$ 是整数）

在实数意义下，对于任意 $a\neq 0$，都有 $a\times \frac{1}{a}=1$。所以在模意义下，也希望 “$\frac{1}{a}$” 满足同样的性质：$a\times\frac{1}{a}\equiv 1\pmod p$。也就是说，尝试找到一个整数 $x$，满足 $a\times x\equiv 1\pmod p$。

定义：若有 $a\times x\equiv 1\pmod p$，则称 $x$ 为 $a$ 在模 $p$ 意义下的乘法逆元，记为 $a^{-1}\pmod p$。

### 快速幂解法

依据：

$$a\times a^{p-2}=a^{p-1}\equiv1\pmod p$$

可知：$a$ 在模 $p$ 意义下的逆元就是 $a^{p-2}$，可用快速幂解决。

使用前提：$p$ 为质数，且 $a$ 不是 $p$ 的倍数。（依据[费马小定理](#定理-3-费马小定理)）

```cpp
int inv(int a, int p) {
    return qpow(a, p - 2, p);
}
```

### 扩展欧几里得解法

根据 $a\times x\equiv 1\pmod p$ 可以发现：

$$\exists y, ax+py=1$$

这实际上就是一个关于 $a,p$ 的不定方程，可用扩展欧几里得算法来解决。

使用前提：由[裴蜀定理](#定理-1-裴蜀定理)可知，存在 $a$ 在模 $p$ 意义下的逆元当且仅当 $\gcd(a,p)=1$，即 $a$ 和 $p$ 互质。

```cpp
int inv(int a, int p) {
    int x, y;
    exgcd(a, p, x, y);
    return x;
}
```

### 逆元递推公式

#### 标准递推式

$$inv_i=(p-\left\lfloor\frac{p}{i}\right\rfloor) inv_{p\bmod i}\bmod p$$

```cpp
inv[i] = (p - p / i) * inv[p % i] % p;
```

#### 推导

已知，当 $i=1$ 时，$i^{-1}\equiv 1\pmod p$。考虑 $2\leqslant i<p$ 的情况：

$$i\times i^{-1}\equiv 1\pmod p\Rightarrow p=q\cdot i+r\quad$$

其中：

$$q=\left\lfloor\frac{p}{i}\right\rfloor$$
$$r=p\bmod i\in[0,i)$$

可以得到：

$$0\equiv q\cdot i+r\Rightarrow r\equiv-q\cdot i$$

两侧同时乘以 $i^{-1}\cdot r^{-1}$：

$$i^{-1}\equiv -q\cdot r^{-1}$$

结合[运算性质](#模的运算)，由于 $-x\equiv p-x\pmod p\Rightarrow -q\cdot r^{-1}\equiv (p-q)\cdot r^{-1}\pmod p$：

$$i^{-1}\equiv (p-q)\cdot r^{-1}\pmod p$$

最终得到：

$$i^{-1}\equiv (p-\left\lfloor\frac{p}{i}\right\rfloor)\cdot(p\bmod i)^{-1}\pmod p$$

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
long long inv[N];
int main() {
    int n, p;
    cin >> n >> p;
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (p - p / i) * inv[p % i] % p;
    }
    for (int i = 1; i <= n; i++) {
        cout << inv[i] << endl;
    }
    return 0;
}
```

#### 倒推

根据：

$$\frac{1}{k}=\frac{(k-1)!}{k!}$$

步骤：

1. 用循环求出 $1!,2!,3!,\cdots,n!\bmod p$ 的结果。
2. 用扩展欧几里得算法 / 快速幂求出 $n!$ 的逆元。
3. 根据 $\frac{1}{(k-1)!}=\frac{k}{k!}$，倒推出 $(n-1)!,(n-2)!,\cdots,1!$ 的逆元。
4. 根据 $\frac{1}{k}=\frac{(k-1)!}{k!}$，求出 $1\sim n$ 的逆元。

代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
long long n, p;
long long inv[N];
long long fac[N];
long long qpow(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1) {
            res = res * x % p;
        }
        x = x * x % p;
        y >>= 1;
    }
    return res;
}
int main() {
    cin >> n >> p;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % p;
    }
    inv[n] = qpow(fac[n], p - 2);
    for (int i = n - 1; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
    for (int i = 1; i <= n; i++) {
        cout << fac[i - 1] * inv[i] % p << endl;
    }
    return 0;
}
```

运用同样的思路，我们也可以在 $O(n+\log p)$ 的时间内求出任意 $n$ 个数 $a_1,a_2,\cdots,a_n$ 模 $p$ 意义下的逆元：

根据：

$$\frac{1}{a_k}=\frac{\prod_{i=1}^{k-1} a_i}{\prod_{i=1}^k a_i}$$

步骤：

1. 用循环求出 $\prod_{i=1}^1 a_i,\prod_{i=1}^2 a_i,\prod_{i=1}^3 a_i,\cdots,\prod_{i=1}^n a_i\bmod p$ 的结果。
2. 用扩展欧几里得算法 / 快速幂求出 $\prod_{i=1}^n a_i$ 的逆元。
3. 根据 $\frac{1}{\prod_{i=1}^{k-1} a_i}=\frac{a_k}{\prod_{i=1}^k a_i}$，倒推出 $\prod_{i=1}^{n-1} a_i,\prod_{i=1}^{n-2} a_i,\cdots,\prod_{i=1}^1 a_i$ 的逆元。
4. 根据 $\frac{1}{a_k}=\frac{\prod_{i=1}^{k-1} a_i}{\prod_{i=1}^k a_i}$，求出 $a_1\sim a_n$ 的逆元。

## [中国剩余定理](code/chinese-remainder-theorem.cpp)

中国剩余定理可以用来求解下面这样一类同余方程组：

$$
\begin{cases}
x \equiv a_1 \pmod{m_1} \\
x \equiv a_2 \pmod{m_2} \\
\quad \vdots \\
x \equiv a_k \pmod{m_k}
\end{cases}
$$

其中：

- $ m_1, m_2, \dots, m_k $ 两两互质（前提）。
- $ a_1, a_2, \dots, a_k $ 是对应的余数。

通用解法公式：

1. 设 $M=m_1\cdot m_2\cdots m_k=\prod_{i=1}^n m_i$ 。
2. 设 $M_i=\frac{M}{m_i}$ 。
3. 设 $t_i=M_i^{-1}$ 为 $M_i$ 模 $m_i$ 的逆元。
4. 通解为：（其中 $k\in\mathbb{Z}$）

   $$
   \begin{align*}
   x&=a_1M_1t_1+a_2M_2t_2+\cdots+a_nM_nt_n+kM \\
    &=\sum_{i=1}^na_iM_it_i+kM
   \end{align*}
   $$

   也就是：

   $$
   \begin{align*}
   x&\equiv\sum_{i=1}^{n}a_i\cdot M_i\cdot y_i\pmod{M} \\
   x&\equiv\sum_{i=1}^{n}a_i\cdot M_i\cdot M_i^{-1}\pmod{M}
   \end{align*}
   $$

核心代码：

```cpp
for (int i = 1; i <= n; i++) {
    M = M * m[i];
}
for (int i = 1; i <= n; i++) {
    ll Mi = M / m[i];
    ll ti, ty;
    exgcd(Mi, m[i], ti, ty);
    ti = (ti % m[i] + m[i]) % m[i];
    for (int k = 1; k <= a[i]; k++) {
        x = (x + Mi * ti % M) % M;
    }
}
```

- [ ] 组合数学扩展
