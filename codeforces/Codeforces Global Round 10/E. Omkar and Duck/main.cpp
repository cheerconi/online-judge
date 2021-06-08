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
const int MAXN = 30;
LL nums[MAXN][MAXN];

pair<int, int> solve(LL k, int i, int j, int n) {
  if (i+1 == n) return {i, j+1};
  if (j+1 == n) return {i+1, j};
  if (nums[i+1][j] != 0) {
    if (k & nums[i+1][j]) return {i+1, j};
    return {i, j+1};
  }
  assert(nums[i][j+1] != 0);
  if (k & nums[i][j+1]) return {i, j+1};
  return {i+1, j};
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a = i - 1;
      int b = j + 1;
      if (b < n && nums[a][b] == 0) {
        nums[i][j] = 1LL<<(i+j-1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << nums[i][j];
      if (j+1 != n) cout << ' ';
    }
    cout << endl;
  }
  int q; cin >> q;
  while (q--) {
    LL k; cin >> k;
    int i = 0, j = 0;
    cout << i+1 << ' ' << j+1 << endl;
    while (i != n-1 || j != n-1) {
      auto item = solve(k, i, j, n);
      cout << item.first + 1 << ' ' << item.second + 1 << endl;
      i = item.first;
      j = item.second;
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
