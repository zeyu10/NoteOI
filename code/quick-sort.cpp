#include <iostream>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];

void sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int i = l - 1, j = r + 1, p = a[l + r >> 1];
    while (i < j) {
        do i++; while (a[i] < p);
        do j--; while (a[j] > p);
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    sort(l, j);
    sort(j + 1, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
