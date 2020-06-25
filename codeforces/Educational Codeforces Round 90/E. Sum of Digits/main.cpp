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
LL solve(int cnt) {
  assert(cnt > 0);
  int n = 1;
  while (n*9 < cnt) n++;
  LL ret = 0;
  while (n > 0) {
    for (int i = 1; i <= 9; i++) {
      if (cnt-i <= (n-1)*9) {
        ret = ret * 10 + i;
        cnt -= i;
        break;
      }
    }
    n--;
  }
  return ret;
}

LL solve(int a, int b, int cnt) {
  assert(cnt > 0);
  LL ret = LLONG_MAX;
  for (int i = 0; i <= 8; i++) {
    int sum = a*i + b*(i+1);
    if (sum > cnt) continue;
    if (sum == cnt) {
      ret = min(ret, (LL)i);
      continue;
    }
    if ((cnt - sum) % (a+b) == 0) {
      LL tmp = solve((cnt-sum)/ (a+b));
      if (tmp != -1) {
        ret = min(ret, tmp*10 + i);
      }
    }
  }
  int sum = 9*a;
  if (cnt > sum) {
    LL tmp = solve(a, b, cnt - sum);
    if (tmp != -1) ret = min(ret, tmp*10 + 9);
  }
  if (ret == LLONG_MAX) return -1;
  return ret;
}

LL solve(int n, int k) {
  if (k == 0) return solve(n);
  LL ret = LLONG_MAX;
  for (int i = 0; i < 10; i++) {
    int sum = 0;
    int a = 0, b = 0;
    for (int j = 0; j <= k; j++) {
      sum += (i+j) % 10;
      if (i+j < 10) a++;
      else b++;
    }
    if (sum > n) continue;
    if (sum == n) {
      if (b == 0) ret = min(ret, (LL)i);
      continue;
    }
    if (b == 0 && (n - sum) % a == 0) {
      LL tmp = solve((n-sum)/a);
      if (tmp != -1) {
        ret = min(ret, tmp*10 + i);
      }
      continue;
    }
    LL tmp = solve(a, b, n - sum);
    if (tmp != -1) ret = min(ret, tmp*10 + i);
  }
  if (ret == LLONG_MAX) return -1;
  return ret;
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
    int n, k; cin >> n >> k;
    cout << solve(n, k) << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
