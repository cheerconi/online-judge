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
int a[MAXN], t[MAXN], p[MAXN];
vector<int> edges[MAXN];
pll dp[200];
vector<pii> op;

vector<int> solve(int n) {
    LL res = 0;
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        memset(dp, -1, sizeof(dp));
        op.clear();
        dp[0] = {0, 0};
        op.emplace_back(-1, -1);
        for (int idx: edges[i]) {
            for (int j = 99; j >= 0; j--) {
                if (dp[j].first == -1) continue;
                int k = j + p[idx];
                if (dp[k].first == -1 || dp[k].first > dp[j].first + t[idx]) {
                    dp[k].first = dp[j].first + t[idx];
                    dp[k].second = op.size();
                    op.emplace_back(idx, dp[j].second);
                }
            }
        }
        int tmp = -1;
        for (int j = 100; j < 200; j++) {
            if (dp[j].first == -1) continue;
            if (tmp == -1 || dp[tmp].first > dp[j].first) tmp = j;
        }
        if (tmp == -1) return {};
        res += a[i];
        if (i - 1 >= 0) res -= a[i - 1];
        if (dp[tmp].first > res) return {};
        res -= dp[tmp].first;
        int j = dp[tmp].second;
        while (j > 0) {
            ret.push_back(op[j].first);
            j = op[j].second;
        }
    }
    return ret;

}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
    int T; cin >> T;
    int e;
    while(T--) {
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            edges[i].clear();
        }
        for (int i = 0; i < m; i++) {
            cin >> e >> t[i] >> p[i];
            e--;
            edges[e].push_back(i);
        }
        vector<int> ret = solve(n);
        if (ret.empty()) {
            cout << "-1\n";
        } else {
            cout << ret.size() << '\n';
            for (int i = 0; i < ret.size(); i++) {
                cout << ret[i]+1;
                if (i+1 == ret.size()) cout << '\n';
                else cout << ' ';
            }
        }
    }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
