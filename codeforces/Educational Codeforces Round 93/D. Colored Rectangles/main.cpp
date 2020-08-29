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
int n[3];
vi nums[3];

LL solve(int a, int b) {
  if (a+b > n[0] || a > n[1] || b > n[2]) return -1;
  int c = min(n[1]-a, n[2]-b);
  LL ret = 0;
  int i = 0, j = 0, k = 0;
  while (true) {
    if (a == 0 && b == 0 && c == 0) break;
    int tmpa = -1, tmpb = -1, tmpc = -1;
    if (a > 0) tmpa = nums[0][i] * nums[1][j];
    if (b > 0) tmpb = nums[0][i] * nums[2][k];
    if (c > 0) tmpc = nums[1][j] * nums[2][k];
    if (tmpa >= tmpb && tmpa >= tmpc) {
      a--;
      i++;
      j++;
      ret += tmpa;
    } else if (tmpb >= tmpa && tmpb >= tmpc) {
      b--;
      i++;
      k++;
      ret += tmpb;
    } else {
      c--;
      j++;
      k++;
      ret += tmpc;
    }
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
  for (int i = 0; i < 3; i++) cin >> n[i];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n[i]; j++) {
      int val; cin >> val;
      nums[i].push_back(val);
    }
    sort(nums[i].begin(), nums[i].end(), greater<int>());
  }
  LL ret = 0;
  for (int i = 0; i <= n[0]; i++) {
    for (int j = 0; j <= n[0]; j++) {
      ret = max(ret, solve(i, j));
    }
  }
  cout << ret << '\n';








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
