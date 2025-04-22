# 数学（基础）

## 实现二分快速幂

```cpp
#include <iostream>
using namespace std;
typedef long long LL;
LL pow_mod(LL a, LL b, LL mod) {
    LL res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int main() {
    LL a, b, mod;
    cin >> a >> b >> mod;
    cout << pow_mod(a, b, mod) << endl;
    return 0;
}
```

## 线性代数

[高斯消元](code/gaussian-elimination.cpp)

实现[矩阵快速幂](code/matrix-fast-power.cpp)

## 组合数学

实现[组合数](code/combinations.cpp)预处理

## 其它

埃拉托色尼筛法 (Sieve of Eratosthenes)

实现质数筛法（埃氏筛法）

```cpp
#include <iostream>
using namespace std;
bool is_prime[100];
int main() {
    for (int i = 2; i < 100; i++) {
        is_prime[i] = true;
    }
    for (int i = 2; i * i < 100; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < 100; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i < 100; i++) {
        if (is_prime[i]) {
            cout << i << endl;
        }
    }
    return 0;
}
```
