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
LL diff[MAXN];

LL solve(LL a, LL b) {
  LL c = a+b;
  if (c >= 0) return (c+1) / 2;
  return c / 2;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  LL first_one; cin >> first_one;
  int pre = first_one;
  LL increase = 0;
  for (int i = 1; i < n; i++) {
    int cur; cin >> cur;
    diff[i] = cur - pre;
    if (diff[i] > 0) increase += diff[i];
    pre = cur;
  }
  cout << solve(increase, first_one) << '\n';
  int q; cin >> q;
  while (q--) {
    int a, b, c; cin >> a >> b >> c;
    a--;
    b--;
    if (a == 0) {
      first_one += c;
    } else {
      LL tmp = diff[a] + c;
      if (diff[a] > 0) increase -= diff[a];
      diff[a] = tmp;
      if (diff[a] > 0) increase += diff[a];
    }
    if (b != n-1) {
      LL tmp = diff[b+1] - c;
      if (diff[b+1] > 0) increase -= diff[b+1];
      diff[b+1] = tmp;
      if (diff[b+1] > 0) increase += diff[b+1];
    }
    cout << solve(increase, first_one) << '\n';
  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
