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
const int MAXN = 5123;
int nums[MAXN];
bool solve(int n, int d) {
  int cur = 0, unused = n-1;
  nums[0] = 1;
  int i = 1;
  for (; unused > 0; i++) {
    nums[i] = min(nums[i-1]*2, unused);
    unused -= nums[i];
    cur += i * nums[i];
  }
  if (cur > d) return false;
  int m = i;
  nums[m] = 0;
  for (int j = i-1; j >= 0 && cur < d; j--) {
    while (nums[j] > 1 && cur < d) {
      int tmp = min(m-j, d - cur) + j;
      nums[j]--;
      nums[tmp]++;
      cur = cur - j + tmp;
      m = max(m, tmp+1);
      nums[m] = 0;
    }
  }
  return cur==d;
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
    int n, d; cin >> n >> d;
    if (solve(n, d)) {
      cout << "YES\n";
      vector<vi> tree;
      int x = 0;
      for (int i = 0; x < n; i++) {
        tree.push_back(vi());
        for (int j = 0; j < nums[i]; j++) {
          x++;
          tree.back().push_back(x);
        }
      }
      int cnt = 1;
      for (int i = 1; cnt < n; i++) {
        for (int j = 0; j < nums[i]; j++) {
          int idx = j/2;
          cout << tree[i-1][idx];
          cnt++;
          if (cnt == n) cout << '\n';
          else cout << ' ';
        }
      }
    } else cout << "NO\n";
  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
