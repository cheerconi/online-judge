#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << i;
        if (i+1 == n) cout << endl;
        else cout << ' ';
    }
    for (int i = 0; i < n; i++) {
        cout << (2*n-1-2*i) % n;
        if (i+1 == n) cout << endl;
        else cout << ' ';
    }
    for (int i = n-1; i >= 0; i--) {
        cout << i;
        if (i == 0) cout << endl;
        else cout << ' ';
    }
    return 0;
}