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
const int MAXN = 2e5  + 10;
int nums[MAXN][2], ret[MAXN];
set<pii>::iterator it[MAXN];
set<int> edges[MAXN];


void clean(set<pii>& table, int k) {
  int b= 0;
  while (!table.empty() && table.begin()->first < k) {
    int node = table.begin()->second;
    auto edge_it = edges[node].begin();
    while (edge_it != edges[node].end()) {
      int nxt = *edge_it;
      if (it[nxt] == table.end()) {
        edge_it = edges[node].erase(edge_it);
        continue;
      }
      auto tmp = *it[nxt];
      table.erase(it[nxt]);
      tmp.first--;
      it[nxt] = table.insert(tmp).first;
      edge_it++;
    }
    table.erase(it[node]);
    it[node] = table.end();
  }
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> nums[i][0] >> nums[i][1];
    edges[nums[i][0]].insert(nums[i][1]);
    edges[nums[i][1]].insert(nums[i][0]);
  }
  set<pii> table;
  for (int i = 1; i <= n; i++) {
    it[i] = table.emplace(edges[i].size(), i).first;
  }
  clean(table, k);
  ret[m] = table.size();
  for (int i = m-1; i > 0; i--) {
    if (it[nums[i][0]] != table.end() && it[nums[i][1]] != table.end()) {
      auto tmp = *it[nums[i][0]];
      table.erase(it[nums[i][0]]);
      tmp.first--;
      it[nums[i][0]] = table.insert(tmp).first;
      edges[nums[i][0]].erase(nums[i][1]);

      tmp = *it[nums[i][1]];
      table.erase(it[nums[i][1]]);
      tmp.first--;
      it[nums[i][1]] = table.insert(tmp).first;
      edges[nums[i][1]].erase(nums[i][0]);

      clean(table, k);

    }
    ret[i] = table.size();

  }
  for (int i = 1; i <= m; i++) {
    cout << ret[i] << '\n';
  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
