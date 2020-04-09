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
int m;
vector<pii> ret;
void solve(int a, int b) {
  if (a == b+1) return;
  ret.emplace_back(a, 1);
  for (int i = 1; i < m; i++) {
    if (i % 2 == 1) {
      ret.emplace_back(b, m-i/2);
    } else {
      ret.emplace_back(a, i/2 + 1);
    }
  }
  if (a == b) return;
  vector<pii> tmp;
  tmp.emplace_back(b, 1);
  for (int i = 1; i < m; i++) {
    if (i % 2 == 1) {
      tmp.emplace_back(a, m - i/2);
    } else {
      tmp.emplace_back(b, i/2 + 1);
    }
  }
  reverse(tmp.begin(), tmp.end());
  ret.insert(ret.end(), tmp.begin(), tmp.end());
  solve(a+1, b-1);
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n >> m;
  solve(1, n);
  for (const auto& item : ret) {
    cout << item.first << ' ' << item.second << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
