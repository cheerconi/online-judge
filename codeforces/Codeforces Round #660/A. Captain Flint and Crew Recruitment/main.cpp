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
vector<int> ret;
set<int> a{6, 10, 14};
vi nums{6, 10, 14, 15, 21, 22, 26};


bool solve(int n) {
  ret.clear();
  if (n <= 30) return false;
  if (a.find(n-30) == a.end()) {
    ret.insert(ret.end(), a.begin(), a.end());
    ret.push_back(n-30);
    return true;
  }
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i+1; j < nums.size(); j++) {
      for (int k = j+1; k < nums.size(); k++) {
        int val = nums[i] + nums[j] + nums[k];
        if (val >= n) continue;
        if (n-val == nums[i] || n-val == nums[j] || n-val == nums[k]) continue;
        ret.push_back(nums[i]);
        ret.push_back(nums[j]);
        ret.push_back(nums[k]);
        ret.push_back(n-val);
        return true;
      }
    }
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
    int n; cin >> n;
    if (solve(n)) {
      cout << "YES\n";
      for (int i = 0; i < 4; i++) {
        cout << ret[i];
        if (i+1 == 4) cout << '\n';
        else cout << ' ';
      }
    } else {
      cout << "NO\n";
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
