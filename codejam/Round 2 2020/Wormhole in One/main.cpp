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
const int MAXN = 123;
int nums[MAXN][2];

int gcd(LL a, LL b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b%a, a);
}

pii slope(int i, int j) {
  int dx = nums[i][0] - nums[j][0];
  int dy = nums[i][1] - nums[j][1];
  int tmp = gcd(abs(dx), abs(dy));
  dx /= tmp;
  dy /= tmp;
  if (dx == 0) dy = 1;
  if (dy == 0) dx = 1;
  if (dx < 0) {
    dx = -dx;
    dy = -dy;
  }
  return {dy, dx};
}

pll bias(pii k, int i) {
  LL b1 = (LL)k.second * nums[i][1] - (LL)k.first * nums[i][0];
  LL b2 = k.second;
  if (b1 == 0 && b2 == 0) return {0LL, 0LL};
  if (b2 == 0) return {(LL)nums[i][0], 1LL};
  LL tmp = gcd(abs(b1), abs(b2));
  b1 /= tmp;
  b2 /= tmp;
  if (b1 == 0) b2 = 1;
  if (b1 < 0) {
    b1 = -b1;
    b2 = -b2;
  }
  return {b1, b2};
}

int solve(const map<pll, int>& table) {
  int n = table.size();
  if (n == 1) return table.begin()->second;

  int dual = 0, one = 0, tot = 0;
  for (const auto &item : table) {
    if (item.second == 1) one++;
    else if (item.second % 2 == 0) dual++;
    tot += item.second;
  }
  if (dual == n) return tot;
  if ((n - dual - one) % 2 == 1) one++;
  return tot - max(one-2, 0);
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
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> nums[i][0] >> nums[i][1];
    }
    int ret = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        pii sl = slope(i, j);
        map<pll, int> table;
        for (int k = 0; k < n; k++) {
          table[bias(sl, k)]++;
        }
        ret = max(ret, solve(table));
      }
    }
    cout << "Case #" << cs << ": " << ret << '\n';
  }





/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
