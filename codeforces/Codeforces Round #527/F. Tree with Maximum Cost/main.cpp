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
constexpr int MAXN = 2e5 + 10;
int nums[MAXN];
LL sum_in[MAXN], sum_out[MAXN], dp_in[MAXN], dp_out[MAXN];
vector<int> edges[MAXN];

void dfs1(int root, int par) {
    sum_in[root] = nums[root];
    for (int nxt : edges[root]) {
        if (nxt == par) continue;
        dfs1(nxt, root);
        sum_in[root] += sum_in[nxt];
        dp_in[root] += dp_in[nxt] + sum_in[nxt];
    }
}

void dfs2(int root, int par) {
    if (par > 0) {
        sum_out[root] = sum_in[par] - sum_in[root];
        dp_out[root] = dp_in[par] - dp_in[root] - sum_in[root] + sum_out[root];
    }
    sum_out[root] += sum_out[par];
    dp_out[root] += dp_out[par] + sum_out[par];
    for (int nxt : edges[root]) {
        if (nxt == par) continue;
        dfs2(nxt, root);
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
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    LL ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = max(ret, dp_in[i]+dp_out[i]);
    }
    cout << ret << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
    return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
