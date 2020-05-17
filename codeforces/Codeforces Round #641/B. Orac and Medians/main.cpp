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
const int MAXN = 100000 + 10;
int nums[MAXN];
int a[3];

bool solve(int n, int k) {
  if (a[1] == 0) return false;
  if (a[0] <= (n-1)/2) return true;
  for (int i = 0; i + 2 < n; i++) {
    int cnt = 0;
    if (nums[i] >= k) cnt++;
    if (nums[i+1] >= k) cnt++;
    if (nums[i+2] >= k) cnt++;
    if (cnt >= 2) return true;
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
  int t; cin >> t;
  while (t--) {
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
      if (nums[i] == k) a[1]++;
      else if (nums[i] > k) a[2]++;
      else a[0]++;
    }
    if (solve(n, k)) cout << "yes\n";
    else cout << "no\n";

  }







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
