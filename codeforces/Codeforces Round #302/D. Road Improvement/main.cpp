#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 2e5 + 10;
const int mod = 1e9 + 7;
vector<int> edges[MAXN];
LL dp[MAXN], ret[MAXN], out[MAXN];

LL power(LL base, int p) {
    LL ret = 1;
    while (p) {
        if (p&1) ret = ret * base % mod;
        p >>= 1;
        base = base * base % mod;
    }
    return ret;
}
void dfs1(int cur) {
    dp[cur] = 1;
    for (int nxt : edges[cur]) {
        dfs1(nxt);
        dp[cur] = dp[cur] * (1 + dp[nxt]) % mod;
    }
}
void dfs2(int cur) {
    for (int nxt : edges[cur]) {
        out[nxt] = ret[cur] * power(1+dp[nxt], mod-2) % mod;
        if (dp[nxt] == mod-1) {
            out[nxt] = out[cur]+1;
            for (int tmp : edges[cur]) {
                if (tmp == nxt) continue;
                out[nxt] = out[nxt] * (dp[tmp]+1) % mod;
            }
        }
        ret[nxt] = dp[nxt] * (1 + out[nxt]) % mod;
        dfs2(nxt);
    }


}
int main() {
//    freopen("test.txt","r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p;
        edges[p].push_back(i);
    }
    dfs1 (1);
    ret[1] = dp[1];
    dfs2 (1);
    for (int i = 1; i <= n; i++) {
        cout << ret[i];
        if (i == n) cout << endl;
        else cout << ' ';
    }
    return 0;
}