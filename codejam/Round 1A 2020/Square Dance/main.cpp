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
vector<vector<int>> mat;
set<int> rows[MAXN], cols[MAXN];

vector<int> get(int i, int j) {
  vector<int> ret;
  auto a = rows[i].lower_bound(j);
  auto tmp = a;
  tmp++;
  if (tmp != rows[i].end()) {
    ret.push_back(*tmp);
  } else {
    ret.push_back(-1);
  }
  if (a != rows[i].begin()) {
    tmp = a;
    tmp--;
    ret.push_back(*tmp);
  } else {
    ret.push_back(-1);
  }
  auto b = cols[j].lower_bound(i);
  auto tmp2 = b;
  tmp2++;
  if (tmp2 != cols[j].end()) {
    ret.push_back(*tmp2);
  } else {
    ret.push_back(-1);
  }
  if (b != cols[j].begin()) {
    tmp2 = b;
    tmp2--;
    ret.push_back(*tmp2);
  } else {
    ret.push_back(-1);
  }
  return ret;

}


bool check(int i, int j) {
  int cnt = 0, sum = 0;
  auto ret = get(i, j);
  for (int k = 0; k < 2; k++) {
    if (ret[k] != -1) {
      cnt++;
      sum += mat[i][ret[k]];
    }
  }
  for (int k = 2; k < 4; k++) {
    if (ret[k] != -1) {
      cnt++;
      sum += mat[ret[k]][j];
    }
  }

  return cnt > 0 && mat[i][j] * cnt < sum;
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    int n, m; cin >> n >> m;
    mat = vector<vi>(n, vi(m));
    for (int i = 0; i < n; i++) rows[i].clear();
    for (int j = 0; j < m; j++) cols[j].clear();
    set<pii> cands;
    LL cur = 0, ret = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
        rows[i].insert(j);
        cols[j].insert(i);
        cands.emplace(i, j);
        cur += mat[i][j];
      }
    }
    while (true) {
      ret += cur;
      set<pii> cands_nxt;
      vector<pii> loser;
      for (const auto& item : cands) {
        int x = item.first;
        int y = item.second;
        if (mat[x][y] == 0) continue;
        if (check(x, y)) {
          cur -= mat[x][y];
          loser.emplace_back(x, y);
        }
      }
      int flag = 0;
      for (const auto& item : loser) {
        int x = item.first;
        int y = item.second;
        mat[x][y] = 0;
        flag++;
        auto vs = get(x, y);
        for (int k = 0; k < 2; k++) {
          if (vs[k] != -1) {
            cands_nxt.emplace(x, vs[k]);
          }
        }
        for (int k = 2; k < 4; k++) {
          if (vs[k] != -1) {
            cands_nxt.emplace(vs[k], y);
          }
        }
        rows[x].erase(y);
        cols[y].erase(x);
      }
      cands = move(cands_nxt);
      if (flag == 0) break;
    }
    cout << "Case #" << cs << ": " << ret << '\n';


  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
