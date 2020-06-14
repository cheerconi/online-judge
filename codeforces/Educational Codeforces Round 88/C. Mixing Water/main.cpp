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
LL gcd(LL a, LL b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b%a, a);
}
pll get_res(LL a, LL b, LL n, LL c) {
  LL x = (n+1)*a  + n * b;
  LL y = 2*n + 1;
  x = abs(x - y * c);
  LL tmp = gcd(x, y);
  return {x/tmp, y/tmp};

}

bool my_less(pll x, pll y) {
  return x.first * y.second < y.first * x.second;
}
int solve(int a, int b, int c) {
  if (c >= a) return 1;
  if ((a+b) >= c*2) return 2;
  int tmp = (a-c) / (2*c-a-b);
  pll res = get_res(a, b, tmp, c);
  int ret = tmp;
  if (tmp-1 >= 0) {
    pll res1 = get_res(a, b, tmp-1, c);
    if (my_less(res1, res)) {
      res = res1;
      ret = tmp-1;
    }
  }
  pll res2 = get_res(a, b, tmp+1, c);
  if (my_less(res2, res)) {
    ret = tmp+1;
  }
  return 2 * ret + 1;
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
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c) << '\n';

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
