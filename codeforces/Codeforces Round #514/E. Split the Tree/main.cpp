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
const int MAXN = 1e5 + 10;
const int MAXB = 30;
int weight[MAXN], par[MAXN][MAXB], level[MAXN];
bool state[MAXN];
LL dp[MAXN], ret, L, s;
vector<int> edges[MAXN];

void dfs(int cur) {
    dp[cur] += weight[cur];
    state[cur] = true;
    for (int nxt : edges[cur]) {
        level[nxt] = level[cur] + 1;
        par[nxt][0] = cur;
        dp[nxt] += dp[cur];
        dfs(nxt);
    }
}

int solve(int cur) {
    int deep = level[cur];
    for (int nxt : edges[cur]) {
        deep = min(solve(nxt), deep);
    }
    if (deep != level[cur]) return deep;
    ret++;
    int p = cur;
    for (int i = MAXB-1; i >= 0; i--) {
        int tmp = par[p][i];
        if (tmp == 0) continue;
        if (level[cur] - level[tmp] + 1 > L) continue;
        if (dp[cur] - dp[tmp] + weight[tmp] > s) continue;
        p = tmp;
    }
    p = par[p][0];
    return level[p];
}




int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    LL n, p;
    cin >> n >> L >> s;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
        if (weight[i] > s) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        cin >> p;
        edges[p].push_back(i);
    }
    level[1] = 1;
    dfs(1);
    for (int j = 1; j < MAXB; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    solve(1);
    cout << ret << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
