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
const int MAXN = 2e5 + 10;
vector<int> edges[MAXN];
vector<pii> pars[MAXN];
bool used[MAXN];






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
      pars[i].clear();
      used[i] = false;
    }
    for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      edges[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
      for (const int j : edges[i]) {
        for (const int k : edges[j]) {
          pars[k].emplace_back(i, j);
        }
      }
    }
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
      if (used[i]) continue;
      bool flag = false;
      for (const auto& item : pars[i]) {
        if (used[item.first] || used[item.second]) continue;
        flag = true;
        break;
      }
      if (flag) {
        used[i] = true;
        ret.push_back(i);
      }
    }
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i+1 == ret.size()) cout << '\n';
        else cout << ' ';
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
