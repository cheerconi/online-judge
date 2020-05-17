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
const int MAXN = 1234;
pii mat[MAXN][MAXN];
string ret[MAXN];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
string actions = "LURD";
int n;


pii find(int i, int j) {
  for (int k = 0; k < 4; k++) {
    int a = i + dx[k];
    int b = j + dy[k];
    if (a < 0 || b < 0 || a >= n || b >= n) continue;
    if (mat[a][b] == make_pair(-2, -2)) {
      assert(ret[a][b] == 'Y');
      ret[a][b] = actions[k];
      return {a, b};
    }
  }
  return {-1, -1};
}

void dfs(int i, int j) {
  for (int k = 0; k < 4; k++) {
    int a = i + dx[k];
    int b = j + dy[k];
    if (a < 0 || b < 0 || a >= n || b >= n) continue;
    if (mat[a][b] == make_pair(-2, -2) && ret[a][b] == 'Y') {
      ret[a][b] = actions[k];
      dfs(a, b);
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
  cin >> n;
  queue<pii> q;
  for (int i = 0; i < n; i++) {
    ret[i] = string(n,'Y');
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j].first >> mat[i][j].second;
      mat[i][j].first--;
      mat[i][j].second--;
      if (i == mat[i][j].first && j == mat[i][j].second) {
        q.emplace(i, j);
        ret[i][j] = 'X';
      }
    }
  }
  while (!q.empty()) {
    pii cur = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int i = cur.first + dx[k];
      int j = cur.second + dy[k];
      if (i < 0 || i >= n || j < 0 || j >= n) continue;
      if (ret[i][j] != 'Y') continue;
      if (mat[cur.first][cur.second] != mat[i][j]) continue;
      ret[i][j] = actions[k];
      q.emplace(i, j);
    }
  }
  bool succ = true;
  for (int i = 0; i < n && succ; i++) {
    for (int j = 0; j < n; j++) {
      if (ret[i][j] != 'Y') continue;
      if (mat[i][j] != make_pair(-2, -2)) {
        succ = false;
        break;
      }
      auto p = find(i, j);
      if (p.first == -1) {
        succ = false;
        break;
      }
      dfs(p.first, p.second);
    }
  }
  if (succ) {
    cout << "VALID\n";
    for (int i = 0; i < n; i++) cout << ret[i] << '\n';
  } else{
    cout << "INVALID\n";
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
