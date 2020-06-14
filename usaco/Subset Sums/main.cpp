/*
ID: txingml
PROG: subset
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
void solve(int a, int b, int tot, vector<int>& nums) {
  if (a == b) {
    nums[tot]++;
    return;
  }
  solve(a+1, b, tot+a, nums);
  solve(a+1, b, tot, nums);
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
  freopen("subset.in", "r", stdin);
  freopen("subset.out", "w", stdout);
  int n; cin >> n;
  int sum = (n+1) * n / 2;
  if (sum % 2 == 1) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> nums1(sum+1, 0), nums2(sum+1, 0);
  int m = (n+1)/2;
  solve(1, m, 0, nums1);
  solve(m, n+1, 0, nums2);
  LL ret = 0;
  for (int i = 0; i < nums1.size(); i++) {
    if (sum/2 - i < 0) break;
    ret += (LL)nums1[i] * nums2[sum/2 - i];
  }
  cout << ret/2 << '\n';






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
