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
int solve(int n, int m) {
  if (min(n, m) >= 4) return -1;
  if (n == 1 || m == 1) return 0;
  vector<string> mat(n);
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  if (n > m) {
    vector<string> mat1(m);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        mat1[i].push_back(mat[j][i]);
      }
    }
    swap(n, m);
    mat = move(mat1);
  }
  if (n == 2) {
    int ret1 = 0, ret2 = 0;
    for (int j = 0; j < m; j++) {
      int val  = mat[0][j] - '0' + mat[1][j] - '0';
      if (j % 2 == 0) {
        if (val % 2 == 0) ret1++;
        else ret2++;
      } else {
        if (val % 2 == 1) ret1++;
        else ret2++;
      }
    }
    return min(ret1, ret2);
  }
  assert(n == 3);
  int ret1 = 0, ret2 = 0, ret3 = 0, ret4 = 0;
  for (int j = 0; j < m; j++) {
    bool aab = mat[0][j] == mat[1][j] && mat[0][j] != mat[2][j];
    bool aaa = mat[0][j] == mat[1][j] && mat[0][j] == mat[2][j];
    bool abb = mat[0][j] != mat[1][j] && mat[1][j] == mat[2][j];
    bool aba = mat[0][j] != mat[1][j] && mat[0][j] == mat[2][j];
    if (j % 2 == 0) {
      if (!aab) ret1++;
      if (!abb) ret2++;
      if (!aaa) ret3++;
      if (!aba) ret4++;
    } else {
      if (!aab) ret2++;
      if (!abb) ret1++;
      if (!aaa) ret4++;
      if (!aba) ret3++;
    }
  }
  return min(min(ret1, ret2), min(ret3, ret4));
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, m; cin >> n >> m;
  cout << solve(n, m) << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
