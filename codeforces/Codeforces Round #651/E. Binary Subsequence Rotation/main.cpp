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






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  string s, t;
  cin >> s >> t;
  deque<int> idx[2];
  for (int i = 0; i < n; i++) {
    if (s[i] == t[i]) continue;
    if (s[i] == '0') {
      idx[0].push_back(i);
    } else {
      idx[1].push_back(i);
    }
  }
  if (idx[1].size() != idx[0].size()) {
    cout << -1 << '\n';
    return 0;
  }
  set<int> dp[2];
  while (!idx[0].empty()) {
    int i = idx[0].front(); idx[0].pop_front();
    int j = idx[1].front(); idx[1].pop_front();
    if (i < j) {
      auto it = dp[0].begin();
      if (it != dp[0].end() && *it  < i) {
        dp[0].erase(it);
      }
      dp[0].insert(j);
    } else {
      auto it = dp[1].begin();
      if (it != dp[1].end() && *it  < j) {
        dp[1].erase(it);
      }
      dp[1].insert(i);
    }
  }
  cout << dp[0].size() + dp[1].size() << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
