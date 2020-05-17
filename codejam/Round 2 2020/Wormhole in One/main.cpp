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
pii nums[123];
int hole[123];
bool used[123][2];
int ret;

void solve2(int i, int j, int k, int n) {
  memset(used, false, sizeof(used));
  LL dx = nums[i].first - nums[j].first;
  LL dy = nums[i].second - nums[j].second;
  while (!used[k][0]) {
    used[k][0] = true;
    if (hole[k] == -1) break;
    k = hole[k];
    if (used[k][1]) break;
    used[k][1] = true;
    int idx = -1;
    LL dist = 0;
    for (int u = 0; u < n; u++) {
      if (k == u) continue;
      LL ddx = nums[u].first - nums[k].first;
      LL ddy = nums[u].second - nums[k].second;
      if (ddx * dy != dx * ddy) continue;
      if (ddx * dx < 0) continue;
      if (ddy * dy < 0) continue;
      LL tmp = abs(ddx) + abs(ddy);
      if (idx == -1 || tmp < dist) {
        idx =  u;
        dist = tmp;
      }
    }
    if (idx == -1) break;
    k = idx;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (used[i][0] || used[i][1]) cnt++;
  }
  ret = max(ret, cnt);
}

void solve1(int k, int n) {
  if (n <= 2) {
    ret = n;
    return;
  }
  while (k < n && hole[k] != -1) k++;
  if (k == n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        for (int u = 0; u < n; u++) {
          solve2(i, j, u, n);
        }
      }
    }
    return;
  }
  solve1(k+1, n);
  for (int u = k+1; u < n; u++) {
    if (hole[u] != -1) continue;
    hole[u] = k;
    hole[k] = u;
    solve1(k+1, n);
    hole[u] = -1;
    hole[k] = -1;
  }

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
    memset(hole, -1, sizeof(hole));
    ret = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> nums[i].first >> nums[i].second;
    }
    solve1(0, n);
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
