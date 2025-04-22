#include <iostream>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];



int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // sort(1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
