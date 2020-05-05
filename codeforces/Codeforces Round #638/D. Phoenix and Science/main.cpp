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
  while (t--) {
    LL n; cin >> n;
    LL cur = 1;
    n--;
    vector<LL> ret;
    while (n > 0) {
      assert (cur <= n);
      if (cur * 2 >= n) {
        ret.push_back(n-cur);
        cur = n;
        n = 0;
      } else if (cur * 4 <= n) {
        ret.push_back(cur);
        cur = cur * 2;
        n -= cur;
      } else if (n > 2*cur && n <= 3*cur) {
        ret.push_back(0);
        n -= cur;
      } else {
        LL x = (cur + 1) / 2;
        ret.push_back(x);
        cur += x;
        n -= cur;
      }
    }
    assert (n == 0);
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
