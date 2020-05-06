/*
ID: txingml
PROG: wormhole
LANG: C++
*/
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
int nxt[15], connect[15];
int holes[15][2];
int ret;

bool loop(int i, int n) {
  vector<bool> used(n);
  used[i] = true;
  while (true) {
    i = connect[i];
    i = nxt[i];
    if (i == -1) return false;
    if (used[i]) return true;
    used[i] = true;
  }
  assert(false);
  return true;
}

void dfs(int i, int n) {
  while (i < n && connect[i] != -1) i++;
  if (i == n) {
    for (int j = 0; j < n; j++) {
      if (loop(j, n)) {
        ret++;
        break;
      }
    }
    return;
  }
  for (int j = i+1; j < n; j++) {
    if (connect[j] != -1) continue;
    connect[j] = i;
    connect[i] = j;
    dfs(i+1, n);
    connect[j] = -1;
  }
  connect[i] = -1;
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("wormhole.in", "r", stdin);
  freopen("wormhole.out", "w", stdout);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> holes[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    int k = -1;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (holes[i][1] != holes[j][1]) continue;
      if (holes[i][0] > holes[j][0]) continue;
      if (k == -1 || holes[k][0] > holes[j][0]) k = j;
    }
    nxt[i] = k;
  }
  memset(connect, -1, sizeof(connect));
  dfs(0, n);
  cout << ret << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
