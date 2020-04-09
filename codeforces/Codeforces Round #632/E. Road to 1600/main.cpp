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
const int MAXN = 550;
int mat[MAXN][MAXN];



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  if (n <= 2) {
    cout << -1 << '\n';
    return 0;
  }
  int cur = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-3; j++) {
      if (i % 2 == 0) mat[i][j] = cur++;
      else mat[i][n-3-j-1] = cur++;
    }
  }
  for (int j = n-3; j < n; j++) {
    for (int i = 0; i < n-3; i++) {
      if (j%2 == (n-3)%2) mat[n-1-i][j] = cur++;
      else mat[3+i][j] = cur++;
    }
  }
  mat[0][n-3] = cur+7;
  mat[0][n-2] = cur+2;
  mat[0][n-1] = cur+4;
  mat[1][n-3] = cur+5;
  mat[1][n-2] = cur+1;
  mat[1][n-1] = cur+3;
  mat[2][n-3] = cur+6;
  mat[2][n-2] = cur+8;
  mat[2][n-1] = cur;
  assert (cur+8 == n*n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j];
      if (j+1 != n) cout << ' ';
    }
    cout << '\n';
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
