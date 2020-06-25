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
const int MAXN = 1e5 + 10;
bool dp[MAXN][2][2];

bool solve01(LL a, LL b) {
  int tmp[2];
  tmp[b%2] = 0;
  tmp[1-b%2] = 1;
  LL cur = b/2;
  while (true) {
    if (a > cur) return tmp[a%2];
    int x = 1 - (tmp[(cur+1)%2] & tmp[0]);
    int y = 1 - (x & tmp[0]);
    tmp[cur%2] = x;
    tmp[1-cur%2] = y;
    cur /= 2;
  }
  assert(false);
}

bool solve00(LL a, LL b) {
  int tmp[2];
  tmp[0] = 0;
  tmp[1] = 0;
  LL cur = b/2;
  while (true) {
    if (a > cur) return tmp[a%2];
    int x = 1 - (tmp[(cur+1)%2] | tmp[0]);
    int y = 1 - (x | tmp[0]);
    tmp[cur%2] = x;
    tmp[1-cur%2] = y;
    cur /= 2;
  }
  assert(false);
}

bool solve10(LL a, LL b) {
  if (2*a > b) return 1;
  int ret = solve00(a+1, b);
  if (a*2 <= b) ret |= solve00(a*2, b);
  return ret;
}

bool solve11(LL a, LL b) {
  if (a == b) return 1;
  int ret = solve01(a+1, b);
  if (a*2 <= b) ret &= solve01(a*2, b);
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
  LL a, b;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    dp[i][0][0] = solve00(a, b);
    dp[i][0][1] = solve01(a, b);
    dp[i][1][0] = solve10(a, b);
    dp[i][1][1] = solve11(a, b);
  }
  int x = 1;
  bool flag = true;
  for (int i = t-1; i >= 0; i--) {
    if (dp[i][0][x] == x && dp[i][1][x] == x) {
      x = 0;
      break;
    }
    if (dp[i][0][x] != x && dp[i][1][x] != x) {
      flag = false;
      break;
    }
    if (dp[i][0][x] == x) x = 0;
    else x = 1;
  }
  cout << (flag && x == 0);

  x = 0;
  flag = true;
  for (int i = t-1; i >= 0; i--) {
    if (dp[i][0][x] == x && dp[i][1][x] == x) {
      x = 0;
      break;
    }
    if (dp[i][0][x] != x && dp[i][1][x] != x) {
      flag = false;
      break;
    }
    if (dp[i][0][x] == x) x = 0;
    else x = 1;
  }
  cout << ' ' << (flag && x == 0) << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
