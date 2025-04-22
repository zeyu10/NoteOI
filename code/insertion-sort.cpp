#include <iostream>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];

void sort() {
    for (int i = 1; i < n; ++i) {
        int k = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort();
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
