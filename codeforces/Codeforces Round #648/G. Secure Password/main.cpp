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
const int MAXB = 13;
const int MAXN = 1234;
int code[MAXN];
LL ret[MAXB];

LL ask(const vector<int>& nums) {
  if (nums.empty()) return 0;
  cout << "? " << nums.size();
  for (int num : nums) {
    cout << ' ' << num;
  }
  cout << endl;
  LL val; cin >> val;
  return val;
}





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    while (__builtin_popcount(cur) != 6) cur++;
    code[i] = cur++;
  }
  for (int i = 0; i < MAXB; i++) {
    int mask = 1<<i;
    vector<int> nums;
    for (int j = 1; j <= n; j++) {
      if (code[j] & mask) {
        nums.push_back(j);
      }
    }
    ret[i] = ask(nums);
  }
  cout << "!";
  for (int i = 1; i <= n; i++) {
    LL val = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      for (int k = 0; k < MAXB; k++) {
        int mask = 1<<k;
        if (mask & code[i]) continue;
        if (mask & code[j]) {
          val |= ret[k];
          break;
        }
      }
    }
    cout << ' ' << val;
  }
  cout << endl;





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
