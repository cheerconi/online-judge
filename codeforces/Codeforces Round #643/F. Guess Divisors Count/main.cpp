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
bool np[MAXN];
vi ps, guess;
vector<bool> sure;
int mi, ma, bound;

LL power(LL base, int p) {
  LL ret = 1;
  while (p) {
    if (p&1) ret = base * ret;
    base *= base;
    p >>= 1;
  }
  return ret;
}

int query(LL a) {
  cout << "? " << a << endl;
  int b;
  cin >> b;
  return b;
}

void solve( int i, int cnt, LL val) {
  while (i < sure.size() && sure[i]) {
    cnt *= (guess[i] + 1);
    i++;
  }
  if (i == ps.size()) {
    mi = min(mi, cnt);
    ma = max(ma, cnt);
    return;
  }
  for (LL j = power(ps[i], guess[i]), k = 0; (LD)val * j <= bound; j *= ps[i], k++) {
    solve(i+1, cnt * (guess[i] + k + 1), val * j);
  }
}




int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.precision(10); cout << fixed;
#ifdef LOCAL
  freopen("../test.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
#endif
  for (int i = 2; i < MAXN; i++) {
    if (np[i]) continue;
    for (int j = i+i; j < MAXN; j += i) {
      np[j] = true;
    }
  }
  for (int i = 2; i < MAXN; i++) {
    if (!np[i]) ps.push_back(i);
  }
  int T; cin >> T;
  int m = ps.size();
  while (T--) {
    mi = INT_MAX;
    ma = -1;
    guess = vi(m, 0);
    sure = vector<bool>(m, false);
    bound = 1e9;
    for (int count = 0; count < 22; count++) {
      LL val = 1;
      for (int i = 0; i < m; i++) {
        if (sure[i]) continue;
        if ((LD)val * ps[i] > 1e18) break;
        LL tmp = power(ps[i], guess[i]+1);
        if ((LD)val * tmp <= 1e18) val *= tmp;
      }
      if (val == 1) break;
      int gcd = query(val);
      for (int i = 0; i < m; i++) {
        if (sure[i]) continue;
        LL tmp = power(ps[i], guess[i]+1);
        if (val % tmp != 0) continue;
        if (gcd % tmp != 0) {
          sure[i] = true;
          bound /= (tmp/ps[i]);
        }
        else guess[i]++;
      }
    }
    solve(0, 1, 1);
    cout << "! " << max(mi*2, mi+7) << endl;
  }








/*---------------------------------------Coding Space End------------------------------------------*/
#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#endif
  return 0;
}
/* author:  txingml */
/* picture is from hamayanhamayan(CF handle) */
