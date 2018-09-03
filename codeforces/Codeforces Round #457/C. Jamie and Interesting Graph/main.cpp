#include <iostream>
using namespace std;
int find (int n) {
    if (n % 2 == 0) n++;
    while (true) {
        bool flag = true;
        for (int i = 3; i*i <= n; i++) {
            if (n % i == 0) {
                flag = false;
                break;
            }
        }
        if (flag) return n;
        else n += 2;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int p = find(n);
    cout << p << ' ' << p << '\n';
    for (int i = 1; i+1 < n; i++) {
        cout << i << ' ' << i+1 << " 1\n";
    }
    cout << n-1 << ' ' << n << ' ' << p-(n-2) << '\n';
    m -= (n-1);
    for (int i = 1; i <= n && m > 0; i++) {
        for (int j = 1; j < i && m > 0; j++) {
            if (i-j <= 1) continue;
            cout << j << ' ' << i << ' ' << p+1 << '\n';
            m--;

        }
    }

    return 0;
}