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
const int MAXN = 1e5 + 10;
LL sum_a[MAXN];




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  LL n, d, m; cin >> n >> d >> m;
  vi a, b;
  LL ret = 0;
  for (int i = 0; i < n; i++) {
    int val; cin >> val;
    if (val <= m) {
      a.push_back(val);
      ret += val;
    }
    else b.push_back(val);
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < a.size(); i++) {
    sum_a[i+1] = sum_a[i] + a[i];
  }
  sort(b.begin(), b.end(), greater<int>());
  LL sum_b = 0;
  for (int i = 0; i < b.size(); i++) {
    LL need = i*d + i + 1;
    if (need > n) break;
    sum_b += b[i];
    need -= i+1 + (b.size()-i-1);
    need = max(need, 0LL);
    assert (need <= a.size());
    ret = max(ret, sum_b + sum_a[a.size()-need]);
  }
  cout << ret << '\n';







/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
