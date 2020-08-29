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
vi solve(int n, int a, int b, int c) {
  vi ret(c, n);
  for (int i = 0; i < b-c; i++) {
    if (n-1 <= 0) return {};
    ret.push_back(n-1);
  }
  for (int i = 0; i < a-c; i++) {
    if (n-1 <= 0) return {};
    ret.insert(ret.begin(), n-1);
  }
  if (ret.size() > n) return {};
  if (ret.size() == n) return ret;
  if (n-2 <= 0 || ret.size() == 1) return {};
  while (ret.size() < n) {
    ret.insert(ret.begin()+1, n-2);
  }
  return ret;
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
    int n, a, b, c; cin >> n >> a >> b >> c;
    vi ret = solve(n, a, b, c);
    cout << "Case #" << cs << ":";
    if (ret.empty()) {
      cout << " IMPOSSIBLE\n";
    } else {
      for (int num : ret) {
        cout << ' ' << num;
      }
      cout << '\n';
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
