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
const int MAXN= 1e5 + 10;
vector<pii> edges[MAXN];
priority_queue<vector<LL>> pq;
LL sum;

LL dfs(int cur, int par) {
  LL cnt = 0;
  for (const auto& item : edges[cur]) {
    if (item.first == par) continue;
    LL tmp = dfs(item.first, cur);
    cnt += tmp;
    sum += tmp * item.second;
    LL diff = item.second - item.second/2;
    diff *= tmp;
    if (diff > 0) pq.push({diff, item.second, tmp});
  }
  if (cnt == 0) return 1;
  return cnt;
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
    LL s; cin >> s;
    for (int i = 1; i <= n; i++) {
      edges[i].clear();
    }
    for (int i = 0; i < n-1; i++) {
      int a, b, c; cin >> a >> b >> c;
      edges[a].emplace_back(b, c);
      edges[b].emplace_back(a, c);
    }
    sum = 0;
    pq = priority_queue<vector<LL>>();
    dfs(1, -1);
    int ret = 0;
    while (sum > s) {
      assert (!pq.empty());
      const auto item  = pq.top(); pq.pop();
      sum -= item[0];
      LL val = item[1] / 2;
      LL diff = val - val/2;
      diff *= item[2];
      if (diff > 0) pq.push({diff, val, item[2]});
      ret++;
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
