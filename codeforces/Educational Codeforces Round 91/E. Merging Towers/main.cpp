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
vi dis[MAXN];
set<pii> table[MAXN];

int merge(int a, int b) {
  int diff = 0;
  for (const auto& item : table[b]) {
    auto it = table[a].lower_bound(item);
    pii tmp = item;
    if (it != table[a].begin()) {
      auto pre = it; pre--;
      if (pre->second+1 == item.first) {
        tmp.first = pre->first;
        table[a].erase(pre);
        diff--;
      }
    }
    if (it->first == item.second + 1) {
      tmp.second = it->second;
      table[a].erase(it);
      diff--;
    }
    table[a].insert(tmp);
  }
  table[b].clear();
  return diff;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int idx; cin >> idx;
    dis[idx].push_back(i);
  }
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    int a = 0;
    for (int b = 1; b < dis[i].size(); b++) {
      if (dis[i][b-1]+1 != dis[i][b]) {
        table[i].emplace(dis[i][a], dis[i][b-1]);
        a = b;
      }
    }
    table[i].emplace(dis[i][a], dis[i].back());
    cnt += table[i].size();
  }
//  for (int i = 1; i <= m; i++) {
//    cout << i << ':';
//    for (const auto item : table[i]) {
//      cout << ' ' << item.first+1 << "-->" << item.second+1;
//    }
//    cout << endl;
//  }
  cout << cnt -1 << '\n';
  for (int i = 0; i < m-1; i++) {
    int a, b; cin >> a >> b;
    if (table[a].size() > table[b].size()) {
      cnt += merge(a, b);
    } else {
      cnt += merge(b, a);
      table[a] = move(table[b]);
    }
//    for (int i = 1; i <= m; i++) {
//      cout << i << ':';
//      for (const auto item : table[i]) {
//        cout << ' ' << item.first+1 << "-->" << item.second+1;
//      }
//      cout << endl;
//    }
    cout << cnt - 1 << '\n';
  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
