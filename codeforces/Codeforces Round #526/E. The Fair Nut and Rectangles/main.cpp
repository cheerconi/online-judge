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
const int MAXN = 1e6 + 10;
struct Item{
  LL x, y, a;
};
struct Frac{
  LL x, y;
  Frac(LL x_, LL y_): x(x_), y(y_){
    assert (y != 0);
    if (y < 0) {
      x = -x;
      y = -y;
    }
  }
  bool operator< (const Frac& other) const {
    return (LD)x * other.y < (LD)other.x * y;
  }
};
Item items[MAXN];
deque<pll> lines;
deque<Frac> xs;
LL dp[MAXN];


LL solve(LL y) {
  Frac p(y, 1);
  while (!xs.empty() && p < xs.back()) {
    xs.pop_back();
    lines.pop_back();
  }
  LL ret = 0;
  if (!lines.empty()) {
    ret = max(ret, y * lines.back().first + lines.back().second);
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
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> items[i].x >> items[i].y >> items[i].a;
  }
  sort(items, items+n, [](const Item& u, const Item& v) {return u.x < v.x;});
  LL ret = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = items[i].x * items[i].y - items[i].a;
    dp[i] += solve(items[i].y);
    ret = max(dp[i], ret);
    pll line = {-items[i].x, dp[i]};
    while (!xs.empty()) {
      LL u = lines.front().second - line.second;
      LL v = line.first - lines.front().first;
      Frac x(u, v);
      if (x < xs.front()) break;
      xs.pop_front();
      lines.pop_front();
    }
    lines.push_front(line);
    if (lines.size() >= 2) {
      LL u = lines[1].second - line.second;
      LL v = line.first - lines[1].first;
      Frac x(u, v);
      xs.push_front(x);
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
