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
const int MAXN = 150000 + 10;
LL dp[2][MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, d; cin >> n >> m >> d;
  map<int, vector<pii>> table;
  for (int i = 0; i < m; i++) {
    int a, b, t; cin >> a >> b >> t;
    table[t].emplace_back(a, b);
  }
  int j = 0, pre_t = -1;
  for (const auto& item : table) {
    for (int i = 1; i <= n; i++) {
      dp[j][i] = 0;
      for (const auto& ab : item.second) {
        dp[j][i] += ab.second - abs(ab.first - i);
      }
    }
    if (pre_t != -1) {
      LL dist = (LL)d * (item.first - pre_t);
      int x = 1, y = 1;
      deque<int> idx;
      for (int i = 1; i <= n; i++) {
        while (y <= n && abs(y-i) <= dist) {
          while (!idx.empty()) {
            if (dp[j^1][idx.back()] <= dp[j^1][y]) idx.pop_back();
            else break;
          }
          idx.push_back(y);
          y++;
        }
        while (x <= n && abs(x-i) > dist) {
          if (!idx.empty() && idx.front() == x) {
            idx.pop_front();
          }
          x++;
        }
        dp[j][i] += dp[j^1][idx.front()];
      }
    }
    j ^= 1;
    pre_t = item.first;
  }
  LL ret = LLONG_MIN;
  for (int i = 1; i <= n; i++) {
    ret = max(ret, dp[j^1][i]);
  }
  cout << ret << '\n';





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
