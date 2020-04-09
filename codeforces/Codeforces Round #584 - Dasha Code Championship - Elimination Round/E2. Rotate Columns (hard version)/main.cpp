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
const int MAXN = 12;
const int MAXM = 2000 + 10;
int nums[MAXN][MAXM], dp[MAXN + 10][1<<MAXN], cache[1<<MAXN];


bool cmp(const pii& a, const pii& b) {
  return nums[a.first][a.second] > nums[b.first][b.second];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    memset(dp, 0, sizeof(dp));
    int n, m; cin >> n >> m;
    vector<pii> pos;
    pos.reserve(n*m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> nums[i][j];
        pos.emplace_back(i, j);
      }
    }
    sort(pos.begin(), pos.end(), cmp);
    set<int> table;
    for (const auto& p : pos) {
      table.insert(p.second);
      if (table.size() == n) break;
    }
    m = 1<<n;
    int idx = 0;
    for (int j : table) {
      memset(cache, 0, sizeof(cache));
      for (int mask = 0; mask < m; mask++) {
        int val = 0;
        for (int i = 0; i < n; i++) {
          if (mask & (1<<i)) {
            val += nums[i][j];
          }
        }
        if (cache[mask] >= val) continue;
        for (int i = 0, now = mask; i < n; i++) {
          cache[now] = max(cache[now], val);
          now = (now>>1) | ((now&1) << (n-1));
        }
      }
      for (int mask = 0; mask < m; mask++) {
        for (int cur_mask = mask; ; cur_mask = (cur_mask-1)&mask) {
          dp[idx+1][mask] = max(dp[idx+1][mask], dp[idx][mask ^ cur_mask] + cache[cur_mask]);
          if (cur_mask == 0) break;
        }
      }
      idx++;
    }
    cout << dp[idx][(1<<n) - 1] << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
