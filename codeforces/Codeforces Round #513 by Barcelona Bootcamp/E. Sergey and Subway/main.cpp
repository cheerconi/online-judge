#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef pair<LL, LL> pll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#ifdef LOCAL
    #define DEBUG(x) { cerr << "# " << #x << ": " << x << endl;}
#else
    #define DEBUG(x)
#endif
mt19937_64 mt(time(0));
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/
const int MAXN = 200000 + 10;
vector<int> edges[MAXN];
LL dp[MAXN][2], out[MAXN][2], cnt[MAXN][2], cnt_out[MAXN][2];

void solve1(int cur, int par) {
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        solve1(nxt, cur);
        cnt[cur][1] += 1 + cnt[nxt][0];
        cnt[cur][0] += cnt[nxt][1];
        dp[cur][1] += 1 + dp[nxt][0] + cnt[nxt][0];
        dp[cur][0] += dp[nxt][1] + cnt[nxt][1];
    }
}

void solve2(int cur, int par) {
    cnt_out[cur][1] += 1 + cnt[par][0] - cnt[cur][1] + cnt_out[par][0];
    out[cur][1] += 1 + dp[par][0] - dp[cur][1] - cnt[cur][1] + cnt[par][0] - cnt[cur][1] + out[par][0] + cnt_out[par][0];
    cnt_out[cur][0] += cnt[par][1] - 1 - cnt[cur][0] + cnt_out[par][1];
    out[cur][0] += dp[par][1] - 1 - dp[cur][0] - cnt[cur][0] + cnt[par][1] - 1 - cnt[cur][0] + out[par][1] + cnt_out[par][1];
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        solve2(nxt, cur);
    }
}





int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n -1; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    solve1(1, 0);
    for (int nxt : edges[1]) {
        solve2(nxt, 1);
    }
    LL ret1 = 0, ret2 = 0;
    for (int i = 1; i <= n; i++) {
        ret1 += dp[i][0] / 2;
        ret1 += (dp[i][1] + cnt[i][1]) / 2;
        ret2 += out[i][0] / 2;
        ret2 += (out[i][1] + cnt_out[i][1]) / 2;
    }
    cout << (ret1 + ret2) / 2 << endl;





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
