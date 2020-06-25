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
const int MAXN = 1e6 + 10;
int a[MAXN], b[MAXN];

bool solve(int n) {
  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (b[i] >= a[i]) {
      idx = i;
      break;
    }
  }
  if (idx == -1) return false;
  LL rem = 0, need = 0;
  for (int i = 0; i < n; i++) {
    int j = (i+idx) % n;
    LL tmp = b[j] + rem;
    tmp -= a[j];
    if (tmp < 0) {
      need -= tmp;
      tmp = 0;
    }
    rem = min(tmp, (LL)b[j]);
  }
  if (b[(idx-1+n) % n] < need) return false;
  b[(idx-1+n) % n] -= need;
  rem = need;
  for (int i = 0; i < n; i++) {
    int j = (i+idx) % n;
    LL tmp = b[j] + rem;
    tmp -= a[j];
    if (tmp < 0) return false;
    rem = min(tmp, (LL)b[j]);
  }
  return true;
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
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    if (solve(n)) cout << "YES\n";
    else cout << "NO\n";
  }






/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
