#include <iostream>
using namespace std;
int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}
int main() {
    int n, m;
    cin >> n >> m;
    int GCD = gcd(n, m);
    // ↓ 最大公因数
    cout << GCD << endl;
    // ↓ 最小公倍数
    cout << n * m / GCD << endl;
    return 0;
}
