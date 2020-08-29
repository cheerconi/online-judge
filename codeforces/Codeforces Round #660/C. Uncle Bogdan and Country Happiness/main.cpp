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
vi edges[MAXN];
LL nums[MAXN], diff[MAXN], cnt[MAXN];

bool dfs(int cur, int par) {
  cnt[cur] = nums[cur];
  LL bad = 0;
  for (int nxt : edges[cur]) {
    if (par == nxt) continue;
    if (!dfs(nxt, cur)) return false;
    cnt[cur] += cnt[nxt];
    LL tmp = cnt[nxt] - diff[nxt];
    if (tmp < 0 || tmp % 2 != 0) return false;
    bad += tmp / 2;
  }
  LL tot_bad = cnt[cur] - diff[cur];
  if (tot_bad < 0 || tot_bad % 2 != 0) return false;
  tot_bad /= 2;
  if (tot_bad - nums[cur] > bad) return false;
  return true;
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
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
      cnt[i] = 0;
      cin >> nums[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> diff[i];
    }
    for (int i = 0; i < n-1; i++) {
      int a, b; cin >> a >> b;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    if (dfs(1, 0)) cout << "YES\n";
    else cout << "NO\n";
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
