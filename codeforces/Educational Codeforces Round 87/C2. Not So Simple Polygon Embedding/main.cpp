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
const LD eps = 1e-8;
const LD pi = acos((LD)-1);

pair<LD, LD> check(LD v, LD c) {
  LD h = 0, cur = c;
  while (cur < pi) {
    h += std::sin(cur);
    cur = pi - v + cur;
  }
  LD w = 0;
  cur = c;
  while (cur < pi/2) {
    w += std::cos(cur);
    cur = pi - v + cur;
  }
  cur = pi - v - c;
  while (cur < pi/2) {
    w += std::cos(cur);
    cur = pi - v + cur;
  }
  return {h, w};
}


LD solve(int n) {
  LD v = pi * (n-2) / n;
  LD a = 0, b = pi/2 - v/2;
  while (b - a > eps) {
    LD c = (b+a) / 2;
    auto tmp = check(v, c);
    if (tmp.first - tmp.second >= 0) {
      b = c;
    } else {
      a = c;
    }
  }
  return check(v, a).first;

}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    n *= 2;
    cout << solve(n) << '\n';

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
