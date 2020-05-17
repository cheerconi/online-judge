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
LL solve1(LL a, LL b) {
  if (a == b) return 0;
  LL d = abs(a - b);
  LL x = 1, y = 2e9;
  while (x < y) {
    LL mid = (x + y + 1) >> 1;
    LL tmp = (1 + mid) * mid / 2;
    if (tmp > d) y = mid - 1;
    else x = mid;
  }
  return x;
}

LL query(LL a, LL cur) {
  if (cur > a) return 0;
  LL x = 1, y = min(a/cur,  (LL)2e9);
  while (x < y) {
    LL mid = (x + y + 1) >> 1;
    LL tmp = (cur + cur + (mid-1) * 2) * mid / 2;
    if (tmp > a) y = mid - 1;
    else x = mid;
  }
  return x;
}

LL solve2(LL &a, LL &b, LL cur) {
  LL x = 0, y = 0;
  if (a >= b) {
    x = query(a, cur);
    y = query(b, cur+1);
  } else {
    x = query(b, cur);
    y = query(a, cur+1);
  }

  LL u = min(x, y);
  LL ret = u * 2;

  LL tmp1 = (cur + cur + (u-1)*2) * u / 2;
  LL tmp2 = (cur+1 + cur+1 + (u-1)*2) * u / 2;
  if (a >= b) {
    a -= tmp1;
    b -= tmp2;
  } else {
    b -= tmp1;
    a -= tmp2;
  }

  if (x > y) {
    ret++;
    if (a >= b) a -= cur+ret-1;
    else b -= cur+ret-1;
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
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    LL a, b; cin >> a >> b;
    LL cur = solve1(a, b);
    if (a > b) {
      a -= (1 + cur) * cur / 2;
    } else {
      b -= (1 + cur) * cur / 2;
    }
    LL ret = cur + solve2(a, b, cur+1);
    cout << "Case #" << cs << ": " << ret << " " << a << " " << b << '\n';


  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
