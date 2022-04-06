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
const int MAXN = 100000 + 10;
int nums[MAXN], fi[MAXN];
LL dp[MAXN];
vector<int> edges[MAXN];

void dfs(int cur, int par) {
    dp[cur] = 0;
    fi[cur] = INT_MAX;
    for (int nxt : edges[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        dp[cur] += dp[nxt];
        fi[cur]  = min(fi[cur], fi[nxt]);
    }
    if (dp[cur] == 0) {
        dp[cur] = nums[cur];
        fi[cur] = nums[cur];
        return;
    }
    assert(fi[cur] < INT_MAX);
    if (fi[cur] >= nums[cur]) return;
    dp[cur] -= fi[cur];
    dp[cur] += nums[cur];
    fi[cur] = nums[cur];
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int n, par; cin >> n;
        edges[n].clear();
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
            edges[i-1].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> par;
            edges[par].push_back(i);
        }
        assert(nums[0] == 0);
        dfs(0, -1);
        cout << "Case #" << cs << ": " <<  dp[0] << '\n';

    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
