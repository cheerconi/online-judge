#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 155;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0);
    a[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> tmp(n+1, 0);
        swap(a, b);
        for (int i = 1; i <= n; i++) {
            tmp[i] = b[i-1];
        }
        for (int i = 0; i < n; i++) {
            tmp[i] = (tmp[i] + a[i]) % 2;
        }
        swap(tmp, a);
    }
    cout << n << endl;
    for (int i = 0; i <= n; i++) {
        cout << a[i];
        if (i == n) cout << endl;
        else cout << ' ';
    }
    cout << n-1 << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i];
        if (i+1 == n) cout << endl;
        else cout << ' ';
    }

    return 0;
}