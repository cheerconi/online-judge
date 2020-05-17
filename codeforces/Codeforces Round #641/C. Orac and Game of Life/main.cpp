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
const int MAXN = 1000;
string mat[MAXN];
int bias[MAXN][MAXN], n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<pii> get(int i, int j) {
  vector<pii> ret;
  for (int k = 0; k < 4; k++) {
    int a = i + dx[k];
    int b = j + dy[k];
    if (a >= 0 && a < n && b >= 0 && b < m) ret.emplace_back(a, b);
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
  int Q; cin >> n >> m >> Q;
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  memset(bias, -1, sizeof(bias));
  queue<pii> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      auto ngb = get(i, j);
      for (const auto& item : ngb) {
        if (mat[item.first][item.second] == mat[i][j]) {
          bias[i][j] = 1;
          q.emplace(i, j);
          break;
        }
      }
    }
  }
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    auto ngb = get(cur.first, cur.second);
    for (const auto& item : ngb) {
      if (bias[item.first][item.second] != -1) continue;
      assert (mat[item.first][item.second] != mat[cur.first][cur.second]);
      bias[item.first][item.second] = bias[cur.first][cur.second] + 1;
      q.emplace(item.first, item.second);
    }
  }
  while (Q--) {
    LL i, j, p;
    cin >> i >> j >> p;
    i--; j--;
    if (bias[i][j] == -1 || p < bias[i][j]) {
      cout << mat[i][j] << '\n';
    } else {
      p -= bias[i][j];
      char c = mat[i][j];
      if (p % 2 == 0) c =  1 - (c - '0') + '0';
      cout << c << '\n';
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
