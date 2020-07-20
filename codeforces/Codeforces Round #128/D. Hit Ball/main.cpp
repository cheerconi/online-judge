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

pii add(pii a, pii b) {
  return {a.first * b.second + b.first * a.second, a.second * b.second};
}

pii div(pii a, pii b) {
  return {a.first * b.second, a.second * b.first};
}

pii mul(pii a, pii b) {
  return {a.first * b.first, a.second * b.second};
}

double solve(pii t, int speed, int len, pii offset) {
  int sign = 1;
  if (speed < 0) {
    speed = -speed;
    sign = 0;
  }
  pii dist = add(offset, mul({speed, 1}, t));
  pii times = div(dist, {len , 1});
  int n = times.first / times.second;
  int k = times.first % times.second;
  double ret = (double)k / times.second * len;
  if (n % 2 == sign) ret = len - ret;
  return ret;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int a, b, m;
  cin >> a >> b >> m;
  int x, y, z;
  cin >> x >> y >> z;
  pii t = {m, -y};
  cout << solve(t, x, a, {a, 2}) << ' ' << solve(t, z, b, {0, 1}) << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
