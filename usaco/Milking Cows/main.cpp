/*
ID: txingml
PROG: milk2
LANG: C++
*/
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
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);
  int n, a, b; cin >> n;
  vector<pii> data;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    data.emplace_back(a, b);
  }
  sort(data.begin(), data.end());
  a = 0, b = 0;
  int s = -1, e = -1;
  for (const auto& item : data) {
    if (s == -1) {
      s = item.first;
      e = item.second;
      a = e - s;
      continue;
    }
    if (item.first <= e) {
      e = max(item.second, e);
      a = max(a, e-s);
      continue;
    }
    b = max(b, item.first - e);
    a = max(a, item.second - item.first);
    s = item.first;
    e = item.second;
  }
  cout << a << ' ' << b << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
