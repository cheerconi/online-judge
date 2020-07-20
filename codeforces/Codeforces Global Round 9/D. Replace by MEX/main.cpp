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
bool used[MAXN];

int mex(int n) {
  for (int i = 0; i <= n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    used[nums[i]] = true;
  }
  for (int i = 0; i <= n; i++) {
    if (!used[i]) return i;
  }
  assert(false);
  return -1;
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
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    vector<int> ret;
    while (true) {
      int x = mex(n);
      if (x < n) {
        ret.push_back(x+1);
        nums[x] = x;
      } else {
        bool done = true;
        for (int i = 0; i < n; i++) {
          if (nums[i] == i) continue;
          ret.push_back(i+1);
          nums[i] = x;
          done = false;
          break;
        }
        if (done) break;
      }
    }
    assert(ret.size() <= 2*n);
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
      cout << ret[i];
      if (i+1 == ret.size()) cout << '\n';
      else cout << ' ';
    }

  };





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
