#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
const int MAXV = 1e6 + 10;
LL tree[MAXV], delta[MAXV];
inline int lowbit(int i) {
    return i&(-i);
}
void add (int i, LL val) {
    int n = MAXV-1;
    while (i <= n) {
        tree[i] = (val + tree[i]) % mod;
        i += lowbit(i);
    }
}
LL sum (int i) {
    LL ret = 0;
    while (i > 0) {
        ret = (ret + tree[i]) % mod;
        i -= lowbit(i);
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        LL tmp = (sum(num) + 1) * num % mod;
        tmp = (tmp + mod - delta[num]) % mod;
        add (num, tmp);
        delta[num] = (delta[num] + tmp) % mod;
    }
    cout << sum(MAXV-1) << endl;
    return 0;
}