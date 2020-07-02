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
const int MAXN = 123;
string mat[MAXN];
int dist[MAXN][MAXN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
string cmd;
pii cur, par[MAXN][MAXN];

void move(char c) {
  cout << c << endl;
  cin >> cur.first >> cur.second;
  assert(cur.first != -1 && cur.second != -1);
  cur.first--;
  cur.second--;
  if (mat[cur.first][cur.second] == 'F') exit(0);
}

void solve(int n, int m) {
  cmd = string(4, '?');
  cur.first = 0;
  cur.second = 0;
  if (n == 1) {
    cmd[2] = 'U';
    cmd[3] = 'D';
  } else if (mat[1][0] != '*') {
    move('U');
    if (cur.first == 0) {
      cmd[2] = 'U';
      cmd[3] = 'D';
    } else {
      cmd[3] = 'U';
      cmd[2] = 'D';
    }
  } else {
    move('L');
    if (cur.second == 0) {
      cmd[1] = 'L';
      cmd[0] = 'R';
    } else {
      cmd[0] = 'L';
      cmd[1] = 'R';
    }
  }
  if (cmd[1] == '?') {
    int i = 0;
    bool flag = false;
    for (; i < n; i++) {
      if (mat[i][0] == '*') break;
      if (mat[i][1] != '*') {
        flag = true;
        break;
      }
    }
    if (flag) {
      while (cur.first != i) {
        int diff = abs(cur.first - i);
        if (cur.first < i) move(cmd[3]);
        else move(cmd[2]);
        assert (diff > abs(cur.first - i));
      }
      move('L');
      if (cur.second == 0) {
        cmd[1] = 'L';
        cmd[0] = 'R';
      } else {
        cmd[1] = 'R';
        cmd[0] = 'L';
      }
    }
  } else {
    int j = 0;
    bool flag = false;
    for (; j < m; j++) {
      if (mat[0][j] == '*') break;
      if (mat[1][j] == '.') {
        flag = true;
        break;
      }
    }
    if (flag) {
      while (cur.second != j) {
        int diff = abs(cur.second -j);
        if (cur.second < j) move(cmd[0]);
        else move(cmd[1]);
        assert (diff > abs(cur.second - j));
      }
      move('U');
      if (cur.first == 0) {
        cmd[2] = 'U';
        cmd[3] = 'D';
      } else {
        cmd[2] = 'D';
        cmd[3] = 'U';
      }
    }
  }
  memset(dist, -1, sizeof(dist));
  queue<pii> q;
  q.push(cur);
  dist[cur.first][cur.second] = 0;
  bool done = false;
  int base = 1e9;
  while (!q.empty() && !done) {
    auto tmp = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int i = tmp.first + dx[k];
      int j = tmp.second + dy[k];
      if (i < 0 || i >= n || j < 0 || j >= m) continue;
      if (mat[i][j] == '*' || dist[i][j] != -1) continue;
      dist[i][j] = dist[tmp.first][tmp.second] + 1;
      par[i][j] = tmp;
      if (mat[i][j] == 'F') {
        tmp = make_pair(i, j);
        while (tmp != cur) {
          dist[tmp.first][tmp.second] += base;
          tmp = par[tmp.first][tmp.second];
        }
        dist[cur.first][cur.second] += base;
        done = true;
        break;
      }
      q.emplace(i, j);
    }
  }
  while (mat[cur.first][cur.second] != 'F') {
    done = false;
    for (int k = 0; k < 4; k++) {
      int i = cur.first + dx[k];
      int j = cur.second + dy[k];
      if (i < 0 || i >= n || j < 0 || j >= m) continue;
      if (dist[i][j] == dist[cur.first][cur.second] + 1) {
        move(cmd[k]);
        assert(cur.first == i && cur.second == j);
        done = true;
        break;
      }
    }
    assert(done);
  }
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  solve(n, m);








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
