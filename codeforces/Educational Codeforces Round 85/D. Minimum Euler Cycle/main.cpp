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
void print(LL a, LL b,  LL n, LL len) {
  LL x = b/2 + a + 1;
  bool one = (b % 2 == 0);
  for (int i = 0; i < len; i++) {
    if (one) cout << a;
    else cout << x++;
    one = !one;
    if (x == n+1) {
      a++;
      x = a + 1;
      if (a == n) {
        a = 1;
      }
    }
    if (i+1 == len) cout << '\n';
    else cout << ' ';
  }
}

pll solve(LL n, LL a) {
  if (a < 2*(n-1)) {
    return {1, a};
  }
  LL x = 1, y = n-1;
  while (x < y) {
    LL mid = (x+y+1) >> 1;
    LL sum = (n-1 + n-mid) * mid;
    if (sum == a) {
      return {mid+1, 0};
    }
    if (sum > a) y = mid-1;
    else x = mid;
  }
  LL sum =  (n-1 + n-x) * x;
  assert (sum <= a);
  return {x+1, a-sum};

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
    LL n, a, b; cin >> n >> a >> b;
    a--;
    b--;
    if (a == n * (n-1)) {
      assert (b == a);
      cout << "1\n";
      continue;
    }
    auto item = solve(n, a);
    print(item.first, item.second, n, b-a+1);

  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
