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
vector<LL> edges[63];
LL nums[MAXN];
int n;
map<LL, set<LL>> table;
int solve(LL s) {
  map<LL, int> deep;
  deep.emplace(s, 0);
  set<pll> used;
  int len = 0;
  queue<LL> q;
  q.push(s);
  while (!q.empty()) {
    int sz = q.size();
    len++;
    while (sz--) {
      LL cur = q.front(); q.pop();
      for (LL nxt : table[cur]) {
        pll tmp = make_pair(cur, nxt);
        if (tmp.first > tmp.second) {
          swap(tmp.first, tmp.second);
        }
        if (deep.find(nxt) != deep.end()) continue;
        deep.emplace(nxt, len);
        q.push(nxt);
        used.insert(tmp);
      }
    }
  }
  int ret = INT_MAX;
  for (const auto& item1 : deep) {
    for (const auto& item2 : deep) {
      if (item1.first >= item2.first) continue;
      if (table[item1.first].find(item2.first) == table[item1.first].end()) continue;
      if (used.find(make_pair(item1.first, item2.first)) != used.end()) continue;
      ret = min(ret, item2.second + item1.second + 1);
    }
  }
  return ret;
}







int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    for (int j = 0; j < 63; j++) {
      if (nums[i] & (1LL<<j)) {
        edges[j].push_back(i);
        if (edges[j].size() >= 3) {
          cout << 3 << endl;
          return 0;
        }
      }
    }
    nums[i] = i;
  }
  for (int k = 0; k < 63; k++) {
    assert(edges[k].size() <= 2);
    if (edges[k].size() <= 1) continue;
    table[edges[k][0]].insert(edges[k][1]);
    table[edges[k][1]].insert(edges[k][0]);
  }
  int ret = INT_MAX;
  for (int i = 0; i < n; i++) {
    ret = min(ret, solve(nums[i]));
  }
  if (ret == INT_MAX) ret = -1;
  cout << ret << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
