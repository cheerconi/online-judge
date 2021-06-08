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
typedef pair<int, string> pis;
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
bool solve(int n, int m, int k, vector<pis>* ret) {
  if (k > 4*m*n - 2*m - 2*n) return false;
  vector<pis> cur;
  cur.emplace_back(m-1, "R");
  for (int i = 1; i < n; i++) {
    cur.emplace_back(1, "D");
    cur.emplace_back(m-1, "ULD");
    cur.emplace_back(m-1, "R");
  }
  cur.emplace_back(m-1, "L");
  cur.emplace_back(n-1, "U");
  for (const auto& item : cur) {
    int tmp = min(item.first, k / (int)item.second.size());
    if (tmp > 0) ret->emplace_back(tmp, item.second);
    k -= tmp * item.second.size();
    if (tmp < item.first && k > 0) {
      ret->emplace_back(1, item.second.substr(0, k));
      k = 0;
    }
    if (k == 0) break;
  }
  return true;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, k; cin >> n >> m >> k;
  vector<pis> ret;
  if (solve(n, m, k, &ret)) {
    cout << "YES\n";
    cout << ret.size() << '\n';
    for (const auto& item : ret) {
      cout << item.first << ' ' << item.second << '\n';
    }
  } else {
    cout << "NO\n";
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
