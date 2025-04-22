#include <iostream>
#include <cstring>
using namespace std;
struct matrix {
   int a[100][100];
   int n;
};
//! 使用结构体声明函数
matrix matrix_mul(matrix A, matrix B, int mod) {
    matrix ret;
    ret.n = A.n;
    memset(ret.a, 0, sizeof(ret.a));
    for (int i = 0; i < ret.n; i++) {
        for (int j = 0; j < ret.n; j++) {
            for (int k = 0; k < A.n; k++) {
                //! 注意取模
                ret.a[i][j] = (ret.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
            }
        }
    }
    return ret;
}
matrix unit(int n) {
    matrix ret;
    ret.n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                ret.a[i][j] = 1;
            } else {
                ret.a[i][j] = 0;
            }
        }
    }
    return ret;
}
matrix matrix_pow(matrix A, int p, int mod) {
    matrix res = unit(A.n);
    while (p > 0) {
        if (p & 1) {
            res = matrix_mul(res, A, mod);
        }
        A = matrix_mul(A, A, mod);
        p >>= 1;
    }
    return res;
}
int main() {
    matrix A;
    int p, mod;
    cin >> A.n >> p >> mod;
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < A.n; j++) {
            cin >> A.a[i][j];
        }
    }
    matrix C = matrix_pow(A, p, mod);
    for (int i = 0; i < C.n; i++) {
        for (int j = 0; j < C.n; j++) {
            cout << C.a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
