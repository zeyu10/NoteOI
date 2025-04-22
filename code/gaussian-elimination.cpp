#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const double eps = 1e-6;
int n, cur = 1;
double a[N][N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for (int j = 1; j <= n; j++) {
        int t;
        for (t = cur; t <= n; t++) {
            if (fabs(a[t][j]) > eps) {
                break;
            }
        }
        if (t > n) {
            continue;
        }

        for (int i = 1; i <= n + 1; i++) {
            swap(a[t][i], a[cur][i]);
        }
        for (int i = n + 1; i >= j; i--) {
            a[cur][i] /= a[cur][j];
        }
        for (int i = 1; i <= n; i++) {
            if (i != cur) {
                for (int k = n + 1; k >= j; k--) {
                    a[i][k] -= a[cur][k] * a[i][j];
                }
            }
        }
        cur++;
    }
    if (cur <= n) {
        for (int i = cur; i <= n; i++) {
            if (fabs(a[i][n + 1]) > eps) {
                puts("-1");
                return 0;
            }
        }
        puts("0");
    } else {
        for (int i = 1; i <= n; i++) {
            printf("x%d=%.2f\n", i, a[i][n + 1]);
        }
    }
    return 0;
}
