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
set<int> subset[MAXN];

int query(int a, int b) {
  int n = b-a+1;
  cout << "? " << n;
  for (int i = a; i <= b; i++) {
    cout << ' ' << i;
  }
  cout << endl;
  int val; cin >> val;
  return val;

}

int query(const vector<int>& nums) {
  int n = nums.size();
  cout << "? " << n;
  for (int i : nums) {
    cout << ' ' << i;
  }
  cout << endl;
  int val; cin >> val;
  return val;

}


int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  int t; cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
      subset[i].clear();
      int m, val; cin >> m;
      for (int j = 0; j < m; j++) {
        cin >> val;
        subset[i].insert(val);
      }
    }
    int a = 1, b = n;
    int ma = query(1, n);
    while (a < b) {
      int mid = (a+b) >> 1;
      int tmp = query(a, mid);
      assert(tmp != -1);
      if (tmp == ma) b = mid;
      else a = mid+1;
    }
    int idx = -1;
    vector<int> nums;
    for (int i = 0; i < k; i++) {
      if (subset[i].find(a) != subset[i].end()) {
        idx = i;
        for (int j = 1; j <= n; j++) {
          if (subset[i].find(j) == subset[i].end())
            nums.push_back(j);
        }
      }
    }
    if (!nums.empty()) {
      b = query(nums);
      assert(b != -1);
    }
    cout << "!";
    for (int i = 0; i < k; i++) {
      if (i == idx) cout << ' ' << b;
      else cout << ' ' << ma;
    }
    cout << endl;
    string s; cin >> s;
    assert(s == "Correct");
  }



/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
