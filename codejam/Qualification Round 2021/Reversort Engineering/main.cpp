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
vector<int> solve(int n, int c) {
  if (c < n-1) return {};
  vector<int> cost(n-1, 1);
  c -= n - 1;
  for (int i = 0; i < n-1; i++) {
    if (c == 0) break;
    int tmp = n-i-1;
    tmp = min(tmp, c);
    c -= tmp;
    cost[i] += tmp;
  }
  if (c != 0) return {};
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    nums[i] = i+1;
  }
  for (int i = n-2; i >= 0; i--) {
    int tmp = cost[i];
    reverse(nums.begin()+i, nums.begin()+i+tmp);
  }
  return nums;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int T; cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    int n, c; cin >> n >> c;
    vi ret = solve(n, c);
    cout << "Case #" << cs << ":";
    if (ret.empty()) {
      cout << " IMPOSSIBLE";
    } else {
      for (int i = 0; i < n; i++) {
        cout << ' ' << ret[i];
      }
    }
    cout << endl;
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
