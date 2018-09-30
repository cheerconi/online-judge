#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n <= 5) {
        cout << -1 << endl;
        for (int i = 2; i <= n; i++) {
            cout << i-1 << ' ' << i << '\n';
        }
        return 0;
    }

    int m = n / 2;
    for (int i = 2; i <= m+1; i++) {
        cout << 1 << ' ' << i << '\n';
    }
    for (int i = m+2; i <= n; i++) {
        cout << 2 << ' ' << i << '\n';
    }
    for (int i = 2; i <= n; i++) {
        cout << i-1 << ' ' << i << '\n';
    }
    return 0;
}