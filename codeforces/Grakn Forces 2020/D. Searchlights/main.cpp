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
const int MAXN = 2333;
pii robbers[MAXN], lights[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> robbers[i].first >> robbers[i].second;
  }
  for (int i = 0; i < m; i++) {
    cin >> lights[i].first >> lights[i].second;
  }
  vector<pii> items;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (robbers[i].first <= lights[j].first && robbers[i].second <= lights[j].second) {
        items.emplace_back(lights[j].first-robbers[i].first+1,lights[j].second-robbers[i].second+1);
      }
    }
  }
  sort(items.begin(), items.end());
  vector<int> dp(items.size()+1);
  for (int i = (int)items.size()-1; i >= 0; i--) {
    dp[i] = items[i].second;
    dp[i] = max(dp[i+1], dp[i]);
  }
  int ret = dp[0];
  for (int i = 0; i < items.size(); i++) {
    ret = min(ret, items[i].first + dp[i+1]);
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
