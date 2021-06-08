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
int solve(const string& s1, const string& s2) {
  if (s1 == s2) return 0;
  vector<int> nums1, nums2;
  if (s1 != "0") {
    nums1.push_back(1);
    for (int i = 1; i < s1.size(); i++) {
      if (s1[i] == s1[i-1]) {
        nums1.back()++;
      } else {
        nums1.push_back(1);
      }
    }
  }
  if (s2 != "0") {
    nums2.push_back(1);
    for (int i = 1; i < s2.size(); i++) {
      if (s2[i] == s2[i-1]) {
        nums2.back()++;
      } else {
        nums2.push_back(1);
      }
    }
  }
  if (nums2.empty()) {
    return nums1.size();
  }
  int base = 0;
  if (nums1.empty()) {
    base = 1;
    nums1.push_back(1);
  }
  int ret = INT_MAX;
  int n1 = nums1.size();
  int n2 = nums2.size();
  for (int i = 0; i <= nums1.size(); i++) {
    int need = n2 - (n1 - i);
    if (need < 0) continue;
    if (n1 % 2 == 0 && need > i) continue;
    if (n1 % 2 == 1 && need > i+1) continue;
    vector<int> tmp(nums2.size());
    for (int j = i; j < nums1.size(); j++) {
      tmp[j-i] = nums1[j];
    }
    int cur = i;
    for (int j = nums1.size()-i; j < nums2.size(); j++) {
      cur += nums2[j];
      tmp[j] = nums2[j];
    }
    if (n1 % 2 == 0 && i != nums1.size()) {
      int j = (int)nums1.size() - i - 1;
      if (tmp[j] < nums2[j]) {
        cur += nums2[j] - tmp[j];
        tmp[j] = nums2[j];
      }
    }
    if (n1 % 2 == 1 && i != nums1.size() && i > need) {
      int j = (int)nums1.size() - i - 1;
      if (tmp[j] < nums2[j]) {
        cur += nums2[j] - tmp[j];
        tmp[j] = nums2[j];
      }
    }
    if (tmp == nums2) {
      ret = min(ret, cur);
    }
  }
  if (ret == INT_MAX) return -1;
  return ret + base;
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
    string s1, s2;
    cin >> s1 >> s2;
    int ret = solve(s1, s2);
    cout << "Case #" << cs << ": ";
    if (ret == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ret << endl;

  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
