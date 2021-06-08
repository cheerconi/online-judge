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
  int T; cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> dp(n, -1);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        dp[i] = 0;
        a = i;
        b = i+1;
        continue;
      }
      while (a < i && s[a] == '0') a++;
      b = max(b, i+1);
      while (b < n && s[b] == '0') b++;
      if (a == i && b == n) continue;
      if (a == i) {
        dp[i] = b - i;
        continue;
      }
      if (b == n) {
        dp[i] = i - a;
        continue;
      }
      int x = b-i;
      int y = i-a;
      if (x == y) continue;
      dp[i] = min(x, y);
    }
    for (int i = 0; i < n; i++) {
      if (dp[i] == -1 || dp[i] > m) cout << '0';
      else cout << '1';
    }
    cout << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
