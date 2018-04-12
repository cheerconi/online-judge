#include <iostream>
#include <string>
using namespace std;
string s;
void solve (int & a, int &b, int idx) {
    if (a >= b) {
        a--;
        s[idx] = 'a';
    }
    else {
        b--;
        s[idx] = 'b';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    cin >> s;
    s = "*" + s;
    int cnt = a + b;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '*') continue;
        if (a == 0 && b == 0) break;
        if (s[i-1] == '*') {
            solve (a, b, i);
        }
        else if (s[i-1] == 'a') {
            if (b == 0) {
                s[i] = '*';
            }
            else {
                b--;
                s[i] = 'b';
            }
        }
        else {
            if (a == 0) {
                s[i] = '*';
            }
            else {
                a--;
                s[i] = 'a';
            }
        }
    }
    cout << cnt - a - b << endl;

    return 0;
}