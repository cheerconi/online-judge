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
int dp[5][5], tmp[5][5], nums[MAXN];



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout.precision(10); cout << fixed;
#ifdef LOCAL
    freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, val; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> val;
    nums[val]++;
  }
  memset(dp, -1, sizeof(dp));
  memset(tmp, -1, sizeof(tmp));
  dp[0][0] = 0;
  for (int idx = 1; idx <= m; idx++) {
    int num = nums[idx];
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        if (dp[i][j] == -1) continue;
        for (int a = 0; a <= j; a++) {
          int mi = min(i, j-a);
          for (int b = 0; b <= min(num, 4); b++) {
            int mii = min(mi, num-b);
            tmp[a][b] = max(tmp[a][b], dp[i][j] + mii + (num-b-mii) / 3);
          }
        }
      }
    }
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        dp[i][j] = tmp[i][j];
        tmp[i][j] = -1;
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      ret = max(ret, dp[i][j]);
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
