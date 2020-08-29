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
const int MAXN = 5000 + 10;
int idx[MAXN][MAXN], nums[MAXN];
int n;
pii solve(int i, int j) {
  int mi = nums[idx[i][j]];
  pii ret;
  ret.second = mi;
  if (i <= idx[i][j]-1) {
    pii tmp = solve(i, idx[i][j]-1);
    ret.second += min(tmp.first, tmp.second-mi);
  }
  if (idx[i][j]+1 <= j) {
    pii tmp = solve(idx[i][j]+1, j);
    ret.second += min(tmp.first, tmp.second-mi);
  }
  ret.first = min(j-i+1, ret.second);
  return ret;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  cin >> n;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    if (nums[i] > n) {
      ret++;
      nums[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    idx[i][i] = i;
    for (int j = i+1; j < n; j++) {
      if (nums[j] < nums[idx[i][j-1]]) idx[i][j] = j;
      else idx[i][j] = idx[i][j-1];
    }
  }
  cout << solve(0, n-1).first + ret << '\n';
  


/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
