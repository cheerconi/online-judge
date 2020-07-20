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
const int MAXN = 2e5 + 10;
int a[MAXN], b[MAXN];
LL n, m, x, k, y;

LL solve(int i, int j) {
  if (i == n) {
    if (j == m) return 0;
    int ma = b[j], cnt = 0;
    for (int u = j; u < m; u++) {
      cnt++;
      ma = max(ma, b[u]);
    }
    LL ret = 0;
    if (ma > a[i-1]) {
      if (cnt < k) return -1;
      cnt -= k;
      ret += x;
    }
    if (cnt % k != 0) {
      ret += cnt%k * y;
      cnt = cnt / k * k;
    }
    if (y*k <= x) {
      ret += y*cnt;
    } else {
      ret += cnt/k * x;
    }
    return ret;
  }
  if (j == m) return -1;
  int cnt = 0, ma = b[j];
  int idx = j;
  for (; idx < m; idx++) {
    if (b[idx] == a[i]) {
      break;
    }
    cnt++;
    ma = max(ma, b[idx]);
  }
  if (idx == m) return -1;
  LL ret = 0;
  if (ma > a[i] && (i == 0 || ma > a[i-1])) {
    if (cnt < k) return -1;
    cnt -= k;
    ret += x;
  }
  if (cnt % k != 0) {
    ret += cnt%k * y;
    cnt = cnt / k * k;
  }
  if (y*k <= x) {
    ret += y*cnt;
  } else {
    ret += cnt/k * x;
  }
  LL nxt = solve(i+1, idx+1);
  if (nxt == -1) return -1;
  return nxt + ret;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> m >> n;
  cin >> x >> k >> y;
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << solve(0, 0) << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
