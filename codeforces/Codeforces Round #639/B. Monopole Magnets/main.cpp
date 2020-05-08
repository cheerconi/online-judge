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
string mat[MAXN];
pii col[MAXN], row[MAXN];

int solve(int n, int m) {
  bool emp_col = false;
  bool emp_row = false;
  for (int i = 0; i < n; i++) {
    bool has = false;
    bool done = false;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '#') {
        if (done) return -1;
        has = true;
      } else if (has) {
        done = true;
      }
    }
    if (!has) emp_row = true;
  }
  for (int j = 0; j < m; j++) {
    bool has = false;
    bool done = false;
    for (int i = 0; i < n; i++) {
      if (mat[i][j] == '#') {
        if (done) return -1;
        has = true;
      } else if (has) {
        done = true;
      }
    }
    if (!has) emp_col = true;
  }
  if (emp_col != emp_row) return -1;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    bool has = false;
    bool con = false;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '#') {
        has = true;
        if (i+1 < n && mat[i+1][j] == '#')  con = true;
      }
    }
    if (has) ret++;
    if (con) ret--;
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
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  cout << solve(n, m) << '\n';






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
