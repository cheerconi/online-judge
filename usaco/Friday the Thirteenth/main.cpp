/*
ID: txingml
PROG: friday
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
set<int> ms{4, 6, 9, 11};





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);

  vi leap(7), nonleap(7);
  int d1 = 0, d2 = 0;
  for (int i = 1; i <= 12; i++) {
    int m = 31;
    if (i == 2) m = 28;
    if (ms.find(i) != ms.end()) m = 30;
    nonleap[(d1 + 12) % 7]++;
    leap[(d2+12) % 7]++;
    d1 = (d1 + m) % 7;
    d2 = (d2 + m) % 7;
    if (i == 2) d2 = (d2 + 1) % 7;
  }
  int n; cin >> n;
  int d = 1;
  vi ret(7);
  for (int i = 0; i < n; i++) {
    bool flag = false;
    int year = 1900 + i;
    if (year % 100 == 0) {
      if (year % 400 == 0) flag = true;
    } else {
      if (year % 4 == 0) flag = true;
    }
    if (flag) {
      for (int j = 0; j < 7; j++) {
        ret[(j+d)%7] += leap[j];
      }
      d = (d + 366) % 7;
    } else {
      for (int j = 0; j < 7; j++) {
        ret[(j+d)%7] += nonleap[j];
      }
      d = (d + 365) % 7;
    }
  }
  for (int i = 0; i < 7; i++) {
    cout << ret[(6+i)%7];
    if (i+1 == 7) cout << '\n';
    else cout << ' ';
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
