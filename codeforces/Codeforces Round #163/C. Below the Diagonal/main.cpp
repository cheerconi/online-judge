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
int mat[MAXN][MAXN], row[MAXN], col[MAXN], cnt[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n-1; i++) {
    int a, b; cin >> a >> b;
    mat[a][b] = 1;
    cnt[a]++;
  }
  for (int i = 1; i <= n; i++) {
    row[i] = i;
    col[i] = i;
  }
  vector<vi> ret;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    int idx = i;
    for (int j = idx+1; j <= n; j++) {
      if (cnt[row[idx]] > cnt[row[j]]) idx = j;
    }
    if (idx != i) {
      ret.push_back({1, idx, i});
      swap(row[idx], row[i]);
    }
    for (int j = k, jj = k; j < i; j++) {
      if (mat[row[i]][col[j]] == 1) {
        k = j+1;
        continue;
      }
      jj = max(j+1, jj);
      while (jj <= n) {
        if (mat[row[i]][col[jj]] == 0) jj++;
        else break;
      }
      if (jj == n+1) break;
      ret.push_back({2, j, jj});
      swap(col[j], col[jj]);
      k = j+1;
    }
    for (int j = k; j <= n; j++) {
      assert (mat[row[i]][col[j]] == 0);
    }
  }
  cout << ret.size() << '\n';
  for (const auto& item : ret) {
    cout << item[0] << ' ' << item[1] << ' ' << item[2] << '\n';
  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
