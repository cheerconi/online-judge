#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a = 0, b = 0, cur = 0;
    int t, x, y;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> t >> x >> y;
        int delta = abs(a - x) + abs(b - y);
        int tmp = t - cur - delta;
        if (tmp < 0 || tmp%2 != 0) {
            flag = false;
            break;
        }
        cur = t; a = x, b = y;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}