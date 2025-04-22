#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a, b;
    string s, t;
    cin >> a >> s >> b;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            num = num * a + (s[i] - '0');
        } else {
            num = num * a + (s[i] - 'A' + 10);
        }
    }
    while (num) {
        int p = num % b;
        if (p < 10) {
            t.push_back(char(p + '0'));
        } else {
            t.push_back(char(p - 10 + 'A'));
        }
        num /= b;
    }
    for (int i = t.size() - 1; i >= 0; i--) {
        cout << t[i];
    }
    return 0;
}
