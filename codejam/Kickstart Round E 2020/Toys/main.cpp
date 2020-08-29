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
LL a[MAXN], b[MAXN];

pll solve(int n) {
  LL suma = 0;
  vector<pll> tmp;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    suma += a[i];
    tmp.emplace_back(a[i]+b[i], i);
  }
  LL sum = suma;
  sort(tmp.begin(), tmp.end());
  while (!tmp.empty()) {
    if (suma < tmp.back().first) {
      suma -= a[tmp.back().second];
      tmp.pop_back();
    } else break;
  }
  if (!tmp.empty()) {
    return {n-(int)tmp.size(), -1};
  }
  priority_queue<pll> pq;
  LL x = 0, y = sum;
  pll ret{x, y};
  for (int i = 0; i < n; i++) {
    if (sum >= b[i]+a[i]) {
      y += a[i];
      pq.emplace(a[i]+b[i], i);
    } else {
      sum -= a[i];
      x++;
      y -= a[i];
      while (!pq.empty()) {
        auto item = pq.top();
        if (item.first <= sum) break;
        x++;
        sum -= a[item.second];
        y -= 2*a[item.second];
        pq.pop();
      }
    }
    if (ret.second < y) {
      ret = {x, y};
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
  for (int cs = 1; cs <= T; cs++) {
    int n; cin >> n;
    pll ret = solve(n);
    cout << "Case #" << cs << ": " << ret.first << ' ';
    if (ret.second == -1) cout << "INDEFINITELY\n";
    else cout << ret.second << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
