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
int nxt[MAXN][26], tot;
vi trie[MAXN];


LL solve(vector<string>& items) {
  while (true) {
    trie[tot].clear();
    for (int i = 0; i < 26; i++) {
      nxt[tot][i] = 0;
    }
    if (tot == 0) break;
    tot--;
  }
  sort(items.begin(), items.end());
  LL n = items.size();
  int m = items[0].size();
  LL ret = n * (n-1);
  vector<vi> idx2trie(n, vi(m+1));
  for (int i = 0; i < n; i++) {
    const auto& item = items[i];
    int cur = 0;
    trie[cur].push_back(i);
    for (int j = m-1; j >= 0; j--) {
      int c = item[j] - 'a';
      if (nxt[cur][c] == 0) {
        nxt[cur][c] = ++tot;
      }
      cur = nxt[cur][c];
      trie[cur].push_back(i);
      idx2trie[i][j] = cur;

    }
  }
  vector<pii> lcps;
  lcps.emplace_back(-1, n);
  for (int i = n-2; i >= 0; i--) {
    int lcp = 0;
    while (lcp < m && items[i][lcp] == items[i+1][lcp]) lcp++;
    while (lcps.back().first >= lcp) {
      lcps.pop_back();
    }
    lcps.emplace_back( lcp, i+1);
    vi segment(1, 0);
    for (int j = 1; j < m; j++) {
      if (items[i][j] < items[i][j-1]) {
        segment.push_back(j);
      }
    }
    segment.push_back(m);
    for (int j = 1; j < segment.size(); j++) {
      int prefix = segment[j-1];
      int a = i+1;
      auto it = lower_bound(lcps.begin(), lcps.end(), make_pair(prefix, -1));
      if (it == lcps.end()) continue;
      it--;
      int b = it->second - 1;
      const vi& idxs = trie[idx2trie[i][segment[j]]];
      int sz = upper_bound(idxs.begin(), idxs.end(), b) - lower_bound(idxs.begin(), idxs.end(), a);
      ret -= sz;
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
  LL n; cin >> n;
  map<string, vector<string>> table;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    table[sorted_s].push_back(s);
  }
  LL ret1 = 0, ret2 = 0;
  for (auto& item : table) {
    LL sz = item.second.size();
    ret1 += 1337 * sz * (n - sz);
    ret2 += solve(item.second);
  }
  cout << ret1 / 2 + ret2 << '\n';






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
