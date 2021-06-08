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
const int MAXN = 3e5 + 10;
int nums[MAXN];

int is_min(int i, int n) {
  if (i == 0 || i == n-1) return false;
  if (nums[i-1] < nums[i]) return false;
  if (nums[i+1] <= nums[i]) return false;
  return true;
}

bool is_max(int i, int n) {
  if (i-1 >= 0) {
    if (nums[i-1] >= nums[i]) return false;
  }
  if (i+1 < n) {
    if (nums[i+1] > nums[i]) return false;
  }
  return true;
}

int coeff(int i, int n) {
  bool mi = is_min(i, n);
  bool ma = is_max(i, n);
  assert(!(mi&&ma));
  if (mi) return -1;
  if (ma) return 1;
  return 0;
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
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    LL ret = 0;
    for (int i = 0; i < n; i++) {
      ret += coeff(i, n) * nums[i];
    }
    cout << ret << '\n';
    while (q--) {
      int a, b; cin >> a >> b;
      a--; b--;
      set<int> idx;
      idx.insert(a);
      idx.insert(b);
      if (a-1 >= 0) idx.insert(a-1);
      if (a+1 < n) idx.insert(a+1);
      if (b-1 >= 0) idx.insert(b-1);
      if (b+1 < n) idx.insert(b+1);
      for (int i : idx) {
        ret -= coeff(i, n) * nums[i];
      }
      swap(nums[a], nums[b]);
      for (int i : idx) {
        ret += coeff(i, n) * nums[i];
      }
      cout << ret << '\n';
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
