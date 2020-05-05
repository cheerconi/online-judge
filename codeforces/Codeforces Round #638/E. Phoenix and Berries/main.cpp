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


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, k; cin >> n >> k;
  LL a = 0, b = 0;
  LL x, y;
  vector<bool> used(k, false);
  used[0] = true;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    b += y;
    a += x;
    LL tmp1 = max(k - y, 0LL);
    LL tmp2 = min(x, (x+y)/k*k);
    if (tmp1 > tmp2) continue;
    vector<bool> cur(k, false);
    for (int idx = 0; idx < k && tmp1 <= tmp2; idx++) {
      int rem = tmp1 % k;
      tmp1++;
      for (int j = 0; j < k; j++) {
        if (!used[j]) continue;
        cur[(rem+j) % k] = true;
      }
    }
    for (int i = 0; i < k; i++) {
      used[i] = used[i] || cur[i];
    }

  }
  LL ret = a / k + b / k;
  a %= k;
  b %= k;
  for (int i = 0; i < k; i++) {
    if (!used[i]) continue;
    if (i <= a && b+i >= k) {
      ret++;
      break;
    }
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
