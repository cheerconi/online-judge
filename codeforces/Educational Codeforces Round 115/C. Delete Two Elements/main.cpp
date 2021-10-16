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
map<int,int> table;

LL solve(int n) {
  LL sum = 0;
  for (auto it = table.begin(); it != table.end(); it++) {
    LL val = it->first;
    LL cnt = it->second;
    sum += val * cnt;
  }
  sum *= 2;
  if (sum % n != 0) return 0;
  sum /= n;
  LL ret = 0;
  for (auto tmp = table.begin(); tmp != table.end(); tmp++) {
    LL val = tmp->first;
    LL cnt = tmp->second;
    LL target = sum - val;
    if (target > val) continue;
    if (target != val) {
      auto it = table.find(target);
      if (it != table.end()) ret += cnt * it->second;
    } else {
      ret += cnt * (cnt-1) / 2;
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
  while (T--) {
    int n; cin >> n;
    table.clear();
    for (int i = 0; i < n; i++) {
      int val; cin >> val;
      table[val]++;
    }
    cout << solve(n) << endl;

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
