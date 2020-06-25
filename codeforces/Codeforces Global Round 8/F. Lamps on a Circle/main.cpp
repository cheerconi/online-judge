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
bool used[MAXN];





int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
//  freopen("../test.txt", "r", stdin);
  // freopen("../output.txt", "w", stdout);
#endif
  int n; cin >> n;
  int t = 1, ma = 0;
  for (int i = 2; i <= n; i++) {
    int tmp = (n/i-1) * (i-1) + max(n%i-1, 0);
    if (ma < tmp) {
      ma = tmp;
      t = i;
    }
  }
  int cur = 0;
  while (cur < ma) {
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      if (i%t == 0 || used[i]) continue;
      ret.push_back(i+1);
      used[i] = true;
      cur++;
    }
    assert (!ret.empty());
    cout << ret.size();
    for (int num : ret) {
      cout << ' ' << num;
    }
    cout << endl;
    int k; cin >> k;
    assert(k != 0);
    k--;
    for (int i = 0; i < ret.size(); i++) {
      if (used[k]) {
        used[k] = false;
        cur--;
      }
      k++;
      if (k == n) k = 0;
    }
  }
  cout << 0 << endl;







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
