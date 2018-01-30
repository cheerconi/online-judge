#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int MAXN = 7000;
int dp[MAXN][MAXN], mp[1<<15];
int n;
LL ret;
void dfs1(int i, int b, int c) {
    if (i == n/2) {
        dp[mp[b]][mp[c]]++;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (b & (1<<j)) continue;
        if ((1<<((i+j)%n)) & c) continue;
        dfs1(i+1, b|(1<<j), (1<<((i+j)%n)) | c);
    }
}
void dfs2(int i, int b, int c) {
    if (i == n) {
        int nb = ((1<<n)-1)^b;
        int nc = ((1<<n)-1)^c;
        ret = (ret + dp[mp[nb]][mp[nc]]) % mod;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (b & (1<<j)) continue;
        if ((1<<((i+j)%n)) & c) continue;
        dfs2(i+1, b|(1<<j), (1<<((i+j)%n)) | c);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    if (n % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < (1<<n); i++) {
        if (__builtin_popcount(i) != n/2) continue;
        static int id = 0;
        mp[i] = id++;
    }
    dfs1(0, 0, 0);
    dfs2(n/2, 0, 0);
    for(int i = 2; i <= n; i++) {
        ret = ret * i % mod;
    }
    cout << ret << endl;
}