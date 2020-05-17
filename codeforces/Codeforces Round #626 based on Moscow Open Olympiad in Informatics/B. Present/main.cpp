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
const int MAXN = 400000 + 10;
const int M = 25;
int nums[M][MAXN];

int count(int a, int b, int i, int bias, int n) {
  if (a > b) return 0;
  return upper_bound(nums[i] + bias, nums[i]+n, b) - lower_bound(nums[i] + bias, nums[i]+n, a);
}



int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n, val; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> val;
    int mask = 1<<M;
    for (int j = M-1; j >= 0; j--) {
      val = (mask-1) & val;
      nums[j][i] = val;
      mask >>= 1;
    }
  }
  for (int i = 0; i < M; i++) {
    sort(nums[i], nums[i] + n);
  }
  int ret = 0, a, b, mask = 1;
  for (int j = 0; j < M; mask <<= 1, j++) {
    if (nums[j][n-1] == 0) continue;
    int rem = 0;
    for (int i = 0; i < n; i++) {
      a = mask - nums[j][i];
      b = (mask<<1) - nums[j][i] - 1;
      rem = (rem + count(a, b, j, i+1,  n)) % 2;
      a = mask + (mask << 1) - nums[j][i];
      b = (mask<<1) - 1;
      rem = (rem + count(a, b, j, i+1,  n)) % 2;
    }
    if (rem) ret += mask;
  }
  cout << ret << endl;






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
