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
set<int> edges[MAXN], redges[MAXN];
int degree[MAXN], rdegree[MAXN], mark[MAXN], rmark[MAXN];






int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (a == b) {
      cout << "-1\n";
      return 0;
    }
    a--;
    b--;
    if (edges[a].find(b) != edges[a].end()) continue;
    edges[a].insert(b);
    degree[b]++;
    redges[b].insert(a);
    rdegree[a]++;
  }

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (degree[i] == 0) q.push(i);
    mark[i] = i;
  }
  int cnt = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop(); cnt++;
    for (int nxt : edges[cur]) {
      mark[nxt] = min(mark[nxt], mark[cur]);
      degree[nxt]--;
      if (degree[nxt] == 0) q.push(nxt);
    }
  }
  if (cnt != n) {
    cout << "-1\n";
    return 0;
  }
  queue<int> rq;
  for (int i = 0; i < n; i++) {
    if (rdegree[i] == 0) rq.push(i);
    rmark[i] = i;
  }
  while (!rq.empty()) {
    int cur = rq.front(); rq.pop();
    for (int nxt : redges[cur]) {
      rmark[nxt] = min(rmark[nxt], rmark[cur]);
      rdegree[nxt]--;
      if (rdegree[nxt] == 0) rq.push(nxt);
    }
  }
  string s(n, 'E');
  cnt = 0;
  for (int i= 0; i < n; i++) {
    if (min(mark[i], rmark[i]) == i) {
      s[i] = 'A';
      cnt++;
    }
  }
  cout << cnt << '\n' << s << '\n';










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
