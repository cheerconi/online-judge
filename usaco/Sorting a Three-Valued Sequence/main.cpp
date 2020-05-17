/*
ID: txingml
PROG: sort3
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
const int MAXN = 1234;
int a[4][4];
int x[MAXN], y[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("sort3.in", "r", stdin);
  freopen("sort3.out", "w", stdout);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    y[i] = x[i];
  }
  sort(y, y+n);
  for (int i = 0; i < n; i++) {
    if (x[i] == y[i]) continue;
    a[x[i]][y[i]]++;
  }
  int ret = 0;
  int ma = 0;
  for (int i = 1; i <= 3; i++) {
    for (int j = i+1; j <= 3; j++) {
      int tmp = min(a[i][j], a[j][i]);
      ret += tmp;
      a[i][j] -= tmp;
      a[j][i] -= tmp;
      ma = max(ma, a[i][j]);
      ma = max(ma, a[j][i]);
    }
  }
  ret += ma * 2;
  cout << ret << endl;








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
