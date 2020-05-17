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
const int MAXN = 2222;
const int M = 1e4;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dp[MAXN][MAXN];

int solve(int a, int b) {
  if (a > b) {
    assert (b+1 == a);
    return 1;
  }
  if (a < 1000 && b < 1000) return dp[a][b];
  int ret = INT_MAX;
  for (int i = 1; i <= M; i++) {
    int cur = abs(i - a);
    if (cur >= ret && i > a) break;
    for (int j = i; ; j += i) {
      ret = min(ret, cur + abs(j-b));
      if (j > b) break;
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
  memset(dp, -1, sizeof(dp));
  queue<pii> q;
  for (int i = 1; i < MAXN; i++) {
    for (int j = i; j < MAXN; j++) {
      if (j % i == 0) {
        dp[i][j] = 0;
        q.emplace(i, j);
      }
    }
  }
  while (!q.empty()) {
    pii cur = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      pii tmp = cur;
      tmp.first += dx[i];
      tmp.second += dy[i];
      if (tmp.first < 0 || tmp.first >= MAXN) continue;
      if (tmp.second < 0 || tmp.second >= MAXN) continue;
      if (tmp.second < tmp.first) continue;
      if (dp[tmp.first][tmp.second] != -1) continue;
      dp[tmp.first][tmp.second] = dp[cur.first][cur.second] + 1;
      q.push(tmp);
    }
  }
  int t; cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    int ret = INT_MAX;
    int x = 0;
    for (int i = 1; i <= 2*a - 1; i++) {
      int cur = abs(i - a);
      if (cur >= ret && i > a) break;
      vector<pii> items;
      if (b % i == 0) {
        items.emplace_back(0, b/i);
      } else {
        items.emplace_back(b%i, b/i);
        items.emplace_back(i-b%i, b/i+1);
      }
      for (const auto& item : items) {
        int tmp = INT_MAX;
        if (c % i == 0) {
          tmp = min(tmp, cur + item.first + solve(item.second, c/i) * i);
        } else {
          tmp = min(tmp, cur+item.first+ + c%i + solve(item.second, c/i) * i);
          tmp = min(tmp, cur+item.first+ i - c%i + solve(item.second, c/i+1) * i);
        }
        if (tmp < ret) {
          ret = tmp;
          x = i;
        }
      }
    }
    cout << ret << '\n' << x << ' ';
    for (int i = x; ; i += x) {
      int tmp, y;
      if (c < i) {
        tmp = i - c;
        y = i;
      }
      else {
        if (c % i > i - c % i) {
          y = c / i * i + i;
          tmp = i - c % i;
        } else {
          y = c / i * i;
          tmp = c % i;
        }
      }
      tmp += abs(a - x) + abs(i - b);
      if (tmp == ret) {
        cout << i << ' ' << y << endl;
        break;
      }
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
