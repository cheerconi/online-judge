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
int p[MAXN], c[MAXN];
bool used[MAXN];

int solve(int i) {
  vi nums;
  while (!used[i]) {
    used[i] = true;
    nums.push_back(i);
    i = p[i];
  }
  int m = nums.size();
  for (int j = 1; j <= m; j++) {
    if (m % j != 0) continue;
    for (int u = 0; u < j; u++) {
      bool succ = true;
      for (int v = u + j; v < m; v += j) {
        if (c[nums[u]] != c[nums[v]]) {
          succ = false;
          break;
        }
      }
      if (succ) return j;

    }
  }
  assert(false);
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
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      used[i] = false;
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    int ret = n;
    for (int i = 1; i <= n; i++) {
      if (used[i]) continue;
      ret = min(ret, solve(i));
    }
    cout << ret << endl;
  }




/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
