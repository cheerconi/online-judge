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
int a[MAXN], b[MAXN], w[MAXN], id[MAXN];
vi in[MAXN], out[MAXN];
int k, cur[10], ret;
int ban[10][10][10], ban2[10];

void dfs(int i) {
  if (i == k+1) {
    ret++;
    return;
  }
  for (int nxt = 1; nxt <= i; nxt++) {
    if (ban2[i] & (1<<nxt)) continue;
    bool flag = true;
    for (int j = 1; j < i; j++) {
      if (ban[i][nxt][j] & (1<<cur[j])) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cur[i] = nxt;
      dfs(i+1);
      cur[i] = 0;
    }
  }
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> w[i];
    in[b[i]].push_back(i);
    out[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    vector<pii> tmp;
    for (int j = 0; j < out[i].size(); j++) {
      tmp.emplace_back(w[out[i][j]], out[i][j]);
    }
    sort(tmp.begin(), tmp.end());
    for (int j = 0; j < tmp.size(); j++) {
      id[tmp[j].second] = j+1;
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<vi> tmp(10, vi(11));
    for (int u = 0; u < in[i].size(); u++) {
      int u_from = a[in[i][u]];
      tmp[out[u_from].size()][id[in[i][u]]-1]++;
    }
    for (int aa = 1; aa < 10; aa++) {
      for (int bb = 0; bb < 10; bb++) {
        if (tmp[aa][bb] > 1) ban2[aa] |= (1<<(bb+1));
        if (tmp[aa][bb] > 0){
          tmp[aa][10] |= (1<<(bb+1));
        }
      }
    }
    for (int aa = 1; aa < 10; aa++) {
      for (int bb = 0; bb < 10; bb++) {
        if (tmp[aa][bb] != 1) continue;
        for (int cc = 1; cc < 10; cc++) {
          if (aa == cc) continue;
          ban[aa][bb+1][cc] |= tmp[cc][10];
        }
      }
    }

  }
  dfs(1);
  cout << ret << '\n';









/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
