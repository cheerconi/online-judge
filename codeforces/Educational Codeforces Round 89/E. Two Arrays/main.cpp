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
const int mod = 998244353;
const int MAXN = 2e5 + 10;
int a[MAXN], b[MAXN];

int solve(int n, int m,  map<int, int>& table) {
  int cur = table[b[0]];
  if (cur == 0) return 0;
  for (int i = 1; i < cur; i++) {
    if (a[i] < b[0]) return 0;
  }
  LL ret = 1;
  for (int i = 1; i < m; i++) {
    int nxt = table[b[i]];
    if (nxt == 0 || nxt <= cur) return 0;
    int tmp = cur;
    for (int j = cur+1; j < nxt; j++) {
      if (a[j] < b[i-1]) return 0;
      if (a[j] < b[i]) tmp = j;
    }
    ret = ret * (nxt - tmp) % mod;
    cur = nxt;
  }
  for (int i = cur+1; i <= n; i++) {
    if (a[i] < b[m-1]) return 0;
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
  map<int, int> table;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    table[a[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  cout << solve(n, m, table) << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
