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
vi nums[3];

LL solve(const vi& a, const vi& b, const vi& c) {
  LL ret = LLONG_MAX;
  int i = 0, j = 0;
  for (int num : a) {
    while (i+1 < b.size() && b[i+1] <= num) i++;
    while (j < c.size() && c[j] < num) j++;
    if (i < b.size() && j < c.size() && b[i] <= num && num <= c[j]) {
      LL tmp = num - b[i];
      LL cur = tmp * tmp;
      tmp = c[j] - num;
      cur += tmp * tmp;
      tmp = c[j] - b[i];
      cur += tmp * tmp;
      ret = min(ret, cur);
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
  int t; cin >> t;
  int ns[3];
  while (t--) {
    for (int i = 0; i < 3; i++) {
      cin >> ns[i];
    }
    for (int i = 0; i < 3; i++) {
      nums[i] = vi(ns[i]);
      for (int j = 0; j < ns[i]; j++) {
        cin >> nums[i][j];
      }
      sort(nums[i].begin(), nums[i].end());
    }
    LL ret = LLONG_MAX;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j) continue;
        for (int k = 0; k < 3; k++) {
          if (k == i || k == j) continue;
          ret = min(ret, solve(nums[i], nums[j], nums[k]));
        }
      }
    }
    cout << ret << endl;
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
