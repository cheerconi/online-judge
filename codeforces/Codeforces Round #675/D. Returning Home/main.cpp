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
int a[MAXN], b[MAXN], dist[MAXN];
vector<int> edges[MAXN];




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  pii x, y;
  cin >> x.first >> x.second >> y.first >> y.second;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    int val = min(abs(x.first - a[i]), abs(x.second - b[i]));
    pq.emplace(val, i);
    dist[i] = val;
  }
  vi idx(m);
  for (int i = 0; i < m; i++) {
    idx[i] = i;
  }

  sort(idx.begin(), idx.end(), [](int i, int j){return a[i] < a[j];});
  for (int i = 1; i < m; i++) {
    edges[idx[i]].push_back(idx[i-1]);
    edges[idx[i-1]].push_back(idx[i]);
  }
  sort(idx.begin(), idx.end(), [](int i, int j){return b[i] < b[j];});
  for (int i = 1; i < m; i++) {
    edges[idx[i]].push_back(idx[i-1]);
    edges[idx[i-1]].push_back(idx[i]);
  }
  int ret = abs(x.first - y.first) + abs(x.second - y.second);
  while (!pq.empty()) {
    pii item = pq.top(); pq.pop();
    int i = item.second;
    int val = item.first;
    if (val >= ret) break;
    if (dist[i] < val) continue;
    ret = min(ret, val + abs(a[i] - y.first) + abs(b[i] - y.second));
    for (int j : edges[i]) {
      int tmp = val + min(abs(a[j] - a[i]), abs(b[j] - b[i]));
      if (dist[j] <= tmp) continue;
      dist[j] = tmp;
      pq.emplace(tmp, j);
    }
  }
  cout << ret << '\n';




/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
