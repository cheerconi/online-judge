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
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
vi edges[MAXN];
int ps[MAXN], sz[MAXN];
LL nums[MAXN];

void dfs(int cur, int par) {
  sz[cur] = 1;
  for(int nxt : edges[cur]) {
    if (nxt == par) continue;
    dfs(nxt, cur);
    sz[cur] += sz[nxt];
  }
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
      edges[i].clear();
    }
    for (int i = 0; i < n-1; i++) {
      int a, b; cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    dfs(1, -1);
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> ps[i];
    }
    sort(ps, ps+m);
    while (m > n-1) {
      ps[m-2] = 1LL * ps[m-1] * ps[m-2] % mod;
      m--;
    }
    reverse(ps, ps+m);

    for (int i = 2; i <= n; i++) {
      nums[i-2] = 1LL * (n-sz[i]) * sz[i];
    }
    sort(nums, nums+n-1, greater<LL>());
    LL ret = 0;
    for (int i = 0; i < n-1; i++) {
      if (i < m) ret = (ret + nums[i] % mod * ps[i] % mod) % mod;
      else ret = (ret + nums[i]) % mod;
    }
    cout << ret << '\n';
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
