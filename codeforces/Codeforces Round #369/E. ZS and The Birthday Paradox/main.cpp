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
const int mod = 1e6 + 3;


LL power(LL base, LL p) {
  LL ret = 1;
  while(p) {
    if (p&1) ret = base * ret % mod;
    p >>= 1;
    base = base * base % mod;
  }
  return ret;
}

LL get_a(LL n, LL k) {
  if (k >= mod) return 0;
  if (n == 1) {
    if (k <= 2) return 1;
    return 0;
  }
  if (k == 1) return 1;
  LL s2 = power(2, n-1);
  LL s = s2 * 2 % mod;
  LL a = 1;
  for (int i = 1; i < k; i += 2) {
    a = a * (s - i + mod) % mod;
    if (a == 0) return 0;
  }
  a = a * get_a(n-1, (k+1)/2) % mod;
  return a;
}

LL get_2(LL n, LL k) {
  if (k == 1) return n;
  return (k+1)/2 + get_2(n-1, (k+1)/2);

}

LL get_b(LL n, LL k) {
  LL x = power(2, n);
  x = power(x, k);
  LL y = power(2, get_2(n, k));
  y = power(y, mod-2);
  return x * y % mod;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  LL n, k; cin >> n >> k;
  if (n <= 62 && (1LL<<n) < k) {
    cout << "1 1" << endl;
    return 0;
  }
  LL b = get_b(n ,k);
  LL a = get_a(n, k);
  a = (b - a + mod) % mod;
  cout << a << ' ' << b << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
