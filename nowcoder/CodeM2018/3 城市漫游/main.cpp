#include <iostream>
#include <climits>
#include <memory.h>
#include <random>
#include <ctime>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <bitset>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
const int MAXN = 1e5 + 10;
const int MAXB = 20;
const int mod = 1e9 + 7;
vector<int> edges[MAXN], weights[MAXN], rounds[MAXN];
int par[MAXN][MAXB], dp[2][MAXN], dist[MAXN];

void dfs(int cur, int p) {
    par[cur][0] = p;
    dist[cur] = dist[p] + 1;
    int i = -1;
    for (int nxt : edges[cur]) {
        i++;
        if (nxt == p) continue;
        if (rounds[cur][i] % 2 == 0) {
            dp[0][nxt] = (dp[0][p] + 1LL*rounds[cur][i]*weights[cur][i]%mod) % mod;
            dp[1][nxt] = (dp[1][p] + 1LL*(rounds[cur][i]+1)*weights[cur][i]%mod) % mod;
        }
        else {
            dp[1][nxt] = (dp[1][p] + 1LL*rounds[cur][i]*weights[cur][i]%mod) % mod;
            dp[0][nxt] = (dp[0][p] + 1LL*(rounds[cur][i]+1)*weights[cur][i]%mod) % mod;
        }
        dfs(nxt, cur);
    }
}

int find(int a, int b) {
    if (dist[a] > dist[b]) return find(b, a);
    if (a == b) return a;
    if (dist[a] == dist[b]) {
        for (int i = MAXB-1; i >= 0; i--) {
            if (par[a][i] == 0) continue;
            if (par[a][i] != par[b][i]) {
                return find(par[a][i], par[b][i]);
            }
        }
        return par[a][0];
    }
    for (int i = MAXB; i >= 0; i--) {
        if (par[b][i] == 0) continue;
        if (dist[a] <= dist[par[b][i]]) return find(a, par[b][i]);
    }
    assert(false);
    return -1;
}

LL solve(int a, int b) {
    int c = find(a, b);
    LL ret = (dp[1][c] - dp[1][a] + mod) % mod;
    ret = (ret + dp[1][c] - dp[1][b] + mod) % mod;
    LL tmp = (dp[0][c] - dp[0][a] + mod) % mod;
    tmp = (tmp + dp[0][c] - dp[0][b] + mod) % mod;
    ret = (ret - tmp + mod) % mod;
    return ret;
}





/*-------------------------------------coding area end------------------------------------------*/
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
    #ifdef LOCAL
        freopen("../test.txt", "r", stdin);
//        freopen("../output.txt", "w", stdout);
    #endif
/*++++++++++++++++++++++++++++++++++++coding area start+++++++++++++++++++++++++++++++++++++++++*/
    LL n, a, b, w, r;
    cin >> n;
    LL tot = 0;
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> w >> r;
        edges[a].push_back(b);
        edges[b].push_back(a);
        weights[a].push_back(w);
        weights[b].push_back(w);
        rounds[a].push_back(r);
        rounds[b].push_back(r);
        tot = (tot + w * r % mod) % mod;
        if (r % 2 == 1) tot = (tot + w) % mod;
    }
    dist[0] = -1;
    dfs(1, 0);
    for (int i = 1; i < MAXB; i++) {
        for (int cur = 1; cur <= n; cur++) {
            par[cur][i] = par[par[cur][i-1]][i-1];
        }
    }
    int m; cin >> m;
    while (m--) {
        cin >> a >> b;
        cout << (tot + solve(a, b)) % mod << '\n';
    }





/*-------------------------------------coding area end------------------------------------------*/

    #ifdef LOCAL
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
    #endif
    return 0;
}
/* author:  txingml */
