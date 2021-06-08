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
const LL ns = 1e9;
const LL mod = 360LL * 12 * ns * 10;
LL h, m, s, n;

bool eq(LL a, LL b) {
  if (a == 0 && b != 0) return false;
  if (b == 0 && a != 0) return false;
  if (a > 0 && b < 0) return false;
  if (b > 0 && a < 0) return false;
  while (a < 0) a += mod;
  while (b < 0) b += mod;
  return a%mod == b%mod;
}

bool check(LL a, LL b, LL c, LL x, LL y, LL z) {
  LL tmp11 = b-a - (y-x);
  if (tmp11 < 0) tmp11 += mod;
  if (tmp11 % 11 != 0) return false;
  LL tmp = tmp11 / 11;
  if (tmp >= ns) return false;
  if (!eq(b -a, y  - x + tmp11)) return false;
  if (!eq(c -a, 720 * tmp + z - x - tmp)) return false;
  LL angle = a - x - tmp;
  if (b+angle != y + 12*tmp || mod-(b+angle) != 12*tmp) return false;
  if (c + angle != z + 720*tmp || mod - (c + angle) != 720*tmp) return false;

  h = x / ns / 60 / 60;
  m = y / ns / 12 / 60;
  s = z / ns / 720;
  n = tmp;
  return true;
}

void solve(LL a, LL b, LL c) {
  for (int i = 0; i < 12 * 60 * 60; i++) {
    LL x = i * ns;
    LL y = i * ns * 12 % mod;
    LL z = i * ns * 720 % mod;
    if (check(a, b, c, x, y, z)) return;
    if (check(a, c, b, x, y, z)) return;
    if (check(b, a, c, x, y, z)) return;
    if (check(b, c, a, x, y, z)) return;
    if (check(c, a, b, x, y, z)) return;
    if (check(c, b, a, x, y, z)) return;
  }
  assert(false);
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
    LL a, b, c; cin >> a >> b >> c;
    solve(a, b, c);
    cout << "Case #" << cs <<": " << h << ' ' << m << ' ' << s << ' ' << n << endl;
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
