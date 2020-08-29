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
const int MAXN = 3e5 + 10;
int x[MAXN], y[MAXN];






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, k; cin >> n >> m >> k;
  set<pii> table;
  for (int i = 0; i < k; i++) {
    int a, b; cin >> a >> b;
    x[a]++;
    y[b]++;
    table.emplace(a, b);
  }
  vector<pii> numx, numy;
  for (int i = 1; i <= n; i++) {
    numx.emplace_back(x[i], i);
  }
  for (int i = 1; i <= m; i++) {
    numy.emplace_back(y[i], i);
  }
  sort(numx.begin(), numx.end(), greater<pii>());
  sort(numy.begin(), numy.end(), greater<pii>());
  int ret = 0;
  for (const auto itemx : numx) {
    for (const auto itemy : numy) {
      if (itemx.first + itemy.first <= ret) break;
      if (table.find(make_pair(itemx.second, itemy.second)) == table.end()) {
        ret = max(ret, itemx.first + itemy.first);
      } else {
        ret = max(ret, itemx.first + itemy.first-1);
      }
    }
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
