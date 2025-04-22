#include <iostream>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];

void sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = (l + r) >> 1;
    sort(l, mid);
    sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    int* t = new int[r - l + 1];
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            t[k++] = a[i++];
        } else {
            t[k++] = a[j++];
        }
    }
    while (i <= mid) {
        t[k++] = a[i++];
    }
    while (j <= r) {
        t[k++] = a[j++];
    }
    for (int x = l, y = 0; x <= r; x++, y++) {
        a[x] = t[y];
    }
    delete[] t;
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
