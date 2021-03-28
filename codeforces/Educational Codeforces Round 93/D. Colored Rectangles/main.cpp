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

int solve(deque<int> as, deque<int> bs, deque<int> cs, vector<int> cnt) {
  int ret = 0;
  while (cnt[0] || cnt[1] || cnt[2]) {
    int tmp = 0;
    int idx = -1;
    if (cnt[0]) {
      if (as[0] * bs[0] >= tmp) {
        tmp = as[0] * bs[0];
        idx = 0;
      }
    }
    if (cnt[1]) {
      if (as[0] * cs[0] >= tmp) {
        tmp = as[0] * cs[0];
        idx = 1;
      }
    }
    if (cnt[2]) {
      if (bs[0] * cs[0] >= tmp) {
        tmp = bs[0] * cs[0];
        idx = 2;
      }
    }

    assert(idx != -1);
    ret += tmp;
    if (idx == 0) {
      as.pop_front();
      bs.pop_front();

    }
    if (idx == 1) {
      as.pop_front();
      cs.pop_front();
    }
    if (idx == 2) {
      bs.pop_front();
      cs.pop_front();
    }
    cnt[idx]--;
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
  int a, b, c;
  cin >> a >> b >> c;
  deque<int> as, bs, cs;
  for (int i = 0; i < a; i++) {
    int val; cin >> val;
    as.push_back(val);
  }
  for (int i = 0; i < b; i++) {
    int val; cin >> val;
    bs.push_back(val);
  }
  for (int i = 0; i < c; i++) {
    int val; cin >> val;
    cs.push_back(val);
  }
  sort(as.begin(), as.end(), greater<int>());
  sort(bs.begin(), bs.end(), greater<int>());
  sort(cs.begin(), cs.end(), greater<int>());

  int ret = 0;
  for (int i = 0; i <= min(a, b); i++) {
    for (int j = 0; j <= min(a-i, c); j++) {
      int k = min(b-i, c-j);
      if (a-i-j > 0 && b-j-k > 0) continue;
      ret = max(ret, solve(as, bs, cs, {i, j, k}));
    }
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
