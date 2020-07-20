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
int nums[MAXN], diff[MAXN];
bool used[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }
  int ret = 0;
  for (int i = 0; i < n; i++) {
    vector<int> dp;
    for (int j = i+1; j < n; j++) {
      if (nums[i] < nums[j]) continue;
      ret++;
      while (!dp.empty() && dp.back() > nums[j]) dp.pop_back();
      dp.push_back(nums[j]);
    }
    memset(used, false, sizeof(used));
    int cnt = 0;
    int j = i+1;
    int a = 0;
    for (int k = 0; k < dp.size(); k++) {
      while (j < n) {
        if (nums[i] > nums[j]) {
          used[nums[j]] = true;
          cnt++;
        }
        j++;
        if (nums[j-1] == dp[k]) break;
      }
      while (a < dp[k]) {
        if (used[a]) {
          used[a] = false;
          cnt--;
        }
        a++;
      }
      diff[cnt]++;
    }
  }
  for (int i = n; i > 0; i--) {
    if (diff[i] != 0) {
      cout << ret-(2*i-1) << ' ' << diff[i] << '\n';
      return 0;
    }
  }
  assert(false);








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
