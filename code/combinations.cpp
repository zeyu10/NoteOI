#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int c[1005][1005];
void init(int n, int m) {
    for(int i = 0; i <= n; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= i && j <= m; j++) {
            c[i][j] = (c[i - 1][j]+ c[i - 1][j - 1]) % mod;
        }
    }
}
int main() {
    init(1000, 1000);
    for (int i = 0; i <= 15; i++) {
        for (int j = 0; j <= i; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
