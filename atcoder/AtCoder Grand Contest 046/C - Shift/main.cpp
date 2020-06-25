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
const int MAXN = 303;
vector<LL> dp[MAXN][MAXN];
vector<int> cnt;
int k, n;
LL get(int i, int pre, int rem) {
  if (dp[i][pre].empty()) {
    dp[i][pre] = vector<LL>(k+1, -1);
  }
  if (dp[i][pre][rem] != -1) {
    return dp[i][pre][rem];
  }
  int tmp = min(cnt[i], pre);
  if (i == n-1) {
    int tmp2 = max(cnt[i] - (cnt[i-1] - pre) - rem, 0);
    dp[i][pre][rem] = (tmp - tmp2 + 1) % mod;
    return dp[i][pre][rem];
  }
  int used = cnt[i-1] - pre;
  used -= cnt[i] - tmp;
  int u = rem;
  dp[i][pre][rem] = 0;
  for (; tmp >= 0 && u >= 0; tmp--) {
    dp[i][pre][rem] = (dp[i][pre][rem] + get(i+1, tmp, u)) % mod;
    if (used > 0) used--;
    else u--;
  }
  return dp[i][pre][rem];
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  string s; cin >> s;

  cin >> k;
  n = s.size();
  vector<int> tmp(n, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      for (int j = 0; j < i; j++) {
        tmp[j]++;
      }
    }
  }
  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      cnt.push_back(tmp[i]);
      tot += tmp[i];
    }
  }
  k = min(tot, k);
  n = cnt.size();
  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }
  if (n == 1) {
    cout << k+1 << endl;
    return 0;
  }
  LL ret = 0;
  for (int pre = cnt[0]; pre >= 0; pre--) {
    int rem = k - cnt[0] + pre;
    if (rem < 0) break;
    ret = (ret + get(1, pre, rem)) % mod;
  }
  cout << ret << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
