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
const int MAXN = 24;
const int MAXM = 5e4 + 10;
int nums[MAXN][MAXM];
const int mod = 998244353;
LL tot;

LL solve(int j, int n) {
  vector<int> tmp;
  for (int i = 0; i < n; i++) {
    if (nums[i][j] == 1) return tot;
    tmp.push_back(n+1-nums[i][j]);
  }
  sort(tmp.begin(), tmp.end(), greater<int>());
  int cur = 0, k = 0;
  LL ret = 1;
  for (int i = n-1; i >= 0; i--) {
    cur++;
    while (k < tmp.size() && tmp[k] >= i) {
      ret = ret * cur % mod;
      if (ret == 0) return tot;
      cur--;
      k++;
    }
  }
  for (int i = 0; i < n - tmp.size(); i++) {
    ret = ret * (i+1) % mod;
  }
  return (tot - ret + mod) % mod;

}

LL power(LL base, int p) {
  LL ret = 1;
  while (p) {
    if (p&1) ret = ret * base % mod;
    base = base * base % mod;
    p >>= 1;
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
  int n, m; cin >> n >> m;
  tot = 1;
  for (int i = 2; i <= n; i++) {
    tot = tot * i % mod;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> nums[i][j];
    }
  }
  LL ret = 0;
  for (int j = 0; j < m; j++) {
    ret = (ret + solve(j, n)) % mod;
  }
  ret = ret * power(tot, mod-2) % mod;
  cout << ret << endl;









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
