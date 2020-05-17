/*
ID: txingml
PROG: holstein
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
int v[25], cur[25], data[15][25], ret;
int n, m;
void dfs(int i, int mask) {
  if (__builtin_popcount(mask) >= __builtin_popcount(ret)) return;
  if (i == m) {
    for (int j = 0; j < n; j++) {
      if (v[j] > cur[j]) return;
    }
    ret = mask;
    return;
  }
  for (int j = 0; j < n; j++) {
    cur[j] += data[i][j];
  }
  dfs(i+1, mask|(1<<i));
  for (int j =0; j < n; j++) {
    cur[j] -= data[i][j];
  }
  dfs(i+1, mask);
};




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("holstein.in", "r", stdin);
  freopen("holstein.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> data[i][j];
    }
  }
  ret = (1<<m) - 1;
  dfs(0, 0);
  cout << __builtin_popcount(ret);
  for (int i = 0; i < m; i++) {
    if (ret & (1<<i)) cout << ' ' << i+1;
  }
  cout << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
