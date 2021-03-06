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
const int MAXN = 1234;
int nums[MAXN];
vector<int> left_array;

int longest_increase_seq(const vector<int>& array) {
  int n = array.size();
  if (n <= 1) return n;
  vector<int> dp(1, 0);
  for (int num : array) {
    auto it = lower_bound(dp.begin(), dp.end(), num);
    auto tmp = it; tmp--;
    if (it == dp.end()) dp.push_back(num);
    else *it = num;
  }
  return dp.size() - 1;
}

int solve_left(int m, int idx) {
  if (idx == 0) return 0;
  int t = idx-1;
  for (int i = idx-1; i >= 0; i--) {
    if (left_array[t] == nums[i]) {
      t--;
    } else {
      m = max(m, nums[i]);
    }
  }
  int ret = 0;
  for (int i = 0; i < idx; i++) {
    if (nums[i] <= m) ret++;
  }
  return ret;

}

int solve(int k, int idx, int n) {
  vector<int> rem;
  int ret = 0, last = n;
  for (int i = idx+1; i < n; i++) {
    if (i == k) {
      ret++;
      continue;
    }
    if (nums[i] > nums[k]) {
      if (nums[i] > last) return INT_MAX;
      last = nums[i];
      ret += rem.size();
      rem.clear();
    } else {
      rem.push_back(nums[i]);
    }
  }
  reverse(rem.begin(), rem.end());
  ret += rem.size() - longest_increase_seq(rem);
  ret += solve_left(nums[k], idx);
  return ret;
}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    if (nums[i] == n) idx = i;
  }
  for (int i = 0; i < idx; i++) {
    left_array.push_back(nums[i]);
  }
  sort(left_array.begin(), left_array.end());
  int ret = INT_MAX;
  for (int i = idx+1; i < n; i++) {
    ret = min(ret, solve(i, idx, n));
  }
  bool flag = true;
  for (int i = idx+1; i < n; i++) {
    if (nums[i-1] < nums[i]) {
      flag = false;
      break;
    }
  }
  if (flag)  ret = min(ret, solve_left(-1, idx));
  cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
