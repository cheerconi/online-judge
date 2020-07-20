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
const int MAXN = 5e5 + 10;
const int MAXB = 19;
int son[MAXN];
int par[MAXN][MAXB];
int dp[MAXN][2];

int get(int i, int a) {
  for (int j = MAXB-1; j >= 0; j--) {
    if (a&(1<<j)) {
      i = par[i][j];
    }
  }
  return i;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    int n, a, b; cin >> n >> a >> b;
    memset(son, 0, sizeof(son));
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <= n; i++) {
      int val; cin >> val;
      son[val]++;
      par[i][0] = val;
    }
    for (int i = 1; i < MAXB; i++) {
      for (int j = n; j >= 1; j--) {
        par[j][i] = par[par[j][i-1]][i-1];
      }
    }
    for (int i = n; i >= 1; i--) {
      dp[i][0] += 1;
      dp[i][1] += 1;
      int dad = get(i, a);
      dp[dad][0] += dp[i][0];
      dad = get(i, b);
      dp[dad][1] += dp[i][1];
    }
    LD ret = n;
    for (int i = 1; i <= n; i++) {
      ret -= (LD)(n-dp[i][0])/n*(n-dp[i][1])/n;
    }
    cout << "Case #" << cs << ": " << ret << '\n';

  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
