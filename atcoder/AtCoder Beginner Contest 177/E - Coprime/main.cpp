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
int fact[MAXN];
bool used[MAXN];

int gcd(int a, int b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b%a, a);
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  for (int i = 2; i < MAXN; i++) {
    if (fact[i] != 0) continue;
    for (int j = i+i; j < MAXN; j += i) {
      fact[j] = i;
    }
  }
  int n; cin >> n;
  int ret = 0;
  bool pairwise = true;
  for (int i = 0; i < n; i++) {
    int val; cin >> val;
    ret = gcd(ret, val);
    if (!pairwise) continue;
    set<int> ps;
    while (val > 1 && fact[val]) {
      ps.insert(fact[val]);
      val /= fact[val];
    }
    if (val > 1) ps.insert(val);
    for (int p : ps) {
      if (used[p]) pairwise = false;
      else used[p] = true;
    }
  }
  if (ret != 1) cout << "not coprime\n";
  else if (pairwise) cout << "pairwise coprime\n";
  else cout << "setwise coprime\n";







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
