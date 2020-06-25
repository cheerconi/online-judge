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
int w[MAXN], x[MAXN], y[MAXN];
vector<int> edges[MAXN];
bool used[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> x[i] >> y[i];
    w[x[i]]--;
    w[y[i]]--;
    edges[x[i]].push_back(i);
    edges[y[i]].push_back(i);
  }
  queue<int> q;
  for (int i = 0; i < m; i++) {
    if (w[x[i]] >= 0 || w[y[i]] >= 0) {
      q.push(i);
      used[i] = true;
    }
  }
  vector<int> ret;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    ret.push_back(cur);
    w[x[cur]]++;
    if (w[x[cur]] == 0) {
      for (int nxt : edges[x[cur]]) {
        if (used[nxt]) continue;
        used[nxt] = true;
        q.push(nxt);
      }
    }
    w[y[cur]]++;
    if (w[y[cur]] == 0) {
      for (int nxt : edges[y[cur]]) {
        if (used[nxt]) continue;
        used[nxt] = true;
        q.push(nxt);
      }
    }
  }
  if (ret.size() != m) {
    cout << "DEAD\n";
  } else {
    reverse(ret.begin(), ret.end());
    cout << "ALIVE\n";
    for (int i = 0; i < ret.size(); i++) {
      cout << ret[i]+1;
      if (i+1 == ret.size()) cout << '\n';
      else cout << ' ';
    }
  }










/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
