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
string ret;
int pivot;

bool solve(const vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();
  vector<int> idxes(n);
  iota(idxes.begin(), idxes.end(), 0);
  sort(idxes.begin(), idxes.end(), [&mat](int i, int j){
    return mat[i][0] < mat[j][0];
  });
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = vector<int>(m);
    for (int j = 0; j < m; j++) {
      a[i][j] = mat[idxes[i]][j];
    }
  }
  vector<vector<int>> b = a, c = a, d = a;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i-1 >= 0) a[i][j] = max(a[i][j], a[i-1][j]);
      if (j-1 >= 0) a[i][j] = max(a[i][j], a[i][j-1]);
    }
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (i+1 < n) b[i][j] = min(b[i][j], b[i+1][j]);
      if (j-1 >= 0) b[i][j] = min(b[i][j], b[i][j-1]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = m-1; j >= 0; j--) {
      if (i-1 >= 0) c[i][j] = min(c[i][j], c[i-1][j]);
      if (j+1 < m) c[i][j] = min(c[i][j], c[i][j+1]);
    }
  }
  for (int i = n-1; i >= 0; i--) {
    for (int j = m-1; j >= 0; j--) {
      if (i+1 < n) d[i][j] = max(d[i][j], d[i+1][j]);
      if (j+1 < m) d[i][j] = max(d[i][j], d[i][j+1]);
    }
  }
  for (int i = 0; i+1 < n; i++) {
    for (int j = 0; j+1 < m; j++) {
      if (a[i][j] < b[i+1][j] && c[i][j+1] > d[i+1][j+1]) {
        pivot = j+1;
        ret = string(n, 'R');
        for (int k = 0; k <= i; k++) {
          ret[idxes[k]] = 'B';
        }
        return true;
      }
    }
  }
  return false;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    }
    if (solve(mat)) {
      cout << "YES\n" << ret << ' ' << pivot << '\n';
    } else {
      cout << "NO\n";
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
