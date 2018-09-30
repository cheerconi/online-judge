#include <iostream>
using namespace std;

int solve (int n, int k) {
    while (n%k != 0 && n > k) {
        int r = n % k;
        int delta = n/k + 1;
        int tmp = r / delta;
        if (r % delta != 0) tmp++;
        n -= tmp*delta;
    }
    return n/k;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, a, b, ret = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ret ^= solve (a, b);
    }
    if (ret == 0) {
        cout << "Aoki" << endl;
    }
    else cout << "Takahashi" << endl;
}