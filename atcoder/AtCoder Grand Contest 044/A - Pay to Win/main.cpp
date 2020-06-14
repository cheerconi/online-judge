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
  int t; cin >> t;
  LL n, d;
  vi divs{2, 3, 5};
  LL costs[3];
  while (t--) {
    cin >> n >> costs[0] >> costs[1] >> costs[2] >> d;
    map<LL, LL> table;
    table[n] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.emplace(0, n);
    LL ret = LLONG_MAX;
    while(!pq.empty()) {
      pll cur = pq.top(); pq.pop();
      if (cur.first >= ret) break;
      if (table[cur.second] < cur.first) continue;
      if (cur.second * (LD)d + cur.first < 1e15) ret = min(ret, cur.second * d + cur.first);
      for (int i = 0; i < 3; i++) {
        int div = divs[i];
        LL cost = costs[i];
        LL x = cur.first + (cur.second % div) * d + cost;
        LL y = cur.second / div;
        auto it = table.find(y);
        if (it == table.end() || it->second > x) {
          table[y] = x;
          pq.emplace(x, y);
        }
        x = cur.first + (div - cur.second % div) * d + cost;
        y = cur.second / div + 1;
        it = table.find(y);
        if (it == table.end() || it->second > x) {
          table[y] = x;
          pq.emplace(x, y);
        }
      }
    }
    cout << ret << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
