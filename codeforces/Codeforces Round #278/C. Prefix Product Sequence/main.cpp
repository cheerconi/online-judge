#include <iostream>
#include <vector>
using namespace std;
vector<int> ret;
int mod;

int power (int base, int p) {
    int ret = 1;
    while (p) {
        if (p & 1) ret = 1LL * base * ret % mod;
        p >>= 1;
        base = 1LL * base * base % mod;
    }
    return ret;
}

void solve (int n) {
    if (n == 1) {
        ret.push_back(1);
        return;
    }
    if (n == 4) {
        ret = vector<int>{1, 3, 2, 4};
        return;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return;
    }
    mod = n;
    for (int i = 0; i < n; i++) {
        ret.push_back(1LL * (i+1) * power(i, mod-2) % mod);
    }
    ret.front() = 1;
    ret.back() = n;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    solve(n);
    if (ret.empty()) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << ret[i] << '\n';
        }
    }

    return 0;
}